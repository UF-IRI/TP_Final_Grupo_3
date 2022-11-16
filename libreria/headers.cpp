#include "headers.h"


bool readpatient(string name, patient*& list_patient, int* Npatient)	//funcion para leer el csv
{
	if (list_patient == nullptr)	//si no tiene asinado espacio en memoria, error
		return false;

	fstream file;
	file.open(name, ios::in);	//abro el archivo para leerlo

	if (!(file.is_open()))	//no se pudo abrir el archivo
	{
		return false;
		cout << "no se abro";
	}
	else
		cout << "abrio";

	string coma;
	patient aux;
	string dummy;

	//file >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy;	//levanto los headers

	while (file)
	{
		string coma1;
		file >> aux.ID >> coma1 >> aux.name >> coma1 >> aux.surname >> coma1 >> aux.sex >> coma1 >> aux.birth >> coma1 >> aux.state >> coma1 >> aux.ID_insurance;
		bool added = addPatient(*&list_patient, Npatient, aux);
		if (added == false)	//hubo algun error al agregar el paciente
		{
			return false;
			cout << "Error";
		}
			
	}
	file.close();
	return true;
}
bool addPatient(patient*& list_patient, int* Npatient, patient aux)
{
	if (list_patient == nullptr)	//rechequeo por las dudas que lo que me pasen tenog  espacio asignado
		return false;

	*Npatient = *Npatient + 1;
	patient* changed = new patient[*Npatient];
	int i=0;

	while (i < *Npatient - 1 )
	{
		changed[i] = list_patient[i];
		i++;
	}
	changed[i] = aux;

	delete[]list_patient;	//borro a donde estaba apuntado
	list_patient = changed;	//redireciono
	return true;	//todo ok
}

bool readContact(string name, contacts*& list_contacts, int* Ncontacts)
{
	if (list_contacts == nullptr || Ncontacts == nullptr)
		return false;
	fstream file;
	file.open(name, ios::in);
	if (!(file.is_open()))
		return false;
	char coma;
	contacts aux;
	string dummy;
	file >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy>>coma>>dummy;
	while (file)
	{
		file >> aux.ID >> coma >> aux.telephone >> coma >> aux.celphone >> coma >>aux.direccion>>coma>> aux.mail;
		bool added = addContact(list_contacts, Ncontacts, aux);
		if (added == false)
			return false;
	}
	file.close();
	return true;
}
bool addContact(contacts*& list_contacts, int* Ncontacts, contacts aux)
{
	if (list_contacts == nullptr)
		return false;
	*Ncontacts = *Ncontacts + 1;
	contacts* changed = new contacts[*Ncontacts];
	int i=0;
	while (i < *Ncontacts - 1 && *Ncontacts - 1 != 0)
	{
		changed[i] = list_contacts[i];
		i++;
	}
	changed[i] = aux;
	delete[]list_contacts;
	list_contacts = changed;
	return true;
}

bool readConsults(string name, consults*& list_consults, int* Nconsults) 
{
	if (list_consults == nullptr)
		return false;
	fstream file;
	file.open(name, ios::in);
	if (!(file.is_open()))
		return false;
	char coma;
	consults aux;
	string dummy;
	file >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy;
	while (file)
	{
		file >> aux.ID >> coma >> aux.required >> coma >> aux.appointment>> coma >> aux.attendance >> coma >> aux.doctors_ID;
		bool added = addConsult(list_consults, Nconsults, aux);
		if (added == false)
			return false;
	}
	file.close();
	return true;
}
bool addConsult(consults*& list_consults, int* Nconsults, consults aux)
{
	if (list_consults == nullptr)
		return false;
	*Nconsults = *Nconsults + 1;
	consults* changed = new consults[*Nconsults];
	int i=0;
	while (i < *Nconsults - 1 && *Nconsults - 1 != 0)
	{
		changed[i] = list_consults[i];
		i++;
	}
		
	changed[i] = aux;
	delete[]list_consults;
	list_consults = changed;
	return true;
}

bool readDoctor(string name, doctor*& list_doctors, int* Ndoctors)
{
	if (list_doctors == nullptr)
		return false;
	fstream file;
	file.open(name, ios::in);
	if (!(file.is_open()))
		return false;
	char coma;
	doctor aux;
	string dummy; 
	file >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy;
	while (file)
	{
		file >> aux.ID >> coma >> aux.name >> coma >> aux.surname >> coma >> aux.telephone >> coma >> aux.speciality >> coma >> aux.state;;
		bool added = addDoctor(list_doctors, Ndoctors, aux);
		if (added == false)
			return false;
	}
	file.close();
	return true;
}
bool addDoctor(doctor*& list_doctors, int* Ndoctors, doctor aux)
{
	if (list_doctors == nullptr)
		return false;
	*Ndoctors = *Ndoctors + 1;
	doctor* changed = new doctor[*Ndoctors];
	int i=0;
	while (i < *Ndoctors - 1 && *Ndoctors - 1 != 0)
	{
		changed[i] = list_doctors[i];
		i++;
	}
	changed[i] = aux;
	delete[]list_doctors;
	list_doctors = changed;
	return true;
}

