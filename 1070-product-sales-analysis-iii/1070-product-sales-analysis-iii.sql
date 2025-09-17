/* Write your T-SQL query statement below */

select s.product_id, s.year first_year, quantity, price
from (
    select product_id, min(year) year
    from sales
    group by product_id
) tb join sales s on tb.product_id = s.product_id and tb.year = s.year