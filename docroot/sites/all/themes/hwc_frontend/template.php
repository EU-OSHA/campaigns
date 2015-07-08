<?php


/**
 * Render footer menu as nav-pills.
 */
function bootstrap_menu_tree__menu_footer_menu(&$variables) {
  return '<ul class="menu nav nav-pills">' . $variables['tree'] . '</ul>';
}

/**
 * Implements theme_menu_link__menu_block().
 */
function hwc_frontend_menu_link__menu_block($variables) {
  $element = &$variables['element'];
  $delta = $element['#bid']['delta'];

  // Add homepage Icon.
  /*$attr = drupal_attributes($element['#attributes']);
  if (isset($variables['element']['#href']) &&
    $variables['element']['#href'] == '<front>' &&
    isset($element['#localized_options']['content']['image'])
  ) {
    $path = file_create_url($element['#localized_options']['content']['image']);
    $link = l('<img src="' . $path . '" />', $element['#href'],
      array('html' => TRUE, 'attributes' => $element['#localized_options']['attributes'])
    );
    return sprintf("\n<li %s>%s</li>", $attr, $link);
  }*/

  // Render or not the Menu Image.
  // Get the variable provided by osha_menu module.
  $render_img = variable_get('menu_block_' . $delta . '_' . HWC_MENU_RENDER_IMG_VAR_NAME, 0);
  if (!$render_img) {
    return theme_menu_link($variables);
  }
  // $element['#attributes']['data-image-url'] = $image_url;
  $output_link = l($element['#title'], $element['#href'], $element['#localized_options']);

  $output_image = "";
  if (!empty($element['#localized_options']['content']['image'])
    && $image_url = file_create_url($element['#localized_options']['content']['image'])) {
    $image = '<img src="' . $image_url . '"/>';
    $output_image = l($image, $element['#href'], array('html' => TRUE));
  }

  return '<li' . drupal_attributes($element['#attributes']) . '>
    <div class="introduction-title">' . $output_link . '</div>
    <div class="introduction-image">' . $output_image . '</div>
    </li>';
}

/**
 * Overrides theme_menu_link().
 */
function hwc_frontend_menu_link(array $variables) {
  $element = $variables['element'];
  $sub_menu = '';

  if ($element['#below']) {
    // Prevent dropdown functions from being added to management menu so it
    // does not affect the navbar module.
    if (($element['#original_link']['menu_name'] == 'management') && (module_exists('navbar'))) {
      $sub_menu = drupal_render($element['#below']);
    }
    elseif ((!empty($element['#original_link']['depth'])) && ($element['#original_link']['depth'] == 1)) {
      // Add our own wrapper.
      unset($element['#below']['#theme_wrappers']);
      $sub_menu = '<ul class="dropdown-menu">' . drupal_render($element['#below']) . '</ul>';
      // Generate as standard dropdown.
      $element['#title'] .= ' <span class="caret"></span>';
      $element['#attributes']['class'][] = 'dropdown';
      $element['#localized_options']['html'] = TRUE;

      // Set dropdown trigger element to # to prevent inadvertant page loading
      // when a submenu link is clicked.
//      $element['#localized_options']['attributes']['data-target'] = '#';
      $element['#localized_options']['attributes']['class'][] = 'dropdown-toggle';
//      $element['#localized_options']['attributes']['data-toggle'] = 'dropdown';
    }
  }
  // On primary navigation menu, class 'active' is not set on active menu item.
  // @see https://drupal.org/node/1896674
  if (($element['#href'] == $_GET['q'] || ($element['#href'] == '<front>' && drupal_is_front_page())) && (empty($element['#localized_options']['language']))) {
    $element['#attributes']['class'][] = 'active';
  }

  // Add image to menu item
//  if (isset($variables['element']['#href']) && isset($element['#localized_options']['content']['image'])) {
//    $path = file_create_url($element['#localized_options']['content']['image']);
//    $link = l('<img src="' . $path . '" />', $element['#href'],
//      array('html' => TRUE, 'attributes' => $element['#localized_options']['attributes'])
//    );
//    return '<li' . drupal_attributes($element['#attributes']) . '>' . $link . "</li>\n";
//  }

  $output = l($element['#title'], $element['#href'], $element['#localized_options']);
  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
}

function hwc_frontend_preprocess_page(&$vars) {
    if (drupal_is_front_page()) {
        unset($vars['page']['content']['system_main']['default_message']);
        drupal_set_title('');
    }

    // add back to links (e.g. Back to news)
    if (isset($vars['node'])) {
      $node = $vars['node'];
      switch ($node->type) {
        case 'news':
          $link_title = t('Back to news');
          $link_href = 'news';
          break;
        case 'publication':
          $link_title = t('Back to publications list');
          $link_href = 'publications';
          $vars['page']['above_title']['title-alternative'] = array(
            '#type' => 'item',
            '#markup' => t('Publications'),
            '#prefix' => '<strong class="title-alt">', '#suffix' => '</strong>'
          );
          break;
        case 'infographic':
          $link_title = t('Back to infographics list');
          $link_href = 'infographics';
          $vars['page']['above_title']['title-alternative'] = array(
            '#type' => 'item',
            '#markup' => t('Infographics'),
            '#prefix' => '<strong class="title-alt">', '#suffix' => '</strong>'
          );
          break;
      }
      if (isset($link_title)) {
        $vars['page']['above_title']['back-to-link'] = array(
            '#type' => 'item',
            '#markup' => l($link_title, $link_href, array('attributes' => array('class' => array('back-to-link pull-right')))),
        );
      }
    }
  if ($node = menu_get_object()) {
    if ($node->type == 'publication') {
      ctools_include('plugins');
      ctools_include('context');
      $pb = path_breadcrumbs_load_by_name('publications_detail_page');
      $breadcrumbs = _path_breadcrumbs_build_breadcrumbs($pb);
      drupal_set_breadcrumb($breadcrumbs);
    }
  }
}

/**
 * Implements theme_on_the_web_image().
 *
 * @param $variables
 *   An associative array with generated variables.
 *
 * @return
 *   HTML for a social media icon.
 */
function hwc_frontend_on_the_web_image($variables) {
  $service = $variables['service'];
  $title   = $variables['title'];
  $size    = variable_get('on_the_web_size', 'sm');
  $variables = array(
    'alt'   => $title,
    'path'  => drupal_get_path('theme', 'hwc_frontend') . '/images/social_icons/' . $size . '/' . $service . '.png',
    'title' => $title
  );
  return theme('image', $variables);
}