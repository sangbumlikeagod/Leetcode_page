# Write your MySQL query statement below
with cte as (
    select * from Orders where order_date like '2020-02%'
)
select products.product_name, sum(unit) as unit from cte left join products on products.product_id = cte.product_id group by cte.product_id having sum(unit) >= 100