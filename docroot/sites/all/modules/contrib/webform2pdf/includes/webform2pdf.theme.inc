<?php

/*
 * _webform2pdf_init_tcpdf: PDF initializing
 */
function _webform2pdf_init_tcpdf($node, $template) {
  global $base_url;

  $tcpdf_dir = libraries_get_path('tcpdf');

  if (defined('K_TCPDF_EXTERNAL_CONFIG')) {
    define('K_TCPDF_EXTERNAL_CONFIG', TRUE);
    define('K_PATH_MAIN', dirname($_SERVER['SCRIPT_FILENAME']));
    define('K_PATH_URL', $base_url);
    define('K_PATH_FONTS', $tcpdf_dir . '/fonts/');
    define('K_PATH_CACHE', $tcpdf_dir . '/cache/');
    define('K_PATH_IMAGES', '');
    define('K_BLANK_IMAGE', $tcpdf_dir . '/images/_blank.png');
    define('K_CELL_HEIGHT_RATIO', 1.25);
    define('K_SMALL_RATIO', 2/3);
  }

  if ( is_file($tcpdf_dir . '/tcpdf.php')   ) {
    include_once( drupal_get_path('module', 'webform2pdf') . '/webform2pdf.class.inc' );

    $font = Array(
      variable_get('p_font_family', 'dejavuserif'),
      '',
      variable_get('p_font_size', 12),
    );

    // create new PDF document
    $pdf = new W2PDF($template['page_orientation'] , 'mm', $template['page_format'], TRUE);

    // set document information
    $pdf->SetCreator(variable_get('site_name', 'Drupal'));
    $pdf->SetAuthor($node->name);
    $pdf->SetTitle($node->title);
    $pdf->setPDFVersion('1.6');
    return $pdf;
  }
  else {
    return;
  }
} // function _webform2pdf_init_tcpdf()

/*
 * theme_webform2pdf_pdf_init: pdf initializing, theme hook
 */
function theme_webform2pdf_pdf_init($vars) {
  return _webform2pdf_init_tcpdf($vars['node'], $vars['template']);
} // function theme_webform2pdf_pdf_init()

/*
 * _webform2pdf_pdf_header: pdf header data
 */
function _webform2pdf_pdf_header($pdf, $node, $template) {
  if (!empty($template['h_left_logo'])) {
    $f = file_load($template['h_left_logo']);
    $s = image_get_info($f->uri);
    $logo['left'] = drupal_realpath($f->uri);
    // 75dpi image, image size convert millimeter
    $size['left']['w'] = $s['width']/75*25;
    $size['left']['h'] = $s['height']/75*25;
  }
  else {
    $logo['left'] = '';
    $size['left']['w'] = 0;
    $size['left']['h'] = 0;
  }

  if (!empty($template['h_right_logo'])) {
    $f = file_load($template['h_right_logo']);
    $s = image_get_info($f->uri);

    $logo['right'] = drupal_realpath($f->uri);
    // 75dpi image, image size convert millimeter
    $size['right']['w'] = $s['width']/75*25;
    $size['right']['h'] = $s['height']/75*25;
  }
  else {
    $logo['right'] = '';
    $size['right']['w'] = 0;
    $size['right']['h'] = 0;
  }

    if (!empty($template['p_background'])) {
    $f = file_load($template['p_background']);
    $background = drupal_realpath($f->uri);
  }
  else {
    $background = NULL;
  }

  // set header font
  $pdf->setHeaderFont(array($template['h_font_family'], '', $template['h_font_size']));
  // set header margin
  $pdf->setHeaderMargin(5);

  // webform filter
  $header_msg = nl2br( _webform_filter_values($template['h_txt'], $node, NULL, NULL, FALSE) );

  // set header data
  $pdf->setHeaderData($logo, $size, $header_msg, $template['h_txt_align'], array(), array(), $background);
  return $pdf;
} // function _webform2pdf_pdf_header()

/*
 * _webform2pdf_pdf_header: pdf header theme hook
 */
function theme_webform2pdf_pdf_header($vars) {
  return _webform2pdf_pdf_header($vars['pdf'], $vars['node'], $vars['template']);
} // function theme_webform2pdf_pdf_header()

/*
 * _webform2pdf_pdf_footer: pdf footer data
 */
