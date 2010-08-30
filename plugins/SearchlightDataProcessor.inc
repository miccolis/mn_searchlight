<?php

/**
 * Extension of the FeedsDataProcessor class which makes searchlight aware of
 * imported items.
 */
class SearchlightDataProcessor extends FeedsDataProcessor {
  /**
   * Call the parent class implementation and then attempt to sync the search
   * table.
   */
  public function process(FeedsImportBatch $batch, FeedsSource $source) {
    parent::process($batch, $source);
    watchdog('status', 'searchlight post ran');
  }
}
