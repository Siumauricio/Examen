#pragma once
#include <stdio.h>
#include <stdint.h> 
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <limits>
#include <string>
using namespace std;
class RecData {
public:
	RecData ();
	char BUFFER[125];
	char Codigo[10];
	char Nombres[50];
	char Apellidos[50];
	char Departamento[3];
	char Edad[3];
	char Sueldo[9];
	void Pack ();
	void UnPack ();
	void Print ();
};
#ifndef DataFile_H
#define DataFile_H
class DataFile {
private:
	//TODO agregar resto de las funciones
public:
	RecData r;

	int  Add ();
	void Find (string);
	void Remove (string);
	void Compact ();
	void PrintAll ();
};


#endif // !DataFile_h


