<?php
/**
 * @file
 * hwc_social_sprites.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function hwc_social_sprites_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['menu_block-3'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 3,
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'menu_block',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'hwc_frontend' => array(
        'region' => 'footer',
        'status' => 1,
        'theme' => 'hwc_frontend',
        'weight' => 1,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['menu_block-4'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 4,
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'menu_block',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'hwc_frontend' => array(
        'region' => 'footer',
        'status' => 1,
        'theme' => 'hwc_frontend',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['printfriendly-printfriendly'] = array(
    'cache' => 8,
    'custom' => 0,
    'delta' => 'printfriendly',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'printfriendly',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'hwc_frontend' => array(
        'region' => 'above_header',
        'status' => 1,
        'theme' => 'hwc_frontend',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['text_resize-0'] = array(
    'cache' => 4,
    'custom' => 0,
    'delta' => 0,
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'text_resize',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'hwc_frontend' => array(
        'region' => 'above_header',
        'status' => 1,
        'theme' => 'hwc_frontend',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  return $export;
}
