<?php

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'single' => TRUE,
  'title' => t('Summary & resources label'),
  'description' => t('Add the label Summary & resources only if the node has a field.'),
  'category' => t('Miscellaneous'),
  'render callback' => 'osha_publication_summary_label_render',
);

function osha_publication_summary_label_render($subtype, $conf, $args, $contexts) {
  $node = menu_get_object();
  if (!empty($node) && (!empty($node->field_related_publications) || !empty($node->field_publication_related_res))) {
    $block = new stdClass();
    // initial content is blank
    $block->title = NULL; // This will be overridden by the user within the panel options.
    $variables = array('element' => array('#tag' => 'h3', '#value' => t('Summary & resources'), '#attributes' => array('class' => 'summary_and_resources_field_label')));
    $block->content = theme('html_tag', $variables);
    return $block;
  }
}
