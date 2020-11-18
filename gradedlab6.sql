-- import database from file world.sql

use world;

-- task1
select distinct Region from country where LifeExpectancy<50;

-- task2
select Language from countrylanguage where isOfficial='F' and percentage between 50 and 80 ;

-- task3
select Name from country where Name like('C_i%'); 

-- task4
create table temp(select Code, LocalName from country where LocalName not like ('congo'));
select Code, LocalName from temp where LocalName not like ('chile');

-- task5
select Code, Language from country, countryLanguage where country.Code=countrylanguage.CountryCode and IndepYear like('198_');
