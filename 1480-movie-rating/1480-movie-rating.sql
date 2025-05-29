# Write your MySQL query statement below


-- (select name as results 
--     from ((select name, count(*)  as cnt from MovieRating left join users on movierating.user_id = users.user_id group by movierating.user_id order by  name) order by cnt desc) as secondD limit 1)

(select threeD.name as results
from ((select name, count(*)  as cnt from MovieRating left join users on movierating.user_id = users.user_id group by movierating.user_id order by cnt desc , name) limit 1) as threeD
union all
(select thirdD.title as results from 
    ((select title, avg(rating) as aver from MovieRating left join movies on MovieRating.movie_id = movies.movie_id 
    where YEAR(MovieRating.created_at) = 2020 and MONTH(MovieRating.created_at) = 2
    group by MovieRating.movie_id 
    order by aver desc, title) limit 1) as thirdD))


    -- ((select title, avg(rating) as aver from MovieRating left join movies on MovieRating.movie_id = movies.movie_id 
    -- where YEAR(MovieRating.created_at) = 2020 and MONTH(MovieRating.created_at) = 2
    -- group by MovieRating.movie_id order by aver desc, title) limit 1) as thirdD