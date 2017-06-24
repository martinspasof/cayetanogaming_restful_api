-- phpMyAdmin SQL Dump
-- version 4.6.5.2
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Jun 24, 2017 at 04:43 PM
-- Server version: 10.1.21-MariaDB
-- PHP Version: 5.6.30

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `job_offers`
--
CREATE DATABASE IF NOT EXISTS `job_offers` DEFAULT CHARACTER SET utf8 COLLATE utf8_general_ci;
USE `job_offers`;

-- --------------------------------------------------------

--
-- Table structure for table `candidates`
--

CREATE TABLE `candidates` (
  `id` int(11) NOT NULL,
  `name` varchar(100) NOT NULL,
  `position` varchar(100) NOT NULL,
  `created_on` date NOT NULL,
  `job_id` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `candidates`
--

INSERT INTO `candidates` (`id`, `name`, `position`, `created_on`, `job_id`) VALUES
(1, 'Joe Dowell', 'Php Developer', '2017-06-04', 1),
(2, 'Mirela Boeva', 'Data Analyst', '2017-05-15', 2),
(3, 'Krasimir Vlaev', 'System Engineer', '2017-05-22', 4),
(4, 'Bozhidar Petkov', 'Senior guru IT Reqruitment ninja', '2017-04-24', 3),
(5, 'Deyan Marinov', 'C# Developer', '2017-06-21', 5),
(6, 'Borislav Vasilev', 'Programmer', '2017-03-21', 6),
(7, 'Boncho Tonev', 'Front Web Developer', '2017-02-21', 7);

-- --------------------------------------------------------

--
-- Table structure for table `jobs`
--

CREATE TABLE `jobs` (
  `id` int(11) NOT NULL,
  `position` varchar(100) NOT NULL,
  `description` text NOT NULL,
  `created_on` date NOT NULL DEFAULT '0000-00-00'
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `jobs`
--

INSERT INTO `jobs` (`id`, `position`, `description`, `created_on`) VALUES
(1, 'PHP Developer', 'The PHP Developer will be responsible for the development, maintenance and optimization of the internal company software. ', '2017-06-07'),
(2, 'HR AND REQRUITMENT MANAGER', 'test', '2017-06-04'),
(3, 'Java Developer', 'test test ', '2017-05-02'),
(4, 'Mobile Developer', 'test', '2017-06-04'),
(5, 'Scrum master', 'test test ', '2017-05-02'),
(6, 'Software Developer', 'test', '2017-06-04'),
(7, 'Scrum master', 'test test ', '2017-05-02');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `candidates`
--
ALTER TABLE `candidates`
  ADD PRIMARY KEY (`id`),
  ADD KEY `fk_job_id` (`job_id`);

--
-- Indexes for table `jobs`
--
ALTER TABLE `jobs`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `candidates`
--
ALTER TABLE `candidates`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=8;
--
-- AUTO_INCREMENT for table `jobs`
--
ALTER TABLE `jobs`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=8;
--
-- Constraints for dumped tables
--

--
-- Constraints for table `candidates`
--
ALTER TABLE `candidates`
  ADD CONSTRAINT `fk_job_id` FOREIGN KEY (`job_id`) REFERENCES `jobs` (`id`);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
