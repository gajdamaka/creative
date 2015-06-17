;(function($, module) {
  'use strict';

  Drupal.behaviors[module] = {
    attach: function(context) {
      var $context = $(context);

      // Process all [type=checkbox] and [type=radio] fields.
      $context.find('.form-type-checkbox, .form-type-radio').once(module, function() {
        var $checkbox = $(this).children('input'),
            input = $checkbox[0];

        $checkbox.after('<label class="pseudo-box ' + input.type + '" for="' + input.id + '"></label>');
      });

      // Process all [type=file] fields.
      $context.find('.form-type-managed-file').once(module, function() {
        var $container = $(this);

        $container.find('[type=file]').css({position: 'fixed', top: '-100px'}).each(function() {
          var $filed = $(this).on('change', function() {
                $wrapper.text(this.value.replace(/.*\\(.*)$/g, '$1')).toggleClass('focus');
              }),
              $wrapper = $('<div class="pseudo-file" />').on('click', function() {
                $filed.click();
                $(this).toggleClass('focus');
              });

          $wrapper.prependTo(this.parentNode);
        });

        $container.find('a').attr('target', '_blank');
      });

      // Handler for "horizontal_tabs" type.
      $context.find('.horizontal-tabs').once(module, function() {
        var $tabs = $('<ul class="clearfix" />'),
            $fieldsets = $(this).children('fieldset');

        $fieldsets.each(function() {
          var $fieldset = $(this);

          $tabs.append($('<li class="' + this.id + '">' + $fieldset.children('legend').text() + '</li>').bind('click', function() {
            var $tab = $(this);

            $fieldsets.add($tab.siblings()).removeClass('active');
            $fieldset.add($tab).addClass('active');
          }));
        });

        $tabs.prependTo(this);
        $tabs.children().first().click();
      });
    }
  };
})(jQuery, 'ctools_api');
