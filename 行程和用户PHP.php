<?php

// 航班对象
class Flight {
    public $id;
    public $from;
    public $to;
    public $date;
    public $depart;
    public $arrival;

    public function __construct($id, $from, $to, $date, $depart, $arrival) {
        $this->id = $id;
        $this->from = $from;
        $this->to = $to;
        $this->date = $date;
        $this->depart = $depart;
        $this->arrival = $arrival;
    }
}

// 用户对象
class User {
    public $id;
    public $name;
    public $email;
    public $phone;
    public $flights;

    public function __construct($id, $name, $email, $phone, $flights) {
        $this->id = $id;
        $this->name = $name;
        $this->email = $email;
        $this->phone = $phone;
        $this->flights = $flights;
    }
}

// 创建一个航班
$flight = new Flight(
    "1234567890",
    "北京",
    "上海",
    new DateTime("2023-07-20"),
    new DateTime("2023-07-20T10:00:00"),
    new DateTime("2023-07-20T12:00:00")
);

// 创建一个用户
$user = new User(
    1,
    "张三",
    "zhangsan@example.com",
    "13800138000",
    [
        $flight,
    ]
);

// 打印航班信息
echo $flight;

// 打印用户信息
echo $user;
?>
