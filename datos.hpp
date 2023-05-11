#ifndef DATOS_HPP
#define DATOS_HPP
#include <iostream>
#include <vector>

using namespace std;

typedef struct {
    int posicion;
    string nombreArtista;
    string nombreCancion;
    int diasTop10;
    int posicionMax;
    int streamMax;
    int streamTotales;
    string genero;
} Song;

vector <Song> songs;

void cargaDatos(vector <Song> songs);

#endif // !DATOS_HPP


