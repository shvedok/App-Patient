#pragma once
#ifndef Header_H
#define Header_H
#include <iostream>
#include <string>
using namespace std;
// ����� �������
class Patient {
private:
	string name; // ���
	string gender; // ���
	string address; // ����� ��������
	string insurance; // ����� ���������� ������
	int yearOfBirth; // ��� ��������
public:
	Patient() { // ����������� �� ���������
		name = "";
		gender = "";
		address = "";
		insurance = "";
		yearOfBirth = 0;
	}
	Patient(string name, string gender, string address, string insurance, int yearOfBirth) { // ����������� � �����������
		this->name = name;
		this->gender = gender;
		this->address = address;
		this->insurance = insurance;
		this->yearOfBirth = yearOfBirth;
	}
	// ������ ��������� �������� �����
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
	// ������ ��������� �������� �����
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