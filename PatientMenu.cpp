#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Menu.h"
#include "Box.h"
using namespace std;


//Menu lua chon login hoac signup
void PatientMenu::Main() {
    system("cls");
    ifstream inFile("../PBL_DUT/Patient.txt");
    string line;
    while (getline(inFile, line)) {
        cout << line << endl;
    }
    inFile.close();

    vector<string>PatientData;
    PatientData.push_back("Login");
    PatientData.push_back("SignUp");
    PatientData.push_back("Back");

    MenuBox PatientBOX(PatientData);
    int choose = PatientBOX.menu();
    switch (choose)
    {
    case 1:
    {
        PatientMenu::login();
        system("pause");
        break;
    }

    case 2:
    {
        PatientMenu::signUp();
        system("pause");
        break;
    }

    case 3:
        Home::menu();
        break;
    }
}

//ham login
void PatientMenu::login() {
    system("cls");
    ifstream inFile("../PBL_DUT/Patient_login.txt");
    string line;
    while (getline(inFile, line)) {
        cout << line << endl;
    }
    inFile.close();
    cout << endl << endl << endl;

    string username, password;
    cout << "Username: "; cin >> username;
    cout << "Password: "; cin >> password;

    cout << username << " " << password << endl;
    int choose = PatientMenu::printTask();
    switch (choose){
    case 6:
        system("cls");
        Home::menu();;
        break;
    }
}

//ham signUp
void PatientMenu::signUp() {
    system("cls");
    ifstream inFile("../PBL_DUT/Patient_SignUp.txt");
    string line;
    while (getline(inFile, line)) {
        cout << line << endl;
    }
    cout << endl << endl << endl;
    string username, password,re_password;
    cout << "Username: "; cin >> username;
    cout << "Password: "; cin >> password;
    cout << "re-enter Password: "; cin >> re_password;
    
    cout << username << " " << password << endl;
}
//ham in ra cac lua chon chuc nang sau khi login
int PatientMenu::printTask() {
    system("cls");
    ifstream inFile("../PBL_DUT/Patient_Function.txt");
    string line;
    while (getline(inFile, line)) {
        cout << line << endl;
    }
    inFile.close();

    vector<string> Content;
    Content.push_back("1.View Appointment");
    Content.push_back("2.Make Appointment");
    Content.push_back("3.Cancle Appointment");
    Content.push_back("4.Update My Infomation");
    Content.push_back("5.Change Password");
    Content.push_back("6.Sign out");

    MenuBox PatientMenu(35,7,2,30,11,1,203,Content);
    int choose = PatientMenu.menu2();

    return choose;
}

//cac FUNCTION cua Patient
