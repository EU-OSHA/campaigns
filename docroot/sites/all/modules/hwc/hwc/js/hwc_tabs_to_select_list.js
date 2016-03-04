(function($) {
    $(function() {
        var id = '';
        var name = '';
        var tab_container = $('div.quicktabs-wrapper div.quicktabs_main');

        var $ul_tabs = $('ul.quicktabs-tabs');
        $ul_tabs.addClass('hidden-xs hidden-md hidden-sm');
        $('.hwc-alphabet-container').addClass('hidden-xs');

        $ul_tabs.parent().prepend('<select class="select_from_tabs visible-xs visible-sm visible-md"></select>');
        var $select_tabs = $('.select_from_tabs');

        $('ul.quicktabs-tabs li').each(function() {
            var $this = $(this);
            var $a = $this.find('a');
            id = $a.attr('id');
            name = $a.text();
            var selected = '';
            if ($this.hasClass('active')) {
                selected = ' selected="selected" ';
            }
            $select_tabs.append('<option value="'+id+'"' + selected +'>'+name+'</option>');
        });


        $select_tabs.change(function(){
            var tab = $(this).val().replace('quicktabs-tab','#quicktabs-tabpage');
            tab_container.find('div.quicktabs-tabpage').addClass('quicktabs-hide');
            var idx = tab_container.find(tab).removeClass('quicktabs-hide').index();
            $ul_tabs.find('li').removeClass('active').eq(idx).addClass('active');
        });

        $(window).on('resize', function(){
            if ($select_tabs.is(':visible')) {
                var idx = $('.quicktabs-wrapper').find('.quicktabs-tabpage:visible').index();
                $select_tabs.val($select_tabs.find('option').eq(idx).val());
            }
        });
    });
})(jQuery);
