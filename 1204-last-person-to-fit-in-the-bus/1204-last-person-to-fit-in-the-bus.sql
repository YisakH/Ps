

declare cur cursor
    for
        select person_name, weight
        from queue
        order by turn
    
declare 
    @person_name    varchar(40),
    @b_person_name  varchar(40),
    @weight         integer,
    @total          integer = 0

open cur
fetch next from cur into @person_name, @weight

while @@fetch_status = 0 and @total + @weight <= 1000
    begin
        set @b_person_name = @person_name
        set @total = @total + @weight
        fetch next from cur into @person_name, @weight
    end

close cur
deallocate cur

select @b_person_name as person_name