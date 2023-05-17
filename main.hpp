#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>

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

void menu();

void cargaDatos(Song songs[]);

#endif // !MAIN_HPP