#include <iostream>
#include <vector>
#include <algorithm>
#include "recomendador.hpp"

Recomendador::Recomendador(vector<Song> songss) {
    songs = songss;
}

Recomendador::~Recomendador(){}

void Recomendador::mostrarCancionesRec(vector<Song> songs) {
    Analizador a(songs);
    vector<string> cancionesRec = a.analizarCancionesRec(songs);
    cout << "--------------------------------\n";
    cout << "CANCIONES RECOMENDADAS\n";
    cout << "--------------------------------\n";
    for (int i = 0; i < cancionesRec.size(); i++) {
        cout << cancionesRec[i] << endl;
    }
}

void Recomendador::mostrarArtistasRec(vector<Song> songs) {
    Analizador a(songs);
    vector<string> artistasRec = a.analizarArtistasRec(songs);
    cout << "--------------------------------\n";
    cout << "ARTISTAS RECOMENDADOS\n";
    cout << "--------------------------------\n";
    for (int i = 0; i < artistasRec.size(); i++) {
        cout << artistasRec[i] << endl;
    }
}

/*void Recomendador::analizarCancion(vector<Song> songs) {
    string cancion;
    vector<string> canciones;
    vector<int> posiciones;
    bool encontrado = false;

    for (Song s : songs) {
        canciones.push_back(s.nombreArtista);
    }

    cout << "Introduce el nombre de la canción que quieres analizar: " << endl;
    cin >> cancion;
    do {
        encontrado = find(canciones.begin(), canciones.end(), cancion) != canciones.end();
        if (!encontrado) {
            cout << "Canción no encontrada. Introduce una canción adecuada: \n";
            cin >> cancion;
        }

    } while (!encontrado);

    auto it = find(canciones.begin(), canciones.end(), cancion);
    int pos = distance(canciones.begin(), it);

    cout << "--------------------------------------\n";
    cout << "Datos sobre la canción " << songs[pos].nombreCancion << endl;
    cout << "--------------------------------------\n";
    cout << "Artista: " << songs[pos].nombreArtista << endl;
    cout << "Género: " << songs[pos].genero << endl;
    cout << "Streams Totales: " << songs[pos].streamTotales << endl;
}
*/

void Recomendador::analizarCancion(const vector<Song>& songs) {
    string cancion;

    cout << "Introduce el nombre de la canción que quieres analizar: " << endl;
    //cin >> cancion;
    cin.ignore(); // Ignorar cualquier caracter residual en el buffer de entrada
    getline(cin, cancion);

    // Buscar la canción por nombre en el vector songs
    /*auto it = find_if(songs.begin(), songs.end(), [&](const Song& s) {
        return s.nombreCancion == cancion;
    });*/
    // Buscar la canción por nombre en el vector songs
string cancionMinusculas = cancion;
transform(cancionMinusculas.begin(), cancionMinusculas.end(), cancionMinusculas.begin(), [](unsigned char c) {
    return std::tolower(c);
});

auto it = find_if(songs.begin(), songs.end(), [&](const Song& s) {
    string nombreCancionMinusculas = s.nombreCancion;
    transform(nombreCancionMinusculas.begin(), nombreCancionMinusculas.end(), nombreCancionMinusculas.begin(), [](unsigned char c) {
        return std::tolower(c);
    });
    return nombreCancionMinusculas.find(cancionMinusculas) != string::npos;
});


    if (it != songs.end()) {
       
        const Song& cancionEncontrada = *it;

        cout << "--------------------------------------\n";
        cout << "Datos sobre la canción " << cancionEncontrada.nombreCancion << endl;
        cout << "--------------------------------------\n";
        cout << "Artista: " << cancionEncontrada.nombreArtista << endl;
        cout << "Género: " << cancionEncontrada.genero << endl;
        cout << "Streams Totales: " << cancionEncontrada.streamTotales << endl;
    } else {
        
        cout << "Canción no encontrada." << endl;
    }
}


void Recomendador::mostrarRanking(vector<Song> songs) {
    int opcion;
    Analizador a(songs);

    cout << "Elige el tipo de Ranking: " << endl;
    cout << "    1. Ranking de canciones por cantante\n";
    cout << "    2. Ranking de canciones por género\n";
    cout << "    3. Ranking de cantantes por género\n";
    cin >> opcion;

    switch (opcion) {
        /*case 1: {   // Ranking de canciones por cantante
            Rankings r1 = a.Rankings1(songs);
            cout << "-----------------------------------------------\n";
            cout << "Ranking de canciones de " << r1.str << endl;
            cout << "-----------------------------------------------\n";
            for (int i = 0; i < r1.posiciones.size(); i++) {
                r1.cancioness.push_back(songs[r1.posiciones[i]]);
                r1.cancioness[i].posicion = contadorPosicion; // Asignar la posición actualizada
                cout << r1.cancioness[i].posicion << ". " << r1.cancioness[i].nombreCancion << endl;
                contadorPosicion++; // Incrementar el contador de posición
            }
            r1.posiciones.clear();
            r1.cancioness.clear();
            break;
        }*/
        
        case 1: {
        Rankings r1 = a.Rankings1(songs);
        cout << "-----------------------------------------------\n";
        cout << "Ranking de canciones de " << r1.str << endl;
        cout << "-----------------------------------------------\n";
        
        int contadorPosicion = 1; // Inicializar el contador de posición

        for (int i = 0; i < r1.posiciones.size(); i++) {
            r1.cancioness.push_back(songs[r1.posiciones[i]]);
            r1.cancioness[i].posicion = contadorPosicion; // Asignar la posición actualizada
            cout << r1.cancioness[i].posicion << ". " << r1.cancioness[i].nombreCancion << endl;
            contadorPosicion++; // Incrementar el contador de posición
        }
        
        r1.posiciones.clear();
        r1.cancioness.clear();
        break;
    }

        /*case 2: {    // Ranking de canciones por género
            Rankings r1 = a.Rankings2(songs);
            cout << "-----------------------------------------------\n";
            cout << "Ranking de canciones de " << r1.str << endl;
            cout << "-----------------------------------------------\n";
            for (int i = 0; i < r1.posiciones.size(); i++) {
                r1.cancioness.push_back(songs[r1.posiciones[i]]);
                cout << r1.cancioness[i].posicion << ". " << r1.cancioness[i].nombreCancion << endl;
            }
            r1.posiciones.clear();
            r1.cancioness.clear();
            break;
        }*/

        case 2: {
    Rankings r1 = a.Rankings2(songs);
    cout << "-----------------------------------------------\n";
    cout << "Ranking de canciones de " << r1.str << endl;
    cout << "-----------------------------------------------\n";
    
    int contadorPosicion = 1; // Inicializar el contador de posición

    for (int i = 0; i < r1.posiciones.size(); i++) {
        r1.cancioness.push_back(songs[r1.posiciones[i]]);
        r1.cancioness[i].posicion = contadorPosicion; // Asignar la posición actualizada
        cout << r1.cancioness[i].posicion << ". " << r1.cancioness[i].nombreCancion << endl;
        contadorPosicion++; // Incrementar el contador de posición
    }
    
    r1.posiciones.clear();
    r1.cancioness.clear();
    break;
}

        case 3: {   // Ranking de cantantes por género
            vector<pair <string,int> > r3 = a.Rankings3(songs);
            for (int i = 0; i < r3.size(); i++) {
                cout << i + 1 << ". " << r3[i].first << " Con un total de " << r3[i].second << " streams totales" << endl;
            }
            r3.clear();
            break;
        }
        default: {
            cout << "Opción incorrecta.\n" << endl;
            mostrarRanking(songs);
            break;
        }
    }
}
