# Write your MySQL query statement below

-- select distinct e1.salary as SecondHighestSalary from employee e1 right join (select null as salary) as r on (r.salary = e1.salary); 

-- (select e1.salary as SecondHighestSalary from employee e1 left join (select null as salary) as r on (r.salary = e1.salary)
-- union  
-- select e1.salary as SecondHighestSalary from employee e1 right join (select null as salary) as r on (r.salary = e1.salary)) as newRelation
-- where newRelation.SecondHighestSalary != (select max(salary) from employee e2) ORDER by newRelation.SecondHighestSalary desc limit 1;


-- select SecondHighestSalary from (select e1.salary as SecondHighestSalary from employee e1 left join (select null as salary) as r on (r.salary = e1.salary)
-- union  
-- select e1.salary as SecondHighestSalary from employee e1 right join (select null as salary) as r on (r.salary = e1.salary)) as newRelation
--  where newRelation.SecondHighestSalary != (select max(salary) from employee e2) ORDER by newRelation.SecondHighestSalary desc limit 1;

select distinct e.SecondHighestSalary from (select e1.salary as SecondHighestSalary from employee e1 left join (select null as salary) as r on (r.salary = e1.salary)
ORDER by SecondHighestSalary DESC) as e where e.SecondHighestSalary != (select max(salary) from employee e2) union  
select e1.salary as SecondHighestSalary from employee e1 right join (select null as salary) as r on (r.salary = e1.salary) order by SecondHighestSalary DESC limit 1;



-- select null as salary
# where e1.salary != (select max(salary) from employee e2) ORDER by e1.salary desc limit 1;
 
# != (SELECT MAX(e2.salary) from e2);
# where e.salary != MAX(e.salary);
# ORDER BY salary DESC LIMIT 1
