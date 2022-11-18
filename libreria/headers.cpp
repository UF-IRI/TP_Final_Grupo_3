#include "headers.h"
#include <cstring>
#include <string>


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

	
	patient aux;
	string headers;
	getline(file, headers);
	

	while (file)
	{
		char coma1;
		file >> aux.ID >> coma1;
		getline(file, aux.name, ',');
		getline(file, aux.surname, ',');
		file >> aux.sex >> coma1;
		getline(file, aux.birth, ',');
		getline(file, aux.state, ',');
		file >> aux.ID_insurance >> coma1;

		bool added = addPatient(*&list_patient, Npatient, aux);
		if (added == false)	//hubo algun error al agregar el paciente
			return false;
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
	if (list_contacts == nullptr)	//si no tengo memoria chau
		return false;
	
	fstream file;	

	file.open(name, ios::in);	//abro el archivo

	if (!(file.is_open()))
		return false;

	contacts aux;
	string headers;
	

	getline(file, headers);
	while (file)
	{
		char coma;
		file >> aux.ID >> coma;
		getline(file, aux.telephone,',');
		getline(file, aux.celphone,',');
		getline(file, aux.direccion,',');
		getline(file,aux.mail,'\n');
		
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

	consults aux;
	string headers;
	getline(file, headers);
	while (file)
	{
		char coma;
		file >> aux.ID >> coma;
		getline(file, aux.required, ',');
		getline(file, aux.appointment, ',');
		file>>aux.attendance>>coma;
		getline(file, aux.doctors_ID, '\n');

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
	string headers; 


	getline(file, headers);
	while (file)
	{
		file >> aux.ID >> coma;
		getline(file, aux.name, ',');
		getline(file, aux.surname, ',');
		getline(file, aux.telephone, ',');
		getline(file, aux.speciality, ',');
		file >> aux.state;

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

bool search(patient*& list_patient, int Npatient, consults*& list_consults, int Nconsults, contacts*& list_contacts, int Ncontacts, doctor*& list_doctors, int Ndoctors)
{
	if (list_patient == nullptr || list_consults == nullptr || list_contacts == nullptr)
		return false;
	int i, j;
	i = j = 0;
	int contRecuperar;
	int contfiled = 0;
	//bool date;
	int tenyears = 315576000;
	time_t checkTime;
	//busco el tiempo actual
	time_t tiempoactual;
	time(&tiempoactual);	//la funcion time me almacena el tiempoactual en segundos en la variable tiempoactual
	double difference;
	while (i < *Npatient)
	{
		if (list_patient[i].state == "fallecido")
		{
			bool filed = createFiled(list_patient[i], contfiled);
			contfiled++;
		}
		else if(list_patient[i].state =="n/c")//va a entrar cuando el estado sea =n/c
		{
			bool asistencia;//para cuando busco la ultima consulta guardame aca si asistio o no
			checkTime = LastConsult(list_consults, *Nconsults, list_patient[i],&asistencia);//busca la ult consulta y me la devuelve como time_t
			difference = difftime(tiempoactual, checkTime);
			if (!(asistencia))//LastConsult me va a devolver en asistencia true si asistio, por lo que ouedo mirar otro pac
			{
				if (difference > tenyears)	//si la diferencia entre la ultima consulta y el tiempo actual es mayor a 10 lo tengo que archivar
				{
					bool filedAgain = createFiled(list_patient[i], contfiled);	//lo archivo directo
					contfiled++;
				}
				else
				{
					bool recuperanding = archivosRecuperables(list_patient[i],list_contacts,Ncontacts,list_doctors,Ndoctors, contRecuperar);	//funciones secretaria
					contRecuperar++;
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
bool archivosRecuperables(patient*&list_patient, contacts*&list_contacts, int Ncontacts, doctor*&list_doctors,int Ndoctors,int contRecuperar)
{
	
	fstream recuperables;
	if (contRecuperar == 0)
	{
		recuperables.open("recuperables.csv", ios::out);
		if (!(recuperables.is_open()))
			return false;
		recuperables << "dni, nombre, apellido, sexo, natalicio, estado, id_os";
		recuperables << aux.ID << "," << aux.name << "," << aux.surname << "," << aux.sex << "," << aux.birth << "," << aux.state << "," << aux.ID_insurance;
		recuperables.close();
		return true;
	}
	else
	{
		recuperables.open("recuperables.csv", ios::app);
		if (!(recuperables.is_open()))
			return false;

		recuperables << aux.ID << "," << aux.name << "," << aux.surname << "," << aux.sex << "," << aux.birth << "," << aux.state << "," << aux.ID_insurance;
		recuperables.close();
		return true;
	}
}



