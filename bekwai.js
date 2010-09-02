/**
 * Theme behavior for collapsing faceted search lists.
 */
Drupal.behaviors.bekwai = function(context) {
  var first = $('.block-searchlight .item-list:has(.searchlight-facet-facets):not(.bekwaiProcessed)').get(0);
  $(first).addClass('expanded');

  $('.block-searchlight .item-list:not(.bekwaiProcessed)').each(function() {
    var facet = $(this);
    if ($('.searchlight-facet-active', this).size() > 0) {
      $(this).addClass('expanded');
    }
    else {
      $('h3', this).each(function() {
        $(this).click(function() {
          facet.siblings('.item-list:has(.searchlight-facet-facets)').removeClass('expanded');
          facet.toggleClass('expanded');
        });
      });
    }
  }).addClass('bekwaiProcessed');
};
