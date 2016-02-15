<?php
/**
 * @file
 * hwc_practical_tool.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function hwc_practical_tool_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['hwc_practical_tool-hwc_practical_tool_language_list'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'hwc_practical_tool_language_list',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'hwc_practical_tool',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'hwc_frontend' => array(
        'region' => '',
        'status' => 0,
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
    'title' => '',
    'visibility' => 0,
  );

  $export['hwc_practical_tool-hwc_practical_tool_listing'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'hwc_practical_tool_listing',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'hwc_practical_tool',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'hwc_frontend' => array(
        'region' => '',
        'status' => 0,
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
    'title' => '',
    'visibility' => 0,
  );

  return $export;
}
