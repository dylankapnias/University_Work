-- DROP SEQUENCE
DROP SEQUENCE IF EXISTS staff_seq CASCADE;

-- CREATE SEQUENCE
CREATE SEQUENCE staff_seq AS INT START 1;

-- DROP TABLES
DROP TABLE IF EXISTS xml_staff_list;
DROP TABLE IF EXISTS xml_staff;
DROP TABLE IF EXISTS shred_staff_list;

-- CREATE TABLES
CREATE TABLE xml_staff_list(
	filename TEXT PRIMARY KEY NOT NULL, 
	xml_document XML NOT NULL);
							
CREATE TABLE xml_staff(
-- 	entry_number INT DEFAULT NEXTVAL('staff_seq') PRIMARY KEY NOT NULL, 
	entry_number INT PRIMARY KEY NOT NULL,
	xml_data XML NOT NULL);

CREATE TABLE shred_staff_list(
	branchNo VARCHAR(4) NOT NULL, 
	staffNo VARCHAR(4) NOT NULL, 
	fname VARCHAR(50) NOT NULL, 
	lname VARCHAR(50) NOT NULL, 
	position VARCHAR(50) NOT NULL, 
	DOB TEXT, 
	salary FLOAT NOT NULL);
		 
-- DROP FUNCTIONS
DROP FUNCTION IF EXISTS loadXMLfragments;
DROP FUNCTION IF EXISTS loadshreddedXML;

-- CREATE FUNCTIONS
CREATE FUNCTION loadXMLfragments(TEXT, XML) RETURNS BOOLEAN AS $$
DECLARE
	i INT := 0;
	b BOOLEAN := true;
	x XML;
BEGIN
	FOR x IN
		SELECT unnest(xpath($1, $2))
	LOOP
		i := i + 1;
		INSERT INTO xml_staff VALUES (i, x);
	END LOOP;
	
	RETURN b;
END;
$$ LANGUAGE plpgsql;

CREATE FUNCTION loadshreddedXML(TEXT, XML) RETURNS BOOLEAN AS $$
DECLARE
	bNo VARCHAR(4); 
	sNo VARCHAR(4); 
	fna VARCHAR(50); 
	lna VARCHAR(50); 
	po VARCHAR(50); 
	DOB TEXT; 
	sa FLOAT;
	b BOOLEAN := true;
	x XML;
BEGIN
	FOR x IN
		SELECT unnest(xpath($1, $2))
	LOOP
		bNo := CAST(unnest(xpath('//@branchNo', x)) AS VARCHAR(4));
		sNo := CAST(unnest(xpath('//STAFFNO/text()', x)) AS VARCHAR(4));
		fna := CAST(unnest(xpath('//NAME/FNAME/text()', x)) AS VARCHAR(50));
		lna := CAST(unnest(xpath('//NAME/LNAME/text()', x)) AS VARCHAR(50));
		po := CAST(unnest(xpath('//POSITION/text()', x)) AS VARCHAR(50));
		DOB := CAST(unnest(xpath('//DOB/text()', x)) AS TEXT);
		sa := CAST(unnest(xpath('//SALARY/text()', x)) AS TEXT)::FLOAT;
		INSERT INTO shred_staff_list VALUES (bNo, sNo, fna, lna, po, DOB, sa);
	END LOOP;
	
	RETURN b;
END;
$$ LANGUAGE plpgsql;

-- INSERT INTO TABLES
INSERT INTO xml_staff_list VALUES (
	'staff_list.xml', 
	CAST(pg_read_file('./MyXMLfiles/staff_list.xml') 
		 AS xml));
		 
DO $$
BEGIN
	PERFORM loadXMLfragments('//STAFF', (SELECT xml_document FROM xml_staff_list));
END $$;

DO $$
BEGIN
	PERFORM loadshreddedXML('//STAFF', (SELECT xml_document FROM xml_staff_list));
END $$;