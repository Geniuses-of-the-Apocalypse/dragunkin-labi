USE lab2;

SELECT COUNT(*) AS "Amount of students"
FROM Student;

SELECT Subject AS "Subject", COUNT(*) AS "Amount of marks"
FROM Maths
GROUP BY Subject;

SELECT Subject AS "Subject", ROUND(AVG(Mark), 2) AS "GPA"
FROM Maths
GROUP BY Subject;

SELECT MAX(Mark) AS "Max point"
FROM Maths;

SELECT COUNT(*) AS "Students with 1 or more 'a'"
FROM Student
WHERE (LENGTH(LOWER(Surname)) - LENGTH(REPLACE(LOWER(Surname), 'а', ''))) > 1;
