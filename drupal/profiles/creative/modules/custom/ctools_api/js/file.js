;(function($, module) {
  'use strict';

  var CToolsAPI = function CToolsAPI(browser) {
    this.settings = {
      browser: browser,
      browserId: module + '_' + browser
    };
  };

  CToolsAPI.prototype = {
    constructor: CToolsAPI,
    getFidByUri: function(uri, func) {
      var self = this;

      $.get('/' + module + '/get_fid_by_uri', {uri: uri}, function(fid) {
        if (fid > 0) {
          self.settings.$wrapper.children('[type=hidden]').val(fid);
          self.settings.$wrapper.children('[type=submit]').mousedown();

          if (func instanceof Function) {
            func(fid, uri);
          }
        }
      });
    },
    addImplementation: function(func) {
      var self = this,
          browserId = self.settings.browserId;

      Drupal.behaviors[browserId] = {
        attach: function(context, settings) {
          var $opener = $('<span class="pseudo-link">' + Drupal.t('Browse files') + '</span>');

          self.settings = $.extend(self.settings, settings[browserId]);

          $(context).find('.' + self.settings.browser + '-files-browser [type=file]').once().each(function() {
            self.settings.input = this;
            self.settings.$wrapper = $(this).parent();

            self.settings.$wrapper.before($opener.bind('click', func));
          });
        }
      };

      return self;
    }
  };

  window.CToolsAPI = CToolsAPI;
})(jQuery, 'ctools_api');
