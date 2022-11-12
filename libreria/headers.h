
#include <string>
#include <cstring>
#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;
struct consults
{
	int ID;
	string required;
	string appointment;
	bool attendance;
	string doctors_ID;
};

struct contacts
{
	int ID;
	string telephone;
	string celphone;
	string mail;
};

struct doctor
{
	string ID;
	string name;
	string surname;
	string telephone;
	string speciality;
	bool state;
};

struct insurance
{
	int ID;
	string insurance_name;
};

struct patient
{
	int ID;
	string name;
	string surname;
	char sex;
	string birth;
	string state;
	int ID_insurance;
};
bool readpatient(string name, patient*& list_patient, int* Npatient);
bool addPatient(patient*& list_patient, int* Npatient, patient aux);