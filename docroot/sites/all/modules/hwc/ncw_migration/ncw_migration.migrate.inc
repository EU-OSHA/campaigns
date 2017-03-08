<?php

define('MIGRATE_STUB_MARKER', '#stub#');

/**
 * Implements hook_migrate_api().
 *
 * Set the API level to 2, for migration classes to be recognized by Migrate.
 */
function ncw_migration_migrate_api() {
  return array(
    'api' => 2,
    'groups' => array(
      'ncw' => array(
        'title' => 'Import data from NCW'
      ),
    ),
    'migrations' => array(
      'events' => array(
        'group_name' => 'ncw',
        'dependencies' => array('tax_tags'),
        'class_name' => 'NCWEventsMigration',
      ),
      'publications' => array(
        'group_name' => 'ncw',
        'dependencies' => array(
          'tax_tags', 'tax_publication_types', 'publications_add_res',
          'news_add_res', 'press_releases_add_res',
          'highlights_add_res', 'notes_to_editor', 'tax_segment',
        ),
        'class_name' => 'NCWPublicationsMigration',
      ),
      'publications_add_res' => array(
        'group_name' => 'ncw',
        'dependencies' => array('tax_tags', 'tax_publication_types'),
        'class_name' => 'NCWAdditionalResourcesPublicationsMigration',
      ),
      'news' => array(
        'group_name' => 'ncw',
        'dependencies' => array(
          'tax_tags', 'publications_add_res', 'news_add_res',
          'press_releases_add_res',
          'highlights_add_res'
        ),
        'class_name' => 'NCWNewsMigration',
      ),
      'news_add_res' => array(
        'group_name' => 'ncw',
        'dependencies' => array('tax_tags'),
        'class_name' => 'NCWAdditionalResourcesNewsMigration',
      ),
      'notes_to_editor' => array(
        'group_name' => 'ncw',
        'dependencies' => array('tax_tags'),
        'class_name' => 'NCWNoteMigration',
      ),
      'press_releases' => array(
        'group_name' => 'ncw',
        'dependencies' => array(
          'tax_tags', 'publications_add_res', 'news_add_res',
          'press_releases_add_res',
          'highlights_add_res', 'notes_to_editor'
        ),
        'class_name' => 'NCWPressMigration',
      ),
      'press_releases_add_res' => array(
        'group_name' => 'ncw',
        'dependencies' => array('tax_tags'),
        'class_name' => 'NCWAdditionalResourcesPressReleasesMigration',
      ),
      'highlights' => array(
        'group_name' => 'ncw',
        'dependencies' => array(
          'tax_tags', 'publications_add_res', 'news_add_res',
          'press_releases_add_res',
          'highlights_add_res'
        ),
        'class_name' => 'NCWHighlightMigration',
      ),
      'highlights_add_res' => array(
        'group_name' => 'ncw',
        'dependencies' => array('tax_tags'),
        'class_name' => 'NCWAdditionalResourcesHighlightsMigration',
      ),
      'infographics' => array(
        'group_name' => 'ncw',
        'dependencies' => array('tax_tags'),
        'class_name' => 'NCWInfographicsMigration',
      ),
      'press_contacts' => array(
        'group_name' => 'ncw',
        'dependencies' => array(),
        'class_name' => 'NCWPressContactMigration',
      ),
      'tax_country' => array(
        'group_name' => 'ncw',
        'dependencies' => array('tax_country_status'),
        'class_name' => 'NCWTaxonomyCountryMigration',
      ),
      'tax_country_status' => array(
        'group_name' => 'ncw',
        'dependencies' => array(),
        'class_name' => 'NCWTaxonomyCountryStatusMigration',
      ),
      'tax_fop_link_sections' => array(
        'group_name' => 'ncw',
        'dependencies' => array(),
        'class_name' => 'NCWTaxonomyFOPLinkSectionsMigration',
      ),
      'tax_newsletter_sections' => array(
        'group_name' => 'ncw',
        'dependencies' => array(),
        'class_name' => 'NCWTaxonomyNewsletterSectionsMigration',
      ),
      // Don't migrate some types
      // Magazine, Annual reports and other corporate publications, Promotional Material
      // Evaluation reports, Corporate strategies and annual management plans
      'tax_publication_types' => array(
        'group_name' => 'ncw',
        'dependencies' => array(),
        'class_name' => 'NCWTaxonomyPublicationTypeMigration',
        'skip_ids' => array(4, 2, 3, 1, 3022),
      ),
      'tax_segment' => array(
        'group_name' => 'ncw',
        'dependencies' => array(),
        'class_name' => 'NCWTaxonomySegmentationMigration',
      ),
      'tax_tags' => array(
        'group_name' => 'ncw',
        'dependencies' => array(),
        'class_name' => 'NCWTaxonomyTagsMigration',
      ),
//      'article' => array(
//        'group_name' => 'ncw',
//        'dependencies' => array(),
//        'class_name' => 'NCWSingleArticleMigration',
//      ),
    ),
  );
}

