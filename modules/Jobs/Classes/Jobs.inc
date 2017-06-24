<?php

class Jobs {

  function __construct($value = null) {

    switch ($value) {
      case 'get_jobs':
        $this->getJobs();
        break;
      default:
        break;
    }
  }

  public function getJobs($id = null, $get_val = null) {

    if (isset($_GET['jobs']) && ($_GET['jobs'] == 'jobs')) {
      $RestQuery = new RestQuery();
      $restquery = $RestQuery->rest_query();

      return $restquery;
    }

    $sql_get_data = "SELECT * 
                       FROM jobs
                     ORDER BY id";


    $db = new Db();
    $get_data = $db->select($sql_get_data);


    return $get_data;
  }

}
