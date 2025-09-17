/* Write your T-SQL query statement below */
select top 1 id, num
from (
    select accepter_id id, count(*) num
    from (
        select accepter_id, requester_id, accept_date 
        from RequestAccepted

        UNION

        select requester_id accepter_id, accepter_id requester_id, accept_date 
        from RequestAccepted
    ) tb1
    group by accepter_id
) tb
order by num desc
