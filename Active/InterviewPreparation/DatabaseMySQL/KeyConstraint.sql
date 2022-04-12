use customer;
create table staff(
    id int not null,
    first_name varchar(25) not null,
    last_name varchar(25) not null,
    age int
);
desc staff;

alter table staff
add primary key(id);

desc staff;
alter table staff
add constraint pk_staff primary key(id, age);

desc staff;

alter table staff drop primary key;

desc staff;
drop table staff;