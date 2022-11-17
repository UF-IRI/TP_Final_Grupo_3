
#include <fstream>
#include <string>
#include <cstring>
#include <iostream>
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
	string direccion;
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

typedef struct patient
{
	int ID;
	string name;
	string surname;
	char sex;
	string birth;
	string state;
	string ID_insurance;
} patient;
bool readpatient(string name, patient*& list_patient, int* Npatient);
bool addPatient(patient*& list_patient, int* Npatient, patient aux);
bool createFiled(patient aux, int cont);
time_t fromStringtoTimet(string aux);
time_t LastConsult(consults* list_consults, int Nconsults, patient aux, bool* asistencia);
bool search(patient*& list_patient, int* Npatient, consults*& list_consults, int* Nconsults, contacts*& list_contacts, int* Ncontacts);
bool addInsurance(insurance*& list_insurances, int* Ninsurances, insurance aux);
bool readInsurances(string name, insurance*& list_insurances, int* Ninsurances);
bool addDoctor(doctor*& list_doctors, int* Ndoctors, doctor aux);
bool readDoctor(string name, doctor*& list_doctors, int* Ndoctors);
bool addConsult(consults*& list_consults, int* Nconsults, consults aux);
bool readConsults(string name, consults*& list_consults, int* Nconsults);
bool addContact(contacts*& list_contacts, int* Ncontacts, contacts aux);
bool readContact(string name, contacts*& list_contacts, int* Ncontacts);
bool addPatient(patient*& list_patient, int* Npatient, patient aux);
bool readpatient(string name, patient*& list_patient, int* Npatient);
