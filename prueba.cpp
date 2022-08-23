#include <iostream>
#include <vector>
#include <string.h>
#include <fstream>
#include <iomanip>
#include <list>
#include <fstream>

#include "librerias.h"

using namespace std;
int tamanomatriz(string nomnbreArhivoOld)
{
  char cadena[750];
  ifstream fe(nomnbreArhivoOld);
  int cont = 0;
  while (!fe.eof())
  {
    if (fe >> cadena)
    {
      // comparar tamaños de cadenas para saber cual es el strlengt mas largo
      if (strlen(cadena) > cont)
      {
        cont = strlen(cadena);
      }
    }
  }
  fe.close();
  return cont;
}

int main()
{
  // int tam = tamanomatriz("archivosFASTA/AligSeq85678.fa");
  char cadena[MAX_LENGHT];
  CodigosGeneticos aux;
  list<CodigosGeneticos> lista;
  ifstream fe("archivosFASTA/AligSeq85678-lin.fa");
  int cont = 0;

  while (!fe.eof())
  {
    if (fe >> cadena && strstr(cadena, ">") != NULL)
    {
      // cout << cadena << endl;
      aux.nombre_sec = cadena;
      //cout << aux.nombre_sec << endl;      
      cont = 0;
    }
    else
    {
      if (fe >> cadena)
      {
        //cout << cadena << endl;
        for (int i = 0; i < strlen(cadena); i++)
        {
          aux.secuencia.push_back(cadena[i]);
        }
      }
    }
    lista.push_back(aux);
    aux.secuencia.clear();
    aux.nombre_sec.clear();
  }
  fe.close();
  for (list<CodigosGeneticos>::iterator it = lista.begin(); it != lista.end(); ++it)
  {
    cout << it->nombre_sec << endl;
    for (vector<char>::iterator it2 = it->secuencia.begin(); it2 != it->secuencia.end(); ++it2)
    {
      cout << *it2;
    }
    cout << endl;
  }

  system("pause");
  return 0;
}