# Write your MySQL query statement below
select D.Name as Department, E.Name as Employee, E.Salary from Department as D join Employee as E on D.Id = E.DepartmentId 
where (select count(distinct(E2.Salary)) from Employee as E2 
where E2.Salary > E.Salary and E2.DepartmentId=E.DepartmentId) < 3;
