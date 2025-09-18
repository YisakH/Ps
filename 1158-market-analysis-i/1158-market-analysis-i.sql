/* Write your T-SQL query statement below

select u.user_id buyer_id, u.join_date, count(*) orders_in_2019 
from users u
    left join orders o on u.user_id = o.buyer_id
    left join items i on o.item_id = i.item_id
where year(o.order_date) = 2019
group by u.user_id, u.join_date*/

select u.user_id buyer_id, u.join_date, count(o.buyer_id) orders_in_2019 
from users u
    left join (
        select buyer_id, item_id
        from orders
        where year(order_date) = 2019
    ) o on u.user_id = o.buyer_id
    left join items i on o.item_id = i.item_id
group by u.user_id, u.join_date