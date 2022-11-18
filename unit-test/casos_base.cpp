#include "gmock/gmock.h"
#include "headers.h"



using namespace testing;

TEST(archivos, abrirlos) {
		bool abierto;
		fstream prueba;
		patient Pacprueba = {45,"valen","mao",'F',"07/06/2004","n/c","italiano"};
		prueba.open("archivoprueba.csv", ios::out);
		if (!(prueba.is_open()))
			abierto = false;
		else
		{
			abierto = true;
			prueba << "ID, name, surname, sex, birth, state, ID_insurance";
			prueba << Pacprueba.ID << ',' << Pacprueba.name << ',' << Pacprueba.surname << ',' << Pacprueba.sex << ',' << Pacprueba.birth << ',' << Pacprueba.state << ',' << Pacprueba.ID_insurance;
			prueba << Pacprueba.ID << ',' << Pacprueba.name << ',' << Pacprueba.surname << ',' << Pacprueba.sex << ',' << Pacprueba.birth << ',' << Pacprueba.state << ',' << Pacprueba.ID_insurance;
			prueba.close();
			int Npatient = 0;
			patient* list_patient = new patient[Npatient];

			bool test = readpatient("archivoprueba.csv", *&list_patient, &Npatient);
			//ASSERT_THAT(Npatient, 2);
			EXPECT_TRUE(test);
			EXPECT_THAT(list_patient[0].name, Pacprueba.name);
		}

	}
	TEST(archivosconsul, abrirlos)
	{
		bool abierto;
		fstream prueba;
		consults Consultprueba;// 867584849"01 / 11 / 2001", "19 / 12 / 2001", true, "00 - 334 - 0838"
	
		Consultprueba.ID = 867584849;
		prueba.open("archivoprueba.csv", ios::out);
		if (!(prueba.is_open()))
			abierto = false;
		else
		{
			abierto = true;
			prueba << "dni_pac, fecha_solicitado, fecha_turno, presento, matricula_med";
			prueba << Consultprueba.ID << "," << Consultprueba.required << "," << Consultprueba.appointment << "," << Consultprueba.attendance << "," << Consultprueba.doctors_ID;
			prueba.close();
			int Nconsults = 0;
			consults* list_consults = new consults[Nconsults];

			bool test = readConsults("archivoprueba.csv", *&list_consults, &Nconsults);
			ASSERT_THAT(Nconsults, 1);
			EXPECT_TRUE(test);
			ASSERT_THAT(list_consults[0].ID, Consultprueba.ID);
		}
	}
	TEST(archivosContact, abrirlos)
	{
		bool abierto;
		fstream prueba;
		contacts Contactprueba = { 967597385," + 41 203 339 0504"," + 57 722 907 7201","Pine View","strillow0@is.gd" };

		prueba.open("archivoprueba.csv", ios::out);
		if (!(prueba.is_open()))
			abierto = false;
		else
		{
			abierto = true;
			prueba << "dni_pac,telefono,celular,direccion,mail";
			prueba << Contactprueba.ID << "," << Contactprueba.telephone << "," << Contactprueba.celphone << "," << Contactprueba.direccion << "," << Contactprueba.mail;
			prueba.close();
			int Ncontacts = 0;
			contacts* list_contacts = new contacts[Ncontacts];

			bool test = readContact("archivoprueba.csv", *&list_contacts, &Ncontacts);
			ASSERT_THAT(Ncontacts, 1);
			EXPECT_TRUE(test);
			EXPECT_THAT(list_contacts[0].ID, Contactprueba.ID);
		}
	}
	TEST(archivosObraSoc, abrirlos)
	{
		bool abierto;
		fstream prueba;
		insurance Insuranceprueba = { 1,"Medicus"};

		prueba.open("archivoprueba.csv", ios::out);
		if (!(prueba.is_open()))
			abierto = false;
		else
		{
			abierto = true;
			prueba << "id_os,obra_social";
			prueba << Insuranceprueba.ID << "," << Insuranceprueba.insurance_name;
			prueba.close();
			int Ninsurances = 0;
			insurance* list_insurances = new insurance[Ninsurances];
			bool test = readInsurances("archivoprueba.csv", *&list_insurances, &Ninsurances);
			EXPECT_THAT(Ninsurances, 1);
			EXPECT_TRUE(test);
			EXPECT_THAT(list_insurances[0].ID, Insuranceprueba.ID);
		}
		EXPECT_TRUE(abierto);
	}
	TEST(archivosMed, abrirlos)
	{
		bool abierto;
		fstream prueba;
		doctor Doctorprueba = { "04 - 723 - 0907","Araldo","Grafom","827 - 190 - 3137","farmacologia clinica",true};

		prueba.open("archivoprueba.csv", ios::out);
		if (!(prueba.is_open()))
			abierto = false;
		else
		{
			abierto = true;
			prueba << "matricula,nombre,apellido,telefono,especialidad,activo";
			prueba << Doctorprueba.ID << "," << Doctorprueba.name<<","<< Doctorprueba.surname<<","<< Doctorprueba.telephone<<","<< Doctorprueba.speciality<<","<< Doctorprueba.state;
			prueba.close();
			int Ndoctors = 0;
			doctor* list_doctors = new doctor[Ndoctors];
			bool test = readDoctor("archivoprueba.csv", *&list_doctors, &Ndoctors);
			EXPECT_THAT(Ndoctors, 1);
			EXPECT_TRUE(test);
			EXPECT_THAT(list_doctors[0].ID, Doctorprueba.ID);
		}
		EXPECT_TRUE(abierto);
	}
	
	/*
	TEST(search, noConincidence)
	{
		int Np = 2;
		patient* list_patient = new patient[Np];
		list_patient[0]= {45,"valen","mao",'F',"07/06/2004","n/c","italiano"};
		list_patient[1] = { 73,"guada","helou",'F',"24/03/2004","n/c","medicus" };
		int Nc = 4;
		consults* list_consults = new consults[Nc];
		list_consults[0] = { 45,"28/09/2017","28/09/2018",false,"218976" };
		list_consults[1] = { 45,"28/09/2015","28/09/2016",true,"218976" };
		list_consults[2] = { 73,"28/09/2014","28/09/2015",false,"218976" };
		list_consults[3] = { 73,"28/09/2015","28/09/2016",true,"218976" };
		int Ncont = 3;
		contacts* list_contacts = new contacts[Ncont];
		int ID;
		list_contacts[0] = { 47586,"02304666144","+5491122832779","vuelta de obligado 875","lupehelou@gmail.com" };
		list_contacts[1] = { 98765,"6482945659","+5491112345678","av santa fe 4576","glopez@gmail.com" };
		list_contacts[2] = { 45678,"02846892","+5491198765432","jose hernandez 3412","dperez@gmail.com" };
		int Nd = 2;
		doctor* list_docs = new doctor[Nd];
		list_contacts[0] = { 47586,"02304666144","+5491122832779","vuelta de obligado 875","lupehelou@gmail.com" };
		list_contacts[1] = { 98765,"6482945659","+5491112345678","av santa fe 4576","glopez@gmail.com" };
		bool check = search(*&list_patient,  Np, *& list_consults,  Nc, *& list_contacts, Ncont, *& list_docs, Nd, nameArch, nameRecup)



		

	}*/

	TEST(fromStringToTimet, coincide)
	{
		string aux = "21/03/2004";
		tm auxiliar{};
		auxiliar.tm_mday = 21;
		auxiliar.tm_mon = 03-1;
		auxiliar.tm_year = 2004-1900;
		time_t esperado= mktime(&auxiliar);
		time_t real = fromStringtoTimet(aux);
		EXPECT_THAT(esperado, real);
	}
	TEST(ultimaConsul, unicaPrueb)
	{
		time_t LastConsult(consults*list_consults,int Nconsults,patient aux, bool*asistencia, string idmed)
	}
