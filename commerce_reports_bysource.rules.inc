<?php

/**
 * Implements hook_rules_action_info().
 */
function commerce_reports_bysource_rules_action_info() {
  return array(
    // Add rules action which classfy by source referral.
    'commerce_reports_bysource_classify_order' => array(
      'label' => t('Classify order by source referral'),
      'parameter' => array(
        'commerce_order_bysource' => array(
          'type' => 'commerce_order',
          'label' => t('Order in checkout'),
        ),
      ),
      'group' => t('Commerce reports by source'),
      'callback' => array(
        'execute' => 'commerce_reports_bysource_classify_order'
      ),
    ),
  );
}
