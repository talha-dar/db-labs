use classicmodels;

-- task 1
SELECT 
    C.customerName, C.customerNumber
FROM
    customers AS C
        INNER JOIN
    orders AS O ON C.customerNumber = O.customerNumber
WHERE
    O.status = 'Cancelled';
    
-- task 2
SELECT 
    p.productName
FROM
    customers c
        INNER JOIN
    orders o ON c.customerNumber = o.customerNumber
        INNER JOIN
    orderdetails od ON o.orderNumber = od.orderNumber
        INNER JOIN
    products p ON od.productCode = p.productCode
WHERE
    c.city = 'paris'
    and o.status="shipped";
                
-- task 3
select max(P.amount) from payments as P where P.paymentDate > "2004-11-03";

-- task 4
select min(P.amount) from payments as P where P.paymentDate < "2004-11-14";

-- task 5
SELECT 
    C.customerName
FROM
    customers AS C
WHERE
    C.customerNumber IN (SELECT 
            P.customerNumber
        FROM
            payments as P
        WHERE
            P.paymentDate > "2003-02-26");

-- task 6
SELECT 
    E.lastName
FROM
    employees AS E
WHERE
    E.officeCode in (select officeCode from offices where city="Sydney");
    
-- task 7
SELECT 
    C.customerName
FROM
    customers AS C
WHERE
    C.customerNumber IN (SELECT 
            P.customerNumber
        FROM
            payments AS P
        WHERE
            P.amount = (select MAX(P2.amount) from payments as P2));