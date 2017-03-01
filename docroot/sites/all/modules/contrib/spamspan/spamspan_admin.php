<?php

/**
 * @file
 * This module implements the spamspan technique (http://www.spamspan.com ) for hiding email addresses from spambots.
 *
 * Move less frequently used code out of the .module file.
 */

// TODO: refactor code to drop spamspan_admin class
class spamspan_admin {
  protected $configuration_page = 'admin/config/content/formats/spamspan';
  protected $defaults;
  protected $display_name = 'SpamSpan';
  protected $filter;
  protected $help = '<p>The SpamSpan module obfuscates email addresses to help prevent spambots from collecting them. Read the <a href="@url">Spamspan configuration page</a>.</p>';
  protected $page;

  function __construct() {
    $info = spamspan_filter_info();
    $this->defaults = $info['spamspan']['default settings'];
  }
  function defaults() {
    return $this->defaults;
  }
  function display_name() {
    return $this->display_name;
  }
  function filter_is() {
    return isset($this->filter);
  }
  function filter_set($filter) {
    $this->filter = $filter;
  }
  
  /**
   * Settings callback for spamspan filter
   */
  function filter_settings($form, $form_state, $filter, $format, $defaults, $filters) {
    $filter->settings += $defaults;
  
    // spamspan '@' replacement
    $settings['spamspan_at'] = array(
      '#type' => 'textfield',
      '#title' => t('Replacement for "@"'),
      '#default_value' => $filter->settings['spamspan_at'],
      '#required' => TRUE,
      '#description' => t('Replace "@" with this text when javascript is disabled.'),
    );
    $settings['spamspan_use_graphic'] = array(
      '#type' => 'checkbox',
      '#title' => t('Use a graphical replacement for "@"'),
      '#default_value' => $filter->settings['spamspan_use_graphic'],
      '#description' => t('Replace "@" with a graphical representation when javascript is disabled'
        . ' (and ignore the setting "Replacement for @" above).'),
    );
    $settings['spamspan_dot_enable'] = array(
      '#type' => 'checkbox',
      '#title' => t('Replace dots in email with text'),
      '#default_value' => $filter->settings['spamspan_dot_enable'],
      '#description' => t('Switch on dot replacement.'),
    );
    $settings['spamspan_dot'] = array(
      '#type' => 'textfield',
      '#title' => t('Replacement for "."'),
      '#default_value' => $filter->settings['spamspan_dot'],
      '#required' => TRUE,
      '#description' => t('Replace "." with this text.'),
    );
    $settings['use_form'] = array(
      '#type' => 'fieldset',
      '#title' => t('Use a form instead of a link'),
    );
    $settings['use_form']['spamspan_use_form'] = array(
      '#type' => 'checkbox',
      '#title' => t('Use a form instead of a link'),
      '#default_value' => $filter->settings['spamspan_use_form'],
      '#description' => t('Link to a contact form instad of an email address. The following settings are used only if you select this option.'),
    );
    $settings['use_form']['spamspan_form_pattern'] = array(
      '#type' => 'textfield',
      '#title' => t('Replacement string for the email address'),
      '#default_value' => $filter->settings['spamspan_form_pattern'],
      '#required' => TRUE,
      '#description' => t('Replace the email link with this string and substitute the following <br />%url = the url where the form resides,<br />%email = the email address (base64 and urlencoded),<br />%displaytext = text to display instead of the email address.'),
    );
    $settings['use_form']['spamspan_form_default_url'] = array(
      '#type' => 'textfield',
      '#title' => t('Default url'),
      '#default_value' => $filter->settings['spamspan_form_default_url'],
      '#required' => TRUE,
      '#description' => t('Default url to form to use if none specified (e.g. me@example.com[custom_url_to_form])'),
    );
    $settings['use_form']['spamspan_form_default_displaytext'] = array(
      '#type' => 'textfield',
      '#title' => t('Default displaytext'),
      '#default_value' => $filter->settings['spamspan_form_default_displaytext'],
      '#required' => TRUE,
      '#description' => t('Default displaytext to use if none specified (e.g. me@example.com[custom_url_to_form|custom_displaytext])'),
    );

    // we need this to insert our own validate/submit handlers
    // we use our own validate handler to extract use_form settings
    $settings['use_form']['#process'] = array('_spamspan_admin_settings_form_process');
    return $settings;
  }


  /**
   * Responds to hook_help().
   */
  function help($path, $arg) {
    switch ($path) {
      case 'admin/help#spamspan':
        return t($this->help, array('@url' => $this->configuration_page));
    }
  }

  /**
   * @function
   * Generic logging function. Used mainly for development.
   */
  function log($message, $variables = array()) {
    watchdog($this->display_name, $message, $variables);
  }
  /**
   * Responds to hook_menu().
   */
  function menu() {
    $items[$this->configuration_page] = array(
      'title' => 'Spamspan',
      'description' => 'Experiment with the Spamspan function.',
      'type' => MENU_LOCAL_TASK,
      'page callback' => 'drupal_get_form',
      'page arguments' => array('spamspan_admin_page'),
      'access arguments' => array('administer filters'),
    );
    return $items;
  }

