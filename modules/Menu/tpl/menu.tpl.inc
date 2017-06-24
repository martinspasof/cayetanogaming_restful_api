<?php
$class_active_menu_id_1 = 'class="active"';
$class_active_menu_id_2 = '';
$check_candidate_list = isset($_GET['review']) && isset($_GET['candidates']) && isset($_GET['id']) && (($_GET['review'] == 'search') || ($_GET['review'] == 'review')) && is_numeric($_GET['id']);
if(isset($_GET['jobs']) || isset($_GET['candidates'])){
  $class_active_menu_id_1 = isset($_GET['jobs']) && ($_GET['jobs'] == 'jobs') ? 'class="active"' : '';
  $class_active_menu_id_2 = (isset($_GET['jobs']) && ($_GET['jobs'] == 'candidates') || $check_candidate_list) ? 'class="active"' : '';
}
?>
<ul id="menu_nav" style="margin: 5px; margin-bottom:30px;margin-left: 40px;" class="nav nav-pills">
  <li id="menu_id_1" role="presentation" <?php echo $class_active_menu_id_1; ?>>
      <a href="<?= WEB_ROOT. 'jobs/list'; ?>">Jobs List</a>
  </li>
  <li id="menu_id_2" role="presentation" <?php echo $class_active_menu_id_2; ?>>
      <a href="<?= WEB_ROOT. 'candidates/list'; ?>">Candidates List</a>
  </li>
  <div style="float:right;margin-right: 20px;font-weight: bold;">
 
  </div>
  <br/>
  
  
</ul>

