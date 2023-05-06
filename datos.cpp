/*#include <iostream>
#include <fstream> 

using namespace std;


typedef struct{

    int posicion;
    string nombreArtista;
    string nombreCancion;
    int diasTop10;
    int posicionMax;
    int streamMax;
    int streamTotales;
    string genero;
}Song;

Song songs[100];

void cargaDatos(Song songs []);

int main(){
    cargaDatos(songs);
    return 0;
}

void cargaDatos(Song songs[]){
    ifstream archivo;
    archivo.open("Spotify_final_dataset.txt");
    if(archivo.is_open()){
        string temp; // variable temporal para leer cada campo
        getline(archivo, temp); // leer la primera línea (cabecera)
        int i = 0;
        while(getline(archivo, temp, '   ')){ // leer cada campo separado por comas
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
*/

#include <iostream>
#include <fstream> 

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

Song songs[100];

void cargaDatos(Song songs[]);

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

void cargaDatos(Song songs[]) {
    ifstream archivo;
    archivo.open("Spotify_final_dataset.txt");
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


