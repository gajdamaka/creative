(function($) {
  'use strict';

  var $body,
      split = function(string) {
        return string.split(/\s|,/);
      },
      callbacks = {
        has: {},
        add: {},
        remove: {}
      };

  window.Theme = function Theme() {
    var self = this;

    $(function() {
      $body = $('body');

      $.each(['add', 'remove'], function(i, prefix) {
        var suffix = 'Class',
            method = prefix + suffix,
            original = $.fn[method];

        $.fn[method] = function(class_name) {
          var data = {
            type: prefix,
            className: class_name
          };

          $(this).trigger('change' + suffix, data).trigger(method, data);

          return original.apply(this, arguments);
        };
      });

      $body.on('addClass removeClass', function(event, data) {
        $.each(split(data.className), function() {
          self.execute(data.type, this);
        });
      });

      for (var class_name in callbacks.has) {
        self.execute('has', class_name);
      }
    });
  };

  Theme.prototype = {
    constructor: Theme,
    execute: function(type, class_name) {
      if (typeof callbacks[type][class_name] == 'object') {
        for (var i = 0; i < callbacks[type][class_name].length; i++) {
          callbacks[type][class_name][i]($body, class_name, Drupal.settings);
        }
      }
    },
    register: function(type, class_names, func) {
      if (typeof func == 'function' && callbacks[type]) {
        $.each(split(class_names), function() {
          callbacks[type][this] = callbacks[type][this] || [];
          callbacks[type][this].push(func);
        });
      }

      return this;
    },
    has: function(class_names, func) {
      return this.register('has', class_names, func);
    },
    add: function(class_names, func) {
      return this.register('add', class_names, func);
    },
    remove: function(class_names, func) {
      return this.register('remove', class_names, func);
    }
  };

  window.Theme = new Theme;
})(jQuery);
