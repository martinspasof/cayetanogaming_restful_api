<?php 

define('ROOT', dirname($_SERVER['SCRIPT_FILENAME']));
$WEB_ROOT = "http://" . $_SERVER['HTTP_HOST'] . dirname($_SERVER['PHP_SELF']) . "/";
define('WEB_ROOT', $WEB_ROOT);

include ROOT . '/html/header.inc';
require_once("modules/AutoLoader/Classes/AutoLoader.inc");
require './Db.inc';
include ROOT . '\modules\Menu\Controllers\MenuController.inc';

if( (isset($_GET) && empty($_GET) ) || ( (isset($_GET['jobs']) && ($_GET['jobs'] == 'jobs')))){
  include ROOT . '\modules\Jobs\Controllers\JobsController.inc';
}else{
  include ROOT . '\modules\Candidates\Controllers\CandidatesController.inc';
}

include ROOT . '/html/footer.inc';

