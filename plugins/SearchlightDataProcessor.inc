<?php

/**
 * Extension of the FeedsDataProcessor class which makes searchlight aware of
 * imported items.
 */
class SearchlightDataProcessor extends FeedsDataProcessor {
  /**
   * Call the parent class implementation and then attempt to sync the search
   * table.
   *
   * TODO ensure this isn't too heavy a query on large sites.
   */
  public function process(FeedsImportBatch $batch, FeedsSource $source) {
    parent::process($batch, $source);

    $table = $this->tableName();

    $result = db_query("SELECT f.id FROM $table f
       LEFT JOIN searchlight_search s ON f.id = s.id
       WHERE (s.type = '%s' OR s.type IS NULL) AND s.id IS NULL", $table);

    while ($id = db_result($result)) {
      db_query("INSERT INTO {searchlight_search} (type, id, status) VALUES ('%s', %d, %d)", $table, $id, 0);
    }
  }

  /**
   * Remove search records as well as actual aggregated items.
   */
  public function clear(FeedsBatch $batch, FeedsSource $source) {
    parent::clear($batch, $source);
    // db_query("DELETE FROM {searchlight_search} WHERE  
  }

}
