<?php

/**
 * Newsletter subscribe block form.
 */
function osha_newsletter_block_subscribe_form($form, &$form_state) {
  $form = array();

  $form['#prefix'] = '<div id="newsletter-subscription-form-wrapper_2">';
  $form['#suffix'] = '</div>';
  $form['email_osh'] = array(
    '#type' => 'textfield',
    '#size' => 30,
    '#title' => t('You can sign up below:'),
    '#attributes' => array('placeholder' => t('E-mail address'), 'title' => t('E-mail address')),
  );
  if (user_is_anonymous()) {
    $form['captcha_osh'] = array(
      '#type' => 'captcha',
      '#captcha_type' => 'default',
    );
  }
  $link_label = t(variable_get('subscribe_block_details_link_label', 'Privacy notice'));
  $link_url = variable_get('subscribe_block_details_link_url', OSHA_PRIVACY_PAGE_URL);
  $form['details_link'] = array(
    '#markup' => '<a class="privacy-policy-oshmail" title="Subscribe to newsletter" href=' . url($link_url) . '>' . $link_label . '</a>',
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Subscribe'),
  );

  $form['unsubscribe_text'] = array(
    '#markup' => '<hr><span>' . t('Not interested any more?') . '</span>',
  );
  $form['unsubscribe'] = array(
    '#type' => 'submit',
    '#value' => t('Unsubscribe'),
    '#submit' => array('osha_newsletter_unsubscribe_form_submit'),
  );

  $form['#validate'] = array('osha_newsletter_block_subscribe_form_validate');
  $form['#submit'] = array('osha_newsletter_block_subscribe_form_submit');

  return $form;
}

function osha_newsletter_block_subscribe_form_validate($form, &$form_state) {
  $email = trim($form_state['values']['email_osh']);
  if (strlen($email) != 0) {
    if (!valid_email_address($form_state['values']['email_osh'])) {
      form_set_error('email_osh', t('The e-mail address is not valid.'));
    }
  }
  else {
    form_set_error('email_osh', t('Please enter the e-mail address.'));
  }
}

function osha_newsletter_block_subscribe_form_submit($form, &$form_state) {
  $email = $form_state['values']['email_osh'];
  $to = variable_get('osha_newsletter_listserv', 'listserv@list.osha.europa.eu');

  osha_newsletter_send_email(
    'subscribe_email',
    $to,
    $email,
    $form_state,
    t('Your subscription has been submitted succesfully.')
  );
}

/**
 * Form submission logic for the subscription form.
 */
function osha_newsletter_unsubscribe_form_submit($form, &$form_state) {
  $unsubscribe_email = $form_state['values']['email'];
  $to = variable_get('osha_newsletter_listserv', 'listserv@list.osha.europa.eu');

  osha_newsletter_send_email('unsubscribe_email', $to, $unsubscribe_email, $form_state,
    t('You have succesfully unsubscribed'));
}