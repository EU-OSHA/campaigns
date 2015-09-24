<?php

function webform2pdf_send2pdf($node, $submission) {
  $webform2pdf = _webform2pdf_get_template($node->nid);
  $nopdf = array();
  if (isset($webform2pdf['enabled']) && $webform2pdf['enabled'] && $webform2pdf['pdf_send_email']) {
    $no_mail = isset($webform2pdf['no_send_email_addr']) ? $webform2pdf['no_send_email_addr'] : FALSE;

    if (is_array($no_mail)) {
      $no_mail = array_diff($no_mail, array(0));
      if ( !empty($no_mail) ) {
        foreach ($no_mail as $eid) {
          $email_addresses = $node->webform['emails'][$eid]['email'];
          if ( isset($node->webform['components'][$email_addresses]) ) {
            $email_addresses = $submission->data[$eid]['value'];
          }
          else {
            $email_addresses = array_filter(explode(',', check_plain($node->webform['emails'][$eid]['email'])));
          }
          $nopdf = array_merge($nopdf, $email_addresses);
          $nopdf = array_map("trim", $nopdf);
        }
      }
    }

    // Check for a multi-page form that is not yet complete.
    return array('nid' => $node->nid, 'sid' => $submission->sid, 'nopdf' => $nopdf);
  }
}

