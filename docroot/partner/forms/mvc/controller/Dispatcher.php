<?php
/**
 * Dispatcher.php
 * Front controller
 * @author Eduardo Martos (eduardo.martos.gomez@everis.com)
 */
class Dispatcher {
    /**
     * Route the execution
     */
    public function dispatch() {
        // Set the route
        $sessionID = null;
        if(count($_REQUEST) == 0){
            $params = Parameters::getInstance();
            $sessionID = null;
            $params->set('session_id', null, true);
            $params->setUrlParamValue('maintenance_mode', false);
            unset($_SESSION['mainContactChangeCheck']);
//            $this->resetSession();
        }else if(isset ($_REQUEST['session_id'])){
            $sessionID = $_REQUEST['session_id'];
//            $this->resetSession();
        }else{
            
// Check the session ID
        $sessionID = $this->checkSessionID();
        }

        $route = $this->setRoute();
        if (class_exists($route) || class_exists(ucfirst(($route)))) {
            try {
                // Set the application context
                $this->setContext($sessionID);
                // Execute the controller
                $controller = new $route();
                if (method_exists($controller, 'executeAction')) {
                    $controller->executeAction();
                    
                    
                }
                $controller->execute();
            } catch (CDBException $e) {
                print $e->getMessage();
            } catch (Exception $e) {
                print $e->getMessage();
            }
        }
    }

    private function setContext($sessionID) {
        $params = Parameters::getInstance();
        // Check the session ID
        $this->checkSessionID();
        // SessionID provided: set the context via CDB
        if ($sessionID && !$params->getUrlParamValue('no_session_id')) {
            CDB::getInstance(null, $sessionID);
        // SessionID not provided: set the context by default
        } else {
            // Grace period does not apply
            $params->setUrlParamValue('graceperiod', false);
            // As requested, the default entity is OCP
            $params->setUrlParamValue('entity', 'ocp');
            // When no SessionID provided, it is a New Applicant
            $params->setUrlParamValue('partner_type', 'new');
            // When no SessionID provided, it cannot be a Maintenance Profile
            $params->setUrlParamValue('maintenance_mode', false);
            // When no SessionID provided, the form cannot be locked
            $params->setUrlParamValue('locked', false);
            // When no SessionID provided, the application cannot guess if it is a Potential Partner
            $params->setUrlParamValue('potential', false);
        }
    }

    /**
     * Check the session ID and retrieve it if defined
     * @return bool|string
     */
    private function checkSessionID() {
        // If there is a previous session ID different than the current one, reset the session
        $this->resetSession();
        // Check if session ID is defined
        $params = Parameters::getInstance();
        if ($params->get('cdb')['debug'] == 'true') {
            if (!$ret = $params->getUrlParamValue('session_id')) {
                $ret = uniqid();
                $params->setUrlParamValue('session_id', $ret);
            }
        } else {
            // If no SessionID provided, the application set a random one
            if (!$params->getUrlParamValue('session_id')) {
                $ret = uniqid('', true);
                $params->setUrlParamValue('session_id', $ret);
                // Set a switch to avoid the query to the CDB
                $params->setUrlParamValue('no_session_id', true);
            } else {
                $ret = $params->getUrlParamValue('session_id');
            }
        }
        return $ret;
    }

    private function resetSession()
    {
        $params          = Parameters::getInstance();
        $key             = $params->getUrlParam('session_id');
        $cachedSessionID = isset($_SESSION[$key]) ? $_SESSION[$key] : false;
        $sessionID = $params->get($key);
        $newAccess = $params->get('newAccess');
        if(strtolower($newAccess) == "true"){
            $_SESSION['resetSession'] = true;
            $params->set("newAccess", "false");
        }
        if(isset($_SESSION['resetSession']) && $_SESSION['resetSession']){
            if($params->get('action')=="printable"){
                $_SESSION['printable']=true;
            }
            $mf = $params->get('mf');
            $session = Session::getInstance();
                $session->destroy($cachedSessionID);
                if (isset($_SESSION['osh_category'])) {
                    unset($_SESSION['osh_category']);
                }
                if (isset($_SESSION['osh_leads'])) {
                    unset($_SESSION['osh_leads']);
                }
                if (isset($_SESSION['session_id'])) {
                    unset($_SESSION['session_id']);
                }
                if (isset($_SESSION['locked'])) {
                    unset($_SESSION['locked']);
                }
                if (isset($_SESSION['mf'])) {
                    unset($_SESSION['mf']);
                }
                if (isset($_SESSION['potential'])) {
                    unset($_SESSION['potential']);
                }
                if (isset($_SESSION['ValidatingDialogHidden'])) {
                    unset($_SESSION['ValidatingDialogHidden']);
                }
            setcookie("PHPSESSID", '', time()-3600);
            unset($_SESSION['resetSession']);
            $params->set('mf', $mf, true);
            $params->set($key, $sessionID, true);
        }elseif ($cachedSessionID) {
            $mf=$params->get('mf');
            if ($cachedSessionID != $sessionID) {
                $session = Session::getInstance();
                $session->destroy($cachedSessionID);

                if (isset($_SESSION['osh_category'])) {
                    unset($_SESSION['osh_category']);
                }
                if (isset($_SESSION['osh_leads'])) {
                    unset($_SESSION['osh_leads']);
                }
                if (isset($_SESSION['session_id'])) {
                    unset($_SESSION['session_id']);
                }
                if (isset($_SESSION['locked'])) {
                    unset($_SESSION['locked']);
                }
                if (isset($_SESSION['mf'])) {
                    unset($_SESSION['mf']);
                }
                if (isset($_SESSION['potential'])) {
                    unset($_SESSION['potential']);
                }
                if (isset($_SESSION['ValidatingDialogHidden'])) {
                    unset($_SESSION['ValidatingDialogHidden']);
                }
//                if(!strpos($cachedSessionID, "_")){
//                    setcookie("PHPSESSID", '', time()-3600);
//                }
                if(isset($mf)){
                    $params->set('mf', $mf, true);
                }
                $params->set($key, $sessionID, true);
//                foreach ($_SESSION as $key => $value) {
//                    unset($_SESSION[$key]);
//                }
            }
        }
    }

    /**
     * Set the route
     * @return bool
     */
    private function setRoute() {
        // Maintenance mode
        $params = Parameters::getInstance();
        if ($params->getUrlParamValue('maintenance_mode')) {
            $params->setUrlParamValue('maintenance_mode', true);
            $route = $params->get('maintenanceRoute');
            $params->set('route', $route);
        // Regular controller
        } else {
            $route = $this->getParamValue('route', 'defaultRoute');
        }
        return $route;
    }

    /**
     * Get a param value (with default if not defined)
     * @param $key
     * @param $defaultKey
     * @return bool
     */
    private function getParamValue($key, $defaultKey) {
        $params = Parameters::getInstance();
        if ($params->get($key)) {
            $value = strtolower($params->get($key));
        } else {
            $value = strtolower($params->get($defaultKey));
        }
        $params->set($key, $value);
        return $value;
    }
}