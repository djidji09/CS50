-- Keep a log of any SQL queries you execute as you solve the mystery.

-- first we want to know what are we working with so we run .schema to see the schema of the data we have
.schema

-- we work with the data that we have : the date and the street so we see the crime scene reports that day in that street
SELECT description FROM crime_scene_reports
WHERE year = 2021
AND month = 7
AND day = 28
AND street = 'Humphrey Street';
-- we know from the description that the three witnesses mention the bakery and the time of the theft is 10:15 so we are going to look into the interviews to see detailes
SELECT transcript , name FROM interviews
WHERE year = 2021
AND month = 7
AND day = 28
AND transcript LIKE '%bakery%';


-- from the transcripts we knew so much information that before eugene got to the bakery she saw the thief withdraw money from an itm in Leggett Street and ruth saw him leave around 10 min from the theft and raymond heard him talk on the phone to someone less than a minute and told him to buy a flight ticket out of fifyville
-- so we are gonna look into the bakery security to see the car that left around ten minutes after the theft
SELECT bakery_security_logs.license_plate,people.name FROM bakery_security_logs
JOIN people ON bakery_security_logs.license_plate=people.license_plate
WHERE year = 2021
AND month = 7
AND day = 28
AND hour =10
AND minute >= 15
AND minute <= 25
AND activity='exit';
-- so we got a list of cars that left ar around 10 minutes from the theft
-- now we search about the atm on leggitt street
SELECT atm_transactions.account_number,people.name FROM atm_transactions
JOIN bank_accounts ON bank_accounts.account_number=atm_transactions.account_number
JOIN people ON people.id=bank_accounts.person_id
WHERE year = 2021
AND month = 7
AND day = 28
AND transaction_type ='withdraw'
AND atm_location = 'Leggett Street';
-- now we've got a list of all the peaple that withdrawed money on leggit street
-- now we have to see the phone calls after the theft and under a minute
SELECT caller,name FROM phone_calls
JOIN people ON phone_calls.caller=people.phone_number
WHERE year = 2021
AND month = 7
AND day = 28
AND duration <=60;
SELECT receiver,name FROM phone_calls
JOIN people ON phone_calls.receiver=people.phone_number
WHERE year = 2021
AND month = 7
AND day = 28
AND duration <=60;
--now we found out that a list of phone calls that has our suspect in there
-- now we are gonna search about the first flight tomorow wich is the 29/07/2021
SELECT airports.city AS origin_city FROM airports
JOIN flights ON flights.origin_airport_id=airports.id
WHERE year = 2021
AND month = 7
AND day = 29
ORDER BY hour DESC
LIMIT 1 ;
SELECT airports.city AS destination_city FROM airports
JOIN flights ON flights.destination_airport_id=airports.id
WHERE year = 2021
AND month = 7
AND day = 29
ORDER BY hour
LIMIT 1 ;
--so now we know wich city the thief escaped to and its new york city
-- now we only have to see the passengers and compare them to the list of our suspects
SELECT name FROM people
JOIN passengers ON passengers.passport_number = people.passport_number
JOIN flights ON passengers.flight_id=flights.id
WHERE year = 2021
AND month = 7
AND day = 29
AND name IN (SELECT name FROM phone_calls
JOIN people ON phone_calls.caller=people.phone_number
WHERE year = 2021
AND month = 7
AND day = 28
AND duration <=60);
AND name IN (SELECT people.name FROM bakery_security_logs
JOIN people ON bakery_security_logs.license_plate=people.license_plate
WHERE year = 2021
AND month = 7
AND day = 28
AND hour =10
AND minute >= 15
AND minute <= 25
AND activity='exit');
-- the only person that is in the phone calls and the backery security system and on the passengers is bruce and he was talking to robin and he flew to new york city
-- this was super fun to do and its a pleasure to have the chance to study this course
