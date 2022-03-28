# create database customer;

use customer;
create table customer_info(
    id integer,
    first_name varchar(10),
    last_name varchar(10)
);
insert into customer_info(id,first_name,last_name) values (1,'Po','Ping');
select * from customer_info;
drop table customer_info;
show tables;
drop database customer;
show databases;




