
function loadData(){
    home();
    loadCategories();
    loadDistricts();
}

function home(){

}

function loadCategories(){
        $.ajax({
            url:'/loadCategories',
            type:'GET',
            contentType: 'application/json',
            dataType:'json',
            success: function(response){
                //alert(JSON.stringify(response));
                var i = 0;
                $.each(response, function()
                {
                    f = '<label onclick=loadPostsbyCategory('+response[i].id+') >';
                    f = f + response[i].name;
                    f = f + '</label>';
                    $('#categories').append(f);
                }
                i = i+1;
            });
            },
            error: function(response){
                alert(JSON.stringify(response));
            }
        });
}

function loadPostsbyCategory(id_category){
        $.ajax({
        url:'/category/'+id_category,
        type:'GET',
        contentType: 'application/json',
        dataType:'json',
        success: function(response){
                //alert(JSON.stringify(response));
q                var i = 0;
                $.each(response, function()
                {
                    f = '<div onclick=loadInfoPost('+response[i].id+') >';
                    f = f + response[i].name;
                    f = f + '</div>';
                    $('#CREARRRR ESTOOOO!!!!').append(f);
                }
                i = i+1;
            });
            },
        error: function(response){
            alert(JSON.stringify(response));
        }
    });

}

function loadDistricts(){
loadPostsbyDistrict()
}


function loadPostsbyDistrict(id_district){
}

function loadInfoPost(id_post){

}
