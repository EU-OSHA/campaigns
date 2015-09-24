<?php
/**
 * @file
 * Implemented menu path:
 * node/%webform_menu/webform-results/downloadpdf
 * node/%webform_menu/submission/%webform_menu_submission/downloadpdf
 */

/*
 * webform2pdf_submission_download_pdf: download submission as one PDF file
 * $output_type: Suported type: 'I', 'D', 'S' ( http://www.tcpdf.org/doc/classTCPDF.html#a3d6dcb62298ec9d42e9125ee2f5b23a1 )
 */
function webform2pdf_submission_download_pdf($node, $submission, $output_type = 'I') {
  $output_types = array('I', 'D', 'S');

  if ( in_array($output_type, $output_types) ) {
    $template = _webform2pdf_get_template($node->nid);

    $pdf = theme('webform2pdf_pdf_init', array('node' => $node, 'template' => $template));
    if ( !empty($pdf) ) {
      $pdf = theme('webform2pdf_pdf_header', array('pdf' => $pdf, 'node' => $node, 'template' => $template));
      $pdf = theme('webform2pdf_pdf_footer', array('pdf' => $pdf, 'node' => $node, 'template' => $template));
      $pdf = theme('webform2pdf_pdf_page', array('pdf' => $pdf));

      // todo: @deprecated deprecated since version 5.9.089 (2011-06-13)
      if (method_exists($pdf, 'AliasNbPages')) {
        // initialize document
        $pdf->AliasNbPages();
      }

      $page = theme('webform2pdf_content', array('node' => $node, 'submission' => $submission, 'template' => $template));

      $template['pages'] = explode('%pagebreak', $page);

      $pdf = theme('webform2pdf_pdf_content', array('pdf' => $pdf, 'node' => $node, 'template' => $template));

      // reset pointer to the last page
      $pdf->lastPage();

      $filename = theme('webform2pdf_filename', array('node' => $node, 'submission' => $submission));

      switch ($output_type) {
        case 'S':
          return $pdf->Output($filename, 'S');
        break;

        case 'I':
          // http header
          drupal_add_http_header('Content-Type', 'application/pdf');
          drupal_add_http_header('Cache-Control', 'public, must-revalidate, max-age=0'); // HTTP/1.1
          drupal_add_http_header('Pragma', 'public');
          drupal_add_http_header('Content-Disposition', 'inline; filename="' . $filename . '";');
        break;

        case 'D':
          drupal_add_http_header('Content-Description', 'File Transfer');
          drupal_add_http_header('Cache-Control', 'public, must-revalidate, max-age=0'); // HTTP/1.1
          drupal_add_http_header('Pragma', 'public');
          drupal_add_http_header('Content-Type', 'application/pdf');

          // use the Content-Disposition header to supply a recommended filename
          drupal_add_http_header('Content-Disposition', 'attachment; filename="' . $filename . '";');
          drupal_add_http_header('Content-Transfer-Encoding', 'binary');
        break;
      }
      // Close and output PDF document
      die($pdf->Output($filename, 'S'));
    }
  }
} // function webform2pdf_submission_download_pdf()

/*
 * _webform2pdf_download_pdf_form: Creates a form, where the submissions can be downloaded in PDF format
 */
function webform2pdf_download_pdf_form($form, &$form_state, $node) {
  global $user;
  module_load_include('inc', 'webform', 'includes/webform.submissions');

  $header = theme('webform_results_submissions_header', array('node' => $node));
  $submissions = webform_get_submissions($node->nid, $header);

  $operation_column = end($header);
  $operation_total = $operation_column['colspan'];

  $rows = array();
  foreach ($submissions as $sid => $submission) {
    $row = array(
      $submission->is_draft ? t('@sid (draft)', array('@sid' => $sid)) : $sid,
      format_date($submission->submitted, 'small'),
    );
    if (webform_results_access($node, $user)) {
      $row[] = theme('username', array('account' => $submission));
      $row[] = $submission->remote_addr;
    }
    $row[] = l(t('View'), 'node/' . $node->nid . '/submission/' . $sid);
    $row[] = array('data' => l(t('Download PDF'), 'node/' . $node->nid . '/submission/' . $sid . '/downloadpdf'));
    // D7 BUG a colspan opciot nem figyeli a tableselect igy nem latszik a downloadpdf link

    $operation_count = 2;
    if ($operation_count < $operation_total) {
      $row[count($row) - 1] += array('colspan' => $operation_total - $operation_count + 1);
    }
    $rows[$sid] = $row;
  }

  $form['submissions']['#type'] = 'tableselect';
  $form['submissions']['#header'] = $header;
  $form['submissions']['#options'] = $rows;
  $form['submissions']['#empty'] = t('There are no submissions for this form. <a href="!url">View this form</a>.', array('!url' => url('node/' . $node->nid)));;

  $form['nid'] = array(
    '#type' => 'value',
    '#value' => $node->nid,
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Download PDF'),
  );

  return $form;
} // function webform2pdf_download_pdf_form()

