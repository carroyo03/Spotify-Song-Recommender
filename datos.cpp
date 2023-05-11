#include <iostream>
#include <fstream> 
#include "datos.hpp"

using namespace std;

int main() {
    cargaDatos(songs);
    /* for (int i = 0; i < 53; i++)
    {
        cout << songs[i].diasTop10<< " ";
        cout << songs[i].genero<< " ";
        cout << songs[i].nombreArtista<< " ";
        cout << songs[i].nombreCancion<< " ";
        cout << songs[i].posicion<< " ";
        cout << songs[i].posicionMax<< " ";
        cout << songs[i].streamMax<< " ";
        cout << songs[i].streamTotales<< " ";
        cout<<endl;

        
    } */
    
    return 0;
}

void cargaDatos(std::vector <Song> songs) {
    ifstream archivo;
    archivo.open("/data/Spotify_final_dataset.txt");
    if (archivo.is_open()) {
        string temp; // variable temporal para leer cada campo
        getline(archivo, temp); // leer la primera línea (cabecera)
        int i = 0;
        while (getline(archivo, temp)) { // leer cada línea del archivo
            int campo = 0;
            size_t pos = 0;
            string delimiter = "   ";
            while ((pos = temp.find(delimiter)) != string::npos) {
                string token = temp.substr(0, pos);
                switch (campo) {
                    case 0: songs[i].posicion = stoi(token); break; // Position
                    case 1: songs[i].nombreArtista = token; break; // Artist Name
                    case 2: songs[i].nombreCancion = token; break; // Song Name
                    case 3: songs[i].diasTop10 = stoi(token); break; // Days Top 10 (xTimes)
                    case 4: songs[i].posicionMax = stoi(token); break; // Peak Position
                    case 5: songs[i].streamMax = stoi(token); break; // Peak Streams
                    case 6: songs[i].streamTotales = stoi(token); break; // Total Streams
                    case 7: songs[i].genero = token; break; // Genre
                }
                temp.erase(0, pos + delimiter.length());
                campo++;
            }
            i++;
        }
        int numCanciones = i; // número de canciones cargadas
        cout << "Se han cargado los datos de " << numCanciones << " canciones." << endl;
        archivo.close();
    } else {
        cout << "No se ha podido abrir el archivo" << endl;
    }
}


