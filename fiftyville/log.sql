-- Keep a log of any SQL queries you execute as you solve the mystery.
-- Query the crime scenes file
SELECT description FROM crime_scene_reports WHERE month = 7 AND day = 28 AND street = "Humphrey Street";

--Now to ascertain the witness accounts of the 3 witnesses.
SELECT transcript FROM interviews WHERE transcript LIKE "%bakery%";

--within 10 mins thief got into car (check security footage witin 10 mins (10.15am) of theft)).
SELECT month, day, hour, minute, license_plate, activity FROM bakery_security_logs WHERE year = 2021 AND month = 7 AND day = 28;

-- | 7     | 28  | 10   | 16     | 5P2BI95
-- | 7     | 28  | 10   | 18     | 94KL13X       |
-- | 7     | 28  | 10   | 18     | 6P58WS2       |
-- | 7     | 28  | 10   | 19     | 4328GD8       |
-- | 7     | 28  | 10   | 20     | G412CB7       |
-- | 7     | 28  | 10   | 21     | L93JTIZ       |
-- | 7     | 28  | 10   | 23     | 322W7JE       |
-- | 7     | 28  | 10   | 23     | 0NTHK55

--thief withdrew money at the ATM on Leggett street (expecting a large withdrawal)
SELECT account_number, amount FROM atm_transactions WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location = "Leggett Street" ORDER BY amount ASC;
 account_number | amount |
+----------------+--------+
| 86363979       | 10     |
| 28296815       | 20     |
| 25506511       | 20     |
| 81061156       | 30     |
| 26013199       | 35     |
| 28500762       | 48     |
| 49610011       | 50     |
| 76054385       | 60     |
| 16153065       | 80     |
+----------------+--------+
--account numbers above - match with bank account to get names.
SELECT person_id FROM bank_accounts WHERE account_number = 16153065;
SELECT id, name, passport_number, phone_number, license_plate FROM people WHERE license_plate = "0NTHK55";
SELECT * FROM people, bakery_security_logs, phone_calls
WHERE people.license_plate = bakery_security_logs.license_plate
AND people.phone_number = phone_calls.caller
AND phone_calls.month = 7 AND phone_calls.day = 28 AND hour = 10 AND minute > 15 AND minute < 25
AND duration < 60;
--Thief is planning to take the earliest flight tomorrow (29/7). Look for earliest flight.
SELECT * from people, passengers, flights
WHERE people.passport_number = passengers.passport_number
AND passengers.flight_id = flights.id
AND month = 7 AND day = 29;
--check phone records and location
SELECT * FROM people, phone_calls
WHERE people.phone_number = phone_calls.caller
AND name = "Bruce"
AND month = 7 AND day = 28;
--airport information/destination info.
SELECT * FROM airports WHERE id = 4;
-- name of accomplice phone call recieved on same day for less than 60 seconds.
SELECT name FROM people WHERE phone_number = "(375) 555-8161";
