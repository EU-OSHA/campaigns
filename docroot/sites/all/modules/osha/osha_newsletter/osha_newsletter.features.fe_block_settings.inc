<?php
/**
 * @file
 * osha_newsletter.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function osha_newsletter_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['osha_newsletter-osha_newsletter_image'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'osha_newsletter_image',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'osha_newsletter',
    'node_types' => array(),
    'pages' => '<front>',
    'roles' => array(),
    'themes' => array(
      'hwc_frontend' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'hwc_frontend',
        'weight' => -56,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => 'Newsletter',
    'visibility' => 1,
  );

  $export['osha_newsletter-osha_newsletter_latest'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'osha_newsletter_latest',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'osha_newsletter',
    'node_types' => array(),
    'pages' => 'node/129',
    'roles' => array(),
    'themes' => array(
      'hwc_frontend' => array(
        'region' => 'sidebar_second',
        'status' => 1,
        'theme' => 'hwc_frontend',
        'weight' => -35,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => 'Our latest newsletters',
    'visibility' => 1,
  );

  $export['osha_newsletter-osha_newsletter_subscribe'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'osha_newsletter_subscribe',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'osha_newsletter',
    'node_types' => array(),
    'pages' => 'node/129',
    'roles' => array(),
    'themes' => array(
      'hwc_frontend' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'hwc_frontend',
        'weight' => -30,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => 'OSHMail newsletter',
    'visibility' => 1,
  );

  $export['osha_newsletter-osha_newsletter_subscribe_extra'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'osha_newsletter_subscribe_extra',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'osha_newsletter',
    'node_types' => array(),
    'pages' => 'node/129',
    'roles' => array(),
    'themes' => array(
      'hwc_frontend' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'hwc_frontend',
        'weight' => -57,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => 'Campaign newsletter',
    'visibility' => 1,
  );

  return $export;
}
