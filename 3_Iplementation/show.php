<html>
<head>
	<style>
	.center {
	  margin: 0;
	  position: absolute;
	  top: 50%;
	  left: 50%;
	  -ms-transform: translate(-50%, -50%);
	  transform: translate(-50%, -50%);
	}
	</style>
</head>
<script src="http://code.jquery.com/jquery-latest.js"></script>
<script>
    $(document).ready(function(){
		 $("#div_refresh").load("show.php");
        setInterval(function() {
            $("#div_refresh").load("show.php");
        }, 5000);
    });
 
</script>
<body style="background-color:black;">	
	  
	  	<div id="div_refresh", class="center">
	    <h1 style="font-size:10vw;color:white;font-style:helvetica">
	    	<?php
				$myfile = fopen("battery_status.txt", "r") or die("Unable to open file!");
				$text = fread($myfile,filesize("battery_status.txt"));
				$arr = explode(' ',trim($text));
				echo $arr[0]
				// fclose($myfile);
			?>
	    </h1>
	    <h2 style="font-size:5vw;color:white">
	    	<?php
				$myfile = fopen("battery_status.txt", "r") or die("Unable to open file!");
				$text = fread($myfile,filesize("battery_status.txt"));
				$arr = explode(' ',trim($text));
				echo $arr[1];
				// fclose($myfile);
			?>
		</h2>	
	  </div>
</body>
</html>