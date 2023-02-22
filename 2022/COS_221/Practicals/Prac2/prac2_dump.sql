-- MySQL dump 10.19  Distrib 10.3.34-MariaDB, for debian-linux-gnu (x86_64)
--
-- Host: localhost    Database: u18108467_invoicingsystem
-- ------------------------------------------------------
-- Server version	10.3.34-MariaDB-0ubuntu0.20.04.1

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `CUSTOMER`
--

DROP TABLE IF EXISTS `CUSTOMER`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `CUSTOMER` (
  `Code` varchar(4) NOT NULL,
  `LName` varchar(15) NOT NULL,
  `FName` varchar(15) NOT NULL,
  `Initial` varchar(1) DEFAULT NULL,
  `AreaCode` varchar(3) NOT NULL,
  `Phone` varchar(9) NOT NULL,
  PRIMARY KEY (`Code`),
  CONSTRAINT `CHK_Code` CHECK (`Code` regexp '^C[0-9]{3}$'),
  CONSTRAINT `CHK_Area` CHECK (`AreaCode` regexp '^[0-9]{3}$'),
  CONSTRAINT `CHK_Phone` CHECK (`Phone` regexp '^[0-9]{3}-[0-9]{4}$')
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `CUSTOMER`
--

LOCK TABLES `CUSTOMER` WRITE;
/*!40000 ALTER TABLE `CUSTOMER` DISABLE KEYS */;
INSERT INTO `CUSTOMER` VALUES ('C001','Peters','Johny','J','021','889-1234'),('C002','Nkosi','Thabo','P','011','234-9966'),('C003','Christie','Agatha','','012','627-7530');
/*!40000 ALTER TABLE `CUSTOMER` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `INVOICE`
--

DROP TABLE IF EXISTS `INVOICE`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `INVOICE` (
  `Number` varchar(5) NOT NULL,
  `Date` varchar(10) NOT NULL,
  `C_Code` varchar(4) NOT NULL,
  PRIMARY KEY (`Number`),
  KEY `C_Code` (`C_Code`),
  CONSTRAINT `INVOICE_ibfk_1` FOREIGN KEY (`C_Code`) REFERENCES `CUSTOMER` (`Code`),
  CONSTRAINT `CHK_Number` CHECK (`Number` regexp '^[0-9]{5}$'),
  CONSTRAINT `CHK_Date` CHECK (`Date` regexp '^[0-9]{4}-[0-9]{2}-[0-9]{2}$'),
  CONSTRAINT `CHK_C_Code` CHECK (`C_Code` regexp '^C[0-9]{3}$')
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `INVOICE`
--

LOCK TABLES `INVOICE` WRITE;
/*!40000 ALTER TABLE `INVOICE` DISABLE KEYS */;
INSERT INTO `INVOICE` VALUES ('00011','2022-03-01','C001'),('00012','2022-03-09','C003');
/*!40000 ALTER TABLE `INVOICE` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `LINE`
--

DROP TABLE IF EXISTS `LINE`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `LINE` (
  `Number` int(11) NOT NULL AUTO_INCREMENT,
  `Units` int(11) NOT NULL,
  `Price` float NOT NULL,
  `I_Number` varchar(5) NOT NULL,
  `P_Code` varchar(5) NOT NULL,
  PRIMARY KEY (`Number`),
  KEY `I_Number` (`I_Number`),
  KEY `P_Code` (`P_Code`),
  CONSTRAINT `LINE_ibfk_1` FOREIGN KEY (`I_Number`) REFERENCES `INVOICE` (`Number`),
  CONSTRAINT `LINE_ibfk_2` FOREIGN KEY (`P_Code`) REFERENCES `PRODUCT` (`Code`),
  CONSTRAINT `CHK_I_Number` CHECK (`I_Number` regexp '^[0-9]{5}$'),
  CONSTRAINT `CHK_P_Code` CHECK (`P_Code` regexp '^(PR|SL)_[0-9]{2}$')
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `LINE`
--

LOCK TABLES `LINE` WRITE;
/*!40000 ALTER TABLE `LINE` DISABLE KEYS */;
INSERT INTO `LINE` VALUES (1,1,200,'00011','SL_01'),(2,10,10,'00011','PR_01'),(3,2,1200,'00011','PR_03'),(4,2,725,'00012','SL_02');
/*!40000 ALTER TABLE `LINE` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `PRODUCT`
--

DROP TABLE IF EXISTS `PRODUCT`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `PRODUCT` (
  `Code` varchar(5) NOT NULL,
  `Description` varchar(50) DEFAULT NULL,
  `Price` float NOT NULL,
  `Vendor` varchar(30) NOT NULL,
  PRIMARY KEY (`Code`),
  CONSTRAINT `CHK_Code` CHECK (`Code` regexp '^(PR|SL)_[0-9]{2}$')
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `PRODUCT`
--

LOCK TABLES `PRODUCT` WRITE;
/*!40000 ALTER TABLE `PRODUCT` DISABLE KEYS */;
INSERT INTO `PRODUCT` VALUES ('PR_01','Fake blood',10,'Props Unlimited'),('PR_02','Rope',125,'Mountain Climbers'),('PR_03','Prop Gun',1456,'UnReal'),('SL_01','Fingerprint kit',250,'Simple Sleuth'),('SL_02','Magnifying glass',725,'Eye Glass');
/*!40000 ALTER TABLE `PRODUCT` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2022-03-22 23:24:29
