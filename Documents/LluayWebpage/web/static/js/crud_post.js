$(function(){
    var url = "http://127.0.0.1:8080/posts";
    var urlDistricts = "http://127.0.0.1:8080/districts";
    var urlCategories = "http://127.0.0.1:8080/categories";

    $("#grid").dxDataGrid({
        dataSource: DevExpress.data.AspNet.createStore({
            key: "id",
            loadUrl: url ,
            insertUrl: url ,
            updateUrl: url ,
            deleteUrl: url ,
            onBeforeSend: function(method, ajaxOptions) {
                ajaxOptions.xhrFields = { withCredentials: true };
            }
        }),
        editing: {
            allowUpdating: true,
            allowDeleting: true,
            allowAdding: true
        },
        remoteOperations: {
            sorting: true,
            paging: true
        },
        paging: {
            pageSize: 12
        },
        pager: {
            showPageSizeSelector: true,
            allowedPageSizes: [8, 12, 20]
        },
        columns: [{
            dataField: "id",
            dataType: "number",
            allowEditing: false
        }, {
            dataField: "category_id",
            lookup: {
                dataSource: DevExpress.data.AspNet.createStore({
                    key: "id",
                    loadUrl: urlCategories ,
                    onBeforeSend: function(method, ajaxOptions) {
                        ajaxOptions.xhrFields = { withCredentials: true };
                    }
                }),
                displayExpr: "name",
                valueExpr: "id"
            }
        }, {
            dataField: "district_id",
            lookup: {
                dataSource: DevExpress.data.AspNet.createStore({
                    key: "id",
                    loadUrl: urlDistricts ,
                    onBeforeSend: function(method, ajaxOptions) {
                        ajaxOptions.xhrFields = { withCredentials: true };
                    }
                }),
                displayExpr: "name",
                valueExpr: "id"
            }
        }, {
            dataField: "title"
        }, {
            dataField: "content"
        }, {
            dataField: "date",
            allowEditing: false
        }
        ],
    }).dxDataGrid("instance");
});


