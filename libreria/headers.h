struct date
{
	int day, month, year;
};

struct consults
{
	int ID;
	date required;
	date appointment;
	bool attendance;
	string doctors_ID;
};

struct contacts
{
	int ID;
	string telephone;
	string celphone;
	string mail;
};

struct doctor
{
	string ID;
	string name;
	string surname;
	string telephone;
	string speciality;
	bool state;
};

struct insurance
{
	int ID;
	string insurance_name;
};

struct patient
{
	int ID;
	string name;
	string surname;
	char sex;
	date birth;
	string state;
	int ID_insurance;
};