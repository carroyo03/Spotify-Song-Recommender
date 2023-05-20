#ifndef ANALIZADOR_HPP
#define ANALIZADOR_HPP

#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include "main.hpp"


typedef struct{
    vector <Song> cancioness;
    vector <int> posiciones;
    string str;
}Rankings;

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
        Rankings Rankings1(vector <Song> songs);
        Rankings Rankings2(vector <Song> songs);
        vector <pair <string,int> > Rankings3(vector <Song> songs);
};


#endif // !ANALIZADOR_HPP
