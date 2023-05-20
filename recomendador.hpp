#ifndef RECOMENDADOR_HPP
#define RECOMENDADOR_HPP
#include "analizador.hpp"

class Recomendador : public database {
    public:
        Recomendador (vector <Song> songs);
        ~Recomendador();
        void analizarCancion(vector <Song> songs), mostrarRanking(vector <Song> songs), mostrarCancionesRec(vector <Song> songs), mostrarArtistasRec(vector <Song> songs);
};


#endif // !RECOMENDADOR_HPP