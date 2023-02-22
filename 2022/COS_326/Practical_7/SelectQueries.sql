-- TASK 2
-- 2.1
SELECT 
	unnest(xpath('//STAFF/@branchNo', xml_data)) AS branchNo,
	unnest(xpath('//STAFF/STAFFNO/text()', xml_data)) AS staffNo,
	concat(unnest(xpath('//STAFF/NAME/FNAME/text()', xml_data)), ' ', unnest(xpath('//STAFF/NAME/LNAME/text()', xml_data))) AS name,
	unnest(xpath('//STAFF/POSITION/text()', xml_data)) AS pos,
	unnest(xpath('//STAFF/DOB/text()', xml_data)) AS DOB,
	unnest(xpath('//STAFF/SALARY/text()', xml_data)) AS sal
FROM (
SELECT unnest(xpath('//STAFF[STAFFNO = "SL21"]', xml_data)) AS xml_data FROM xml_staff
) AS temp;

-- 2.2
SELECT 
	unnest(xpath('//STAFF/@branchNo', xml_data)) AS branchNo,
	unnest(xpath('//STAFF/NAME/FNAME/text()', xml_data)),
	unnest(xpath('//STAFF/NAME/LNAME/text()', xml_data))
FROM (
SELECT unnest(xpath('//STAFF[@branchNo = "B003"]', xml_data)) AS xml_data FROM xml_staff
) AS temp;

-- 2.3
SELECT 
	unnest(xpath('//STAFF/STAFFNO/text()', xml_data)) AS staffNo,
	unnest(xpath('//STAFF/SALARY/text()', xml_data))::TEXT::INT AS sal
FROM (
SELECT unnest(xpath('//STAFF', xml_data)) AS xml_data FROM xml_staff
) AS temp;

-- 2.4
SELECT SUM(sal) FROM (
	SELECT unnest(xpath('//STAFF/SALARY/text()', xml_data))::TEXT::INT AS sal FROM xml_staff
) AS temp;

-- 2.5
SELECT ROUND(AVG(sal), 2) FROM (
	SELECT unnest(xpath('//STAFF/SALARY/text()', xml_data))::TEXT::INT AS sal FROM xml_staff
) AS temp;

-- TASK 3
-- 3.1
SELECT table_to_xmlschema('shred_staff_list', false, false, '');

-- 3.2
SELECT query_to_xml('SELECT * FROM shred_staff_list WHERE salary = 30000', false, false, '');

-- 3.3
SELECT row_to_json(newRow) FROM (
	SELECT * FROM shred_staff_list WHERE salary = 30000
) AS newRow;
