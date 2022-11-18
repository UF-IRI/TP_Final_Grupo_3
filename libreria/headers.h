
#include <fstream>
#include <string>
#include <cstring>
#include <iostream>
#include <ctime>
#include <cstdlib>

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

 struct patient
{
	int ID;
	string name;
	string surname;
	char sex;
	string birth;
	string state;
	string ID_insurance;
};
 struct llamar
 {
	 int id;
	 string nombre;
	 string apellido;
	 string telefono;
	 string ID_med;
	 string nombreMed;
	 string apellidoMed;
	 string telefonoMed;
	 string especialidad;
	 bool activo;
	 string obraSoc;
 };

bool readpatient(string name, patient*& list_patient, int* Npatient);
bool addPatient(patient*& list_patient, int* Npatient, patient aux);
bool createFiled(patient aux, int cont, string filed_name);
time_t fromStringtoTimet(string aux);
time_t LastConsult(consults* list_consults, int Nconsults, patient aux, bool* asistencia, string*idmed);
bool search(patient*& list_patient, int Npatient, consults*& list_consults, int Nconsults, contacts*& list_contacts, int Ncontacts, doctor*& list_doctors, int Ndoctors, string filed_name, string recuperados_nombre, int* contfiled);
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
bool archivosRecuperado(llamar aux, int cont, string nombre_recu);
void secretaria(llamar aux, int* contFiled, patient* list_patient, int Np, insurance* list_insurances, string nombre_recuperados, string filed_name, int NOS);
bool modify(llamar recuperable, int NOS, insurance* list_insurance);
bool leerSecretaria(string nombre_recuperados, llamar*& recuperados, int* Nrecuperados);
bool addLlamar(llamar*& recuperados, int* Nrecuperados, llamar aux);
void llenarLlamar(llamar* recup, patient paciente, contacts*& list_contacts, int Ncontacts, doctor*& list_doctors, int Ndoctors, string idmed);