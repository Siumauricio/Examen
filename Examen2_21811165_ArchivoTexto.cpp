#include "ArchivoTexto.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#pragma warning(disable: 4996)
ArchivoTexto::ArchivoTexto () {}

ArchivoTexto::~ArchivoTexto () {}

void ArchivoTexto::EscribirRegistro () {
	ofstream file3 ("Archivo.txt", ios::in | ios::out);
	cout << "Nombre :";
	cin >> r.Nombre;
	cout << "Apellido: ";
	cin >> r.Apellido;
	cout << "Direccion: ";
	cin >> r.Direccion;
	cout << "Ciudad: ";
	cin >> r.Ciudad;
	cout << "Estado: ";
	cin >> r.Estado;
	cout << "ZipCode: ";
	cin >> r.ZipCode;
	r.Pack ();

	ifstream file ("Archivo.txt",ios::app);
	while (1) {
		int posicion = file.tellg();

		file.read (r.BUFFER, 64);
		if (file.eof ()) {
			return;
		}
		r.Unpack ();
		if (r.Nombre[0] == '*') {
			ofstream file2 ("Archivo.txt", ios::in | ios::out);
			file2.seekp (posicion, ios::beg);
			file2 << r.BUFFER;
			return;
		}
	}
	file3 << r.BUFFER ;
	//file.close ();


	
	//file << r.BUFFER;
	//file.close ();
}

