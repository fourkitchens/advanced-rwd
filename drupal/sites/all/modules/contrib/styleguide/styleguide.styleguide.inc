<?php
// $Id: styleguide.styleguide.inc,v 1.7 2010/10/22 20:59:56 agentken Exp $

/**
 * Implements hook_styleguide().
 */
function styleguide_styleguide() {
  $items['a'] = array(
    'title' => t('Link'),
    'content' => ucfirst(styleguide_word(3)) . ' ' . l(styleguide_word(3), 'node') . ' ' . styleguide_word(4) . '.',
  );
  $items['em'] = array(
    'title' => t('Emphasis'),
    'content' => ucfirst(styleguide_word(3)) . ' <em>' . styleguide_word(3) . '</em> ' . styleguide_word(4) . '.',
  );
  $items['strong'] = array(
    'title' => t('Strong'),
    'content' => ucfirst(styleguide_word(3)) . ' <strong>' . styleguide_word(3) . '</strong> ' . styleguide_word(4) . '.',
  );
  $items['ul'] = array(
    'title' => t('Unordered list'),
    'theme' => 'item_list',
    'variables' => array('items' => styleguide_list(), 'type' => 'ul'),
    'group' => t('Lists'),
  );
  $items['ol'] = array(
    'title' => t('Ordered list'),
    'theme' => 'item_list',
    'variables' => array('items' => styleguide_list(), 'type' => 'ol'),
    'group' => t('Lists'),
  );
  $items['ul_title'] = array(
    'title' => t('Unordered list, with title'),
    'theme' => 'item_list',
    'variables' => array('items' => styleguide_list(), 'type' => 'ul', 'title' => ucwords(styleguide_word())),
    'group' => t('Lists'),
  );
  $items['ol_title'] = array(
    'title' => t('Ordered list, with title'),
    'theme' => 'item_list',
    'variables' => array('items' => styleguide_list(), 'type' => 'ol', 'title' => ucwords(styleguide_word())),
    'group' => t('Lists'),
  );
  $items['menu_tree'] = array(
    'title' => t('Menu tree'),
    'content' => menu_tree('management'),
    'group' => t('Menus'),
  );
  $items['table'] = array(
    'title' => t('Table'),
    'theme' => 'table',
    'variables' => array('header' => styleguide_header(), 'rows' => styleguide_rows()),
    'group' => t('Tables'),
  );
  $items['text'] = array(
    'title' => t('Text block'),
    'content' => styleguide_paragraph(3),
    'group' => t('Text'),
  );
  $items['image-horizontal'] = array(
    'title' => t('Image, horizontal'),
    'theme' => 'image',
    'variables' => array('path' => styleguide_image('horizontal'), 'alt' => t('My image'), 'title' => t('My image')),
    'group' => t('Media'),
  );
  $items['image-vertical'] = array(
    'title' => t('Image, vertical'),
    'theme' => 'image',
    'variables' => array('path' => styleguide_image('vertical'), 'alt' => t('My image'), 'title' => t('My image')),
    'group' => t('Media'),
  );
  $items['image-inset-horizontal'] = array(
    'title' => t('Image, horizontal, within text'),
    'content' => styleguide_paragraph(1) . theme('image', array('path' => styleguide_image('horizontal'), 'alt' => t('My image'), 'title' => t('My image'))) . styleguide_paragraph(2),
    'group' => t('Media'),
  );
  $items['image-inset-vertical'] = array(
    'title' => t('Image, vertical, within text'),
    'content' => styleguide_paragraph(1) . theme('image', array('path' => styleguide_image('vertical'), 'alt' => t('My image'), 'title' => t('My image'))) . styleguide_paragraph(2),
    'group' => t('Media'),
  );
  $content = '';
  for ($i = 1; $i <=6; $i++) {
    $content .= "<h$i>" . "h$i: " . implode(' ', styleguide_list()) . "</h$i>";
  }
  $items['headings'] = array(
    'title' => "Headings",
    'content' => $content,
    'group' => t('Text'),
  );
  $content = '';
  for ($i = 1; $i <=6; $i++) {
    $content .= "<h$i>" . "h$i: " . implode(' ', styleguide_list()) . "</h$i>" . styleguide_paragraph(1);
  }
  $items['headings_text'] = array(
    'title' => "Headings with text",
    'content' => $content,
    'group' => t('Text'),
  );
  $messages = array('status', 'warning', 'error');
  foreach ($messages as $message) {
    $items[$message . '-message'] = array(
      'title' => ucwords($message) . ' message',
      'content' => '<div class="messages ' . $message . '"><h2 class="element-invisible">Status message</h2>' . styleguide_sentence() . '</div>',
    );
  }
  // Form elements.
  $fake = $form_state = array();
  $elements = styleguide_form($fake, $form_state);
  $basic = array();
  $fieldsets = array();
  $tabs = array();
  $markup = array();
  foreach (element_children($elements) as $key) {
    if (!isset($elements[$key]['#type']) || $elements[$key]['#type'] == 'item') {
      $markup[] = $key;
    }
    elseif ($elements[$key]['#type'] == 'fieldset') {
      $fieldsets[] = $key;
    }
    elseif ($key == 'vertical_tabs') {
      $tabs[] = $key;
    }
    // We skip these.
    elseif (in_array($elements[$key]['#type'], array('button', 'submit', 'image_button'))) {
      $buttons[] = $key;
    }
    else {
      $basic[] = $key;
    }
  }
  $items['form'] = array(
    'title' => t('Forms, basic'),
    'content' => drupal_get_form('styleguide_form', $basic),
    'group' => t('Forms'),
  );
  $items['form-submit'] = array(
    'title' => t('Forms, submit'),
    'content' => drupal_get_form('styleguide_form', array('submit')),
    'group' => t('Forms'),
  );
  $items['form-button'] = array(
    'title' => t('Forms, button'),
    'content' => drupal_get_form('styleguide_form', array('button')),
    'group' => t('Forms'),
  );
  $items['form-image-button'] = array(
    'title' => t('Forms, image button'),
    'content' => drupal_get_form('styleguide_form', array('image_button')),
    'group' => t('Forms'),
  );
  $items['form-markup'] = array(
    'title' => t('Forms, markup'),
    'content' => drupal_get_form('styleguide_form', $markup),
    'group' => t('Forms'),
  );
  $items['form-fieldsets'] = array(
    'title' => t('Forms, fieldsets'),
    'content' => drupal_get_form('styleguide_form', $fieldsets),
    'group' => t('Forms'),
  );
  $items['form-vertical-tabs'] = array(
    'title' => t('Forms, vertical tabs'),
    'content' => drupal_get_form('styleguide_form', $tabs),
    'group' => t('Forms'),
  );

  return $items;
}
