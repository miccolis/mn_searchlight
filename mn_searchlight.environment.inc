<?php

/**
 * Implementation of hook_searchlight_default_environments().
 */
function mn_searchlight_searchlight_default_environments() {
  $export = array();
  $searchlight_environment = new SearchlightEnvironment;
  $searchlight_environment->disabled = FALSE; /* Edit this to true to make a default searchlight_environment disabled initially */
  $searchlight_environment->api_version = 1;
  $searchlight_environment->name = 'mn_searchlight_syndication';
  $searchlight_environment->view_display = 'mn_news:page_2';
  $searchlight_environment->facets = array(
    'feeds_data_syndication_timestamp' => array(
      'enabled' => 1,
      'weight' => '0',
      'label' => '',
      'items' => '5',
      'granularity' => 'month',
      'date_format' => 'F, Y',
    ),
    'search_query' => array(
      'enabled' => 1,
      'weight' => '0',
      'label' => '',
      'items' => 1,
    ),
  );
  $searchlight_environment->options = array(
    'facets_label' => 'Search facets',
  );

  $export['mn_searchlight_syndication'] = $searchlight_environment;
  return $export;
}
