/* Write your T-SQL query statement below */

declare @maxnum int
set @maxnum = (select count(*) from product)

select customer_id
from customer
group by customer_id
having count(distinct product_key) = (@maxnum)