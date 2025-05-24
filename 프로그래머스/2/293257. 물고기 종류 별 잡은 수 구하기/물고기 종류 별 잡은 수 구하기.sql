-- 코드를 작성해주세요
select count(ID) as FISH_COUNT, FISH_NAME
from fish_info as I
    join fish_name_info as N
    ON I.fish_type = N.fish_type
group by fish_name
order by FISH_COUNT desc