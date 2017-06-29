# Write your MySQL query statement below
select Name as Customers from Customers as C where C.Id not in (select CustomerId from Orders);
