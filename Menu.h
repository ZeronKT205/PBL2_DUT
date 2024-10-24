#pragma once
#include <iostream>
#include "Patient.h"
#include "Doctor.h"
using namespace std;
#ifndef MENU_H
#define MENU_H
class Home {
public:
    static void welcome(); //ham in ra chu welcome
    static int printTask(); // ham in ra cac option
    static void menu();
};

class PatientMenu {
public:
    static int printTask();                    // In ra console các chức năng
    static void menu(Patient&);               // Thực hiện các chức năng menu, switchcase
    static void login();
    static void signUp();
    static void Main();
};

class DoctorMenu {
public:
    static int printTask();
    static void menu(Doctor&);                  // Thực hiện các chức năng menu, switchcase
    static void login();

    static void Main();
};

#endif
