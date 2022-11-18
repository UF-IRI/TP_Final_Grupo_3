#include "iri.cpp"
#include "headers.h"


int main() 
{
	int Npatient = 0;
	patient *list_patient = new patient[Npatient];//cuando hagas esto ejecuta paso po paso, esta buscando el archivo en tu compu y no en la carpeta esta de porqueria
	string patientPath = "IRI_Pacientes.csv";//SUERTE<3
	int Ncontacts = 0;
	contacts* list_contacts = new contacts[Ncontacts];
	int Nconsults = 0;
	consults* list_consults = new consults[Nconsults];
	string contactPath = "IRI_Contactos.csv";
	string consultsPath = "IRI_Consultas.csv";
	string doctorsPath = "IRI_Medicos.csv";
	int Ndoctors = 0;
	doctor* list_docs = new doctor[Ndoctors];
	bool checkDoc = readDoctor(doctorsPath, list_docs, &Ndoctors);
	//bool check = readpatient(patientPath, list_patient, &Npatient);
	//bool checkContacts = readContact(contactPath, list_contacts, &Ncontacts);
	//bool check = readConsults(consultsPath, list_consults, &Nconsults);

	for (int i = 0; i < Ndoctors; i++)
	{
		cout <<"\n" << list_docs[i].speciality;
	}
	return 0;
}
