#include "main.hpp"



int main(){
    menu();
    return 0;
}

void menu(){
  int opcion;
  
  do {
    cout << "========== Menú ==========" << endl;
    cout << "1. Salir" << endl;
    cout << "2. Recomendador de canciones" << endl;
    cout << "3. Recomendador de artistas" << endl;
    cout << "4. Análisis de canción" << endl;
    cout << "5. Ranking de cantantes" << endl;
    cout << "Ingrese su opción (1-5): ";
    cin >> opcion;
    
    switch(opcion) {
      case 1:
        cout << "Saliendo del programa..." << endl;
        break;
      case 2:
        cout << "Recomendador de canciones..." << endl;
        // Aquí iría el código para la opción 2
        break;
      case 3:
        cout << "Recomendador de artistas..." << endl;
        // Aquí iría el código para la opción 3
        break;
      case 4:
        cout << "Análisis de canción" << endl;
        // Aquí iría el código para la opción 4
        break;
      case 5:
        cout << "Rankings" << endl;
        // Aquí iría el código para la opción 5
        break;
      default:
        cout << "Opción inválida. Inténtelo de nuevo." << endl;
        break;
    }
    
  } while(opcion != 1);
  
}

void cargaDatos(vector <Song> songs) {
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
