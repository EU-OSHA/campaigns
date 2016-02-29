<?php

/**
 * Field handler to translate a moderation state into its readable form.
 */
class hwc_partner_workbench_moderation_handler_field_state extends workbench_moderation_handler_field_state {
  /**
   * Render node type as human readable name, unless using machine_name option.
   */
  function render_name($data, $values) {
    if ($this->options['machine_name'] != 1 && $data !== NULL && $data !== '') {
      if ($this->view->name == 'partner_draft_content' && in_array($data, array(OSHA_WORKFLOW_STATE_TO_BE_APPROVED, OSHA_WORKFLOW_STATE_TO_BE_REVIEWED))) {
        return t('Pending to be validated by EU-OSHA');
      }
      return t($this->sanitize_value(workbench_moderation_state_label($data)));
    }
    return $this->sanitize_value($data);
  }
}
