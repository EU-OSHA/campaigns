<?php

/**
 * @file
 * This module implements the spamspan technique (http://www.spamspan.com ) for hiding email addresses from spambots.
 *
 * Move less frequently used code out of the .module file.
 */

class spamspan_admin_page {
  protected $parent;
  protected $test_field = 'test_text';
  protected $test_text = 'My work email is me@example.com and my home email is me@example.org.';
  function __construct($parent) {
    $this->parent = $parent;
  }
  /**
   * Return the admin page.
   * External text should be checked: = array('#markup' => check_plain($format->name));
   */
  function form($form, &$form_state) {
    $defaults = $this->parent->defaults();
    $test_text = $this->test_text;
    if(isset($form_state['storage'][$this->test_field])) {
      $test_text = $form_state['storage'][$this->test_field];
    }
    $default_list = array();
    foreach ($defaults as $name => $value) {
      if ($value === TRUE) { $value = 'TRUE'; }
      elseif ($value === FALSE) { $value = 'FALSE'; }
      $default_list[] = $name . ': <strong>' . htmlentities($value) . '</strong>';
    }
    $form['configure'] = array('#markup' => t(
      '<p>The @dn module obfuscates email addresses to help prevent spambots from collecting them.'
      . ' It will produce clickable links if JavaScript is enabled,'
      . ' and will show the email address as <code>example [at] example [dot] com</code> if the browser does not support JavaScript.</p>'
      . '<p>To configure the module:<ol>'
      . '<li>Read the list of text formats at <a href="/admin/config/content/formats">Text formats</a>.</li>'
      . '<li>Select <strong>configure</strong> for the format requiring email addresses.</li>'
      . '<li>In <strong>Enable filters</strong>, select <em>@dn email address encoding filter</em>.</li>'
      . '<li>In <strong>Filter processing order </strong>, move @dn below <em>Convert line breaks into HTML</em> and above <em>Convert URLs into links</em>.</li>'
      . '<li>If you use the <strong>Limit allowed HTML tags</strong> filter, make sure that &lt;span&gt; is one of the allowed tags.</li>'
      . '<li>Select <strong>@dn email address encoding filter</strong> to configure @dn for the text format.</li>'
      . '<li>Select <strong>Save configuration</strong> to save your changes.</li>'
      . '</ol></p>'
      . '<h2>Defaults</h2>'
      . '<p>The following defaults are used for new filters and for spamspan() when there is no filter specified.</p>'
      . '<ul><li>' . implode('</li><li>', $default_list) . '</li></ul>'
      . '<h2>Test spamspan()</h2>'
      . '<p>Test the @dn <code>spamspan()</code> function using the following <strong>Test text</strong> field.'
      . ' Enter text containing an email address then hit the Test button. We set up a default example to get you started.</p>',
      array('@dn' => $this->parent->display_name())
    ));
    $form[$this->test_field] = array(
      '#type' => 'textfield',
      '#title' => t('Test text'),
      '#size' => 80,
      '#maxlength' => 200,
      '#default_value' => $test_text,
    );
    $filter = (object) array('settings' => array());
    $settings_form = $this->parent->filter_settings(array(), array(), $filter, '', $defaults, array());
    foreach ($defaults as $field => $value) {
      if (isset($settings_form['use_form'][$field])) {
        $form[$field] = $settings_form['use_form'][$field];
      }
      else {
        $form[$field] = $settings_form[$field];
      }
      if(isset($form_state['storage'][$field])) {
        $form[$field]['#default_value'] = $form_state['storage'][$field];
        $defaults[$field] = $form_state['storage'][$field];
      }
    }
    $test_result = spamspan($test_text, $defaults);
    $form['test_js'] = array('#markup' => '<p>The result passed through spamspan()'
      . ' and processed by Javasript:</p><div style="background-color: #ccffcc;">' . $test_result . '</div>');
    $form['test_result'] = array('#markup' => '<p>The result passed through spamspan() but not processed by Javascript:</p>'
      . '<div style="background-color: #ccccff;">'
      . str_replace('class="spamspan"', '', $test_result)
      . '</div>');
    $form['test_as_html'] = array('#markup' => '<p>The HTML in the result:</p>'
      . '<div style="background-color: #ffcccc;">' . nl2br(htmlentities($test_result)) . '</div>');
    $form['actions'] = array('#type' => 'actions');
    $form['actions']['submit'] = array('#type' => 'submit', '#value' => t('Test'));
    return $form;
  }
  /**
   * .
   */
  function submit($form, &$form_state) {
    // Store the submitted value in $form_state['storage']:
    $form_state['storage'][$this->test_field] = $form_state['values'][$this->test_field];
    $defaults = $this->parent->defaults();
    foreach ($defaults as $field => $value) {
      if (isset($form_state['values'][$field])) {
        $form_state['storage'][$field] = $form_state['values'][$field];
      }
    }

    // Force the form to rebuild to save the stored value.
    $form_state['rebuild'] = TRUE;
  }
}