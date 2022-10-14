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
            if (str[0] == '>')
            {
                if (sec != "")
                {
                    Secuencia secuencia;
                    secuencia.setNombre_sec(datos);
                    secuencia.setSecuencia(sec);

                    secuencia.setTamano(cont);

                    lista.push_back(secuencia);
                    sec = "";
                    datos = "";
                    cont = 0;
                }
                datos = str;
            }
            else
            {
                // copiar solo la primera secuencia
                if (aux == 0)
                {
                    sec = str;
                    cont = strlen(str);
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

        lista.push_back(secuencia);
        sec = "";
        aux=0;
    }
    else
    {
        cout << "No se pudo abrir el archivo" << endl;
    }
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

void listarSecuencias(list<Secuencia> lista)
{
    int cont = 0;
    // Cuantas veces cada codigo aparece en la secuencia por cada codigo genetico
    for (list<Secuencia>::iterator it = lista.begin(); it != lista.end(); ++it)
    {
        vector<char> secuencias;
        for (int i = 0; i < it->getSecuencia().size(); i++)
        {
            secuencias.push_back(it->getSecuencia()[i]);
        }
        vector<char>::iterator it2 = secuencias.begin();

        // it2 vacio
        if (it2 == secuencias.end())
        {
            break;
        }
        else
        {
            cout << it->getNombre_sec() << endl;
            listarSecuenciaw(secuencias, cont);
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
        for (int i = 0; i < secuencias.size(); i++)
        {
            cout << secuencias[i];
        }
        secuencias.clear();
        system("pause");
    }
}
