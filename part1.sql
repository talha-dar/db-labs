use bankschema;

-- task 1
create table employee(
    eid varchar (10),
    branch_id varchar (15),
    name varchar (25),
    address varchar (50),
    age float
);
alter table employee add primary key(eid);
alter table employee add foreign key (branch_id) references branch(branch_id);

-- task 2
alter table employee add column designation varchar(25);

-- task 3
alter table loanaccounts alter max_credit set default 1000;

-- task 4
alter table employee modify column age int;

-- task 5
alter table transaction add foreign key (eid) references employee(eid);