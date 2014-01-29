<?php

/**
 * Implements hook_default_rules_configuration().
 */
function commerce_reports_bysource_default_rules_configuration() {
  $rule = rules_reaction_rule();
  $rule->label = 'Classify order by source referral';
  $rule->active = TRUE;
  $rule->event('commerce_checkout_complete')
          ->action('commerce_reports_bysource_classify', array('commerce_order:select' => 'commerce_order')
  );
  $configs['commerce_reports_bysource_rule_classify_order'] = $rule;
  return $configs;
}
