-- phpMyAdmin SQL Dump
-- version 5.2.0
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Nov 29, 2022 at 10:52 PM
-- Server version: 10.4.24-MariaDB
-- PHP Version: 8.1.6

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `studious`
--

-- --------------------------------------------------------

--
-- Table structure for table `decks`
--

CREATE TABLE `decks` (
  `deckID` int(11) NOT NULL,
  `deckname` varchar(255) NOT NULL,
  `size` int(11) NOT NULL,
  `userID` int(11) NOT NULL,
  `score` tinyint(1) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `decks`
--

INSERT INTO `decks` (`deckID`, `deckname`, `size`, `userID`, `score`) VALUES
(6, 'Programming languages', 4, 6, 0),
(7, 'fruits', 5, 6, 0),
(8, 'vegetables', 3, 7, 0),
(9, 'fruits', 2, 7, 0),
(10, 'acronyms', 2, 9, 0),
(11, 'holidays', 3, 8, 0);

-- --------------------------------------------------------

--
-- Table structure for table `flashcards`
--

CREATE TABLE `flashcards` (
  `deckID` int(255) NOT NULL,
  `answer` varchar(255) NOT NULL,
  `question` varchar(255) NOT NULL,
  `Correct` tinyint(1) NOT NULL,
  `cardID` int(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `flashcards`
--

INSERT INTO `flashcards` (`deckID`, `answer`, `question`, `Correct`, `cardID`) VALUES
(6, 'HTML', 'what language is used for the basic structure of web pages', 0, 101),
(6, 'PHP', 'what language is used to take input for forms ', 0, 105),
(6, 'C', 'what is the base language that java is built off of ', 0, 106),
(6, 'C++', 'what language is taught in cis 150', 0, 107),
(7, 'banana', 'a log yellow fruit', 0, 108),
(7, 'kiwi', 'a small hairy fruit with green insides', 0, 109),
(7, 'coconut', 'a large hairy fruit with white insides', 0, 110),
(10, 'laugh out loud', 'lol', 0, 111),
(10, 'rolling on the floor', 'rofl', 0, 112),
(11, 'christmas', 'a holiday in december', 0, 113),
(11, 'thanksgiving', 'holiday in november', 0, 114),
(11, 'halloween', 'holiday in october', 0, 115),
(9, 'star fruit', 'a fruit with 5 points', 0, 116),
(9, 'orange', 'a fruit named after a color', 0, 117),
(8, 'broccoli', 'a green tree veggie', 0, 118),
(8, 'carrot', 'an orange vegetable', 0, 119),
(8, 'lettuce', 'a green vegetable that has very little taste', 0, 120),
(7, 'watermelon', 'green on the outside red on the inside', 0, 122),
(7, 'watermelon', 'green on the outside red on the inside', 0, 123);

-- --------------------------------------------------------

--
-- Table structure for table `users`
--

CREATE TABLE `users` (
  `ID` int(255) NOT NULL,
  `username` varchar(255) NOT NULL,
  `password` varchar(255) NOT NULL,
  `email` varchar(255) NOT NULL,
  `firstname` varchar(255) NOT NULL,
  `lastname` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `users`
--

INSERT INTO `users` (`ID`, `username`, `password`, `email`, `firstname`, `lastname`) VALUES
(6, 'Xavier', 'Password1', 'xkageb@umich.edu', 'xavier', 'begerow'),
(7, 'Nicole', 'Password2', 'nicolesemail@google.com', 'nicole', 'kratizinski'),
(8, 'moe', '1234word', 'moehasanemail@umich.edu', 'moe', 'idontremember'),
(9, 'sarawithoutanH', 'itsasecret', 'dokterdokter@google.com', 'sara', 'dokter\r\n'),
(10, 'username', 'password', 'email', 'fname', 'lname'),
(908458726, 'stevemail', '2eeecd72c567401e6988624b179d0b14', 'stevemail', 'steve', 'steve'),
(2147483647, 'saradokteremail', 'hi', 'saradokteremail', 'sara', 'dokter');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `decks`
--
ALTER TABLE `decks`
  ADD PRIMARY KEY (`deckID`),
  ADD KEY `userID` (`userID`);

--
-- Indexes for table `flashcards`
--
ALTER TABLE `flashcards`
  ADD PRIMARY KEY (`cardID`),
  ADD KEY `forward` (`deckID`);

--
-- Indexes for table `users`
--
ALTER TABLE `users`
  ADD PRIMARY KEY (`ID`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `decks`
--
ALTER TABLE `decks`
  MODIFY `deckID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=12;

--
-- AUTO_INCREMENT for table `flashcards`
--
ALTER TABLE `flashcards`
  MODIFY `cardID` int(255) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=127;

--
-- AUTO_INCREMENT for table `users`
--
ALTER TABLE `users`
  MODIFY `ID` int(255) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2147483648;

--
-- Constraints for dumped tables
--

--
-- Constraints for table `decks`
--
ALTER TABLE `decks`
  ADD CONSTRAINT `decks_ibfk_1` FOREIGN KEY (`userID`) REFERENCES `users` (`ID`);

--
-- Constraints for table `flashcards`
--
ALTER TABLE `flashcards`
  ADD CONSTRAINT `forward` FOREIGN KEY (`deckID`) REFERENCES `decks` (`deckID`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
