#include "analizador.hpp"
#include <set>
#include <map>


Analizador::Analizador(vector <Song> songss){
    songs = songss;
}

Analizador::~Analizador(){}



vector <string> Analizador::analizarCancionesRec(vector <Song> songs){
    string genero; 
    vector <string> generos; //= {"POP","RAP", "INDIE", "SOUL", "COUNTRY" }; //vector <string> generos = {"POP","RAP", "INDIE", "SOUL", "COUNTRY" };
    bool encontrado = false;
    vector <int> posiciones;
    vector <string> cancionesRec;

    for (Song s : songs){
        generos.push_back(s.genero);
    }
    cout << "Para poder recomendarte canciones, necesitamos que introduzcas un género musical que te guste (RAP, POP, INDIE, SOUL o COUNTRY): " << endl;
    cin >> genero;
    do{
        encontrado = find(begin(generos), end(generos),genero) != end(generos);
        if(!encontrado){
                cout << "Género no encontrado. "<<
                "Introduce el nombre de un género musical para que te podamos recomendar canciones que te puedan gustar: \n";
                cin >> genero;
        }

    }while(!encontrado);

    auto it = find(generos.begin(), generos.end(), genero);
    int pos = distance(generos.begin(), it);

    while (it != generos.end()) {
        int pos = distance(generos.begin(), it);
        posiciones.push_back(pos);
        it = find(++it, generos.end(), genero);
    }

    for (int i = 0; i < 5; i++) {
        int j = rand() % posiciones.size();
        string cancionActual = songs[posiciones[j]].nombreCancion;
        
        // Verificar si la canción actual ya está en cancionesRec
        bool cancionRepetida = false;
        for (string s : cancionesRec) {
            if (s == cancionActual) {
                cancionRepetida = true;
                break;
            }
        }
        
        // Verificar si ya se seleccionaron todas las canciones disponibles para el género
        if (cancionRepetida && cancionesRec.size() >= posiciones.size()) {
            break;
        }
        
        // Si la canción está repetida, seleccionar otra posición
        if (cancionRepetida) {
            i--;
            continue;
        }
        
        cancionesRec.push_back(cancionActual);
    }

    
    return cancionesRec;

}
        
vector <string> Analizador::analizarArtistasRec(vector <Song> songs){
    vector <string> generos; 
    string genero; 
    bool encontrado = false;
    
    vector <int> posiciones;
    vector <string> artistasRec; //vector <string> generos = {"POP","RAP", "INDIE", "SOUL", "COUNTRY" };
    for (Song s : songs){
        generos.push_back(s.genero);
    }
    cout << "Para poder recomendarte artistas, necesitamos que introduzcas un género musical que te guste (RAP, POP, INDIE, SOUL o COUNTRY): " << endl;
    cin >> genero;

    do{
        encontrado = find(begin(generos), end(generos),genero) != end(generos);
        if(!encontrado){
                cout << "Género no encontrado. "<<
                "Introduce el nombre de un género musical para que te podamos recomendar artistas que te puedan gustar: \n";
                cin >> genero;
        }

    }while(!encontrado);

    auto it = find(generos.begin(), generos.end(), genero);
    int pos = distance(generos.begin(), it);


    while (it != generos.end()) {
        int pos = distance(generos.begin(), it);
        posiciones.push_back(pos);
        it = find(++it, generos.end(), genero);
    }
    

    for (int i = 0; i < 5; i++) {
        int j = rand() % posiciones.size();
        string artistaActual = songs[posiciones[j]].nombreArtista;
        
        // Verificar si la canción actual ya está en cancionesRec
        bool artistaRepetido = false;
        for (string s : artistasRec) {
            if (s == artistaActual) {
                artistaRepetido = true;
                break;
            }
        }
        
        // Verificar si ya se seleccionaron todas las canciones disponibles para el género
        if (artistaRepetido && artistasRec.size() >= posiciones.size()) {
            break;
        }
        
        // Si la canción está repetida, seleccionar otra posición
        if (artistaRepetido) {
            i--;
            continue;
        }
        
        artistasRec.push_back(artistaActual);
    }
    
    return artistasRec;

    



}



