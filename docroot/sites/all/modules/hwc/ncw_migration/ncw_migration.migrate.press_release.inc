<?php

/**
 * Class NCWPressMigration migrates press releases
 *
 * Set hwc_migration_press_releases_url variable for explicit source URL.
 */
class NCWPressMigration extends AbstractNCWNodeMigration {

  public function __construct($arguments) {
    parent::__construct($arguments, 'NCWPressSource', 'press_release');
    $this->description = 'Import press releases from NCW';
  }

  function addFieldMappings() {
    parent::addFieldMappings();

    $this->addFieldMapping('field_tags:source_type')->defaultValue('tid');
    $this->addFieldMapping('field_tags:create_term')->defaultValue(FALSE);
    $this->addFieldMapping('field_tags', 'field_tags');
    $this->addFieldMapping('field_aditional_resources', 'field_aditional_resources');
    $this->addFieldMapping('field_pr_notes_to_editor', 'field_pr_notes_to_editor');

    $this->addUnmigratedDestinations(array(
      'field_tags:ignore_case',
      'field_expiration_date:rrule',
      'field_image:file_class',
      'field_image:preserve_files',
      'field_image:destination_dir',
      'field_image:destination_file',
      'field_image:source_dir',
      'field_image:urlencode',
      'field_image:alt',
      'field_image:title',
      'field_publication_date:rrule',
      'field_pr_embargo_date:rrule',
    ));
    $this->ignoreMetatagMigration();
  }

  protected function getManuallyMigratedFields() {
    return array('field_tags', 'field_aditional_resources', 'field_pr_notes_to_editor');
  }

  function prepareRow($row) {
    parent::prepareRow($row);
    $row->field_tags = osha_migration_normalize_migrated_term_reference($row->field_tags, 'tax_tags');

    // field_aditional_resources
    $fi = field_info_field('field_aditional_resources');
    osha_migration_normalize_field_entityreference($row, 'field_aditional_resources', $fi);
    $additional_resources = $row->field_aditional_resources;
    $row->field_aditional_resources = array();
    foreach ($additional_resources as $original_nid) {
      if ($destid1 = ncw_migration_find_additional_resource($original_nid)) {
        $row->field_aditional_resources[] = $destid1;
      }
    }

    // field_pr_notes_to_editor
    if (!empty($row->field_pr_notes_to_editor)) {
      $source_press_releases = $row->field_pr_notes_to_editor[LANGUAGE_NONE];
      $row->notes_to_editor = array();
      foreach($source_press_releases as $original) {
        if ($destid1 = ncw_migration_find_migrated_item_id($original['target_id'], 'notes_to_editor')) {
          $row->field_pr_notes_to_editor[] = $destid1;
        }
      }
    }
  }
}


class NCWPressSource extends AbstractNCWNodeSource {

  /**
   * The list of available fields to map from the source, keyed by field name.
   */
  public function contentFields() {
    $fields = array(
      'title_field',
      'title_field_language',
      'body',
      'body_language',
      'body_summary',
      'body_format',
      'field_summary',
      'field_summary_format',
      'field_summary_language',
      'field_image_language',
      'field_publication_date',
      'field_publication_date_timezone',
      'field_publication_date_value2',
      'field_pr_embargo_date',
      'field_pr_embargo_date_timezone',
      'field_pr_embargo_date_value2',
      'field_expiration_date',
      'field_expiration_date_timezone',
      'field_expiration_date_value2',
      'field_image',
      'field_quote',
      'field_quote_format',
      'field_quote_language',
      'field_tags',
      'field_archived',
      'field_character_count',
      'field_page_count',
      'field_pr_notes_to_editor',
      'field_aditional_resources',
    );
    return array_combine($fields, $fields);
  }
}
