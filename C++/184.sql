# Write your MySQL query statement below
select D.Name as Department, E.Name as Employee, E.Salary from Department as D join Employee as E on D.Id = E.DepartmentId 
where E.Salary = (select max(Salary) from Employee where Employee.DepartmentId=D.Id);
