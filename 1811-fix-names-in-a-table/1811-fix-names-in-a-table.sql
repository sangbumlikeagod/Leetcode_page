# Write your MySQL query statement below

select user_id, concat(upper(substr(name, 1, 1)), lower(substr(name, 2)))  as name from Users where name REGEXP ('[a-z][A-Z]*') order by user_id