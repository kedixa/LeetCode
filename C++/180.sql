# Write your MySQL query statement below
select distinct L1.Num as ConsecutiveNums from Logs as L1, Logs as L2, Logs as L3
where L1.Id=L2.Id-1 and L2.Id=L3.Id-1 and L1.Num=L2.Num and L2.Num=L3.Num;
