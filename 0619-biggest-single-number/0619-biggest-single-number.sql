# Write your MySQL query statement below
select num from MyNumbers group by num having count(num) = 1 
union all
select null
order by num desc limit 1