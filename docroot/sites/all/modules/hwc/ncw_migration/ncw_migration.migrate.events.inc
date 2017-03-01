<?php

/**
 * Class NCWEventsMigration migrates events
 *
 * Set hwc_migration_events_url variable for explicit source URL.
 */
class NCWEventsMigration extends AbstractNCWNodeMigration {

  public function __construct($arguments) {
    parent::__construct($arguments, 'NCWEventsSource', 'events');
    $this->description = 'Import events from NCW';
  }

  function addFieldMappings() {
    parent::addFieldMappings();

    $this->addFieldMapping('field_tags:source_type')->defaultValue('tid');
    $this->addFieldMapping('field_tags:create_term')->defaultValue(FALSE);
    $this->addFieldMapping('field_tags', 'field_tags');

    $this->addUnmigratedDestinations(array(
      'field_city:language',
      'field_agency_contact_reply:language',
      'field_agency_initial_contact:language',
      'field_agency_rep_confirmed:language',
      'field_organised_by:ignore_case',
      'field_organised_by:source_type',
      'field_organization:language',
      'field_start_date:rrule',
      'field_tags:ignore_case',
      'field_related_documents:file_class',
      'field_related_documents:preserve_files',
      'field_related_documents:destination_dir',
      'field_related_documents:destination_file',
      'field_related_documents:source_dir',
      'field_related_documents:urlencode',
      'field_related_documents:description',
      'field_related_documents:display',
      'field_website_of_event:language',
    ));
    $this->ignoreMetatagMigration();
  }

  protected function getManuallyMigratedFields() {
    return array('field_tags');
  }

  function prepareRow($row) {
    parent::prepareRow($row);
    // Trim title.
    $row->field_tags = osha_migration_normalize_migrated_term_reference($row->field_tags, 'tax_tags');
    $row->title = views_trim_text(array(
      'max_length' => 150,
      'word_boundary' => TRUE,
      'ellipsis' => TRUE,
      'html' => FALSE,
    ), $row->title);
  }
}


class NCWEventsSource extends AbstractNCWNodeSource {

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
      'field_country_code',
      'field_city',
      'field_agency_role',
      'field_tags',
      'field_adonis',
      'field_adonis_language',
      'field_agency_contact_reply',
      'field_agency_initial_contact',
      'field_agency_rep_confirmed',
      'field_color',
      'field_comments_summary_after_eve',
      'field_comments_summary_after_eve_language',
      'field_event_in_amp',
      'field_event_type',
      'field_for_the_web',
      'field_number_of_attendees',
      'field_organised_by',
      'field_organization',
      'field_satisfaction_rate',
      'field_start_date',
      'field_start_date_timezone',
      'field_start_date_value2',
      'field_unit_ref',
      'field_website_of_event',
      'field_website_of_event_title',
      'field_website_of_event_attributes',
      'field_related_documents',
      'field_related_documents_language',
      'field_migration_source',
    );
    return array_combine($fields, $fields);
  }
}
