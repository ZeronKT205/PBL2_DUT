#pragma once
#ifndef AUTHENTICCATION_H
#define AUTHENTICCATION_H
#include <string>
#include "Linked_List.cpp"
#include "Schedule.h"
#include "User.h"

using namespace std;

class Authentication : public Schedule {
private:
    LinkedList<User> users;

public:
    Authentication();

    // Hàm đăng ký (signup)
    bool signup(const string& username, const string& password);

    // Hàm đăng nhập (login)
    bool login(const string& username, const string& password) const;

    // Kiểm tra xem người dùng có tồn tại hay không
    bool userExists(const string& username) const;
};
#endif
