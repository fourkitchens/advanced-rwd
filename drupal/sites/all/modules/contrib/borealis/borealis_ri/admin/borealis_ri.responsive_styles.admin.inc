<?php

/**
 * @Administration page for Responsive Styles form.
 *
 * @todo
 *  Sit fieldsets side by side, make clicking a checkbox activate AJAX niceness to create styls and move to other fieldset
 */
function borealis_ri_responsive_styles_form($form, &$form_state) {
  // Get list of responsive styles.
  $responsive = variable_get('borealis_ri_parents', array());

  // Add Custom CSS
  drupal_add_css(drupal_get_path('module', 'image') . '/image.admin.css');
  drupal_add_css(drupal_get_path('module', 'borealis_ri') . '/css/borealis-ri_admin.css');

  // Get list of styles.
  $styles = image_styles();
  foreach ($styles as $style_name => $style) {
    if ($style['module'] == 'borealis_ri') {
      unset($styles[$style_name]);
    }
  }
  $form_state['styles'] = $styles;

  // Set page title.
  drupal_set_title('Responsive Styles');

  // AJAX anchor wrapper.
  $form['form_wrapper_open'] = array(
    '#markup' => '<span id="form_wrapper">',
  );

  // Description of page.
  $form['description'] = array(
    '#markup' => '<p class="responsive-styles-description">' . t('Select the styles below that you would like to be responsive. Responsive styles will retail all of their effects, with only their scale changed depending on the responsive action. Scale ratio and Scale and Crop ratios will be preserved.') . '</p>',
  );



  // Wrapper for Disabled Styles
  $form['disabled'] = array(
    '#type' => 'fieldset',
    '#title' => t('Non-Responsive Image Styles'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
  );

  // Wrapper for Enabled Styles
  $form['enabled'] = array(
    '#type' => 'fieldset',
    '#title' => t('Responsive Image Styles'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
  );

  // Get Sample Image
  $sample_image = variable_get('image_style_preview_image', drupal_get_path('module', 'image') . '/sample.png');
  $sample_width = 75;
  $sample_height = 75;

  // Set up original file information
  $original_image = image_get_info($sample_image);
  if ($original_image['width'] > $original_image['height']) {
    $original_width = min($original_image['width'], $sample_width);
    $original_height = round($original_width / $original_image['width'] * $original_image['height']);
  }
  else {
    $original_height = min($original_image['height'], $sample_height);
    $original_width = round($original_height / $original_image['height'] * $original_image['width']);
  }
  $original_attributes = array_intersect_key($original_image, array('width' => '', 'height' => ''));
  $original_attributes['style'] = 'width: ' . $original_width . 'px; height: ' . $original_height . 'px;';
  $original_url = file_create_url($sample_image);

  // Loop through each style.
  foreach ($styles as $style) {
    // Find name of Style
    $name = $style['name'];

    // Find effects put on style.
    $effects = t('Effects') . ': ';
    foreach ($style['effects'] as $effect) {
      $effects .= t($effect['label']) . ', ';
    }
    $effects = substr($effects, 0, -2);

    // Set up preview file information.
    $preview_file = image_style_path($style['name'], $sample_image);
    if (!file_exists($preview_file)) {
      image_style_create_derivative($style, $sample_image, $preview_file);
    }
    $preview_image = image_get_info($preview_file);
    if ($preview_image['width'] > $preview_image['height']) {
      $preview_width = min($preview_image['width'], $sample_width);
      $preview_height = round($preview_width / $preview_image['width'] * $preview_image['height']);
    }
    else {
      $preview_height = min($preview_image['height'], $sample_height);
      $preview_width = round($preview_height / $preview_image['height'] * $preview_image['width']);
    }
    $preview_attributes = array_intersect_key($preview_image, array('width' => '', 'height' => ''));
    $preview_attributes['style'] = 'width: ' . $preview_width . 'px; height: ' . $preview_height . 'px;';

    // In the previews, timestamps are added to prevent caching of images.
    $preview = '<div class="image-style-preview preview clearfix">';

    // Build the preview of the original image.
    $original_url = file_create_url($sample_image);
    $preview .= '<div class="preview-image-wrapper original-image">';
    $preview .= '<span class="preview-title">' . t('original') . ' (' . l(t('view actual size'), $original_url) . ')</span>';
    $preview .= '<div class="preview-image original-image" style="' . $original_attributes['style'] . '">';
    $preview .= '<a href="' . $original_url . '">' . theme('image', array('path' => $sample_image, 'alt' => t('Sample original image'), 'title' => '', 'attributes' => $original_attributes)) . '</a>';
    $preview .= '<div class="height" style="height: ' . $original_height . 'px"><span>' . $original_image['height'] . 'px</span></div>';
    $preview .= '<div class="width" style="width: ' . $original_width . 'px"><span>' . $original_image['width'] . 'px</span></div>';
    $preview .= '</div>'; // End preview-image.
    $preview .= '</div>'; // End preview-image-wrapper.

    // Build the preview of the image style.
    $preview_url = file_create_url($preview_file) . '?cache_bypass=' . REQUEST_TIME;
    $preview .= '<div class="preview-image-wrapper modified-image">';
    $preview .= '<span class="preview-title">' . check_plain($style['name']) . ' (' . l(t('view actual size'), file_create_url($preview_file) . '?' . time()) . ')</span>';
    $preview .= '<div class="preview-image modified-image" style="' . $preview_attributes['style'] . '">';
    $preview .= '<a href="' . file_create_url($preview_file) . '?' . time() . '">' . theme('image', array('path' => $preview_url, 'alt' => t('Sample modified image'), 'title' => '', 'attributes' => $preview_attributes)) . '</a>';
    $preview .= '<div class="height" style="height: ' . $preview_height . 'px"><span>' . $preview_image['height'] . 'px</span></div>';
    $preview .= '<div class="width" style="width: ' . $preview_width . 'px"><span>' . $preview_image['width'] . 'px</span></div>';
    $preview .= '</div>'; // End preview-image.
    $preview .= '</div>'; // End preview-image-wrapper.

    $preview .= '</div>'; // End image-style-preview.

    $in_responsive = FALSE;
    foreach ($responsive as $respond_style) {
      if (in_array($name, $respond_style)) {
        $in_responsive = TRUE;
      }
    }

    if ($in_responsive) {
      // Build disabled checkbox for each style.
      $form['enabled'][$name] = array(
        '#type' => 'checkbox',
        '#prefix' => '<div class="inner-left">',
        '#title' => $name,
        '#description' => $effects,
        '#default_value' => 1,
        '#suffix' => '</div><div class="inner-right">' . $preview . '</div>',
        '#ajax' => array(
          'callback' => 'borealis_ri_take_responsive',
          'wrapper' => 'form_wrapper',
        ),
      );
    }
    else {
      // Build disabled checkbox for each style.
      $form['disabled'][$name] = array(
        '#type' => 'checkbox',
        '#prefix' => '<div class="inner-left">',
        '#title' => $name,
        '#description' => $effects,
        '#suffix' => '</div><div class="inner-right">' . $preview . '</div>',
        '#default_value' => 0,
        '#ajax' => array(
          'callback' => 'borealis_ri_make_responsive',
          'wrapper' => 'form_wrapper',
        ),
      );
    }
  }

  // End AJAX anchor wrapper.
  $form['form_wrapper_close'] = array(
    '#markup' => '</span>',
  );

  return $form;
}

function borealis_ri_make_responsive($form, $form_state) {
  // Get triggering element
  $trigger_title = $form_state['triggering_element']['#title'];
  $trigger = $form_state['complete form']['disabled'][$trigger_title];

  // Add to the borealis_ri variable
  $responsive = variable_get('borealis_ri_parents', array());
  $responsive[$trigger_title] = $form_state['styles'][$trigger_title];
  variable_set('borealis_ri_parents', $responsive);

  $form['enabled'][$trigger_title] = $trigger;
  unset($form['disabled'][$trigger_title]);

  borealis_ri_build_and_flush($trigger_title);
  return $form;
}

function borealis_ri_take_responsive($form, $form_state) {
  // Get triggering element
  $trigger_title = $form_state['triggering_element']['#title'];
  $trigger = $form_state['complete form']['enabled'][$trigger_title];

  $form['enabled'][$trigger_title] = $trigger;
  unset($form['disabled'][$trigger_title]);

  // Add to the borealis_ri variable
  $responsive = variable_get('borealis_ri_parents', array());
  unset($responsive[$trigger_title]);
  variable_set('borealis_ri_parents', $responsive);

  $form['disabled'][$trigger_title] = $trigger;
  unset($form['enabled'][$trigger_title]);

  borealis_ri_build_and_flush($trigger_title);
  return $form;
}

function borealis_ri_responsive_styles_settings_form($form, &$form_state) {
  drupal_add_css(drupal_get_path('module', 'borealis_ri') . '/css/borealis-ri_settings.css');

  $form['borealis_key'] = array(
    '#type' => 'hidden',
    '#value' => 'borealis_ri',
  );

  $form['back'] = array(
    '#markup' => '<ul class="action-links"><li><a href="/admin/config/media/image-styles/responsive">' .t('Back to Responsive Styles') . '</a></li></ul>'
  );

  $form['min_size'] = array(
    '#type' => 'textfield',
    '#title' => t('Minimum Image Width'),
    '#default_value' => variable_get('borealis_ri_min_size', 250),
    '#description' => t("The smallest width you'd like to have your Responsive Images generated at. This applies to all responsive images. Should be larger than 50px and smaller than 500px."),
    '#size' => 3,
    '#required' => TRUE,
    '#field_suffix' => 'px',
    '#ajax' => array(
      'callback' => 'borealis_ri_responsive_styles_settings_ajax'
    ),
  );

  $form['hidpi'] = array(
    '#type' => 'radios',
    '#title' => t('High DPI Quality'),
    '#options' => array(
      '1.5' => t('Smaller Download Size'),
      '1.75' => t('Normal'),
      '2' => t('Higher Quality'),
    ),
    '#default_value' => variable_get('borealis_ri_hidpi', '1.75'),
    '#description' => t('Choose the quality of the images for high resolution devices.'),
    '#ajax' => array(
      'callback' => 'borealis_ri_responsive_styles_settings_ajax'
    ),
  );

  $lazyload = variable_get('borealis_ri_lazyload', true);

  $form['lazyload'] = array(
    '#type' => 'radios',
    '#title' => t('Initial Image Load'),
    '#description' => t('Choose whether you would like to always load the smallest image in or use an image placeholder.'),
    '#default_value' => $lazyload,
    '#options' => array(
      false => t('Always Load Smallest Image Size'),
      true => t('Use Image Placeholders')
    ),
    '#ajax' => array(
      'callback' => 'borealis_ajax_settings_save',
    ),
  );

  $form['aspect_ratio'] = array(
    '#type' => 'radios',
    '#title' => t('Placeholder Aspect Ratio'),
    '#options' => array(
      '1' => '1:1',
      '3/4' => '4:3',
      '9/16' => '16:9'
    ),
    '#default_value' => variable_get('borealis_ri_aspect_ratio', '3/4'),
    '#description' => t('The aspect ratio of the placeholder. Should be similar to the majority of the images that will be used.'),
    '#prefix' => '<span id="aspect-ratio">',
    '#suffix' => '</span>',
    '#states' => array(
      'visible' => array(
        ':input[name="lazyload"]' => array('value' => '1'),
      ),
    ),
    '#ajax' => array(
      'callback' => 'borealis_ajax_settings_save',
    ),
  );

  $form['image_wrap'] = array(
    '#type' => 'checkbox',
    '#title' => t('Wrap Images in container'),
    '#description' => t('Borealis works by finding the nearest non-block level element\'s width and swapping out out the images based on that width. This will wrap your Borealis images in an inline-block <span> with classes you can target to set specific sizes.'),
    '#default_value' => variable_get('borealis_image_wrap', 0),
    '#ajax' => array(
      'callback' => 'borealis_ajax_settings_save'
    ),
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save configuration'),
  );

  return $form;
}

function borealis_ri_responsive_styles_settings_form_submit($form, &$form_state) {
  borealis_ri_build_and_flush();

  variable_set('borealis_ri_hidpi', $form_state['values']['hidpi']);
  variable_set('borealis_ri_lazyload', $form_state['values']['lazyload']);
  variable_set('borealis_ri_min_size', $form_state['values']['min_size']);
  variable_set('borealis_image_wrap', $form_state['values']['image_wrap']);

  drupal_set_message(t('Your settings have been saved'));
}

function borealis_ri_responsive_styles_settings_ajax($form, &$form_state) {
  borealis_ajax_settings_save($form, $form_state);
  borealis_ri_build_and_flush();
}

// function borealis_ri_lazyload_options($form, $form_state) {
//   $lazyload = variable_get('borealis_ri_lazyload', 1);

//   if (!$lazyload) {
//     $form['aspect_ratio']['#disabled'] = true;
//   }
//   else {
//     $form['aspect_ratio']['#disabled'] = false;
//   }

//   borealis_ajax_settings_save($form, $form_state);

//   return $form['aspect_ratio'];
// }