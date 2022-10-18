#include "Codificacion.h"

Codificacion::Codificacion()
{

}

// contructor de todos atributos de Codificacion
Codificacion::Codificacion(short cantidadBases, map <char, double> bases, float cantidadSecuencias, vector<int> tamanoNombreSecuencia, vector<char> ultimoCaracterDelNombre, vector<double> longitudSecuencia, int cantidadCerosAgregados, vector<string> binario)
{
    this->cantidadBases = cantidadBases;
    this->bases = bases;
    this->cantidadSecuencias = cantidadSecuencias;
    this->tamanoNombresecuencia = tamanoNombreSecuencia;
    this->ultimoCaracterDelNombre = ultimoCaracterDelNombre;
    this->longitudSecuencia = longitudSecuencia;
    this->cantidadCerosAgregados = cantidadCerosAgregados;
    this->binario = binario;
}

Codificacion::~Codificacion()
{

}