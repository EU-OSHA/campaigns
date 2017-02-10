<?php

/**
 * Class NCWPublicationsMigration migrates publications.
 *
 * Set hwc_migration_publications_url variable for explicit source URL.
 */
class NCWPublicationsMigration extends AbstractNCWNodeMigration {

  public function __construct($arguments) {
    parent::__construct($arguments, 'NCWPublicationsSource', 'publication');
    $this->description = 'Import publications from NCW';
  }

  function addFieldMappings() {
    parent::addFieldMappings();

    $this->addFieldMapping('field_tags:source_type')->defaultValue('tid');
    $this->addFieldMapping('field_tags:create_term')->defaultValue(FALSE);
    $this->addFieldMapping('field_tags', 'field_tags');

    $this->addFieldMapping('field_publication_type:source_type')->defaultValue('tid');
    $this->addFieldMapping('field_publication_type:create_term')->defaultValue(FALSE);
    $this->addFieldMapping('field_publication_type', 'field_publication_type');

    $this->addFieldMapping('field_segment:source_type')->defaultValue('tid');
    $this->addFieldMapping('field_segment:create_term')->defaultValue(FALSE);
    $this->addFieldMapping('field_segment', 'field_relevant_for');

    $this->addFieldMapping('field_aditional_resources', 'field_aditional_resources');

    $this->addUnmigratedDestinations(array(
      'field_tags:ignore_case',
      'field_publication_type:ignore_case',
      'field_cover_image:file_class',
      'field_cover_image:preserve_files',
      'field_cover_image:destination_dir',
      'field_cover_image:destination_file',
      'field_cover_image:urlencode',
      'field_cover_image:source_dir',
      'field_cover_image:alt',
      'field_file:file_class',
      'field_file:preserve_files',
      'field_file:destination_dir',
      'field_file:destination_file',
      'field_file:source_dir',
      'field_file:urlencode',
      'field_file:description',
      'field_file:display',
      'field_publication_date:rrule',
      'field_publication_related_res:file_class',
      'field_publication_related_res:preserve_files',
      'field_publication_related_res:destination_dir',
      'field_publication_related_res:destination_file',
      'field_publication_related_res:source_dir',
      'field_publication_related_res:urlencode',
      'field_publication_related_res:description',
      'field_publication_related_res:display',
      'field_expiration_date:rrule',
    ));
    $this->ignoreMetatagMigration();
  }

  protected function getManuallyMigratedFields() {
    return array('field_tags', 'field_publication_type', 'field_aditional_resources');
  }

  function prepareRow($row) {
    parent::prepareRow($row);

    // field_related_publications
    $fi = field_info_field('field_related_publications');
    osha_migration_normalize_field_entityreference($row, 'field_related_publications', $fi);
    $related_publications = $row->field_related_publications;
    $row->field_related_publications = array();
    foreach ($related_publications as $original_nid) {
      $row->field_related_publications[] = $this->handleSourceMigration('publications', $original_nid);
    }
    $row->field_tags = osha_migration_normalize_migrated_term_reference($row->field_tags, 'tax_tags');
    if (empty($row->field_publication_type)) {
      watchdog(
        'ncw_migration',
        'Skipping import of publication without type: !title',
        array('!title' => $row->title)
      );
      return FALSE;
    }
    $type = array($row->field_publication_type['tid']);
    $row->field_publication_type = osha_migration_normalize_migrated_term_reference($type, 'tax_publication_types');

    $row->field_relevant_for = osha_migration_normalize_migrated_term_reference($row->field_relevant_for, 'tax_segment');

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

    // Replace "publications" with case-studies in aliases.
    // more things are done in prepare().
    $publication_type_term = taxonomy_get_term_by_name('Case studies', 'publication_types');
    if (!empty($publication_type_term)) {
      reset($publication_type_term);
      $publication_type_term = current($publication_type_term);
      if ($row->field_publication_type == $publication_type_term->tid) {
        $row->path = str_replace('/publications/', '/case-studies/', $row->path);
      }
    }
  }

