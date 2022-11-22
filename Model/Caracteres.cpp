#include "Caracteres.h"

Caracteres::Caracteres()
{
}
Caracteres::~Caracteres()
{
}

bool operator<(const Caracteres &c1, const Caracteres &c2)
{
    Caracteres aux1, aux2;
    aux1 = c1;
    aux2 = c2;
    return aux1.getFrecuencia() < aux2.getFrecuencia();
}


