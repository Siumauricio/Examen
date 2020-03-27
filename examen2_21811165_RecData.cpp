#include "examen2_21811165_RecData.h"
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
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
	char a[9] ;
	size_t prevlen = 0;

	sprintf (BUFFER, "%08s", Codigo);
	strcat (BUFFER, ",");

	strcat (BUFFER, Nombres);
	strcat (BUFFER, ",");


	strcat (BUFFER, Apellidos);
	strcat (BUFFER, ",");

	strcat (BUFFER, Departamento);
	strcat (BUFFER, ",");

	strcat (BUFFER, Edad);
	strcat (BUFFER, ",");


	strcat (BUFFER, Sueldo);
	strcat (BUFFER, ",");

	//cout << BUFFER << endl;

	memset (BUFFER + strlen(BUFFER), '*', sizeof (BUFFER) - strlen (BUFFER));
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
	while (!file.eof ()) {
	
		string palabra;
		getline (file, palabra);
		strcpy (r.BUFFER, palabra.c_str ());
		if (file.eof ()) {
			cout << "Usuario no Encontrado!" << endl;
			break;
		}
		r.UnPack ();
		if (strcmp (r.Nombres, nombre.c_str ()) == 0&&r.Codigo[0]!='D') {
			r.Print ();
			cout << "Usuario Encontrado!" << endl;
			return;
		}
	}
	file.close ();

}

void DataFile::Remove (string nombre) {

	ifstream file ("Archivo.txt");
	ofstream fileW ("Archivo.txt", ios::in);
	while (!file.eof ()) {
		int posicion=file.tellg();
		string palabra;
		getline (file, palabra);
		strcpy (r.BUFFER, palabra.c_str ());
		if (file.eof ()) {
			cout << "Usuario no Encontrado!" << endl;
			break;
		}
		r.UnPack ();
		if (strcmp (r.Nombres, nombre.c_str ()) == 0&&r.Codigo[0]!='D') {
			fileW.seekp (posicion, ios::beg);
			fileW.put ('D');
			cout << "Registro Eliminado!" << endl;
			return;
		}
	}
	file.close ();
}

void DataFile::Compact () {
	ifstream file ("Archivo.txt");
	ofstream fileW ("Auxiliar.txt");
	while (!file.eof()) {
		string palabra;
		getline (file, palabra);
		strcpy (r.BUFFER,palabra.c_str());
		//file.read (r.BUFFER, 125);
		if (file.eof ()) {
			//cout << "Usuario no Encontrado!" << endl;
			break;
		}
		r.UnPack ();
		if (r.Codigo[0] != 'D') {
			r.Pack ();
			fileW <<r.BUFFER<<endl;
		}
	}
	file.close ();
}

void DataFile::PrintAll () {
	ifstream file ("Archivo.txt");
	ofstream fileW ("Auxiliar.txt");
	while (!file.eof ()) {
		string palabra;
		getline (file, palabra);
		strcpy (r.BUFFER, palabra.c_str ());
		if (file.eof ()) {
			break;
		}
		r.UnPack ();
		if (r.Codigo[0] != 'D') {
			r.Print ();
		}
	}
	file.close ();


}
