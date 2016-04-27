<?php

/**
 * Ajax endpoint to deliver the newsletter subscribe block with CAPTCHA.
 */
function osha_newsletter_block_subscribe_load_ajax() {
  $form = drupal_get_form('campaigns_newsletter_subscribe_captcha_form');
  $email_id = $form['email']['#id'];
  $content = drupal_render($form);
  $commands = array();
  $commands[] = ajax_command_replace('#newsletter-subscription-frontpage-form-wrapper', $content);
  $commands[] = ajax_command_invoke('#' . $email_id, 'focus');
  $commands[] = ajax_command_invoke(NULL, 'captcha_init');
  $page = array(
    '#type' => 'ajax',
    '#commands' => $commands,
  );
  ajax_deliver($page);
}

/**
 * Frontpage newsletter subscribe form.
 */
function campaigns_newsletter_subscribe_form() {
  $form['#prefix'] = '<div id="newsletter-subscription-frontpage-form-wrapper">';
  $form['#suffix'] = '</div>';

  $form['email'] = array(
    '#type' => 'textfield',
    '#size' => 30,
    '#attributes' => array('placeholder' => t('E-mail address'), 'title' => t('E-mail address')),
  );
  $form['#validate'] = array('campaigns_newsletter_subscribe_captcha_form_validate');
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Sign up!'),
    '#submit' => array('campaigns_newsletter_subscribe_captcha_form_submit'),
  );
  if (user_is_anonymous()) {
    drupal_add_library('system', 'drupal.ajax');
    drupal_add_library('system', 'jquery.form');
    drupal_add_js(drupal_get_path('module', 'osha_newsletter') . '/js/ajax.js');
  }

  return $form;
}

/**
 * Frontpage newsletter subscribe form with CAPTCHA loaded with ajax.
 */
function campaigns_newsletter_subscribe_captcha_form() {
  $form = array();

  $form['#prefix'] = '<div id="newsletter-subscription-frontpage-form-wrapper">';
  $form['#suffix'] = '</div>';
  $form['email'] = array(
    '#type' => 'textfield',
    '#size' => 30,
    '#attributes' => array('placeholder' => t('E-mail address'), 'title' => t('E-mail address')),
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Sign up!'),
    '#submit' => array('campaigns_newsletter_subscribe_captcha_form_submit'),
  );
  $form['captcha'] = array(
    '#type' => 'captcha',
    '#captcha_type' => 'default',
  );
  return $form;
}

/**
 * Newsletter subscribe form validation.
 */
function campaigns_newsletter_subscribe_captcha_form_validate($form, &$form_state) {
  // Need to redirect due to Ajax handling.
  $has_error = FALSE;
  $referer = empty($_SERVER['HTTP_REFERER']) ? '/' : $_SERVER['HTTP_REFERER'];
  if (form_get_errors()) {
    // Invalid CAPTCHA.
    $has_error = TRUE;
  }
  if (empty($form_state['values']['email']) || !valid_email_address($form_state['values']['email'])) {
    form_set_error('email', t('The e-mail address is not valid.'));
    $has_error = TRUE;
  }
  if ($has_error) {
    $fs['redirect'] = $referer;
    drupal_redirect_form($fs);
  }
}

/**
 * Newsletter subscribe form submit.
 */
function campaigns_newsletter_subscribe_captcha_form_submit($form, &$form_state) {
  $email = $form_state['values']['email'];
  $to = variable_get('osha_newsletter_listserv', 'listserv@list.osha.europa.eu');

  // Need to redirect due to Ajax handling.
  $referer = empty($_SERVER['HTTP_REFERER']) ? '/' : $_SERVER['HTTP_REFERER'];
  $form_state['redirect'] = $referer;

  // Anonymous could avoid click on input and submit form without capcha input
  // so check for captcha.
  if (user_is_anonymous() && !isset($form_state['values']['captcha'])) {
    drupal_set_message('You have sent the form without captcha.', 'error');
    return;
  }

  osha_newsletter_send_email(
    'campaigns_subscribe_email',
    $to,
    $email,
    $form_state,
    t('Your subscription has been submitted succesfully.')
  );

}
