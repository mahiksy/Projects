<!DOCTYPE html>
<html lang="en">
<head>
<title>Studious HomePage</title>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1">
<link rel="stylesheet" href="https://www.w3schools.com/w3css/4/w3.css">
<link rel="stylesheet" href="https://fonts.googleapis.com/css?family=Lato">
<link rel="stylesheet" href="https://fonts.googleapis.com/css?family=Montserrat">
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">
<link rel="stylesheet" type="text/css" href="pages/myCSS.css">
<style>
body,h1,h2,h3,h4,h5,h6 {font-family: "Lato", sans-serif}
.w3-bar,h1,button {font-family: "Montserrat", sans-serif}
.fa-anchor,.fa-coffee {font-size:200px}
</style>
</head>
<body>

<!-- Navbar -->
<div class="w3-top">
<?php $signIn="login.php?_Title=Studious_SignIn_Page";
$signUp="signUp.php?_Title=Studious_SignUp_Page";
$home="entry.php?_Title=Studious_Home_Page"
?>
  <div class="w3-bar w3-indigo w3-card w3-left-align w3-large">
    <a class="w3-bar-item w3-button w3-hide-medium w3-hide-large w3-right w3-padding-large w3-hover-white w3-large w3-indigo" href="javascript:void(0);" onclick="myFunction()" title="Toggle Navigation Menu"><i class="fa fa-bars"></i></a>
    <a href="<?php echo $home ?>" class="w3-bar-item w3-button w3-padding-large w3-light-blue">Home</a>
    <a href="<?php echo $signIn ?>" class="w3-bar-item w3-button w3-hide-small w3-padding-large w3-hover-light-blue">Library</a>
  </div>

  <!-- Navbar on small screens -->
  <div id="navDemo" class="w3-bar-block w3-white w3-hide w3-hide-large w3-hide-medium w3-large">
    <a href="#" class="w3-bar-item w3-button w3-padding-large">Create+</a>
    <a href="#" class="w3-bar-item w3-button w3-padding-large">Library</a>
    <a href="#" class="w3-bar-item w3-button w3-padding-large">Quiz Me</a>
  </div>
</div>

<!-- Header -->
<header class="w3-container w3-amber w3-center" style="padding:128px 16px">
  <h1 class="w3-margin w3-jumbo"><strong>Welcome to Studious!</strong></h1>
  <p class="w3-xlarge"></p>
  <a class="link" href="<?php echo $signIn ?>">
  <button class="w3-button w3-indigo w3-padding-large w3-large w3-margin-top w3-hover-light-blue">Sign In</button>
  </a>
  <a class="link" href="<?php echo $signUp ?>" >
   <button class="w3-button w3-indigo w3-padding-large w3-large w3-margin-top w3-hover-light-blue">Sign Up Here</button>
  </a>
</header>

<!-- First Grid -->
<div class="w3-row-padding w3-padding-64 w3-container">
  <div class="w3-content">
    <div class="w3-twothird">
      <h1>What is Studious?</h1>
      <p class="w3-padding-25"><strong>Are you stresed out and need to find an effective tool to study for exams?</strong></p>

      <p class="w3-text-grey">Look no further! Studious seeks to eliminate the challenges associated with the cost of studying by providing a FREE platform for students to utilize. Studious allows our users go master their academic materials by creating personalized flashcards and generating practice quizzes to help users advance their knowledge!</p>
    </div>

    <div class="w3-third w3-center">
      <img src= "study.png" style="width:70%" alt="studying picture" >
	</div>
	</div>
	</div>
<div class="w3-container w3-indigo w3-center w3-padding-64">
    <h1 class="w3-margin w3-xlarge"><strong>Quote of the Day: </strong> Education is NOT the learning of facts, but the training of the mind to THINK! -Albert Einstein</h1>
</div>

<!-- Footer -->
<footer class="w3-container w3-padding-64 w3-center w3-opacity">  
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

<script>
// Used to toggle the menu on small screens when clicking on the menu button
function myFunction() {
  var x = document.getElementById("navDemo");
  if (x.className.indexOf("w3-show") == -1) {
    x.className += " w3-show";
  } else { 
    x.className = x.className.replace(" w3-show", "");
  }
}
</script>

</body>
</html>
