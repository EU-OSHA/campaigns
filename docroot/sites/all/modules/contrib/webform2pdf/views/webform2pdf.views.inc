<?php

/**
 * @file
 * Views hooks implemented for the Webform2pdf module.
 */

/**
 * Implements hook_views_data_alter().
 */
function webform2pdf_views_data_alter(&$data){
  // View submission link.
  $data['webform_submissions']['download_pdf'] = array(
    'title' => t('Download PDF'),
    'help' => t('Provide a simple link to pdf.'),
    'real field' => 'serial',
    'field' => array(
      'handler' => 'webform2pdf_handler_field_submission_download_pdf',
      'click sortable' => TRUE,
      'real field' => 'sid',
      'link_type' => 'download pdf',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
}

/**
 * Implements hook_views_default_views_alter().
 */
function webform2pdf_views_default_views_alter(&$views) {
  if (isset($views['webform_submissions'])) {
    $handler =& $views['webform_submissions']->display['default']->handler;
    $download_pdf = array(
      'id' => 'download_pdf',
      'table' => 'webform_submissions',
      'field' => 'download_pdf',
      'label' => '',
      'element_label_colon' => FALSE,
      'access_check' => 0,
    );
    $handler->display->display_options['fields']['download_pdf'] = $download_pdf;
    $handler->display->display_options['style_options']['columns']['download_pdf'] = 'view_submission_1';
  }
}