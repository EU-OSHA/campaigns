<?php
//error_reporting(E_ERROR | E_WARNING | E_PARSE);
// Enviroment constants
ini_set('display_errors', false);
define('APP_ROOT', dirname($_SERVER['SCRIPT_FILENAME']) . '/');
$phpSelf = pathinfo($_SERVER['PHP_SELF']);
define('APP_URL', 'http://' . $_SERVER['HTTP_HOST'] . $phpSelf['dirname'] . '/');
define('HTTP_HOST', 'http://' . $_SERVER['HTTP_HOST'] . '/');

define('APP_PORT', intval($_SERVER['SERVER_PORT']) != 80 ? ':' . $_SERVER['SERVER_PORT'] : '');
define('APP_CONFIG', APP_ROOT . 'config/');


/* Drupal bootstrap procedure */ 
//define('DRUPAL_ROOT', realpath(__DIR__ . '/../../')); 
//require_once DRUPAL_ROOT . '/includes/bootstrap.inc'; 
//$base_url = $_SERVER['REQUEST_SCHEME'] . '://' . $_SERVER['HTTP_HOST'];
//drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL); 
//global $user; 
//
//$user->roles content is array(2) {
//  [13]=>
//  string(10) "supervisor"
//  [12]=>
//  string(16) "campaign partner"
//}




//if (isset($_COOKIE['PHPSESSID']) && !empty($_COOKIE['PHPSESSID'])) {
//     unset($_COOKIE['PHPSESSID']);
//    setcookie('PHPSESSID', '', time()-3600, '/');
//}






// Autoloader
require(APP_ROOT . 'lib/dwoo/lib/dwooAutoload.php');
require(APP_ROOT . 'Autoloader.php');
// Session start
$session = Session::getInstance();
$session->start();
// Security nonce
$nonce  = chr(mt_rand(97, 122)) . substr(md5(time()), 1);
$params = Parameters::getInstance();
$params->set('nonce', $nonce);
// Dispatcher
$dispatcher = new Dispatcher();
$dispatcher->dispatch();
