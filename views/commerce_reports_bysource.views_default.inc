<?php

/*
 * Implementation of hook_views_default_views().
 */
function commerce_reports_bysource_views_default_views() {
  /**
    * Create view Sales by source reports
    */ 

	$view = new view();
$view->name = 'sales_by_source_reports';
$view->description = 'View commerce daily and monthly sales totals.';
$view->tag = 'commerce_reports';
$view->base_table = 'commerce_order';
$view->human_name = 'Sales by source reports';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Sales report';
$handler->display->display_options['css_class'] = 'commerce-reports';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['group_by'] = TRUE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['access']['perm'] = 'access commerce reports';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['query']['options']['query_comment'] = FALSE;
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['exposed_form']['options']['submit_button'] = 'Refresh report';
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'sales_data' => 'sales_data',
  'order_id' => 'order_id',
  'commerce_order_total' => 'commerce_order_total',
  'commerce_order_total_1' => 'commerce_order_total_1',
);
$handler->display->display_options['style_options']['default'] = 'sales_data';
$handler->display->display_options['style_options']['info'] = array(
  'sales_data' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'order_id' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'commerce_order_total' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'commerce_order_total_1' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
);
/* Field: COUNT(Commerce Order: Order ID) */
$handler->display->display_options['fields']['order_id']['id'] = 'order_id';
$handler->display->display_options['fields']['order_id']['table'] = 'commerce_order';
$handler->display->display_options['fields']['order_id']['field'] = 'order_id';
$handler->display->display_options['fields']['order_id']['group_type'] = 'count';
$handler->display->display_options['fields']['order_id']['label'] = 'Number of Orders';
/* Field: SUM(Commerce Order: Order total) */
$handler->display->display_options['fields']['commerce_order_total']['id'] = 'commerce_order_total';
$handler->display->display_options['fields']['commerce_order_total']['table'] = 'field_data_commerce_order_total';
$handler->display->display_options['fields']['commerce_order_total']['field'] = 'commerce_order_total';
$handler->display->display_options['fields']['commerce_order_total']['group_type'] = 'sum';
$handler->display->display_options['fields']['commerce_order_total']['label'] = 'Total Revenue';
$handler->display->display_options['fields']['commerce_order_total']['click_sort_column'] = 'amount';
$handler->display->display_options['fields']['commerce_order_total']['settings'] = array(
  'calculation' => FALSE,
);
$handler->display->display_options['fields']['commerce_order_total']['group_column'] = 'amount';
$handler->display->display_options['fields']['commerce_order_total']['group_columns'] = array(
  'currency_code' => 'currency_code',
);
/* Field: AVG(Commerce Order: Order total) */
$handler->display->display_options['fields']['commerce_order_total_1']['id'] = 'commerce_order_total_1';
$handler->display->display_options['fields']['commerce_order_total_1']['table'] = 'field_data_commerce_order_total';
$handler->display->display_options['fields']['commerce_order_total_1']['field'] = 'commerce_order_total';
$handler->display->display_options['fields']['commerce_order_total_1']['group_type'] = 'avg';
$handler->display->display_options['fields']['commerce_order_total_1']['label'] = 'Average Order';
$handler->display->display_options['fields']['commerce_order_total_1']['click_sort_column'] = 'amount';
$handler->display->display_options['fields']['commerce_order_total_1']['settings'] = array(
  'calculation' => FALSE,
);
$handler->display->display_options['fields']['commerce_order_total_1']['group_column'] = 'amount';
$handler->display->display_options['fields']['commerce_order_total_1']['group_columns'] = array(
  'currency_code' => 'currency_code',
);
/* Filter criterion: Commerce Order: Order state */
$handler->display->display_options['filters']['state']['id'] = 'state';
$handler->display->display_options['filters']['state']['table'] = 'commerce_order';
$handler->display->display_options['filters']['state']['field'] = 'state';
$handler->display->display_options['filters']['state']['value'] = array(
  'pending' => 'pending',
  'completed' => 'completed',
);
$handler->display->display_options['filters']['state']['exposed'] = TRUE;
$handler->display->display_options['filters']['state']['expose']['operator_id'] = 'state_op';
$handler->display->display_options['filters']['state']['expose']['label'] = 'Order statuses';
$handler->display->display_options['filters']['state']['expose']['operator'] = 'state_op';
$handler->display->display_options['filters']['state']['expose']['identifier'] = 'state';
$handler->display->display_options['filters']['state']['expose']['multiple'] = TRUE;

