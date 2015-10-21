<?php

/**
 * @file
 * CTools plugin 'description_display' for field_collection_table.module.
 */

$plugin = array(
  'callback' => 'fel_fields_field_collection_table_process_description_display',
);

/**
 * CTools plugin callback.
 */
function fel_fields_field_collection_table_process_description_display($field, $instance, &$form) {
  $form['#after_build'][] = 'fel_fields_field_collection_table_after_build';
}
