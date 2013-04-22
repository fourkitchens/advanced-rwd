<?php
/**
 * @file
 * Theme functions for the Blockify module.
 */

/**
 * Returns the rendered logo.
 *
 * @ingroup themeable
 */
function theme_blockify_logo($variables) {
  $site_name = filter_xss_admin(variable_get('site_name', 'Drupal'));

  // Strip the base_path from the beginning of the logo path.
  $path = preg_replace('|^' . base_path() . '|', '', $variables['logo_path']);

  $image = array(
    '#theme' => 'image',
    '#path' => $path,
    '#alt' => t('!site_name logo', array(
      '!site_name' => $site_name,
    ))
  );

  return l(render($image), '<front>', array(
    'html' => TRUE,
    'attributes' => array(
      'id' => 'logo',
      'rel' => 'home',
      'title' => t('Return to the !site_name home page', array(
        '!site_name' => $site_name,
      )),
    ),
  ));
}

/**
 * Returns the rendered site name.
 *
 * @ingroup themeable
 */
function theme_blockify_site_name($variables) {
  $title = drupal_get_title();
  $site_name = $variables['site_name'];

  // If there is no page title set for this page, use an h1 for the site name.
  $tag = ($title !== '') ? 'span' : 'h1';

  $link = array(
    '#theme' => 'link',
    '#path' => '<front>',
    '#text' => '<span>' . $site_name . '</span>',
    '#prefix' => '<' . $tag . ' id="site-name">',
    '#suffix' => '</' . $tag . '>',
    '#options' => array(
      'attributes' => array(
        'title' => t('Return to the !site_name home page', array(
          '!site_name' => $site_name,
        )),
        'rel' => 'home',
      ),
      'html' => TRUE,
    ),
  );

  return render($link);
}

/**
 * Returns the rendered site slogan.
 *
 * @ingroup themeable
 */
function theme_blockify_site_slogan($variables) {
  return '<span class="site-slogan">' . $variables['site_slogan'] . '</span>';
}

/**
 * Returns the rendered page title.
 *
 * @ingroup themeable
 */
function theme_blockify_page_title($variables) {
  if ($variables['page_title'] !== '') {
    $title_attributes_array = array(
      'class' => array('title'),
      'id' => array('page-title'),
    );
    $title_attributes = drupal_attributes($title_attributes_array);

    return '<h1' . $title_attributes . '>' . $variables['page_title'] . '</h1>';
  }
}

/**
 * Returns the rendered breadcrumb.
 *
 * @ingroup themeable
 */
function theme_blockify_breadcrumb($variables) {
  return theme('breadcrumb', $variables);
}

/**
 * Returns the rendered action items.
 *
 * @ingroup themeable
 */
function theme_blockify_local_actions($variables) {
  $actions = render($variables['menu_local_actions']);
  if (!empty($actions)) {
    return '<ul class="action-links" class="clearfix">' . $actions . '</ul>';
  }
}

/**
 * Returns the rendered feed icons.
 *
 * @ingroup themeable
 */
function theme_blockify_feed_icons($variables) {
  return $variables['feed_icons'];
}

/**
 * Returns the rendered menu local tasks.
 *
 * @ingroup themeable
 */
function theme_blockify_menu_local_tasks($variables) {
  $tabs = theme('menu_local_tasks', $variables);
  if (!empty($tabs)) {
    return '<div id="tabs" class="clearfix">' . $tabs . '</div>';
  }
}

