Create database autoservice;
use autoservice;

Create table clients (
id Int auto_increment primary key,
fullname varchar(40) not null,
adress varchar(200) not null);

Create table car (
id Int auto_increment primary key,
make varchar(20) not null,
model varchar(20) not null,
wheels smallint not null,
client_id int not null references clients(id) on delete cascade,
master_rab int not null references masters(orders) on delete cascade,
descriptions text not null);

Create table masters(
id Int auto_increment primary key,
fullname varchar(40) not null,
price float not null,
orders varchar(40) not null);

Create role client;
grant select on masters to client;

Create role master;
grant select, insert, update, delete on car to master;

