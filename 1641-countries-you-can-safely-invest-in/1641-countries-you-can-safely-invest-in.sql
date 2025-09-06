# Write your MySQL query statement below
with cte1 as (
    select substr(p.phone_number, 1, 3) as cc , duration from calls as c left join Person as p on c.caller_id = p.id), cte2 as (
    select substr(p.phone_number, 1, 3) as cc , duration from calls as c left join Person as p on c.callee_id = p.id), cte3 as (
    select cc, sum(duration) / count(*) as ca from (select * from cte1 union all select * from cte2) as ct group by cc) 
    select country.name as country from cte3 left join country on cte3.cc = country.country_code  where ca > (select avg(duration) from calls)
    -- select * from cte3 left join country on cte3.cc = country.country_code 
    -- select avg(duration) from calls