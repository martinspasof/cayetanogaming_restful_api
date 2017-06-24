<?php

$candidates = new Candidates();
$flag = false;
 if (isset($_GET['review']) && isset($_GET['candidates']) && isset($_GET['id']) && (($_GET['review'] == 'search') || ($_GET['review'] == 'review')) && is_numeric($_GET['id'])) {    
    $get_candidates = $candidates->getCandidates($_GET['id']);
    $flag = true;
}

    
  $get_candidates = $flag ? $get_candidates : $candidates->getCandidates();

  $candidates_list = new BaseModuleTemplater(ROOT . '/modules/Candidates/tpl/candidates_list.tpl.inc'); 
  $candidates_list->set('get_candidates', $get_candidates);
  $candidates_list->publish();

