;(function($, browser) {
  'use strict';

  var ckfinder = new CKFinder('public://test'),
      module = new CToolsAPI(browser).addImplementation(function() {
        var settings = module.settings;

        $.each(['basePath', 'language'], function() {
          ckfinder[this] = settings[this];
        });

        ckfinder.selectActionFunction = function(url) {
          module.getFidByUri(settings.scheme + ':' + url.replace(new RegExp(settings.schemeUrl), ''));
        };

        ckfinder.popup();
      });
})(jQuery, 'ckfinder');
