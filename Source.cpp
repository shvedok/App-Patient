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
	// Создание объекта базы данных пациентов
	string choice,adminchoice,userchoice;
	ofstream outFile;
	outFile.open("patients.txt", ios::app);
	// Выбор пользователя	
	while (true) 
	{
		cout << "Выберите режим: " << endl;
		cout << "1. Администратор" << endl;
		cout << "2. Пользователь" << endl;
		cout << "3. Выход" << endl;
		getline(cin,choice);
		if (choice == "1")
		{
			// Режим администратора
			string password;
			ifstream infile("password.txt");
			getline(infile, password);
			infile.close();
			cout << "Введите пароль: ";
			string input;
			getline(cin, input);
			if (input == password)
			{
				cout << "Доступ разрешен." << endl;
			}
			else
			{
				cout << "Доступ запрещен." << endl;
				continue;
			}
			while (true)
			{
				cout << "Выберите действие: " << endl;
				cout << "1. Добавить пациента" << endl;
				cout << "2. Удалить пациента" << endl;
				cout << "3. Изменить данные пациента" << endl;
				cout << "4. Просмотреть список пациентов" << endl;
				cout << "5. Сортировка списка пациентов" << endl;
				cout << "6. Поиск пациента по параметру" << endl;
				cout << "7. Выход" << endl;
				getline(cin, adminchoice);
				if (adminchoice == "1")
				{
					// Добавление пациента
					string name, gender, address, insurance;
					int yearOfBirth;
					bool validName = false;
					while (!validName)
					{
						cout << "Введите ФИО пациента (минимум 3 слова): ";
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
							cout << "ФИО должно состоять минимум из 3 слов!" << endl;
						}
					}
					bool validGender = false;
					while (!validGender)
					{
						cout << "Введите пол пациента (M - мужской, Ж - женский): ";
						getline(cin, gender);
						if (gender == "М" || gender == "Ж")
						{
							validGender = true;
						}
						else
						{
							cout << "Введите корректное значение пола (M - мужской, Ж - женский)!" << endl;
						}
					}
					bool Validaddress = false;
					while (!Validaddress)
					{
						regex pattern(R"([А-Яа-я]+\s+\d+[а-я]?)");
						smatch match;
						cout << "Введите адрес прописки пациента (одно слово и цифра): ";
						getline(cin, address);
						if (regex_match(address, match, pattern))
						{
							cout << "Адрес прописки корректен" << endl;
							Validaddress = true;
						}
						else
						{
							cout << "Адрес прописки некорректен" << endl;
						}
					}
					bool validInsurance = false;
					while (!validInsurance)
					{
						cout << "Введите номер страхового полиса пациента (не более 6 символов): ";
						getline(cin, insurance);
						if (insurance.length() <= 6)
						{
							validInsurance = true;
						}
						else
						{
							cout << "Номер страхового полиса не может быть больше 6 символов!" << endl;
						}
					}
					bool validYear = false;
					while (!validYear)
					{
						cout << "Введите год рождения пациента: ";
						cin >> yearOfBirth;
						if (yearOfBirth > 1920) {
							validYear = true;
						}
						else
						{
							cout << "Введите другой возраст!" << endl;
						}
					}
					Patient patient(name, gender, address, insurance, yearOfBirth);
					db.addPatient(patient);
					outFile << name << "\t" << gender << "\t" << address << "\t" << insurance << "\t" << yearOfBirth << endl;
					cout << "Пациент успешно добавлен!" << endl;
				}
				// Удаление пациента
				else if (adminchoice == "2")
				{
					cout << "Введите номер пациента, которого хотите удалить: ";
					int index;
					cin >> index;
					if (index == -1) {
						cout << "Удаление отменено." << endl;
						continue;
					}
					if (index < 1 || index > db.getSize())
					{
						cout << "Некорректный номер пациента!" << endl;
						continue;
					}
					db.deletePatient(index - 1);
					outFile.close();
					outFile.open("patients.txt");
					for (int i = 0; i < db.getSize(); i++) {
						Patient patient = db.getPatient(i);
						outFile << patient.getName() << "\t" << patient.getGender() << "\t" << patient.getAddress() << "\t" << patient.getInsurance() << "\t" << patient.getYearOfBirth() << endl;
					}
					cout << "Пациент успешно удален!" << endl;
				}
				// Изменение пациента
				else if (adminchoice == "3")
				{
					cout << "Введите номер пациента, данные которого хотите изменить: ";
					int index;
					cin >> index;
					if (index < 1 || index > db.getSize())
					{
						cout << "Некорректный номер пациента!" << endl;
						continue;
					}
					string name, gender, address, insurance;
					int yearOfBirth;
					bool validName = false;
					while (!validName)
					{
						cout << "Введите ФИО пациента (минимум 3 слова): ";
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
							cout << "ФИО должно состоять минимум из 3 слов!" << endl;
						}
					}
					bool validGender = false;
					while (!validGender)
					{
						cout << "Введите пол пациента (M - мужской, Ж - женский): ";
						getline(cin, gender);
						if (gender == "М" || gender == "Ж")
						{
							validGender = true;
						}
						else
						{
							cout << "Введите корректное значение пола (M - мужской,  - женский)!" << endl;
						}
					}
					regex pattern(R"([А-Яа-я]+\s+\d+[а-я]?)");
					smatch match;
					cout << "Введите адрес прописки пациента (одно слово и цифра): ";
					getline(cin, address);
					if (regex_match(address, match, pattern))
					{
						cout << "Адрес прописки корректен" << endl;
					}
					else
					{
						cout << "Адрес прописки некорректен" << endl;
					}
					bool validInsurance = false;
					while (!validInsurance)
					{
						cout << "Введите номер страхового полиса пациента (не более 6 символов): ";
						getline(cin, insurance);
						if (insurance.length() <= 6) {
							validInsurance = true;
						}
						else
						{
							cout << "Номер страхового полиса не может быть больше 6 символов!" << endl;
						}
					}
					bool validYear = false;
					while (!validYear)
					{
						cout << "Введите год рождения пациента: ";
						cin >> yearOfBirth;
						if (yearOfBirth > 1920) {
							validYear = true;
						}
						else {
							cout << "Введите другой возраст!" << endl;
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
						cout << "Данные пациента успешно изменены!" << endl;
					}
				}
				else if (adminchoice == "4")
				{
					// Просмотр списка пациентов
					db.checklist();
				}
				else if (adminchoice == "5")
				{
					// Сортировка списка пациентов
					db.sortingpatient();
				}
				else if (adminchoice == "6")
				{
					//поиск пациента
					db.searchpatient();
				}
				else if (adminchoice == "7")
				{
					break;
				}
				else {
					cout << "Неверный ввод!" << endl;
				}
			}
		}
		else if (choice == "2")
		{
			// Режим пользователя
			while (true)
			{
				cout << "Выберите действие: " << endl;
				cout << "1. Просмотреть список пациентов" << endl;
				cout << "2. Сортировка списка пациентов" << endl;
				cout << "3. Поиск пациента по параметру" << endl;
				cout << "4. Выход" << endl;
				getline(cin, userchoice);
				if (userchoice == "1")
				{
					// Просмотр списка пациентов
					db.checklist();
				}
				else if (userchoice == "2")
				{
					// Сортировка списка пациентов
					db.sortingpatient();
				}
				else if (userchoice == "3")
				{
					//поиск пациента
					db.searchpatient();
				}
				else if (userchoice == "4")
				{
					break;
				}
				else {
					cout << "Некорректный ввод! Попробуйте еще раз." << endl;
				}
			}
		}
		else if (choice == "3")
		{
			break;
		}
		else
		{
			cout << "Неверный ввод данных!" << endl;
		}
	}
}