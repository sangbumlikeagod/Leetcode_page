# Write your MySQL query statement below
select 
DATE_FORMAT(tr.trans_date, '%Y-%m') as month, 
country,
count(tr.state) as trans_count,
sum(tr.state = 'approved') as approved_count,
sum((tr.state = 'approved') * amount) as approved_total_amount,
SUM(amount) as trans_total_amount
from Transactions as tr group by DATE_FORMAT(tr.trans_date, '%Y%m'), tr.country;