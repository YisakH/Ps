/* Write your T-SQL query statement below */

(select employee_id
from Employees 

except

select employee_id
from salaries)

union

(select employee_id
from salaries

except

select employee_id
from Employees )