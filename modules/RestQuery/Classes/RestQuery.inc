<?php

class RestQuery {

  //Enter details of your database
  const DB_SERVER = "localhost";
  const DB_USER = "root";
  const DB_PASSWORD = "";
  const DB = "job_offers";

  public function rest_query() {
//Array ( [candidates] => index.php [search] => 1 
 // [id] => 1 [review] => 1 [list] => 1 [jobs] => jobs ) GET
// get the HTTP method, path and body of the request
   
    $id = '';
    $request_table = 'jobs';
    $parameter2 = '';
    if(isset($_GET['candidates']) && isset($_GET['list'])){
      $request_table = $_GET['candidates'];
      $parameter2 = $_GET['list'];
    } 
    if(isset($_GET['candidates']) && isset($_GET['review']) && isset($_GET['id'])){
      $request_table = $_GET['candidates'];
      $parameter2 = $_GET['review'];
      $id = $_GET['id'];
    } 
    if(isset($_GET['candidates']) && isset($_GET['search']) && isset($_GET['id'])){
      $request_table = $_GET['candidates'];
      $parameter2 = $_GET['search'];
      $id = $_GET['id'];
    } 
    
    if(isset($_GET['jobs']) && isset($_GET['list'])){
      $request_table = $_GET['jobs'];
      $parameter2 = $_GET['list'];
    } 
    
    if(isset($_GET['jobs']) && isset($_GET['id'])){
      $request_table = $_GET['jobs'];
      $id = $_GET['id'];
      $parameter2 = $id;
      $id = '';
    } 
   
    
    $method = $_SERVER['REQUEST_METHOD'];
    $path_info = $request_table . '/' .$parameter2 . '/'. $id . '/';

//print_r($_SERVER['PATH_INFO']);
    // $request = explode('/', trim($_SERVER['PATH_INFO'], '/'));
    $request = explode('/', trim($path_info, '/'));
    $input = json_decode(file_get_contents('php://input'), true);

// connect to the mysql database
    $link = mysqli_connect(self::DB_SERVER, self::DB_USER, self::DB_PASSWORD, self::DB);
    mysqli_set_charset($link, 'utf8');

// retrieve the table and key from the path
    $table = preg_replace('/[^a-z0-9_]+/i', '', array_shift($request));
    $key = array_shift($request) + 0;

    if (isset($input)) {
// escape the columns and values from the input object
      $columns = preg_replace('/[^a-z0-9_]+/i', '', array_keys($input));
      $values = array_map(function ($value) use ($link) {
        if ($value === null){
          return null;
        }else{
         return mysqli_real_escape_string($link, (string) $value);
        }
      }, array_values($input));

// build the SET part of the SQL command
      $set = '';
      for ($i = 0; $i < count($columns); $i++) {
        $set .= ($i > 0 ? ',' : '') . '`' . $columns[$i] . '`=';
        $set .= ($values[$i] === null ? 'NULL' : '"' . $values[$i] . '"');
      }
    }
    
    
    
// create SQL based on HTTP method
    switch ($method) {
      case 'GET':
        if($parameter2 == 'list'){
          $key = '';
        }else if($parameter2 == 'review'){
          $key = $id;
        }else if(is_numeric($parameter2)){
          $key = $parameter2;
        }
        $sql = "select * from `$table`" . ($key ? " WHERE id=$key" : '');
        break;
      case 'PUT':
        $sql = "update `$table` set $set where id=$key";
        break;
      case 'POST':
        $sql = "insert into `$table` set $set";
        break;
      case 'DELETE':
        $sql = "delete `$table` where id=$key";
        break;
    }

// excecute SQL statement
    $result = mysqli_query($link, $sql);

// die if SQL statement failed
    if (!$result) {
      http_response_code(404);
      die(mysqli_error());
    }

    $_result = "";
// print results, insert id or affected row count
    if ($method == 'GET') {
      if (!$key)
        $_result .= '[';
      for ($i = 0; $i < mysqli_num_rows($result); $i++) {
        $_result .= ($i > 0 ? ',' : '') . json_encode(mysqli_fetch_object($result));
      }
      if (!$key)
        $_result .= ']';
    } elseif ($method == 'POST') {
      $_result = mysqli_insert_id($link);
      return $_result;
    }
    else {
      $_result = mysqli_affected_rows($link);
      return $_result;
    }
   
    return json_decode($_result, true);
// close mysql connection
    mysqli_close($link);
  }
  

}
