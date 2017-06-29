# Write your MySQL query statement below
select Score,(select count(*) from (select distinct Score as s  from Scores) as c where s >= Score) as Rank
from Scores order by Score desc;