bool readInsurances(string name, insurance*& list_insurances, int* Ninsurances)
{
	if (list_insurances == nullptr || Ninsurances == nullptr)
		return false;
	fstream file;
	file.open(name, ios::in);
	if (!(file.is_open()))
		return false;

	char coma;
	insurance aux;
	string dummy;
	file >> dummy >> coma >> dummy;
	while (file)
	{
		file >> aux.ID >> coma >> aux.insurance_name;
		bool added = addInsurance(list_insurances, Ninsurances, aux);
		if (added == false)
			return false;
	}
	file.close();
	return true;
}
bool addInsurance(insurance*& list_insurances, int* Ninsurances, insurance aux)
{
	if (list_insurances == nullptr)
		return false;
	*Ninsurances = *Ninsurances + 1;
	insurance* changed = new insurance[*Ninsurances];
	int i=0;
	while (i < *Ninsurances - 1 && *Ninsurances - 1 != 0)
	{
		changed[i] = list_insurances[i];
		i++;
	}
	changed[i] = aux;
	delete[]list_insurances;
	list_insurances = changed;
	return true;
}

bool search(patient*& list_patient, int* Npatient, consults*& list_consults, int* Nconsults, contacts*& list_contacts, int* Ncontacts)
{
	if (list_patient == nullptr || list_consults == nullptr || list_contacts == nullptr)
		return false;
	int i, j;
	i = j = 0;
	int contfilled = 0;
	//bool date;
	int tenyears = 315576000;
	time_t checkTime;
	//busco el tiempo actual
	time_t tiempoactual;
	time(&tiempoactual);	//la funcion time me almacena el tiempoactual en segundos en la variable tiempoactual
	double difference;
	while (i < *Npatient)
	{
		if (list_patient[i].state == "internado")	//mayor eficienia, no busco al pedo, si esá internado me voy del while
			break;
		else if (list_patient[i].state == "fallecido")
		{
			contfilled++;
			bool filed = createFiled(list_patient[i], contfilled);

		}
		else //va a entrar cuando el estado sea =n/c
		{
			bool asistencia;//para cuando busco la ultima consulta guardame aca si asistio o no
			checkTime = LastConsult(list_consults, *Nconsults, list_patient[i],&asistencia);
			difference = difftime(tiempoactual, checkTime);
			if (asistencia)
				break;
			else
			{
				if (difference > tenyears)	//si la diferencia entre la ultima consulta y el tiempo actual es mayor a 10 lo tengo que archivar
				{
					bool filedAgain = createFiled(list_patient[i], contfilled);
					contfilled++;
				}
				else
					while (j < *Ncontacts)
					{
						if (list_contacts[j].ID == list_patient[i].ID)
						{
							//int funcion;//llamar
						}
						j++;
					}
				
			}
				
		}
		i++;
	}
	return true;
}
time_t LastConsult(consults* list_consults, int Nconsults, patient aux,bool*asistencia)	//fncón para buscar la ultima ocnsulta
{
	if (Nconsults<=0|| list_consults == nullptr)
		return NULL;
	int j = 0;
	int cont = 0;
	time_t ultima=0;
	time_t auxConsult;
	while (j < Nconsults) //para buscar la ultima consulta para dsp poder comparar si pasaron 10 años
	{
		if (aux.ID == list_consults[j].ID)//comparo las consultas que coinciden con mi pac
		{	
			auxConsult = fromStringtoTimet(list_consults[j].appointment);
			if (auxConsult > ultima || cont == 0)// busco la ultima consulta
			{
				ultima = auxConsult;//cambio el valor de ultima consulta
				*asistencia = list_consults[j].attendance;
			}
			cont++;
		}

		j++;
	}
	return ultima; 
}

time_t fromStringtoTimet(string aux)	//funcion para cambiar mi fecha string a un time t
{
	tm auxiliar{};
	time_t devuelvo;
	auxiliar.tm_mday = stoi(aux.substr(0, 1));
	auxiliar.tm_mon = stoi(aux.substr(3, 4)) - 1;
	auxiliar.tm_year = stoi(aux.substr(6, 9)) - 1900;
	devuelvo = mktime(&auxiliar);
	return devuelvo;
}

bool createFiled(patient aux, int cont)
{
	fstream filled;
	if (cont == 0)
	{
		filled.open("filled.csv", ios::out);
		if (!(filled.is_open()))
			return false;
		filled << "dni, nombre, apellido, sexo, natalicio, estado, id_os";
		filled << aux.ID << "," << aux.name << "," << aux.surname << "," << aux.sex << "," << aux.birth << "," << aux.state << "," << aux.ID_insurance;
		filled.close();
		return true;
	}
	else
	{
		filled.open("filled.csv", ios::app);
		if (!(filled.is_open()))
			return false;
		
		filled << aux.ID << "," << aux.name << "," << aux.surname << "," << aux.sex << "," << aux.birth << "," << aux.state << "," << aux.ID_insurance;
		filled.close();
		return true;
	}
}
void llamar(contacts*& list_contats, int Ncontacts, patient*& list_patients, int Npatients)
{
	int option, decision;
	bool finished=true;



}