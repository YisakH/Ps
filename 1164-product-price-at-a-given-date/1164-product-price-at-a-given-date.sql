/* Write your T-SQL query statement below */

select 
    p3.product_id,
    case 
        when p1.product_id is null then 10
        else p1.new_price
    end price
from products p1
    join (
        select product_id, max(change_date) change_date
        from products
        where change_date <= '2019-08-16'
        group by product_id
    ) p2 on p1.product_id = p2.product_id and p1.change_date = p2.change_date
    right join (
        select distinct product_id
        from products
    ) p3 on p3.product_id = p1.product_id


