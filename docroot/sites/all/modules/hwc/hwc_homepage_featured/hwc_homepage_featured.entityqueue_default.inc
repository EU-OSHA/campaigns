<?php
/**
 * @file
 * hwc_homepage_featured.entityqueue_default.inc
 */

/**
 * Implements hook_entityqueue_default_queues().
 */
function hwc_homepage_featured_entityqueue_default_queues() {
  $export = array();

  $queue = new EntityQueue();
  $queue->disabled = FALSE; /* Edit this to true to make a default queue disabled initially */
  $queue->api_version = 1;
  $queue->name = 'featured_partner';
  $queue->label = 'Featured Partner';
  $queue->language = 'en';
  $queue->handler = 'simple';
  $queue->target_type = 'node';
  $queue->settings = array(
    'target_bundles' => array(
      'partner' => 'partner',
    ),
    'min_size' => '1',
    'max_size' => '1',
    'act_as_queue' => 1,
  );
  $export['featured_partner'] = $queue;

  return $export;
}
