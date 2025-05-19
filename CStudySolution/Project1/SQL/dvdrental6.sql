
-- SELECT EXTRACT(MONTH FROM payment_date) AS paymonth
-- FROM payment

-- SELECT AGE(payment_date) FROM payment

-- SELECT TO_CHAR(payment_date, 'mm/dd/YYYY') FROM payment

-- SELECT COUNT(payment_date) FROM payment
-- WHERE EXTRACT(DOW FROM payment_date) = 1

-- SELECT ROUND(rental_rate/replacement_cost,2)*100 AS percent_cost FROM film

-- SELECT  upper(first_name) || ' ' || last_name AS full_name
-- FROM customer

-- SELECT LOWER(LEFT(first_name, 1)) || last_name || '@gamil.com'
-- AS custom_email
-- FROM customer