/////////////////////////// Migration abstract classes /////////////////////////

/**
 * Class AbstractNCWNodeMigration is used to migrate nodes from NCW.
 */
abstract class AbstractNCWNodeMigration extends Migration {

  protected $endpoint_url = NULL;
  protected $bundle = NULL;
  protected $missingUrl = TRUE;

  public function __construct($arguments, $source_klass, $bundle) {
    parent::__construct($arguments);

    /** Disable linkchecker globally to avoid failures during migration */
    global $linkchecker_disable_scan;
    $linkchecker_disable_scan = TRUE;

    $this->bundle = $bundle;
    if (!empty($arguments['dependencies'])) {
      $this->dependencies = $arguments['dependencies'];
    }
    $this->endpoint_url = $this->getMigrationURL();
    if ($this->validateEndpointURL()) {
      $this->missingUrl = FALSE;
    }
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'nid' => array(
          'type'        => 'varchar',
          'length'      => 255,
          'not null'    => TRUE,
          'description' => 'Original nid in the NCW website',
        ),
      ),
      MigrateDestinationNode::getKeySchema(),
      'default',
      array('track_last_imported' => TRUE)
    );
    $options = array(
      'cache_counts' => FALSE,
      'endpoint_url' => $this->endpoint_url,
      'track_changes' => TRUE,
    );
    if (!empty($arguments['skip_ids'])) {
      $options['skip_ids'] = $arguments['skip_ids'];
    }
    $this->source = new $source_klass($options);
    $this->destination = new MigrateDestinationNode($bundle);
    $this->addFieldMappings();
  }

  /**
   * Configure field mappings, reads bundle field information
   */
  protected function addFieldMappings() {
    // Node base fields
    $this->addFieldMapping('uid')->defaultValue(0);
    $this->addFieldMapping('comment')->defaultValue(0);
    $this->addFieldMapping('status', 'status');
    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('changed', 'changed');
    $this->addFieldMapping('created', 'created');
    $this->addFieldMapping('promote', 'promote');
    $this->addFieldMapping('sticky', 'sticky');
    $this->addFieldMapping('log', 'log');
    $this->addFieldMapping('language', 'language');
    $this->addFieldMapping('path', 'path');
    $this->addFieldMapping('workbench_access')->defaultValue('section'); // Assign default section

    // Handle field migration in a generic way
    $fields = field_info_instances('node', $this->bundle);
    $exposed = $this->source->fields();
    foreach($fields as $field_name => $field_info) {
      if (array_key_exists($field_name, $exposed) && !in_array($field_name, $this->getManuallyMigratedFields())) {
        $this->addFieldMapping($field_name, $field_name);

        // Extra mappings depending on field type
        $fi = field_info_field($field_name);
        if ($fi['translatable'] == 1
          && $fi['type'] != 'taxonomy_term_reference' /* field_organised_by */) {
          $this->addFieldMapping("$field_name:language", $field_name . '_language');
        }
        if ($fi['type'] == 'taxonomy_term_reference') {
          $this->addFieldMapping("$field_name:create_term")->defaultValue(TRUE);
        }
        if ($fi['type'] == 'link_field') {
          $this->addFieldMapping("$field_name:title", $field_name . '_title');
          $this->addFieldMapping("$field_name:attributes", $field_name . '_attributes');
        }
        if ($fi['type'] == 'text_with_summary') {
          $this->addFieldMapping("$field_name:summary", $field_name . '_summary');
          $this->addFieldMapping("$field_name:format", $field_name . '_format');
        }
        if ($fi['type'] == 'text_long') {
          $this->addFieldMapping("$field_name:format", $field_name . '_format');
        }
        if ($fi['type'] == 'datetime') {
          $this->addFieldMapping("$field_name:to", $field_name . '_value2');
          $this->addFieldMapping("$field_name:timezone", $field_name . '_timezone');
        }
        if ($fi['type'] == 'file' || $fi['type'] == 'image') {
          $this->addFieldMapping("$field_name:file_replace")->defaultValue(TRUE);
        }
      }
    }
    $this->addUnmigratedDestinations(
      array(
        'revision', 'tnid', 'translate', 'revision_uid', 'is_new'
      )
    );
  }

  protected function getManuallyMigratedFields() {
    return array();
  }

  protected function ignoreMetatagMigration() {
    $this->addUnmigratedDestinations(array(
      'metatag_title',
      'metatag_description',
      'metatag_abstract',
      'metatag_keywords',
      'metatag_robots',
      'metatag_news_keywords',
      'metatag_standout',
      'metatag_generator',
      'metatag_rights',
      'metatag_image_src',
      'metatag_canonical',
      'metatag_shortlink',
      'metatag_publisher',
      'metatag_author',
      'metatag_original-source',
      'metatag_revisit-after',
      'metatag_content-language',
      'metatag_dcterms.title',
      'metatag_dcterms.creator',
      'metatag_dcterms.subject',
      'metatag_dcterms.description',
      'metatag_dcterms.publisher',
      'metatag_dcterms.contributor',
      'metatag_dcterms.date',
      'metatag_dcterms.modified',
      'metatag_dcterms.type',
      'metatag_dcterms.format',
      'metatag_dcterms.identifier',
      'metatag_dcterms.source',
      'metatag_dcterms.language',
      'metatag_dcterms.relation',
      'metatag_dcterms.coverage',
      'metatag_dcterms.rights',
    ));
  }

  /**
   * Implements Migration::prepareRow() to adapt JSON fields data to what migrate expects in the field.
   */
  public function prepareRow($row) {
    try {
      ncw_migration_debug('!klass:      * Preparing source node: !id', array(
        '!klass' => get_class($this),
        '!id' => $row->nid
      ));
      $row->path = !empty($row->path['alias']) ? $row->path['alias'] : NULL;
      // Normalize JSON structure, to match migrate expectations for field data
      $fields = field_info_instances('node', $this->bundle);
      foreach ($fields as $field_name => $field_info) {
        if (in_array($field_name, $this->getManuallyMigratedFields())) {
          continue;
        }
        $fi = field_info_field($field_name);
        if ($fi['type'] == 'entityreference') {
          // Entity references will be manually handled by each migration
          continue;
        }
        $normalizer = 'osha_migration_normalize_field_' . $fi['type'];
        if (function_exists($normalizer)) {
          $filter_languages = array();
          if (!$this->allowMigrateTranslation()) {
            $filter_languages = array('en');
          }
          $normalizer($row, $field_name, $fi, $filter_languages);
        }
        else {
          $name = $this->currentMigration()->getMachineName();
          ncw_migration_debug("[BUG][$name] Cannot find normalization '$normalizer', skipping field $field_name");
          $row->{$field_name} = array();
        }
      }
      $row->field_migration_source = 'ncw';
    } catch(Exception $e) {
      ncw_migration_debug("Exception while preparing the row: {$row->nid}", 'error');
      return FALSE;
    }
    return TRUE;
  }

  /**
   * Implements Migration::prepare()
   */
  public function prepare($entity, stdClass $row) {
    $entity->workbench_moderation_state_new = OSHA_WORKFLOW_STATE_PUBLISHED;
  }

  // News should be imported only in EN - MH-19
  public function allowMigrateTranslation() {
    return !in_array($this->bundle, array('news'));
  }

  /**
   * Implements Migration::complete() to configure translations
   */
  public function complete($entity, stdClass $row) {
    unset($row->translations['data']['en']);
    if (!empty($row->translations['data']) && $this->allowMigrateTranslation()) {
      $handler = entity_translation_get_handler('node', $entity);
      foreach($row->translations['data'] as $language => $data) {
        $handler->setTranslation(array(
          'language' => $data['language'],
          'source' => $data['source'],
          'status' => $data['status'],
          'translate' => $data['translate'],
          'uid' => osha_migration_author_uid(),
        ));
      }
      $handler->saveTranslations();
    }
  }

  public function postImport() {
    $this->removeNeedsUpdateItems();
  }

  public function getMigrationURL() {
    $root = variable_get('hwc_migration_root_url', '');
    $variable = variable_get('hwc_migration_' . $this->getMachineName() . '_url');
    return $root . $variable;
  }

  public function validateEndpointURL() {
    if(empty($this->endpoint_url)) {
      return FALSE;
    }
    return TRUE;
  }

  protected function createStub($migration, array $source_id) {
    $node = new stdClass();
    node_submit($node);
    // Do not delete/change this marker unless you know what you are doing!
    $node->title = format_string(MIGRATE_STUB_MARKER . ' stub for original nid: !id', array('!id' => $source_id[0]));
    $node->language = 'en';
    $node->type = $this->destination->getBundle();
    $node->uid = 0;
    $node->status = 1;
    $node->path['pathauto'] = 0;
    $node->path['alias'] = '';
    node_save($node);
    if (isset($node->nid)) {
      return array($node->nid);
    }
    else {
      return FALSE;
    }
  }

  /**
   * Remove nodes that are not in the source anymore.
   */
  protected function removeNeedsUpdateItems() {
    $map = $this->getMap();
    $source = $this->getSource();
    $removed = $map->getRowsNeedingUpdate(10000);
    $to_be_removed = array();
    if (!empty($removed)) {
      if (strpos($this->arguments['machine_name'], 'tax_') === 0) {
        // TODO ?! Removing terms that don't exists anymore
        // Similar as for nodes below.
      }
      else {
        // Check if the needs review nodes are indeed missing in source.
        foreach ($removed as $to_remove) {
          $url = $source->itemURL($to_remove->sourceid1);
          $curl = curl_init();
          curl_setopt($curl, CURLOPT_URL, $url);
          curl_setopt($curl, CURLOPT_NOBODY, true);
          curl_setopt($curl, CURLOPT_CONNECTTIMEOUT, 5);
          curl_setopt($curl, CURLOPT_FOLLOWLOCATION, true);
          $result = curl_exec($curl);
          $info = curl_getinfo($curl);
          curl_close($curl);
          // Remove only if 404
          if (!empty($info['http_code']) && $info['http_code'] == 404) {
            node_delete($to_remove->destid1);
            $this->getMap()->delete(array($to_remove->sourceid1));
            watchdog('osha_sites_migration', 'Deleting NODE that are not in the source anymore (@migration): !nids.',
              array('!nids' => $to_remove->destid1, '@migration' => $this->arguments['machine_name']), WATCHDOG_INFO);
          }
        }
      }
    }
  }
}


