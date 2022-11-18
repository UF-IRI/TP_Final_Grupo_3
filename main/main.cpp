#include "iri.cpp"
#include "headers.h"


int main()
{
	//genero las variables de pacientes y leo el archivo
	int Npatient = 0;
	patient* list_patient = new patient[Npatient];//cuando hagas esto ejecuta paso po paso, esta buscando el archivo en tu compu y no en la carpeta esta de porqueria
	string patientPath = "IRI_Pacientes.csv";//SUERTE<3
	bool checkPatient = readpatient(patientPath, list_patient, &Npatient);

	//genero las variables de contactos y leo el archivo
	int Ncontacts = 0;
	contacts* list_contacts = new contacts[Ncontacts];
	string contactPath = "IRI_Contactos.csv";
	bool checkContacts = readContact(contactPath, list_contacts, &Ncontacts);

	//genero las variables de consultas y leo el archivo
	int Nconsults = 0;
	consults* list_consults = new consults[Nconsults];
	string consultsPath = "IRI_Consultas.csv";
	bool checkConsults = readConsults(consultsPath, list_consults, &Nconsults);

	//genero las variables de medicos y leo el archivo	
	string doctorsPath = "IRI_Medicos.csv";
	int Ndoctors = 0;
	doctor* list_docs = new doctor[Ndoctors];
	bool checkDoc = readDoctor(doctorsPath, list_docs, &Ndoctors);
	
	//genero las variables de obra social y leo el archivo
	string insurancePath = "IRI_ObraSocial.csv";
	int Nos = 0;
	insurance* list_insurance = new insurance[Nos];
	bool checkInsurance = readInsurances(insurancePath, list_insurance, &Nos);

	string nameArch, nameRecup;
	nameArch = "archivados.csv";
	nameRecup = "recuperados.csv";
	int i = 0;
	int contFiled=0;
	
	bool busqueda=search(* &list_patient, Npatient,  * &list_consults, Nconsults,  * &list_contacts, Ncontacts, *&list_docs, Ndoctors, nameArch,nameRecup,&contFiled);
	if (busqueda)
	{
		int Nrecup = 0;
		llamar paciente;
		llamar* recuperados = new llamar[Nrecup];
		bool checkSec = leerSecretaria(nameRecup, recuperados, &Nrecup);
		for (i = 0; i < Nrecup;i++)
		{
			paciente = recuperados[i];
			secretaria(paciente,&contFiled, list_patient, Npatient,list_insurance, nameArch, nameRecup,Nos);
		}
		delete[]recuperados;
	}

	
	delete[]list_patient;
	delete[]list_consults;
	delete[]list_contacts;
	delete[]list_docs;
	delete[]list_insurance;
	return 0;
	
}




