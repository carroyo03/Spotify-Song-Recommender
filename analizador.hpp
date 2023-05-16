#ifndef ANALIZADOR_HPP
#define ANALIZADOR_HPP

#include <iostream>
#include "main.hpp"

// Clase abstracta que contendrá el vector songs
class baseRA
{

protected:
    vector <Song> songs;
};

class Analizador : public baseRA{};

void analisisCancion();
vector <Song> cancionesSugeridas(), artistasSugeridos();

#endif // !ANALIZADOR_HPP
