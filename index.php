<?php if(!empty($_POST['command'])){
$incomingData = $_POST['command'];

if(explode(" ", $incomingData)[0] == "list"){
    $array = explode(" ",$incomingData);
    unset($array[0]);
    file_put_contents("buffer.bf", "");
    foreach($array as $city){
        file_put_contents("buffer.bf", $city, FILE_APPEND);
    }
    
    $execString = "./openWeatherCli list buffer.bf";
    exec($execString, $execOutput);
    unlink("buffer.bf");
    die(implode("<br>", $execOutput));
}
        //die($_POST['command']);
    $execString = "./openWeatherCli " . $incomingData;
    exec($execString, $execOutput);
    die(implode("<br>", $execOutput));
    
    
} else {
?><!doctype html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>OWCW</title>
    <script type="text/javascript" src="https://code.jquery.com/jquery-2.1.4.min.js"></script>
    <script type="text/javascript" src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.5/js/bootstrap.min.js"></script>
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.5/css/bootstrap.min.css" type="text/css" />
    <style type="text/css">
        .c1{
            float: left;
            margin-left: 5px;
            margin-right: 5px;
            width: 32%;
        }
        .c2 {
            float: right;
            float: left;
            margin-left: 5px;
            margin-right: 5px;
            width: 32%;
        }
        .c3{
            float: left;
            margin-left: 5px;
            margin-right: 5px;
            width: 32%;
        }
        
        .out{
            margin-top: 10%;
        }
        
        .btn{
            margin-top: 5px;
        }
        .alert{
            width: 50%;
        }
        .allof{
            margin-right: 3%;
            margin-left: 3%;
        }
    </style>
</head>
<body>
    
<nav class="navbar navbar-default">
  <div class="container-fluid">
    <div class="navbar-header">
      <a class="navbar-brand" href="#">
          <div class="form-group">
            <img alt="OWCWeb" src="...">
                         
          </div>
      </a>
      <p class="navbar-text">Web interface for openWeatherCli</p> 
    </div>
  </div>
</nav>
<div class="container allof">
    <div class="container c1">
        <div class="input-group">
          <span class="input-group-addon" id="basic-addon1">City</span>
          <input type="text" id="singlecity" class="form-control" placeholder="city name" aria-describedby="basic-addon1">
        </div>
        <button id="btnForSingleCity" class="btn btn-default">Check it</button>
    </div>
    <div class="container c2">
        <div class="input-group">
        <span class="input-group-addon" id="basic-addon1">First</span>
          <input type="text" id="compareFirst" class="form-control" placeholder="city name" aria-describedby="basic-addon1">
        <span class="input-group-addon" id="basic-addon1">Second</span>
          <input type="text" id="compareSecond" class="form-control" placeholder="city name" aria-describedby="basic-addon1">
          </div>
        <button id="btnForCompare" class="btn btn-default">Compare!</button>

    </div>
    <div class="container c3">
        <div class="input-group">
            <textarea type="text" id="list" class="form-control" placeholder="List of cities"></textarea>
            <button id="btnForAll" class="btn btn-default">Check all!</button>
        </div>
    </div>
    <div class="container out">
        <output></output>
    </div>
    </div>

</div>
    
<script>
    $(document).ready(function(){
        $('#btnForSingleCity').on('click', function(){
            if($("#singlecity").val() != "")
            $.ajax({
                url: 'index.php',
                type: 'post',
                data: {"command" : "check " + $("#singlecity").val()},
                success: function(resp){
                    $('output').html('<div class="jumbotron"><p>' + resp + '</p></div>');
                }
            }); else $('output').html('<div class="alert alert-warning" role="alert">Something looks empty</div>');
        });
        $('#btnForCompare').on('click', function(){
            if($("#compareFirst").val() != "" && $("#compareSecond").val() != "")
            $.ajax({
                url: 'index.php',
                type: 'post',
                data: {"command" : "compare " + $("#compareFirst").val() + " " + $('#compareSecond').val()},
                success: function(resp){
                    $('output').html('<div class="jumbotron"><p>' + resp + '</p></div>');
                }
            });else $('output').html('<div class="alert alert-warning" role="alert">Something looks empty</div>');
        });
        $('#btnForAll').on('click', function(){
            if($("#list").val() != "")
            $.ajax({
                url: 'index.php',
                type: 'post',
                data: {"command" : "list " + $("#list").val()},
                success: function(resp){
                    $('output').html('<div class="jumbotron"><p>' + resp + '</p></div>');
                }
            });else $('output').html('<div class="alert alert-warning" role="alert">Something looks empty</div>');
        });
    });
    
</script>
</body>
</html><?php } ?>