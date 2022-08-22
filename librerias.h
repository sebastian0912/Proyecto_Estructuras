#ifndef _LIBRERIA_H_
#define _LIBRERIA_H_

#include <iostream>
#include <queue>
#include <vector>
#include <iomanip>
#include <vector>
#include <list>
#define MAX_LENGHT 1000
using namespace std;

struct CodigosGeneticos
{
    string nombre_sec;
    list<char> secuencia;
};

void guardar(list<CodigosGeneticos> &lista, string nombre_archivo)
{
    int cont = 0;
    char cadena[MAX_LENGHT];
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
                memset(cadena, 0, sizeof(cadena));
                fe >> cadena;
                if (strstr(cadena, ">") != NULL)
                {
                    aux.nombre_sec = cadena;
                    // aux.nombre_sec.erase(0, 1);
                    memset(cadena, 0, sizeof(cadena));
                    fe >> cadena;
                    for (int i = 0; i < MAX_LENGHT; i++)
                    {
                        aux.secuencia.push_back(cadena[i]);
                    }
                }
                lista.push_back(aux);
                aux.secuencia.clear();
                aux.nombre_sec.clear();
            }
            lista.pop_back();
            cout << lista.size() << "   secuencias cargadas" << endl;
        }
        else
        {
            cout << nombre_archivo << "   no se encuentra o no puede leerse." << endl;
        }
    }
    // eliminar ultimo elemento de la lista
}

void listarSecuenciaw(list<char> cod, int &aux, bool &centinela)
{
    int cont = 0, cont2 = 0;
    vector<char> codigos = {'A', 'C', 'G', 'T', 'U', 'R', 'Y', 'K', 'M', 'S', 'W', 'B', 'D', 'H', 'V', 'N', 'X', '-'};
    for (int i = 0; i < codigos.size(); i++)
    {
        list<char>::iterator it = cod.begin();
        while (it != cod.end())
        {
            if (*it == codigos[i])
            {
                cont++;
            }
            if (*it == '-')
            {
                cont2++;
            }
            it++;
        }

        if (cont != 0 && cont2 !=0 && codigos[i] != '-')
        {
            aux -= cont;
            cout << codigos[i] << " Contiene" << cont << "bases" << endl;            
        }
        else if (cont != 0 && cont2==0 && codigos[i] != '-')
        {
            aux += cont;
            cout << codigos[i] << " Contiene: " << cont << "bases" << endl;            
        }
        cont = 0;
        cont2 = 0;
    }
}

void listarSecuencias(list<CodigosGeneticos> &lista)
{
    vector<char> codigos = {'A', 'C', 'G', 'T', 'U', 'R', 'Y', 'K', 'M', 'S', 'W', 'B', 'D', 'H', 'V', 'N', 'X'};
    int cont = 0;
    bool centinela;
    // Cuantas veces cada codigo aparece en la secuencia por cada codigo genetico
    for (list<CodigosGeneticos>::iterator it = lista.begin(); it != lista.end(); ++it)
    {

        list<char>::iterator it2 = it->secuencia.begin();

        // it2 vacio
        if (it2 == it->secuencia.end())
        {
            break;
        }
        else
        {
            centinela = false;
            cout << it->nombre_sec << endl;
            listarSecuenciaw(it->secuencia, cont, centinela);
            if (cont<1){
                cout<< "Esta secuencia contiene al menos "<< cont*-1 <<" bases"<<endl;
            }
            else{
                cout<< "Esta secuencia contiene "<< cont <<" bases"<<endl;
            }
            cont = 0;
        }

        system("pause");
    }
}

#endif