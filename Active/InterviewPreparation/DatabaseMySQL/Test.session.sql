create table clients(
    client_id int(11) not null,
    name varchar(50) not null,
    address varchar(50) not null,
    city char(2) not null,
    phone varchar(10) default null,
    primary key(client_id)
)