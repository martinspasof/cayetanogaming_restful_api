function search_by_candidate_id(request_url){
    var candidate_id = $("#candidate_id").val();  
    request_url = request_url+'/'+candidate_id;

    window.location.replace(request_url);
}



