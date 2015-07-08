(function($) {
  'use strict';

  Theme.has('html', function($body) {
    var $menu = $('.mobile-menu-wrapper'),
        $overlay = $('#overlay'),
        $header = $('header .wrapper');

    $body.find('.mobile-menu').on('click', function() {
      if ($menu.hasClass('open')){
        $menu.stop().hide(500);
        $menu.removeClass('open');
      }
      else {
        $menu.toggleClass('open');
        $menu.stop().show(500);
      }

      setTimeout(function() {
        $overlay.css('top', $header.outerHeight()).toggle()
      }, 500);
    });
  });
})(jQuery);
