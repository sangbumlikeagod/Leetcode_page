# Write your MySQL query statement below
-- select * from Visits left join Transactions on (Visits.visit_id = Transactions.visit_id);
select customer_id , sum(case when Transactions.visit_id is null then 1 END) as count_no_trans from Visits left join Transactions on (Visits.visit_id = Transactions.visit_id) where Transactions.visit_id is null group by Visits.customer_id order by count_no_trans asc;
-- select * from Visits left join Transactions on (Visits.visit_id = Transactions.visit_id);