/*
 * webform2pdf_download_pdf_form_submit: webform2pdf_download_pdf_form of submit hook
 */
function webform2pdf_download_pdf_form_submit($form, &$form_state) {
  // filter zero values
  $form_state['values']['submissions'] = array_filter($form_state['values']['submissions']);

  // If there is a selected form element
  if (count($form_state['values']['submissions'])) {
    // call header generator
    $node = node_load($form_state['values']['nid']);
    module_load_include('inc', 'webform', 'includes/webform.submissions');

    $header = theme('webform_results_submissions_header', array('node' => $node));
    $filters = array(
      'nid' => $form_state['values']['nid'],
      'sid' => $form_state['values']['submissions'],
    );

    $submissions = webform_get_submissions($filters, $header);
    $template = _webform2pdf_get_template($node->nid);

    $pdf = theme('webform2pdf_pdf_init', array('node' => $node, 'template' => $template));
    $pdf = theme('webform2pdf_pdf_header', array('pdf' => $pdf, 'node' => $node, 'template' => $template));
    $pdf = theme('webform2pdf_pdf_footer', array('pdf' => $pdf, 'node' => $node, 'template' => $template));
    $pdf = theme('webform2pdf_pdf_page', array('pdf' => $pdf));

    foreach ($submissions as $key => $submission) {
      $pages[$key] = theme('webform2pdf_content', array('node' => $node, 'submission' => $submission, 'template' => $template));
    }

    $template['pages'] = implode('%pagebreak', $pages);
    $template['pages'] = explode('%pagebreak', $template['pages']);

    $pdf = theme('webform2pdf_pdf_content', array('pdf' => $pdf, 'node' => $node, 'template' => $template));

    // reset pointer to the last page
    $pdf->lastPage();
    $filename = theme('webform2pdf_filename', array('node' => $node, 'submission' => time()));

    // http header
    drupal_add_http_header('Content-Type', 'application/pdf');
    drupal_add_http_header('Cache-Control', 'public, must-revalidate, max-age=0'); // HTTP/1.1
    drupal_add_http_header('Pragma', 'public');
    drupal_add_http_header('Content-Disposition', 'inline; filename="' . $filename . '";');

    // Close and output PDF document
    die($pdf->Output($filename, 'S'));
  }
} // function webform2pdf_download_pdf_form_submit()

/*
 * webform2pdf_url_encode: pdf download anonymous url generation.
 */
function webform2pdf_url_decode($url) {
  if ( function_exists('mcrypt_decrypt')  ) {
    $key = variable_get('webform2pdf_key', '');
    $url2 = trim(mcrypt_decrypt(MCRYPT_RIJNDAEL_256, $key, urldecode(base64_decode($url)), MCRYPT_MODE_ECB, mcrypt_create_iv(mcrypt_get_iv_size(MCRYPT_RIJNDAEL_256, MCRYPT_MODE_ECB), MCRYPT_RAND)));

    list($tmp, $nid, $tmp, $sid, $tmp) = explode('/', $url2);
    unset($tmp, $url2);
    if ( is_int($nid) && is_int($sid) ) {
      $node = webform_menu_load($nid);
      $submission = webform_menu_submission_load($sid, $nid);
      if ( !empty($node) && !empty($submission) ) {
        return webform2pdf_submission_download_pdf($node, $submission);
      }
    }
  }
  drupal_not_found();
} // function webform2pdf_url_encode()
