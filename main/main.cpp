#include "iri.cpp"
#include "headers.h"

int main() 
{
	int Npatient = 0;
	patient *list_patient = new patient[Npatient];//cuando hagas esto ejecuta paso po paso, esta buscando el archivo en tu compu y no en la carpeta esta de porqueria
	string patientPath = BASE_PATH + "../data_files/input/IRI_Consultas.csv";//SUERTE<3
	bool check = readpatient(patientPath, list_patient, &Npatient);
	for (int i = 0; i < Npatient; i++)
	{
		cout << Npatient;
		cout <<"\n" << list_patient[i].birth;
	}
	return 0;
}
