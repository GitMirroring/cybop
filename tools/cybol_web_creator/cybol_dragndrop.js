

$(function() {

var methods = [];
var listcounter = 0;


  $("#buttonAjax").click(function(){
        $.ajax({
              type: "POST",
              url: "cybol_web_creator.php",
              data: {fname:methods}
              }).done(function( result ) {
              $("#output").html(result);
        });
    });

$('#popupBoxClose').click( function() {
     unloadPopupBox();
});

$('#container').click( function() {
    unloadPopupBox();
});

$('#listcounter_1').live("click", function() {
    loadPopupBox();
});
//    $("form").submit(function () {


$("form").live("submit", function()
{

   var type = $("#type").val();
   var method_name = $("#method_name").val();
   var model = $("#model").val();
   var channel = $("#channel").val();
   var encoding = $("#encoding").val();
   var language = $("#language").val();
   var format = $("#format").val();
   var abstraction = $("#abstraction").val();
   var counterExist = 0;

// if listcounter exist in array = change array
 for(var key in methods)
 {
   if(key == listcounter)
     {   // change values of array
         delete methods[""+listcounter+""];

         inputvalues["type"] = type;
         inputvalues["name"] = method_name;
         inputvalues["model"] = model;
         inputvalues["channel"] = channel;
         inputvalues["encoding"] = encoding;
         inputvalues["language"] = language;
         inputvalues["format"] = format;
         methods[""+listcounter+""] = inputvalues;
         counterExist = 1;
         return;
     }
 }

   if(counterExist == 0)
   {
         //var inputvalues = new Array( type, method_name, model, channel, encoding, language, format);
    var inputvalues = new Array();
    inputvalues.push(type, method_name, model, channel, encoding, language, format, abstraction);
     methods[listcounter] = inputvalues;
   }

 unloadPopupBox();

 $( "#korb ol" ).find( "#listcount_"+listcounter+"" ).html( "<li>"+method_name+"</li>" );

 return false;
});

function unloadPopupBox() {    // TO Unload the Popupbox
       $('#popup_box').fadeOut("slow");
            $("#container").css({ // this is just for style
                "opacity": "1"
            });
        }
function loadPopupBox() {    // To Load the Popupbox
  $('#popup_box').fadeIn("slow");
  $('#method_name').val( "" );
  $('#model').val( "" );
  $('#format').val( "" );
  $('#abstraction').val( "" );
  $("#container").css({ // this is just for style
    "opacity": "0.3"
   });
}

  // Drag-Elemente erstellen
    $( "#list li" ).draggable({
      appendTo: "body",
      helper: "clone",
      cursorAt: { cursor: "move", top: 5, left: 0 }
    });
    // wk als Dropzone und Liste sortierbar machen
    $( "#korb ol" ).droppable({
      activeClass: "ui-state-default",
      hoverClass: "ui-state-hover",
      accept: ":not(.ui-sortable-helper)",
      drop: function( event, ui ) {
      $( this ).find( ".placeholder" ).remove();
      listcounter = listcounter + 1;

      $( "<span id=\"listcount_"+listcounter+"\"></span>" ).html( "<li></li>" ).appendTo( this );
     // $( "#korb ol" ).find( "#listcount_"+listcounter ).html( "<li></li>" ).appendTo( this );

      $( "#listcount_"+listcounter ).find( "li" ).text( "Method" );
     // $( "<span id=\"dropMarker\"></span>" ).text("Property").appendTo( this );

        // popup
        loadPopupBox();

      }
    }).sortable({
      items: "li:not(.placeholder)",
      sort: function() {
        $( this ).removeClass( "ui-state-default" );
        $("ul, li").disableSelection();
      }
    });
    // Zone zum Elemente löschen
    $("#trash").droppable({
  accept: "#korb li",
  hoverClass: 'hovered',
  drop: function( event, ui ) {
        entfernen( ui.draggable );
      }
  });
  });
// Löschen Funktion
function entfernen($item) {
    $item.remove();
  }

  $('#dropMarker').droppable( {
    drop: handleDropEvent
  } );

  function handleDropEvent( event, ui ) {
  var draggable = ui.draggable;
}