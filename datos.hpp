//@author Carlos Arroyo

#ifndef DATOS_HPP
#define DATOS_HPP
#include <iostream>


typedef struct { //@author Gabriel Nassri
    int posicion;
    std::string nombreArtista;
    std::string nombreCancion;
    int diasTop10;
    int posicionMax;
    int streamMax;
    int streamTotales;
    std::string genero;
} Song;

std::vector <Song> songs;

void cargaDatos(Song songs[]);

#endif // !DATOS_HPP


