(function($, pane) {
  'use strict';

  Drupal.behaviors[pane] = {
    attach: function(context) {
      var $context = $(context);

      $context.once(pane, function() {
        var $select = $context.find('#edit-context'),
            $image = $context.find('.form-item-image-field');

        $select.on('change', (function change() {
          var methods = {
            image: 'show',
            fields: 'hide'
          };

          if ('empty' == $select.val()) {
            methods.image = methods.fields;
            methods.fields = 'show';
          }

          $image[methods.image]().siblings(':not(.form-actions, .form-item-context)')[methods.fields]();

          return change;
        })());
      });
    }
  };
})(jQuery, 'pane__preview');
