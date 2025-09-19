/* Write your T-SQL query statement below */


select round(count(*) * 100.0 / (select count(distinct customer_id) from Delivery), 2) immediate_percentage 
from delivery d1
    join (
        select customer_id, min(order_date) order_date                  
        from delivery d2
        group by customer_id
    ) d2 on d1.customer_id = d2.customer_id and d1.order_date = d2.order_date
where d1.order_date = d1.customer_pref_delivery_date