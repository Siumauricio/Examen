#pragma once
#ifndef Registro_H
#define Registro_H

class Registro {
public:
    char BUFFER[64];
    char Nombre[16];
    char Apellido[15];
    char Direccion[15];
    char Ciudad[8];
    char Estado[4];
    char ZipCode[6];
    Registro ();
    ~Registro ();
    void Pack ();
    void Unpack ();
};
#endif // !PERSON_H