  /**
   * A helper function for the callbacks
   *
   * Replace an email addresses which has been found with the appropriate
   * <span> tags
   *
   * @param $name
   *  The user name
   * @param $domain
   *  The email domain
   * @param $contents
   *  The contents of any <a> tag
   * @param $headers
   *  The email headers extracted from a mailto: URL
   * @param $vars
   *  Optional parameters to be implemented later.
   * @param $settings
   *  Provide specific settings. They replace anything set through filter_set().
   * @return
   *  The span with which to replace the email address
   */
  function output($name, $domain, $contents = '', $headers = array(), $vars = array(), $settings = NULL) {
    if ($settings === NULL) {
      $settings = $this->defaults;
      if ($this->filter_is()) {
        $settings = $this->filter->settings;
      }
    }

    // processing for forms
    if (!empty($settings['spamspan_use_form'])) {
      $email = urlencode(base64_encode($name . '@' . $domain));

      //put in the defaults if nothing set
      if (empty($vars['custom_form_url'])) {
        $vars['custom_form_url'] = $settings['spamspan_form_default_url'];
      }
      if (empty($vars['custom_displaytext'])) {
        $vars['custom_displaytext'] = t($settings['spamspan_form_default_displaytext']);
      }
      $vars['custom_form_url'] = strip_tags($vars['custom_form_url']);
      $vars['custom_displaytext'] = strip_tags($vars['custom_displaytext']);

      $url_parts = parse_url($vars['custom_form_url']);
      if (!$url_parts) {
        $vars['custom_form_url'] = '';
      }
      else if (empty($url_parts['host'])) {
        $vars['custom_form_url'] = base_path() . trim($vars['custom_form_url'], '/');
      }

      $replace = array('%url' => $vars['custom_form_url'], '%displaytext' => $vars['custom_displaytext'], '%email' => $email);

      $output = strtr($settings['spamspan_form_pattern'], $replace);
      return $output;
    }

    $at = $settings['spamspan_at'];
    if ($settings['spamspan_use_graphic']) {
      $at = theme('spamspan_at_sign', array('settings' => $settings));
    }

    if ($settings['spamspan_dot_enable']) {
      // Replace .'s in the address with [dot]
      $name = str_replace('.', '<span class="t">' . $settings['spamspan_dot'] . '</span>', $name);
      $domain = str_replace('.', '<span class="t">' . $settings['spamspan_dot'] . '</span>', $domain);
    }
    $output = '<span class="u">' . $name . '</span>' . $at . '<span class="d">' . $domain . '</span>';

  
    // if there are headers, include them as eg (subject: xxx, cc: zzz)
    // we replace the = in the headers by ": " to look nicer
    if (count($headers)) {
      foreach ($headers as $key => $header) {
        // check if header is already urlencoded, if not, encode it
        if ($header == rawurldecode($header)) {
          $header = rawurlencode($header);
          //replace the first = sign
          $header = preg_replace('/%3D/', ': ', $header, 1);
        }
        else {
          $header = str_replace('=', ': ', $header);
        }

        $headers[$key] = $header;
      }
      $output .= '<span class="h"> (' . check_plain(implode(', ', $headers)) . ') </span>';
    }

    // If there are tag contents, include them, between round brackets.
    // Remove emails from the tag contents, otherwise the tag contents are themselves
    // converted into a spamspan, with undesirable consequences - see bug #305464.
    if (!empty($contents)) {
      $contents = preg_replace('!' . SPAMSPAN_EMAIL . '!ix', '', $contents);

      // remove anything except certain inline elements, just in case.  NB nested
      // <a> elements are illegal.
      $contents = filter_xss($contents, array('em', 'strong', 'cite', 'b', 'i', 'code', 'span', 'img'));

      if (!empty($contents)) {
        $output .= '<span class="a"> (' . $contents . ')</span>';
      }
    }

    // put in the extra <a> attributes
    // this has to come after the xss filter, since we want comment tags preserved
    if (!empty($vars['extra_attributes'])) {
      $output .= '<span class="e"><!--'. strip_tags($vars['extra_attributes']) .'--></span>';
    }

    $output = '<span class="spamspan">' . $output . '</span>';
    
    return $output;
  }
  
  /**
   * Return the admin page.
   * External text should be checked: = array('#markup' => check_plain($format->name));
   */
  function page_object() {
    if (!isset($this->page)) {
      $this->page = new spamspan_admin_page($this);
    }
    return $this->page;
  }
  function page($form, &$form_state) {
    return $this->page_object()->form($form, $form_state);
  }
  function page_submit($form, &$form_state) {
    $this->page_object()->submit($form, $form_state);
  }
}

function _spamspan_admin_settings_form_process(&$element, &$form_state, &$complete_form) {
  $complete_form['#validate'][] = '_spamspan_admin_settings_form_validate';
  return $element;
}

function _spamspan_admin_settings_form_validate(&$form, &$form_state) {
  $settings = $form_state['values']['filters']['spamspan']['settings'];
  $use_form = $settings['use_form'];

  //no trees, see https://www.drupal.org/node/2378437
  unset($settings['use_form']);
  $settings += $use_form;
  $form_state['values']['filters']['spamspan']['settings'] = $settings;
}
