<!DOCTYPE html>
<html>
<head>
<title>Studious Decks</title>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1">
<link rel="stylesheet" href="https://www.w3schools.com/w3css/4/w3.css">
<link rel="stylesheet" href="https://fonts.googleapis.com/css?family=Raleway">
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">
<style>
body,h1,h2,h3,h4,h5,h6 {font-family: "Raleway", sans-serif}
</style>
</head>
<body class="w3-white w3-content" style="max-width:1600px">

<!-- Navbar -->
<div class="w3-top">
  <div class="w3-bar w3-indigo w3-card w3-left-align w3-large">
    <a class="w3-bar-item w3-button w3-hide-medium w3-hide-large w3-right w3-padding-large w3-hover-white w3-large w3-indigo" href="javascript:void(0);" onclick="myFunction()" title="Toggle Navigation Menu"><i class="fa fa-bars"></i></a>
    <a href="Studious.php" class="w3-bar-item w3-button w3-padding-large w3-hover-light-blue">Home</a>
    <a href="decks.php" class="w3-bar-item w3-button w3-hide-small w3-padding-large w3-light-blue">Library</a>
    <a href="logout.php" class="w3-bar-item w3-button w3-hide-small w3-padding-large w3-hover-light-blue">Logout</a>
  </div>

  <!-- Navbar on small screens -->
  <div id="navDemo" class="w3-bar-block w3-white w3-hide w3-hide-large w3-hide-medium w3-large">
    <a href="#" class="w3-bar-item w3-button w3-padding-large">Create+</a>
    <a href="#" class="w3-bar-item w3-button w3-padding-large">Library</a>
    <a href="#" class="w3-bar-item w3-button w3-padding-large">Quiz Me</a>
    <a href="#" class="w3-bar-item w3-button w3-padding-large">Account Information</a>
  </div>
</div>
</div>
</div>
</div>
<!-- !PAGE CONTENT! -->
<!-- Header 
<header class="w3-container w3-amber w4-center" style="padding:50px 16px">
  <h1 class="w3-margin w3-jumbo"><strong>Decks</strong></h1> 
</header>
-->
  
  <!-- First deck Grid-->
    
 
  <div class="w3-panel w3-large w3-amber ">
  <br>
  <div class="w3-row-padding">
    
 
<body>

<?php
	//database connection  
    	$conn = mysqli_connect('141.215.80.154', 'group14', '5cZ4o@7iF1i');  
    	if (! $conn) {  
		die("Connection failed" . mysqli_connect_error());  
    	}		  
    	else {  
		mysqli_select_db($conn, 'group14_db');  
	}

	// For setting and getting cache to/from memcache
	try
	{
		$memcached = new Memcached();
		$memcached->addServer("127.0.0.1", 11211);
		$response = $memcached->get("popular_decks");
		
		if($response==true)
		{
			//echo "Result coming from caching";
			$popular_decks_result = $memcached->get("popular_decks");
		}
		else
		{	  
    			//determine which page number visitor is currently on  
    			if (!isset ($_GET['page']) ) {  
        			$page = 1;  
    			} else {  
        			$page = $_GET['page'];  
    			}  
  
    			$query = "SELECT * FROM decks ORDER BY size DESC LIMIT 3";  
			$res = mysqli_query($conn, $query);
			$popular_decks_result = array();
			while($row = mysqli_fetch_assoc($res)) {
				array_push($popular_decks_result, $row);
			}

			//echo "Cache is not created yet, reload again to see changes";
			$memcached->set("popular_decks", $popular_decks_result, 86400) ;
		}
	}
	catch (exception $e)
	{
		echo $e->getMessage();
	}
    
    //define total number of results you want per page  
    $results_per_page = 3;  
  
    //find the total number of results stored in the database  
    $query = "select *from decks";  
    $result = mysqli_query($conn, $query);  
    $number_of_result = mysqli_num_rows($result);  
  
    //determine the total number of pages available  
    $number_of_page = ceil ($number_of_result / $results_per_page);  
  
    //determine which page number visitor is currently on  
    if (!isset ($_GET['page']) ) {  
        $page = 1;  
    } else {  
        $page = $_GET['page'];  
    }  
  
    //determine the sql LIMIT starting number for the results on the displaying page  
    $page_first_result = ($page-1) * $results_per_page;  
  
    //retrieve the selected results from database   
    $query = "SELECT *FROM decks LIMIT " . $page_first_result . ',' . $results_per_page;  
    $result = mysqli_query($conn, $query);  
  
