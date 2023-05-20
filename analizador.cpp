#include "analizador.hpp"


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
        encontrado = std::find(begin(generos), end(generos),genero) != end(generos);
        if(!encontrado){
                cout << "Género no encontrado. "<<
                "Introduce el nombre de un género musical para que te podamos recomendar canciones que te puedan gustar: \n";
                cin >> genero;
        }

    }while(!encontrado);

    auto it = std::find(generos.begin(), generos.end(), genero);
    int pos = distance(generos.begin(), it);

    while (it != generos.end()) {
        int pos = distance(generos.begin(), it);
        posiciones.push_back(pos);
        it = std::find(++it, generos.end(), genero);
    }
    
    for (int i = 0; i < 5; i++){
        int j = rand ()% sizeof(posiciones);
        cancionesRec.push_back(songs[posiciones[j]].nombreCancion);
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
        encontrado = std::find(begin(generos), end(generos),genero) != end(generos);
        if(!encontrado){
                cout << "Género no encontrado. "<<
                "Introduce el nombre de un género musical para que te podamos recomendar artistas que te puedan gustar: \n";
                cin >> genero;
        }

    }while(!encontrado);

    auto it = std::find(generos.begin(), generos.end(), genero);
    int pos = distance(generos.begin(), it);


    while (it != generos.end()) {
        int pos = distance(generos.begin(), it);
        posiciones.push_back(pos);
        it = std::find(++it, generos.end(), genero);
    }
    
    for (int i = 0; i < 5; i++){
        int j = rand ()% sizeof(posiciones);
        artistasRec.push_back(songs[posiciones[j]].nombreArtista);
    }
    
    return artistasRec;

    



}

