(function($) {var cookie_name = 'hsg';
    var segment = $.cookie(cookie_name);
    if (segment == null && Drupal.settings.hwc.segment != null) {
        segment = Drupal.settings.hwc.segment;
        $.cookie(cookie_name, segment, { expires: 30 * 6 });
    }
    if (typeof _paq != 'undefined' && segment != null) {
        _paq.push(['setCustomDimension', 2, segment]);
    }
})(jQuery);