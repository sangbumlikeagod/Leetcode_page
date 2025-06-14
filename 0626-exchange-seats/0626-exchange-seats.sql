# Write your MySQL query statement below

# 1차 join
-- select * from (Seat s1 left join Seat s2 on s1.id = s2.id - 1) 
# 2차 join
-- select * from (select s1.id as mId, s1.student as rS, s2.student as sS from (Seat s1 left join Seat s2 on s1.id = s2.id - 1)) s3 left join Seat s4 on s3.mId = s4.id + 1
-- 3차 select
select s3.mId as id, case when s3.mId % 2 = 1 then ifnull(s3.sS, s3.rS) else ifnull(s4.student, s3.rS) end as student from (select s1.id as mId, s1.student as rS, s2.student as sS from (Seat s1 left join Seat s2 on s1.id = s2.id - 1)) s3 left join Seat s4 on s3.mId = s4.id + 1