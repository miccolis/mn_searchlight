<?php

/**
 * Implementation of hook_strongarm().
 */
function mn_searchlight_strongarm() {
  $export = array();
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'searchlight_datasource_feeds_data_syndication';
  $strongarm->value = 'mn_searchlight_syndication';

  $export['searchlight_datasource_feeds_data_syndication'] = $strongarm;
  return $export;
}
