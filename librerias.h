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
    vector<char> secuencia;
};

vector<char> codigos = {'A', 'C', 'G', 'T', 'U', 'R', 'Y', 'K', 'M', 'S', 'W', 'B', 'D', 'H', 'V', 'N', 'X'};

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
                    aux.nombre_sec.erase(0, 1);
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

void listarSecuenciaw(vector<char> cod, int &aux)
{
    int cont = 0, cont2 = 0;
    vector<char> codigos = {'A', 'C', 'G', 'T', 'U', 'R', 'Y', 'K', 'M', 'S', 'W', 'B', 'D', 'H', 'V', 'N', 'X', '-'};
    for (int i = 0; i < codigos.size(); i++)
    {
        vector<char>::iterator it = cod.begin();
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

        if (cont != 0 && cont2 != 0 && codigos[i] != '-')
        {
            aux -= cont;
            cout << codigos[i] << " Contiene: " << cont << " bases" << endl;
        }
        else if (cont != 0 && cont2 == 0 && codigos[i] != '-')
        {
            aux += cont;
            cout << codigos[i] << " Contiene: " << cont << " bases" << endl;
        }
        cont = 0;
        cont2 = 0;
    }
}

void listarSecuencias(list<CodigosGeneticos> &lista)
{
    int cont = 0;
    // Cuantas veces cada codigo aparece en la secuencia por cada codigo genetico
    for (list<CodigosGeneticos>::iterator it = lista.begin(); it != lista.end(); ++it)
    {

        vector<char>::iterator it2 = it->secuencia.begin();

        // it2 vacio
        if (it2 == it->secuencia.end())
        {
            break;
        }
        else
        {
            cout << it->nombre_sec << endl;
            listarSecuenciaw(it->secuencia, cont);
            if (cont < 1)
            {
                cout << "Esta secuencia contiene al menos " << cont * -1 << " bases" << endl;
            }
            else
            {
                cout << "Esta secuencia contiene " << cont << " bases" << endl;
            }
            cont = 0;
        }

        system("pause");
    }
}

void histograma(string nombre_secuencia, list<CodigosGeneticos> &lista)
{
    int cont = 0;
    for (list<CodigosGeneticos>::iterator it = lista.begin(); it != lista.end(); ++it)
    {
        if (it->nombre_sec == nombre_secuencia)
        {
            vector<char>::iterator it2 = it->secuencia.begin();
            if (it2 == it->secuencia.end())
            {
                cout << "La secuencia " << nombre_secuencia << " esta invalidada, no se encuentra" << endl;
                break;
            }
            else
            {
                if (it->nombre_sec == nombre_secuencia)
                {
                    listarSecuenciaw(it->secuencia, cont);
                }
            }
        }
    }
}

void cuantos(string sub, vector<char> &aux, int &cont2)
{
    char cadena[MAX_LENGHT];
    char subcadena[MAX_LENGHT];
    char *busqueda = NULL;
    strcpy(subcadena, sub.c_str());
    // cout<<subcadena<<endl;
    // copiar aux.secuencia a cadena
    for (int i = 0; i < aux.size(); i++)
    {
        cadena[i] = aux[i];
    } /*
     for (int i=0; i< sizeof(cadena); i++)
     {
         cout<<cadena[i];
     }    */
    busqueda = strstr(cadena, subcadena);
    if (busqueda == NULL)
    {
        cout << "La secuencia dada no existe." << endl;
    }
    while (busqueda != NULL)
    {
        cont2++;
        busqueda = strstr(busqueda + 1, subcadena);
    }
}

void sub_secuencia(string sub, list<CodigosGeneticos> &lista)
{
    int cont = 0, aux = 0;
    // cout << sub << endl;
    bool encontrado = false;
    char cadena[MAX_LENGHT], cadena2[MAX_LENGHT];
    strcpy(cadena, sub.c_str());
    // cout << cadena << endl;

    for (list<CodigosGeneticos>::iterator it = lista.begin(); it != lista.end(); ++it)
    {
        // cout << "   " << it->nombre_sec << endl;
        vector<char>::iterator it2 = it->secuencia.begin();
        cuantos(sub, it->secuencia, cont);
        // cout<<endl<<endl;
    }
    cout << endl
         << endl;
    cout << "La subsecuencia " << sub << " aparece " << cont << " veces" << endl;

    // es_subsecuencia CAACATCACCAATCA
}

#endif