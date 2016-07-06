<?php

/**
 * @file
 * This template is used to print a single field in a view.
 *
 * It is not actually used in default Views, as this is registered as a theme
 * function which has better performance. For single overrides, the template is
 * perfectly okay.
 *
 * Variables available:
 * - $view: The view object
 * - $field: The field handler object that can process the input
 * - $row: The raw SQL result that can be used
 * - $output: The processed output that will normally be used.
 *
 * When fetching output from the $row, this construct should be used:
 * $data = $row->{$field->field_alias}
 *
 * The above will guarantee that you'll always get the correct data,
 * regardless of any changes in the aliasing that might happen if
 * the view is modified.
 */

if (empty($output)) {
  if (is_int($row->entity)) {
    $entity = node_load($row->entity);
  }
  else if (!empty($row->entity->nid)) {
    $entity = node_load($row->entity);
  }
  if (!empty($entity) && !empty($entity->body)) {
    $wrapper = entity_metadata_wrapper('node', $entity);
    $body = $wrapper->body->value()['value'];
    $display = array(
      'label' => 'hidden',
      'module' => 'smart_trim',
      'settings' => array(
        'more_link' => 1,
        'more_text' => 'See more',
        'trim_length' => 300,
        'trim_options' => array('text' => 'text'),
        'trim_type' => 'chars',
        'trim_link' => 0,
      ),
      'type' => 'smart_trim_format',
    );
    $out = field_view_field('node', $entity, 'body', $display);
    $output = drupal_render($out);
  }
}
?>
<?php print $output; ?>