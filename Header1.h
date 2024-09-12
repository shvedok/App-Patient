#pragma once
#ifndef Header1_H
#define Header1_H
#include <iostream>
#include "Header.h"
#include <vector>
#include <algorithm>
#include <sstream>
#include <regex>
// Класс "База данных пациентов"
using namespace std;
class PatientsDB	
{
private:
	vector<Patient> patients; // Вектор пациентов
public:
	// Конструктор по умолчанию
	PatientsDB()
	{
		patients = {};
	}
	// Методы работы с базой данных
	void addPatient(Patient patient) { // Добавление пациента
		patients.push_back(patient);
	}
	void deletePatient(int index) { // Удаление пациента по индексу
		patients.erase(patients.begin() + index);
	}
	void updatePatient(int index, Patient patient) { // Изменение пациента по индексу
		patients[index] = patient;
	}
	Patient getPatient(int index) const { // Получение пациента по индексу
		return patients[index];
	}
	size_t getSize() const
	{ // Получение количества пациентов в базе данных
		return patients.size();
	}
	void sortByName()
	{
		sort(patients.begin(), patients.end(), [](const Patient& p1, const Patient& p2) {
			return p1.getName() < p2.getName();
			});
	}
	void sortByAddress()
	{
		sort(patients.begin(), patients.end(), [](Patient& p1, Patient& p2) {
			return p1.getAddress() < p2.getAddress();
			});
	}
	void sortByYearOfBirth()
	{
		sort(patients.begin(), patients.end(), [](Patient p1, Patient p2) {
			return p1.getYearOfBirth() < p2.getYearOfBirth();
			});
	}
	void sortByGender()
	{
		sort(patients.begin(), patients.end(), [](Patient p1, Patient p2) {
			return p1.getGender() < p2.getGender();
			});
	}
	void sortByInsurance()
	{
		sort(patients.begin(), patients.end(), [](Patient p1, Patient p2) {
			return p1.getInsurance() < p2.getInsurance();
			});
	}
	void sortingpatient()
	{
		string sortChoice;
		while (true)
		{
			cout << "Выберите параметр для сортировки: " << endl;
			cout << "1. ФИО" << endl;
			cout << "2. Адрес" << endl;
			cout << "3. Год рождения" << endl;
			cout << "4. Пол пациента" << endl;
			cout << "5. Номер страхового полиса" << endl;
			cout << "6. Выйти из режима сортировки" << endl;
			getline(cin, sortChoice);
			if (sortChoice == "1")
			{
				// Сортировка по ФИО
				sortByName();
				cout << "Список пациентов отсортирован по ФИО: " << endl;
				for (int i = 0; i < getSize(); i++) {
					cout << i + 1 << ". " << getPatient(i).getName() << ", " << getPatient(i).getGender() << ", " << getPatient(i).getAddress() << ", " << getPatient(i).getInsurance() << ", " << getPatient(i).getYearOfBirth() << endl;
				}
			}
			else if (sortChoice == "2")
			{
				// Сортировка по адресу прописки
				sortByAddress();
				cout << "Список пациентов отсортирован по улице прописки: " << endl;
				for (int i = 0; i < getSize(); i++) {
					cout << i + 1 << ". " << getPatient(i).getName() << ", " << getPatient(i).getGender() << ", " << getPatient(i).getAddress() << ", " << getPatient(i).getInsurance() << ", " << getPatient(i).getYearOfBirth() << endl;
				}
			}
			else if (sortChoice == "3")
			{
				// Сортировка по году рождения
				sortByYearOfBirth();
				cout << "Список пациентов отсортирован по году рождения: " << endl;
				for (int i = 0; i < getSize(); i++) {
					cout << i + 1 << ". " << getPatient(i).getName() << ", " << getPatient(i).getGender() << ", " << getPatient(i).getAddress() << ", " << getPatient(i).getInsurance() << ", " << getPatient(i).getYearOfBirth() << endl;
				}
			}
			else if (sortChoice == "4")
			{
				//сортировка по полу
				sortByGender();
				cout << "Список пациентов отсортирован по полу" << endl;
				for (int i = 0; i < getSize(); i++) {
					cout << i + 1 << ". " << getPatient(i).getName() << ", " << getPatient(i).getGender() << ", " << getPatient(i).getAddress() << ", " << getPatient(i).getInsurance() << ", " << getPatient(i).getYearOfBirth() << endl;
				}
			}
			else if (sortChoice == "5")
			{
				//сортировка по страховому полису
				sortByInsurance();
				cout << "Список пациентов отсортирован по номеру страхового полиса" << endl;
				for (int i = 0; i < getSize(); i++) {
					cout << i + 1 << ". " << getPatient(i).getName() << ", " << getPatient(i).getGender() << ", " << getPatient(i).getAddress() << ", " << getPatient(i).getInsurance() << ", " << getPatient(i).getYearOfBirth() << endl;
				}
			}
			else if (sortChoice == "6")
			{
				break;
			}
			else
			{
				cout << "Неверный ввод!" << endl;
			}
		}
	}
	void searchpatient()
	{
		int  yearOfBirth;
		string gender, name, address, insurance,searchchoice;
		while (true)
		{
			cout << "Выберите параметр для поиска" << endl;
			cout << "1. ФИО" << endl;
			cout << "2. Пол" << endl;
			cout << "3. Адрес" << endl;
			cout << "4. Номер страхового полиса" << endl;
			cout << "5. Год рождения" << endl;
			cout << "6. Выход из режима поиска" << endl;
			getline(cin,searchchoice);
			if (searchchoice == "1")
			{
				cout << "Введите ФИО пациента: ";
				cin.ignore();
				getline(cin, name);
				for (int i = 0; i < getSize(); i++) {
					if (name == getPatient(i).getName())
						cout << i + 1 << ". " << getPatient(i).getName() << ", " << getPatient(i).getGender() << ", " << getPatient(i).getAddress() << ", " << getPatient(i).getInsurance() << ", " << getPatient(i).getYearOfBirth() << endl;
				}
			}
			else if (searchchoice == "2")
			{
				bool validGender = false;
				cout << "Введите пол пациента (M - мужской, Ж - женский): ";
				getline(cin, gender);
				while (!validGender)
				{
					if (gender == "М" || gender == "Ж")
					{
						validGender = true;
						for (int i = 0; i < getSize(); i++) {
							if (gender == getPatient(i).getGender())
								cout << i + 1 << ". " << getPatient(i).getName() << ", " << getPatient(i).getGender() << ", " << getPatient(i).getAddress() << ", " << getPatient(i).getInsurance() << ", " << getPatient(i).getYearOfBirth() << endl;
						}
					}
					else
					{
						cout << "Введите корректное значение пола (M - мужской,  - женский)!" << endl;
						getline(cin, gender);
					}
				}
			}
			else if (searchchoice == "3")
			{
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
				for (int i = 0; i < getSize(); i++) {
					if (address == getPatient(i).getAddress())
						cout << i + 1 << ". " << getPatient(i).getName() << ", " << getPatient(i).getGender() << ", " << getPatient(i).getAddress() << ", " << getPatient(i).getInsurance() << ", " << getPatient(i).getYearOfBirth() << endl;
				}
			}
			else if (searchchoice == "4")
			{
				bool validInsurance = false;
				while (!validInsurance)
				{
					cout << "Введите номер страхового полиса пациента (не более 6 символов): ";
					cin.ignore();
					getline(cin, insurance);
					if (insurance.length() <= 6) {
						validInsurance = true;
						for (int i = 0; i < getSize(); i++) {
							if (insurance == getPatient(i).getInsurance())
								cout << i + 1 << ". " << getPatient(i).getName() << ", " << getPatient(i).getGender() << ", " << getPatient(i).getAddress() << ", " << getPatient(i).getInsurance() << ", " << getPatient(i).getYearOfBirth() << endl;
						}
					}
					else
					{
						cout << "Номер страхового полиса не может быть больше 6 символов!" << endl;
					}
				}
			}
			else if (searchchoice == "5")
			{
				cout << "Введите год рождения пациента: ";
				cin >> yearOfBirth;
				for (int i = 0; i < getSize(); i++)
				{
					if (yearOfBirth == getPatient(i).getYearOfBirth())
						cout << i + 1 << ". " << getPatient(i).getName() << ", " << getPatient(i).getGender() << ", " << getPatient(i).getAddress() << ", " << getPatient(i).getInsurance() << ", " << getPatient(i).getYearOfBirth() << endl;
				}
			}
			else if (searchchoice == "6") {
				break;
			}
			else
			{
				cout << "Неверный ввод!" << endl;
			}
		}
	}
	void checklist()
	{
		cout << "Список пациентов: " << endl;
		for (int i = 0; i < getSize(); i++) {
			cout << i + 1 << ". " << getPatient(i).getName() << ", " << getPatient(i).getGender() << ", " << getPatient(i).getAddress() << ", " << getPatient(i).getInsurance() << ", " << getPatient(i).getYearOfBirth() << endl;
		}
	}
};
#endif