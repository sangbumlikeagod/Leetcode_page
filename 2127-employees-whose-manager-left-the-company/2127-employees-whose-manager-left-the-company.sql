# Write your MySQL query statement below
-- select e1.employee_id from Employees as e1 left join Employees as e2 on e1.manager_id = e2.employee_id   where e1.manager_id is NULL and salary < 30000;

select e1.employee_id from Employees as e1 left join Employees as e2 on e1.manager_id = e2.employee_id  
 where (e1.manager_id is not null and e2.employee_id is NULL) and e1.salary < 30000 order by e1.employee_id asc;