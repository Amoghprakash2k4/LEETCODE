# Write your MySQL query statement below
select a.product_name, b.year, b.price
from sales b
join product a
on b.product_id=a.product_id;