# Write your MySQL query statement below
with cte1 as (
    select sale_date, sold_num from Sales where fruit = 'apples'
), cte2 as (
    select sale_date, sold_num from Sales where fruit = 'oranges'
) select cte1.sale_date, cte1.sold_num - cte2.sold_num as diff from cte1 left join cte2 on (cte1.sale_date = cte2.sale_date)
    union 
 select cte2.sale_date, cte1.sold_num - cte2.sold_num as diff from cte2 left join cte1 on (cte2.sale_date = cte1.sale_date)