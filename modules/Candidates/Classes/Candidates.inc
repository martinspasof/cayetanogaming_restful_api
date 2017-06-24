<?php

class Candidates {

  function __construct($value = null) {

    switch ($value) {
      case 'get_candidates':
        $this->getCandidates();
        break;     
      default:
        break;
    }
  }
  
  public function getCandidates($id = null, $get_val = null) {
  
  $get_id = isset($id) && $id ? $id : '';
  if(isset($_GET['jobs']) && ($_GET['jobs'] == 'candidates')){ 
     $RestQuery = new RestQuery();
     $restquery = $RestQuery->rest_query();
  }
  
  $job_ids = '';  
  if(isset($restquery) && is_array($restquery) && $restquery){
    foreach ($restquery as $res){
      $job_ids .= $res['job_id'].',';
    }
  }
  
  $clause_job_ids = '';
  
  if($job_ids || $get_id){
   $clause_job_ids = $get_id ? $job_ids.$get_id : rtrim($job_ids,',');
  }
  
    $sql_get_data = "SELECT ca.*,jobs.position as job_position
                       FROM candidates as ca
                     LEFT JOIN jobs 
                     ON jobs.id = ca.job_id
                     WHERE  jobs.id IN ($clause_job_ids)
                     ORDER BY ca.name";


    $db = new Db();
    $get_data = $db->select($sql_get_data);


    return $get_data;
  }

}
