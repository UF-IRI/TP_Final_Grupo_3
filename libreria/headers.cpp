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
		return false;

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

bool search(patient*& list_patient, int Npatient, consults*& list_consults, int Nconsults, contacts*& list_contacts, int Ncontacts, doctor*& list_doctors, int Ndoctors, string filed_name, string recuperados_nombre, int *contfiled)
{
	if (list_patient == nullptr || list_consults == nullptr || list_contacts == nullptr)
		return false;

	int i, j;
	i = j = 0;
	int contRecup=0;	//contador de pacientes recuperados
	string idmed;	//para copiar de la ultima consulta
	//contador de archivados
	int tenyears = 315576000;	//para compara la diferencia
	time_t checkTime;	//para chequear la diferencia
	llamar recuperados; //estructura con los datos importantes que se le van a sar al archivo de la secretaria
	//busco el tiempo actual
	time_t tiempoactual;
	time(&tiempoactual);	//la funcion time me almacena el tiempoactual en segundos en la variable tiempoactual
	double difference;	//diferencia de tiempo

	while (i < Npatient)	//recorro el paciente
	{
		if (list_patient[i].state == "fallecido")	//chequeo si está fallecido
		{
			bool filed = createFiled(list_patient[i], *contfiled, filed_name);	//llamo a la funcion para archivar
			contfiled++;	//incremento el contador de archivados
		}
		else if(list_patient[i].state =="n/c")	//va a entrar cuando el estado sea =n/c
		{
			bool asistencia;	//para cuando busco la ultima consulta, me guardo aca si asistio o no

			checkTime = LastConsult(list_consults, Nconsults, list_patient[i],&asistencia,&idmed);//busca la ult consulta y me la devuelve como time_t
			difference = difftime(tiempoactual, checkTime);	//hago la diferencia entre el tiempo actual y la ultima consulta

			if (!(asistencia))//LastConsult me va a devolver en asistencia true si asistio, por lo que ouedo mirar otro pac
			{
				if (difference > tenyears)	//si la diferencia entre la ultima consulta y el tiempo actual es mayor a 10 lo tengo que archivar
				{
					bool filedAgain = createFiled(list_patient[i], *contfiled, filed_name);	//lo archivo directo
					contfiled++;
				}
				else
				{
					llenarLlamar(&recuperados, list_patient[i], list_contacts, Ncontacts, list_doctors,Ndoctors, idmed);	//me crea la estructura
					bool recuperando = archivosRecuperado(recuperados, contRecup, recuperados_nombre);	//si asistio y pasaron menos de 10 años, lo paso al archivo de recuperados
					contRecup++;
				}
				
			}
				
		}
		i++;
	}
	return true;
}

time_t LastConsult(consults* list_consults, int Nconsults, patient aux, bool*asistencia, string*idmed)	//funcion para buscar la ultima ocnsulta, cuando desconozco el estado del paciente
{
	if (Nconsults==0|| list_consults == nullptr)	//si no tengo espacio de memoria ni consultas
		return NULL;
	
	int j = 0;
	int cont = 0;
	time_t ultima=0;
	time_t auxConsult;

	while (j < Nconsults) //para buscar la ultima consulta para dsp poder comparar si pasaron 10 años
	{
		if (aux.ID == list_consults[j].ID)//comparo las consultas que coinciden con mi pac
		{	
			auxConsult = fromStringtoTimet(list_consults[j].appointment);	//cambio a timet
			if (auxConsult > ultima || cont == 0)// busco la ultima consulta
			{
				*idmed = list_consults[j].doctors_ID;	//lo necesito para completar la esctructura llamar
				ultima = auxConsult;	//cambio el valor de ultima consulta
				*asistencia = list_consults[j].attendance;	//para mandarle a search si asistio o no a la ultima consulta que acabamo de clacular
			}
			cont++;
		}

		j++;
	}
	return ultima; //devuelvo la ultima consulta
}	//existe en search

