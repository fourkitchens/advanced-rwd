<?php
/**
 * @file
 * Administrative page callbacks for the blockify module.
 */

/**
 * Blockify administration form.
 */
function blockify_admin_settings() {
  $form = array();

  $form['blockify_blocks'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Make the following blocks available'),
    '#options' => _blockify_get_blocks(FALSE),
    '#default_value' => variable_get('blockify_blocks', array()),
    '#description' => t('These blocks will be made available in places
      such as the blocks admin interface and the context UI.'),
  );

  return system_settings_form($form);
}
