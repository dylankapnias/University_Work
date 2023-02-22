-- MySQL dump 10.19  Distrib 10.3.34-MariaDB, for debian-linux-gnu (x86_64)
--
-- Host: localhost    Database: u18108467_upbank
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
-- Table structure for table `ACCOUNT`
--

DROP TABLE IF EXISTS `ACCOUNT`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ACCOUNT` (
  `accountNumber` varchar(8) NOT NULL,
  `amount` float NOT NULL,
  `currency` varchar(3) NOT NULL,
  `isSavings` tinyint(1) NOT NULL,
  `interest_rate` float NOT NULL,
  `noticePeriod` int(11) NOT NULL,
  `isSharia` tinyint(1) NOT NULL,
  `clientId` varchar(8) NOT NULL,
  `ownerBranch` varchar(8) NOT NULL,
  `ownedId` varchar(8) NOT NULL,
  PRIMARY KEY (`accountNumber`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ACCOUNT`
--

LOCK TABLES `ACCOUNT` WRITE;
/*!40000 ALTER TABLE `ACCOUNT` DISABLE KEYS */;
INSERT INTO `ACCOUNT` VALUES ('A0000001',10.5,'ZAR',1,0.3,32,0,'C0000001','B0000001','O0000001'),('A0000002',10.5,'ZAR',1,0.3,32,0,'C0000002','B0000002','O0000002'),('A0000003',10.5,'ZAR',1,0.3,32,0,'C0000003','B0000003','O0000003'),('A0000004',10.5,'ZAR',1,0.3,32,0,'C0000004','B0000002','O0000004'),('A0000005',10.5,'ZAR',1,0.3,32,0,'C0000005','B0000002','O0000005'),('A0000006',10.5,'ZAR',1,0.3,32,0,'C0000006','B0000003','O0000006'),('A0000007',10.5,'ZAR',1,0.3,32,0,'C0000007','B0000001','O0000007');
/*!40000 ALTER TABLE `ACCOUNT` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ADDRESS`
--

DROP TABLE IF EXISTS `ADDRESS`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ADDRESS` (
  `Oid` varchar(8) NOT NULL,
  `a_type` varchar(20) NOT NULL,
  `streetNumber` varchar(4) NOT NULL,
  `street` varchar(20) NOT NULL,
  `suburb` varchar(20) NOT NULL,
  `city` varchar(20) NOT NULL,
  `postalCode` varchar(5) NOT NULL,
  PRIMARY KEY (`Oid`,`postalCode`),
  CONSTRAINT `ADDRESS_ibfk_1` FOREIGN KEY (`Oid`) REFERENCES `OWNERS` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ADDRESS`
--

LOCK TABLES `ADDRESS` WRITE;
/*!40000 ALTER TABLE `ADDRESS` DISABLE KEYS */;
INSERT INTO `ADDRESS` VALUES ('B0000001','physical','333','1\'st','Randburg','Nature','7777'),('B0000002','physical','333','1\'st','Hatfield','Nature','7777'),('B0000003','physical','333','1\'st','Groenkloof','Nature','7777'),('B0000004','physical','333','1\'st','Greenwood','Nature','7777'),('B0000005','physical','333','1\'st','Greenwood','Nature','7777'),('B0000006','physical','333','1\'st','Greenwood','Nature','7777'),('B0000007','physical','333','1\'st','Greenwood','Nature','7777'),('C0000001','physical','333','1\'st','Greenwood','Nature','7777'),('C0000002','physical','333','1\'st','Greenwood','Nature','7777'),('C0000003','physical','333','1\'st','Greenwood','Nature','7777'),('C0000004','physical','333','1\'st','Greenwood','Nature','7777'),('C0000005','postal','888','1\'st','Greenwood','Nature','7777'),('C0000006','physical','333','1\'st','Greenwood','Nature','7777'),('C0000007','physical','333','1\'st','Greenwood','Nature','7777');
/*!40000 ALTER TABLE `ADDRESS` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ATM`
--

DROP TABLE IF EXISTS `ATM`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ATM` (
  `serialNumber` varchar(8) NOT NULL,
  `f_date` varchar(10) NOT NULL,
  `companyCode` varchar(8) NOT NULL,
  `cashOnHand` float NOT NULL,
  `responsibleBranch` varchar(8) NOT NULL,
  `ownedId` varchar(8) NOT NULL,
  PRIMARY KEY (`serialNumber`),
  CONSTRAINT `CHK_Date` CHECK (`f_date` regexp '^[0-9]{4}-[0-9]{2}-[0-9]{2}$')
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ATM`
--

LOCK TABLES `ATM` WRITE;
/*!40000 ALTER TABLE `ATM` DISABLE KEYS */;
INSERT INTO `ATM` VALUES ('ABC12203','2022-04-02','CI000003',55.55,'B0000003','O0000010'),('ABC12301','2022-04-02','CI000001',55.55,'B0000001','O0000008'),('ABC12302','2022-04-02','CI000002',55.55,'B0000002','O0000009'),('ABC12307','2022-04-02','CI000007',55.55,'B0000001','O0000014'),('ZYX32104','2022-04-02','CI000004',55.55,'B0000003','O0000011'),('ZYX32106','2022-04-02','CI000006',55.55,'B0000001','O0000013'),('ZYX32ABC','2022-04-02','CI000005',55.55,'B0000002','O0000012');
/*!40000 ALTER TABLE `ATM` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `BRANCH`
--

DROP TABLE IF EXISTS `BRANCH`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `BRANCH` (
  `id` varchar(8) NOT NULL,
  `open` varchar(5) NOT NULL,
  `close` varchar(5) NOT NULL,
  `day` varchar(9) NOT NULL,
  PRIMARY KEY (`id`),
  CONSTRAINT `CHK_O_Time` CHECK (`open` regexp '^[0-1]{1}[0-9]{1}:[0-5]{1}[0-9]{1}$'),
  CONSTRAINT `CHK_C_Time` CHECK (`close` regexp '^[0-1]{1}[0-9]{1}:[0-5]{1}[0-9]{1}$')
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `BRANCH`
--

LOCK TABLES `BRANCH` WRITE;
/*!40000 ALTER TABLE `BRANCH` DISABLE KEYS */;
INSERT INTO `BRANCH` VALUES ('B0000001','07:30','16:00','Monday'),('B0000002','07:30','16:00','Monday'),('B0000003','07:30','16:00','Monday'),('B0000004','07:30','16:00','Monday'),('B0000005','07:30','16:00','Monday'),('B0000006','07:30','16:00','Monday'),('B0000007','07:30','16:00','Monday');
/*!40000 ALTER TABLE `BRANCH` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `CLIENTS`
--

DROP TABLE IF EXISTS `CLIENTS`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `CLIENTS` (
  `id` varchar(8) NOT NULL,
  `prefix` varchar(4) NOT NULL,
  `first` varchar(20) NOT NULL,
  `middle` varchar(20) DEFAULT NULL,
  `last` varchar(20) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `CLIENTS`
--

LOCK TABLES `CLIENTS` WRITE;
/*!40000 ALTER TABLE `CLIENTS` DISABLE KEYS */;
INSERT INTO `CLIENTS` VALUES ('C0000001','Mr','A','B','C'),('C0000002','Mr','D','E','F'),('C0000003','Mr','A','F','C'),('C0000004','Mr','U','','D'),('C0000005','Mr','R','D','B'),('C0000006','Mr','M','S','C'),('C0000007','Mr','A','','K');
/*!40000 ALTER TABLE `CLIENTS` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `CONTACTDETAILS`
--

DROP TABLE IF EXISTS `CONTACTDETAILS`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `CONTACTDETAILS` (
  `Oid` varchar(8) NOT NULL,
  `c_type` varchar(20) NOT NULL,
  `identifier` varchar(30) NOT NULL,
  PRIMARY KEY (`Oid`,`identifier`),
  CONSTRAINT `CONTACTDETAILS_ibfk_1` FOREIGN KEY (`Oid`) REFERENCES `OWNERS` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `CONTACTDETAILS`
--

LOCK TABLES `CONTACTDETAILS` WRITE;
/*!40000 ALTER TABLE `CONTACTDETAILS` DISABLE KEYS */;
INSERT INTO `CONTACTDETAILS` VALUES ('B0000001','mphone','0123456789'),('B0000002','mphone','0123456789'),('B0000003','mphone','0123456789'),('B0000004','mphone','0123456789'),('B0000005','mphone','0123456789'),('B0000006','mphone','0123456789'),('B0000007','mphone','0123456789'),('C0000001','mphone','0123456789'),('C0000002','mphone','0123456789'),('C0000003','mphone','0123456789'),('C0000004','IG','@TreeLover'),('C0000005','mphone','0123456789'),('C0000006','mphone','0123456789'),('C0000007','mphone','0123456789');
/*!40000 ALTER TABLE `CONTACTDETAILS` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `CONTRACTS`
--

DROP TABLE IF EXISTS `CONTRACTS`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `CONTRACTS` (
  `companyCode` varchar(8) NOT NULL,
  `start` varchar(10) NOT NULL,
  `end` varchar(10) NOT NULL,
  `atmSerialNumber` varchar(10) NOT NULL,
  PRIMARY KEY (`companyCode`),
  KEY `atmSerialNumber` (`atmSerialNumber`),
  CONSTRAINT `CONTRACTS_ibfk_1` FOREIGN KEY (`atmSerialNumber`) REFERENCES `ATM` (`serialNumber`),
  CONSTRAINT `CHK_S_Date` CHECK (`start` regexp '^[0-9]{4}-[0-9]{2}-[0-9]{2}$'),
  CONSTRAINT `CHK_E_Date` CHECK (`end` regexp '^[0-9]{4}-[0-9]{2}-[0-9]{2}$')
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `CONTRACTS`
--

LOCK TABLES `CONTRACTS` WRITE;
/*!40000 ALTER TABLE `CONTRACTS` DISABLE KEYS */;
INSERT INTO `CONTRACTS` VALUES ('CI000001','2022-04-01','2022-04-03','ABC12301'),('CI000002','2022-04-01','2022-04-03','ABC12302'),('CI000003','2022-04-01','2022-04-03','ABC12203'),('CI000004','2022-04-01','2022-04-03','ZYX32104'),('CI000005','2022-04-01','2022-04-03','ZYX32ABC'),('CI000006','2022-04-01','2022-04-03','ZYX32106'),('CI000007','2022-04-01','2022-04-03','ABC12307');
/*!40000 ALTER TABLE `CONTRACTS` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `OWNED`
--

DROP TABLE IF EXISTS `OWNED`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `OWNED` (
  `owendId` varchar(8) NOT NULL,
  PRIMARY KEY (`owendId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `OWNED`
--

LOCK TABLES `OWNED` WRITE;
/*!40000 ALTER TABLE `OWNED` DISABLE KEYS */;
INSERT INTO `OWNED` VALUES ('O0000001'),('O0000002'),('O0000003'),('O0000004'),('O0000005'),('O0000006'),('O0000007'),('O0000008'),('O0000009'),('O0000010'),('O0000011'),('O0000012'),('O0000013'),('O0000014');
/*!40000 ALTER TABLE `OWNED` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `OWNERS`
--

DROP TABLE IF EXISTS `OWNERS`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `OWNERS` (
  `id` varchar(8) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `OWNERS`
--

LOCK TABLES `OWNERS` WRITE;
/*!40000 ALTER TABLE `OWNERS` DISABLE KEYS */;
INSERT INTO `OWNERS` VALUES ('B0000001'),('B0000002'),('B0000003'),('B0000004'),('B0000005'),('B0000006'),('B0000007'),('C0000001'),('C0000002'),('C0000003'),('C0000004'),('C0000005'),('C0000006'),('C0000007');
/*!40000 ALTER TABLE `OWNERS` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `TRANSACTION`
--

DROP TABLE IF EXISTS `TRANSACTION`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `TRANSACTION` (
  `transactionCode` varchar(10) NOT NULL,
  `transactionDate` varchar(10) NOT NULL,
  `amount` float NOT NULL,
  `currency` varchar(10) NOT NULL,
  `toAccount` varchar(8) NOT NULL,
  `fromAccount` varchar(8) NOT NULL,
  PRIMARY KEY (`transactionCode`),
  KEY `fromAccount` (`fromAccount`),
  CONSTRAINT `TRANSACTION_ibfk_1` FOREIGN KEY (`fromAccount`) REFERENCES `ACCOUNT` (`accountNumber`),
  CONSTRAINT `CHK_Date` CHECK (`transactionDate` regexp '^[0-9]{4}-[0-9]{2}-[0-9]{2}$')
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `TRANSACTION`
--

LOCK TABLES `TRANSACTION` WRITE;
/*!40000 ALTER TABLE `TRANSACTION` DISABLE KEYS */;
INSERT INTO `TRANSACTION` VALUES ('T0000001','2022-04-01',21.9,'ZAR','A0000001','A0000003'),('T0000002','2022-04-01',21.9,'ZAR','A0000004','A0000002'),('T0000003','2022-04-01',21.9,'ZAR','A0000007','A0000003'),('T0000004','2022-04-01',21.9,'ZAR','A0000004','A0000001'),('T0000005','2022-04-01',21.9,'ZAR','A0000004','A0000002'),('T0000006','2022-04-01',21.9,'ZAR','A0000004','A0000002'),('T0000007','2022-04-01',21.9,'ZAR','A0000004','A0000002'),('T0000008','2022-04-01',21.9,'ZAR','A0000004','A0000002'),('T0000009','2022-04-01',21.9,'ZAR','A0000004','A0000002'),('T0000010','2022-04-01',21.9,'ZAR','A0000004','A0000002'),('T0000011','2022-04-01',21.9,'ZAR','A0000004','A0000002'),('T0000012','2022-04-01',21.9,'ZAR','A0000004','A0000002'),('T0000013','2022-04-01',21.9,'ZAR','A0000004','A0000002'),('T0000014','2022-04-01',21.9,'ZAR','A0000004','A0000002'),('T0000015','2022-04-01',21.9,'ZAR','A0000004','A0000002'),('T0000016','2022-04-01',21.9,'ZAR','A0000004','A0000002'),('T0000017','2022-04-01',21.9,'ZAR','A0000004','A0000002'),('T0000018','2022-04-01',21.9,'ZAR','A0000004','A0000002'),('T0000019','2022-04-01',21.9,'ZAR','A0000004','A0000002'),('T0000020','2022-04-01',21.9,'ZAR','A0000004','A0000002'),('T0000021','2022-04-01',21.9,'ZAR','A0000004','A0000002'),('T0000022','2022-04-01',21.9,'ZAR','A0000004','A0000002'),('T0000023','2022-04-01',21.9,'ZAR','A0000004','A0000002'),('T0000024','2022-04-01',21.9,'ZAR','A0000004','A0000002'),('T0000025','2022-04-01',21.9,'ZAR','A0000004','A0000002'),('T0000026','2022-04-01',21.9,'ZAR','A0000004','A0000002'),('T0000027','2022-04-01',21.9,'ZAR','A0000004','A0000002'),('T0000028','2022-04-01',21.9,'ZAR','A0000004','A0000002'),('T0000029','2022-04-01',21.9,'ZAR','A0000007','A0000001');
/*!40000 ALTER TABLE `TRANSACTION` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `VALIDATION`
--

DROP TABLE IF EXISTS `VALIDATION`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `VALIDATION` (
  `clientId` varchar(8) NOT NULL,
  `v_type` varchar(20) NOT NULL,
  `identifier` varchar(20) NOT NULL,
  `document` varchar(20) NOT NULL,
  PRIMARY KEY (`clientId`,`v_type`),
  CONSTRAINT `VALIDATION_ibfk_1` FOREIGN KEY (`clientId`) REFERENCES `CLIENTS` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `VALIDATION`
--

LOCK TABLES `VALIDATION` WRITE;
/*!40000 ALTER TABLE `VALIDATION` DISABLE KEYS */;
INSERT INTO `VALIDATION` VALUES ('C0000001','ID','copy','proof.pdf'),('C0000002','ID','copy','proof.pdf'),('C0000003','ID','copy','proof.pdf'),('C0000004','ID','copy','proof.pdf'),('C0000005','ID','copy','proof.pdf'),('C0000007','ID','copy','proof.pdf');
/*!40000 ALTER TABLE `VALIDATION` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2022-04-06  7:56:37
