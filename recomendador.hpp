#ifndef RECOMENDADOR_HPP
#define RECOMENDADOR_HPP

#include "analizador.hpp"

// Clase Recomendador que hereda de la clase database
class Recomendador : public database {
public:
    // Constructor de la clase Recomendador
    Recomendador(vector<Song> songs);
    
    // Destructor de la clase Recomendador
    ~Recomendador();
    
    // Método para analizar una canción
    void analizarCancion(const vector<Song>& songs);
    
    // Método para mostrar el ranking de canciones
    void mostrarRanking(vector<Song> songs);
    
    // Método para mostrar las canciones recomendadas
    void mostrarCancionesRec(vector<Song> songs);
    
    // Método para mostrar los artistas recomendados
    void mostrarArtistasRec(vector<Song> songs);
};

#endif // !RECOMENDADOR_HPP
