
DROP DATABASE IF EXISTS lab2;
CREATE DATABASE lab2;
USE lab2;

DROP TABLE IF EXISTS Maths;
DROP TABLE IF EXISTS Student;

CREATE TABLE Student (
    idStudent INT AUTO_INCREMENT PRIMARY KEY,
    Surname VARCHAR(45),
    Name VARCHAR(20),
    Address VARCHAR(100),
    Tel VARCHAR(11)
);

CREATE TABLE Maths (
    idMaths INT AUTO_INCREMENT PRIMARY KEY,
    Subject VARCHAR(45),
    Date_mark DATE,
    Mark TINYINT,
    Student_idStudent INT,
    FOREIGN KEY (Student_idStudent) REFERENCES Student(idStudent) ON DELETE CASCADE
);

INSERT INTO Student (Surname, Name, Address, Tel) VALUES 
('Иванов', 'Иван', 'ул. Ленина д.78', '2225777'),
('Петров', 'Петр', 'ул. Мира д.10', NULL),
('Сидоров', 'Сидр', 'ул. Пушкина д.78', '5557777'),
('Абрамов', 'Алексей', 'ул. Гагарина д.5', '2323232'),
('Антонов', 'Антон', 'ул. Чехова д.12', '2345677');

INSERT INTO Maths (Subject, Date_mark, Mark, Student_idStudent) VALUES 
('Математика', '2023-10-01', 2, 1),
('Математика', '2023-10-02', 4, 2),
('Физика', '2023-10-03', 5, 3),
('Математика', '2023-10-04', 3, 4),
('Математика', '2023-10-05', 5, 5),
('Математика', '2023-10-06', 3, 5);

SELECT * FROM Student;

SELECT Surname, Tel FROM Student;

SELECT * FROM Student WHERE Tel IS NULL OR Tel = '';

SELECT Student.Surname, Maths.Subject, Maths.Mark 
FROM Student 
JOIN Maths ON Student.idStudent = Maths.Student_idStudent;

SELECT Student.Surname, Student.Name 
FROM Student 
JOIN Maths ON Student.idStudent = Maths.Student_idStudent 
WHERE Maths.Subject = 'Математика' AND Maths.Mark = 2;

SELECT CONCAT(Surname, ' ', LEFT(Name, 1)) AS Фамилия_Имя 
FROM Student 
WHERE Surname LIKE 'а%' AND Surname LIKE '%в%';

SELECT Surname, Tel 
FROM Student 
WHERE Tel REGEXP '^[2-57]+$';

SELECT Surname FROM Student WHERE Address LIKE '%д.78%';

SELECT * FROM Student WHERE Surname IN ('Иванов', 'Петров', 'Сидоров');

SELECT Surname FROM Student WHERE Surname BETWEEN 'Иванов' AND 'Сидоров' ORDER BY Surname;

SELECT DISTINCT Student.Surname 
FROM Student 
JOIN Maths ON Student.idStudent = Maths.Student_idStudent 
WHERE Maths.Subject = 'Математика' AND Maths.Mark >= 3;

SELECT DISTINCT Mark AS '5-балльная', (Mark * 20) AS '100-балльная' 
FROM Maths;
