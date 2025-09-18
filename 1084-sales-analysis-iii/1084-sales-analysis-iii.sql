/* Write your T-SQL query statement below */
select distinct s.product_id, p.product_name
from sales s
    join product p on s.product_id = p.product_id
where sale_date between '2019-01-01' and '2019-03-31'
    and s.product_id not in(
        select s2.product_id
        from sales s2
        where s2.sale_date < '2019-01-01' or s2.sale_date > '2019-03-31'
    )