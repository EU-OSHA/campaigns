<?php
/**
 * @file
 * hwc_homepage_featured.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function hwc_homepage_featured_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'eq_node'
  $field_bases['eq_node'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(
      0 => 'entityqueue_subqueue',
    ),
    'field_name' => 'eq_node',
    'indexes' => array(
      'target_id' => array(
        0 => 'target_id',
      ),
    ),
    'locked' => 1,
    'module' => 'entityreference',
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'handler' => 'entityqueue',
      'handler_settings' => array(
        'behaviors' => array(
          'entityqueue' => array(
            'status' => 1,
          ),
        ),
      ),
      'target_type' => 'node',
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  return $field_bases;
}
