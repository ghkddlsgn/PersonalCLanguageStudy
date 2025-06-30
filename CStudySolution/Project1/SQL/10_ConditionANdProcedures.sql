-- import and export
-- CREATE TABLE simple(
--     a INTEGER,
--     b INTEGER,
--     c INTEGER
-- );

COPY simple FROM 'E:\Program\PersonalCLanguageStudy\CStudySolution\Project1\SQL\simple_table.csv'
WITH (FORMAT csv, HEADER true);

INSERT INTO simple(
    a,b,c
)
VALUES
(1,1,1),
(2,2,2),
(3,3,3);

COPY simple to 'E:\Program\PersonalCLanguageStudy\CStudySolution\Project1\SQL\simple_table2.csv'
WITH (FORMAT csv, HEADER true);
SELECT * FROM simple;

-- VIEWS
-- CREATE VIEW customer_info AS
-- SELECT first_name, last_name, address FROM customer
-- INNER JOIN address
-- ON customer.address_id = address.address_id;

-- CREATE OR REPLACE VIEW customer_info AS
-- SELECT first_name, last_name, address, district FROM customer
-- INNER JOIN address
-- ON customer.address_id = address.address_id;

-- SELECT * FROM customer_info;

-- ALTER VIEW customer_info RENAME TO c_info;
-- DROP VIEW IF EXISTS c_info;


-- NULLIF
-- CREATE TABLE depts(
--     first_name VARCHAR(50),
--     department VARCHAR(50)
-- );

-- INSERT INTO depts(
--     first_name, department
-- )
-- VALUES
-- ('Vinton', 'A'),
-- ('Lauren', 'A'),
-- ('Claire', 'B');

-- SELECT(
--     SUM(CASE WHEN department = 'A' THEN 1 ELSE 0 END)/
--     SUM(CASE WHEN department = 'B' THEN 1 ELSE 0 END)    
-- ) AS department_ratio
-- FROM depts;

-- DELETE FROM depts
-- WHERE department = 'B';

-- SELECT(
--     SUM(CASE WHEN department = 'A' THEN 1 ELSE 0 END)/
--     NULLIF(SUM(CASE WHEN department = 'B' THEN 1 ELSE 0 END), 0)
-- ) AS department_ratio
-- FROM depts;

-- SELECT * FROM depts

-- CAST
-- SELECT CAST('5' AS INTEGER);
-- SELECT inventory_id, CHAR_LENGTH(CAST(inventory_id AS VARCHAR)) FROM rental

-- COALESCE
-- SELECT item,(price - COALESCE(discount, 0))
-- AS final FROM TABLE


-- Case
-- SELECT customer_id,
-- CASE
--     WHEN (customer_id <= 100) THEN 'Premium'
--     WHEN (customer_id BETWEEN 100 and 200) THEN 'Plus'
--     ELSE 'Normal'
-- END AS customer_class
-- FROM customer;

-- SELECT customer_id,
-- CASE customer_id
--     WHEN 2 THEN 'Winner'
--     WHEN 5 THEN 'Second place'
--     ELSE 'Normal'
-- END AS raffle_results
-- FROM customer;

-- SELECT
-- SUM(CASE rental_rate
--     WHEN 0.99 THEN 1
--     ELSE 0
-- END) AS bargains,
-- SUM(CASE rental_rate
--     WHEN 2.99 THEN 1
--     ELSE 0
-- END) AS regular,
-- SUM(CASE rental_rate
--     WHEN 4.99 THEN 1
--     ELSE 0
-- END) AS premium
-- FROM film

-- SELECT 
--     COUNT(CASE WHEN rental_rate = 0.99 THEN 1 END) AS count_099,
--     COUNT(CASE WHEN rental_rate = 2.99 THEN 1 END) AS count_299,
--     COUNT(CASE WHEN rental_rate = 4.99 THEN 1 END) AS count_499
-- FROM film;

-- SELECT
-- SUM(
--     CASE rating
--     WHEN 'PG' THEN 1 ELSE 0
--     END
-- ) AS pg,

-- SUM(
--     CASE rating
--     WHEN 'R' THEN 1 ELSE 0
--     END
-- ) AS r,
-- SUM(
--     CASE rating
--     WHEN 'PG-13' THEN 1 ELSE 0
--     END
-- ) AS pg13
-- FROM film