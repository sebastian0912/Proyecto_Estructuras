#ifndef CARACTERES_H
#define CARACTERES_H

#pragma once

#include <iostream>
#include <queue>
using namespace std;

class Caracteres
{

public:
    Caracteres();
    ~Caracteres();

    char getCaracter()
    {
        return caracter;
    }
    void setCaracter(char caracter_c)
    {
        caracter = caracter_c;
    }
    int getFrecuencia()
    {
        return frecuencia;
    }
    void setFrecuencia(int frecuencia_c)
    {
        frecuencia = frecuencia_c;
    }

private:
    char caracter;
    int frecuencia;
};

bool operator<(const Caracteres &c1, const Caracteres &c2)
{
    Caracteres aux1, aux2;
    aux1 = c1;
    aux2 = c2;
    return aux1.getFrecuencia() < aux2.getFrecuencia();
}

#endif