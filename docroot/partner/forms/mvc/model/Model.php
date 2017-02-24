<?php

/**
 * Model.php
 * Class for models
 * @author Eduardo Martos (eduardo.martos.gomez@everis.com)
 */
class Model {

    /** @var $attributes Array of attributes */
    protected $attributes;

    /** @var $cdbMap Array CDB map of the current entity */
    protected $cdbMap;

    /** @var $cdbMapAppform  Array CDB map for AppForm */
    protected $cdbMapAppform;

    /** @var $cdbMapMF Array CDB map for MF */
    protected $cdbMapMF;

    /** @var $sections Array Sections of the current entity */
    protected $sections;

    public function getCdbMap() {
        return $this->cdbMap;
    }

    /**
     * Class constructor
     *
     * @param $entity
     */
    public function __construct($entity) {
        if (isset($entity) && !empty($entity)) {
            $this->initializeAttributes($entity);
        }
    }

    /**
     * Load the model
     *
     * @param string $sessionID
     */
    public function load($sessionID = '') {
        $session = Session::getInstance();
        $url = "$_SERVER[REQUEST_URI]";
        $start = strstr($url, 'route');
        $start2 = strstr($url, 'session_id');
        if(isset($_SESSION['printable']) && $_SESSION['printable']){
            $this->loadFromCDB($this->cdbMap, $sessionID);
            $this->saveSession();
        }elseif ($session->isSessionReady()) {
            $sesionAttribute = $session->getAttribute(Constants::SESSIONID_NAME);
            if ($sesionAttribute == "" || isset($start2) || $start2 != '') {
                $this->loadFromSession();
            } else {
                $this->loadFromCDB($this->cdbMap, $sesionAttribute);
            }
        } else {

            $params = Parameters::getInstance();
            if ($params->getUrlParamValue('no_session_id')) {
                $this->loadFromCDB($this->cdbMap);
            } else {
                $this->loadFromCDB($this->cdbMap, $sessionID);
            }
            $this->saveSession();
        }
    }

    /**
     * Load from session
     */
    private function loadFromSession() {
        $session = Session::getInstance();
        if ($this->attributes) {
            foreach ($this->attributes as $name => &$attribute) {
                $attribute->setValue($session->getAttribute($attribute->getName()));
                if ($attribute->getType() == Attribute::TYPE_DROPDOWN) {
                    $attribute->setSelectedValues($session->getAttribute($attribute->getName() . '_selected'));
                    
                }
                if ($attribute->getType() == Attribute::TYPE_DROPDOWN_MULTIPLE) {
                    $cdbMap = $this->getCdbMap();
                    $cdb = CDB::getInstance($cdbMap);
                    $valor = $cdb->getDropdown($name);
                    $attribute->setValue($valor);
                    $attribute->setSelectedValues($session->getAttribute($attribute->getName() . '_selected'));
                }
                //$this->filter($attribute);
            }
        }
    }

    /**
     * Initialize the attributes of the current entity
     *
     * @param $entity
     *
     * @throws Exception
     */
    private function initializeAttributes($entity) {
        $params = Parameters::getInstance();
        $model = $params->get('entitiesPath');
        if ($entityDefinition = File::read(APP_ROOT . $model . $entity)) {
            $entityDefinition = json_decode($entityDefinition, true);
            if (isset($entityDefinition) && $entityDefinition !== false) {
                foreach ($entityDefinition['attributes'] as $attributeDefinition) {
                    $this->attributes[$attributeDefinition['name']] = new Attribute($attributeDefinition);
                }
                if (!$params->getUrlParamValue('maintenance_mode')) {
                    $this->cdbMap = isset($entityDefinition['map']) ? $entityDefinition['map'] : false;
                } else {
                    $this->cdbMap = isset($entityDefinition['map_mf']) ? $entityDefinition['map_mf'] : false;
                }
                $this->cdbMapAppform = $entityDefinition['map'];
                $this->cdbMapMF = $entityDefinition['map_mf'];
                $this->sections = isset($entityDefinition['sections']) ? $entityDefinition['sections'] : false;
            } else {
                throw new OshException("data_unavailable", 500);
            }
        }
    }

