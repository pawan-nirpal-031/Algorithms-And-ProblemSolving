

-- wheatherObservationStation5 

-- Query the two cities in STATION with the shortest and longest CITY names, as well as their respective lengths (i.e.: number of characters in the name). If there is more than one smallest or largest city, choose the one that comes first when ordered alphabetically.
-- The STATION table is described as follows 
select city, length(city) from station order by length(city), city limit 1;
select city, length(city) from station order by length(city) desc limit 1;





-- wheatherObservationStation6

-- staring with vowels

select city from station where city like 'A%' or city like 'E%' city like 'I%' or city like 'O%' or city like 'U%';






-- Write a query identifying the type of each record in the TRIANGLES table using its three side lengths. Output one of the following statements for each record in the table:

-- Equilateral: It's a triangle with  sides of equal length.
-- Isosceles: It's a triangle with  sides of equal length.
-- Scalene: It's a triangle with  sides of differing lengths.
-- Not A Triangle: The given values of A, B, and C don't form a triangle.
-- Input Format

-- The TRIANGLES table is described as follows:

select (
    case 
    when A=B and B=C then 'Equilateral'
    when A+B<=C or B+C<=A or A+C<=B then 'Not A Triangle'
    when A=B or B=C or C=A then 'Isosceles'
    else 'Scalene'
    end
) from TRIANGLES;





-- Query the Name of any student in STUDENTS who scored higher than  Marks. Order your output by the last three characters of each name. If two or more students both have names ending in the same last three characters (i.e.: Bobby, Robby, etc.), secondary sort them by ascending ID.


select name from students where marks>75 order by substr(name,length(name)-2,3), id;


-- Query the list of CITY names from STATION that do not start with vowels and do not end with vowels. Your result cannot contain duplicates.

select distinct city from station where not ((city like 'A%' or city like 'E%' or city like 'I%' or city like 'O%' or city like 'U%') or (city like '%a' or city like '%e' or city like '%i' or city like '%o' or city like '%u'));




-- Given the CITY and COUNTRY tables, query the names of all cities where the CONTINENT is 'Africa'.
-- Note: CITY.CountryCode and COUNTRY.Code are matching key columns.

select city.name from city, country where countrycode=code and continent='Africa';

or

select name from city where countrycode in (select code from country where continent='Africa');



-- Given the CITY and COUNTRY tables, query the sum of the populations of all cities where the CONTINENT is 'Asia'.
-- Note: CITY.CountryCode and COUNTRY.Code are matching key columns.
-- Input Format
-- The CITY and COUNTRY tables are described as follows:

select sum(population) from city where countrycode in (select code from country where continent='Asia');