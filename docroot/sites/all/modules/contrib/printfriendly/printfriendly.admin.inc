<?php

/**
 * @file
 * Administrative page callbacks for Service Links module.
 */

/**
 * Menu callback administration settings for general options.
 */
function printfriendly_admin_settings() {
  if (substr($_SERVER['REMOTE_ADDR'], 0, 4) == '127.'
      || $_SERVER['REMOTE_ADDR'] == '::1') {
    drupal_set_message(t('It appears that your site is running on a local
    server. PrintFriendly service requires a remotely-accessible web site
    to function.'), 'warning', FALSE);
  }
  $form['printfriendly_types'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Content Types'),
    '#description' => t('Configure where the printfriendly button should appear.'),
    '#options' => node_type_get_names(),
    '#default_value' => variable_get('printfriendly_types', array()),
  );
  $form['printfriendly_display'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Button display'),
    '#description' => t('Select content displays that the button should appear.'),
    '#options' => array(
      'teaser' => t('Teaser'),
      'full' => t('Full content page'),
    ),
    '#default_value' => array_filter(variable_get('printfriendly_display')),
  );
  $form['printfriendly_website_protocol'] = array(
    '#type' => 'select',
    '#title' => t('Website protocol'),
    '#options' => array(
      'http' => 'HTTP',
      'https' => 'HTTPS',
    ),
    '#default_value' => variable_get('printfriendly_website_protocol', 'http'),
  );

  $img_path = drupal_get_path('module', 'printfriendly') . '/images';
  $results = file_scan_directory($img_path, '/^.*\.(gif|png|jpg|GIF|PNG|JPG)$/');
  $options = array();
  foreach ($results as $image) {
    $options[$image->filename] = theme('image', array('path' => $image->uri));
  }
  ksort($options);

  $form['printfriendly_image'] = array(
    '#type' => 'radios',
    '#title' => t('Choose button'),
    '#options' => $options,
    '#default_value' => variable_get('printfriendly_image', 'button-print-grnw20.png'),
  );
  $form['support-link'] = array(
    '#markup' => t('Need help or have suggestions? !support-email.', array(
      '!support-email' => l(t('Support@PrintFriendly.com'), 'mailto:support@printfriendly.com', array(
        'absolute' => TRUE,
        'query' => array('subject' => 'Support for PrintFriendly Drupal module'),
      )),
    )),
    '#weight' => 1000,
  );

  return system_settings_form($form);
}
