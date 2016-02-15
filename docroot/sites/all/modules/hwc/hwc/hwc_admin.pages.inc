<?php

function hwc_admin_config_form() {
  $form['title'] = array(
    '#markup' => '<h1>HWC website configuration</h1>',
  );
  $form['fb_app_key'] = array(
    '#type' => 'textfield',
    '#default_value' => variable_get('fb_app_key', ''),
    '#title' => 'Facebook application key',
  );
  // By default, render the form using theme_system_settings_form().
  if (!isset($form ['#theme'])) {
    $form ['#theme'] = 'system_settings_form';
  }

  $tags_voc = taxonomy_vocabulary_machine_name_load(OSHA_TAXONOMIES_TAGS);
  $tags = taxonomy_term_load_multiple(array(), array('vid' => $tags_voc->vid));
  $options = array();
  foreach ($tags as $tag) {
    $options[$tag->tid] = $tag->name;
  }
  $form['hwc_current_campaign_tags'] = array(
    '#title' => 'Current campaigns tags',
    '#type' => 'select',
    '#multiple' => TRUE,
    '#options' => $options,
    '#default_value' => variable_get('hwc_current_campaign_tags', array()),
  );
  $form['hwc_partner_registration_deadline'] = array(
    '#title' => 'Campaign partners registration deadline',
    '#description' => 'Starting from 12:00 AM of the date selected here, the registration is no longer visible',
    '#type' => 'date',
    '#default_value' => variable_get('hwc_partner_registration_deadline', ''),
  );
  $form['hwc_partner_registration_deadline_message'] = array(
    '#title' => 'Message to show after the registration deadline is over',
    '#description' => '',
    '#type' => 'textfield',
    '#default_value' => variable_get('hwc_partner_registration_deadline_message', ''),
  );

  $form['site_hwc_mostra_mailbox'] = array(
    '#title' => 'Mostra mailbox',
    '#description' => '',
    '#type' => 'textfield',
    '#default_value' => variable_get('site_hwc_mostra_mailbox', ''),
  );

  // NCW migration
  if (module_exists('migrate')) {
    $form['migration'] = array(
      '#type' => 'fieldset',
      '#title' => 'Corporate content migration',
      '#collapsible' => TRUE,
      '#weight' => 100,
    );
    $note = 'To disable one of the migrations set the URL empty then Save. Endpoints should expose JSON data';
    if (module_exists('migrate_ui')) {
      $note .= ' ' . l('Visit migration status overview', 'admin/content/migrate/groups/ncw');
    }
    $form['migration']['note'] = array(
      '#type' => 'item',
      '#markup' => $note,
      '#weight' => -1,
    );

    foreach(migrate_migrations() as $machine_name => $meta) {
      $migration = MigrationBase::getInstance($machine_name);
      if ($group = $migration->getGroup()) {
        // Filter all migrations from NCW group
        if ('ncw' == $group->getName()) {
          $form['migration']["hwc_migration_${machine_name}_url"] = array(
            '#type' => 'textfield',
            '#title' => ucfirst(str_replace('_', ' ', $machine_name)) . ' endpoint URI',
            '#default_value' => variable_get("hwc_migration_${machine_name}_url", ''),
            '#description' => 'Uri that will be appended to the Root endpoint URL defined',
            '#size' => 90,
          );
        }
      }
      uksort($form['migration'], 'strcmp');
    }
  }

  $form['migration']["hwc_migration_root_url"] = array(
    '#type' => 'textfield',
    '#title' => 'Root endpoint URL',
    '#default_value' => variable_get("hwc_migration_root_url", ''),
    '#size' => 90,
  );

  $form = system_settings_form($form);
  $form['actions']['#weight'] = 150;
  return $form;
}
