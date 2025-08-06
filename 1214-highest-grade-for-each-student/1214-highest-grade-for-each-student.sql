# Write your MySQL query statement below
with cte as (
    select student_id, max(grade) as highest from Enrollments group by student_id
) select r1.student_id, min(course_id) as course_id, r1.grade from Enrollments as r1 left join cte on r1.student_id = cte.student_id where cte.highest = r1.grade group by r1.student_id order by r1.student_id