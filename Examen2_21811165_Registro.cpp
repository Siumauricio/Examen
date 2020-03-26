#include "Registro.h"
#include  <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#pragma warning(disable: 4996)
Registro::Registro () {
	Nombre[0] = 0;
	Apellido[0] = 0;
	Direccion[0] = 0;
	Ciudad[0] = 0;
	Estado[0] = 0;
	ZipCode[0] = 0;
	BUFFER[0] = 0;
}

Registro::~Registro () {}

void Registro::Pack () {
   size_t prevlen = 0;

   prevlen+= strlen (Nombre)+1;
   strcat (BUFFER, Nombre);
   strcat (BUFFER, "|");

   prevlen += strlen (Apellido)+1;
   strcat (BUFFER, Apellido);
   strcat (BUFFER, "|");
	
   prevlen += strlen (Direccion)+1;
   strcat (BUFFER, Direccion );
   strcat (BUFFER, "|");

   prevlen += strlen (Ciudad)+1;
   strcat (BUFFER, Ciudad);
   strcat (BUFFER, "|");

   prevlen += strlen (Estado)+1;
   strcat (BUFFER, Estado );
   strcat (BUFFER, "|");

   prevlen += strlen (ZipCode)+1;
   strcat (BUFFER, ZipCode);
   strcat (BUFFER, "|");

   memset (BUFFER + prevlen, ' ', sizeof (BUFFER) - prevlen);
   *(BUFFER + sizeof (BUFFER)) = '\0';

}

void Registro::Unpack () {
    char* token = BUFFER;
    
    char* tok = strtok (token, "|");
    strcpy (Nombre, token);
    
    token = strtok (0, "|");
    strcpy (Apellido, token);

    token = strtok (0, "|");
    strcpy (Direccion, token);

    token = strtok (0, "|");
    strcpy (Ciudad, token);

    token = strtok (0, "|");
    strcpy (Estado, token);

    token = strtok (0, "|");
    strcpy (ZipCode, token);

}
//  sprintf (Estado, " %s ", token);