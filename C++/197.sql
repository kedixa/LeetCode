# Write your MySQL query statement below
select W1.Id from Weather as W1, Weather as W2
where W1.Temperature > W2.Temperature and TO_DAYS(W1.Date)=TO_DAYS(W2.Date)+1;
