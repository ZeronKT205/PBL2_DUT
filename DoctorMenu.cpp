#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include "Menu.h"
#include "Box.h"

using namespace std;


//Menu lua chon login hoac signup
void DoctorMenu::Main() {
	system("cls");
	ifstream inFile("../PBL_DUT/Doctor.txt");
	string line;
	while (getline(inFile, line)) {
		cout << line << endl;
	}
	inFile.close();

	//tao content
	vector<string> DoctorData;
	DoctorData.push_back("Login");
	DoctorData.push_back("Back");

	//ve bang
	MenuBox DoctorBox(DoctorData);
	int choose = DoctorBox.menu();
	switch (choose) {
	case 1:
		DoctorMenu::login();
		system("pause");
		break;
	case 2:
		Home::menu();
		break;

	}

}

//ham login
void DoctorMenu::login() {
	system("cls");
	ifstream inFile("../PBL_DUT/Doctor_login.txt");
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
	int choose = DoctorMenu::printTask();
	switch (choose) {
	case 9:
		system("cls");
		Home::menu();;
		break;
	}
}


//ham in ra cac lua chon chuc nang sau khi login
int DoctorMenu::printTask() {
	system("cls");
	ifstream inFile("../PBL_DUT/Doctor_Function.txt");
	string line;
	while (getline(inFile, line)) {
		cout << line << endl;
	}
	inFile.close();

	vector<string> DoctorFunctions;
	DoctorFunctions.push_back("1. View Appointment Schedule");
	DoctorFunctions.push_back("2. Update Appointment Status");
	DoctorFunctions.push_back("3. View Patient Information");
	DoctorFunctions.push_back("4. Diagnose Medication");
	DoctorFunctions.push_back("5. View Patient Medical History");
	DoctorFunctions.push_back("6. Manage Work Schedule");
	DoctorFunctions.push_back("7. View My Information");
	DoctorFunctions.push_back("8. Update My Information");
	DoctorFunctions.push_back("9. Sign out");

	MenuBox DoctorMenu(18, 7, 2, 33, 11, 1, 203, DoctorFunctions);
	int choose = DoctorMenu.menu2();

	return choose;
	
}


//ham tao switch case thuc hien chuc nang


	