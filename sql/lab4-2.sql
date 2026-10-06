USE lab4;

SELECT DISTINCT sub.SUBJ_NAME
FROM exam_marks e
JOIN subjects sub ON e.subjects_SUBJ_ID = sub.SUBJ_ID
WHERE e.MARK > ALL (
    SELECT MARK 
    FROM exam_marks 
    WHERE subjects_SUBJ_ID = 105
);

SELECT sub.SUBJ_NAME, COUNT(e.EXAM_ID) AS marks_count
FROM subjects sub
JOIN exam_marks e ON sub.SUBJ_ID = e.subjects_SUBJ_ID
GROUP BY sub.SUBJ_ID, sub.SUBJ_NAME
HAVING COUNT(e.EXAM_ID) < (
    SELECT MAX(cnt) 
    FROM (
        SELECT COUNT(EXAM_ID) AS cnt 
        FROM exam_marks 
        GROUP BY subjects_SUBJ_ID
    ) AS counts
);

SELECT u1.UNIV_NAME AS university_1, u2.UNIV_NAME AS university_2, u1.CITY
FROM university u1
JOIN university u2 ON u1.CITY = u2.CITY
WHERE u1.UNIV_ID < u2.UNIV_ID; 

SELECT st.NAME, st.STUDENT_ID
FROM student st
WHERE st.STIPEND = (
    SELECT MAX(st2.STIPEND)
    FROM student st2
    WHERE st2.CITY = st.CITY
);

SELECT st.NAME, st.STUDENT_ID
FROM student st
WHERE st.CITY NOT IN (
    SELECT DISTINCT CITY 
    FROM university
);
