CREATE DOMAIN stu_no_dom AS TEXT
CHECK (
	VALUE ~ '^\d{6}$'
);

CREATE TYPE u_title AS ENUM ('Ms', 'Mev', 'Miss', 'Mrs', 'Mr', 'Mnr');
CREATE TYPE p_title AS ENUM ('Ms', 'Mev', 'Miss', 'Mrs', 'Mr', 'Mnr', 'Dr', 'Prof');

CREATE TYPE cat AS ENUM ('Full time', 'Part time');

CREATE SEQUENCE stu_seq AS integer START 1;
CREATE SEQUENCE deg_seq AS integer START 1;
CREATE SEQUENCE cou_seq AS integer START 1;

CREATE TABLE DegreeProgram (
	degreeKey INT DEFAULT NEXTVAL('deg_seq') PRIMARY KEY,
	degreeCode VARCHAR(3) UNIQUE NOT NULL,
	degreeName VARCHAR(50) NOT NULL,
	noy integer NOT NULL,
	faculty VARCHAR(50) NOT NULL
);

CREATE TABLE Course (
	courseKey INT DEFAULT NEXTVAL('deg_seq') PRIMARY KEY,
	courseCode VARCHAR(6) NOT NULL,
	courseName VARCHAR(50) NOT NULL,
	department VARCHAR(50) NOT NULL,
	credits integer NOT NULL
);

CREATE TABLE Student (
	studentKey INT UNIQUE DEFAULT NEXTVAL('stu_seq') PRIMARY KEY,
	studentNumber stu_no_dom NOT NULL,
	title u_title NOT NULL,
	firstName VARCHAR(50) NOT NULL,
	surname VARCHAR(50) NOT NULL,
	dob DATE NOT NULL,
	degreeCode VARCHAR(3) NOT NULL,
	yos integer NOT NULL,
	CONSTRAINT fk_stu
    FOREIGN KEY(degreeCode) 
	REFERENCES DegreeProgram(degreeCode)
);

CREATE TABLE Undergraduate (
	studentKey integer UNIQUE DEFAULT CURRVAL('stu_seq'),
	courseRegistration text[],
	CONSTRAINT fk_under
    FOREIGN KEY(studentKey) 
	REFERENCES Student(studentKey)
);

CREATE TABLE Postgraduate (
	studentKey integer UNIQUE DEFAULT CURRVAL('stu_seq'),
	category cat NOT NULL,
	title p_title NOT NULL,
	firstName VARCHAR(50) NOT NULL,
	surname VARCHAR(50) NOT NULL,
	CONSTRAINT fk_post
    FOREIGN KEY(studentKey) 
	REFERENCES Student(studentKey)
);

CREATE FUNCTION ageInYears(Student) RETURNS text AS $$
	SELECT CONCAT_WS(' ', date_part('year', age($1.dob)), 'years');
$$ LANGUAGE SQL;

CREATE FUNCTION isFullTime(Postgraduate) RETURNS boolean AS $$
	SELECT $1.category = 'Full time';
$$ LANGUAGE SQL;

CREATE FUNCTION isPartTime(Postgraduate) RETURNS boolean AS $$
	SELECT $1.category = 'Part time';
$$ LANGUAGE SQL;

CREATE FUNCTION personFullNames(Student) RETURNS text AS $$
	SELECT CONCAT_WS(' ', $1.Title, $1.firstName, $1.surname);
$$ LANGUAGE SQL;

CREATE FUNCTION personFullNames(Postgraduate) RETURNS text AS $$
	SELECT CONCAT_WS(' ', $1.Title, $1.firstName, $1.surname);
$$ LANGUAGE SQL;

CREATE FUNCTION isRegisteredFor(Undergraduate, y text) RETURNS boolean AS $$
	SELECT $2 = ANY($1.courseRegistration);
$$ LANGUAGE SQL;