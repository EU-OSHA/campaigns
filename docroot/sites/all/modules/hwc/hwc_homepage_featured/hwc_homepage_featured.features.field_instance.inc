<?php
/**
 * @file
 * hwc_homepage_featured.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function hwc_homepage_featured_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'entityqueue_subqueue-featured_partner-eq_node'
  $field_instances['entityqueue_subqueue-featured_partner-eq_node'] = array(
    'bundle' => 'featured_partner',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'entityqueue_subqueue',
    'field_name' => 'eq_node',
    'label' => 'Queue items',
    'required' => FALSE,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'entityqueue',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'size' => 60,
      ),
      'type' => 'entityqueue_dragtable',
      'weight' => 0,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Queue items');

  return $field_instances;
}
