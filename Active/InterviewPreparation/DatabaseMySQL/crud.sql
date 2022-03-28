#create database customer;
use customer;
create table customer_info(
    id integer auto_increment,
    first_name varchar(25),
    last_name varchar(25),
    salary integer,
    primary key(id)
);

insert into customer_info(first_name,last_name,salary) values 
('Pinxu', 'wang', 10),
('Harake','Jippo',20),
('Hangman','Truss',30),
('Hido','Minomoto',15),
('Suxi','hidi',null);

select * from customer_info where salary is not null;

# update statement 

update customer_info set salary=50 where id=5;
select * from customer_info;

# SQL delete statement 

delete from customer_info where id=5;
select * from customer_info;

# SQL alter table 
# add coloumn in table 
alter table customer_info add email varchar(25);

select * from customer_info;

update customer_info set email='pixuwang@gmail.com' where id=1;
update customer_info set email='hJippo@gmail.com' where id=2;
update customer_info set email='hangmantruss@gmail.com' where id=3;
update customer_info set email='hidomino@gmail.com' where id = 4;

select * from customer_info;

update customer_info set first_name='Pixu' where id=1;
select * from customer_info;

alter table customer_info add dob date;
select * from customer_info;

alter table customer_info modify dob year;
select * from customer_info;

desc customer_info;

# alter table to drop coloumn 

alter table customer_info drop column dob;
select * from customer_info;






