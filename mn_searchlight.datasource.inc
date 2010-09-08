<?php

/**
 * Implementation of hook_searchlight_default_datasources().
 */
function mn_searchlight_searchlight_default_datasources() {
  $export = array();
  $searchlight_datasource = new SearchlightDatasource;
  $searchlight_datasource->disabled = FALSE; /* Edit this to true to make a default searchlight_datasource disabled initially */
  $searchlight_datasource->api_version = 1;
  $searchlight_datasource->name = 'mn_searchlight_syndication';
  $searchlight_datasource->base_table = 'feeds_data_syndication';
  $searchlight_datasource->fields = array(
    'feeds_data_syndication_title' => array(
      'label' => 'Syndication: Title (title)',
      'datatype' => 'text',
      'table' => 'feeds_data_syndication',
      'field' => 'title',
      'name' => 'feeds_data_syndication_title',
      'usage' => 'content',
    ),
    'feeds_data_syndication_description' => array(
      'label' => 'Syndication: Description (description)',
      'datatype' => 'text',
      'table' => 'feeds_data_syndication',
      'field' => 'description',
      'name' => 'feeds_data_syndication_description',
      'usage' => 'content',
    ),
    'feeds_data_syndication_timestamp' => array(
      'label' => 'Syndication: Timestamp (timestamp)',
      'datatype' => 'timestamp',
      'table' => 'feeds_data_syndication',
      'field' => 'timestamp',
      'name' => 'feeds_data_syndication_timestamp',
      'usage' => 'attribute',
    ),
    'votingapi_vote_feeds_data_syndication_mark_trash_value' => array(
      'label_field' => array(),
      'base_table' => 'feeds_data_syndication',
      'view' => 'mn_searchlight_trash:searchlight_multivalue_1',
      'label' => 'Votes: Value (value)',
      'datatype' => 'float',
      'table' => 'votingapi_vote',
      'field' => 'value',
      'name' => 'votingapi_vote_feeds_data_syndication_mark_trash_value',
      'usage' => 'multivalue',
    ),
  );

  $view = views_get_view('mn_searchlight_term_facet');
  foreach ($view->display as $display) {
    if ($display->display_plugin == 'searchlight_multivalue') {
      $options = $display->display_options['searchlight_multivalue'];
      $searchlight_datasource->fields[$options['override']['name']] = array(
        'label_field' => array(
          'label' => $options['override']['label'],
          'datatype' => 'text',
          'table' => 'term_data',
          'field' => 'name',
          'name' => 'term_data_data_taxonomy_name',
          'usage' => 'multivalue',
        ),
        'base_table' => 'feeds_data_syndication',
        'view' => $view->name .':'. $display->id,
        'label' => $options['override']['label'],
        'datatype' => 'int',
        'table' => 'term_data',
        'field' => 'tid',
        'name' => $options['override']['name'],
        'usage' => 'multivalue',
      );
    }
  }

  $searchlight_datasource->filters = array();
  $searchlight_datasource->options = array(
    'node_access' => TRUE,
  );

  $export['mn_searchlight_syndication'] = $searchlight_datasource;
  return $export;
}
