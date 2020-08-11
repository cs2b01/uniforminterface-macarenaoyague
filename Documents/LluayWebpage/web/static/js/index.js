
function createDistricts(){
        $.ajax({
            url:'/districts',
            type:'GET',
            contentType: 'application/json',
            dataType:'json',
            success: function(response){
                var i = 0;
                $('#districts').empty();
                $.each(response, function(){
                    a = '<div><span  onclick="getPostsDistrict(' + response[i].id + response[i].name + ') style="color:rgb(175, 112, 8);">';
                    a = a + response[i].name + '</span></div>';
                    $('#districts').append(a);
                    i = i + 1;
                });
            },
        });
}

function getPostsDistrict(districtId,districtName){
        alert(9);
        $('#principal').hide();
        $('#disctrictPosts').show();
        $.ajax({
            url:'/posts',
            type:'GET',
            contentType: 'application/json',
            dataType:'json',
            success: function(response){
                var i = 0;
                $.each(response, function(){
                    if (response[i].district_id==districtId)
                    {
                        a = '<div><span onclick="getPostDetails(' + response[i].content + ') >';
                        a = a + response[i].title + '</span>';
                        a = a + '<span>' + districtName + '</span><';
                        a = a + '<span>' + response[i].date + '</span>';
                        $('#disctrictPosts').append(a);
                    }
                    i = i + 1;
                });
            },
        });
}

function getPostDetails(idPost){
        $('#disctrictPosts').hide();
        $('#postInfo').show();
        $.ajax({
            url:'/posts',
            type:'GET',
            contentType: 'application/json',
            dataType:'json',
            success: function(response){
                var i = 0;
                $.each(response, function(){
                    if (response[i].id==districtId)
                    {
                        a = '<div><span onclick="getPostDetails(' + response[i].id + ') >';
                        a = a + response[i].title + '</span>';
                        a = a + '<span>' + districtName + '</span></div>';
                        a = a + '<span>' + response[i].date + '</span></div>';
                        $('#disctrictPosts').append(a);
                    }
                    i = i + 1;
                });
            },
        });
}









