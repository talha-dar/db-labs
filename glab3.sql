use classicmodels;

-- task 1

SELECT 
    customerName
FROM
    customers
WHERE
    customerNumber IN (SELECT 
            customerNumber
        FROM
            payments
        WHERE
            amount > 30000);








-- task 2

SELECT 
    customerName
FROM
    customers
WHERE
    salesRepEmployeeNumber IN (SELECT 
            employeeNumber
        FROM
            employees,
            offices
        WHERE
            employees.officeCOde = offices.officeCode
                AND employees.jobTitle = 'Sales Rep'
                AND offices.territory = 'Japan');



-- task 3
select customerNumber from customers order by asc;

SELECT customers.customerNumber FROM customers INNER JOIN orders ON orders.customerNumber = customers.customerNumber WHERE orders.status = 'Shipped';