  /**
   * Implements Migration::prepare()
   */
  public function prepare($entity, stdClass $row) {
    parent::prepare($entity, $row);
    $entity->path['pathauto'] = 0;
    $entity->path['alias'] = $row->path;
    // Remove old aliases and create redirects (when alias changes on source).
    if (!empty($row->path) && !empty($entity->nid)) {
      $existing_alias = path_load(array('source' => 'node/' . $entity->nid));
      if (!empty($existing_alias) && $existing_alias['alias'] != $row->path) {
        // Remove old alias
        path_delete(array('alias' => $existing_alias['alias']));
        // Redirect old alias
        $redirect = new stdClass();
        redirect_object_prepare($redirect);
        $redirect->source = $existing_alias['alias'];
        $redirect->redirect = $existing_alias['source'];
        $redirect->language = LANGUAGE_NONE;
        // Check if the redirect exists before saving.
        $hash = redirect_hash($redirect);
        if (!redirect_load_by_hash($hash)) {
          redirect_save($redirect);
        }
      }
    }
  }
}


class NCWPublicationsSource extends AbstractNCWNodeSource {

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
      'field_archived',
      'field_author',
      'field_author_language',
      'field_character_count',
      'field_cover_image',
      'field_cover_image_language',
      'field_file',
      'field_file_language',
      'field_expiration_date',
      'field_expiration_date_timezone',
      'field_expiration_date_value2',
      'field_page_count',
      'field_publication_bookshop_id',
      'field_publication_bookshop_id_language',
      'field_publication_date',
      'field_publication_date_timezone',
      'field_publication_date_value2',
      'field_publication_related_res',
      'field_publication_related_res_language',
      'field_publication_type',
      'field_tags',
      'field_related_publications',
      'field_aditional_resources',
    );
    return array_combine($fields, $fields);
  }

  /**
   * Include the related publications recursively into the migrated content.
   */
  public function readData() {
    $this->rows = array();
    $content = $this->fileGetContents($this->endpoint_url);
    if ($data = json_decode($content)) {
      foreach ($data->items as $ob) {
        $ob = $ob->item;
        $id = $this->itemIdentifier($ob);
        $node_url = $this->itemURL($id);
        if ($rowd = $this->fileGetContents($node_url)) {
          if ($row_ob = json_decode($rowd, TRUE)) {
            $row = new stdClass();
            foreach ($row_ob as $k => $v) { $row->$k = $v; }
            $this->rows[$id] = $row;
            $this->children_recursive_publications($row);
          }
        }
        else {
          $msg = format_string('Failed to read data from !url', array('!url' => $node_url));
          watchdog('ncw_migration', $msg, [], WATCHDOG_ERROR);
          $this->rows[$id] = NULL;
        }
      }
    }
    else {
      $msg = format_string('Failed to read data from !url', array('!url' => $this->endpoint_url));
      watchdog('ncw_migration', $msg, [], WATCHDOG_ERROR);
      throw new MigrateException($msg, Migration::MESSAGE_ERROR);
    }
    reset($this->rows);
  }


  protected function children_recursive_publications($row) {
    // Check the field_related_publications for children and add to source
    $tmp = new stdClass();
    $tmp->field_related_publications = $row->field_related_publications;
    $firp = field_info_field('field_related_publications');
    osha_migration_normalize_field_entityreference($tmp, 'field_related_publications', $firp);
    foreach($tmp->field_related_publications as $cid) {
      // Skip records already added
      if (array_key_exists($cid, $this->rows)) {
        continue;
      }
      $child_url = $this->itemURL($cid);
      if ($child_rowd = $this->fileGetContents($child_url)) {
        if ($child_row_ob = json_decode($child_rowd, TRUE)) {
          $child_row = new stdClass();
          foreach ($child_row_ob as $k => $v) { $child_row->$k = $v; }
          $this->rows[$cid] = $child_row;
          $this->children_recursive_publications($child_row);
        }
      }
    }
  }
}
