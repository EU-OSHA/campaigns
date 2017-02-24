<?php

/**
 * Validator.php
 * Validator for form fields
 * @author Eduardo Martos (eduardo.martos.gomez@everis.com)
 */
class Validator
{
    /**
     * Constant for NOT NULL validation
     */
    const VALIDATION_NOTNULL = 'not_null';
    /**
     * Constant for NOT NULL validation
     */
    const VALIDATION_NUMERIC = 'numeric';
    /**
     * Constant for SIZE validation
     */
    const VALIDATION_SIZE = 'size';
    /**
     * Constant for EMAIL validation
     */
    const VALIDATION_EMAIL = 'email';
    /**
     * Constant for URL validation
     */
    const VALIDATION_URL = 'url';
    /** Constant for captcha validation */
    const VALIDATION_CAPTCHA = 'captcha';
    /**
     * @var array Validation types
     */
    private $validationTypes = array(
        self::VALIDATION_NOTNULL,
        self::VALIDATION_NUMERIC,
        self::VALIDATION_SIZE,
        self::VALIDATION_EMAIL,
        self::VALIDATION_URL,
        self::VALIDATION_CAPTCHA,
    );

    /**
     * Validate a value
     *
     * @param $attribute
     *
     * @return bool
     */
    public function validate($attribute)
    {
        $ret = true;
        $validationType = $attribute->getValidator();
        if (is_array($validationType)) {
            foreach ($validationType as $singleValidationType) {
                $ret = $this->singleValidation($attribute, $singleValidationType);
                if (! $ret) {
                    break;
                }
            }
        } else {
            $ret = $this->singleValidation($attribute, $validationType);
        }

        return $ret;
    }

    /**
     * Single validation
     *
     * @param $attribute
     * @param $validationType
     *
     * @return bool|mixed
     */
    private function singleValidation($attribute, $validationType)
    {
        $ret = true;
        if (in_array($validationType, $this->validationTypes)) {
            $lang = Lang::getInstance();
            $value = $attribute->getValue();
            switch ($validationType) {
                case self::VALIDATION_NOTNULL:
                    if($attribute->getName()=="company_osh_orgtype" ||
                            $attribute->getName()=="company_osh_bussinessector"){
                        $value=$attribute->getSelectedValues();
                    }
                     if($attribute->getName()=="company_osh_socialdialoguepartner"){
                        $value="true";
                    }
                 //   if($attribute->getName()=="company_osh_logoimage"){
                   //     if(!isset($value['content'])){
                 //        $value = null;
                    //    }
                 //   }
                    if (! ($ret = $this->validateNull($value))) {
                        $messageBus = MessageBus::getInstance();
                        $messageBus->put($attribute->getName(), $lang->get($validationType));
                    }
                    break;
                case self::VALIDATION_NUMERIC:
                    if (! ($ret = $this->validateNumeric($value))) {
                        $messageBus = MessageBus::getInstance();
                        $messageBus->put($attribute->getName(), $lang->get($validationType));
                    }
                    break;
                case self::VALIDATION_SIZE:
                    $size = $attribute->getMaxLength();
                    if (! ($ret = $this->validateSize($value, $size))) {
                        $messageBus = MessageBus::getInstance();
                        $messageBus->put($attribute->getName(), $lang->get($validationType) . $size);
                    }
                    break;
                case self::VALIDATION_EMAIL:
                    if (! ($ret = $this->validateEmail($value))) {
                        $messageBus = MessageBus::getInstance();
                        $messageBus->put($attribute->getName(), $lang->get($validationType));
                    }
                    break;
                case self::VALIDATION_URL:
                    if (! ($ret = $this->validateURL($value))) {
                        $messageBus = MessageBus::getInstance();
                        $messageBus->put($attribute->getName(), $lang->get($validationType));
                    }
                    break;
                case self::VALIDATION_CAPTCHA:
                    if (! ($ret = $this->validateCaptcha($value))) {
                        $messageBus = MessageBus::getInstance();
                        $messageBus->put($attribute->getName(), $lang->get($validationType));
                    }
                break;
            }

        }

        return $ret;
    }

    /**
     * Sanitize an attribute
     *
     * @param $attribute
     */
    public function sanitize($attribute)
    {
        switch ($attribute->getType()) {
            case Attribute::TYPE_EMAIL:
                $attribute->setValue(filter_var($attribute->getValue(), FILTER_VALIDATE_EMAIL));
                break;
            case Attribute::TYPE_URL:
                $attribute->setValue(filter_var($attribute->getValue(), FILTER_SANITIZE_URL));
                break;
            default:
                $sanitizedString = filter_var($attribute->getValue(), FILTER_SANITIZE_STRING);
                $attribute->setValue(preg_replace("/[^A-Za-z0-9 ]/", '', $sanitizedString));
                break;
        }
    }

    /**
     * Validate The value received is the one rendered in the captcha
     * @param $value
     *
     * @return bool
     */
    private function validateCaptcha($value)
    {
        return ($_SESSION['securimage_code_value']['default'] === strtolower($value));
    }
    /**
     * Validate the value is not null
     *
     * @param $value
     *
     * @return bool
     */
    private function validateNull($value)
    { 
		//if($value == null){
       //     return false;
       // }else{
       //     return true;
        //}
		 return ! empty($value);
    }

    /**
     * Validate the value is numeric
     *
     * @param $value
     *
     * @return bool
     */
    private function validateNumeric($value)
    {
        return is_numeric($value);
    }

    /**
     * Validate the value is less or equal than the specified size
     *
     * @param $value
     *
     * @return bool
     */
    private function validateSize($value, $size)
    {
        return (strlen($value) <= $size);
    }

    /**
     * Validate the value is a valid email address
     *
     * @param $value
     *
     * @return mixed
     */
    private function validateEmail($value)
    {
        
        if($value != ''){
            return filter_var($value, FILTER_VALIDATE_EMAIL);
        }else{
            return TRUE;
        }

    }

    /**
     * Validate the value is a valid URL
     *
     * @param $value
     *
     * @return mixed
     */
    private function validateURL($value)
    {
        return filter_var($value, FILTER_VALIDATE_URL);
    }
}