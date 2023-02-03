<?php

$signIn="login.php?_Title=Studious_SignIn_Page";
$signUp="signUp.php?_Title=Studious_SignUp_Page";
$home= "entry.php?_Title=Studious_Home_Page_";

session_start();

    include("connections.php");
    include("functions.php");
    
    if($_SERVER['REQUEST_METHOD'] == "POST")
    {
        //something was posted
		$firstname = $_POST['firstname'];
		$lastname = $_POST['lastname'];
		$email =  $_POST['email'];
		$password = $_POST['password'];
		
        $password = md5($password);

        if(!empty($email) && !empty($password) && !is_numeric($firstname))
        {
 
            //save to database
		//$ID = random_num(20);
            $query = "insert into users (firstname, lastname, username, email,password) values ('$firstname', '$lastname', '$email', '$email', '$password')";
          
			mysqli_query($con, $query); 
			 
            header("Location: $signIn");
            die;
        }else
        {
            echo "Please enter some valid information!";  //Figure out how to make the site cancel signup form and go back to the homepage
        }
    }

?>

<!DOCTYPE html>
<html>
<head>
	<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1">
<link rel="stylesheet" href="https://www.w3schools.com/w3css/4/w3.css">
<link rel="stylesheet" href="https://fonts.googleapis.com/css?family=Raleway">
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">
<link rel="stylesheet" type="text/css" href="pages/myCSS.css">
<style>
body,h1,h2,h3,h4,h5,h6 {font-family: "Raleway", sans-serif}
</style>
</head>
<body id="backG">


<nav >
<div class="w3-bar w3-indigo w3-card w3-left-align w3-large">
    <a class="w3-bar-item w3-button w3-hide-medium w3-hide-large w3-right w3-padding-large w3-hover-white w3-large w3-indigo" href="javascript:void(0);" onclick="myFunction()" title="Toggle Navigation Menu"><i class="fa fa-bars"></i></a>
    <a href="<?php echo $home ?>" class="w3-bar-item w3-button w3-padding-large w3-light-blue">Home</a>
    <a href="<?php echo $signIn ?>" class="w3-bar-item w3-button w3-hide-small w3-padding-large w3-hover-light-blue">Library</a>
  </div>
</nav>
<div class="myCSS w3-blue">
	<div class="signBox">
	
	<form method="post">
		<label class="textUp" for="username"><b>First Name:</b></label>
		<input class="input" type="text" placeholder="Enter First Name" name="firstname" required>
		<label class="textUp" for="username"><b>Last Name:</b></label>
		<input class="input" type="text" placeholder="Enter Last Name" name="lastname" required>
		<label class="textUp" for="username"><b>Email:</b></label>
		<input class="input" type="text" placeholder="Enter Email" name="email" required>
		<label class="textUp" for="password"><b>Password:</b></label>
		<input class="input" type="text" placeholder="Enter Password" name="password" required>
		<br>

		<button class=" w3-hover-light-blue button" type="submit"><b>Sign Up</b></button></button>
		<br>
		<a class="link" href="<?php echo $home ?>">
		<button class=" w3-hover-light-blue button" type="button" ><b>Cancel</b></button></button>
		</a>
		
		</form>
	</div>

</div>
</div>

</div>
<div class=" qoute  w3-indigo w3-center w3-padding-64">
    <h1 class="w3-margin w3-xlarge"><strong>Quote of the Day: </strong> Education is NOT the learning of facts, but the training of the mind to THINK! -Albert Einstein</h1>
</div>
<!-- Footer -->
<footer class=" footer w3-padding-64 w3-center w3-opacity">  
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
</body>
</html>