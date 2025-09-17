/* Write your T-SQL query statement below */

declare @maxval int;
set @maxval = (select max(id) from seat)

select
    case
        when id % 2 = 1 and id < (@maxval) then id + 1
        when id % 2 = 0 then id - 1
        else id
    end id,
    student
from seat
order by id