    /**
     * Load from the CDB
     *
     * @param        $cdbMap
     * @param string $sessionId
     */
    private function loadFromCDB($cdbMap, $sessionId = '') {
        $value = false;
        $cdb = CDB::getInstance($cdbMap, $sessionId, true);
        foreach ($this->attributes as $name => &$attribute) {
            // If a callback is defined, invoke the callback
            if ($callback = $attribute->getCallback()) {
                if (method_exists($cdb, $callback)) {
                    $value = $cdb->$callback();
                }
                // If no callback is defined, check the attribute type to determine the call
            } else {
                $name = $attribute->getName();
                $type = $attribute->getType();
                if ($type == Attribute::TYPE_DROPDOWN || $type == Attribute::TYPE_DROPDOWN_MULTIPLE) {
                    $value = $cdb->getDropdown($name);
                } else {
                    if ($type == Attribute::TYPE_IMAGE) {
                        //(CRG - Lo cambio por un GET al cambiar por URL en vez de base64)
                        //   $value = $cdb->getImage($name);
                        //(/CRG - Lo cambio por un GET al cambiar por URL en vez de base64)
                        $value = $cdb->get($name);
                    } else {
                        $value = $cdb->get($name);
                    }
                }
            }
            if ($value) {
                $attribute->setValue($value);
            }
        }
    }

    /**
     * Send the data to be updated in CDB
     *
     * @param $fields
     *
     * @return bool
     */
    public function saveToCDB($fields) {
        $cdb = CDB::getInstance(null);
        $cdb->updateData($fields);

        return true;
    }

    /**
     * Retrieve all the attributes
     * @return Array
     */
    public function getAttributes() {
        return $this->attributes;
    }

    /**
     * Retrieve the values of all the attributes
     * @return Array
     */
    public function getAttributesValues() {
        $values = array();
        foreach ($this->attributes as $name => $attribute) {
            $values[$attribute->getName()] = $attribute->getValue();
        }

        return $values;
    }

    /**
     * Retrieve the selected values
     * @return Array
     */
    public function getSelectedValues() {
        $values = array();
        foreach ($this->attributes as $name => $attribute) {
            $values[$attribute->getName()] = $attribute->getSelectedValues();
        }

        return $values;
    }

    /**
     * Retrieve the loaded sections
     * @return Array
     */
    public function getSections() {
        return $this->sections;
    }

    /**
     * Validate the attributes
     *
     * @param bool|string $attribute
     * @param bool        $section
     *
     * @return bool
     */
    public function validate($attribute = false, $section = false) {
        $ret = true;
        $validator = new Validator();
        if ($attribute) {
            // Single attribute validation
            if (isset($this->attributes[$attribute])) {
                $ret = $validator->validate($this->attributes[$attribute]);
            }
        } else {
            // Validation of all attributes
            foreach ($this->attributes as $attribute) {
                if (!$section || ($section && $attribute->getSection() == $section)) {
                    $ret &= $validator->validate($attribute);
                }
            }
        }

        return $ret;
    }

    /**
     * Retrieve an attribute
     *
     * @param $attribute
     *
     * @return bool
     */
    public function get($attribute) {
        return (isset($this->attributes[$attribute])) ? $this->filter($this->attributes[$attribute->getValue()]) : false;
    }

    /**
     * Set an attribute
     *
     * @param Attribute $attribute
     * @param mixed     $value
     * @param bool      $persistence
     */
    public function set($attribute, $value, $persistence = false) {
        if (isset($this->attributes[$attribute])) {
            $this->attributes[$attribute]->setValue($value);
            if ($persistence) {
                $session = Session::getInstance();
                $session->setAttribute($attribute, $value);
            }
        }
    }

    /**
     * Save the send values in session
     */
    public function saveSession() {
        $session = Session::getInstance();
        foreach ($this->attributes as $name => $attribute) {
            $session->setAttribute($attribute->getName(), $attribute->getValue());

            if ($attribute->getType() == Attribute::TYPE_DROPDOWN || $attribute->getType() == Attribute::TYPE_DROPDOWN_MULTIPLE) {
                $session->setAttribute($attribute->getName() . '_selected', $attribute->getSelectedValues());
            }
        }
        $params = Parameters::getInstance();
        $session->setAttribute($params->get('route') . '_' . Session::STORED_IN_SESSION, true);
    }

    /**
     * Set the attribute with all its properties
     *
     * @param $attribute
     */
    public function setWholeAttribute($attribute) {
        if (isset($this->attributes[$attribute->getName()])) {
            $this->attributes[$attribute->getName()] = $attribute;
        }
    }

    /**
     * Get the cdb name of an attribute, based on its html name
     *
     * @param $attribute
     *
     * @return null
     */
    public function getTranslation($attribute) {
        if (isset($this->cdbMap[$attribute->getName()])) {
            return $this->cdbMap[$attribute->getName()];
        }

        return null;
    }

    /**
     * Set the entity
     *
     * @param $entity
     *
     * @throws \OshException
     */
    public function setEntity($entity) {
        $this->initializeAttributes($entity);
    }

