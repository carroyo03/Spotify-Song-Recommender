#include <iostream>
#include <fstream> 

using namespace std;


typedef struct{

    int posicion;
    string nombreArtista;
    auto nombreCancion;
    int diasTop10;
    int posicionMax;
    int streamMax;
    int streamTotales;
    string genero;
}Song;

Song songs[100];

void cargaDatos(Song &c){
    ifstream archivo;
    archivo.open("Spotify_final_dataset.csv");
    if(archivo.is_open()){
        string temp; // variable temporal para leer cada campo
        getline(archivo, temp); // leer la primera línea (cabecera)
        int i = 0;
        while(getline(archivo, temp, ';')){ // leer cada campo separado por comas
            switch(i % 8){ // hay 8 campos en total
                case 0: c.posicion[i/8] = temp; break; // Position
                case 1: c.nombreArtista[i/8] = temp; break; // Artist Name
                case 2: c.nombreCancion[i/8] = temp; break; // Song Name
                case 3: c.diasTop10[i/8] = stoi(temp); break; // Days Top 10 (xTimes)
                case 4: c.posicionMax[i/8] = stoi(temp); break; // Peak Position
                case 5: c.streamsMax[i/8] = stof(temp); break; // Peak Streams
                case 6: c.streamsTotales[i/8] = stof(temp); break; // Total Streams
                case 7: c.genero[i/8] = temp; break; // Genre
            }
            i++;
        }
        c.contador = i/8; // número de filas
        archivo.close();
        cout << "Se han cargado los datos de " << c.contador << " canciones." << endl;
    }else{
        cout << "No se ha podido abrir el archivo" << endl;
    }
}

cargaDatos(songs);
