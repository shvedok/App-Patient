#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Header1.h"
#include "Header.h"
#include <sstream>
#include <regex>
#include <windows.h>
int main()
{
	system("chcp 1251");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "ru");
	PatientsDB db;
	ifstream inFile("patients.txt");
	if (inFile) 
	{
		string name, gender, address, insurance, yearOfBirthStr;
		int yearOfBirth;
		while (std::getline(inFile, name, '\t') && std::getline(inFile, gender, '\t') && std::getline(inFile, address, '\t') && getline(inFile, insurance, '\t') && getline(inFile, yearOfBirthStr))
		{
			yearOfBirth = stoi(yearOfBirthStr);
			Patient patient(name, gender, address, insurance, yearOfBirth);
			db.addPatient(patient);
		}
		inFile.close();
	}
	// �������� ������� ���� ������ ���������
	string choice,adminchoice,userchoice;
	ofstream outFile;
	outFile.open("patients.txt", ios::app);
	// ����� ������������	
	while (true) 
	{
		cout << "�������� �����: " << endl;
		cout << "1. �������������" << endl;
		cout << "2. ������������" << endl;
		cout << "3. �����" << endl;
		getline(cin,choice);
		if (choice == "1")
		{
			// ����� ��������������
			string password;
			ifstream infile("password.txt");
			getline(infile, password);
			infile.close();
			cout << "������� ������: ";
			string input;
			getline(cin, input);
			if (input == password)
			{
				cout << "������ ��������." << endl;
			}
			else
			{
				cout << "������ ��������." << endl;
				continue;
			}
			while (true)
			{
				cout << "�������� ��������: " << endl;
				cout << "1. �������� ��������" << endl;
				cout << "2. ������� ��������" << endl;
				cout << "3. �������� ������ ��������" << endl;
				cout << "4. ����������� ������ ���������" << endl;
				cout << "5. ���������� ������ ���������" << endl;
				cout << "6. ����� �������� �� ���������" << endl;
				cout << "7. �����" << endl;
				getline(cin, adminchoice);
				if (adminchoice == "1")
				{
					// ���������� ��������
					string name, gender, address, insurance;
					int yearOfBirth;
					bool validName = false;
					while (!validName)
					{
						cout << "������� ��� �������� (������� 3 �����): ";
						getline(cin, name);
						istringstream iss(name);
						int count = 0;
						string word;
						while (iss >> word) {
							count++;
						}
						if (count >= 3) {
							validName = true;
						}
						else {
							cout << "��� ������ �������� ������� �� 3 ����!" << endl;
						}
					}
					bool validGender = false;
					while (!validGender)
					{
						cout << "������� ��� �������� (M - �������, � - �������): ";
						getline(cin, gender);
						if (gender == "�" || gender == "�")
						{
							validGender = true;
						}
						else
						{
							cout << "������� ���������� �������� ���� (M - �������, � - �������)!" << endl;
						}
					}
					bool Validaddress = false;
					while (!Validaddress)
					{
						regex pattern(R"([�-��-�]+\s+\d+[�-�]?)");
						smatch match;
						cout << "������� ����� �������� �������� (���� ����� � �����): ";
						getline(cin, address);
						if (regex_match(address, match, pattern))
						{
							cout << "����� �������� ���������" << endl;
							Validaddress = true;
						}
						else
						{
							cout << "����� �������� �����������" << endl;
						}
					}
					bool validInsurance = false;
					while (!validInsurance)
					{
						cout << "������� ����� ���������� ������ �������� (�� ����� 6 ��������): ";
						getline(cin, insurance);
						if (insurance.length() <= 6)
						{
							validInsurance = true;
						}
						else
						{
							cout << "����� ���������� ������ �� ����� ���� ������ 6 ��������!" << endl;
						}
					}
					bool validYear = false;
					while (!validYear)
					{
						cout << "������� ��� �������� ��������: ";
						cin >> yearOfBirth;
						if (yearOfBirth > 1920) {
							validYear = true;
						}
						else
						{
							cout << "������� ������ �������!" << endl;
						}
					}
					Patient patient(name, gender, address, insurance, yearOfBirth);
					db.addPatient(patient);
					outFile << name << "\t" << gender << "\t" << address << "\t" << insurance << "\t" << yearOfBirth << endl;
					cout << "������� ������� ��������!" << endl;
				}
				// �������� ��������
				else if (adminchoice == "2")
				{
					cout << "������� ����� ��������, �������� ������ �������: ";
					int index;
					cin >> index;
					if (index == -1) {
						cout << "�������� ��������." << endl;
						continue;
					}
					if (index < 1 || index > db.getSize())
					{
						cout << "������������ ����� ��������!" << endl;
						continue;
					}
					db.deletePatient(index - 1);
					outFile.close();
					outFile.open("patients.txt");
					for (int i = 0; i < db.getSize(); i++) {
						Patient patient = db.getPatient(i);
						outFile << patient.getName() << "\t" << patient.getGender() << "\t" << patient.getAddress() << "\t" << patient.getInsurance() << "\t" << patient.getYearOfBirth() << endl;
					}
					cout << "������� ������� ������!" << endl;
				}
				// ��������� ��������
				else if (adminchoice == "3")
				{
					cout << "������� ����� ��������, ������ �������� ������ ��������: ";
					int index;
					cin >> index;
					if (index < 1 || index > db.getSize())
					{
						cout << "������������ ����� ��������!" << endl;
						continue;
					}
					string name, gender, address, insurance;
					int yearOfBirth;
					bool validName = false;
					while (!validName)
					{
						cout << "������� ��� �������� (������� 3 �����): ";
						cin.ignore();
						getline(cin, name);
						istringstream iss(name);
						int count = 0;
						string word;
						while (iss >> word) {
							count++;
						}
						if (count >= 3)
						{
							validName = true;
						}
						else
						{
							cout << "��� ������ �������� ������� �� 3 ����!" << endl;
						}
					}
					bool validGender = false;
					while (!validGender)
					{
						cout << "������� ��� �������� (M - �������, � - �������): ";
						getline(cin, gender);
						if (gender == "�" || gender == "�")
						{
							validGender = true;
						}
						else
						{
							cout << "������� ���������� �������� ���� (M - �������,  - �������)!" << endl;
						}
					}
					regex pattern(R"([�-��-�]+\s+\d+[�-�]?)");
					smatch match;
					cout << "������� ����� �������� �������� (���� ����� � �����): ";
					getline(cin, address);
					if (regex_match(address, match, pattern))
					{
						cout << "����� �������� ���������" << endl;
					}
					else
					{
						cout << "����� �������� �����������" << endl;
					}
					bool validInsurance = false;
					while (!validInsurance)
					{
						cout << "������� ����� ���������� ������ �������� (�� ����� 6 ��������): ";
						getline(cin, insurance);
						if (insurance.length() <= 6) {
							validInsurance = true;
						}
						else
						{
							cout << "����� ���������� ������ �� ����� ���� ������ 6 ��������!" << endl;
						}
					}
					bool validYear = false;
					while (!validYear)
					{
						cout << "������� ��� �������� ��������: ";
						cin >> yearOfBirth;
						if (yearOfBirth > 1920) {
							validYear = true;
						}
						else {
							cout << "������� ������ �������!" << endl;
						}
						Patient patient(name, gender, address, insurance, yearOfBirth);
						db.updatePatient(index - 1, patient);
						outFile.close();
						outFile.open("patients.txt");
						for (int i = 0; i < db.getSize(); i++)
						{
							Patient patient = db.getPatient(i);
							outFile << patient.getName() << "\t" << patient.getGender() << "\t" << patient.getAddress() << "\t" << patient.getInsurance() << "\t" << patient.getYearOfBirth() << endl;
						}
						cout << "������ �������� ������� ��������!" << endl;
					}
				}
				else if (adminchoice == "4")
				{
					// �������� ������ ���������
					db.checklist();
				}
				else if (adminchoice == "5")
				{
					// ���������� ������ ���������
					db.sortingpatient();
				}
				else if (adminchoice == "6")
				{
					//����� ��������
					db.searchpatient();
				}
				else if (adminchoice == "7")
				{
					break;
				}
				else {
					cout << "�������� ����!" << endl;
				}
			}
		}
		else if (choice == "2")
		{
			// ����� ������������
			while (true)
			{
				cout << "�������� ��������: " << endl;
				cout << "1. ����������� ������ ���������" << endl;
				cout << "2. ���������� ������ ���������" << endl;
				cout << "3. ����� �������� �� ���������" << endl;
				cout << "4. �����" << endl;
				getline(cin, userchoice);
				if (userchoice == "1")
				{
					// �������� ������ ���������
					db.checklist();
				}
				else if (userchoice == "2")
				{
					// ���������� ������ ���������
					db.sortingpatient();
				}
				else if (userchoice == "3")
				{
					//����� ��������
					db.searchpatient();
				}
				else if (userchoice == "4")
				{
					break;
				}
				else {
					cout << "������������ ����! ���������� ��� ���." << endl;
				}
			}
		}
		else if (choice == "3")
		{
			break;
		}
		else
		{
			cout << "�������� ���� ������!" << endl;
		}
	}
}