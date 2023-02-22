INSERT INTO Course (courseCode, courseName, department, credits) VALUES
	('COS301', 'Software Engineering', 'Computer Science', 40),
	('COS326', 'Database Systems', 'Computer Science', 20),
	('MTH301', 'Discrete Mathematics', 'Mathematics', 15),
	('PHL301', 'Logical', 'Philosophy', 15);

INSERT INTO DegreeProgram (degreeCode, degreeName, noy, faculty) VALUES
	('BSc', 'Bachelor of Science', 3, 'EBIT'),
 	('BIT', 'Bachelor of IT', 4, 'EBIT'),
	('PhD', 'Philosophiae Doctor', 5, 'EBIT');

INSERT INTO Undergraduate (studentNumber, title, firstName, surname, dob, degreeCode, yos, courseRegistration) VALUES (140010, 'Mr', 'Sheunesu', 'Makura', '1996-01-10', 'BSc', 3, '{"COS301", "COS326", "MTH301"}');

INSERT INTO Undergraduate (studentNumber, title, firstName, surname, dob, degreeCode, yos, courseRegistration) VALUES (140015, 'Mrs', 'Thando', 'Mandela', '1995-05-25', 'BSc', 3, '{"COS301", "PHL301", "MTH301"}');

INSERT INTO Undergraduate (studentNumber, title, firstName, surname, dob, degreeCode, yos, courseRegistration) VALUES (131120, 'Mev', 'Janie', 'Kruger', '1995-01-30', 'BIT', 3, '{"COS301", "COS326", "PHL301"}');

INSERT INTO Undergraduate (studentNumber, title, firstName, surname, dob, degreeCode, yos, courseRegistration) VALUES (131140, 'Miss', 'Palesa', 'Mohlare', '1996-02-20', 'BIT', 4, '{"COS301", "COS326", "MTH301", "PHL301"}');

INSERT INTO Postgraduate (studentNumber, title, firstName, surname, dob, degreeCode, yos, category, ttitle, tfirstName, tsurname) VALUES (101122, 'Mnr', 'James', 'Genius', '1987-06-15', 'PhD', 2, 'Full time', 'Dr', 'Anton', 'Prinsloo');

INSERT INTO Postgraduate (studentNumber, title, firstName, surname, dob, degreeCode, yos, category, ttitle, tfirstName, tsurname) VALUES (121101, 'Ms', 'Ayanda', 'Phila', '1985-04-27', 'PhD', 3, 'Part time', 'Prof', 'Jason', 'Meyer');
