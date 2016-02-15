<?php
/**
 * @file node--publication--pub--teaser.tpl.php
 * Default template implementation to display the value of a publication listing field.
 *
 * Available variables:
 * - $variables['content']: An array of field values. Use render() to output them.
 * - $variables['node']: Actual publication node
 *
 * @ingroup themeable
 */

$items = array();
$file_items = '';
$publ_type = taxonomy_term_load($node->field_publication_type[LANGUAGE_NONE][0]['tid'])->name;
if (!empty($node->field_file)) {
  foreach($node->field_file as $lang => $files) {
    foreach($files as $f) {
      $ext = strtoupper(pathinfo($f['uri'], PATHINFO_EXTENSION));
      $file_uri = file_create_url($f['uri']);
      $lang;
      $items[] = '<a href="' . $file_uri . '">' . strtoupper($lang) . '</a><span class="glyphicon glyphicon-circle-arrow-down"></span>';
    }
  }
  $file_items = theme('item_list', array('items' => $items));
}
?>
<div class="publication-item publication-teaser">
<?php
/** @var array $variables */
$content = $variables['content'];
$node = $variables['node'];
global $language;
print render($content['field_publication_date']);
foreach($content as $field_name => $field) {
  if (!in_array($field_name, array('field_file', 'field_publication_date'))) {
    print render($field);
  }
}
?>
<div class="field field-files">
  <?php if (!empty($file_items)) { ?>
    <span class="publication-ext-type"><?php print $ext . ' ' . $publ_type; ?></span>
    <span class="publication-download-label"><?php print t('Download in'); ?></span>
    <?php print $file_items; ?>
  <?php } ?>
</div>
</div>
