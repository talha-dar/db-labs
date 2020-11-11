create database Graded_1_0060;
use Graded_1_0060;

-- task 1
create table Person(
PersonID int not null,
Name varchar(25),
Gender char,
Age int,
Email varchar(50),
primary key(PersonID));

insert into Person values (1, "Sarah", "F",10,"sarah@ucp.edu.pk"),(2, "Nagesh", "M",28,"nagesh@gmail.com"),(3, "Arifa", "F",29,"arifa@gmail.com"),(4, "Rehan", "M",74,"rehan@nust.edu.pk"),(5, "Makhdoom", "M",159,"makhdoom@ucp.edu.pk");
select * from Person;

-- task 2
alter table Person drop column Age;
alter table Person add column City varchar(30);

update Person set City="Swat" where PersonID=1;
update Person set City="Lahore" where PersonID=2;
update Person set City="Karachi" where PersonID=3;
update Person set City="Islamabad" where PersonID=4;
update Person set City="Lahore" where PersonID=5;

select * from Person;

-- task 3
create table Contacts(
PhoneId int not null,
PersonID int,
Phone char(16),
primary key(PhoneId),
foreign key(PersonID) references Person(PersonID) on delete cascade);

insert into Contacts values (1,1,"+92-0333-1111111"),(2,4,"+92-0321-1234567"),(3,2,"+92-0321-7894561"),(4,5,"+92-0345-3453453"),(5,3,"+92-0313-1313131");
select * from Contacts;

show create table Contacts;
-- task 4
delete from Person where Name="Sarah";
select* from Contacts;	

--  task 5
create table Officer(
OfficerID int not null,
Name varchar(25),
Age int,
Gender char,
primary key(OfficerID));

insert into Officer values (1,"Affer Raza",35,"M"),(2,"Sami Saqib",26,"F"),(3,"Rehan Khan",22,"M"),(4,"Zikriya",24,"M"),(5,"Mahwand Sultan",29,"M");

select * from Officer;

-- task 6
create table Preferences(
PreferenceID int not null,
Preference varchar(30),
primary key(PreferenceID));


select * from Preferences;
-- task 7

alter table Preferences drop column Preference;
alter table Preferences add column OfficerID int; # before preferences
alter table Preferences add column Preference varchar(30);

insert into Preferences values (1,1,"Cricket"),(2,2,"Badminton"),(3,1,"Table Tennis");

select * from Preferences;

-- task 8

alter table Preferences add constraint foreign key (OfficerID) references Officer(OfficerID);

show create table Preferences;