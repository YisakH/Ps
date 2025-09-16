/* Write your T-SQL query statement below */

/*
최초 로그인 날짜를 구하고,

*/

declare @total_num INT
set @total_num = count(*)

select round(convert(float, count(*)) / (select count(distinct player_id) from activity), 2) fraction 
from (
    select player_id, min(event_date) event_date
    from activity
    group by player_id
) tb
    join Activity a on tb.player_id = a.player_id and dateadd(day, 1, tb.event_date) = a.event_date