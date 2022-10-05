#ifndef SECUENCIA_H
#define SECUENCIA_H

#pragma once

#include <vector>
#include <iostream>
using namespace std;

class Secuencia
{
public:
    Secuencia();
    ~Secuencia();

    void guardar(list<Secuencia> &lista, string nombre_archivo);

    void listarSecuenciaw(vector<char> cod, int &aux);
    void listarSecuencias(list<Secuencia> lista);

    
    string getNombre_sec()
    {
        return nombre_sec;
    }

    void setNombre_sec(string nombre)
    {
        nombre_sec = nombre;
    }

    string getSecuencia()
    {
        return secuencia;
    }

    void setSecuencia(string secuencia_sec)
    {        
        secuencia = secuencia_sec;
        
    }

    int getTamano()
    {
        return tamano;
    }

    void setTamano(int tamano_c)
    {
        tamano = tamano_c;
    }

private:
    string nombre_sec;
    string secuencia;
    int tamano;
};

#endif