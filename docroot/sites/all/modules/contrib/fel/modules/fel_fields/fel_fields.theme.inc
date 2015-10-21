<?php

/**
 * @file
 * Theme replacement functions for Form element layout fields.
 */

/**
 * Theme replacement for 'date_combo'.
 *
 * @see http://drupalcontrib.org/api/drupal/contributions!date!date.theme/function/theme_date_combo/7
 */
function theme_fel_date_combo($variables) {
  $element = $variables['element'];

  // Group start/end items together in fieldset.
  $fieldset = array(
    '#title' => field_filter_xss(t($element['#title'])) . ' ' . ($element['#delta'] > 0 ? intval($element['#delta'] + 1) : ''),
    '#value' => '',
    '#attributes' => array(),
    '#children' => $element['#children'],
  );
  if (!empty($element['#fieldset_description'])) {
    $fieldset['#description'] = $element['#fieldset_description'];
    if (!empty($element['#description_display'])) {
      $fieldset['#description_display'] = $element['#description_display'];
    }
    if (!empty($element['#description_classes'])) {
      $fieldset['#description_classes'] = $element['#description_classes'];
    }
  }
  if (!empty($element['#title_classes'])) {
    $fieldset['#title_classes'] = $element['#title_classes'];
  }
  // Add marker to required date fields.
  if ($element['#required']) {
    $fieldset['#title'] .= " " . theme('form_required_marker');
  }
  return theme('fel_fieldset', array('element' => $fieldset));
}

/**
 * Theme replacement for 'field_collection_table_multiple_value_fields'.
 *
 * Which again is an override for field_multiple_value_form.
 *
 * @see theme_field_collection_table_multiple_value_fields()
 */
function theme_fel_fields_collection_table($variables) {
  $element = $variables['element'];
  $output = '';

  if (isset($element['#cardinality']) && ($element['#cardinality'] > 1 || $element['#cardinality'] == FIELD_CARDINALITY_UNLIMITED)) {
    $table_id = drupal_html_id($element['#field_name'] . '_values');
    $order_class = $element['#field_name'] . '-delta-order';
    $required = !empty($element['#required']) ? '<span class="form-required" title="' . t('This field is required.') . '">*</span>' : '';

    $rows = array();

    // Sort items according to '_weight' (needed when the form comes back after
    // preview or failed validation).
    $items = array();
    foreach (element_children($element) as $key) {
      if (!isset($element[$key]['#entity_type'])) {
        if ($key === 'add_more') {
          $add_more_button = &$element[$key];
        }
      }
      else {
        $items[] = &$element[$key];
      }
    }
    usort($items, '_field_sort_items_value_helper');

    $label_classes = !empty($element['#title_classes']) ? (' class="' . implode(' ', $element['#title_classes']) . '"') : '';
    $header = array(
      array(
        'data' => '<label' . $label_classes . '>' . t('!title: !required', array('!title' => $element['#title'], '!required' => $required)) . "</label>",
        'class' => array('field-label'),
      ),
    );

    // Add the items as table rows.
    foreach ($items as $key => $item) {
      uasort($item, 'element_sort');
      $item['_weight']['#attributes']['class'] = array($order_class);
      $cells = array(
        array('data' => '', 'class' => array('field-multiple-drag')),
      );
      foreach (element_children($item) as $field_name) {
        // Only add the header once.
        if ($key == 0) {
          $header[] = array(
            'data' => '<label>' . t('!title', array('!title' => _field_collection_table_get_title($item[$field_name]))) . '</label>',
            'class' => array('field-label'),
          );
        }
        $cells[] = array('data' => $item[$field_name]);
      }
      $rows[] = array(
        'data' => $cells,
        'class' => array('draggable'),
      );
    }

    $output = array(
      '#prefix' => '<div class="form-item">',
      '#suffix' => '</div>',
    );
    if (!empty($element['#description']) and !empty($element['#description_display']) and $element['#description_display'] == 'before') {
      $output[] = array(
        '#markup' => theme('fel_form_element_description', $variables),
      );
    }
    $output['field_collection_table'] = array(
      '#theme' => 'table',
      '#header' => $header,
      '#rows' => $rows,
      '#attributes' => array(
        'id' => $table_id,
        'class' => array(
          'field-multiple-table',
        ),
      ),
    );
    if (!empty($element['#description']) and (empty($element['#description_display']) or $element['#description_display'] == 'after')) {
      $output[] = array(
        '#markup' => theme('fel_form_element_description', $variables),
      );
    }
    if (isset($add_more_button)) {
      $output[] = $add_more_button + array(
        '#prefix' => '<div class="clearfix">',
        '#suffix' => '</div>',
      );
    }

    $output = drupal_render($output);

    drupal_add_tabledrag($table_id, 'order', 'sibling', $order_class);
  }
  else {
    foreach (element_children($element) as $key) {
      $output .= drupal_render($element[$key]);
    }
  }

  return $output;
}

/**
 * Theme replacement for 'matrix_table'.
 *
 * @see theme_matrix_table()
 */
function theme_fel_fields_matrix_table($variables) {
  $form = $variables['form'];
  $rows_count = $form['#matrix_rows'];
  $cols_count = $form['#matrix_cols'];
  $more_cols = $form['#matrix_more_cols'];
  $more_rows = $form['#matrix_more_rows'];
  $column_labels = $form['#column_labels'];
  $row_labels = $form['#row_labels'];
  $field_name = $form['#field_name'];

  $table_rows = array();
  for ($row = 1; $row <= $rows_count; $row++) {
    for ($col = 1; $col <= $cols_count; $col++) {
      $table_rows[$row - 1][$col - 1] = drupal_render($form['grid'][$row . '-' . $col]);
    }
  }

  if (!empty($row_labels)) {
    array_unshift($column_labels, '');
    foreach ($row_labels as $id => $label) {
      array_unshift($table_rows[$id - 1], $label);
    }
  }

  if ($more_rows) {
    $table_rows[$rows_count][1] = drupal_render($form['more_rows']);
    for ($col = 2; $col <= $cols_count; $col++) {
      $table_rows[$rows_count][$col] = '&nbsp;';
    }
  }

  if ($more_cols) {
    $column_labels[] = drupal_render($form['more_cols']);
    for ($row = 1; $row <= $rows_count; $row++) {
      $table_rows[$row - 1][$cols_count + 1] = '&nbsp;';
    }
  }

  $parts = array(
    'title' => theme('fel_form_element_label', (array('element' => $form))),
    'children' => theme('table', array('header' => $column_labels, 'rows' => $table_rows)),
  );
  if (!empty($form['#description'])) {
    $form['#description'] = filter_xss_admin($form['#description']);
    $parts['description'] = theme('fel_form_element_description', array('element' => $form));
  }
  $output  = '<div id="matrix-field-' . $field_name . '">';
  $output .= fel_order_output($form, $parts);
  $output .= '</div>';
  return $output;
}
