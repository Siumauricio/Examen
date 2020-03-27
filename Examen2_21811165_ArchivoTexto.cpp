#include "Examen2_211811165_ArchivoTexto.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#pragma warning(disable: 4996)
ArchivoTexto::ArchivoTexto () {}

ArchivoTexto::~ArchivoTexto () {}

void ArchivoTexto::EscribirRegistro () {
	ifstream pFile ("Archivo.txt", ios::app);
	ofstream file ("Archivo.txt", ios::app);
	pFile.seekg (0, ios::end);
	if (pFile.tellg () == 0 ){
		file << "-1   ";
		cout << "VACIO" << endl;
	}
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
	//ifstream fileR ("Archivo.txt");
	/*
	while (1) {
		int posicion = fileR.tellg();	
		fileR.read (r2.BUFFER, 64);
		if (fileR.eof ()) {
			break;
		}
		r2.Unpack ();
		if (r2.Nombre[0] == '*') {
			ofstream fileW ("Archivo.txt", ios::in | ios::out);
			fileW.seekp (posicion, ios::beg);
			fileW << r.BUFFER;
			return;
		}
	}*/
	file << r.BUFFER;
	file.close ();
}

void ArchivoTexto::ImprimirRegistro () {
	ifstream file ("Auxiliar.txt", ios::app);
	while (1) {
		file.read (r.BUFFER, 64);
		if (file.eof ()) {
			return;
		}
		r.Unpack ();
		if (r.Nombre[0] != '*') {
			Print ();
		}
	}
	file.close ();
}
int posicion = 0;
Registro ArchivoTexto::Buscar (string nombre) {
	ifstream file ("Archivo.txt");
	Registro vacio;
	file.seekg (5, ios::beg);
	while (1) {
		posicion = file.tellg ();
		file.read (r.BUFFER, 64);
		if (file.eof ()) {
			return vacio;
		}
		r.Unpack ();
		if (strcmp (r.Nombre, nombre.c_str ())==0) {
			file.close ();
			return r;
		}
	}
	file.close ();
}

void ArchivoTexto::Print () {
	cout << r.Nombre << "  " << r.Apellido << "  " << r.Direccion << "  " << r.Ciudad << "  " << r.Estado << "  " << r.ZipCode << "\n";
}

void ArchivoTexto::EliminarRegistro (string nombre) {
	Registro registro = Buscar (nombre);
	char borrado[16] = { 0 };
	if (strcmp (registro.Nombre, nombre.c_str ()) == 0) {
		ofstream file ("Archivo.txt", ios::in | ios::out);
		file.seekp (posicion, ios::beg);
		file.put('*');
		file.seekp (0, ios::beg);
		file << posicion;
	}
}
