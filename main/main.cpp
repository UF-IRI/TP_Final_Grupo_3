#include "iri.cpp"
#include "headers.h"

using namespace std;
int main() 
{
	int Npatient = 0;
	patient *list_patient = new patient[Npatient];
	string dir_pac = BASE_PATH + "../data_files/input/IRI_Consultas.csv";
	bool check=readpatient(dir_pac, list_patient, &Npatient);
	for (int i = 0; i < Npatient; i++)
	{
		cout << list_patient[i].name;
	}
	return 0;
}
