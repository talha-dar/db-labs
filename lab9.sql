use classicmodels;

show tables;

-- task 1
select customername,(select count(ordernumber)from orders where customers.customernumber = orders.customernumber)from customers;

-- task 2
select productname, (select sum(quantityordered) from orderdetails where orderdetails.productcode = products.productcode) from  products;