function search_by_job_id(request_url){
    var job_id = $("#job_id").val();  
    request_url = request_url+'/'+job_id;
    
    window.location.replace(request_url);
}






