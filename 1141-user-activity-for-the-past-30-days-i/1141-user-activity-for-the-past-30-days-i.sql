/* Write your T-SQL query statement below */

select activity_date day, count(distinct user_id) active_users 
from activity
where activity_date between dateadd(day, -30 + 1, '2019-07-27') and '2019-07-27'
group by activity_date