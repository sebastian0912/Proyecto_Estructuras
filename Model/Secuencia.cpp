#include "Secuencia.h"
#include <fstream>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <list>
#include <iterator>

#define MAX_LENGHT 1000

// Constructor
Secuencia::Secuencia() {}

Secuencia::~Secuencia() {}

void Secuencia::guardar(list<Secuencia> &lista, string nombre_archivo)
{
    char *str = new char[800];
    string datos;
    ifstream fe(nombre_archivo);
    int cont = 0, aux = 0;

    // Comprobar si el archivo esta vacio y luego leeerlo
    if (fe.is_open())
    {
        string sec;
        while (!fe.eof())
        {
            fe.getline(str, MAX_LENGHT);
            Secuencia secuencia;
            if (str[0] == '>')
            {
                Secuencia secuencia;
                secuencia.setNombre_sec(datos);
                secuencia.setSecuencia(sec);
                secuencia.setTamano(cont);
                lista.push_back(secuencia);
                sec = "";
                datos = "";
                datos = str;
                aux = 0;
            }
            else
            {
                // copiar solo la primera secuencia
                if (aux == 0)
                {
                    sec = str;
                    cont = sec.size();
                    aux++;
                }
                else
                {
                    sec += str;
                }
            }
        }
        Secuencia secuencia;
        secuencia.setNombre_sec(datos);
        secuencia.setSecuencia(sec);
        secuencia.setTamano(cont);
        lista.push_back(secuencia);
        sec = "";
    }
    else
    {
        cout << "No se pudo abrir el archivo" << endl;
    }
    fe.close();
    lista.pop_front();
    cout << "Secuencias guardadas" << endl;
    for (list<Secuencia>::iterator it = lista.begin(); it != lista.end(); ++it)
    {
        cout << "   " << it->nombre_sec << endl;
        cout << "   " << it->tamano << endl;
        cout << "   " << it->secuencia << endl;
    }
    cout << "Tamaño de la lista: " << lista.size() << endl;
    fe.close();
}





