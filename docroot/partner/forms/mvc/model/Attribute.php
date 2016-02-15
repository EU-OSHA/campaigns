<?php

/**
 * Attribute.php
 * Class for storing attribute values
 * @author Eduardo Martos (eduardo.martos.gomez@everis.com)
 */
class Attribute
{
    /** Constant for dropDown type */
    const TYPE_DROPDOWN = 'dropdown';
    /** Constant for dropDown multiple type */
    const TYPE_DROPDOWN_MULTIPLE = 'dropdown_multiple';
    /** Constant for email type */
    const TYPE_EMAIL = 'email';
    /** Constant for URL type */
    const TYPE_URL = 'url';
    /** Constant for image type */
    const TYPE_IMAGE = 'image';
    /** Constant for radio type */
    const TYPE_RADIO = 'radio';
    /** Constant for checkbox type */
    const TYPE_CHECKBOX = 'checkbox';
    /** Constant for contactchange type */
    const TYPE_CONTACTCHANGE = 'contact_change';

    /** @var string Name */
    protected $name;
    /** @var string Section this attribute belongs to */
    protected $section;
    /** @var Callback method associated to this attribute */
    protected $callback;
    /** @var Validator associated to this attribute */
    protected $validator;
    /** @var string Type of field */
    protected $type;
    /** @var string Label of the field */
    protected $label;
    /** @var string Placeholder of the text */
    protected $placeholder;
    /** @var bool Public Profile of the element */
    protected $publicProfile;
    /** @var string Help text for the field */
    protected $helpText;
    /** @var string Value */
    protected $value;
    /** @var $extended string Extended attributes */
    protected $extended;
    /** @var $selectedValues array */
    protected $selectedValues;
    /** @var $validation bool Switch to show/hide the validation widget */
    protected $validation;
    
    protected $maxLength;
    
    protected $helpTextImageLoaded;
    /**
     * Class constructor
     *
     * @param string $attribute
     */
    public function __construct($attribute)
    {
        $this->name          = $this->assignProperty($attribute, 'name');
        $this->section       = $this->assignProperty($attribute, 'section');
        $this->callback      = $this->assignProperty($attribute, 'callback');
        $this->validator     = $this->assignProperty($attribute, 'validator');
        $this->type          = $this->assignProperty($attribute, 'type');
        $this->label         = $this->assignProperty($attribute, 'label');
        $this->placeholder   = $this->assignProperty($attribute, 'placeholder');
        $this->publicProfile = $this->assignProperty($attribute, 'publicProfile');
        $this->helpText      = $this->assignProperty($attribute, 'helpText');
        $this->validation    = $this->assignProperty($attribute, 'validator');
        $this->maxLength    = $this->assignProperty($attribute, 'maxLength');
        $this->helpTextImageLoaded   = $this->assignProperty($attribute, 'helpTextImageLoaded');
    }

    /**
     * Safe assignment of properties
     *
     * @param $container
     * @param $name
     *
     * @return string
     */
    private function assignProperty($container, $name)
    {
        return isset($container[$name]) ? $container[$name] : '';
    }

    /**
     * Retrieve the selected values
     * @return array
     */
    public function getSelectedValues()
    {
        return $this->selectedValues;
    }

    /**
     * Set the selected values
     *
     * @param array $selectedValues
     */
    public function setSelectedValues($selectedValues)
    {
        if ($this->type == self::TYPE_DROPDOWN_MULTIPLE && $selectedValues) {
            if (is_array($selectedValues)) {
                foreach ($selectedValues as $selectedValue) {
                    if (isset($this->value[$selectedValue])) {
                        $this->selectedValues[$selectedValue] = $this->value[$selectedValue];
                    } else {
                        if ($key = array_search($selectedValue, $this->value)) {
                            $this->selectedValues[$key] = $selectedValue;
                        }
                    }
                }
            }
        } else {
            $this->selectedValues = $selectedValues;
        }
    }

    /**
     * Retrieve the name of the attribute
     *
     * @return string
     */
    public function getName()
    {
        return $this->name;
    }

    /**
     * Set the name of the attribute
     *
     * @param string $name
     */
    public function setName($name)
    {
        $this->name = $name;
    }

    /**
     * Retrieve the section of the attribute
     *
     * @return string
     */
    public function getSection()
    {
        return $this->section;
    }

