# Write your MySQL query statement below

delete from Person where Person.Id in (
    select * from (
        select P.Id from Person as P where exists
        (
            select * from Person as P1 where P1.Email=P.Email and P1.Id<P.Id
        )
    ) as T
);
