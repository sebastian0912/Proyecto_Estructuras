#ifndef CODIFICACION_H
#define CODIFICACION_H

#pragma once
#include <cstdint>

class Codificacion
{
public:
    Codificacion();
    ~Codificacion();

private:
    short cantidadBases;
    int8_t bases;
    double frecuencia;
    float cantidad_secuencias;
    short tamano_Nombre_secuencia;
    char ultimoCaracterDelNombre;
    double longitudSecuencia;
    
};

#endif