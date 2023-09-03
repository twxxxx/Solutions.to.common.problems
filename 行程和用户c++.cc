#include <iostream>

using namespace std;

class Flight {
public:
    string id;
    string from;
    string to;
    string date;
    string depart;
    string arrival;

    Flight(string id, string from, string to, string date, string depart, string arrival) {
        this->id = id;
        this->from = from;
        this->to = to;
        this->date = date;
        this->depart = depart;
        this->arrival = arrival;
    }
};

class User {
public:
    int id;
    string name;
    string email;
    string phone;
    vector<Flight*> flights;

    User(int id, string name, string email, string phone, vector<Flight*> flights) {
        this->id = id;
        this->name = name;
        this->email = email;
        this->phone = phone;
        this->flights = flights;
    }
};

int main() {
    Flight* flight = new Flight("1234567890", "北京", "上海", "2023-07-20", "2023-07-20T10:00:00", "2023-07-20T12:00:00");
    User* user = new User(1, "张三", "zhangsan@example.com", "13800138000", {flight});

    cout << flight->id << endl;
    cout << flight->from << endl;
    cout << flight->to << endl;
    cout << flight->date << endl;
    cout << flight->depart << endl;
    cout << flight->arrival << endl;

    cout << user->id << endl;
    cout << user->name << endl;
    cout << user->email << endl;
    cout << user->phone << endl;
    for (Flight* flight : user->flights) {
        cout << flight->id << endl;
        cout << flight->from << endl;
        cout << flight->to << endl;
        cout << flight->date << endl;
        cout << flight->depart << endl;
        cout << flight->arrival << endl;
    }

    return 0;
}
