# Write your MySQL query statement below
-- (select order_date, customer_pref_delivery_date from Delivery group by customer_id order by order_date asc) as logs;
select round(sum(case when logs.c2 = logs.c3 then 1 end) / count(*), 4) * 100 as immediate_percentage from  (select argsgs.customer_id, min(order_date) as c2, min(customer_pref_delivery_date) as c3 from (select customer_id, order_date, customer_pref_delivery_date from Delivery order by order_date) as argsgs group by argsgs.customer_id) as logs;


-- select customer_id, order_date, customer_pref_delivery_date from Delivery order by order_date 

-- select argsgs.customer_id, min(order_date), min(customer_pref_delivery_date) from (select customer_id, order_date, customer_pref_delivery_date from Delivery order by order_date) as argsgs group by argsgs.customer_id