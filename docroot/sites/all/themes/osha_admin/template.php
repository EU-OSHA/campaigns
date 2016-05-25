<?php
/**
 * @file template.php
 */


/**
 * Implements hook_preprocess_HOOK() for theme_file_icon().
 *
 * Change the icon directory to use icons from this theme.
 */
function osha_admin_preprocess_file_icon(&$variables) {
  $variables['icon_directory'] = drupal_get_path('theme', 'osha_frontend') . '/images/file_icons';
}

function osha_admin_preprocess_views_view(&$vars) {
  $view = &$vars['view'];
  // Make sure it's the correct view
  if ($view->name == 'events') {
    // add needed javascript
    drupal_add_js(drupal_get_path('theme', 'osha_admin') . '/../osha_frontend/js/color_events_backend.js');
  }
}

function osha_admin_entity_collection_content_form(&$variables) {
  $is_newsletter = FALSE;
  $form = &$variables['form'];
  $rows = array();
  $output = '';
  if (isset($form['content'])) {
    if ($form['#style']->entity_collection->bundle == 'newsletter_content_collection') {
      $is_newsletter = TRUE;
    }
    foreach (element_children($form['content']) as $key) {
      $form['content'][$key]['parent']['#attributes']['class'] = array('entity_collection-parent');
      $form['content'][$key]['key']['#attributes']['class'] = array('key');
      $form['content'][$key]['depth']['#attributes']['class'] = array('depth');
      $form['content'][$key]['position']['#attributes']['class'] = array('position');
      $title = drupal_render($form['content'][$key]['title']);
      $operations = drupal_render($form['content'][$key]['operations']);
      $position = drupal_render($form['content'][$key]['position']);
      $style = drupal_render($form['content'][$key]['style']);
      $rendered_key = drupal_render($form['content'][$key]['key']);
      $parent = drupal_render($form['content'][$key]['parent']);
      $depth = drupal_render($form['content'][$key]['depth']);
      $indentation = $form['content'][$key]['depth']['#default_value'] > 0 ? theme('indentation', array('size' => $form['content'][$key]['depth']['#default_value'])) : '';
      $data = array($indentation . $title . $parent . $depth . $rendered_key, $position);
      if ($is_newsletter) {
        $data[] = drupal_render($form['content'][$key]['start_date']);
      }
      if ($form['#row']->useStylePerRow()) {
        $data[] = $style;
      }
      $data[] = $operations;
      $rows[] = array('class' => array('draggable'), 'data' => $data);
    }
    $header = array(t('Title'), t('Position'));
    if ($is_newsletter) {
      $header[] = '';
    }
    if ($form['#row']->useStylePerRow()) {
      $header[] = t('Style');
    }
    $header[] = t('Operations');
    $output = theme('table', array(
      'header' => $header,
      'rows' => $rows,
      'attributes' => array('id' => 'entity_collection-table'),
    ));
    if ($form['#style']->getMaxDepth()) {

      drupal_add_tabledrag('entity_collection-table', 'match', 'parent', 'entity_collection-parent', 'entity_collection-parent', 'key', FALSE, $form['#style']->getMaxDepth());
      drupal_add_tabledrag('entity_collection-table', 'depth', 'group', 'depth', NULL, NULL, FALSE, $form['#style']->getMaxDepth());
    }
    drupal_add_tabledrag('entity_collection-table', 'order', 'sibling', 'position');
  }
  return $output . drupal_render_children($variables['form']);
}
