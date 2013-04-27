window.onload = function() {
  var menu = document.getElementById('menu');
  // var info = document.getElementById('info');
  // var about = document.getElementById('about');
  var main = document.getElementById('main')

  menu.addEventListener('click', function() {
    if (hasClass(main, 'open')) {
      removeClass(main, 'open');
    }
    else {
      addClass(main, 'open');
    }
  });

  // info.addEventListener('click', function() {
  //   if (hasClass(info, 'open')) {
  //     removeClass(info, 'open');
  //   }
  //   else {
  //     addClass(info, 'open');
  //   }
  // });

  // about.addEventListener('click', function() {
  //   if (hasClass(about, 'open')) {
  //     removeClass(about, 'open');
  //   }
  //   else {
  //     addClass(about, 'open');
  //   }
  // });


  //////////////////////////////
  // Has Class
  //
  // From http://www.avoid.org/?p=78
  //////////////////////////////
  function hasClass(el, name) {
   return new RegExp('(\\s|^)'+name+'(\\s|$)').test(el.className);
  }

  //////////////////////////////
  // Remove Class
  //
  // From http://stackoverflow.com/questions/2155737/remove-css-class-from-element-with-javascript-no-jquery
  //////////////////////////////
  function removeClass(ele,cls) {
    if (hasClass(ele,cls)) {
      var reg = new RegExp('(\\s|^)'+cls+'(\\s|$)');
      ele.className=ele.className.replace(reg,' ');
    }
  }

  //////////////////////////////
  // Add Class
  //
  // From http://www.avoid.org/?p=78
  //////////////////////////////
  function addClass(el, name) {
   if (!hasClass(el, name)) { el.className += (el.className ? ' ' : '') +name; }
  }
}