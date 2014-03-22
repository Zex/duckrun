/*
 * duckrun.sql
 *
 * SQL for maintaining the duckrun database
 * 
 * Author: Zex
 */
/* create user 'duckadm'@'localhost' identified by 'ducksir'; */
create database if not exists  duckrun;
use duckrun;
create table if not exists duckinfo
(
 email char(30) not null primary key,
 birth date,
 class int(2)
);
/* alter table duckinfo add unique (email); */
/* alter table duckinfo add constraint primary key (email); */
insert into duckinfo value ("redduck@cyberspace.com", 30210105, 7);
insert into duckinfo value ("purpleduck@cyberspace.com", 20171119, 10);
insert into duckinfo value ("pinkduck@cyberspace.com", 18211002, 3);
insert into duckinfo value ("blackduck@cyberspace.com", 20200131, 1);
/* update duckinfo set email=replace(email, 'syberspace.com','cyberspace.com'); */

show variables like 'port';

/* grant all on duckrun to 'duckadm'@localhost identified by 'ducksir'; */
insert into duckinfo value ('xduck@reality.net', curdate(), 3);
select email, birth from duckinfo where birth = curdate();

create user 'duckadm'@'localhost' identified by 'riskcud';
grant all on duckrun.* to 'duckadm'@'localhost';
