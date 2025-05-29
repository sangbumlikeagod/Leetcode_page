# Write your MySQL query statement below
-- select re1.customer_id, re1.cnt from (select distinct customer_id, count(*) as cnt from customer  group by customer_id) as re1
    
-- (select customer_id, distinct product_key, count(*) as cnt from customer group by customer_id)
-- (select distinct product_key, customer_id, count(*) as cnt from customer group by customer_id)
    -- (select count(product_key) from product)

# Write your MySQL query statement below
-- select distinct customer_id count(customer_id) as cnt from customer group by customer_id where cnt = (select count(*) from product)

-- select re1.customer_id from (select distinct product_key, customer_id, count(*) as cnt from customer group by customer_id) as re1 where re1.cnt = 2

select sub.customer_id as customer_id
from (
    select arg.customer_id, count(arg.customer_id) as cnt from 
    (select distinct product_key, customer_id from customer) 
    as arg group by customer_id 
) as sub
    where sub.cnt = (select count(product_key) as cnt from product)

-- ((select count(product_key) from product) = 2)
-- select distinct customer_id count(customer_id) as cnt from customer group by customer_id where cnt = (select count(*) from product)


-- select distinct customer_id, count(*) as cnt from customer  group by customer_id

-- select count(product_key) from product