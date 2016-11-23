<?php
/**
 * @file
 * osha_infographics.ds.inc
 */

/**
 * Implements hook_ds_layout_settings_info().
 */
function osha_infographics_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|infographic|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'infographic';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_2col';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'field_thumbnail',
      ),
      'right' => array(
        1 => 'title_field',
        2 => 'body',
        3 => 'field_file',
        4 => 'field_image',
      ),
    ),
    'fields' => array(
      'field_thumbnail' => 'left',
      'title_field' => 'right',
      'body' => 'right',
      'field_file' => 'right',
      'field_image' => 'right',
    ),
    'classes' => array(
      'layout_class' => array(
        'row' => 'row',
      ),
      'left' => array(
        'col-sm-4' => 'col-sm-4',
      ),
      'right' => array(
        'col-sm-8' => 'col-sm-8',
      ),
    ),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => 1,
  );
  $export['node|infographic|teaser'] = $ds_layout;

  return $export;
}
