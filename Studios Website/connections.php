<?php 

$dbhost = "141.215.80.154";
$dbuser = "group14";
$dbpass = "5cZ4o@7iF1i";
$dbname = "group14_db";
   
if(!$con = mysqli_connect($dbhost,$dbuser,$dbpass,$dbname))
{

	die("failed to connect!");

}
 
