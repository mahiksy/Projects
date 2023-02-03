<?php

require_once("DB.php");

$checkDeckId = (isset($_GET["Deck"]));
$deckid = $checkDeckId ? trim($_GET["Deck"]) : 5;

$checkOffset = (isset($_GET["FlashCard"])); 
$offset = $checkOffset ? trim($_GET["FlashCard"]) : 0;

$answerFlag=(isset($_GET["flag"]));
$flag=$answerFlag ? trim($_GET['flag']) : 0;
$numRows=mysqli_query($db, "SELECT count(CardID) as num_rows From flashcards where deckID= $deckid");
$true="this is equal to the last row number"; 
while($num=$numRows->fetch_assoc())
  {
    $total_row=$num['num_rows'] -1;
  }
$getQue=mysqli_query($db, "SELECT Question FROM flashcards Where DeckID=$deckid");
$getAns=mysqli_query($db, "SELECT Answer FROM flashcards Where DeckID=$deckid");
$deckname=mysqli_query($db,"SELECT deckname FROM decks WHERE DeckID=$deckid");
$titlle=" ";
while($res=$deckname->fetch_assoc())
 {
	$titlle= $res['deckname'];
 }

?>

<!DOCTYPE html>
<html>
<head>
<title>Studious Create</title>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1">
<link rel="stylesheet" href="https://www.w3schools.com/w3css/4/w3.css">
<link rel="stylesheet" href="https://fonts.googleapis.com/css?family=Raleway">
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">
<link rel="stylesheet" type="text/css" href="pages/myCSS2.css">
<style>
body,h1,h2,h3,h4,h5,h6 {font-family: "Raleway", sans-serif}
</style>
</head>
<body class="w3-white w3-content" style="max-width:1600px">

<!-- Navbar -->
<div class="w3-top">
  <div class="w3-bar w3-indigo w3-card w3-left-align w3-large">
    <a class="w3-bar-item w3-button w3-hide-medium w3-hide-large w3-right w3-padding-large w3-hover-white w3-large w3-indigo" href="javascript:void(0);" onclick="myFunction()" title="Toggle Navigation Menu"><i class="fa fa-bars"></i></a>
    <a href="Studious

<?php   
$quiz = "test.php?_Title=" . $titlle. "&Deck=" . $deckid . "&FlashCard=0";

?>

.php" class="w3-bar-item w3-button w3-padding-large w3-hover-light-blue">Home</a>
    <a href="decks.php" class="w3-bar-item w3-button w3-hide-small w3-padding-large w3-hover-light-blue">Library</a>
    <a href= "<?php echo $quiz ?>" class="w3-bar-item w3-button w3-hide-small w3-padding-large w3-hover-light-blue">Quiz Me</a>
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
<!-- Header -->
<header class="w3-container w3-amber " style="padding:50px 16px; height: 150px;">
  <div style="display:inline-block;">
 <?php while($res=$deckname->fetch_assoc())
  {
  ?>
  <h4 class="w3-margin " style="font-size: 45px;"><strong> <?php echo $res['deckname'];?></strong> </h4>

  <?php
    }
  ?>
  </div>
  <button style="display:inline-block; float: right;position: relative; margin-top: 25px; height: 110%;" class="button w3-light-blue w3-hover-light-gray"><strong>Test</strong></button>
</header>
  
<div class="w3-amber w3-panel quizBox">
<?php
$result=mysqli_query($db,"SELECT * FROM flashcards WHERE deckID=" . $deckid. " LIMIT " . $offset . "," . 1);






if($row=mysqli_fetch_array($result))
{
  $queestion=$row['question'];
  $answer=$row['answer'];
}


?>
<div class="qBox">
  <p class="pAnsQue"><strong>Question</strong></p>
  <div class="queAnsBox">
   <p style="text-align: center;"><?php echo $queestion?> </p>
  </div >
</div>
<div class="aBox">
  <p class="pAnsQue"><strong>Answer</strong></p>
  <div class="queAnsBox">
   <p style="text-align: center;"><?php echo $answer?> </p>
  </div>
</div>

<div class="butBox w3-blue"> 
<?php
$refresh=0; 
$deckname=mysqli_query($db,"SELECT deckname FROM decks WHERE DeckID=$deckid");
$title = " "; 
while($res=$deckname->fetch_assoc())
 {
	$title = $res['deckname'];
 }

//whne user got to the last card and hits the refresh button, it will go to the first card again.
$Ref_URL="study.php?_Title=" . $title. "_&Deck=" . $deckid . "&FlashCard=" . $refresh;
//check to see if we went through all of the rows inside the table and increment offset based on that.
$dummy=$offset;
if($dummy>=$total_row)
{
  $dummy=$total_row;
}
if($dummy>=0 && $dummy<$total_row)
{
  $dummy=$dummy+1;
}
$nextURL = "study.php?_Title=" . $title. "_&Deck=" . $deckid . "&FlashCard=" . $dummy;

//check to see if the offset is less than 0 value
if($offset <= 0){
  $offset== 0;
}
else{
  $offset=$offset-1;
}
$prevURL = "study.php?_Title=" . $title. "_&Deck=" . $deckid . "&FlashCard=" . $offset;

?>
<a href="<?php echo $prevURL ?>"> <button class="button w3-light-blue w3-hover-light-gray"  style="float: left; display: inline-block; position: relative; margin-left: 20px; width: 80px;"><strong>Previous</strong></button></a>
<a href="<?php echo $nextURL ?>"><button class="button w3-light-blue w3-hover-light-gray" style="float: left; display: inline-block; position: relative; margin-left: 27px; width: 80px;"><strong>Next</strong></button></a>
<a href="<?php echo $Ref_URL?>"><button class="button w3-light-blue w3-hover-light-gray" style="position: relative; margin-left: 20px;margin-top: 20px; width: 200px;"><strong>Refresh</strong></button></a>
<a href="#list"><button class="button w3-light-blue w3-hover-light-gray" style="position: relative; margin-left: 20px;margin-top: 20px; width: 200px;"><strong>View List</strong></button></a>

</div>
</div> 


<div id="list" class="list w3-amber w3-panel">
  <h2 style="text-align: center; margin-top:50px; font-size: 40px;"><strong>List of Cards</strong></h2>
  <div>
  <?php
  while($que=$getQue->fetch_assoc()){
  echo "<div class='qBox'style='margin-left:170px';>";
  echo"<p class='pAnsQue'><strong>Question</strong></p>";
  echo"<div class='queAnsBox'>";
  echo"<p class='pAnsQue'>";
  echo $que['Question'];
  echo "</p>";
  echo"</div >";
  echo"</div>";
}
while($ans=$getAns->fetch_assoc())
{
  echo"<div class='aBox' style='margin-left:170px;'>";
  echo"<p class='pAnsQue'><strong>Answer</strong></p>";
  echo"<div class='queAnsBox'>";
  echo"<p class='pAnsQue'>";
  echo $ans['Answer'];
  echo"</p>";
  echo"</div>";
  echo"</div>";

}
?>
  
 </div>

</div>

<div class="w3-container w3-indigo w3-center w3-padding-64" style="position:relative;margin-top: 100px;>
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