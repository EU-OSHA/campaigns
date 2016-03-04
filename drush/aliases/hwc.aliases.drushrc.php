<?php

$aliases['staging'] = array(
  'uri' => 'osha-campaigns-staging.mainstrat.com',
  'db-allows-remote' => TRUE,
  'remote-host' => 'osha-campaigns-staging01.mainstrat.com',
  'remote-user' => 'osha',
  'root' => '/expert/campaigns/docroot',
  'path-aliases' => array(
    '%files' => 'sites/default/files',
  ),
  'command-specific' => array(
    'sql-sync' => array(
      'simulate' => '1',
      'source-dump' => '/tmp/campaigns-source-dump.sql',
    ),
  ),
);


// Add your local aliases.
if (file_exists(dirname(__FILE__) . '/aliases.local.php')) {
  include dirname(__FILE__) . '/aliases.local.php';
}
