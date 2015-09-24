<?php
/**
 * @file
 * Webform to PDF settings form.
 */

/**
 * Overview form of all components for this webform.
 */
function webform2pdf_admin_settings($form, &$form_state) {
  $default = variable_get('webform2pdf_default', '');
  // It is needed because of file upload
  $form['#attributes'] = array('enctype' => 'multipart/form-data');
  $form['base'] = array(
    '#type' => 'fieldset',
    '#title' => t('General settings'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $form['base']['pdf_send_email'] = array(
    '#type' => 'checkbox',
    '#title' => t('Attach PDF as an attachment to the e-mails sent to the form recipients.'),
    '#default_value' => $default['pdf_send_email'],
  );

   //background image
  $form['base']['p_background'] = array(
    '#type' => 'value',
    '#value' => $default['p_background'],
  );

  if ($default['p_background']) {
    $file = file_load($default['p_background']);

    $picture = array(
      'path' => $file->uri,
      'alt' => 'Page background',
      'title' => $file->filename,
    );

    $form['base']['p_background_img'] = array(
      '#type' => 'item',
      '#title' => t('Background image for page'),
      '#markup' => theme('image', $picture),
    );

    $form['base']['p_background_del'] = array(
      '#type' => 'checkbox',
      '#title' => t('Delete this image.'),
    );
  }
  else {
    $form['base']['p_background_file'] = array(
      '#type' => 'file',
      '#title' => t('Background image for page.'),
      '#size' => 60,
      '#description' => t('Upload background image for page. Image will be scaled by page size.'),
    );
  }

  $form['base']['page_format'] = array(
    '#type' => 'select',
    '#title' => t('Paper size'),
    '#default_value' => $default['page_format'],
    '#options' => array(
      '4A0' => '4A0', '2A0' => '2A0', 'A0' => 'A0',
      'A1' => 'A1', 'A2' => 'A2', 'A3' => 'A3', 'A4' => 'A4',
      'A5' => 'A5', 'A6' => 'A6', 'A7' => 'A7', 'A8' => 'A8',
      'A9' => 'A9', 'A10' => 'A10', 'B0' => 'B0', 'B1' => 'B1',
      'B2' => 'B2', 'B3' => 'B3', 'B4' => 'B4', 'B5' => 'B5',
      'B6' => 'B6', 'B7' => 'B7', 'B8' => 'B8', 'B9' => 'B9',
      'B10' => 'B10', 'C0' => 'C0', 'C1' => 'C1', 'C2' => 'C2',
      'C3' => 'C3', 'C4' => 'C4', 'C5' => 'C5', 'C6' => 'C6',
      'C7' => 'C7', 'C8' => 'C8', 'C9' => 'C9', 'C10' => 'C10',
      'RA0' => 'RA0', 'RA1' => 'RA1', 'RA2' => 'RA2',
      'RA3' => 'RA3', 'RA4' => 'RA4', 'SRA0' => 'SRA0',
      'SRA1' => 'SRA1', 'SRA2' => 'SRA2', 'SRA3' => 'SRA3',
      'SRA4' => 'SRA4', 'LETTER' => t('Letter'), 'LEGAL' => t('Legal'),
      'EXECUTIVE' => t('Executive'), 'FOLIO' => t('Folio'),
    ),
  );

  $form['base']['page_orientation'] = array(
    '#type' => 'radios',
    '#title' => t('Page orientation'),
    '#default_value' => $default['page_orientation'],
    '#options' => array(
      'P' => t('Portrait'),
      'L' => t('Landscape'),
    ),
  );

  $form['img'] = array(
    '#type' => 'fieldset',
    '#title' => t('Images size settings'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $form['img']['h_left_logo_size'] = array(
    '#type' => 'textfield',
    '#title' => t('Maximum size of left header logo'),
    '#default_value' => $default['h_left_logo_size'],
    '#size' => 10,
    '#description' => t('Maximum dimensions of the logo on the left side of the header in pixels. Format: width x height. E.g: 270x205'),
  );

  $form['img']['h_right_logo_size'] = array(
    '#type' => 'textfield',
    '#title' => t('Maximum dimensions of right header logo'),
    '#default_value' => $default['h_right_logo_size'],
    '#size' => 10,
    '#description' => t('Maximum dimensions of the logo on the right side of the header in pixels. Format: width x height. E.g: 270x205'),
  );

  $form['img']['f_left_logo_size'] = array(
    '#type' => 'textfield',
    '#title' => t('Maximum dimensions of left footer logo'),
    '#default_value' => $default['f_left_logo_size'],
    '#size' => 10,
    '#description' => t('Maximum dimensions of the logo on the left side of the footer in pixels. Format: width x height. E.g: 270x56 <br /> <b>WARNING! Setting height greater than 56px could cause error in PDF output.</b>'),
  );

  $form['img']['f_right_logo_size'] = array(
    '#type' => 'textfield',
    '#title' => t('Maximum dimensions of right footer logo'),
    '#default_value' => $default['f_right_logo_size'],
    '#size' => 10,
    '#description' => t('Maximum dimensions of the logo on the right side of the footer in pixels. Format: width x height. E.g: 270x56 <br /> <b>WARNING! Setting height greater than 56px could cause error in PDF output.</b>'),
  );

  // Header
  $form['header'] = array(
    '#type' => 'fieldset',
    '#title' => t('PDF header'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $form['header']['h_left_logo'] = array(
    '#type' => 'value',
    '#value' => $default['h_left_logo'],
  );

  if ($default['h_left_logo']) {
    $logo_file = file_load($default['h_left_logo']);

    $picture = array(
      'path' => $logo_file->uri,
      'alt' => 'Header left logo.',
      'title' => $logo_file->filename,
    );
    $form['header']['h_left_logo_img'] = array(
      '#type' => 'item',
      '#title' => t('Logo on the left side'),
      '#markup' => theme('image', $picture),
    );
    $form['header']['h_left_logo_del'] = array(
      '#type' => 'checkbox',
      '#title' => t('Delete left side logo.'),
    );
  }
  else {
    $form['header']['h_left_logo_file'] = array(
      '#type' => 'file',
      '#title' => t('Upload left side logo'),
      '#size' => 60,
      '#maxlength' => 250,
      '#description' => t("Upload left side logo. If the size of the uploaded image is more than @size, it will be resized to this size.", array('@size' => $default['h_left_logo_size'])),
    );
  }

  $form['header']['h_txt'] = array(
    '#type' => 'textarea',
    '#title' => t('Header text'),
    '#rows' => '5',
    '#default_value' => $default['h_txt'],
    '#resizable' => FALSE,
    '#description' => t("PDF header text. 5 rows maximum.") . theme('webform_token_help'),
  );

  $form['header']['h_txt_align'] = array(
    '#type' => 'select',
    '#title' => t('Text alignment'),
    '#default_value' => $default['h_txt_align'],
    '#options' => array(
      'L' => t('Align left'),
      'C' => t('Align center'),
      'R' => t('Align right'),
    ),
  );

  $form['header']['h_font_family'] = array(
    '#type' => 'select',
    '#title' => t('Font Family'),
    '#default_value' => $default['h_font_family'],
    '#options' => array(
      'helvetica' => 'Helvetica',
      'times' => 'Times',
      'courier' => 'Courier',
      'dejavusans' => 'Dejavu Sans',
      'dejavuserif' => 'Dejavu Serif',
      'freesans' => 'Free Sans',
      'freeserif' => 'Free Serif',
      'freemono' => 'Free Mono',
    ),
    '#description' => t('Set the font family to be used.'),
  );

  $form['header']['h_font_size'] = array(
    '#type' => 'textfield',
    '#title' => t('Font Size'),
    '#default_value' => $default['h_font_size'],
    '#size' => 2,
    '#maxlength' => 3,
    '#description' => t('Set the font size to be used for header text. This is the base value for the scaling applied to other text styles.'),
  );

  $form['header']['h_right_logo'] = array(
    '#type' => 'value',
    '#value' => $default['h_right_logo'],
  );

  if ($default['h_right_logo']) {
    $logo_file = file_load($default['h_right_logo']);
    $picture = array(
      'path' => $logo_file->uri,
      'alt' => 'Header right logo.',
      'title' => $logo_file->filename,
    );

    $form['header']['h_right_logo_img'] = array(
      '#type' => 'item',
      '#title' => t('Logo on the right side'),
      '#markup' => theme('image', $picture),
    );
    $form['header']['h_right_logo_del'] = array(
      '#type' => 'checkbox',
      '#title' => t('Delete right logo.'),
    );
  }
  else {
    $form['header']['h_right_logo_file'] = array(
      '#type' => 'file',
      '#title' => t('Upload right logo'),
      '#size' => 60,
      '#maxlength' => 250,
      '#description' => t("Upload right side logo. If the size of the uploaded image is more than @size, it will be resized to this size.", array('@size' => $default['h_right_logo_size'])),
    );
  }

  // PDF body (page)
  $form['page'] = array(
    '#type' => 'fieldset',
    '#title' => t('Content of the PDF document'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $form['page']['p_body'] = array(
    '#type' => 'text_format',
    '#base_type' => 'textarea',
    '#title' => t('Page body'),
    '#format' => isset($default['p_body']['format']) ? $default['p_body']['format'] : NULL,
    '#rows' => '10',
    '#default_value' => $default['p_body']['value'],
    '#description' => t("The content of the PDF file can be defined here, the text can be formatted with HTML and CSS tags. The form elements can be referred with the following special strings: !vars."
    , array('!vars' => '%pagebreak')) . theme('webform_token_help'),
  );

  $form['page']['p_txt_align'] = array(
    '#type' => 'select',
    '#title' => t('Text alignment'),
    '#default_value' => $default['p_txt_align'],
    '#options' => array(
      'L' => t('Align left'),
      'C' => t('Align center'),
      'R' => t('Align right'),
      ),
  );

  $form['page']['p_font_family'] = array(
    '#type' => 'select',
    '#title' => t('Font Family'),
    '#default_value' => $default['p_font_family'],
    '#options' => array(
      'helvetica' => 'Helvetica',
      'times' => 'Times',
      'courier' => 'Courier',
      'dejavusans' => 'Dejavu Sans',
      'dejavuserif' => 'Dejavu Serif',
      'freesans' => 'Free Sans',
      'freeserif' => 'Free Serif',
      'freemono' => 'Free Mono',
    ),
    '#description' => t('Set the font family to be used.'),
  );

  $form['page']['p_font_size'] = array(
    '#type' => 'textfield',
    '#title' => t('Font Size'),
    '#default_value' => $default['p_font_size'],
    '#size' => 2,
    '#maxlength' => 3,
    '#description' => t('Set the font size to be used for header text. This is the base value for the scaling applied to other text styles.'),
  );

  // Footer
  $form['footer'] = array(
    '#type' => 'fieldset',
    '#title' => t('PDF footer'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $form['footer']['f_left_logo'] = array(
    '#type' => 'value',
    '#value' => $default['f_left_logo'],
  );

  if ($default['f_left_logo']) {
    $logo_file = file_load($default['f_left_logo']);

    $picture = array(
      'path' => $logo_file->uri,
      'alt' => 'Footer left logo.',
      'title' => $logo_file->filename,
    );
    $form['footer']['f_left_logo_img'] = array(
      '#type' => 'item',
      '#title' => t('Logo on the left side'),
      '#markup' => theme('image', $picture),
    );
    $form['footer']['f_left_logo_del'] = array(
      '#type' => 'checkbox',
      '#title' => t('Delete left side logo.'),
    );
  }
  else {
    $form['footer']['f_left_logo_file'] = array(
      '#type' => 'file',
      '#title' => t('Upload left side logo'),
      '#size' => 60,
      '#maxlength' => 250,
      '#description' => t("Upload left side logo. If the size of the uploaded image is more than @size, it will be resized to this size.", array('@size' => $default['f_left_logo_size'])),
    );
  }

  $form['footer']['f_txt'] = array(
    '#type' => 'textarea',
    '#title' => t('Footer text'),
    '#rows' => '2',
    '#default_value' => $default['f_txt'],
    '#resizable' => FALSE,
    '#description' => t("The PDF footer text. 2 rows maximum. The following special element can be used: %pagenumber - number of the page, %totalpage - total page count.") . theme('webform_token_help'),
  );

  $form['footer']['f_txt_align'] = array(
    '#type' => 'select',
    '#title' => t('Text alignment'),
    '#default_value' => $default['f_txt_align'],
    '#options' => array(
      'L' => t('Align left'),
      'C' => t('Align center'),
      'R' => t('Align right'),
    ),
  );

  $form['footer']['f_font_family'] = array(
    '#type' => 'select',
    '#title' => t('Font Family'),
    '#default_value' => $default['f_font_family'],
    '#options' => array(
      'helvetica' => 'Helvetica',
      'times' => 'Times',
      'courier' => 'Courier',
      'dejavusans' => 'Dejavu Sans',
      'dejavuserif' => 'Dejavu Serif',
      'freesans' => 'Free Sans',
      'freeserif' => 'Free Serif',
      'freemono' => 'Free Mono',
    ),
    '#description' => t('Set the font family to be used.'),
  );

  $form['footer']['f_font_size'] = array(
    '#type' => 'textfield',
    '#title' => t('Font Size'),
    '#default_value' => $default['f_font_size'],
    '#size' => 2,
    '#maxlength' => 3,
    '#description' => t('Set the font size to be used for header text. This is the base value for the scaling applied to other text styles.'),
  );

  $form['footer']['f_right_logo'] = array(
    '#type' => 'value',
    '#value' => $default['f_right_logo'],
  );

  if ($default['f_right_logo']) {
    $logo_file = file_load($default['f_right_logo']);

    $picture = array(
      'path' => $logo_file->uri,
      'alt' => 'Footer right logo.',
      'title' => $logo_file->filename,
    );

    $form['footer']['f_right_logo_img'] = array(
      '#type' => 'item',
      '#title' => t('Logo on the right side'),
      '#markup' => theme('image', $picture),
    );
    $form['footer']['f_right_logo_del'] = array(
      '#type' => 'checkbox',
      '#title' => t('Delete right logo.'),
    );
  }
  else {
    $form['footer']['f_right_logo_file'] = array(
      '#type' => 'file',
      '#title' => t('Upload right logo'),
      '#size' => 60,
      '#maxlength' => 250,
      '#description' => t("Upload right side logo. If the size of the uploaded image is more than @size, it will be resized to this size.", array('@size' => $default['f_right_logo_size'])),
    );
  }

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );

  return $form;
} // function webform2pdf_admin_settings()

/*
 * webform2pdf_admin_settings_validate: Implements validate hook
 */
function webform2pdf_admin_settings_validate($form, &$form_state) {
  foreach (array('h_left_logo_size', 'h_right_logo_size', 'f_left_logo_size', 'f_right_logo_size') as $logo_size) {
    if ( !preg_match("/^\d+x\d+$/", $form_state['values'][$logo_size]) ) {
      form_set_error($logo_size, t('Wrong picture size format!'));
    }
  }

  $header = explode('<br />', nl2br( str_replace('<br>', '<br />', $form_state['values']['h_txt']) ) );

  if ( count($header) > 5) {
    form_set_error('h_txt', t('Up to 5 rows can be set!'));
  }

  $footer = explode('<br />', nl2br( str_replace('<br>', '<br />', $form_state['values']['f_txt']) ) );
  if ( count($footer) > 2) {
    form_set_error('f_txt', t('Up to 2 rows can be set!'));
  }
} // function webform2pdf_admin_settings_validate()

/*
 * webform2pdf_admin_settings_submit: Implements submit hook
 */
function webform2pdf_admin_settings_submit($form, &$form_state) {
  // File deleted.
  foreach (array('h_left_logo', 'h_right_logo', 'f_left_logo', 'f_right_logo', 'p_background') as $logo) {
    if ( isset($form_state['values'][$logo . '_del']) ) {
      if ( $form_state['values'][$logo . '_del'] ) {
        $logo_file = file_load($form_state['values'][$logo]);
        file_usage_delete($logo_file, 'webform2pdf', $logo, 1);
        file_delete($logo_file);
        $form_state['values'][$logo] = 0;
      }
    }
  }

  // Header and footer image file save.
  foreach (array('h_left_logo', 'h_right_logo', 'f_left_logo', 'f_right_logo', 'p_background') as $logo) {
    if ( isset($form_state['values'][$logo . '_file']) ) {
      $validators['file_validate_is_image'] = array();
      if (isset($form_state['values'][$logo . '_size'])) {
        $validators['file_validate_image_resolution'] = array($form_state['values'][$logo . '_size']);
      }

      if ( $file = file_save_upload($logo . '_file', $validators ) ) {
        $webform2pdf_directory =  file_default_scheme() . '://' . 'webform2pdf';
        // Prepare the pictures directory.
        file_prepare_directory($webform2pdf_directory, FILE_CREATE_DIRECTORY);
        $destination = file_stream_wrapper_uri_normalize($webform2pdf_directory);
        if ($file = file_move($file, $destination, FILE_EXISTS_RENAME)) {
          $file->status |= FILE_STATUS_PERMANENT;
          $file = file_save($file);
          file_usage_add($file, 'webform2pdf', $logo, 0);
          $form_state['values'][$logo] = $file->fid;
        }
      }
    }
  }

  $save = $form_state['values'];
  foreach (array('h_left_logo_del', 'h_right_logo_del', 'f_left_logo_del', 'f_right_logo_del',
    'h_left_logo_img', 'h_right_logo_img', 'f_left_logo_img', 'f_right_logo_img',
    'h_left_logo_file', 'h_right_logo_file', 'f_left_logo_file', 'f_right_logo_file',
    'op', 'submit', 'form_build_id', 'form_token', 'form_id','p_background_del','p_background_file') as $del) {
    unset($save[$del]);
  }

  variable_set('webform2pdf_default', $save);
} // function webform2pdf_admin_settings_submit()

/**
 * Overview form of all components for this webform.
 */
function webform2pdf_edit_form($form, &$form_state, $node) {
  $default = webform2pdf_get_setting($node->nid);

  if (!$default) {
    $default = variable_get('webform2pdf_default', '');
    $default['enabled'] = 0;
  }

  $form['enabled'] = array(
    '#default_value' => $default['enabled'],
    '#type' => 'checkbox',
    '#title' => t('Generate PDF Document.'),
  );

  $webform2pdf_default = variable_get('webform2pdf_default', '');

  // Needed because of file upload
  $form['#attributes'] = array('enctype' => 'multipart/form-data');

  $form['base'] = array(
    '#type' => 'fieldset',
    '#title' => t('General settings'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#states' => array(
      'visible' => array(
        'input[name="enabled"]' => array('checked' => TRUE),
      ),
    ),
  );

  $form['base']['page_format'] = array(
    '#type' => 'select',
    '#title' => t('Paper size'),
    '#default_value' => $default['page_format'],
    '#options' => array(
      '4A0' => '4A0', '2A0' => '2A0', 'A0' => 'A0',
      'A1' => 'A1', 'A2' => 'A2', 'A3' => 'A3', 'A4' => 'A4',
      'A5' => 'A5', 'A6' => 'A6', 'A7' => 'A7', 'A8' => 'A8',
      'A9' => 'A9', 'A10' => 'A10', 'A11' => 'A11', 'A12' => 'A12',
      'B0' => 'B0', 'B1' => 'B1', 'B2' => 'B2', 'B3' => 'B3',
      'B4' => 'B4', 'B5' => 'B5', 'B6' => 'B6', 'B7' => 'B7',
      'B8' => 'B8', 'B9' => 'B9', 'B10' => 'B10', 'B11' => 'B11',
      'B12' => 'B12',
      'C0' => 'C0', 'C1' => 'C1', 'C2' => 'C2', 'C3' => 'C3',
      'C4' => 'C4', 'C5' => 'C5', 'C6' => 'C6', 'C7' => 'C7',
      'C8' => 'C8', 'C9' => 'C9', 'C10' => 'C10', 'C11' => 'C11',
      'C12' => 'C12',
      'DL' => 'DL',
      'E0' => 'E0', 'E1' => 'E1', 'E2' => 'E2', 'E3' => 'E3',
      'E4' => 'E4', 'E5' => 'E5', 'E6' => 'E6', 'E7' => 'E7',
      'E8' => 'E8', 'E9' => 'E9', 'E10' => 'E10', 'E11' => 'E11',
      'E12' => 'E12',
      'G0' => 'G0', 'G1' => 'G1', 'G2' => 'G2', 'G3' => 'G3',
      'G4' => 'G4', 'G5' => 'G5', 'G6' => 'G6', 'G7' => 'G7',
      'G8' => 'G8', 'G9' => 'G9', 'G10' => 'G10', 'G11' => 'G11',
      'G12' => 'G12',
      'RA0' => 'RA0', 'RA1' => 'RA1', 'RA2' => 'RA2',
      'RA3' => 'RA3', 'RA4' => 'RA4',
      'SRA0' => 'SRA0', 'SRA1' => 'SRA1', 'SRA2' => 'SRA2',
      'SRA3' => 'SRA3', 'SRA4' => 'SRA4',
      'LETTER' => t('Letter'), 'LEGAL' => t('Legal'),
      'EXECUTIVE' => t('Executive'), 'FOLIO' => t('Folio'),
    ),
  );

  $form['base']['page_orientation'] = array(
    '#type' => 'radios',
    '#title' => t('Page orientation'),
    '#default_value' => $default['page_orientation'],
    '#options' => array(
      'P' => t('Portrait'),
      'L' => t('Landscape'),
    ),
  );

   //background image
  $form['base']['p_background'] = array(
    '#type' => 'value',
    '#value' => $default['p_background'],
  );

  if ($default['p_background']) {
    $file = file_load($default['p_background']);

    $picture = array(
      'path' => $file->uri,
      'alt' => 'Page background',
      'title' => $file->filename,
    );
    $form['base']['p_background_img'] = array(
      '#type' => 'item',
      '#title' => t('Background image for page'),
      '#markup' => theme('image', $picture),
    );
    $form['base']['p_background_del'] = array(
      '#type' => 'checkbox',
      '#title' => t('Delete this image.'),
    );
  }
  else {
    $form['base']['p_background_file'] = array(
      '#type' => 'file',
      '#title' => t('Background image for page.'),
      '#size' => 60,
      '#description' => t('Upload background image for page. Image will be scaled by page size.'),
    );
  }

  // E-mail settings
  $form['email'] = array(
    '#type' => 'fieldset',
    '#title' => t('E-mail settings'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#states' => array(
      'visible' => array(
        'input[name="enabled"]' => array('checked' => TRUE),
      ),
    ),
  );

  $form['email']['pdf_send_email'] = array(
    '#type' => 'checkbox',
    '#title' => t('Attach PDF as an attachment to the e-mails sent to the form recipients.'),
    '#default_value' => $default['pdf_send_email'],
  );

  $send_mail = array();
  if ( !empty($node->webform['email']) ) {
    $send_mail['email'] = $node->webform['email'];
  }

  if (is_array($node->webform['emails'])) {
    foreach ($node->webform['emails'] as $eid => $email) {
      $email_addresses = array_filter(explode(',', check_plain($email['email'])));
      foreach ($email_addresses as $key => $email_address) {
        $email_addresses[$key] = webform_format_email_address($email_address, NULL, $node, NULL, FALSE);
      }

      $send_mail[$eid] = implode(', ', $email_addresses);
    }
  }

  if ( count($send_mail) ) {
    if (isset($default['no_send_email_addr'])) {
      $def = $default['no_send_email_addr'];
    }
    if (!isset($def) || !is_array($def) ) {
      $def = array();
    }

    $form['email']['no_send_email_addr'] = array(
      '#title' => t("Don't attach PDF file"),
      '#type' => 'checkboxes',
      '#options' => $send_mail,
      '#default_value' => $def,
      '#description' => t("PDF file won't be attached to the e-mail sent to the following recipients."),
    );
  }

  // Header
  $form['header'] = array(
    '#type' => 'fieldset',
    '#title' => t('PDF header'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#states' => array(
      'visible' => array(
        'input[name="enabled"]' => array('checked' => TRUE),
      ),
    ),
  );

  $form['header']['h_left_logo'] = array(
    '#type' => 'value',
    '#value' => $default['h_left_logo'],
  );

  if ($default['h_left_logo']) {
    $logo_file = file_load($default['h_left_logo']);

    $picture = array(
      'path' => $logo_file->uri,
      'alt' => 'Header left logo.',
      'title' => $logo_file->filename,
    );
    $form['header']['h_left_logo_img'] = array(
      '#type' => 'item',
      '#title' => t('Logo on the left side'),
      '#markup' => theme('image', $picture),
    );
    $form['header']['h_left_logo_del'] = array(
      '#type' => 'checkbox',
      '#title' => t('Delete left side logo.'),
    );
  }
  else {
    $form['header']['h_left_logo_file'] = array(
      '#type' => 'file',
      '#title' => t('Upload left side logo'),
      '#size' => 60,
      '#maxlength' => 250,
      '#description' => t("Upload left side logo. If the size of the uploaded image is more than @size, it will be resized to this size.", array('@size' => $webform2pdf_default['h_left_logo_size'])),
    );
  }

  $form['header']['h_txt'] = array(
    '#type' => 'textarea',
    '#title' => t('Header text'),
    '#rows' => '5',
    '#default_value' => $default['h_txt'],
    '#resizable' => FALSE,
    '#description' => t("PDF header text. 5 rows maximum.") . theme('webform_token_help'),
  );

  $form['header']['h_txt_align'] = array(
    '#type' => 'select',
    '#title' => t('Text alignment'),
    '#default_value' => $default['h_txt_align'],
    '#options' => array(
      'L' => t('Align left'),
      'C' => t('Align center'),
      'R' => t('Align right'),
    ),
  );

  $form['header']['h_font_family'] = array(
    '#type' => 'select',
    '#title' => t('Font Family'),
    '#default_value' => $default['h_font_family'],
    '#options' => array(
      'helvetica' => 'Helvetica',
      'times' => 'Times',
      'courier' => 'Courier',
      'dejavusans' => 'Dejavu Sans',
      'dejavuserif' => 'Dejavu Serif',
      'freesans' => 'Free Sans',
      'freeserif' => 'Free Serif',
      'freemono' => 'Free Mono',
    ),
    '#description' => t('Set the font family to be used.'),
  );

  $form['header']['h_font_size'] = array(
    '#type' => 'textfield',
    '#title' => t('Font Size'),
    '#default_value' => $default['h_font_size'],
    '#size' => 2,
    '#maxlength' => 3,
    '#description' => t('Set the font size to be used for header text. This is the base value for the scaling applied to other text styles.'),
  );

  $form['header']['h_right_logo'] = array(
    '#type' => 'value',
    '#value' => $default['h_right_logo'],
  );

  if ($default['h_right_logo']) {
    $logo_file = file_load($default['h_right_logo']);
    $picture = array(
      'path' => $logo_file->uri,
      'alt' => 'Header right logo.',
      'title' => $logo_file->filename,
    );

    $form['header']['h_right_logo_img'] = array(
      '#type' => 'item',
      '#title' => t('Logo on the right side'),
      '#markup' => theme('image', $picture),
    );
    $form['header']['h_right_logo_del'] = array(
      '#type' => 'checkbox',
      '#title' => t('Delete right logo.'),
    );
  }
  else {
    $form['header']['h_right_logo_file'] = array(
      '#type' => 'file',
      '#title' => t('Upload right logo'),
      '#size' => 60,
      '#maxlength' => 250,
      '#description' => t("Upload right side logo. If the size of the uploaded image is more than @size, it will be resized to this size.", array('@size' => $webform2pdf_default['h_right_logo_size'])),
    );
  }

  // PDF body (page)
  $form['page'] = array(
    '#type' => 'fieldset',
    '#title' => t('Content of the PDF document'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#states' => array(
      'visible' => array(
        'input[name="enabled"]' => array('checked' => TRUE),
      ),
    ),
  );

  $form['page']['p_body'] = array(
    '#type' => 'text_format',
    '#base_type' => 'textarea',
    '#title' => t('Page body'),
    '#format' => isset($default['p_body']['format']) ? $default['p_body']['format'] : NULL,
    '#rows' => '10',
    '#default_value' => $default['p_body']['value'],
    '#description' => t("The content of the PDF file can be defined here, the text can be formatted with HTML and CSS tags.")
      . theme('webform_token_help', array('groups' => array('node', 'submission'))),
  );

  $form['page']['p_txt_align'] = array(
    '#type' => 'select',
    '#title' => t('Text alignment'),
    '#default_value' => $default['p_txt_align'],
    '#options' => array(
      'L' => t('Align left'),
      'C' => t('Align center'),
      'R' => t('Align right'),
      ),
  );

  $form['page']['p_font_family'] = array(
    '#type' => 'select',
    '#title' => t('Font Family'),
    '#default_value' => $default['p_font_family'],
    '#options' => array(
      'helvetica' => 'Helvetica',
      'times' => 'Times',
      'courier' => 'Courier',
      'dejavusans' => 'Dejavu Sans',
      'dejavuserif' => 'Dejavu Serif',
      'freesans' => 'Free Sans',
      'freeserif' => 'Free Serif',
      'freemono' => 'Free Mono',
    ),
    '#description' => t('Set the font family to be used.'),
  );

  $form['page']['p_font_size'] = array(
    '#type' => 'textfield',
    '#title' => t('Font Size'),
    '#default_value' => $default['p_font_size'],
    '#size' => 2,
    '#maxlength' => 3,
    '#description' => t('Set the font size to be used for header text. This is the base value for the scaling applied to other text styles.'),
  );

  // Footer
  $form['footer'] = array(
    '#type' => 'fieldset',
    '#title' => t('PDF footer'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#states' => array(
      'visible' => array(
        'input[name="enabled"]' => array('checked' => TRUE),
      ),
    ),
  );

  $form['footer']['f_left_logo'] = array(
    '#type' => 'value',
    '#value' => $default['f_left_logo'],
  );

  if ($default['f_left_logo']) {
    $logo_file = file_load($default['f_left_logo']);

    $picture = array(
      'path' => $logo_file->uri,
      'alt' => 'Footer left logo.',
      'title' => $logo_file->filename,
    );
    $form['footer']['f_left_logo_img'] = array(
      '#type' => 'item',
      '#title' => t('Logo on the left side'),
      '#markup' => theme('image', $picture),
    );
    $form['footer']['f_left_logo_del'] = array(
      '#type' => 'checkbox',
      '#title' => t('Delete left side logo.'),
    );
  }
  else {
    $form['footer']['f_left_logo_file'] = array(
      '#type' => 'file',
      '#title' => t('Upload left side logo'),
      '#size' => 60,
      '#maxlength' => 250,
      '#description' => t("Upload left side logo. If the size of the uploaded image is more than @size, it will be resized to this size.", array('@size' => $webform2pdf_default['f_left_logo_size'])),
    );
  }

  $form['footer']['f_txt'] = array(
    '#type' => 'textarea',
    '#title' => t('Footer text'),
    '#rows' => '2',
    '#default_value' => $default['f_txt'],
    '#resizable' => FALSE,
    '#description' => t("The PDF footer text. 2 rows maximum. The following special element can be used: %pagenumber - number of the page, %totalpage - total page count.") . theme('webform_token_help'),
  );

  $form['footer']['f_txt_align'] = array(
    '#type' => 'select',
    '#title' => t('Text alignment'),
    '#default_value' => $default['f_txt_align'],
    '#options' => array(
      'L' => t('Align left'),
      'C' => t('Align center'),
      'R' => t('Align right'),
    ),
  );

  $form['footer']['f_font_family'] = array(
    '#type' => 'select',
    '#title' => t('Font Family'),
    '#default_value' => $default['f_font_family'],
    '#options' => array(
      'helvetica' => 'Helvetica',
      'times' => 'Times',
      'courier' => 'Courier',
      'dejavusans' => 'Dejavu Sans',
      'dejavuserif' => 'Dejavu Serif',
      'freesans' => 'Free Sans',
      'freeserif' => 'Free Serif',
      'freemono' => 'Free Mono',
    ),
    '#description' => t('Set the font family to be used.'),
  );

  $form['footer']['f_font_size'] = array(
    '#type' => 'textfield',
    '#title' => t('Font Size'),
    '#default_value' => $default['f_font_size'],
    '#size' => 2,
    '#maxlength' => 3,
    '#description' => t('Set the font size to be used for header text. This is the base value for the scaling applied to other text styles.'),
  );

  $form['footer']['f_right_logo'] = array(
    '#type' => 'value',
    '#value' => $default['f_right_logo'],
  );

  if ($default['f_right_logo']) {
    $logo_file = file_load($default['f_right_logo']);

    $picture = array(
      'path' => $logo_file->uri,
      'alt' => 'Footer right logo.',
      'title' => $logo_file->filename,
    );

    $form['footer']['f_right_logo_img'] = array(
      '#type' => 'item',
      '#title' => t('Logo on the right side'),
      '#markup' => theme('image', $picture),
    );
    $form['footer']['f_right_logo_del'] = array(
      '#type' => 'checkbox',
      '#title' => t('Delete right logo.'),
    );
  }
  else {
    $form['footer']['f_right_logo_file'] = array(
      '#type' => 'file',
      '#title' => t('Upload right logo'),
      '#size' => 60,
      '#maxlength' => 250,
      '#description' => t("Upload right side logo. If the size of the uploaded image is more than @size, it will be resized to this size.", array('@size' => $webform2pdf_default['f_right_logo_size'])),
    );
  }

  $form['nid'] = array(
    '#type' => 'value',
    '#value' => $node->nid,
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );

  if (!isset($default['nid'])) {
    $form['new'] = array(
      '#type' => 'value',
      '#value' => 1,
    );
  }
  else {
    $form['reset'] = array(
      '#type' => 'submit',
      '#value' => t('Reset to defaults'),
    );
  }

  return $form;
} // function webform2pdf_edit_form()

/*
 * webform2pdf_edit_form_validate: Implements validate hook
 */
function webform2pdf_edit_form_validate($form, &$form_state) {
  if ($form_state['values']['op'] == t('Save')) {
    if (!empty($form_state['values']['h_txt'])) {
      $header = explode('<br />', nl2br( str_replace('<br>', '<br />', $form_state['values']['h_txt']) ) );
      if ( count($header) > 5) {
        form_set_error('h_txt', t('Up to 5 rows can be set!'));
      }
    }

    if (!empty($form_state['values']['f_txt'])) {
      $footer = explode('<br />', nl2br( str_replace('<br>', '<br />', $form_state['values']['f_txt']) ) );
      if ( count($footer) > 2) {
        form_set_error('f_txt', t('Up to 2 rows can be set!'));
      }
    }

    if (!(is_numeric($form_state['values']['h_font_size']) && ($form_state['values']['h_font_size'] > 0))) {
      form_set_error('h_font_size', t('Header font size must be numeric.'));
    }

    if (!(is_numeric($form_state['values']['p_font_size']) && ($form_state['values']['p_font_size'] > 0))) {
      form_set_error('p_font_size', t('Content font size must be numeric.'));
    }

    if (!(is_numeric($form_state['values']['f_font_size']) && ($form_state['values']['f_font_size'] > 0))) {
      form_set_error('f_font_size', t('Footer font size must be numeric.'));
    }
  }
} // function webform2pdf_edit_form_validate()

/*
 * webform2pdf_edit_form_submit: Implements submit hook
 */
function webform2pdf_edit_form_submit($form, &$form_state) {
  if ($form_state['values']['op'] == t('Save')) {
    $save = $form_state['values'];
    unset($save['nid']);
    unset($save['enabled']);
    unset($save['submit']);
    unset($save['reset']);
    unset($save['form_build_id']);
    unset($save['form_token']);
    unset($save['form_id']);
    unset($save['op']);

    // First enabled
    if (isset($form_state['values']['new'])) {
      unset($save['new']);

      if ($form_state['values']['enabled']) {
        // Image file create
        foreach (array('h_left_logo', 'h_right_logo', 'f_left_logo', 'f_right_logo', 'p_background') as $logo) {
          if ( isset($form_state['values'][$logo . '_del']) ) {
            if ( $form_state['values'][$logo . '_del'] ) {
              $save[$logo] = 0;
            }
            elseif (!empty($form_state['values'][$logo])) {
              $save[$logo] = $form_state['values'][$logo];
              $file = file_load($save[$logo]);
              file_usage_add($file, 'webform2pdf', $logo, 1);
            }
            unset($save[$logo . '_del']);
          }
          if ( isset($form_state['values'][$logo . '_file']) ) {
            $save[$logo] = _webform2pdf_save_logo($logo, $form_state['values']['nid']);
            unset($save[$logo . '_file']);
          }
        }

        $w2pdf_setting['nid'] = $form_state['values']['nid'];
        $w2pdf_setting['enabled'] = $form_state['values']['enabled'];
        $w2pdf_setting['data'] = $save;
        drupal_write_record('webform2pdf', $w2pdf_setting);
      }
    }
    else {
      // Image file deleted.
      foreach (array('h_left_logo', 'h_right_logo', 'f_left_logo', 'f_right_logo', 'p_background') as $logo) {
        if ( isset($form_state['values'][$logo . '_del']) ) {
          if ( $form_state['values'][$logo . '_del'] ) {
            $logo_file = file_load($form_state['values'][$logo]);
            file_usage_delete($logo_file, 'webform2pdf', $logo, 1);
            file_delete($logo_file);
            $save[$logo] = 0;
          }
          unset($save[$logo . '_del']);
        }
      }

      // Header and footer image file save.
      foreach (array('h_left_logo', 'h_right_logo', 'f_left_logo', 'f_right_logo', 'p_background') as $logo) {
        if ( isset($form_state['values'][$logo . '_file']) ) {
          $save[$logo] = _webform2pdf_save_logo($logo, $form_state['values']['nid']);
          unset($save[$logo . '_file']);
        }
      }
    }
  }
  else {
    // default settings
    $save = variable_get('webform2pdf_default', '');

    // Image file deleted.
    foreach (array('h_left_logo', 'h_right_logo', 'f_left_logo', 'f_right_logo', 'p_background') as $logo) {
      $logo_file = file_load($form_state['values'][$logo]);
      if ($logo_file) {
        file_usage_delete($logo_file, 'webform2pdf', $logo, 1);
        file_delete($logo_file);
      }
    }
  }

  if (!isset($form_state['values']['new'])) {
    // update settings
    $w2pdf_setting['nid'] = $form_state['values']['nid'];
    $w2pdf_setting['enabled'] = $form_state['values']['enabled'];
    $w2pdf_setting['data'] = $save;
    drupal_write_record('webform2pdf', $w2pdf_setting, 'nid');
  }
} // function webform2pdf_edit_form_submit()

function _webform2pdf_save_logo($logo, $nid) {
  $webform2pdf_default = variable_get('webform2pdf_default', '');

  $validators['file_validate_is_image'] = array();
  if (isset($webform2pdf_default[$logo . '_size'])) {
    $validators['file_validate_image_resolution'] = array($webform2pdf_default[$logo . '_size']);
  }

  if ( $file = file_save_upload($logo . '_file', $validators ) ) {
    $webform2pdf_directory =  file_default_scheme() . '://' . 'webform2pdf';
    // Prepare the pictures directory.
    file_prepare_directory($webform2pdf_directory, FILE_CREATE_DIRECTORY);
    $destination = file_stream_wrapper_uri_normalize($webform2pdf_directory);
    if ($file = file_move($file, $destination, FILE_EXISTS_RENAME)) {
      $file->status |= FILE_STATUS_PERMANENT;
      $file = file_save($file);
      file_usage_add($file, 'webform2pdf', $logo, $nid);
      return $file->fid;
    }
  }
  return 0;
}