time_t fromStringtoTimet(string aux)	//funcion para cambiar mi fecha string a un time t
{
	tm auxiliar{};
	time_t devuelvo;
	auxiliar.tm_mday = stoi(aux.substr(0, 1));
	auxiliar.tm_mon = stoi(aux.substr(3, 4)) - 1;
	auxiliar.tm_year = stoi(aux.substr(6, 9)) - 1900;
	devuelvo = mktime(&auxiliar);
	return devuelvo;
}	//existe en search

bool createFiled(patient aux, int cont, string filed_name)	//lleno el archivo de archivados
{
	fstream filed;
	if (cont == 0)	//si el archivo esta vacio/no existe
	{
		filed.open(filed_name, ios::out);
		if (!(filed.is_open()))
			return false;
		filed << "dni, nombre, apellido, sexo, natalicio, estado, id_os";
		filed << aux.ID << "," << aux.name << "," << aux.surname << "," << aux.sex << "," << aux.birth << "," << aux.state << "," << aux.ID_insurance;
		filed.close();
		return true;
	}
	else
	{
		//hago append para agregar si ya hay pacientes archivados
		filed.open(filed_name, ios::app);
		if (!(filed.is_open()))
			return false;
		
		filed << aux.ID << "," << aux.name << "," << aux.surname << "," << aux.sex << "," << aux.birth << "," << aux.state << "," << aux.ID_insurance;
		filed.close();
		return true;
	}
}	//existe en search

void llenarLlamar(llamar* recup, patient paciente, contacts*& list_contacts, int Ncontacts, doctor*& list_doctors, int Ndoctors, string idmed)
{	//aca llenams el struct llamar que es con el que llenamos el archivo para secretaria
	llamar datosImp;
	datosImp.nombre = paciente.name;
	datosImp.apellido = paciente.surname;
	datosImp.obraSoc = paciente.ID_insurance;
	datosImp.ID_med = idmed;
	int i = 0;
	while (i < Ndoctors)	//para copiar los datos del doctor
	{
		if (list_doctors[i].ID == idmed)
		{
			datosImp.nombreMed = list_doctors[i].name;
			datosImp.apellidoMed = list_doctors[i].surname;
			datosImp.especialidad = list_doctors[i].speciality;
			datosImp.telefonoMed = list_doctors[i].telephone;
			datosImp.activo = list_doctors[i].state;

		}
		i++;
	}
	i = 0;
	while (i < Ncontacts)	//para copiar el telefono
	{
		if (list_contacts[i].ID == paciente.ID)
			datosImp.telefono = list_contacts[i].telephone;
		i++;
	}
}	//existe en search y secretaria

