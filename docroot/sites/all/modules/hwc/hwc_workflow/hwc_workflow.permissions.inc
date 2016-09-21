<?php

function hwc_workflow_permissions_role_partner() {
  return array(
    'create news content',
    'edit own news content',
    'edit any news content',
    'delete own news content',

    'create events content',
    'edit own events content',
    'edit any events content',
    'delete own events content',

    'edit any content in final_draft',
    'edit any content in draft',
    'moderate content from draft to final_draft',
  );
}


function hwc_workflow_permissions_role_supervisor() {
  return array(
    'create news content',
    'edit own news content',
    'edit any news content',
    'delete own news content',
    'delete any news content',

    'create events content',
    'edit own events content',
    'edit any events content',
    'delete own events content',
    'delete any events content',

    'edit any content in draft',
    'edit any content in final_draft',
    'edit any content in needs_review',

//    'moderate content from draft to final_draft',
    'moderate content from draft to needs_review',
    'moderate content from needs_review to draft',
    'moderate content from needs_review to to_be_approved',

    'view own unpublished content',

    'select content section',

    'view the administration theme',
    'access toolbar',
    'access administration pages',
    'access dashboard',
    'access content overview',

    'access content',
    'view revisions',
    'view all unpublished content',
    'access workbench access by role',

    'access hwc review tab',
    'assign cpm to node',

    'view moderation history',
    'view moderation messages'
  );
}

function hwc_workflow_permission_role_review_manager() {
  return hwc_workflow_permissions_role_supervisor() + array(
    'use workbench_moderation needs review tab',
  );
}

function hwc_workflow_permission_role_cpm() {
  return array(
    'edit own news content',
    'edit any news content',

    'edit own events content',
    'edit any events content',

    'edit any content in to_be_approved',

    'moderate content from to_be_approved to published',
    'moderate content from to_be_approved to needs_review',

    'access hwc review tab',

    'view own unpublished content',

    'view the administration theme',
    'access toolbar',
    'access administration pages',
    'access dashboard',
    'access content overview',

    'access content',
    'view revisions',
    'view all unpublished content',
    'access workbench access by role',

    'view moderation history',
    'view moderation messages',
  );
}
