use classicmodels;

-- task 1
select customers.customerNumber from customers inner join orders on customers.customerNumber = orders.customerNumber where orders.status="Shipped";

-- task 2
select customers.customerName from customers where customers.customerNumber in (select customerNumber from payments where amount >80000);

-- task 3
select employees.firstName from employees inner join offices on employees.officeCode=offices.officeCode where offices.country="USA" and employees.jobTitle="Sales Rep";

-- task 4
select * from employees where employeeNumber in(select employees.employeeNumber from employees, offices where employees.officeCode = offices.officeCode and offices.city="Sydney");

-- task 5
select customers.customerName, orders.orderDate from customers inner join orders on customers.customerNumber = orders.customerNumber where orders.orderNumber between 10101 and 10110;

-- task 6
select distinct productCode, productName from products where productCode in (select productCode from orderdetails where quantityOrdered > 30);