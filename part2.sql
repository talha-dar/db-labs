-- part 2
use chess;

-- taskk 1
select * from players where fname like ("__S%");

-- task 2
select * from sponsors where sponsor_name not like ("galib") and sponsor_name not like ("azhar");

-- task 3
create table temp as (select * from tournaments T inner join on player_participated PP on T.tournaments_id=PP.tournaments_id);