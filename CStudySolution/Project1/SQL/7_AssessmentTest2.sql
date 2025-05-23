-- 1
-- SELECT * FROM cd.facilities

-- 2
-- SELECT name, membercost FROM cd.facilities

-- 3
-- SELECT * FROM cd.facilities
-- WHERE membercost > 0

-- 4
-- SELECT * FROM cd.facilities
-- WHERE membercost > 0 and membercost < monthlymaintenance/50

-- 5
-- SELECT * FROM cd.facilities
-- WHERE name LIKE '%Tennis%'

-- 6
-- SELECT * FROM cd.facilities
-- WHERE facid in (1,5)

-- 7
-- SELECt * FROM cd.members
-- WHERE joindate > '2012-9-01'
-- LIMIT 10

-- 8
-- SELECT DISTINCT(surname) FROM cd.members
-- ORDER BY surname
-- LIMIT 10

-- 9
-- SELECT MAX(joindate) FROM cd.members

-- 10
-- SELECT COUNT(*) FROM cd.facilities
-- WHERE guestcost >= 10

-- 11
-- SELECT facid, SUM(slots) FROM cd.bookings GROUP BY facid
-- ORDER BY facid

-- 12
-- SELECT facid, SUM(slots) FROM cd.bookings
-- GROUP BY facid HAVING SUM(slots) > 1000

-- 13
-- SELECT cd.bookings.starttime, cd.facilities.name
-- FROM cd.bookings
-- JOIN cd.facilities ON cd.facilities.facid = cd.bookings.facid
-- WHERE cd.bookings.starttime >= '2012-09-21' AND cd.bookings.starttime < '2012-09-22'
-- AND cd.facilities.name IN ('Tennis Court 1', 'Tennis Court 2')

-- 14
-- SELECT cd.bookings.starttime FROM cd.members
-- JOIN cd.bookings ON cd.members.memid = cd.bookings.memid
-- WHERE cd.members.firstname = 'David' AND cd.members.surname = 'Farrell'