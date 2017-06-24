<script src="<?php echo WEB_ROOT ?>modules/Candidates/js/candidates.js"></script>
<div class="container">
    <h2>Candidates List</h2>
       <form style="float:right;margin-top:-70px;margin-right:80px;">
         <h2>Search candidate by Id</h2>   
         <input type='text' id="candidate_id" name="candidate_id" value=""/>
         <input type="button" value="Search" onclick="search_by_candidate_id('<?= WEB_ROOT. 'candidates/search';?>')"/>
    </form>
    <table id="candidates_list_table" class="table">
        <thead>
       <tr>
          <th>#</th>     
          <th>Name</th>
          <th>Created Date</th>
          <th>Position</th>
        </tr>
        </thead>
        
        <tbody>      
            <?php
            foreach ($this->get('get_candidates') as $key => $data) {?>
              <tr id="<?= 'candidate_' . $data['id']; ?>">
                  <td><?= $data['id']; ?></td>
                  <td><?= $data['name']; ?></td>
                  <td><?= $data['created_on']; ?></td>
                  <td><?= $data['job_position']; ?></td>                  
              </tr>
    <?php } ?>
        </tbody>
    </table>
</div>
<script>
  $(document).ready(function () {

      // DataTable
      var table = $('#candidates_list_table').DataTable({"bPaginate": true}, {"bSortable": false});

 
  });
</script>