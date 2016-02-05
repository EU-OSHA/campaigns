<script>
jQuery(document).ready(function ($) {
  var options = {
    $AutoPlay: false,
    $AutoPlaySteps: 1,
    $SlideDuration: 160,
//    $SlideWidth: 800,
    $SlideHeight: 230,
    $SlideSpacing: 1,
    $DisplayPieces: 1,
    $HWA: false,
    $BulletNavigatorOptions: {
      $Class: $JssorBulletNavigator$,
      $ChanceToShow: 1,
      $AutoCenter: 1
    },
    $ArrowNavigatorOptions: {
      $Class: $JssorArrowNavigator$,
      $ChanceToShow: 1,
      $AutoCenter: 2,
      $Steps: 1
    }
  };
  new $JssorSlider$("publications_slideshow", options);
});
</script>
<div id="publications_slideshow">
    <div id="num_slides" data-u="slides" style="">
      <?php print $rows ?>
    </div>
    <div data-u="navigator" class="jssorb03">
        <div class="prototype" data-u="prototype"></div>
    </div>	
    <span data-u="arrowleft" class="jssora03l publications"></span>
    <span data-u="arrowright" class="jssora03r publications"></span>
</div>
