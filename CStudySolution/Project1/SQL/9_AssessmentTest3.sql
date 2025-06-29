CREATE TABLE students(
    student_id SERIAL PRIMARY KEY,
    first_name VARCHAR(50),
    last_name VARCHAR(50),
    homeroom_number INTEGER,
    phone VARCHAR(50) NOT NULL UNIQUE,
    email VARCHAR(100) UNIQUE,
    graduation_year INTEGER
);

CREATE TABLE teachers(
    teacher_id SERIAL PRIMARY KEY,
    first_name VARCHAR(50),
    last_name VARCHAR(50),
    homeroom_number INTEGER,
    department VARCHAR(50),
    phone VARCHAR(50) NOT NULL UNIQUE,
    email VARCHAR(100) UNIQUE
);

INSERT INTO students(first_name, last_name, phone, graduation_year, homeroom_number)
VALUES
(
    'Mark', 'Watney', '777-555-1234', 2035, 5
);

INSERT INTO teachers(first_name, last_name, homeroom_number, department, email, phone)
VALUES
(
    'Jonas', 'Salk', 5, 'Biology', 'jsalk@school.org', '777-555-4321'
);

SELECT * FROM students;
SELECT * FROM teachers;