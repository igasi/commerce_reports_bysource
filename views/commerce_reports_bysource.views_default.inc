<?php

/*
 * Implementation of hook_views_default_views().
 */
function commerce_reports_bysource_views_default_views() {
  /**
    * Create view test
    */ 

	$view = new view();
	$view->name = 'view_test';
	$view->description = '';
	$view->tag = 'default';
	$view->base_table = 'commerce_order';
	$view->human_name = 'View test';
	$view->core = 7;
	$view->api_version = '3.0';
	$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

	/* Display: Master */
	$handler = $view->new_display('default', 'Master', 'default');
	$handler->display->display_options['title'] = 'View test';
	$handler->display->display_options['use_more_always'] = FALSE;
	$handler->display->display_options['access']['type'] = 'none';
	$handler->display->display_options['cache']['type'] = 'none';
	$handler->display->display_options['query']['type'] = 'views_query';
	$handler->display->display_options['exposed_form']['type'] = 'basic';
	$handler->display->display_options['pager']['type'] = 'full';
	$handler->display->display_options['pager']['options']['items_per_page'] = '10';
	$handler->display->display_options['style_plugin'] = 'table';
	/* Field: Commerce Order: Order ID */
	$handler->display->display_options['fields']['order_id']['id'] = 'order_id';
	$handler->display->display_options['fields']['order_id']['table'] = 'commerce_order';
	$handler->display->display_options['fields']['order_id']['field'] = 'order_id';
	/* Filter criterion: Commerce Order: Order type */
	$handler->display->display_options['filters']['type']['id'] = 'type';
	$handler->display->display_options['filters']['type']['table'] = 'commerce_order';
	$handler->display->display_options['filters']['type']['field'] = 'type';
	$handler->display->display_options['filters']['type']['value'] = array(
	  'commerce_order' => 'commerce_order',
	);

	/* Display: Page view test */
	$handler = $view->new_display('page', 'Page view test', 'page');
	$handler->display->display_options['path'] = 'view-test';

	return $views;
}