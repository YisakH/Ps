/* Write your T-SQL query statement below */

select d.name Department , e.name Employee , e.salary Salary 
from (
    select departmentid, max(salary) salary
    from employee
    group by departmentid
) a join employee e on a.departmentid = e.departmentid and a.salary = e.salary
    join department d on e.departmentid = d.id

