<?php
/**
 * @file
 * Social share widgets
 *
 * Available variables:
 * - $url: URL to the page
 * - $node: Current node / A false node with nid=0 if the widget is for a page
 * - $tweet_url: Twitter share URL
 * - $language: Current language
 * - $options: Additional configuration options
 *
 * Additional configuration options variables:
 * - rss_url: URL to the RSS feed
 * - rss_hide: Set to TRUE to hide the RSS link
 * @see template_process()
 */
?>
<?php
/** @var string $tweet_url */
/** @var array $options */
$rss_url = !empty($options['rss_url']) ? $options['rss_url'] : url('rss-feeds/latest/news.xml', array('absolute' => TRUE));
$rss_hide = !empty($options['rss_hide']);

// FB share counter.
//$api = simplexml_load_file('http://api.facebook.com/restserver.php?method=links.getStats&urls==' . $url);
//$count = json_decode($api);
//$fb_share_count = isset($api->link_stat->share_count) ? (string) $api->link_stat->share_count : 0;

$twitter_url = str_replace('http://', '', $url);
$twitter_url = str_replace('https://', '', $twitter_url);
// Twitter share counter.
//$api = file_get_contents('https://cdn.api.twitter.com/1/urls/count.json?url=' . $twitter_url);
//$count = json_decode($api);
//$twitter_share_count = isset($count->count) ? $count->count : 0;

// LinkedIn share counter.
//$api = file_get_contents('https://www.linkedin.com/countserv/count/share?url=' . $url . '&format=json');
//$count = json_decode($api);
//$linkedin_share_count = isset($count->count) ? $count->count : 0;

?>
<div class="hwc-share-widget">
  <ul>
    <li id="facebook-share-button-<?php print $node->nid; ?>"  class="hwc-share-widget-button hwc-share-widget-facebook" data-href="">
      <a onclick="window.open(this.href, 'hwc-share', 'left=20,top=20,width=500,height=500,toolbar=1,resizable=0'); return false;"
         href="https://www.facebook.com/sharer/sharer.php?u=<?php print $url ?>">Facebook</a>
    </li>
    <li class="label">
      <?php print t('Share'); ?>
    </li>
    <li id="twitter-share-button-<?php print $node->nid; ?>" class="hwc-share-widget-button hwc-share-widget-twitter">
      <a href="<?php print $tweet_url; ?>">Twitter</a>
    </li>
    <li class="label">
      <?php print t('Tweet'); ?>
    </li>
    <li id="linked-in-<?php print $node->nid; ?>" class="napo-share-widget-button napo-share-widget-linkedin">
      <a href="https://www.linkedin.com/shareArticle?mini=true&url=<?php print $url; ?>">Linked in</a>
    </li>
    <li class="label">
      <?php print t('Share'); ?>
    </li>
    <li id="google-plus-<?php print $node->nid; ?>" class="napo-share-widget-button napo-share-widget-google-plus">
      <a onclick="window.open(this.href, 'hwc-share', 'left=20,top=20,width=500,height=500,toolbar=1,resizable=0'); return false;"
         href="https://plus.google.com/share?url=<?php print $url; ?>">Google+</a>
    </li>
    <li class="label">
      <?php print t('Share'); ?>
    </li>
    <?php if (!$rss_hide): ?>
      <li class="label label-rss pull-right">
        <?php print t('RSS'); ?>
      </li>
    <li class="pull-right">
      <a href="<?php print $rss_url; ?>">RSS</a>
    </li>
    <?php endif; ?>
  </ul>
</div>
<script>
  (function($) {

    $(window).ready(function(){
      $('#twitter-share-button-<?php print $node->nid; ?> a').click(function(e) {
        e.preventDefault();
        var width  = 575,
          height = 400,
          left   = ($(window).width()  - width)  / 2,
          top    = ($(window).height() - height) / 2,
          opts   = 'status=1' +
            ',width='  + width  +
            ',height=' + height +
            ',top='    + top    +
            ',left='   + left;
        window.open(this.href, 'twitter', opts);
      });

      $('#linked-in-<?php print $node->nid; ?> a').click(function(e) {
        e.preventDefault();
        var width  = 575,
          height = 400,
          left   = ($(window).width()  - width)  / 2,
          top    = ($(window).height() - height) / 2,
          opts   = 'status=1' +
            ',width='  + width  +
            ',height=' + height +
            ',top='    + top    +
            ',left='   + left;
        window.open(this.href, 'Linked In', opts);
      });
    });
  })(jQuery);
</script>


<?php
/* PIWIK EVENTS */
$event_name = '/node/' . $node->nid;
$event_val = $language->language;
if (!empty($node->path['alias'])) {
  $event_name = '/' . $node->path['alias'];
}
?>
<script>
    (function($) {
        $(window).ready(function(){
            if (typeof _paq != 'undefined') {
                $('#linked-in-<?php print $node->nid; ?> a').click(function(event) {
                    _paq.push(['trackEvent', 'Share', 'LinkedIn', '<?php print $event_name ?>', '<?php print $event_val ?>']);
                });
                $('#twitter-share-button-<?php print $node->nid; ?> a').click(function(event) {
                    _paq.push(['trackEvent', 'Share', 'Twitter', '<?php print $event_name ?>', '<?php print $event_val ?>']);
                });
                $('#facebook-share-button-<?php print $node->nid; ?> a').click(function(event) {
                    _paq.push(['trackEvent', 'Share', 'Facebook', '<?php print $event_name ?>', '<?php print $event_val ?>']);
                });
                $('#google-plus-<?php print $node->nid; ?> a').click(function(event) {
                    _paq.push(['trackEvent', 'Share', 'Google+', '<?php print $event_name ?>', '<?php print $event_val ?>']);
                });
            }
        });
    })(jQuery);
</script>