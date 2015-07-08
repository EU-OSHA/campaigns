<?php
function printfriendly_views_data() {
  $data = array();
  $data['node']['pfbutton'] = array(
    'title' => t('Printfriendly'),
    'help' => t('Printfriendly button.'),
    'field' => array(
      'handler' => 'printfriendly_views_handler_field_pfbutton',
      'click sortable' => FALSE,
    ),
  );

  return $data;
}
