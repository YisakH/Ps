/* Write your T-SQL query statement below */

select distinct a.num ConsecutiveNums 
from logs a
    join logs b on a.id + 1 = b.id and a.num = b.num
    join logs c on b.id + 1 = c.id and b.num = c.num
