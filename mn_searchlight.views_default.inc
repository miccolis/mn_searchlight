<?php

/**
 * Implementation of hook_views_default_views().
 */
function mn_searchlight_views_default_views() {
  $views = array();

  // Exported view: mn_searchlight_term_facet
  $view = new view;
  $view->name = 'mn_searchlight_term_facet';
  $view->description = '';
  $view->tag = '';
  $view->view_php = '';
  $view->base_table = 'feeds_data_syndication';
  $view->is_cacheable = FALSE;
  $view->api_version = 2;
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('relationships', array(
    'data_taxonomy_id' => array(
      'label' => 'Relate a data record to a term tid.',
      'required' => 1,
      'id' => 'data_taxonomy_id',
      'table' => 'feeds_data_syndication',
      'field' => 'data_taxonomy_id',
      'relationship' => 'none',
    ),
    'tid' => array(
      'label' => 'Relate data_taxonomy to a term data.',
      'required' => 0,
      'id' => 'tid',
      'table' => 'data_taxonomy',
      'field' => 'tid',
      'relationship' => 'data_taxonomy_id',
    ),
  ));
  $handler->override_option('fields', array(
    'name' => array(
      'label' => 'Tags',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'link_to_taxonomy' => 0,
      'exclude' => 0,
      'id' => 'name',
      'table' => 'term_data',
      'field' => 'name',
      'relationship' => 'tid',
    ),
    'id' => array(
      'label' => 'Id',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'set_precision' => FALSE,
      'precision' => 0,
      'decimal' => '.',
      'separator' => ',',
      'prefix' => '',
      'suffix' => '',
      'exclude' => 0,
      'id' => 'id',
      'table' => 'feeds_data_syndication',
      'field' => 'id',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('access', array(
    'type' => 'none',
  ));
  $handler->override_option('cache', array(
    'type' => 'none',
  ));

  foreach (taxonomy_get_vocabularies() as $vocab) {
    $identifier = !empty($vocab->module) && $vocab->module !== 'taxonomy' ? $vocab->module : $vocab->vid;
    $identifier = strtr($identifier, ' -:', '___');

    /* Display: Vocabulary */
    $handler = $view->new_display('searchlight_multivalue', $vocab->name, 'searchlight_multivalue_'. $identifier);
    $handler->override_option('searchlight_multivalue', array(
      'field' => 'term_data_data_taxonomy_tid',
      'label_field' => 'term_data_data_taxonomy_name',
      'override' => array(
        'name' => 'term_data_tid_'. $identifier,
        'label' => $vocab->name,
      ),
    ));

    // If Views can handle the Taxonomy vocab module field for supporting
    // exportable vocabularies, use it.
    $data = views_fetch_data('vocabulary');
    if (isset($data['module']) && !is_numeric($identifier)) {
      $handler->override_option('filters', array(
        'module' => array(
          'id' => 'module',
          'table' => 'vocabulary',
          'field' => 'module',
          'value' => array($vocab->module => $vocab->module),
          'relationship' => 'tid',
        ),
      ));
    }
    else {
      $handler->override_option('filters', array(
        'vid' => array(
          'id' => 'vid',
          'table' => 'term_data',
          'field' => 'vid',
          'value' => array($vocab->vid => $vocab->vid),
          'relationship' => 'tid',
        ),
      ));
    }
  }
  $views[$view->name] = $view;

  // Trash Facet
  $view = new view;
  $view->name = 'mn_searchlight_trash';
  $view->description = '';
  $view->tag = '';
  $view->view_php = '';
  $view->base_table = 'feeds_data_syndication';
  $view->is_cacheable = FALSE;
  $view->api_version = 2;
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('relationships', array(
    'vapi_feeds_data_syndication_id' => array(
      'label' => 'Votes',
      'required' => 0,
      'votingapi' => array(
        'value_type' => 'mark',
        'tag' => 'trash',
      ),
      'current_user' => 0,
      'id' => 'vapi_feeds_data_syndication_id',
      'table' => 'feeds_data_syndication',
      'field' => 'vapi_feeds_data_syndication_id',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('fields', array(
    'value' => array(
      'label' => '',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'set_precision' => 0,
      'precision' => '0',
      'decimal' => '.',
      'separator' => ',',
      'prefix' => '',
      'suffix' => '',
      'appearance' => NULL,
      'exclude' => 0,
      'id' => 'value',
      'table' => 'votingapi_vote',
      'field' => 'value',
      'relationship' => 'vapi_feeds_data_syndication_id',
    ),
  ));
  $handler->override_option('access', array(
    'type' => 'none',
  ));
  $handler->override_option('cache', array(
    'type' => 'none',
  ));
  $handler->override_option('distinct', 1);
  $handler = $view->new_display('searchlight_multivalue', 'Searchlight multivalue', 'searchlight_multivalue_1');
  $handler->override_option('searchlight_multivalue', array(
    'field' => 'votingapi_vote_feeds_data_syndication_mark_trash_value',
    'label_field' => 'votingapi_vote_feeds_data_syndication_mark_trash_value',
  ));
  $views[$view->name] = $view;

  return $views;
}
