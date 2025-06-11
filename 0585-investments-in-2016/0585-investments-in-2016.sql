# Write your MySQL query statement below
-- select distinct sum(tiv_2016), lat, lon from Insurance group by tiv_2015

-- select sum(arg2.tiv_2016) as tiv_2016 from (select round(sum(tiv_2016), 2) as tiv_2016 from (select * from Insurance group by lat, lon having count(*) = 1) as arg group by arg.tiv_2015 having count(*) > 1) as arg2 

#select round(sum(s1), 2) as tiv_2016 from 
#(select sum(tiv_2016) as s1 from 
#(select * from Insurance group by lat, lon having count(*) = 1) as arg1
#group by tiv_2015 having count(*) > 1) as 
with tiv as (
    select tiv_2015 from insurance 
    group by tiv_2015 having count(*) > 1
),
latlon as (
    select * from insurance 
    group by lat, lon having count(*) = 1 
)

select round(sum(tiv_2016 ), 2) as tiv_2016  from latlon where tiv_2015 in (select tiv_2015 from tiv)