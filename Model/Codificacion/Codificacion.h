#ifndef CODIFICACION_H
#define CODIFICACION_H

#pragma once
#include <cstdint>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Codificacion
{

public:

    Codificacion();
    ~Codificacion();

    short getCantidadBases() const { return cantidadBases; }
    void setCantidadBases(short cantidadBases_) { cantidadBases = cantidadBases_; }

    map <char, double> getBases() const { return bases; }
    void setBases( map <char, double> &bases_) { bases = bases_; }

    vector<string> getBinario() const { return binario; }
    void setBinario(const vector<string> &binario_) { binario = binario_; }

    vector<char> getUltimoCaracterDelNombre() const { return ultimoCaracterDelNombre; }
    void setUltimoCaracterDelNombre(const vector<char> &ultimoCaracterDelNombre_) { ultimoCaracterDelNombre = ultimoCaracterDelNombre_; }

    float getCantidadSecuencias() const { return cantidadSecuencias; }
    void setCantidadSecuencias(float cantidadSecuencias_) { cantidadSecuencias = cantidadSecuencias_; }

    vector<int> getTamanoNombresecuencia() const { return tamanoNombresecuencia; }
    void setTamanoNombresecuencia(const vector<int> &tamanoNombresecuencia_) { tamanoNombresecuencia = tamanoNombresecuencia_; }

    vector<double> getLongitudSecuencia() const { return longitudSecuencia; }
    void setLongitudSecuencia(const vector<double> &longitudSecuencia_) { longitudSecuencia = longitudSecuencia_; }    

private:

    short cantidadBases;
    map <char, double> bases;    
    float cantidadSecuencias;
    vector<int> tamanoNombresecuencia;
    vector<char> ultimoCaracterDelNombre;
    vector<double> longitudSecuencia;    
    vector<string> binario;

};

#endif