#include "iri.cpp"
#include "headers.h"


int main() 
{
	int Npatient = 0;
	patient *list_patient = new patient[Npatient];//cuando hagas esto ejecuta paso po paso, esta buscando el archivo en tu compu y no en la carpeta esta de porqueria
	string patientPath = BASE_PATH+"TP_Final_Grupo_03\\data_files\\input\\IRI_Pacientes.csv";//SUERTE<3
	
	bool check = readpatient(patientPath, list_patient, &Npatient);
	if (!(check))
		cout << "no";
	
	for (int i = 0; i < Npatient; i++)
	{
		cout <<"\n" << list_patient[i].name;
	}
	return 0;
}
