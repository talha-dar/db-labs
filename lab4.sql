create database lab4;

use lab4;

show databases;

create table employee(
Fname char(15),
Minit char(1),
Lname char(15),
Ssn char(9) not null,
Bdate char(10),
Address char(25),
Sex char(1),
Salary int(10) not null,
Super_ssn char(9),
Dno int(1),
primary key (Ssn)
);

create table department(
Dname char(15),
Dnumber int(1),
Mngr_ssn char(9),
Mngr_start_date char(10),
primary key (Dnumber, Mngr_ssn)
);


create table dept_locations(
Dnumber int(1),
Dlocation char(10),
primary key(Dlocation)
);

create table project(
Pname char(10),
Pnumber int(1) not null,
Plocation char(10),
Dnum int(1),
primary key (Pnumber)
);

create table works_on(
Essn char(9),
Pno int(1),
Hours int,
primary key(Essn, Pno)
);

create table dependent(
Essn char(9),
Dependent_name char(15),
Sex char(1),
Bdate char(10),
Relationship char(10),
primary key (Essn, Dependent_name)
);

insert into employee values('Jared', 'D', 'James', '111111100', '1965-05-11', '123 Peachtree, Atlanta, GA', 'M', 85000.00, NULL, 1);
insert into employee values('Jon', 'C', 'Jones', '111111101', '1966-07-10', '111 Allgood, Atlanta, GA', 'M', 45000.00, '111111100', 4);

insert into department values('Headquarters', 1, '111111100', '2016-05-11');
insert into department values('Administration', 4, '111111100', '2016-05-11');

insert into dept_locations values(1, 'Houston');
insert into dept_locations values(4, 'Stafford');

insert into project values('ProductX', 1, 'Bellaire', 1);
insert into project values('ProductY', 2, 'Sugarland', 4);

insert into works_on values('111111100', 1, 40.0);
insert into works_on values('111111101', 2, 40.0);

insert into dependent values('111111101', 'Elizabeth', 'F', '1997-02-08', 'Spouse');
insert into dependent values('111111100', 'Alice', 'F', '1995-05-11', 'Daughter');


alter table employee add constraint foreign key (Dno) references department (Dnumber) on delete cascade on update cascade;
alter table employee add constraint foreign key (Super_ssn) references employee (Ssn) on delete cascade on update cascade;

alter table department add constraint foreign key (Mngr_ssn) references employee (Ssn) on delete cascade on update cascade;

alter table dept_locations add constraint foreign key (Dnumber) references department (Dnumber) on delete cascade on update cascade;

alter table project add constraint foreign key (Dnum) references department (Dnumber) on delete cascade on update cascade;

alter table works_on add constraint foreign key (Pno) references project (Pnumber) on delete cascade on update cascade;
alter table works_on add constraint foreign key (Essn) references employee (Ssn) on delete cascade on update cascade;

alter table dependent add constraint foreign key (Essn) references employee (Ssn) on delete cascade on update cascade;