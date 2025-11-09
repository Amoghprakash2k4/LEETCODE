# Write your MySQL query statement below
-- Option 1: LEFT JOIN
SELECT c.name AS Customers
FROM Customers c
LEFT JOIN Orders o
  ON c.id = o.customerId
WHERE o.customerId IS NULL;