bool leerSecretaria(string nombre_recuperados, llamar*& recuperados, int* Nrecuperados)	//que llenamos en buscar, son recuperables dudoso
{	//leo el archivo de recuprados y armo un listado
	fstream archi;
	archi.open(nombre_recuperados, ios::in);
	if (!(archi.is_open()))
		return false;
	string header;
	char coma;
	getline(archi, header);
	llamar aux;

	while (archi)
	{
		archi >> aux.id >> coma;
		getline(archi, aux.nombre, ',');
		getline(archi, aux.apellido, ',');
		getline(archi, aux.telefono, ',');
		getline(archi, aux.ID_med, ',');
		getline(archi, aux.nombreMed, ',');
		getline(archi, aux.apellidoMed, ',');
		getline(archi, aux.telefonoMed, ',');
		getline(archi, aux.especialidad, ',');
		archi >> aux.activo >> coma;	//creemos que los booll son un problema
		getline(archi, recuperados->obraSoc, '\n');

		bool added = addLlamar(*&recuperados, Nrecuperados, aux);
		if (added == false)	//hubo algun error al agregar el paciente
			return false;
	}
	archi.close();
	return true;

}	//lo invoco en main
bool addLlamar(llamar*& recuperados, int* Nrecuperados, llamar aux)	//funcion que agrega "llamar"
{
	if (recuperados == nullptr)
		return false;
	*Nrecuperados = *Nrecuperados + 1;
	llamar* changed = new llamar[*Nrecuperados];
	int i = 0;
	while (i < *Nrecuperados - 1 && *Nrecuperados - 1 != 0)
	{
		changed[i] = recuperados[i];
		i++;
	}
	changed[i] = aux;
	delete[]recuperados;
	recuperados = changed;
	return true;
}
void secretaria(llamar aux, int *contFiled, patient* list_patient, int Np, insurance* list_insurances, string nombre_recuperados, string filed_name, int NOS)	//le paso un llamar y me fijo si lo archivo o lo recpero oficialmente
{//le cae un llamar y va a ir oficialmente al archivo de recuperables si  vivo=1 y vuelve=1
	srand(time(0));	//inicializo rand
	int N = 0;//cant de pacientes recuperados
	int i = 0;	//0 false, 1 true
	while (Np)
	{
		int atendio = rand() % 2;	//valores entre 0 y 1;
		if (atendio == 1)
		{
			int vivo_muerto = rand() % 2;
			if (vivo_muerto == 0)	//si esta muerto lo archivo
			{
				bool archi = createFiled(list_patient[i], *contFiled, filed_name);
				list_patient[i].state = "fallecido";	//le cambio el estado en la lista
				*contFiled = *contFiled + 1;
			}
			else
			{
				int vuelve = rand() % 2;	//random para determinar si vuelve o no
				if (vuelve == 0)	//no va a volver, lo archivo
				{
					bool filed= createFiled(list_patient[i], *contFiled,filed_name);	//tambien lo archivo
					*contFiled = *contFiled + 1;
				}
				else // va oficialmente al archivo de recuperables
				{

					int modifico = rand() % 2;
					if(modifico==0)	//modifico
					{
						bool modificar = modify(aux, NOS, list_insurances);
					}
					bool recuperar = archivosRecuperado(aux, N, nombre_recuperados);
					N++;
				}
			}
		}
		i++;
	}


}
bool archivosRecuperado(llamar aux,int cont, string nombre_recu)	//me creo el archivo de recuperables
{
	fstream recuperables;
	if (cont == 0)
	{
		recuperables.open(nombre_recu, ios::out);
		if (!(recuperables.is_open()))
			return false;
		recuperables << "nombre,apellido,telefono,idmedico,nombreMedico,apellidoMedico,telefonoMedico,especialidadMedico,actividadMedico,ObraSocialPac";
		recuperables << aux.nombre << "," << aux.apellido << "," << aux.telefono << "," << aux.ID_med << "," << aux.nombreMed << "," << aux.apellidoMed << "," << aux.telefonoMed << "," << aux.especialidad << "," << aux.activo<<","<<aux.obraSoc;
		recuperables.close();
		return true;
	}
	else
	{
		recuperables.open(nombre_recu, ios::app);
		if (!(recuperables.is_open()))
			return false;

		recuperables << aux.nombre << "," << aux.apellido << "," << aux.telefono << "," << aux.ID_med << "," << aux.nombreMed << "," << aux.apellidoMed << "," << aux.telefonoMed << "," << aux.especialidad << "," << aux.activo << "," << aux.obraSoc;
		recuperables.close();
		return true;
	}
}
bool modify(llamar recuperable, int NOS, insurance* list_insurance)	//funcion para modificar la obra social
{
	if (list_insurance == nullptr)
		return false;
	srand(time(0));	//inicializo el rand
	int newOS = rand() % 6 + 1;	//genero numeros enetre 1 y 6 para compararlo con el listado de obras sociales  y meterselo a recuperable
	int i = 0;
	while (i < NOS)
	{
		if (newOS == list_insurance[i].ID)
		{
			recuperable.obraSoc = list_insurance[i].ID;
		}
		i++;
	}
	return true;

}

