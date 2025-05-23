
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

-- subquery
-- SELECT title, rental_rate FROM film
-- WHERE rental_rate > (SELECT AVG(rental_rate) FROM film)

-- SELECT film_id, title FROM film
-- WHERE film_id IN
-- (SELECT inventory.film_id FROM rental
-- INNER JOIN inventory ON inventory.inventory_id = rental.rental_id
-- WHERE return_date BETWEEN '2005-05-29' AND '2005-05-30')
-- ORDER BY film_id

-- SELECT first_name, last_name FROM customer
-- WHERE EXISTS
-- (SELECT * FROM payment
-- WHERE payment.customer_id = customer.customer_id AND amount > 11
-- )

-- Self Join
-- SELECT f1.title, f2.title, f1.length
-- FROM film AS f1
-- INNER JOIN film AS f2 ON
-- f1.film_id != f2.film_id AND f1.length = f2.length