/**
 * Class AbstractNCWNodeSource base for all NCW JSON node imports.
 */
abstract class AbstractNCWNodeSource extends MigrateSource {

  protected $endpoint_url = NULL;
  protected $rows = array();
  protected $count = -1;
  protected $skip_ids = array();

  public function __construct($options) {
    parent::__construct($options);
    $this->endpoint_url = $options['endpoint_url'];
    if (!empty($options['skip_ids'])) {
      $this->skip_ids = $options['skip_ids'];
    }
  }

  /**
   * Return a string representing the source, for display in the UI.
   */
  public function __toString() {
    return 'Extract data from NCW endpoint';
  }

  /**
   * Total number of entities.
   */
  public function computeCount() {
    ncw_migration_debug('!klass: Starting counting !url', array('!klass' => get_class($this), '!url' => $this->endpoint_url));
    if ($this->count == -1) {
      $data = $this->fileGetContents($this->endpoint_url);
      $this->count = 0;
      if ($data = json_decode($data)) {
        if (!empty($data->items)) {
          $data = $data->items;
          foreach ($data as $ob) {
            $ob = $ob->item;
            $id = $this->itemIdentifier($ob);
            if (!in_array($id, $this->skip_ids)) {
              $this->count++;
            }
          }
        }
      }
    }
    ncw_migration_debug('!klass: Found !count items', array('!klass' => get_class($this), '!count' => $this->count));
    return $this->count;
  }