void mostrarRanking(vector <Song> songs){ //@author Juan Carlos Estefanía y Carlos Arroyo
//Variables comunes a todos los casos
int opcion; 
bool encontrado = false;
vector <Song> canciones;
//Variables para el caso 1
string cantante;    
vector <string> cantantes; 
vector <int> posiciones;

//Variables para el caso 2
string genero; 
vector <string> generos;

//Variables para el caso 3
vector <pair <string,int> > cantantes2;
//vector <string> cantantes;



cout << "Elige el tipo de Ranking: " << endl;
cout << "    1. Ranking de canciones por cantante\n";
cout << "    2. Ranking de canciones por género\n";
cout << "    3. Ranking de cantantes por género\n";
cin >> opcion;


switch (opcion){
    case 1: {   // Ranking de canciones por cantante

        for (Song s : songs){
            cantantes.push_back(s.nombreArtista);
        }
        cout << "Introduce el nombre del cantante para ver su Ranking de canciones más escuchadas: " << endl;
        cin >> cantante;
        do{
            encontrado = std::find(begin(cantantes), end(cantantes),cantante) != end(cantantes);
            if(!encontrado){
                    cout << "Cantante no encontrado. "<<
                    "Introduce el nombre del cantante para ver su Ranking de canciones más escuchadas: \n";
                    cin >> cantante;
            }

        }while(!encontrado);
        
        auto it = std::find(cantantes.begin(), cantantes.end(), cantante);

        while (it != cantantes.end()) {
            int pos = distance(cantantes.begin(), it);
            posiciones.push_back(pos);
            it = std::find(++it, cantantes.end(), cantante);
        }
        cout << "-----------------------------------------------\n";
        cout << "Ranking de canciones de "<< cantante << endl;
        cout << "-----------------------------------------------\n";
        for (int i = 0; i < sizeof(posiciones); i++){
            canciones.push_back(songs[posiciones[i]]);
            cout << canciones[i].posicion << ". " << canciones[i].nombreCancion << endl;
        }
        
        cantantes.clear();
        canciones.clear();
        
        break;
    }
    case 2: {    // Ranking de canciones por género

        for (Song s : songs){
            generos.push_back(s.genero);
        }
        cout << "Introduce un género para ver el Ranking de canciones más escuchadas (RAP, POP, INDIE, SOUL o COUNTRY): " << endl;
        cin >> genero;
        do{
            encontrado = std::find(begin(generos), end(generos),genero) != end(generos);
            if(!encontrado){
                    cout << "Género no encontrado. "<<
                    "Introduce el nombre del género para ver su Ranking de canciones más escuchadas (RAP, POP, INDIE, SOUL o COUNTRY): \n";
                    cin >> genero;
            }

        }while(!encontrado);

        auto it = std::find(generos.begin(), generos.end(), genero);

        while (it != generos.end()) {
            int pos = distance(generos.begin(), it);
            posiciones.push_back(pos);
            it = std::find(++it, generos.end(), genero);
        }
        cout << "-----------------------------------------------\n";
        cout << "Ranking de canciones del género "<< genero << endl;
        cout << "-----------------------------------------------\n";
        for (int i = 0; i < posiciones.size(); i++){
            canciones.push_back(songs[posiciones[i]]);
            cout << canciones[i].posicion << ". " << canciones[i].nombreCancion << endl;
        }

        generos.clear();
        canciones.clear();

        break;
    }
    

    case 3: { //Ranking de artistas por género

        for (Song s : songs){
            generos.push_back(s.genero);
        }
        cout << "Introduce un género para ver el Ranking de artistas más escuchados (RAP, POP, INDIE, SOUL o COUNTRY): " << endl;
        cin >> genero;
        do{
            encontrado = std::find(begin(generos), end(generos),genero) != end(generos);
            if(!encontrado){
                    cout << "Género no encontrado. "<<
                    "Introduce el nombre del género para ver su Ranking de artistas más escuchadas (RAP, POP, INDIE, SOUL o COUNTRY): \n";
                    cin >> genero;
            }

        }while(!encontrado);

        auto it = std::find(generos.begin(), generos.end(), genero);

        while (it != generos.end()) {
            int pos = distance(generos.begin(), it);
            posiciones.push_back(pos);
            it = std::find(++it, generos.end(), genero);
        }
        
        for (int i = 0; i < sizeof(posiciones); i++){
            canciones.push_back(songs[posiciones[i]]);
        }

        
    
        
        for (Song s : canciones){
            for (auto cantante : cantantes2){
                if(cantante.first == s.nombreArtista){
                    cantante.second += s.streamTotales;
                    break;
                }
            }
            cantantes2.push_back(make_pair(s.nombreArtista,s.streamTotales));   
        }
        
        sort(cantantes2.begin(), cantantes2.end(), [](const pair<string,int>& a, const pair<string,int>& b){return a.second > b.second;});

        for (int i = 0; i < sizeof(cantantes2); i++){
            cout << i + 1  << ". " << cantantes2[i].first<< " Con un total de " << cantantes2[i].second << "streams totales" << endl;
        }

        cantantes2.clear();
        canciones.clear();
        generos.clear();

        break;
    }
        default:{
        cout <<"Opción incorrecta.\n" << endl;
        mostrarRanking(songs);
        break;
        }

    }
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
        cin >> cantante;
        do{
            encontrado = std::find(begin(cantantes), end(cantantes),cantante) != end(cantantes);
            if(!encontrado){
                    cout << "Cantante no encontrado. "<<
                    "Introduce el nombre del cantante para ver su Ranking de canciones más escuchadas: \n";
                    cin >> cantante;
            }

        }while(!encontrado);
        
        auto it = std::find(cantantes.begin(), cantantes.end(), cantante);

        while (it != cantantes.end()) {
            int pos = distance(cantantes.begin(), it);
            posiciones.push_back(pos);
            it = std::find(++it, cantantes.end(), cantante);
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
        cin >> genero;
        do{
            encontrado = std::find(begin(generos), end(generos),genero) != end(generos);
            if(!encontrado){
                    cout << "Género no encontrado. "<<
                    "Introduce el nombre del género para ver su Ranking de canciones más escuchadas (RAP, POP, INDIE, SOUL o COUNTRY): \n";
                    cin >> genero;
            }

        }while(!encontrado);

        auto it = std::find(generos.begin(), generos.end(), genero);

        while (it != generos.end()) {
            int pos = distance(generos.begin(), it);
            posiciones.push_back(pos);
            it = std::find(++it, generos.end(), genero);
        }
        Rankings r;
        r.cancioness = canciones;
        r.posiciones = posiciones; 
        r.str = genero;
        return r;

}
vector <pair <string,int> > Analizador::Rankings3(vector <Song> songs)
{
    int opcion; 
    bool encontrado = false;
    vector <Song> canciones;
    vector <pair <string,int> > cantantes2;
    vector <int> posiciones;
    vector <string> generos;
    string genero;

      for (Song s : songs){
            generos.push_back(s.genero);
        }
        cout << "Introduce un género para ver el Ranking de artistas más escuchados (RAP, POP, INDIE, SOUL o COUNTRY): " << endl;
        cin >> genero;
        do{
            encontrado = std::find(begin(generos), end(generos),genero) != end(generos);
            if(!encontrado){
                    cout << "Género no encontrado. "<<
                    "Introduce el nombre del género para ver su Ranking de artistas más escuchadas (RAP, POP, INDIE, SOUL o COUNTRY): \n";
                    cin >> genero;
            }

        }while(!encontrado);

        auto it = std::find(generos.begin(), generos.end(), genero);

        while (it != generos.end()) {
            int pos = distance(generos.begin(), it);
            posiciones.push_back(pos);
            it = std::find(++it, generos.end(), genero);
        }
        
        for (int i = 0; i < sizeof(posiciones); i++){
            canciones.push_back(songs[posiciones[i]]);
        }

        
    
        
        for (Song s : canciones){
            for (auto cantante : cantantes2){
                if(cantante.first == s.nombreArtista){
                    cantante.second += s.streamTotales;
                    break;
                }
            }
            cantantes2.push_back(make_pair(s.nombreArtista,s.streamTotales));   
        }
        
        sort(cantantes2.begin(), cantantes2.end(), [](const pair<string,int>& a, const pair<string,int>& b){return a.second > b.second;});
        return cantantes2;

}


