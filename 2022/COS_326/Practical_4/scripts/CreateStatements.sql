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
	courseRegistration text[]
) INHERITS (Student);

CREATE TABLE Postgraduate (
	category cat NOT NULL,
	ttitle p_title NOT NULL,
	tfirstName VARCHAR(50) NOT NULL,
	tsurname VARCHAR(50) NOT NULL
) INHERITS (Student);

CREATE TABLE deletedUndergraduate (
	timeOfDel timestamp,
	userid VARCHAR(255)
) INHERITS (Undergraduate);

CREATE TABLE deletedPostgraduate (
	timeOfDel timestamp,
	userid VARCHAR(255)
)INHERITS (Postgraduate);

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

CREATE FUNCTION isRegisteredFor(Undergraduate, y text) RETURNS boolean AS $$
	SELECT $2 = ANY($1.courseRegistration);
$$ LANGUAGE SQL;

CREATE FUNCTION isValidCourseCode(VARCHAR(6)) RETURNS boolean AS $$
DECLARE
	r record;
	b boolean := false;
BEGIN
	FOR r IN
		SELECT courseCode FROM Course
	LOOP
		IF $1 = r.courseCode THEN
			RETURN NOT b;
		END IF;
	END LOOP;
	RETURN b;
END;
$$ LANGUAGE plpgsql;

CREATE FUNCTION isValidDegreeCode(VARCHAR(3)) RETURNS boolean AS $$
DECLARE
	r record;
	b boolean := false;
BEGIN
	FOR r IN
		SELECT degreeCode FROM DegreeProgram
	LOOP
		IF $1 = r.degreeCode THEN
			RETURN NOT b;
		END IF;
	END LOOP;
	RETURN b;
END;
$$ LANGUAGE plpgsql;

CREATE FUNCTION hasValidCourseCodes(text[]) RETURNS boolean AS $$
DECLARE
  	b boolean := true;
  	x text;
BEGIN
	FOREACH x IN ARRAY $1
	LOOP
    	IF NOT isValidCourseCode(x) THEN
	  		RETURN NOT b;
		END IF;
  	END LOOP;
	RETURN b;
END;
$$ LANGUAGE plpgsql;

CREATE FUNCTION courseCodeFrequency(VARCHAR(6), text[]) RETURNS int AS $$
DECLARE
  	i int := 0;
  	x text;
BEGIN
	FOREACH x IN ARRAY $2
	LOOP
    	IF $1 = x THEN
	  		i := i + 1;
		END IF;
  	END LOOP;
	RETURN i;
END;
$$ LANGUAGE plpgsql;

CREATE FUNCTION hasDuplicateCourseCodes(text[]) RETURNS boolean AS $$
DECLARE
  	b boolean := false;
	i int := 0;
  	x text;
	y text;
BEGIN
	FOREACH x IN ARRAY $1
	LOOP
    	FOREACH y IN ARRAY $1
		LOOP
			IF x = y THEN
				i := i + 1;
			END IF;
		END LOOP;
		
		IF i - 1 <> 0 THEN
			RETURN NOT b;
		END IF;
		
		i := 0;
  	END LOOP;
	RETURN b;
END;
$$ LANGUAGE plpgsql;

CREATE FUNCTION check_valid_degree_code() RETURNS trigger AS $check_valid_degree_code$
BEGIN
	IF NOT isValidDegreeCode(NEW.degreeCode) THEN
		RAISE EXCEPTION 'Degree code is not valid.';
	END IF;
	
	RETURN NEW;
END;
$check_valid_degree_code$ LANGUAGE plpgsql;

CREATE TRIGGER check_valid_degree BEFORE INSERT OR UPDATE ON Student
    FOR EACH ROW EXECUTE PROCEDURE check_valid_degree_code();
	
CREATE TRIGGER check_valid_degree BEFORE INSERT OR UPDATE ON Postgraduate
    FOR EACH ROW EXECUTE PROCEDURE check_valid_degree_code();

CREATE TRIGGER check_valid_degree BEFORE INSERT OR UPDATE ON Undergraduate
    FOR EACH ROW EXECUTE PROCEDURE check_valid_degree_code();
	
CREATE FUNCTION check_valid_course_codes() RETURNS trigger AS $check_valid_course_codes$
BEGIN
	IF NOT hasValidCourseCodes(NEW.courseRegistration) THEN
		RAISE EXCEPTION 'One of the Course codes is not valid.';
	END IF;
	IF hasDuplicateCourseCodes(NEW.courseRegistration) THEN
		RAISE EXCEPTION 'There are duplicate course codes.';
	END IF;
	
	RETURN NEW;
END;
$check_valid_course_codes$ LANGUAGE plpgsql;

CREATE TRIGGER check_valid_course_registration BEFORE INSERT OR UPDATE ON Undergraduate
    FOR EACH ROW EXECUTE PROCEDURE check_valid_course_codes();
	
CREATE FUNCTION record_delete_undergrad() RETURNS trigger AS $record_delete_undergrad$
BEGIN
	INSERT INTO deletedUndergraduate VALUES (OLD.*, current_timestamp, current_user);
	RETURN OLD;
END;
$record_delete_undergrad$ LANGUAGE plpgsql;

CREATE TRIGGER audit_delete_undergrad BEFORE DELETE ON Undergraduate
    FOR EACH ROW EXECUTE PROCEDURE record_delete_undergrad();
	
CREATE FUNCTION record_delete_postgrad() RETURNS trigger AS $record_delete_postgrad$
BEGIN
	INSERT INTO deletedPostgraduate VALUES (OLD.*, current_timestamp, current_user);
	RETURN OLD;
END;
$record_delete_postgrad$ LANGUAGE plpgsql;

CREATE TRIGGER audit_delete_postgrad BEFORE DELETE ON Postgraduate
    FOR EACH ROW EXECUTE PROCEDURE record_delete_postgrad();