<?php
/**
 * @file
 * Default theme implementation to display a single Drupal page.
 *
 * The doctype, html, head and body tags are not in this template. Instead they
 * can be found in the html.tpl.php template in this directory.
 *
 * Available variables:
 *
 * General utility variables:
 * - $base_path: The base URL path of the Drupal installation. At the very
 *   least, this will always default to /.
 * - $directory: The directory the template is located in, e.g. modules/system
 *   or themes/bartik.
 * - $is_front: TRUE if the current page is the front page.
 * - $logged_in: TRUE if the user is registered and signed in.
 * - $is_admin: TRUE if the user has permission to access administration pages.
 *
 * Site identity:
 * - $front_page: The URL of the front page. Use this instead of $base_path,
 *   when linking to the front page. This includes the language domain or
 *   prefix.
 * - $logo: The path to the logo image, as defined in theme configuration.
 * - $site_name: The name of the site, empty when display has been disabled
 *   in theme settings.
 * - $site_slogan: The slogan of the site, empty when display has been disabled
 *   in theme settings.
 *
 * Navigation:
 * - $main_menu (array): An array containing the Main menu links for the
 *   site, if they have been configured.
 * - $secondary_menu (array): An array containing the Secondary menu links for
 *   the site, if they have been configured.
 * - $breadcrumb: The breadcrumb trail for the current page.
 *
 * Page content (in order of occurrence in the default page.tpl.php):
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title: The page title, for use in the actual HTML content.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 * - $messages: HTML for status and error messages. Should be displayed
 *   prominently.
 * - $tabs (array): Tabs linking to any sub-pages beneath the current page
 *   (e.g., the view and edit tabs when displaying a node).
 * - $action_links (array): Actions local to the page, such as 'Add menu' on the
 *   menu administration interface.
 * - $feed_icons: A string of all feed icons for the current page.
 * - $node: The node object, if there is an automatically-loaded node
 *   associated with the page, and the node ID is the second argument
 *   in the page's path (e.g. node/12345 and node/12345/revisions, but not
 *   comment/reply/12345).
 *
 * Regions:
 * - $page['help']: Dynamic help text, mostly for admin pages.
 * - $page['highlighted']: Items for the highlighted content region.
 * - $page['content']: The main content of the current page.
 * - $page['sidebar_first']: Items for the first sidebar.
 * - $page['sidebar_second']: Items for the second sidebar.
 * - $page['header']: Items for the header region.
 * - $page['footer']: Items for the footer region.
 *
 * @see bootstrap_preprocess_page()
 * @see template_preprocess()
 * @see template_preprocess_page()
 * @see bootstrap_process_page()
 * @see template_process()
 * @see html.tpl.php
 *
 * @ingroup themeable
 */
$theme_dir = drupal_get_path('theme', 'hwc_frontend');
?>
<?php if (!empty($page['above_header'])): ?>
<?php endif; ?>
<header id="navbar" class="navbar navbar-default container-fluid"><?php // print $navbar_classes; ?>
  <div class="container-fluid campaigns-header">
    <div class="row">
      <div class="navbar-header">
        <div class="row">
          <div class="col-xs-12 col-sm-9">
            <a class="pull-left" accesskey="0" href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>">
              <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" />
            </a>
            <a href="http://osha.europa.eu" title="EU-OSHA" target="_blank"><img class="pull-left" src="/<?php print $theme_dir . '/logo-osha.png'; ?>" alt="<?php print t('EU-OSHA logo'); ?>" /></a>
            <img class="pull-left" src="/<?php print $theme_dir . '/logo-eu.png'; ?>" alt="<?php print t('EU logo'); ?>" />
			<div class="header-text"><?php echo t('Healthy Workplaces for All Ages') . ' 2016-17'; ?></div>
          </div>
          <div class="col-xs-12 col-sm-3 xs-menu">
            <div class="header_top_bar">
              <div class="vertical-align">
                <?php print render($page['above_header']); ?>
              </div>
            </div>
            <?php print render($page['header']); ?>
			<!-- .btn-navbar is used as the toggle for collapsed navbar content -->
			<button type="button" class="navbar-toggle" data-toggle="collapse" data-target=".navbar-collapse">
			  <span class="sr-only">Toggle navigation</span>
			  <span class="icon-bar"></span>
			  <span class="icon-bar"></span>
			  <span class="icon-bar"></span>
			</button>
          </div>
        </div>
      </div>
    </div>
    <div class="row">
		<div class="navbar-collapse collapse">
		  <nav>
			<?php if (!empty($primary_nav)): ?>
			  <?php print render($primary_nav); ?>
			<?php endif; ?>
		  </nav>
		</div>
    </div>
  </div>
</header>

<div class="main-container container-fluid">

  <div class="row">
    <section class="<?php print (!empty($content_class)) ? $content_class : ''; ?>">
    <?php /* print $content_column_class; */ ?>
      <?php if (!empty($page['highlighted'])): ?>
        <div class="highlighted jumbotron"><?php print render($page['highlighted']); ?></div>
      <?php endif; ?>
      <?php if (!empty($breadcrumb)): print $breadcrumb; endif;?>
      <a id="main-content"></a>
		<?php print render($title_prefix); ?>
      <div class="above_title">
        <?php print render($page['above_title']); ?>
      </div>
      <div class="page_title">
        <?php if (!empty($title)): ?>
          <h1 class="page-header"><?php print $title; ?></h1>
        <?php endif; ?>
      </div>
      <?php print render($title_suffix); ?>
      <?php print $messages; ?>
      <?php if (!empty($tabs)): ?>
        <?php print render($tabs); ?>
      <?php endif; ?>
      <?php if (!empty($page['help'])): ?>
        <?php print render($page['help']); ?>
      <?php endif; ?>
      <?php if (!empty($action_links)): ?>
        <ul class="action-links"><?php print render($action_links); ?></ul>
      <?php endif; ?>
	  
	  <?php if (!empty($page['sidebar_first'])): ?>
		  <aside class="col-xs-12 col-sm-12 col-md-3" role="complementary">
			<?php print render($page['sidebar_first']); ?>
		  </aside>  <!-- /#sidebar-first -->
	  <?php endif; ?>
      <div id="skip-to-content" style="visibility: hidden; height: 0px"><a href="#skip-to-content" rel="nofollow" accesskey="S" style="visibility: hidden;"><?php print t('Skip to content'); ?></a></div>
      <?php print render($page['content']); ?>
    </section>
	
    <?php if (!empty($page['sidebar_second'])): ?>
      <aside class="col-xs-12 col-sm-8 col-sm-offset-2">
        <?php print render($page['sidebar_second']); ?>
      </aside>  <!-- /#sidebar-second -->
    <?php endif; ?>
  </div>
</div>
<footer class="footer">
  <?php print render($page['footer']); ?>
  <h2>
    <?php print t("Safety and health at work is everyone's concern. It's good for you. It's good for business."); ?>
  </h2>
  <p>
    <?php print t("European Agency for Safety and Health at Work | an agency of the European Union"); ?>
  </p>
  <div class="on-the-web">
    <?php $my_block = module_invoke('on_the_web', 'block_view', 'on_the_web'); print render($my_block['content']); ?>
  </div>
</footer>