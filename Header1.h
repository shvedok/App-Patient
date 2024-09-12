#pragma once
#ifndef Header1_H
#define Header1_H
#include <iostream>
#include "Header.h"
#include <vector>
#include <algorithm>
#include <sstream>
#include <regex>
// ����� "���� ������ ���������"
using namespace std;
class PatientsDB	
{
private:
	vector<Patient> patients; // ������ ���������
public:
	// ����������� �� ���������
	PatientsDB()
	{
		patients = {};
	}
	// ������ ������ � ����� ������
	void addPatient(Patient patient) { // ���������� ��������
		patients.push_back(patient);
	}
	void deletePatient(int index) { // �������� �������� �� �������
		patients.erase(patients.begin() + index);
	}
	void updatePatient(int index, Patient patient) { // ��������� �������� �� �������
		patients[index] = patient;
	}
	Patient getPatient(int index) const { // ��������� �������� �� �������
		return patients[index];
	}
	size_t getSize() const
	{ // ��������� ���������� ��������� � ���� ������
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
			cout << "�������� �������� ��� ����������: " << endl;
			cout << "1. ���" << endl;
			cout << "2. �����" << endl;
			cout << "3. ��� ��������" << endl;
			cout << "4. ��� ��������" << endl;
			cout << "5. ����� ���������� ������" << endl;
			cout << "6. ����� �� ������ ����������" << endl;
			getline(cin, sortChoice);
			if (sortChoice == "1")
			{
				// ���������� �� ���
				sortByName();
				cout << "������ ��������� ������������ �� ���: " << endl;
				for (int i = 0; i < getSize(); i++) {
					cout << i + 1 << ". " << getPatient(i).getName() << ", " << getPatient(i).getGender() << ", " << getPatient(i).getAddress() << ", " << getPatient(i).getInsurance() << ", " << getPatient(i).getYearOfBirth() << endl;
				}
			}
			else if (sortChoice == "2")
			{
				// ���������� �� ������ ��������
				sortByAddress();
				cout << "������ ��������� ������������ �� ����� ��������: " << endl;
				for (int i = 0; i < getSize(); i++) {
					cout << i + 1 << ". " << getPatient(i).getName() << ", " << getPatient(i).getGender() << ", " << getPatient(i).getAddress() << ", " << getPatient(i).getInsurance() << ", " << getPatient(i).getYearOfBirth() << endl;
				}
			}
			else if (sortChoice == "3")
			{
				// ���������� �� ���� ��������
				sortByYearOfBirth();
				cout << "������ ��������� ������������ �� ���� ��������: " << endl;
				for (int i = 0; i < getSize(); i++) {
					cout << i + 1 << ". " << getPatient(i).getName() << ", " << getPatient(i).getGender() << ", " << getPatient(i).getAddress() << ", " << getPatient(i).getInsurance() << ", " << getPatient(i).getYearOfBirth() << endl;
				}
			}
			else if (sortChoice == "4")
			{
				//���������� �� ����
				sortByGender();
				cout << "������ ��������� ������������ �� ����" << endl;
				for (int i = 0; i < getSize(); i++) {
					cout << i + 1 << ". " << getPatient(i).getName() << ", " << getPatient(i).getGender() << ", " << getPatient(i).getAddress() << ", " << getPatient(i).getInsurance() << ", " << getPatient(i).getYearOfBirth() << endl;
				}
			}
			else if (sortChoice == "5")
			{
				//���������� �� ���������� ������
				sortByInsurance();
				cout << "������ ��������� ������������ �� ������ ���������� ������" << endl;
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
				cout << "�������� ����!" << endl;
			}
		}
	}
	void searchpatient()
	{
		int  yearOfBirth;
		string gender, name, address, insurance,searchchoice;
		while (true)
		{
			cout << "�������� �������� ��� ������" << endl;
			cout << "1. ���" << endl;
			cout << "2. ���" << endl;
			cout << "3. �����" << endl;
			cout << "4. ����� ���������� ������" << endl;
			cout << "5. ��� ��������" << endl;
			cout << "6. ����� �� ������ ������" << endl;
			getline(cin,searchchoice);
			if (searchchoice == "1")
			{
				cout << "������� ��� ��������: ";
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
				cout << "������� ��� �������� (M - �������, � - �������): ";
				getline(cin, gender);
				while (!validGender)
				{
					if (gender == "�" || gender == "�")
					{
						validGender = true;
						for (int i = 0; i < getSize(); i++) {
							if (gender == getPatient(i).getGender())
								cout << i + 1 << ". " << getPatient(i).getName() << ", " << getPatient(i).getGender() << ", " << getPatient(i).getAddress() << ", " << getPatient(i).getInsurance() << ", " << getPatient(i).getYearOfBirth() << endl;
						}
					}
					else
					{
						cout << "������� ���������� �������� ���� (M - �������,  - �������)!" << endl;
						getline(cin, gender);
					}
				}
			}
			else if (searchchoice == "3")
			{
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
					cout << "������� ����� ���������� ������ �������� (�� ����� 6 ��������): ";
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
						cout << "����� ���������� ������ �� ����� ���� ������ 6 ��������!" << endl;
					}
				}
			}
			else if (searchchoice == "5")
			{
				cout << "������� ��� �������� ��������: ";
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
				cout << "�������� ����!" << endl;
			}
		}
	}
	void checklist()
	{
		cout << "������ ���������: " << endl;
		for (int i = 0; i < getSize(); i++) {
			cout << i + 1 << ". " << getPatient(i).getName() << ", " << getPatient(i).getGender() << ", " << getPatient(i).getAddress() << ", " << getPatient(i).getInsurance() << ", " << getPatient(i).getYearOfBirth() << endl;
		}
	}
};
#endif