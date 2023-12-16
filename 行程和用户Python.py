class Flight:
    def __init__(self, id, from_, to, date, depart, arrival):
        self.id = id
        self.from_ = from_
        self.to = to
        self.date = date
        self.depart = depart
        self.arrival = arrival


class User:
    def __init__(self, id, name, email, phone, flights):
        self.id = id
        self.name = name
        self.email = email
        self.phone = phone
        self.flights = flights


# 创建一个航班
flight = Flight(
    id="1234567890",
    from_="北京",
    to="上海",
    date="2023-07-20",
    depart="2023-07-20T10:00:00",
    arrival="2023-07-20T12:00:00",
)

# 创建一个用户
user = User(
    id=1,
    name="张三",
    email="zhangsan@example.com",
    phone="13800138000",
    flights=[flight],
)

# 打印航班信息
print(flight)

# 打印用户信息
print(user)
