#include "gmock/gmock.h"
#include "headers.h"
#include <iostream>
#include <fstream>


using namespace testing;
	/*TEST(Casos_Base, Test_Caso1) {
		ASSERT_THAT(1, 1);
	}

	TEST(Casos_Base, Test_Caso2) {
		ASSERT_THAT(1, 1);
	}*/

	TEST(archivos, abrirlos) {

		fstream prueba;
		patient Pacprueba = {45,"valen","mao",'F',"07/06/2004","n/c","italiano"};
		prueba.open("archivoprueba.csv", ios::out);
		
		prueba << "ID, name, surname, sex, birth, state, ID_insurance";
		prueba << Pacprueba.ID << "," << Pacprueba.name << "," << Pacprueba.surname << "," << Pacprueba.sex << "," << Pacprueba.birth << "," << Pacprueba.state << "," << Pacprueba.ID_insurance;
		prueba.close();
		int Npatient = 0;
		patient* list_patient = new patient[Npatient];
		bool test=readpatient("archivoprueba.csv", list_patient, &Npatient);
		ASSERT_THAT(Npatient, 1);
		EXPECT_TRUE(test);
		ASSERT_THAT(list_patient[0].name, Pacprueba.name);


	}
