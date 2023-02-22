-- INSERT INTO Undergraduate (studentNumber, title, firstName, surname, dob, degreeCode, yos, courseRegistration) VALUES (999999, 'Mr', 'Dyl', 'Kap', '1999-12-06', 'BSs', 3, '{"COS301", "COS326", "MTH301"}');
-- INSERT INTO Undergraduate (studentNumber, title, firstName, surname, dob, degreeCode, yos, courseRegistration) VALUES (999998, 'Mr', 'Dyl', 'Kap', '1999-12-06', 'BSc', 3, '{"COS301", "COS326", "MTH333"}');
-- INSERT INTO Postgraduate (studentNumber, title, firstName, surname, dob, degreeCode, yos, category, ttitle, tfirstName, tsurname) VALUES (999997, 'Mr', 'Dyl', 'Kap', '1999-12-06', 'PhS', 2, 'Full time', 'Dr', 'Anton', 'Prinsloo');

-- UPDATE Undergraduate SET degreeCode = 'BSs' WHERE studentNumber = '140010';
-- UPDATE Undergraduate SET courseRegistration = '{"COS111"}' WHERE studentNumber = '140010';
-- UPDATE Postgraduate SET degreeCode = 'PhS' WHERE studentNumber = '101122';

-- DELETE FROM Undergraduate WHERE studentNumber = '140010';
-- DELETE FROM Postgraduate WHERE studentNumber = '101122';

-- SELECT * FROM deletedUndergraduate;
-- SELECT * FROM deletedPostgraduate;