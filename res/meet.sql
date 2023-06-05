
CREATE TABLE `employee` (
  `employeeid` int(16) NOT NULL AUTO_INCREMENT,
  `employeename` varchar(14) NOT NULL CHARACTER SET utf8 COLLATE utf8_general_ci,
  `username` varchar(20) NOT NULL CHARACTER SET utf8 COLLATE utf8_general_ci,
  `phone` varchar(20) DEFAULT NULL,
  `email` varchar(100) DEFAULT NULL,
  `status` varchar(20) CHARACTER SET utf8 COLLATE utf8_general_ci DEFAULT NULL,
  `departmentid` int(16) DEFAULT NULL,
  `password` varchar(50) DEFAULT NULL,
  `role` varchar(12) CHARACTER SET utf8 COLLATE utf8_general_ci DEFAULT NULL,
  PRIMARY KEY (`employeeid`)
  CONSTRAINT `chk_phone_length` CHECK (LENGTH(`phone`) = 11)
) ENGINE=InnoDB AUTO_INCREMENT=37 DEFAULT CHARSET=utf8;












CREATE TABLE user (
id INT PRIMARY KEY AUTO_INCREMENT,
username VARCHAR(30) NOT NULL,
password VARCHAR(20) NOT NULL,
user_type ENUM('admin', 'normal') NOT NULL
);