?>

<!-- Popular Decks Section -->
<!-- Header -->
<center><h2 class="w3-margin"><strong>Popular Decks</strong></h1></center>
<?php
    foreach ($popular_decks_result as $row) { ?> 
       	<div class="w3-third w3-container w3-margin-bottom">
       	<div class="w3-container w3-white w3-hover-indigo">
	<b><center>
		<?php echo $row['deckname'] . ' </br> Size: ' . $row['size'] . '</br>'; 
?>
	</center></b>
	<br>
	<center>
	<form action="flashcards.php" method="get">
  		<button name="decknumber" type="text" value=<?php echo $row['deckID'] ?> formmethod="post">View Deck</button>
	</form>
	<?php   
		$prevURL = "study.php?deck=" . $row['deckID'];
	?>
	<a href="<?php echo $prevURL ?>"> <button  ><strong>Study Deck</strong></button></a>
	</center>
	</br>
	</div>
    </div>
  <?php  } 
?>
</div>
<!-- End of Popular Decks Section -->

<!-- My Decks -->
<hr/>
<center><h2 class="w3-margin"><strong>My Decks</strong></h2></center>

<?php  
    while ($row = mysqli_fetch_array($result)) { ?> 
	<div class="w3-third w3-container w3-margin-bottom">
       	<div class="w3-container w3-white w3-hover-indigo">
        <p><b><center>
		<?php echo $row['deckname'] . ' </br> Size: ' . $row['size'] . '</br>'; 
?>
	</center></b></p>
        <br>
        <p><center>
		   

	<form action="flashcards.php" method="get">
  		<button name="decknumber" type="text" value=<?php echo $row['deckID'] ?> formmethod="post">View Deck</button>
	</form>
	<?php   
		$prevURL = "study.php?deck=" . $row['deckID'];
	?>
	<a href="<?php echo $prevURL ?>"> <button  ><strong>Study Deck</strong></button></a>
	</center></p>
      </div>
    </div>
  <?php  } 
?>

  </div>

  <!-- Pagination -->

  <div class="w3-center w3-padding-32">
<?php    

  
  
    //display the link of the pages in URL  
    for($page = 1; $page<= $number_of_page; $page++) {  
        echo '<a href = "decks.php?page=' . $page . '">' . $page . ' </a>';  
    }  
  ?>
  </div>
  <!-- add deck -->
  <div class="w3-row-padding w3-padding-16" id="about">

  </div>

<div class="w3-container w3-indigo w3-center w3-padding-64">
    <h1 class="w3-margin w3-xlarge"><strong>Quote of the Day: </strong> Never regard studying as a duty, but as the enviable opportunity to learn. -Albert Einstein</h1>
</div>





<!-- Footer -->
<footer class="w3-container w3-padding-64 w3-center w3-opacity">  
  <div class="w3-container w3-padding-large w3-white" style="margin-bottom:32px">
  <div class="w3-xlarge w3-padding-32">
    <i class="fa fa-facebook-official w3-hover-opacity"></i>
    <i class="fa fa-instagram w3-hover-opacity"></i>
    <i class="fa fa-snapchat w3-hover-opacity"></i>
    <i class="fa fa-pinterest-p w3-hover-opacity"></i>
    <i class="fa fa-twitter w3-hover-opacity"></i>
    <i class="fa fa-linkedin w3-hover-opacity"></i>
 </div>
 <p>Powered by <a href="https://www.w3schools.com/w3css/default.asp" target="_blank">broke and tired college students</a></p>
</footer>

<!-- End page content -->
</div>


</body>
</html>
