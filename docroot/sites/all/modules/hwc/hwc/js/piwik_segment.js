(function($) {
    Drupal.behaviors.piwik_segment = {
        attach: function(context, settings) {
            $('body').once('piwik_segment', function(){
                var cookie_name = 'hwc_segment';
                var segment = $.cookie(cookie_name);
                if (segment == null && typeof Drupal.settings.hwc.segment != 'undefined') {
                    segment = Drupal.settings.hwc.segment;
                    $.cookie(cookie_name, segment, { expires: 30 * 6 });
                }
                if (typeof _paq != 'undefined') {
                    _paq.push(['setCustomDimension', Drupal.settings.hwc.cd_id, segment]);
                }
            });
        }
    }
})(jQuery);
