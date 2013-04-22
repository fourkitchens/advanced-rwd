// $Id: README.markdown,v 1.2 2010/10/19 15:01:29 agentken Exp $

# Style Guide Drupal Module [http://drupal.org/project/styleguide](http://drupal.org/project/styleguide)

The Style Guide module creates an API and preview page for displaying common
theme elements. Use it to preview items such as tables, menus, and lists in your
custom themes.

## Installing Style Guide:

 * Place the entirety of this directory on a Drupal module path, under a
 location like: sites/all/modules/ or sites/all/modules/contrib
 * Navigate to the modules administration page and enable the module.

## Using Style Guide

 * You must be logged in as a global admin user (uid=1), or the user you are
 logged in with must have a "View theme style guides" permission.
 * Navigate to: http://yourdomain.com/admin/appearance/styleguide and you will
 see a style guide for the current default theme. 
 * Using the tabs at the top of the page, you can switch to viewing the style
 guide in any other, available theme.

## Extending Style Guide

To change the list of items displayed by Style Guide, third-party modules
can implement following hooks:
 * hook_styleguide()
 * hook_styleguide_alter(&$items)
