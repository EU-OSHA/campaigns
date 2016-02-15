<?php
/**
 * Parameters.php
 * Parameters and configuration singleton
 * @author Eduardo Martos (eduardo.martos.gomez@everis.com)
 */
final class Parameters {
    /**
     * @var Array of parameters
     */
    private $params;

    /**
     * Private class constructor so nobody else can instance it
     */
    private function __construct() {}

    /**
     * Private class clone so nobody else can clone it
     */
    private function __clone() {}

    /**
     * Retrieve the persistent instance
     * @return \Parameters
     */
    public static function getInstance() {
        static $inst = null;
        if ($inst === null) {
            $class = __CLASS__;
            $inst = new $class();
            // Load the configuration
            $inst->params = array();
            $configFiles = glob(APP_CONFIG . '*.json');
            foreach ($configFiles as $configFile) {
                if ($config = file_get_contents($configFile)) {
                    $inst->params = array_merge($inst->params, json_decode($config, true));
                }
            }
        }
        return $inst;
    }

    /**
     * Retrieve the value of a parameter
     * @param $name
     * @return bool
     */
    public function get($name) {
        if($name == "mf"){
//            if(strpos($_SERVER['REQUEST_URI'],"session_id")){
//                if(strpos(strtolower($_SERVER['REQUEST_URI']),"mf=true")){
//                    $this->params['mf'] = true;
//                }else{
//                     $this->params['mf'] = false;
//                }
//            }
             if(isset($_REQUEST['session_id'])){
                if(isset($_REQUEST['mf'])){
                    $this->params['mf'] = true;
                }else{
                     $this->params['mf'] = false;
                }
            }
        }
        if (isset($this->params[$name])) {
            $ret = $this->params[$name];
        } else if (isset($_REQUEST[$name])) {
            $ret = $_REQUEST[$name];
        } else if (isset($_SESSION[$name])) {
            $ret = $_SESSION[$name];
        } else {
            $ret = false;
        }
        return $ret;
    }

    /**
     * Retrieve the name of an URL parameter through its configuration key
     * @param $name
     * @return bool
     */
    public function getUrlParam($name) {
        $key = (isset($this->get('urlParams')[$name])) ? $this->get('urlParams')[$name] : '';
        return $key;
    }

    /**
     * Retrieve the value of an URL parameter through its configuration key
     * @param $name
     * @return bool
     */
    public function getUrlParamValue($name) {
        $key = $this->getUrlParam($name);
        $value = $this->get($key);
        return $value;
    }

    /**
     * Set the value of an URL parameter
     * @param $name
     * @param $value
     */
    public function setUrlParamValue($name, $value) {
        $key = $this->getUrlParam($name);
        $this->set($key, str_replace("\"", "''", $value), true);
    }

    /**
     * Set the value of a parameter
     * @param $name
     * @param $value
     * @param $persistent
     */
    public function set($name, $value, $persistent = false) {
        $this->params[$name] = str_replace("\"", "''", $value);
        if ($persistent) {
            $_SESSION[$name] = str_replace("\"", "''", $value);
        }
    }
    public function unsetParam($name, $persistent = false) {
        unset($this->params[$name]);
        if ($persistent) {
            unset($_SESSION[$name]);
        }
    }
}
