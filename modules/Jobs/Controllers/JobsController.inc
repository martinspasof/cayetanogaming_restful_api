<?php

if (isset($_GET['list']) && $_GET['list'] && is_numeric($_GET['list'])) {
    $_GET['id'] = $_GET['list'];   
    $RestQuery = new RestQuery();
    $restquery = array();
    $restquery[0] = $RestQuery->rest_query();
}

$jobs = new Jobs();
$get_jobs = isset($restquery) ? $restquery : $jobs->getJobs();

$jobs_list = new BaseModuleTemplater(ROOT . '/modules/Jobs/tpl/jobs_list.tpl.inc');
$jobs_list->set('get_jobs', $get_jobs);
$jobs_list->publish();

