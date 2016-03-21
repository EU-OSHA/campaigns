<?php

class NCWTaxonomyCountryMigration extends AbstractNCWTaxonomyTermMigration {

  public function __construct($arguments) {
    parent::__construct($arguments, 'CountryNCWTaxonomyTermSource', 'country');
    $this->description = 'Import taxonomy "country" from NCW';
  }
}

class NCWTaxonomyCountryStatusMigration extends AbstractNCWTaxonomyTermMigration {

  public function __construct($arguments) {
    parent::__construct($arguments, 'SimpleNCWTaxonomyTermSource', 'country_status');
    $this->description = 'Import taxonomy "country_status" from NCW';
  }
}

class NCWTaxonomyFOPLinkSectionsMigration extends AbstractNCWTaxonomyTermMigration {

  public function __construct($arguments) {
    parent::__construct($arguments, 'SimpleNCWTaxonomyTermSource', 'fop_link_sections');
    $this->description = 'Import taxonomy "fop_link_sections" from NCW';
  }
}

class NCWTaxonomyNewsletterSectionsMigration extends AbstractNCWTaxonomyTermMigration {

  public function __construct($arguments) {
    parent::__construct($arguments, 'SimpleNCWTaxonomyTermSource', 'newsletter_sections');
    $this->description = 'Import taxonomy "newsletter_sections" from NCW';
  }
}

class NCWTaxonomyPublicationTypeMigration extends AbstractNCWTaxonomyTermMigration {

  public function __construct($arguments) {
    parent::__construct($arguments, 'PublicationTypeNCWTaxonomyTermSource', 'publication_types');
    $this->description = 'Import taxonomy "publication_types" from NCW';
  }
}

class NCWTaxonomySegmentationMigration extends AbstractNCWTaxonomyTermMigration {

  public function __construct($arguments) {
    parent::__construct($arguments, 'SegmentationNCWTaxonomyTermSource', 'segment');
    $this->description = 'Import taxonomy "relevant_for" from NCW';
  }
}

class NCWTaxonomyTagsMigration extends AbstractNCWTaxonomyTermMigration {

  public function __construct($arguments) {
    parent::__construct($arguments, 'TagsNCWTaxonomyTermSource', 'tags');
    $this->description = 'Import taxonomy "tags" from NCW';
  }
}


class SimpleNCWTaxonomyTermSource extends AbstractNCWTaxonomyTermSource {

  public function contentFields() {
    return array();
  }
}

class TagsNCWTaxonomyTermSource extends AbstractNCWTaxonomyTermSource {

  public function contentFields() {
    return array(
      'field_tags_code' => 'field_tags_code',
    );
  }
}

class SegmentationNCWTaxonomyTermSource extends AbstractNCWTaxonomyTermSource {

  public function contentFields() {
    return array();
  }
}

class PublicationTypeNCWTaxonomyTermSource extends AbstractNCWTaxonomyTermSource {

  public function prepareRow($row) {
    // Don't migrate some types
    // Magazine, Annual reports and other corporate publications, Promotional Material
    // Evaluation reports, Corporate strategies and annual management plans
    $ignore_tids = array(4, 2, 3, 1, 3022);
    if (in_array($row->tid, $ignore_tids)) {
      return FALSE;
    }
    parent::prepareRow($row);
  }
  public function contentFields() {
    return array(
      'field_publication_type_code' => 'field_publication_type_code',
    );
  }
}

class CountryNCWTaxonomyTermSource extends AbstractNCWTaxonomyTermSource {

  public function contentFields() {
    return array(
      'field_iso2' => 'field_iso2',
      'field_flag' => 'field_flag',
      'field_country_status' => 'field_country_status',
    );
  }
}
