<script>
  jQuery(document).ready(function ($) {
    var options = {
      $AutoPlay: true,
      $SlideWidth: 1100,
      $SlideHeight: 200,
      $BulletNavigatorOptions: {
        $Class: $JssorBulletNavigator$,
        $ChanceToShow: 2,
        $AutoCenter: 1
      }
    };
    new $JssorSlider$('homepage_slider', options);
  });
</script>
<div class="separator_recomended_resources_home">&nbsp;</div>
<div id="homepage_slider" class="homepage-slider">
  <!-- Slides Container -->
  <div id="num_slides" data-u="slides">
    <?php print $rows ?>
  </div>
  <!-- Bullet navigator container -->
  <div data-u="navigator" class="jssorb12">
    <!-- Bullet navigator item prototype -->
    <div data-u="prototype"></div>
  </div>
  <!--#endregion Bullet Navigator Skin End -->
</div>