Rankings Analizador::Rankings1(vector <Song> songs){
    int opcion; 
    bool encontrado = false;
    vector <Song> canciones;
    string cantante;    
    vector <string> cantantes; 
    vector <int> posiciones;
    for (Song s : songs){
            cantantes.push_back(s.nombreArtista);
        }
        cout << "Introduce el nombre del cantante para ver su Ranking de canciones más escuchadas: " << endl;
        cin.ignore();
        getline(cin,cantante);
        do{
            encontrado = find(begin(cantantes), end(cantantes),cantante) != end(cantantes);
            if(!encontrado){
                    cout << "Cantante no encontrado. "<<
                    "Introduce el nombre del cantante para ver su Ranking de canciones más escuchadas: \n";
                    cin.ignore();
                    getline(cin,cantante);
            }

        }while(!encontrado);
        
        auto it = find(cantantes.begin(), cantantes.end(), cantante);

        while (it != cantantes.end()) {
            int pos = distance(cantantes.begin(), it);
            posiciones.push_back(pos);
            it = find(++it, cantantes.end(), cantante);
        }

        Rankings r;
        r.cancioness = canciones;
        r.posiciones = posiciones; 
        r.str = cantante;
        cantantes.clear();
        return r;

}
Rankings Analizador::Rankings2(vector <Song> songs){
    int opcion; 
    bool encontrado = false;
    vector <Song> canciones;
    string genero; 
    vector <string> generos;
    vector <int> posiciones;
    for (Song s : songs){
            generos.push_back(s.genero);
        }
        cout << "Introduce un género para ver el Ranking de canciones más escuchadas (RAP, POP, INDIE, SOUL o COUNTRY): " << endl;
        cin.ignore();
        getline(cin,genero);
        do{
            encontrado = find(begin(generos), end(generos),genero) != end(generos);
            if(!encontrado){
                    cout << "Género no encontrado. "<<
                    "Introduce el nombre del género para ver su Ranking de canciones más escuchadas (RAP, POP, INDIE, SOUL o COUNTRY): \n";
                    cin.ignore();
                    getline(cin,genero);
            }

        }while(!encontrado);

        auto it = find(generos.begin(), generos.end(), genero);

        while (it != generos.end()) {
            int pos = distance(generos.begin(), it);
            posiciones.push_back(pos);
            it = find(++it, generos.end(), genero);
        }

        Rankings r;
        r.cancioness = canciones;
        r.posiciones = posiciones; 
        r.str = genero;
        return r;

}

vector<pair<string, int> > Analizador::Rankings3(vector<Song> songs) {
    int opcion;
    bool encontrado = false;
    vector<string> generos;
    string genero;

    for (Song s : songs) {
        generos.push_back(s.genero);
    }

    cout << "Introduce un género para ver el Ranking de artistas más escuchados (RAP, POP, INDIE, SOUL o COUNTRY): " << endl;
    cin.ignore();
    getline(cin, genero);

    do {
        encontrado = find(begin(generos), end(generos), genero) != end(generos);
        if (!encontrado) {
            cout << "Género no encontrado. Introduce el nombre del género para ver su Ranking de artistas más escuchadas (RAP, POP, INDIE, SOUL o COUNTRY): \n";
            cin.ignore();
            getline(cin, genero);
        }
    } while (!encontrado);

    vector<int> posiciones;
    auto it = find(generos.begin(), generos.end(), genero);

    while (it != generos.end()) {
        int pos = distance(generos.begin(), it);
        posiciones.push_back(pos);
        it = find(++it, generos.end(), genero);
    }

    set<string> artistas;
    map<string, int> cantantesSumaStreams;

    for (int i = 0; i < posiciones.size(); i++) {
        Song s = songs[posiciones[i]];
        artistas.insert(s.nombreArtista);
        cantantesSumaStreams[s.nombreArtista] += s.streamTotales;
    }

    vector<pair<string, int> > cantantes2;

    for (const auto& artista : artistas) {
        cantantes2.push_back(make_pair(artista, cantantesSumaStreams[artista]));
    }

    sort(cantantes2.begin(), cantantes2.end(), [](const pair<string, int>& a, const pair<string, int>& b) { return a.second > b.second; });

    return cantantes2;
}



