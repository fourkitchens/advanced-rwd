(function($, window, undefined) {

  var viewportWidth = $('#magic-viewport-indicator');
  var modernizrDebug = $('#magic-modernizr-debug');

  //////////////////////////////
  // Localstorage Test
  //////////////////////////////
  function supports_html5_storage() {
    // Please see https://github.com/Modernizr/Modernizr/blob/master/feature-detects/storage/localstorage.js
    // for details.
    var mod = 'modernizr';
    try {
      localStorage.setItem(mod, mod);
      localStorage.removeItem(mod);
      return true;
    } catch(e) {
      return false;
    }
  }

  //////////////////////////////
  // Viewport Width Display
  //////////////////////////////
  if (viewportWidth.length) {
    var widthPX = $(window).width();
    var widthEM = widthPX / 16;

    if (supports_html5_storage()) {
      var viewportStatus = localStorage.getItem("Magic Viewport Storage");
    }

    if (viewportStatus !== null) {
      if (viewportStatus == 'px') {
        viewportWidth.html(widthPX + 'px');
      }
      else if (viewportStatus == 'em') {
        viewportWidth.html(widthEM + 'em');
      }
      else {
        viewportWidth.html(widthEM + 'em');
        localStorage.setItem("Magic Viewport Storage", 'em');
      }
    }



    viewportWidth.click(function() {
      $(window).resize(function() {
        widthPX = $(window).width();
        widthEM = widthPX / 16;
      });

      var parseHTML = parseFloat($(this).html());
      if (parseHTML == widthPX) {
        $(this).html(widthEM + 'em');
        if (supports_html5_storage()) {
          localStorage.setItem("Magic Viewport Storage", 'em');
        }
      }
      else if (parseHTML == widthEM) {
        $(this).html(widthPX + 'px');
        if (supports_html5_storage()) {
          localStorage.setItem("Magic Viewport Storage", 'px');
        }
      }
    });

    $(window).resize(function() {
      widthPX = $(window).width();
      widthEM = widthPX / 16;
      if (viewportWidth.html().indexOf('em') > 0) {
        viewportWidth.html(widthEM + 'em');
        if (supports_html5_storage()) {
          localStorage.setItem("Magic Viewport Storage", 'em');
        }
      }
      else {
        viewportWidth.html(widthPX + 'px');
        if (supports_html5_storage()) {
          localStorage.setItem("Magic Viewport Storage", 'px');
        }
      }
    });
  }

  //////////////////////////////
  // Modernizr Features Display
  //////////////////////////////
  if (modernizrDebug.length) {
    if (typeof Modernizr === "undefined") {
      modernizrDebug.html('Modernizr is not loaded!');
      console.log('Modernizr Not Loaded!');
    }
    else {

      if (supports_html5_storage()) {
        var modernizrStatus = localStorage.getItem("Magic Modernizr Storage");
      }

      if (modernizrStatus !== null) {
        modernizrDebug.removeClass('open closed');
        modernizrDebug.addClass(modernizrStatus);
      }

      modernizrDebug.html($('html').attr('class'));
      modernizrDebug.click(function() {
        if ($(this).hasClass('open')) {
          $(this).removeClass('open');
          $(this).addClass('closed');


          if (supports_html5_storage()) {
            localStorage.setItem("Magic Modernizr Storage", 'closed');
          }
        }
        else if ($(this).hasClass('closed')) {
          $(this).removeClass('closed');
          $(this).addClass('open');

          if (supports_html5_storage()) {
            localStorage.setItem("Magic Modernizr Storage", 'open');
          }
        }
      });
    }
  }
})(jQuery, window);
