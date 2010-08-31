<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function mn_searchlight_context_default_contexts() {
  $export = array();
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'mn_searchlight_search';
  $context->description = '';
  $context->tag = 'Search';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'mn_news' => 'mn_news',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'searchlight-facets_mn_searchlight_syndication' => array(
          'module' => 'searchlight',
          'delta' => 'facets_mn_searchlight_syndication',
          'region' => 'right',
          'weight' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  $export['mn_searchlight_search'] = $context;
  return $export;
}
