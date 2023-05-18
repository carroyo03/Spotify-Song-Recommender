#ifndef RECOMENDADOR_HPP
#define RECOMENDADOR_HPP
#include "analizador.hpp"

class Recomendador : public database {
    using database::database;
    void mostrarRecomendacion(),mostrarCantantes(), mostrarCancion(), mostrarRanking();
};


#endif // !RECOMENDADOR_HPP