DROP DATABASE IF EXISTS lab4;
CREATE DATABASE lab4;
USE lab4;

CREATE TABLE university (
    UNIV_ID INT PRIMARY KEY,
    UNIV_NAME VARCHAR(45),
    RATING INT,
    CITY VARCHAR(45)
);

CREATE TABLE student (
    STUDENT_ID INT PRIMARY KEY,
    SURNAME VARCHAR(45),
    NAME VARCHAR(20),
    STIPEND DECIMAL(6,2),
    KURS INT,
    CITY VARCHAR(45),
    BIRTHDAY DATE,
    university_UNIV_ID INT,
    FOREIGN KEY (university_UNIV_ID) REFERENCES university(UNIV_ID)
);

CREATE TABLE lecturer (
    LECTURER_ID INT PRIMARY KEY,
    SURNAME VARCHAR(45),
    NAME VARCHAR(20),
    CITY VARCHAR(45),
    university_UNIV_ID INT,
    FOREIGN KEY (university_UNIV_ID) REFERENCES university(UNIV_ID)
);

CREATE TABLE subjects (
    SUBJ_ID INT PRIMARY KEY,
    SUBJ_NAME VARCHAR(45),
    HOUR INT,
    SEMESTER INT
);

CREATE TABLE exam_marks (
    EXAM_ID INT PRIMARY KEY,
    MARK TINYINT,
    EXAM_DATE DATE,
    student_STUDENT_ID INT,
    subjects_SUBJ_ID INT,
    FOREIGN KEY (student_STUDENT_ID) REFERENCES student(STUDENT_ID),
    FOREIGN KEY (subjects_SUBJ_ID) REFERENCES subjects(SUBJ_ID)
);

CREATE TABLE subj_lect (
    LECTURER_ID INT,
    lecturer_LECTURER_ID INT,
    subjects_SUBJ_ID INT,
    PRIMARY KEY (LECTURER_ID, subjects_SUBJ_ID),
    FOREIGN KEY (lecturer_LECTURER_ID) REFERENCES lecturer(LECTURER_ID),
    FOREIGN KEY (subjects_SUBJ_ID) REFERENCES subjects(SUBJ_ID)
);

INSERT INTO university VALUES 
(1, 'МГУ', 5, 'Москва'),
(2, 'СПбГУ', 4, 'Санкт-Петербург'),
(3, 'НГУ', 4, 'Новосибирск');

INSERT INTO student VALUES 
(1, 'Иванов', 'Иван', 1500.00, 1, 'Москва', '2005-01-01', 1),
(2, 'Петров', 'Петр', 2000.00, 2, 'Москва', '2004-02-02', 1),
(3, 'Сидоров', 'Сидор', 0.00, 3, 'Новосибирск', '2003-03-03', 3),
(4, 'Архангельсков', 'Александр', 1200.00, 1, 'Санкт-Петербург', '2005-04-04', 2),
(5, 'Крювландин', 'Борис', 0.00, 4, 'Москва', '2002-05-05', NULL);

INSERT INTO lecturer VALUES 
(1, 'Смирнов', 'Алексей', 'Москва', 1),
(2, 'Кузнецова', 'Мария', 'Санкт-Петербург', 2);

INSERT INTO subjects VALUES 
(1, 'Математика', 100, 1),
(2, 'Физика', 80, 2),
(3, 'История', 60, 1);

INSERT INTO exam_marks VALUES 
(1, 5, '2024-01-10', 1, 1),
(2, 4, '2024-01-11', 1, 2),
(3, 3, '2024-01-12', 2, 1),
(4, 5, '2024-01-13', 3, 3),
(5, 4, '2024-01-14', 4, 1),
(6, 5, '2024-01-15', 4, 2);

INSERT INTO subj_lect VALUES 
(1, 1, 1),
(2, 2, 2);

SELECT '--- 1. Студенты и сданные предметы ---' AS '';
SELECT st.SURNAME, e.subjects_SUBJ_ID
FROM student st
LEFT JOIN exam_marks e ON st.STUDENT_ID = e.student_STUDENT_ID
ORDER BY st.SURNAME;

SELECT '--- 2. Студенты и рейтинг вузов ---' AS '';
SELECT st.SURNAME, u.RATING
FROM student st
LEFT JOIN university u ON st.university_UNIV_ID = u.UNIV_ID
ORDER BY st.SURNAME ASC;

SELECT '--- 3. Только хорошие оценки (4 и 5) ---' AS '';
SELECT st.SURNAME, sub.SUBJ_NAME, e.MARK
FROM exam_marks e
JOIN student st ON e.student_STUDENT_ID = st.STUDENT_ID
JOIN subjects sub ON e.subjects_SUBJ_ID = sub.SUBJ_ID
WHERE e.subjects_SUBJ_ID IN (
    SELECT subjects_SUBJ_ID
    FROM exam_marks
    GROUP BY subjects_SUBJ_ID
    HAVING MIN(MARK) >= 4
);

SELECT '--- 4. Пары студентов из одного города ---' AS '';
SELECT st1.SURNAME AS student_1, st2.SURNAME AS student_2, st1.CITY
FROM student st1
JOIN student st2 ON st1.CITY = st2.CITY
WHERE st1.STUDENT_ID < st2.STUDENT_ID
ORDER BY st1.CITY, st1.SURNAME;