  /**
   * Do whatever needs to be done to start a fresh traversal of the source data.
   *
   * This is always called at the start of an import, so tasks such as opening
   * file handles, running queries, and so on should be performed here.
   */
  public function performRewind() {
    reset($this->rows);
  }

  /**
   * Fetch the next row of data, returning it as an object.
   *
   * @return object
   *   FALSE data as stdClass, FALSE when there is no more data available.
   */
  public function getNextRow() {
    if (empty($this->rows)) {
      $this->readData();
    }
    $item = NULL;
    if (count($this->rows)) {
      $item = current($this->rows);
      next($this->rows);
    }
    return $item;
  }

  /**
   * Remote call to load the data from the endpoint URL
   */
  public function readData() {
    ncw_migration_debug('!klass: Starting reading items from !url', array('!klass' => get_class($this), '!url' => $this->endpoint_url));
    $this->rows = array();
    $content = $this->fileGetContents($this->endpoint_url);
    if ($data = json_decode($content)) {
      ncw_migration_debug('!klass:      * Processing !count items', array('!klass' => get_class($this), '!count' => count($data->items)));
      foreach ($data->items as $ob) {
        $ob = $ob->item;
        $id = $this->itemIdentifier($ob);
        if (in_array($id, $this->skip_ids)) {
          continue;
        }
        $node_url = $this->itemURL($id);
        ncw_migration_debug('!klass:      * Reading item: !url', array('!klass' => get_class($this), '!url' => $node_url));
        if ($rowd = $this->fileGetContents($node_url)) {
          if ($row_ob = json_decode($rowd, TRUE)) {
            $row = new stdClass();
            foreach($row_ob as $k => $v) {
              $row->$k = $v;
            }
            $this->rows[$id] = $row;
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
    ncw_migration_debug('!klass: Done reading items', array('!klass' => get_class($this)));
    reset($this->rows);
  }

  public function fileGetContents($url) {
    //@todo replace all instances of fileGetContents
    return ncw_migration_file_get_contents($url);
  }

  public function itemURL($id) {
    return ncw_migration_datasource_url() . '/export/node/' . $id;
  }

  public function itemIdentifier($ob) {
    return $ob->nid;
  }

  public function fields() {
    return array(
      'nid' => 'nid',
      'title' => 'title',
      'created' => 'created',
      'changed' => 'changed',
      'status' => 'status',
      'promote' => 'promote',
      'sticky' => 'sticky',
      'log' => 'log',
      'language' => 'language',
      'path' => 'path',
    ) + $this->contentFields();
  }

  /**
   * Check the provided ID exists in the migrated source.
   *
   * @param mixed $id
   *   ID to verify
   *
   * @return bool
   *   TRUE if the key exists, FALSE otherwise
   */
  public function containsKey($id) {
    return array_key_exists($id, $this->rows);
  }

  public abstract function contentFields();
}


/**
 * Class AbstractNCWNodeMigration is used to migrate nodes from NCW.
 */
abstract class AbstractNCWTaxonomyTermMigration extends AbstractNCWNodeMigration {

  public function __construct($arguments, $source_klass, $bundle) {
    parent::__construct($arguments, $source_klass, $bundle);
    $this->bundle = $bundle;
    if (!empty($arguments['dependencies'])) {
      $this->dependencies = $arguments['dependencies'];
    }
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'tid' => array(
          'type'        => 'varchar',
          'length'      => 255,
          'not null'    => TRUE,
          'description' => 'Original tid in the NCW website',
        ),
      ),
      MigrateDestinationTerm::getKeySchema()
    );
    $options = array(
      'endpoint_url' => $this->endpoint_url,
      'track_changes' => TRUE,
    );
    if (!empty($arguments['skip_ids'])) {
      $options['skip_ids'] = $arguments['skip_ids'];
    }
    $this->source = new $source_klass($options);
    $this->destination = new MigrateDestinationTerm($bundle, array('language' => 'en'));
    $this->ignoreMetatagMigration();
  }

  /**
   * Configure field mappings, reads bundle field information.
   *
   * @param array $ignore
   *   Ignore these fields during mapping (or handle manually in derived class).
   */
  protected function addFieldMappings() {
    // Taxnomy term base fields
    $this->addSimpleMappings(array('name', 'description', 'format', 'weight'));

    // Handle field migration in a generic way
    $fields = field_info_instances('taxonomy_term', $this->bundle);
    $exposed = $this->source->fields();
    foreach($fields as $field_name => $field_info) {
      if (array_key_exists($field_name, $exposed) && !in_array($field_name, $this->getManuallyMigratedFields())) {
        $this->addFieldMapping($field_name, $field_name);
        // Extra mappings depending on field type
        $fi = field_info_field($field_name);
        if ($fi['translatable'] == 1 && $fi['type'] != 'taxonomy_term_reference' /* field_organised_by */) {
          $this->addFieldMapping("$field_name:language", $field_name . '_language');
        }
        if ($fi['type'] == 'taxonomy_term_reference') {
          $this->addFieldMapping("$field_name:create_term")->defaultValue(TRUE);
        }
        if ($fi['type'] == 'link_field') {
          $this->addFieldMapping("$field_name:title", $field_name . '_title');
          $this->addFieldMapping("$field_name:attributes", $field_name . '_attributes');
        }
        if ($fi['type'] == 'text_with_summary') {
          $this->addFieldMapping("$field_name:summary", $field_name . '_summary');
          $this->addFieldMapping("$field_name:format", $field_name . '_format');
        }
        if ($fi['type'] == 'text_long') {
          $this->addFieldMapping("$field_name:format", $field_name . '_format');
        }
        if ($fi['type'] == 'datetime') {
          $this->addFieldMapping("$field_name:to", $field_name . '_value2');
          $this->addFieldMapping("$field_name:timezone", $field_name . '_timezone');
        }
        if ($fi['type'] == 'file' || $fi['type'] == 'image') {
          $this->addFieldMapping("$field_name:file_replace")->defaultValue(TRUE);
        }
      }
    }
  }

  /**
   * Implements Migration::prepareRow() to adapt JSON fields data to what migrate expects in the field.
   */
  public function prepareRow($row) {
    try {
      ncw_migration_debug('!klass:      * Preparing source term: !id', array('!klass' => get_class($this), '!id' => $row->tid));
      $row->language = 'en';
      $row->path = !empty($row->path['alias']) ? $row->path['alias']:  NULL;
      // Normalize JSON structure, to match migrate expectations for field data
      $fields = field_info_instances('taxonomy_term', $this->bundle);
      foreach($fields as $field_name => $field_info) {
        if (in_array($field_name, $this->getManuallyMigratedFields())) {
          continue;
        }
        $fi = field_info_field($field_name);
        $normalizer = 'osha_migration_normalize_field_' . $fi['type'];
        if(function_exists($normalizer)) {
          $filter_languages = array();
          if (!$this->allowMigrateTranslation()) {
            $filter_languages = array('en');
          }
          $normalizer($row, $field_name, $fi, $filter_languages);
        }
        else {
          $name = $this->currentMigration()->getMachineName();
          watchdog('ncw_migration', "[BUG][$name] Cannot find normalization '$normalizer', skipping field $field_name", array(), WATCHDOG_ERROR);
          $row->{$field_name} = array();
        }
      }

      // Remove invalid values so we don't get field validation errors (ie. blog)
      if (!empty($row->field_excluded_from) && is_array($row->field_excluded_from)) {
        $whitelist = array(
          'article',
          'page',
          'job_vacancies',
          'news',
          'press_release',
          'publication',
          'infographic'
        );
        foreach($row->field_excluded_from as $k => $v) {
          if (!in_array($v, $whitelist)) {
            unset($row->field_excluded_from[$k]);
          }
        }
      }
    }
    catch(Exception $e) {
      ncw_migration_debug("Exception while preparing the row: {$row->tid}", 'error');
      return FALSE;
    }
    return TRUE;
  }

  /**
   * Implements Migration::complete() to configure translations
   */
  public function complete($entity, stdClass $row) {
    unset($row->translations['data']['en']);
    if (!empty($row->translations['data'])) {
      $handler = entity_translation_get_handler('taxonomy_term', $entity);
      foreach($row->translations['data'] as $language => $data) {
        $handler->setTranslation(array(
          'language' => $data['language'],
          'source' => $data['source'],
          'status' => $data['status'],
          'translate' => $data['translate'],
          'uid' => osha_migration_author_uid(),
        ));
      }
      $handler->saveTranslations();
    }
  }
}


/**
 * Class AbstractNCWTaxonomyTermSource - base for NCW taxonomy migration.
 */
abstract class AbstractNCWTaxonomyTermSource extends AbstractNCWNodeSource {

  public function itemIdentifier($ob) {
    return $ob->tid;
  }

  public function itemURL($id) {
    return ncw_migration_datasource_url() . '/export/taxonomy_term/' . $id;
  }

  public function fields() {
    return array(
             'tid' => 'tid',
             'name' => 'name',
             'name_field_language' => 'name_field:language',
             'name_field' => 'name_field',
             'format' => 'format',
             'weight' => 'weight',
             'description' => 'description',
             'description_field' => 'description_field',
             'description_field_language' => 'description_field:language',
             'description_field_format' => 'description_field:format',
             'description_field_summary' => 'description_field:summary',
             'field_excluded_from' => 'field_excluded_from',
           ) + $this->contentFields();
  }
}


////////////////////////////////// Utilities ///////////////////////////////////
function ncw_migration_datasource_url() {
  $ret = NULL;
  static $errorDisplayed = FALSE;
  $ret = variable_get('hwc_migration_root_url');
  if (empty($ret)) {
    $ret = 'http://osha.localhost';
    if (!$errorDisplayed) {
      $errorDisplayed = TRUE;
      drupal_set_message("Empty 'hwc_migration_root_url' variable. Using default 'http://osha.localhost'", 'warning');
    }
  }
  return $ret;
}



function osha_migration_url_files($suffix = '') {
  return ncw_migration_datasource_url() . '/sites/default/files/' . $suffix;
}

function ncw_migration_file_get_contents($url) {
  $ch = curl_init();
  curl_setopt($ch, CURLOPT_URL, $url);
  curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
  curl_setopt($ch, CURLOPT_CONNECTTIMEOUT, 5);
  curl_setopt($ch, CURLOPT_FOLLOWLOCATION, 1);
  $result = curl_exec($ch);
  curl_close($ch);
  return $result;
}


function osha_migration_author_uid() {
  return 0;
}


////////////////////////////// Normalization functions /////////////////////////
function osha_migration_normalize_field_list_text($row, $field_name, $field_info, $filter_languages) {
  $field = array();
  if (!empty($row->{$field_name}) && is_array($row->{$field_name})) {
    foreach ($row->{$field_name} as $language => $values) {
      if (!empty($filter_languages) && !in_array($language, $filter_languages)) {
        continue;
      }
      foreach($values as $v) {
        $field[] = $v['value'];
      }
    }
  }
  $row->{$field_name} = $field;
}

function osha_migration_normalize_field_number_integer($row, $field_name, $field_info, $filter_languages) {
  osha_migration_normalize_field_list_text($row, $field_name, $field_info, $filter_languages);
}

function osha_migration_normalize_field_number_decimal($row, $field_name, $field_info, $filter_languages) {
  osha_migration_normalize_field_number_integer($row, $field_name, $field_info, $filter_languages);
}

function osha_migration_normalize_field_list_boolean($row, $field_name, $field_info, $filter_languages) {
  osha_migration_normalize_field_number_integer($row, $field_name, $field_info, $filter_languages);
}

function osha_migration_normalize_field_text_long($row, $field_name, $field_info, $filter_languages) {
  $field = array();
  $languages = array();
  $format = array();
  if (!empty($row->{$field_name}) && is_array($row->{$field_name})) {
    foreach ($row->{$field_name} as $language => $values) {
      if (!empty($filter_languages) && !in_array($language, $filter_languages)) {
        continue;
      }
      foreach($values as $v) {
        $field[] = $v['value'];
        $languages[] = $language;
        $format[] = $v['format'];
      }
    }
  }
  $row->{$field_name} = $field;
  $row->{$field_name . '_language'} = $languages;
  $row->{$field_name . '_format'} = $format;
}

function osha_migration_normalize_field_text_with_summary($row, $field_name, $field_info, $filter_languages) {
  osha_migration_normalize_field_text_long($row, $field_name, $field_info, $filter_languages);
}

function osha_migration_normalize_field_link_field($row, $field_name, $field_info, $filter_languages) {
  $field = array(
    'url' => array(),
    'title' => array(),
    'language' => array(),
  );
  if (!empty($row->{$field_name}) && is_array($row->{$field_name})) {
    if ($field_info['translatable'] == 0) {
      $data = array_pop($row->{$field_name});
      foreach ($data as $link) {
        $field['url'][] = $link['url'];
        $field['title'][] = $link['title'];
        $field['attributes'][] = $link['attributes'];
      }
    }
    else {
      foreach ($row->{$field_name} as $lang => $data) {
        foreach ($data as $link) {
          $field['url'][] = $link['url'];
          $field['title'][] = $link['title'];
          $field['attributes'][] = $link['attributes'];
          $field['language'][] = $lang;
        }
      }
    }
  }
  $row->{$field_name} = $field['url'];
  $row->{$field_name . '_title'} = $field['title'];
  $row->{$field_name . '_attributes'} = $field['attributes'];//@todo not tested
  $row->{$field_name . '_language'} = $field['language'];
}

function osha_migration_normalize_field_text($row, $field_name, $field_info, $filter_languages) {
  $field = array();
  $languages = array();
  if (!empty($row->{$field_name}) && is_array($row->{$field_name})) {
    foreach ($row->{$field_name} as $language => $values) {
      if (!empty($filter_languages) && !in_array($language, $filter_languages)) {
        continue;
      }
      foreach($values as $v) {
        $field[] = $v['value'];
        $languages[] = $language;
      }
    }
  }
  $row->{$field_name} = $field;
  $row->{$field_name . '_language'} = $languages;
}

function osha_migration_normalize_field_email($row, $field_name, $field_info, $filter_languages) {
  $field = array();
  $languages = array();
  if (!empty($row->{$field_name}) && is_array($row->{$field_name})) {
    foreach ($row->{$field_name} as $language => $values) {
      if (!empty($filter_languages) && !in_array($language, $filter_languages)) {
        continue;
      }
      foreach($values as $v) {
        $field[] = $v['email'];
        $languages[] = $language;
      }
    }
  }
  $row->{$field_name} = $field;
  $row->{$field_name . '_language'} = $languages;
}

function osha_migration_normalize_field_datetime($row, $field_name, $field_info, $filter_languages) {
  $field = array(
    'value' => NULL,
    'timezone' => NULL,
    'value2' => NULL,
  );
  if (!empty($row->{$field_name}) && is_array($row->{$field_name})) {
    $field = array_pop($row->{$field_name});
    if (!empty($field[0])) {
      $field = $field[0];
    }
  }
  $row->{$field_name} = $field['value'];
  $row->{$field_name . '_value2'} = !empty($field['value2']) ? $field['value2'] : NULL;
  $row->{$field_name . '_timezone'} = !empty($field['timezone']) ? $field['timezone'] : NULL;
}

function osha_migration_normalize_field_taxonomy_term_reference($row, $field_name, $field_info, $filter_languages) {
  $field = array();
  if (isset($row->{$field_name}['name_original'])) { // cardinality 1
    $field[] = $row->{$field_name}['name_original'];
  }
  else if (!empty($row->{$field_name}) && is_array($row->{$field_name})) {
    foreach ($row->{$field_name} as $value) {
      if (isset($value['name_original'])) {
        $field[] = $value['name_original'];
      }
    }
  }
  else if (empty($row->{$field_name})) {
    // Do nothing ...
  }
  else {
    watchdog('ncw_migration', '[normalize_field_taxonomy_term_reference] Failed to extract value from !field', array('!field' => $field_name), WATCHDOG_WARNING);
  }
  $row->{$field_name} = $field;
}

function osha_migration_normalize_field_entityreference($row, $field_name, $field_info) {
  $field = array();
  //@todo cardinality -1 (multiple) not implemented
  if (!empty($row->{$field_name}) && is_array($row->{$field_name})) {
    foreach ($row->{$field_name} as $value) {
      foreach($value as $arr) {
        if (isset($arr['target_id'])) {
          $field[] = $arr['target_id'];
        }
      }
    }
  }
  else if (empty($row->{$field_name})) {
    // Do nothing ...
  }
  else {
    watchdog('ncw_migration', '[osha_migration_normalize_field_entityreference] Failed to extract value from !field', array('!field' => $field_name), WATCHDOG_WARNING);
  }
  $row->{$field_name} = $field;
}

function osha_migration_normalize_field_file($row, $field_name, $field_info, $filter_languages) {
  $field = array();
  $languages = array();
  if (!empty($row->{$field_name}) && is_array($row->{$field_name})) {
    foreach ($row->{$field_name} as $language => $values) {
      if (!empty($filter_languages) && !in_array($language, $filter_languages)) {
        continue;
      }
      foreach($values as $f) {
        $field[] = osha_migration_url_files(str_replace('public://', '', $f['uri']));
        $languages[] = $language;
      }
    }
  }
  $row->{$field_name} = $field;
  $row->{$field_name . '_language'} = $languages;
}

function osha_migration_normalize_field_image($row, $field_name, $field_info, $filter_languages) {
  osha_migration_normalize_field_file($row, $field_name, $field_info, $filter_languages);
}

/**
 * Not used automatically by normalizing
 */
function osha_migration_normalize_migrated_term_reference(&$original, $source_migration_name) {
  if (empty($original)) {
    return array();
  }
  $ret = array();
  if ($migration = Migration::getInstance($source_migration_name)) {
    foreach ($original as $term) {
      $tid = NULL;
      if(is_numeric($term)) {
        $tid = $term;
        if ($tid && $dest = $migration->getMap()->getRowBySource(array($tid))) {
          $ret = $dest['destid1'];
        }
      }
      else if (!empty($term['tid'])) {
        $tid = $term['tid'];
        if ($tid && $dest = $migration->getMap()->getRowBySource(array($tid))) {
          $ret[] = $dest['destid1'];
        }
      }
    }
  }
  return $ret;
}


function ncw_migration_find_additional_resource($source_nid) {
  $migrations = array(
    'publications_add_res', 'news_add_res',
    'press_releases_add_res', 'highlights_add_res'
  );
  foreach($migrations as $machine_name) {
    $migration = Migration::getInstance($machine_name);
    /** @var MigrateMap $map */
    $map = $migration->getMap();
    if ($destid1 = $map->lookupDestinationID(array($source_nid))) {
      // @todo add some debugging here
      ncw_migration_debug(
        'Linking additional resource from !machine (src=!src:dest=!dest',
          array('!machine' => $machine_name, '!src' => $source_nid, '!dest' => $destid1['destid1'])
      );
      return $destid1['destid1'];
    }
  }
  return NULL;
}

function ncw_migration_find_migrated_item_id($source_nid, $migration_name) {
  $migration = Migration::getInstance($migration_name);
  /** @var MigrateMap $map */
  $map = $migration->getMap();
  if ($destid1 = $map->lookupDestinationID(array($source_nid))) {
    ncw_migration_debug(
        'Linking additional resource from !machine (src=!src:dest=!dest',
        array('!machine' => $migration_name, '!src' => $source_nid, '!dest' => $destid1['destid1'])
    );
    return $destid1['destid1'];
  }
  return NULL;
}