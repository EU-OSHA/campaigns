<table border="0" cellpadding="20" cellspacing="0" width="800" style="margin-left: 25px;">
  <tbody>
	<tr>
	   <td width="550" style="padding-top: 10px; vertical-align: top; padding-right: 50px;" class="left-column">
		<?php
      if (isset($campaign_id)) {
        $url_query = array('pk_campaign' => $campaign_id);
      } else {
        $url_query = array();
      }
		  $elements_no = sizeof($items);
		  // Delete title 'News'.
		  unset($items[0]);
		  foreach ($items as $idx => $item) {
			  if ($item['#entity_type'] == 'taxonomy_term' && ($idx+1 <= $elements_no)) {
			    if (($idx == $elements_no-1) && ($items[$idx]['#entity_type'] == 'taxonomy_term')) {
				    continue;
			    } else if (($items[$idx+1]['#entity_type'] == 'taxonomy_term')) {
				    continue;
			    } else {
				    if ($idx != 0) {?>
				  <table border="0" cellpadding="0" cellspacing="0" class="blue-line" width="100%">
					<tbody>
					<tr>
					  <td style="padding-top: 15px;"></td>
					</tr>
					<tr>
					  <td width="100%" style="background-color:#003399; height: 4px;" valign="top"></td>
					</tr>
					</tbody>
				  </table>
          <?php
          }
				  print(render($item));
			  }
			} else {
			  if ($idx != 1 && $item["#view_mode"] == "highlights_item") { ?>

				<?php
					/*	<table border="0" cellpadding="0" cellspacing="0" width="100%">
				  <tbody>
				  <tr>
					<td style="border-bottom:2px dotted #CFDDEE;padding-top:0px;"></td>
				  </tr>
				  <tr>
					<td></td>
				  </tr>
				  </tbody>
				</table>*/
					?>
			  <?php
			  }
			  print(render($item));
			}
		  }
		?>
	  </td>
	  <td width="180" style="vertical-align: top; padding-top: 10px; padding-right: 0px;" class="right-column">
		<?php
		if (!empty($events) && sizeof($events) > 1) {
			foreach ($events as $item) {
			  print(render($item));
			}
		}
		?>
	  </td>
	</tr>
  </tbody>
</table>