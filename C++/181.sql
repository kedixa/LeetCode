# Write your MySQL query statement below
select Name as Employee from Employee as E where E.Salary > (select Salary from Employee as E2 where E.ManagerId=E2.Id);
