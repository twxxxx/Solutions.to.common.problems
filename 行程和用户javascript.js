// 航班对象
class Flight {
    constructor(id, from, to, date, depart, arrival) {
        this.id = id;
        this.from = from;
        this.to = to;
        this.date = date;
        this.depart = depart;
        this.arrival = arrival;
    }
}

// 用户对象
class User {
    constructor(id, name, email, phone, flights) {
        this.id = id;
        this.name = name;
        this.email = email;
        this.phone = phone;
        this.flights = flights;
    }
}

// 创建一个航班
const flight = new Flight(
    "1234567890",
    "北京",
    "上海",
    new Date(2023, 7, 20),
    new Date(2023, 7, 20, 10, 0, 0),
    new Date(2023, 7, 20, 12, 0, 0)
);

// 创建一个用户
const user = new User(
    1,
    "张三",
    "zhangsan@example.com",
    "13800138000",
    [flight]
);

// 打印航班信息
console.log(flight);

// 打印用户信息
console.log(user);
