#pragma once
#ifndef Header_H
#define Header_H
#include <iostream>
#include <string>
using namespace std;
// Класс Пациент
class Patient {
private:
	string name; // ФИО
	string gender; // Пол
	string address; // Адрес прописки
	string insurance; // Номер страхового полиса
	int yearOfBirth; // Год рождения
public:
	Patient() { // Конструктор по умолчанию
		name = "";
		gender = "";
		address = "";
		insurance = "";
		yearOfBirth = 0;
	}
	Patient(string name, string gender, string address, string insurance, int yearOfBirth) { // Конструктор с параметрами
		this->name = name;
		this->gender = gender;
		this->address = address;
		this->insurance = insurance;
		this->yearOfBirth = yearOfBirth;
	}
	// Методы получения значений полей
	string getName() const
	{
		return name;
	}
	string getGender() const
	{
		return gender;
	}
	string getAddress() const
	{
		return address;
	}
	string getInsurance() const
	{
		return insurance;
	}
	int getYearOfBirth() const
	{
		return yearOfBirth;
	}
	// Методы установки значений полей
	void setName(string name)
	{
		this->name = name;
	}
	void setGender(string gender) {
		this->gender = gender;
	}
	void setAddress(string address) {
		this->address = address;
	}
	void setInsurance(string insurance) {
		this->insurance = insurance;
	}
	void setYearOfBirth(int yearOfBirth) {
		this->yearOfBirth = yearOfBirth;
	}
	Patient(const string& name, const string& address, int yearOfBirth, const string& insuranceNumber)
		: name(name), address(address), yearOfBirth(yearOfBirth), insurance(insurance) { }
};
#endif