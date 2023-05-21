


#include "main.hpp"
#include "recomendador.hpp"



int main() {
    srand(time(nullptr));
    vector<Song> spotifySongs;
    cargaDatos(spotifySongs);
    /*for(Song s: spotifySongs){
      cout << s.posicion << " " << s.nombreArtista << " " << s.nombreCancion << " " << s.diasTop10 << " " << s.diasTop10 << " " << s.posicionMax << " " << s.streamMax << " " <<s.streamTotales << " " << s.genero << endl;
    }*/
    Recomendador recom(spotifySongs);
    int option = 2;
    while (option != 0) {
        option = menu();
        switch (option) {
            case 0:
                cout << "Saliendo del programa..." << endl;
                break;
            case 1:
                cout << "Recomendador de canciones..." << endl;
                recom.mostrarCancionesRec(spotifySongs);
                break;
            case 2:
                cout << "Recomendador de artistas..." << endl;
                recom.mostrarArtistasRec(spotifySongs);
                break;
            case 3:
                cout << "Análisis de canción" << endl;
                recom.analizarCancion(spotifySongs);
                break;
            case 4:
                cout << "Rankings" << endl;
                recom.mostrarRanking(spotifySongs);
                break;
            default:
                cout << "Opción inválida. Inténtelo de nuevo." << endl;
                break;
        }
    }

    return 0;
}

int menu() {
    int opcion;
    cout << "========== Menú ==========" << endl;
    cout << "0. Salir" << endl;
    cout << "1. Recomendador de canciones" << endl;
    cout << "2. Recomendador de artistas" << endl;
    cout << "3. Análisis de canción" << endl;
    cout << "4. Ranking de cantantes" << endl;
    cout << "Ingrese su opción (0-4): ";
    cin >> opcion;
    return opcion;
}



void cargaDatos(vector<Song>& songs) {
    ifstream archivo;
    archivo.open("data/Spotify_final_dataset.txt");
    if (archivo.is_open()) {
        string temp;
        getline(archivo, temp);
        while (getline(archivo, temp)) {
            Song song;
            int campo = 0;
            size_t pos = 0;
            string delimiter = "   ";
            while ((pos = temp.find(delimiter)) != string::npos) {
                string token = temp.substr(0, pos);
                switch (campo) {
                    case 0: song.posicion = stoi(token); break;
                    case 1: song.nombreArtista = token; break;
                    case 2: song.nombreCancion = token; break;
                    case 3: song.diasTop10 = stoi(token); break;
                    case 4: song.posicionMax = stoi(token); break;
                    case 5: song.streamMax = stoi(token); break;
                    case 6: song.streamTotales = stoll(token); break;
                    case 7: song.genero = token; break;
                }
                temp.erase(0, pos + delimiter.length());
                campo++;
            }
            // Agregar el campo restante (género)
            song.genero = temp;
            songs.push_back(song);
        }
        int numCanciones = songs.size();
        cout << "Se han cargado los datos de " << numCanciones << " canciones." << endl;
        archivo.close();
    } else {
        cout << "No se ha podido abrir el archivo" << endl;
    }
}

