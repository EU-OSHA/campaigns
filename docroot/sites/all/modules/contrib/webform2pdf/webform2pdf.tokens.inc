<?php

/**
 * @file
 * Builds placeholder replacement tokens for webform-related data.
 */

/**
 * Implements hook_token_info_alter().
 */
function webform2pdf_token_info_alter(&$info) {
  $help = t('Replace the "?" with the "option field key", including any parent field keys separated by colons. You may append ":label" for just the label or ":withlabel" for both the label and value together.');

  $info['tokens']['submission']['nl'] = array(
    'name' => t('Webform submission options write new line'),
    'description' => t('Modifier outputs all of the selected options: one below the other.') . ' ' . $help,
    'dynamic' => TRUE,
  );
  $info['tokens']['submission']['all'] = array(
    'name' => t('Webform submission all options'),
    'description' => t('Lists every option, and highlights which were selected from them.') . ' ' . $help,
    'dynamic' => TRUE,
  );
  $info['tokens']['submission']['all-nl'] = array(
    'name' => t('Webform submission all options new line'),
    'description' => t('Lists all of the options in separate lines, and highlights selected ones.') . ' ' . $help,
    'dynamic' => TRUE,
  );

  return $info;
}

/**
 * Implements hook_tokens().
 */
function webform2pdf_tokens($type, $tokens, array $values = array(), array $options = array()) {
  $replacements = array();
  $sanitize = !empty($options['sanitize']);

  // Webform tokens (caching globally).
  if ($type == 'submission' && !empty($values['webform-submission'])) {
    // Prepare all the submission data that we will likely need more than once.
    $submission = $values['webform-submission'];
    $node = isset($values['node']) ? $values['node'] : node_load($submission->nid);
    $format = $sanitize ? 'html' : 'text';

    $option_components = array();
    foreach ($node->webform['components'] as $cid => $component) {
      if ('select' == $component['type']) {
        $option_components[$component['form_key']] = $cid;
      }
    }

    if ($nl_value_tokens = token_find_with_prefix($tokens, 'nl')) {
      foreach ($nl_value_tokens as $name => $original) {
        $parent_token = explode(':', $name);
        if (isset($option_components[$parent_token[0]]) && count($parent_token) <= 2) {

          $cid = $option_components[$parent_token[0]];
          if (isset($submission->data[$cid])) {
            $select_values = array_filter($submission->data[$cid]);
            if (!empty($select_values)) {
              $label_format = isset($parent_token[1]) ? $parent_token[1] : 'withlabel';
              $label = '';
              if ('label' == $label_format || 'withlabel' == $label_format) {
                $label = _webform_filter_xss($node->webform['components'][$cid]['name']);
              }

              $values_output = '';
              if ('nolabel' == $label_format || 'withlabel' == $label_format) {
                module_load_include('inc', 'webform', 'components/select');
                $items = _webform_select_options_from_text($node->webform['components'][$cid]['extra']['items']);

                $nl = array();
                foreach ($select_values as $key) {
                  if ('html' == $format) {
                    $nl[] = ' - ' . (isset($items[$key]) ? $items[$key] : $key) . "<br />\n";
                  }
                  else {
                    $nl[] = ' - ' . (isset($items[$key]) ? $items[$key] : $key) . "\n";
                  }
                }

                $values_output = implode('', $nl);
              }
              if ('html' == $format) {
                $replacements[$original] = $label . ((!empty($label) && !empty($values_output) ? ": <br />\n" : '')) . $values_output;
              }
              else {
                $replacements[$original] = $label . ((!empty($label) && !empty($values_output) ? ": \n" : '')) . $values_output;
              }
            }
          }
        }
      }
    }

    if ($all_value_tokens = token_find_with_prefix($tokens, 'all')) {
      foreach ($all_value_tokens as $name => $original) {
        $parent_token = explode(':', $name);
        if (isset($option_components[$parent_token[0]]) && count($parent_token) <= 2) {

          $cid = $option_components[$parent_token[0]];
          if (isset($submission->data[$cid])) {
            $select_values = array_filter($submission->data[$cid]);
            if (!empty($select_values)) {
              $label_format = isset($parent_token[1]) ? $parent_token[1] : 'withlabel';
              $label = '';
              if ('label' == $label_format|| 'withlabel' == $label_format) {
                $label = _webform_filter_xss($node->webform['components'][$cid]['name']);
              }

              $values_output = '';
              if ('nolabel' == $label_format|| 'withlabel' == $label_format) {
                module_load_include('inc', 'webform', 'components/select');
                $items = _webform_select_options_from_text($node->webform['components'][$cid]['extra']['items']);

                $all = array();
                foreach ($items as $key => $item) {
                  if ('html' == $format) {
                    $all[] = in_array($key, $select_values) ? '<u><b><span class="selected">' . $items[$key] . '</span></b></u>' : $items[$key];
                  }
                  else {
                    $all[] = in_array($key, $select_values) ? '[X] ' . $items[$key] : '[ ]' . $items[$key];
                  }
                }

                if (module_exists('select_or_other')) {
                  $potential_values = array_merge(array_keys($items), array_values($items));
                  $diff = array_diff($select_values, $potential_values);
                  if (!empty($diff)) {
                    foreach ($diff as $value) {
                      if ( !empty($value) ) {
                        if ('html' == $format) {
                          $all[] = '<u><b><span class="selected">' . check_plain($value) . '</span></b></u>';
                        }
                        else {
                          $all[] = '[X] ' . check_plain($value);
                        }
                      }
                    }
                  }
                }

                $values_output = implode(', ', $all);
              }
              $replacements[$original] = $label . ((!empty($label) && !empty($values_output) ? ': ' : '')) . $values_output;
            }
          }
        }
      }
    }

    if ($allnl_value_tokens = token_find_with_prefix($tokens, 'all-nl')) {
      foreach ($allnl_value_tokens as $name => $original) {
        $parent_token = explode(':', $name);
        if (isset($option_components[$parent_token[0]]) && count($parent_token) <= 2) {

          $cid = $option_components[$parent_token[0]];
          if (isset($submission->data[$cid])) {
            $select_values = array_filter($submission->data[$cid]);
            if (!empty($select_values)) {
              $label_format = isset($parent_token[1]) ? $parent_token[1] : 'withlabel';
              $label = '';
              if ('label' == $label_format || 'withlabel' == $label_format) {
                $label = _webform_filter_xss($node->webform['components'][$cid]['name']);
              }

              $values_output = '';
              if ('nolabel' == $label_format || 'withlabel' == $label_format) {
                module_load_include('inc', 'webform', 'components/select');
                $items = _webform_select_options_from_text($node->webform['components'][$cid]['extra']['items']);

                $allnl = array();
                foreach ($items as $key => $item) {
                  if ('html' == $format) {
                    $allnl[] = in_array($key, $select_values) ? ' [X] ' . $items[$key] . "<br />\n" : ' [  ] ' . $items[$key]  . "<br />\n";
                  }
                  else {
                    $allnl[] = in_array($key, $select_values) ? ' [X] ' . $items[$key] . "\n" : ' [  ] ' . $items[$key]  . "\n";
                  }
                }

                if (module_exists('select_or_other')) {
                  $potential_values = array_merge(array_keys($items), array_values($items));
                  $diff = array_diff($select_values, $potential_values);
                  if (!empty($diff)) {
                    foreach ($diff as $value) {
                      if ( !empty($value) ) {
                        if ('html' == $format) {
                          $allnl[] = ' [X] ' . check_plain($value) . "<br />\n";
                        }
                        else {
                          $allnl[] = ' [X] ' . check_plain($value) . "\n";
                        }
                      }
                    }
                  }
                }

                $values_output = implode('', $allnl);
              }
              if ('html' == $format) {
                $replacements[$original] = $label . ((!empty($label) && !empty($values_output) ? ": <br />\n" : '')) . $values_output;
              }
              else {
                $replacements[$original] = $label . ((!empty($label) && !empty($values_output) ? ": \n" : '')) . $values_output;
              }
            }
          }
        }
      }
    }
  }

  return $replacements;
}
