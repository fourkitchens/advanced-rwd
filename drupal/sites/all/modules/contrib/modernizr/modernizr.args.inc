<?php
/**
 * @file
 *   An up-to-date list of Modernizr custom build args
 *   and the way in which they affect Modernizr. This
 *   file is the glue that makes the drush command for
 *   custom builds possible.
 */

global $_modernizr_args;

$_modernizr_args = array(

  // Tests
  'applicationcache' => 'tests',
  'audio' => 'tests',
  'borderradius' => 'tests',
  'boxshadow' => 'tests',
  'backgroundsize' => 'tests',
  'borderimage' => 'tests',
  'canvas' => 'tests',
  'canvastext' => 'tests',
  'cssanimations' => 'tests',
  'csscolumns' => 'tests',
  'cssgradients' => 'tests',
  'cssreflections' => 'tests',
  'csstransforms' => 'tests',
  'csstransforms3d' => 'tests',
  'csstransitions' => 'tests',
  'draganddrop' => 'tests',
  'flexbox' => 'tests',
  'flexboxlegacy' => 'tests',
  'fontface' => 'tests',
  'generatedcontent' => 'tests',
  'geolocation' => 'tests',
  'hashchange' => 'tests',
  'history' => 'tests',
  'hsla' => 'tests',
  'indexeddb' => 'tests',
  'inlinesvg' => 'tests',
  'input' => 'tests',
  'inputtypes' => 'tests',
  'localstorage' => 'tests',
  'multiplebgs' => 'tests',
  'opacity' => 'tests',
  'postmessage' => 'tests',
  'rgba' => 'tests',
  'sessionstorage' => 'tests',
  'smil' => 'tests',
  'svg' => 'tests',
  'svgclippaths' => 'tests',
  'textshadow' => 'tests',
  'touch' => 'tests',
  'video' => 'tests',
  'webgl' => 'tests',
  'websockets' => 'tests',
  'websqldatabase' => 'tests',
  'webworkers' => 'tests',

  // Extensibility
  'addtest' => 'extensibility',
  'domprefixes' => 'extensibility',
  'hasevent' => 'extensibility',
  'prefixed' => 'extensibility',
  'prefixes' => 'extensibility',
  'teststyles' => 'extensibility',
  'testprop' => 'extensibility',
  'testallprops' => 'extensibility',

  // Extras
  'load' => 'extras',
  'cssclasses' => 'extras',
  'mq' => 'extras',
  'printshiv' => 'extras',
  'shiv' => 'extras',

  // CSS Prefix
  'cssclassprefix' => 'extras',

);


