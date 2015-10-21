<?php

/**
 * @file
 * CTools plugin 'description_display' for text.module.
 */

$plugin = array(
  'callback' => 'fel_field_text_description_display_columns',
);

/**
 * Plugin callback.
 */
function fel_field_text_description_display_columns($field, $instance, $form) {
  if (!$instance['settings']['text_processing']) {
    return array('value');
  }
  if ($instance['widget']['type'] == 'text_textarea_with_summary') {
    return array();
  }
}