function _webform2pdf_pdf_footer($pdf, $node, $template) {
  if (!empty($template['f_left_logo'])) {
    $f = file_load($template['f_left_logo']);
    $s = image_get_info($f->uri);

    $logo['left'] = drupal_realpath($f->uri);
    // 75dpi image, image size convert millimeter
    $size['left']['w'] = $s['width']/75*25;
    $size['left']['h'] = $s['height']/75*25;
  }
  else {
    $logo['left'] = '';
    $size['left']['w'] = 0;
    $size['left']['h'] = 0;
  }

  if (!empty($template['f_right_logo'])) {
    $f = file_load($template['f_right_logo']);
    $s = image_get_info($f->uri);

    $logo['right'] = drupal_realpath($f->uri);
    // 75dpi image, image size convert millimeter
    $size['right']['w'] = $s['width']/75*25;
    $size['right']['h'] = $s['height']/75*25;
  }
  else {
    $logo['right'] = '';
    $size['right']['w'] = 0;
    $size['right']['h'] = 0;
  }

  // set footer font
  $pdf->setFooterFont(array($template['f_font_family'], '', $template['f_font_size']));
  // set footer margin
  $pdf->setFooterMargin(5);

  // webform filter
  $footer_msg = nl2br( _webform_filter_values($template['f_txt'], $node, NULL, NULL, FALSE) );

  // set footer data
  $pdf->SetFooterData($logo, $size, $footer_msg, $template['f_txt_align']);

  return $pdf;
} // function _webform2pdf_pdf_footer()

/*
 * theme_webform2pdf_pdf_footer: pdf footer theme hook
 */
function theme_webform2pdf_pdf_footer($vars) {
  return _webform2pdf_pdf_footer($vars['pdf'], $vars['node'], $vars['template']);
} // function theme_webform2pdf_pdf_footer()

/*
 * _webform2pdf_pdf_page: pdf page init
 */
function _webform2pdf_pdf_page($pdf) {

  // set margins
  $pdf->SetMargins(15, 20, 15);
  // set auto page breaks
  $pdf->SetAutoPageBreak(TRUE, 25 );

  // set image scale factor
  $pdf->setImageScale(4);
  // set image compression quality
  $pdf->setJPEGQuality(100);
  return $pdf;
} // function _webform2pdf_pdf_page()

/*
 * theme_webform2pdf_pdf_page: pdf page theme hook
 */
function theme_webform2pdf_pdf_page($vars) {
  return _webform2pdf_pdf_page($vars['pdf']);
} // function theme_webform2pdf_pdf_page()

/*
 * _webform2pdf_pdf_content: Fills PDF page with content
 */
function _webform2pdf_pdf_content($pdf, $node, $template) {
  $pdf->SetFont($template['p_font_family'], '', $template['p_font_size'] );

  foreach ($template['pages'] as $page) {
    // add a page
    $pdf->AddPage();
    $pdf->writeHTML($page, TRUE, FALSE, FALSE, FALSE, $template['p_txt_align']);
  }

  return $pdf;
} // function _webform2pdf_pdf_content()

/*
 * theme_webform2pdf_pdf_content: pdf content theme hook
 */
function theme_webform2pdf_pdf_content($vars) {
  return _webform2pdf_pdf_content($vars['pdf'], $vars['node'], $vars['template']);
} // function theme_webform2pdf_pdf_content()

function theme_webform2pdf_content($vars) {
  $email = array(
    'html' => 'text',
    'excluded_components' => array(),
  );

  return webform_replace_tokens($vars['template']['p_body']['value'], $vars['node'], $vars['submission'], $email, TRUE);
} // function theme_webform2pdf_pdf_content()

/*
 * theme_webform2pdf_mail2pdf(): mail attachment pdf
 */
function theme_webform2pdf_mail2pdf($vars) {
  $node = node_load($vars['nid']);

  $submission = webform_menu_submission_load($vars['sid'], $vars['nid']);

  $template = _webform2pdf_get_template($node->nid);
  $pdf = theme('webform2pdf_pdf_init', array('node' => $node, 'template' => $template));
  if ( !empty($pdf) ) {
    $pdf = theme('webform2pdf_pdf_header', array('pdf' => $pdf, 'node' => $node, 'template' => $template));
    $pdf = theme('webform2pdf_pdf_footer', array('pdf' => $pdf, 'node' => $node, 'template' => $template));
    $pdf = theme('webform2pdf_pdf_page', array('pdf' => $pdf));

    $page = theme('webform2pdf_content', array('node' => $node, 'submission' => $submission, 'template' => $template));

    $template['pages'] = explode('%pagebreak', $page);

    $pdf = theme('webform2pdf_pdf_content', array('pdf' => $pdf, 'node' => $node, 'template' => $template));

    // reset pointer to the last page
    $pdf->lastPage();

    // Return PDF document
    return $pdf->Output('filename', 'S');
  }
} // function theme_webform2pdf_mail2pdf()

function theme_webform2pdf_filename($vars) {
  $sid = is_object($vars['submission']) ? $vars['submission']->sid : $vars['submission'];

  $pdf_file_name = "webform_submission-" . $vars['node']->nid;
  $pdf_file_name .= !empty($sid) ? '-' . $sid : '';
  $pdf_file_name .= ".pdf";
  return $pdf_file_name;
}
