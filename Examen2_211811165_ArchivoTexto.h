#pragma once
#include "Examen2_21811165_Registro.h"
#include <string>
#ifndef ArchivoTexto_H
#define ArchivoTexto_H
using namespace std;

class ArchivoTexto {
private:
    Registro r;
    Registro r2;
public:
    ArchivoTexto ();
    ~ArchivoTexto ();
    void EscribirRegistro ();
    void ImprimirRegistro ();
    Registro Buscar (string);
    void EliminarRegistro (string);
    void Print ();
    void Compactar ();
};
#endif // !PERSON_H
