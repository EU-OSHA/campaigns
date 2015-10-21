<?php

/**
 * @file
 * CTools plugin 'description_display' for date.module.
 */

$plugin = array(
  'callback' => 'fel_fields_date_process_description_display',
);

/**
 * Plugin callback.
 */
function fel_fields_date_process_description_display($field, $instance, &$form) {
  if ($field['cardinality'] > 1 or $field['cardinality'] == FIELD_CARDINALITY_UNLIMITED) {
    return;
  }
  if (!empty($form[0]['#description'])) {
    fel_wrapper_replace('date_combo', 'fel_date_combo', $form[0]);
    $form[0]['#fieldset_description'] = $form[0]['#description'];
    if (empty($field['settings']['todate'])) {
      unset($form[0]['#description']);
    }
  }
}
