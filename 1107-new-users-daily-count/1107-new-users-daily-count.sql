select 
    min_date as login_date,
    count(distinct user_id) as user_count
from (
    select
        user_id,
        min(activity_date) as min_date
    from Traffic where activity = 'login'
    group by user_id 
    having min(activity_date) >= date_sub('2019-06-30', interval 90 day) and min(activity_date) <= '2019-06-30'
) as filter1 # user_id 
group by min_date;