/* Display: Sales by source reports */
$handler = $view->new_display('page', 'Sales by source reports', 'page');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'Sales by source report';
$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'field_reports_bysource' => 'field_reports_bysource',
  'order_id' => 'order_id',
  'commerce_order_total' => 'commerce_order_total',
  'commerce_order_total_1' => 'commerce_order_total_1',
);
$handler->display->display_options['style_options']['default'] = '-1';
$handler->display->display_options['style_options']['info'] = array(
  'field_reports_bysource' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'order_id' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'commerce_order_total' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'commerce_order_total_1' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
);
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Commerce Order: Reports by source */
$handler->display->display_options['fields']['field_reports_bysource']['id'] = 'field_reports_bysource';
$handler->display->display_options['fields']['field_reports_bysource']['table'] = 'field_data_field_reports_bysource';
$handler->display->display_options['fields']['field_reports_bysource']['field'] = 'field_reports_bysource';
$handler->display->display_options['fields']['field_reports_bysource']['label'] = 'By source';
$handler->display->display_options['fields']['field_reports_bysource']['element_type'] = '0';
$handler->display->display_options['fields']['field_reports_bysource']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_reports_bysource']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_reports_bysource']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_reports_bysource']['type'] = 'taxonomy_term_reference_plain';
$handler->display->display_options['fields']['field_reports_bysource']['field_api_classes'] = TRUE;
/* Field: COUNT(Commerce Order: Order ID) */
$handler->display->display_options['fields']['order_id']['id'] = 'order_id';
$handler->display->display_options['fields']['order_id']['table'] = 'commerce_order';
$handler->display->display_options['fields']['order_id']['field'] = 'order_id';
$handler->display->display_options['fields']['order_id']['group_type'] = 'count';
$handler->display->display_options['fields']['order_id']['label'] = 'Number of Orders';
/* Field: SUM(Commerce Order: Order total) */
$handler->display->display_options['fields']['commerce_order_total']['id'] = 'commerce_order_total';
$handler->display->display_options['fields']['commerce_order_total']['table'] = 'field_data_commerce_order_total';
$handler->display->display_options['fields']['commerce_order_total']['field'] = 'commerce_order_total';
$handler->display->display_options['fields']['commerce_order_total']['group_type'] = 'sum';
$handler->display->display_options['fields']['commerce_order_total']['label'] = 'Total Revenue';
$handler->display->display_options['fields']['commerce_order_total']['click_sort_column'] = 'amount';
$handler->display->display_options['fields']['commerce_order_total']['settings'] = array(
  'calculation' => FALSE,
);
$handler->display->display_options['fields']['commerce_order_total']['group_column'] = 'amount';
$handler->display->display_options['fields']['commerce_order_total']['group_columns'] = array(
  'currency_code' => 'currency_code',
);
/* Field: AVG(Commerce Order: Order total) */
$handler->display->display_options['fields']['commerce_order_total_1']['id'] = 'commerce_order_total_1';
$handler->display->display_options['fields']['commerce_order_total_1']['table'] = 'field_data_commerce_order_total';
$handler->display->display_options['fields']['commerce_order_total_1']['field'] = 'commerce_order_total';
$handler->display->display_options['fields']['commerce_order_total_1']['group_type'] = 'avg';
$handler->display->display_options['fields']['commerce_order_total_1']['label'] = 'Average Order';
$handler->display->display_options['fields']['commerce_order_total_1']['click_sort_column'] = 'amount';
$handler->display->display_options['fields']['commerce_order_total_1']['settings'] = array(
  'calculation' => FALSE,
);
$handler->display->display_options['fields']['commerce_order_total_1']['group_column'] = 'amount';
$handler->display->display_options['fields']['commerce_order_total_1']['group_columns'] = array(
  'currency_code' => 'currency_code',
);
$handler->display->display_options['defaults']['sorts'] = FALSE;
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: Commerce Order: Order state */
$handler->display->display_options['filters']['state']['id'] = 'state';
$handler->display->display_options['filters']['state']['table'] = 'commerce_order';
$handler->display->display_options['filters']['state']['field'] = 'state';
$handler->display->display_options['filters']['state']['value'] = array(
  'pending' => 'pending',
  'completed' => 'completed',
);
$handler->display->display_options['filters']['state']['exposed'] = TRUE;
$handler->display->display_options['filters']['state']['expose']['operator_id'] = 'state_op';
$handler->display->display_options['filters']['state']['expose']['label'] = 'Order statuses';
$handler->display->display_options['filters']['state']['expose']['operator'] = 'state_op';
$handler->display->display_options['filters']['state']['expose']['identifier'] = 'state';
$handler->display->display_options['filters']['state']['expose']['multiple'] = TRUE;
/* Filter criterion: Date: Date (commerce_order) */
$handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
$handler->display->display_options['filters']['date_filter']['table'] = 'commerce_order';
$handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
$handler->display->display_options['filters']['date_filter']['operator'] = 'between';
$handler->display->display_options['filters']['date_filter']['exposed'] = TRUE;
$handler->display->display_options['filters']['date_filter']['expose']['operator_id'] = 'date_filter_op';
$handler->display->display_options['filters']['date_filter']['expose']['label'] = 'Order date';
$handler->display->display_options['filters']['date_filter']['expose']['operator'] = 'date_filter_op';
$handler->display->display_options['filters']['date_filter']['expose']['identifier'] = 'date_filter';
$handler->display->display_options['filters']['date_filter']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
);
$handler->display->display_options['filters']['date_filter']['form_type'] = 'date_popup';
$handler->display->display_options['filters']['date_filter']['default_date'] = '-12 months';
$handler->display->display_options['filters']['date_filter']['default_to_date'] = 'now';
$handler->display->display_options['filters']['date_filter']['year_range'] = '-4:+0';
$handler->display->display_options['filters']['date_filter']['date_fields'] = array(
  'commerce_order.created' => 'commerce_order.created',
);
$handler->display->display_options['path'] = 'admin/commerce/reports/bysource';
$handler->display->display_options['menu']['type'] = 'tab';
$handler->display->display_options['menu']['title'] = 'By source';
$handler->display->display_options['menu']['description'] = 'View sales by source reports.';
$handler->display->display_options['menu']['weight'] = '12';
$handler->display->display_options['menu']['name'] = 'management';
$handler->display->display_options['menu']['context'] = 0;
$handler->display->display_options['menu']['context_only_inline'] = 0;
$handler->display->display_options['tab_options']['type'] = 'normal';
$handler->display->display_options['tab_options']['title'] = 'Sales totals';
$handler->display->display_options['tab_options']['description'] = 'View daily and monthly sales totals.';
$handler->display->display_options['tab_options']['weight'] = '-10';
$handler->display->display_options['tab_options']['name'] = 'management';


	$views[$view->name] = $view;
	return $views;
}