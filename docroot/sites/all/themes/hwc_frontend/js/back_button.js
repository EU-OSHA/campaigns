(function ($, Drupal) {
    Drupal.behaviors.skbp_back_button = {
        attach: function (context, settings) {
            $("body").once('skbp_back_button').each(function(){
                if (document.referrer.indexOf(window.location.origin + '/search') === 0) {
                    $(this).find('a.back-to-link').show().attr('href', document.referrer);
                }
                else {
                    $(this).find('a.back-to-link').hide();
                }
            });
        }
    };
})(jQuery, Drupal);