    /**
     * Set the CDB map
     *
     * @param $update
     */
    public function setCdbMap($update = false) {
        $params = Parameters::getInstance();
        if (!$params->getUrlParamValue('maintenance_mode') || !$update) {
            $this->cdbMap = $this->cdbMapAppform;
        } else {
            $this->cdbMap = $this->cdbMapMF;
        }
    }

    public static function base64_to_jpeg($base64_string, $output_file) {
        //        $ifp = fopen($output_file, "w");
        $data = explode(',', $base64_string);
        $datos = (count($data) > 1) ? $data[1] : $data[0];
        $dataMime = base64_decode($datos);
        //Detectamos tipo
        $f = finfo_open();
        $mime_type = finfo_buffer($f, $dataMime, FILEINFO_MIME_TYPE); //tipo de imagen
        switch ($mime_type) {
            case Constants::TYPE_IMAGE_JPEG:
                $output_file .= ".jpg";
                $ifp = fopen($file, "w");
                fwrite($ifp, $dataMime);
                break;
            case Constants::TYPE_IMAGE_GIF://Esta casu�stica (GIFs) no est� probada por falta de tiempo
                $sufix = ".gif";
                $output_file .= $sufix;
                file_put_contents(/* 'img.png' */$output_file, $dataMime);
                break;
            case Constants::TYPE_IMAGE_PNG:
                $sufix = ".png";
                $output_file .= $sufix;
                file_put_contents(/* 'img.png' */$output_file, $dataMime);
                break;

            default:

                break;
        }
        fclose($ifp);
        return $output_file;
    }

    public static function convertParameters($parameters) {
        $parametersArray = explode(",", $parameters);
        $array = array();
        foreach ($parametersArray as $i => $param) {
            $param = str_replace(array("(", ")"), "", $param);
            $p = explode("|", $param);
            $key = $p[0];
            $value = $p[1];
            $array[$key] = $value;
        }
        return $array;
    }

    public static function getRandom(array $a) {
        $length = $a['length'];
        $characters = '0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ';
        $randomString = '';
        for ($i = 0; $i < $length; $i++) {
            $randomString .= $characters[rand(0, strlen($characters) - 1)];
        }
        return $randomString;
    }

    /*
     *  Uploads  
     *  
     *  @return list of photos
     *      */

//    public static function uploadPhoto($photo) {
//        $photosFolder = Constants::PHOTOS_FOLDER;
//        $photosFolderURL = str_replace(array("\\"), "/", $photosFolder);
//
//        $dirname = dirname($_SERVER["SCRIPT_FILENAME"]); //"C:/wamp/www/osha"
//        $dirnameFolderArray = explode("/", $dirname);
//        $parentFolder = $dirnameFolderArray[count($dirnameFolderArray) - 1]; //osha
//
//        $documentRoot = $_SERVER["DOCUMENT_ROOT"]; //"C:/wamp/www/"
////        $path = $realpath . $photosFolder;
//        $relativePath = $parentFolder . $photosFolder;
//        $publicPath = "/" . $relativePath;
//        $path = $documentRoot . $relativePath;
//        if (strtoupper(substr(PHP_OS, 0, 3)) === 'WIN') {
//            $path = str_replace(array("/", /* "\\" */), "\\\\", $path);
//        }
//        //Preparamos un nombre para el fichero aleatorio que no exista 
//        do {
//            $a = array("length" => 10);
//            $fileName = Model::getRandom($a);
//            $fileNameComplete = $fileName /* . ".jpg" */;
//            $filePath = $path . $fileNameComplete;
//        } while (file_exists($filePath . ".png") || file_exists($filePath . ".jpg"));
//        $privateRoute = Model::base64_to_jpeg($photo, $filePath);
//        $Protocol = ($_SERVER["HTTPS"]) ? "https://" : "http://";
////        $url = $Protocol. $_SERVER['SERVER_NAME']. $publicPath . $fileNameComplete;
////        $url = $Protocol. $_SERVER['SERVER_NAME']. $publicPath . $fileNameComplete;
//        $documentRootReal = str_replace(array("/"), "\\\\", $documentRoot);
//        $server = $Protocol . $_SERVER['SERVER_NAME'] . "/";
//        $secondPart = str_replace(array($documentRootReal), "", $privateRoute);
//        $secondPart = str_replace(array("\\\\"), "/", $secondPart);
////        $url = str_replace($documentRootReal, $server, $privateRoute);
//        $url = $server . $secondPart;
//        return $url;
//    }

}
