<?php
/**
 * Session.php
 * Session management singleton
 * @author Juan José Arol Rosa <Juan.Jose.Arol.Rosa@everis.com>
 * @author Eduardo Martos (eduardo.martos.gomez@everis.com)
 */
final class Session {
    /**
     * Constant for the stored in session switch
     */
    const STORED_IN_SESSION = 'stored_in_session';
    /**
     * @var Session status
     */
    private $status = false;

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
     * @return \Session
     */
    public static function getInstance() {
        static $inst = null;
        if ($inst === null) {
            $class = __CLASS__;
            $inst = new $class();
        }
        return $inst;
    }

    /**
     * Start a new session
     * @return bool|\Session
     */
    public function start() {
        if ($this->status === false && !headers_sent() && session_status() !== PHP_SESSION_ACTIVE) {
            $this->status = session_start();
        }
        return $this->status;
    }

    /**
     * Destroy an existing session
     * @param string $sessionToken
     *
     * @return bool
     */
    public function destroy($sessionToken = '') {
        if ($this->status !== false) {
            $this->status = false;
            if (!$sessionToken) {
                $sessionToken = $this->getSessionToken();
            }
            foreach ($_SESSION as $key => $value) {
//                if (strpos($key, $sessionToken) !== false) {
                    unset($_SESSION[$key]);
//                }
            }
            $ret = !$this->status;
        } else {
            $ret = false;
        }
        return $ret;
    }

    /**
     * Retrieve the session token
     * @return string
     */
    public function getSessionToken() {
        $params = Parameters::getInstance();
        $sessionToken = $params->getUrlParamValue('session_id');

        return $sessionToken;
    }

    /**
     * Retrieve an attribute from the session
     * @param $name
     * @return bool
     */
    public function getAttribute($name) {
        $params = Parameters::getInstance();
        $name = $this->getSessionToken() . '_' . $name;
        $value = $params->get($name);
        return $value;
    }

    /**
     * Set a parameter in the current session
     * @param $name
     * @param $value
     */
    public function setAttribute($name, $value) {
        $params = Parameters::getInstance();
        $name = $this->getSessionToken() . '_' . $name;
        $params->set($name, $value, true);
    }

    /**
     * Tell if the session is loaded for the current context or not
     * @return bool
     */
    public function isSessionReady() {
        $params = Parameters::getInstance();
        $name = $this->getSessionToken() . '_' . $params->get('route') . '_' . self::STORED_IN_SESSION;
        $value = $params->get($name) ? true : false;
        // Store the session ID in SESSION
        $params->setUrlParamValue('session_id', $params->getUrlParamValue('session_id'));
        return $value;
    }
}