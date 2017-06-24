<script src="<?php echo WEB_ROOT ?>modules/Jobs/js/jobs.js"></script>
<div class="container">
    <h2>Jobs List</h2>
    <form style="float:right;margin-top:-70px;margin-right:80px;">
         <h2>Search Job by Id</h2>   
         <input type='text' id="job_id" name="job_id" value=""/>
         <input type="button" value="Search" onclick="search_by_job_id('<?= WEB_ROOT. 'jobs';?>')" />
    </form>
    <table id="jobs_list_table" class="table">
        <thead>
            <tr>
                <th>#</th>
                <th>Position</th>
                <th>Created Date</th>
                <th>Description</th>
            </tr>
        </thead>

        <tbody>      
            <?php foreach ($this->get('get_jobs') as $key => $data) { ?>
              <tr id="<?= 'jobs_' . $data['id']; ?>">
                  <td><?= $data['id']; ?></td>
                  <td><?= $data['position']; ?></td>
                  <td><?= $data['created_on']; ?></td>
                  <td><?= $data['description']; ?></td>                  
              </tr>
            <?php } ?>
        </tbody>
    </table>
</div>
<script>
  $(document).ready(function () {

      // DataTable
      var table = $('#jobs_list_table').DataTable({"bPaginate": true}, {"bSortable": false});


  });
</script>