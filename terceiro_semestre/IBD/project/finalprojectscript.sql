CREATE DATABASE IF NOT EXISTS asa439ict301;

-- -----------------------------------------------------
-- Table `asa439ict301`.`Student`
-- -----------------------------------------------------

CREATE TABLE IF NOT EXISTS `asa439ict301`.`Student` (
  `StudentID` INT NOT NULL AUTO_INCREMENT,
  `Email` VARCHAR(45) NOT NULL,
  `Major` VARCHAR(45) NOT NULL,
  `Year` YEAR NOT NULL,
  `FirstName` VARCHAR(45) NOT NULL,
  `LastName` VARCHAR(45) NOT NULL,
  PRIMARY KEY (`StudentID`))
  AUTO_INCREMENT = 1;

-- -----------------------------------------------------
-- Table `asa439ict301`.`Department`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `asa439ict301`.`Department` (
  `DepartmentID` INT NOT NULL AUTO_INCREMENT,
  `DepartmentName` VARCHAR(45) NOT NULL,
  PRIMARY KEY (`DepartmentID`))
  AUTO_INCREMENT = 1;


-- -----------------------------------------------------
-- Table `asa439ict301`.`Course`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `asa439ict301`.`Course` (
  `CourseID` INT NOT NULL AUTO_INCREMENT,
  `CourseName` VARCHAR(45) NOT NULL,
  `DepartmentID` INT NOT NULL,
  PRIMARY KEY (`CourseID`),
  FOREIGN KEY (`DepartmentID`)
    REFERENCES `asa439ict301`.`Department` (`DepartmentID`)
    ON UPDATE CASCADE
    ON DELETE CASCADE)
  AUTO_INCREMENT = 1;

-- -----------------------------------------------------
-- Table `asa439ict301`.`Instructor`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `asa439ict301`.`Instructor` (
  `InstructorID` INT NOT NULL AUTO_INCREMENT,
  `DepartmentID` INT NOT NULL,
  `Email` VARCHAR(45) NOT NULL,
  `FirstName` VARCHAR(45) NOT NULL,
  `LastName` VARCHAR(45) NOT NULL,
  PRIMARY KEY (`InstructorID`),
  FOREIGN KEY (`DepartmentID`)
    REFERENCES `asa439ict301`.`Department` (`DepartmentID`)
    ON UPDATE CASCADE
    ON DELETE CASCADE)
  AUTO_INCREMENT = 1;



-- -----------------------------------------------------
-- Table `asa439ict301`.`Classroom`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `asa439ict301`.`Classroom` (
  `ClassroomID` INT NOT NULL AUTO_INCREMENT,
  `Building` VARCHAR(45) NOT NULL,
  `RoomNum` INT NOT NULL,
  `Capacity` INT NOT NULL,
  PRIMARY KEY (`ClassroomID`))
  AUTO_INCREMENT = 1;


-- -----------------------------------------------------
-- Table `asa439ict301`.`CourseOfferings`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `asa439ict301`.`CourseOfferings` (
  `OfferingID` INT NOT NULL AUTO_INCREMENT,
  `CourseID` INT NOT NULL,
  `InstructorID` INT NOT NULL,
  `ClassroomID` INT NOT NULL,
  `Semester` VARCHAR(45) NOT NULL,
  `Year` YEAR NOT NULL,
  PRIMARY KEY (`OfferingID`),
  FOREIGN KEY (`CourseID`)
    REFERENCES `asa439ict301`.`Course` (`CourseID`)
    ON UPDATE CASCADE
    ON DELETE CASCADE,
  FOREIGN KEY (`InstructorID`)
    REFERENCES `asa439ict301`.`Instructor` (`InstructorID`)
    ON UPDATE CASCADE
    ON DELETE CASCADE,
  FOREIGN KEY (`ClassroomID`)
    REFERENCES `asa439ict301`.`Classroom` (`ClassroomID`)
    ON UPDATE CASCADE
    ON DELETE CASCADE)
    AUTO_INCREMENT = 1;
    

-- -----------------------------------------------------
-- Table `asa439ict301`.`Grade`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `asa439ict301`.`Grade` (
  `GradeID` INT NOT NULL AUTO_INCREMENT,
  `GradeValue` VARCHAR(5) NOT NULL,
  `StudentID` INT NOT NULL,
  `OfferingID` INT NOT NULL,
  PRIMARY KEY (`GradeID`),
  FOREIGN KEY (`StudentID`)
    REFERENCES `asa439ict301`.`Student` (`StudentID`)
    ON UPDATE CASCADE
    ON DELETE CASCADE,
  FOREIGN KEY (`OfferingID`)
    REFERENCES `asa439ict301`.`CourseOfferings` (`OfferingID`)
    ON UPDATE CASCADE
    ON DELETE CASCADE)
    AUTO_INCREMENT = 1;


-- -----------------------------------------------------
-- Table `asa439ict301`.`AcademicCredits`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `asa439ict301`.`AcademicCredits` (
  `CreditID` INT NOT NULL AUTO_INCREMENT,
  `OfferingID` INT NOT NULL,
  `Credits` INT NOT NULL,
  PRIMARY KEY (`CreditID`),
  FOREIGN KEY (`OfferingID`)
    REFERENCES `asa439ict301`.`CourseOfferings` (`OfferingID`)
    ON UPDATE CASCADE
    ON DELETE CASCADE)
    AUTO_INCREMENT = 1;
   
-- -----------------------------------------------------
-- Table `asa439ict301`.`Enrollments`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `asa439ict301`.`Enrollments` (
  `EnrollmentID` INT NOT NULL AUTO_INCREMENT,
  `StudentID` INT NOT NULL,
  `OfferingID` INT NOT NULL,
  PRIMARY KEY (`EnrollmentID`),
  FOREIGN KEY (`StudentID`)
    REFERENCES `asa439ict301`.`Student` (`StudentID`)
    ON UPDATE CASCADE
    ON DELETE CASCADE,
  FOREIGN KEY (`OfferingID`)
    REFERENCES `asa439ict301`.`CourseOfferings` (`OfferingID`)
    ON UPDATE CASCADE
    ON DELETE CASCADE)
    AUTO_INCREMENT = 1;