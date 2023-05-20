#ifndef ANALIZADOR_HPP
#define ANALIZADOR_HPP

#include <iostream>
#include <utility>
#include <algorithm>
#include "main.hpp"


// Clase abstracta que contendrá el vector songs
class database
{
    protected:
        vector <Song> songs;
        

};

class Analizador: public database{

    public:
        //using database::database;
        Analizador(vector <Song> songs);
        ~Analizador();
        vector <string> analizarCancionesRec(vector <Song> songs);
        vector <string> analizarArtistasRec(vector <Song> songs);
        void Rankings1();
        void Rankings2();
        void Rankings3();
};


#endif // !ANALIZADOR_HPP
