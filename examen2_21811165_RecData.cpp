#include "RecData.h"
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;
#pragma warning(disable: 4996)
RecData::RecData (){
	BUFFER[0] = 0;
	Codigo[0] = 0;
	Nombres[0] = 0;
	Apellidos[0] = 0;
	Departamento[0] = 0;
	Edad[0] = 0;
	Sueldo[0] = 0;
}

void RecData::Pack () {
	size_t prevlen = 11;
	string padded = string ((10 - strlen (Codigo)), '0').append (Codigo);
	
	strcat (BUFFER, padded.c_str ());
	strcat (BUFFER, ",");

	prevlen += strlen (Nombres) + 1;
	strcat (BUFFER, Nombres);
	strcat (BUFFER, ",");

	prevlen += strlen (Apellidos) + 1;
	strcat (BUFFER, Apellidos);
	strcat (BUFFER, ",");

	prevlen += strlen (Departamento) + 1;
	strcat (BUFFER, Departamento);
	strcat (BUFFER, ",");

	prevlen += strlen (Edad) + 1;
	strcat (BUFFER, Edad);
	strcat (BUFFER, ",");

	prevlen += strlen (Sueldo) + 1;
	strcat (BUFFER, Sueldo);
	strcat (BUFFER, ",");

	memset (BUFFER + prevlen, '*', sizeof (BUFFER) - prevlen);
	*(BUFFER + sizeof (BUFFER)) = '\0';
	//cout << BUFFER << endl;

}

void RecData::UnPack () {


	char* token = BUFFER;

	char* tok = strtok (token, ",");
	strcpy (Codigo, tok);

	token = strtok (0, ",");
	strcpy (Nombres, token);

	token = strtok (0, ",");
	strcpy (Apellidos, token);

	token = strtok (0, ",");
	strcpy (Departamento, token);

	token = strtok (0, ",");
	strcpy (Edad, token);

	token = strtok (0, ",");
	strcpy (Sueldo, token);


}

void RecData::Print () {
	cout << Codigo << "   " << Nombres << " " << Apellidos << " " << Departamento << " " << Edad << " " << Sueldo << endl;
}

int DataFile::Add () {
	ofstream file ("Archivo.txt", ios::app);

	cout << "Codigo :";
	cin >> r.Codigo;
	cout << "Nombres: ";
	cin >> r.Nombres;
	cout << "Apellidos: ";
	cin >> r.Apellidos;
	cout << "Departamento: ";
	cin >> r.Departamento;
	cout << "Edad: ";
	cin >> r.Edad;
	cout << "Sueldo: ";
	cin >> r.Sueldo;
	r.Pack ();
	file << r.BUFFER << endl;
	file.close ();
	return -1;
}

void DataFile::Find (string nombre) {
	ifstream file ("Archivo.txt");
	while (1) {
		file.read (r.BUFFER, 125);
		if (file.eof ()) {
			cout << "Usuario no Encontrado!" << endl;
			break;
		}
		r.UnPack ();
		if (strcmp (r.Nombres, nombre.c_str ()) == 0&&r.Codigo[0]!='D') {
			cout << "Usuario Encontrado!" << endl;
			return;
		}
	}
	file.close ();

}

void DataFile::Remove (string nombre) {

	ifstream file ("Archivo.txt");
	ofstream fileW ("Archivo.txt", ios::in);
	while (1) {
		int posicion = file.tellg();
		file.read (r.BUFFER, 125);
		if (file.eof ()) {
			cout << "Usuario no Encontrado!" << endl;
			break;
		}
		r.UnPack ();
		if (strcmp (r.Nombres, nombre.c_str ()) == 0&&r.Codigo[0]!='D') {
			fileW.seekp (posicion, ios::beg);
			fileW.put ('D');
			cout << "Usuario Encontrado!" << endl;
			return;
		}
	}
	file.close ();
}

void DataFile::Compact () {
	ifstream file ("Archivo.txt");
	ofstream fileW ("Auxiliar.txt");
	while (1) {
		int posicion = file.tellg ();
		file.read (r.BUFFER, 125);
		if (file.eof ()) {
			cout << "Usuario no Encontrado!" << endl;
			break;
		}
		r.UnPack ();
		if (r.Codigo[0] != 'D') {
			fileW <<r.Codigo<<","<<r.Nombres<<"," <<r.Apellidos<< ","<<r.Departamento<<","<<r.Edad<< ","<<r.Sueldo<<","<<endl;
		}
	}
	file.close ();
}
