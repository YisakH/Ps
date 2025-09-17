/* Write your T-SQL query statement below 
    case 
        when tr.p_id is null then 'Root'
        when tr2.id is null then 'Leaf'
        else 'Inner'
    end
    */

select distinct tr.id,     
    case 
        when tr.p_id is null then 'Root'
        when tr2.id is null then 'Leaf'
        else 'Inner'
    end Type

from tree tr
    left join tree tr2 on tr.id = tr2.p_id
--group by 