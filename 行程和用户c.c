#include <stdio.h>

typedef struct Flight {
    char *id;
    char *from;
    char *to;
    char *date;
    char *depart;
    char *arrival;
} Flight;

typedef struct User {
    int id;
    char *name;
    char *email;
    char *phone;
    struct Flight **flights;
} User;

Flight *create_flight(char *id, char *from, char *to, char *date, char *depart, char *arrival) {
    Flight *flight = malloc(sizeof(Flight));
    flight->id = id;
    flight->from = from;
    flight->to = to;
    flight->date = date;
    flight->depart = depart;
    flight->arrival = arrival;
    return flight;
}

User *create_user(int id, char *name, char *email, char *phone, Flight **flights) {
    User *user = malloc(sizeof(User));
    user->id = id;
    user->name = name;
    user->email = email;
    user->phone = phone;
    user->flights = flights;
    return user;
}

void print_flight(Flight *flight) {
    printf("ID: %s\n", flight->id);
    printf("From: %s\n", flight->from);
    printf("To: %s\n", flight->to);
    printf("Date: %s\n", flight->date);
    printf("Depart: %s\n", flight->depart);
    printf("Arrival: %s\n", flight->arrival);
}

void print_user(User *user) {
    printf("ID: %d\n", user->id);
    printf("Name: %s\n", user->name);
    printf("Email: %s\n", user->email);
    printf("Phone: %s\n", user->phone);
    for (int i = 0; user->flights[i] != NULL; i++) {
        print_flight(user->flights[i]);
    }
}

int main() {
    Flight *flight = create_flight("1234567890", "北京", "上海", "2023-07-20", "2023-07-20T10:00:00", "2023-07-20T12:00:00");
    User *user = create_user(1, "张三", "zhangsan@example.com", "13800138000", &flight);

    print_flight(flight);
    print_user(user);

    return 0;
}
