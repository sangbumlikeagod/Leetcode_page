# Write your MySQL query statement below
select distinct t1.id, 
    case 
    when isnull(t1.p_id) then 'Root' 
    when isnull(t2.p_id) = false then 'Inner' 
    else 'Leaf' end as type from Tree as t1 left join Tree as t2 on t1.id = t2.p_id
 

--  select * from Tree as t1 left join Tree as t2 on t1.id = t2.p_id