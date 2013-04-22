<?php

/**
 * @file
 *   Admin include for Modernizr module.
 */

/**
 * Generates new Modernizr URL for admin interface
 * Callback for 'admin/config/development/modernizr'.
 */
function modernizr_generate_url() {
  $tests = modernizr_api_list(TRUE);
  $link = 'http://www.modernizr.com/download/#-';

  // Create the tests heading render element.
  $elements['tests']['heading-tests'] = array(
    '#theme' => 'html_tag',
    '#value' => t('Current Modernizr Tests'),
    '#tag' => 'h2',
  );

  // Create the tests description render element.
  $elements['tests']['description'] = array(
    '#theme' => 'html_tag',
    '#value' => t('Currently enabled Drupal modules and themes have requested the following Modernizr tests:'),
    '#tag' => 'p',
  );

  // Check to see if there are any registered tests.
  if (!empty($tests)) {
    // Loop through each registered test.
    foreach ($tests as $key => $test) {
      $module = $test['module'];

      // Check to see if this test's module has been set. If not, set it.
      if (!isset($elements['tests']['list'][$module])) {
        $elements['tests']['list'][$module]['name'] = array(
          '#theme' => 'html_tag',
          '#value' => $module,
          '#tag' => 'h3',
        );

        // Wrap this module.
        $elements['tests']['list'][$module]['#prefix'] = '<li>';
        $elements['tests']['list'][$module]['#suffix'] = '</li>';

        // Wrap the tests for this module.
        $elements['tests']['list'][$module]['tests']['#prefix'] = '<dl>';
        $elements['tests']['list'][$module]['tests']['#suffix'] = '</dl>';
      }

      // Create a definition pair for this test.
      $elements['tests']['list'][$module]['tests'][] = array(
        'label' => array(
          '#markup' => $key,
          '#prefix' => '<dt>',
          '#suffix' => '</dt>',
        ),
        'description' => array(
          '#markup' => $test['desc'],
          '#prefix' => '<dd>',
          '#suffix' => '</dd>',
        ),
      );

      // @todo Check to see if this test has already been added by another module.
      $link .= $key . '-';
    }

    // Wrap the modules.
    $elements['tests']['list']['#prefix'] = '<ul>';
    $elements['tests']['list']['#suffix'] = '</ul>';
  }
  else {
    $elements['tests']['list']['#markup'] = '<p>There are no Modernizr tests registered</p>';
  }

  // Create the download heading render element.
  $elements['download_build']['heading'] = array(
    '#theme' => 'html_tag',
    '#value' => t('Create a new Modernizr build'),
    '#tag' => 'h2',
    '#attributes' => array(
      'class' => array(
        'element-invisible',
      ),
    ),
  );

  // Create the download link render element.
  $elements['download_build']['link'] = array(
    '#prefix' => '<br>',
    '#theme' => 'link',
    '#text' => t('Download your Modernizr production build'),
    '#path' => substr($link, 0, -1), // Truncate the last hyphen.
    '#options' => array(
      'attributes' => array(
        'class' => array(
          'button',
        ),
        'target' => '_blank',
      ),
      'html' => FALSE,
    ),
  );

  // Create the download description render element.
  $elements['download_build']['description'] = array(
    '#theme' => 'html_tag',
    '#value' => t('The button links to a custom Modernizr build based on the tests listed above. <br/> Once you download the script, place it inside <b>!path</b> and !cc.', array(
      '!path' => module_exists('libraries') ? 'sites/all/libraries/modernizr' : drupal_get_path('module', 'modernizr') . '/js',
      '!cc' => l(t('clear your cache'), 'admin/config/development/performance'),
    )),
    '#tag' => 'p',
  );

  return $elements;
}
