<table border="0" cellpadding="10" cellspacing="0" class="category-name" width="100%">
  <tbody>
    <tr>
      <td style="font-family: Oswald, Arial, sans-serif; font-weight: bold; font-size: 20px; padding-left: 0px; padding-right: 0px; padding-top: 0px; color: #749b00;">
        <?php
          $label = "";
          if (isset($name_field[$language])) {
            $label = $name_field[$language][0]['safe_value'];
            print($label);
          } else {
            $label = $name_field[0]['safe_value'];
            print($label);
          }
        ?>
      </td>
    </tr>
  </tbody>
</table>