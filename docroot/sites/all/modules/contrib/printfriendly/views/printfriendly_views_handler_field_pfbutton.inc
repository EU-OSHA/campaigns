<?php

/**
 * @file
 * handler class for the new field 'pfbutton'.
 */

/**
 * class definition.
 */
class printfriendly_views_handler_field_pfbutton extends views_handler_field {
  /**
   * Render function: return html output.
   */
  function render($values) {
    return printfriendly_create_button('node/' . $values->nid, FALSE);
  }

  /**
   * We just override the parent query.
   */
  function query() {
    // Do nothing, leave query blank, we render the contents.
  }
}
