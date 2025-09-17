/* Write your T-SQL query statement below */

select round(sum(tiv_2016), 2) tiv_2016 
from insurance i
    join (
        select tiv_2015
        from insurance w1
        group by tiv_2015
        having count(*) > 1
    ) tb1 on i.tiv_2015 = tb1.tiv_2015
    join (
        select lat, lon
        from insurance w2
        group by lat, lon
        having count(*) = 1
    ) tb2 on i.lat = tb2.lat and i.lon = tb2.lon