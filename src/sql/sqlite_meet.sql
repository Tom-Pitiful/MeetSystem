/*use meetdatabase.db;*/
/*部门表*/
CREATE TABLE department (
  departmentid INTEGER PRIMARY KEY AUTOINCREMENT,
  departmentname VARCHAR(20) DEFAULT NULL
)
/*部门表*/
INSERT INTO department(departmentid,departmentname) VALUES 
(1,'技术部'),
(2,'财务部'),
(3,'市场部'),
(4,'商务部'),
(5,'销售部'),
(6,'生产部');

/*会议室表*/
CREATE TABLE meetingroom (
  roomid INTEGER PRIMARY KEY AUTOINCREMENT,
  roomnum INTEGER NOT NULL,
  roomname VARCHAR(20) NOT NULL,
  capacity SMALLINT DEFAULT 0,
  status TEXT CHECK(status IN ('available', 'not_available')) DEFAULT 'available',
  description VARCHAR(200) DEFAULT NULL
);
/*会议室实例*/
INSERT INTO meetingroom(roomid, roomnum, roomname, capacity, status, description) VALUES 
(1, 101, '第一会议室', 15, 'available', '公共会议室'),
(2, 102, '第二会议室', 25, 'available', '管理部门会议室'),
(3, 103, '第三会议室', 12, 'not_available', '市场部专用会议室'),
(4, 401, '第四会议室', 15, 'available', '公共会议室'),
(5, 201, '第五会议室', 15, 'available', '最大会议室'),
(6, 601, '第六会议室', 12, 'available', '需要提前三天预定');


/*员工表*/
CREATE TABLE employee (
  employeeid INTEGER PRIMARY KEY AUTOINCREMENT,/*员工id*/
  employeename varchar(14) NOT NULL,/*员工名字*/
  username varchar(20) NOT NULL,/*员工用户名*/
  password varchar(50) NOT NULL,/*员工用户名对应的密码*/
  phone VARCHAR(20) DEFAULT NULL CHECK(LENGTH(phone) = 11),
  email VARCHAR(50) DEFAULT NULL CHECK(email like '%@%.%' AND email NOT LIKE '%@%@%'),
  status TEXT CHECK(status IN ('active', 'inactive')) DEFAULT 'active',/*员工状态*/
  departmentid INTEGER DEFAULT NULL,/*员工部门*/
  u_role TEXT CHECK(u_role IN ('normal', 'admin')) DEFAULT 'normal',/*员工类型*/
  FOREIGN KEY(departmentid) REFERENCES department(departmentid)
);

/*20个例子*/
INSERT INTO employee (employeename, username, phone, email, status, departmentid, password, u_role) VALUES
('张三', 'zhangsan', '13312345678', 'zhangsan@qq.com', 'active', 1, '123456', 'normal'),
('李四', 'lisi', '13512345678', 'lisi@qq.com', 'active', 2, '123456', 'normal'),
('王五', 'wangwu', '13712345678', 'wangwu@qq.com', 'active', 3, '123456', 'normal'),
('赵六', 'zhaoliu', '13912345678', 'zhaoliu@qq.com', 'active', 4, '123456', 'normal'),
('钱七', 'qianqi', '13112345678', 'qianqi@qq.com', 'inactive', 5, '123456', 'normal'),
('孙八', 'sunba', '13212345678', 'sunba@qq.com', 'inactive', 6, '123456', 'normal'),
('周九', 'zhoujiu', '13412345678', 'zhoujiu@qq.com', 'inactive', 1, '123456', 'normal'),
('吴十', 'wushi', '13612345678', 'wushi@qq.com', 'inactive', 2, '123456', 'normal'),
('郑十一', 'zhengshiyi', '13812345678', 'zhengshiyi@qq.com', 'inactive', 3, '123456', 'normal'),
('王十二', 'wangshier', '13012345678', 'wangshier@qq.com', 'inactive', 4, '123456', 'normal'),
('许十三', 'xushisan', '13301112222', 'xushisan@qq.com', 'active', 5, '123456', 'normal'),
('李十四', 'lishisi', '13501112222', 'lishisi@qq.com', 'active', 6, '123456', 'normal'),
('赵十五', 'zhao15', '13701112222', 'zhao15@qq.com', 'active', 1, '123456', 'admin'),
('钱十六', 'qian16', '13901112222', 'qian16@qq.com', 'active', 2, '123456', 'admin'),
('孙十七', 'sun17', '13101112222', 'sun17@qq.com', 'inactive', 3, '123456', 'admin'),
('周十八', 'zhou18', '13201112222', 'zhou18@qq.com', 'inactive', 4, '123456', 'admin'),
('吴十九', 'wu19', '13401112222', 'wu19@qq.com', 'inactive', 5, '123456', 'admin'),
('郑二十', 'zheng20', '13601112222', 'zheng20@qq.com', 'inactive', 6, '123456', 'admin'),
('张二十一', 'zhang21', '13801112222', 'zhang21@qq.com', 'inactive', 1, '123456', 'admin'),
('李二十二', 'li22', '13001112222', 'li22@qq.com', 'inactive', 2, '123456', 'admin');


/*会议表*/
CREATE TABLE meeting (
  meetingid INTEGER PRIMARY KEY AUTOINCREMENT, /*会议 ID*/
  meetingname varchar(20) NOT NULL,/*会议名称*/
  roomid INTEGER DEFAULT NULL,/*会议室 ID*/
  reservationistid INTEGER DEFAULT NULL,/*预定人ID*/
  numberofparticipants smallint DEFAULT NULL,/*参加人数*/
  starttime datetime DEFAULT NULL,/*会议开始时间*/
  endtime datetime DEFAULT NULL,/*会议结束时间*/
  reservationtime datetime DEFAULT NULL,/*预定时间*/
  canceledtime datetime DEFAULT NULL,/*取消时间*/
  description varchar(200) DEFAULT NULL,/*会议描述*/
  status varchar(50) DEFAULT NULL,/*会议状态*/
  canceledreason varchar(255) DEFAULT NULL,/*会议取消原因*/
  FOREIGN KEY(roomid) REFERENCES meetingroom(roomid),
  FOREIGN KEY(reservationistid) REFERENCES employee(employeeid)
);

/*存储参加会议的员工信息的表*/
CREATE TABLE meetingparticipants (
  meetingid INTEGER NOT NULL,
  employeeid INTEGER NOT NULL,
  signtime DATETIME DEFAULT NULL,
  PRIMARY KEY (meetingid, employeeid),
  FOREIGN KEY (meetingid) REFERENCES meeting(meetingid),
  FOREIGN KEY (employeeid) REFERENCES employee(employeeid)
);