    /**
     * Set the section of the attribute
     *
     * @param string $section
     */
    public function setSection($section)
    {
        $this->section = $section;
    }

    /**
     * Retrieve the callback of the attribute
     *
     * @return callable
     */
    public function getCallback()
    {
        return $this->callback;
    }

    /**
     * Set the callback of the attribute
     *
     * @param callable $callback
     */
    public function setCallback($callback)
    {
        $this->callback = $callback;
    }

    /**
     * Retrieve the validator of the attribute
     *
     * @return Validator
     */
    public function getValidator()
    {
        return $this->validator;
    }

    /**
     * Set the validator of the attribute
     *
     * @param Validator $validator
     */
    public function setValidator($validator)
    {
        $this->validator = $validator;
    }

    /**
     * Retrieve the type of the attribute
     *
     * @return string
     */
    public function getType()
    {
        return $this->type;
    }

    /**
     * Set the type of the attribute
     *
     * @param string $type
     */
    public function setType($type)
    {
        $this->type = $type;
    }

    /**
     * Retrieve the value of the attribute
     *
     * @return string
     */
    public function getValue()
    {
        return $this->value;
    }

    /**
     * Set the value of the attribute
     *
     * @param string $value
     */
    public function setValue($value)
    {
        if (is_array($value)) {
            if (array_key_exists('selected', $value)) {
                $this->selectedValues = $value['selected'];
            }
            if (array_key_exists('values', $value)) {
                $value = $value['values'];
            }
        } else {
            $value = trim($value);
            // Convert the data:image/type;base64=,... to an array
            if ($this->type == self::TYPE_IMAGE) {
                $value = explode(';', $value);
                if (is_array($value) && count($value) > 1) {
                    $mimeType = str_replace('data:', '', $value[0]);
                    $data     = explode(',', $value[1]);
                    if (is_array($data) && count($data) > 1) {
                        $data  = $data[1];
                        $value = array(
                            'mime'    => $mimeType,
                            'content' => $data,
                        );
                    }
                }
            }
        }
        $this->value = $value;
    }

    /**
     * Retrieve an extended attribute
     *
     * @param $key
     *
     * @return string
     */
    public function getExtended($key)
    {
        return isset($this->extended[$key]) ? $this->extended[$key] : '';
    }

    /**
     * Set extended attributes
     *
     * @param $key
     * @param $value
     */
    public function setExtended($key, $value)
    {
        $this->extended[$key] = $value;
    }

    /**
     * @return string
     */
    public function getLabel()
    {
        return $this->label;
    }

    /**
     * @param string $label
     */
    public function setLabel($label)
    {
        $this->label = $label;
    }

    /**
     * @return string
     */
    public function getPlaceholder()
    {
        return $this->placeholder;
    }

    /**
     * @param string $placeholder
     */
    public function setPlaceholder($placeholder)
    {
        $this->placeholder = $placeholder;
    }

    /**
     * @return bool
     */
    public function getPublicProfile()
    {
        return $this->publicProfile;
    }

    /**
     * @param bool $publicProfile
     */
    public function setPublicProfile($publicProfile)
    {
        $this->publicProfile = $publicProfile;
    }

    /**
     * @return string
     */
    public function getHelpText()
    {
        return $this->helpText;
    }

    /**
     * @param string $helpText
     */
    public function setHelpText($helpText)
    {
        $this->helpText = $helpText;
    }

    /**
     * @return string
     */
    public function getValidation()
    {
        return $this->validation;
    }

    /**
     * @param string $validation
     */
    public function setValidation($validation)
    {
        $this->validation = $validation;
    }
    
        /**
     * @return string
     */
    public function getMaxLength()
    {
        return $this->maxLength;
    }

    /**
     * @param string $maxLength
     */
    public function setMaxLength($maxLength)
    {
        $this->maxLength = $maxLength;
    }
            /**
     * @return string
     */
    public function getHelpTextImageLoaded()
    {
        return $this->helpTextImageLoaded;
    }

    /**
     * @param string $helpTextImageLoaded
     */
    public function setHelpTextImageLoaded($helpTextImageLoaded)
    {
        $this->helpTextImageLoaded = $helpTextImageLoaded;
    }
}