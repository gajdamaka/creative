(function($) {
  'use strict';

  Theme.has('html', function($body) {
    var $menu = $('.mobile-menu-wrapper'),
        $overlay = $('#overlay'),
        $header = $('header');

    $body.find('.mobile-menu').on('click', function() {
      //$menu.toggleClass('open');
      $overlay.css('top', $header.outerHeight() + $header.offset().top).toggle();
    });
    $('.carousel').carousel({
      interval: 5000 //changes the speed
    })
  });
})(jQuery);
