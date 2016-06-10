#创建表，id为自动增长
create table user (
		id integer PRIMARY KEY AUTOINCREMENT,
		name varchar(20),
		password varchar(20),
		startTime timestamp
);

#插入初始值
insert into user (name, password, startTime) values ('zjf', 'zjf', current_timestamp);
insert into user (name, password, startTime) values ('lt', 'lt', current_timestamp);
insert into user (name, password, startTime) values ('cyq', 'cyq', current_timestamp);

#查询
select * from user;
select * from user where name='zjf';

#日期的使用
select date('now');
select time('now');
select datetime('now');
select jolianday('now')-jolianday('1981-12-23');
select strftime('%Y.%m.%d', 'now');
select strftime('%Y.%m.%d', 'now', 'localtime');

#带日期的查询
select id, name, password, date(startTime) from user;
select id, name, password, time(startTime) from user;
select id, name, password, datetime(startTime) from user;

#删除表
drop table user;
