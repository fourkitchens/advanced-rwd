Modernizr for Drupal
====================

This module implements Modernizr, the client-side feature detection
library. Modernizr allows you to avoid user-agent sniffing on the
server, and rely on the honesty of the browsers that visit your
website by detecting each individual feature that they support.

Modernizr will inject yes/no classes into your <html> tag for each
test, so that you can write conditional rules based on the results:

    .multiplebgs div p {
      /* properties for browsers that
         support multiple backgrounds */
    }
    .no-multiplebgs div p {
      /* optional fallback properties
         for browsers that don't */
    }

Modernizr v2 optionally includes a script loader which can load
additional resources based on the outcome of specific Modernizr
tests you're interested in:

    Modernizr.load({
      test : Modernizr.geolocation,
      yep  : 'normal.js',
      nope : ['polyfill.js', 'wrapper.js']
    });

The 3.x branch of the Drupal module aims to integrate Modernizr.load()
so it is available to themes/modules that support HTML5/CSS3 features.

For more information, visit: http://www.modernizr.com/docs/

Usage
=====

Find admin settings at /admin/config/development/modernizr


Credits
=======

Project page: http://drupal.org/project/modernizr
Library page: http://modernizr.com

Module originally written by:
Tamás Demeter-Haludka - http://drupal.org/user/372872

Maintainers:
Chris Ruppel - http://drupal.org/user/411999
