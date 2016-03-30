<?php

function osha_newsletter_reorder_error_messages(){
  $error_messages = drupal_get_messages('error');

  if (isset($error_messages['error'])) {
    sort($error_messages['error']);

    foreach($error_messages['error'] as $idx => $error) {
      drupal_set_message($error,'error');
    }
  }
}
