show databases;

use classicmodels;

-- task1
select firstName, city from employees, offices where employees.officeCode=offices.officeCode;

-- task2
select country from employees, offices where employees.officeCode=offices.officeCode and jobTitle="vp sales" or jobTitle="vp marketing";

-- task3
select * from orders where shippedDate like ('2003%');

-- task4
select customerName, phone from customers, payments where customers.customerNumber=payments.customerNumber and amount>=40000 and amount<=80000;

-- task5
create table temp( select productName, productVendor from products where productVendor not like('min lin diecast'));
select * from temp where productVendor not like ('red start diecast');


-- task6
select city from offices where addressLine1 like('%Market%') or addressLine2 like('%Market%');

-- task7
select * from customers where customerName like('__LL%');

-- task 8
select distinct customerName,city,amount from customers, payments where customers.customerNumber=payments.customerNumber and amount>40000 and amount<50000 and city like('_an%');