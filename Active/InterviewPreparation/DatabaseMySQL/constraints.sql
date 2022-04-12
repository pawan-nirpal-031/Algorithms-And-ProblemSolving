# use customer;
create table student(
    id int NOT NULL,
    first_name varchar(25) NOT NULL,
    last_name varchar(25) NOT NULL,
    age int
);
alter table student modify age int NOT NULL;
create table person(
    id int NOT NULL,
    first_name varchar(25)not NULL,
    last_name varchar(25) not NULL,
    unique(id)
);

insert into person values 
(1,'Pingo', 'Suim'),
(2,'xing','Kaum'),
(3,'Uio','Xerxes');
select * from person;

alter table person add unique(first_name);
alter table person add age int;
desc person;

alter table person add constraint uc_person unique(age,first_name);
desc person;

# drop unique constraint
alter table person drop index uc_person;
desc person;

create table people (
    id int not null,
    first_name varchar(25) not null,
    last_name varchar(25), 
    age int,
    constraint pk_people primary key(id,last_name)
);

desc people;

alter table people drop primary key;
desc people;
alter table people add primary key (id);
desc people;


