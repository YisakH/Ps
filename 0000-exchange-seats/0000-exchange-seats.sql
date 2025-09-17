/* Write your T-SQL query statement below */

select *
from (
    select *
    from seat
    where id % 2 = 1 and id = ( select max(id) from seat)

    union

    select id + 1 id, student
    from seat
    where id % 2 = 1 and id != ( select max(id) from seat)

    union

    select id - 1 id, student
    from seat
    where id % 2 = 0
) tb
order by id