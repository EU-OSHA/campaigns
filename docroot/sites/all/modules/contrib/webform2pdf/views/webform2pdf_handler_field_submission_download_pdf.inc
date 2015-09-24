<?php

/**
 * @file
 * Views handler to download pdf link to a submission.
 */

/**
 * Field handler to present a download pdf link to the user.
 */
class webform2pdf_handler_field_submission_download_pdf extends views_handler_field {
  var $link_type;

  function construct() {
    // We need to set this property before calling the construct() chain
    // as we use it in the option_definintion() call.
    $this->link_type = $this->definition['link_type'];

    parent::construct();
    $this->additional_fields['sid'] = 'sid';
    $this->additional_fields['nid'] = 'nid';
  }

  function allow_advanced_render() {
    return FALSE;
  }

  function option_definition() {
    $options = parent::option_definition();
    $options['label'] = array('default' => '', 'translatable' => TRUE);
    $options['text'] = array('default' => $this->link_type, 'translatable' => TRUE);
    $options['access_check'] = array('default' => TRUE);
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['text'] = array(
      '#type' => 'textfield',
      '#title' => t('Text to display'),
      '#default_value' => $this->options['text'],
      '#description' => t('The token [serial] will be replaced with the serial number and draft indication.'),
    );
    $form['access_check'] = array(
      '#type' => 'checkbox',
      '#title' => t('Verify submission access for each link'),
      '#default_value' => $this->options['access_check'],
    );
  }

  function render($values) {
    $sid = $values->{$this->aliases['sid']};
    $nid = $values->{$this->aliases['nid']};

    $text = $this->options['text'];
    $text = !empty($text) ? $text : t('download pdf');
    $link = l($text, 'node/' . $nid . '/submission/' . $sid . '/downloadpdf');

    if ($this->options['access_check']) {
      module_load_include('inc', 'webform', 'includes/webform.submissions');
      $node = node_load($nid);
      $submission = webform_get_submission($nid, $sid);
      if (!webform_submission_access($node, $submission, 'view')) {
        return;
      }
    }

    return $link;
  }
}
