#ifndef _LIBRERIA_H_
#define _LIBRERIA_H_

#include <iostream>
#include <queue>
#include <vector>
#include <iomanip>
#include <vector>
#include <list>

using namespace std;

struct CodigosGeneticos
{
    string nombre_sec;
    list<char> secuencia;
};

void guardar(vector<CodigosGeneticos> &lista, string nombre_archivo)
{
    int cont = 0;
    char cadena[1000];
    CodigosGeneticos aux;
    ifstream fe(nombre_archivo.c_str());
    // comprobar si el archivo esta vacio
    if (fe.peek() == std::ifstream::traits_type::eof())
    {
        cout << nombre_archivo << " no contiene ninguna secuencia" << endl;
    }
    else
    {
        if (fe.is_open())
        {
            while (!fe.eof())
            {
                aux.nombre_sec.clear();
                aux.secuencia.clear();
                memset(cadena, 0, sizeof(cadena));
                fe >> cadena;

                if (strstr(cadena, ">") != NULL)
                {
                    aux.nombre_sec = cadena;
                    cout<<aux.nombre_sec<<endl;
                    cont++;
                }
                else
                {
                    for (int i = 0; i < strlen(cadena); i++)
                    {
                        aux.secuencia.push_back(cadena[i]);

                    }
                }                
                lista.push_back(aux);
                
                
            }
            
            lista.push_back(aux);
            cout << "   archivo cargado" << endl;
            cout << lista.size() << "   secuencias cargadas" << endl;
        }
        else
        {
            cout << nombre_archivo << "   no se encuentra o no puede leerse." << endl;
        }
    }
}

#endif