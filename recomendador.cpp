#include <iostream>
#include <utility>
#include <algorithm>
#include "recomendador.hpp"
#include "main.hpp"
#include "analizador.hpp"




class Analizador : public baseRA{

public:

void mostrarRecomendacion(vector <Song> songs){
    vector <string> generos;int i = 0;
    for (Song s : songs){
        for (string str : generos){
            if(str == s.genero){
                break;
            }
        }
        generos.push_back(s.genero);
    }
    cout << "Elige tu género favorito"<< endl;
    for (string genero : generos){
        i++;
        cout<<i<<". "<<genero<<endl;
    }

}

void mostrarCantantes(vector <Song> songs){
    vector <string> cantantes;int i = 0;
    for (Song s : songs){
        for (string str : cantantes){
            if(str == s.nombreArtista){
                break;
            }
        }
        cantantes.push_back(s.nombreArtista);
    }
    cout << "Elige tu cantante favorito"<< endl;
    for (string cantante : cantantes){
        i++;
        cout<<i<<". "<<cantante<<endl;
    }
}

void mostrarCancion(vector <Song> songs){ //@author Gabriel Nassri

    vector <string> canciones;int i = 0;
    for (int i=0; i<10;i++){
        for (string str : canciones){
            if(str == songs[i].nombreCancion){
                break;
            }
        }
        canciones.push_back(songs[i].nombreCancion);
    }
    cout << "Elige tu cancion favorita"<< endl;
    for (string cancion : canciones){
        i++;
        cout<<i<<". "<<cancion <<endl;
    }
}



void analizarCancion(vector <Song> songs){
    string cancion;
    vector <string> canciones;
    vector <int> posiciones;
    bool encontrado = false;

    for (Song s : songs){
                canciones.push_back(s.nombreArtista);
    }


    cout << "Introduce el nombre de la canción la cual quieres analizar: " << endl;
    cin >> cancion;
    do{
        encontrado = find(begin(canciones), end(canciones), cancion) != end(canciones);
        if(!encontrado){
                cout << "Canción no encontrada. "<<
                "Introduce una canción adecuada: \n";
                cin >> cancion;
        }

    }while(!encontrado);

    auto it = find(canciones.begin(), canciones.end(), canciones);
    int pos = distance(canciones.begin(), it);

    cout << "--------------------------------------\n";
    cout << "Datos sobre la canción "<<songs[pos].nombreCancion << endl;
    cout << "--------------------------------------\n";
    cout << "Artista: " << songs[pos].nombreArtista << endl;
    cout << "Género: "<< songs[pos].genero << endl;
    cout << "Streams Totales: " << songs[pos].streamTotales << endl;
}

};

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
    vector <pair<string,int>> cantantes2;
    //vector <string> cantantes;

    
   
   cout << "Elige el tipo de Ranking: " << endl;
   cout << "    1. Ranking de canciones por cantante\n";
   cout << "    2. Ranking de canciones por género\n";
   cout << "    3. Ranking de cantantes por género\n";
   cin >> opcion;


   switch (opcion){
        case 1: // Ranking de canciones por cantante

            for (Song s : songs){
                cantantes.push_back(s.nombreArtista);
            }
            cout << "Introduce el nombre del cantante para ver su Ranking de canciones más escuchadas: " << endl;
            cin >> cantante;
            do{
                encontrado = find(begin(cantantes), end(cantantes),cantante) != end(cantantes);
                if(!encontrado){
                        cout << "Cantante no encontrado. "<<
                        "Introduce el nombre del cantante para ver su Ranking de canciones más escuchadas: \n";
                        cin >> cantante;
                }

            }while(!encontrado);
            
            auto it = find(cantantes.begin(), cantantes.end(), cantante);

            while (it != cantantes.end()) {
                int pos = distance(cantantes.begin(), it);
                posiciones.push_back(pos);
                it = find(++it, cantantes.end(), cantante);
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

        case 2: // Ranking de canciones por género

            for (Song s : songs){
                generos.push_back(s.genero);
            }
            cout << "Introduce un género para ver el Ranking de canciones más escuchadas: " << endl;
            cin >> genero;
            do{
                encontrado = find(begin(generos), end(generos),genero) != end(generos);
                if(!encontrado){
                        cout << "Género no encontrado. "<<
                        "Introduce el nombre del género para ver su Ranking de canciones más escuchadas: \n";
                        cin >> genero;
                }

            }while(!encontrado);

            auto it = find(generos.begin(), generos.end(), genero);

            while (it != generos.end()) {
                int pos = distance(generos.begin(), it);
                posiciones.push_back(pos);
                it = find(++it, generos.end(), genero);
            }
            cout << "-----------------------------------------------\n";
            cout << "Ranking de canciones del género "<< genero << endl;
            cout << "-----------------------------------------------\n";
            for (int i = 0; i < sizeof(posiciones); i++){
                canciones.push_back(songs[posiciones[i]]);
                cout << canciones[i].posicion << ". " << canciones[i].nombreCancion << endl;
            }

            generos.clear();
            canciones.clear();

            break;
        default:
            cout <<"Opción incorrecta.\n" << endl;
            mostrarRanking(songs);
            break;

        case 3: //Ranking de artistas por género
    
            for (Song s : songs){
                generos.push_back(s.genero);
            }
            cout << "Introduce un género para ver el Ranking de artistas más escuchados: " << endl;
            cin >> genero;
            do{
                encontrado = find(begin(generos), end(generos),genero) != end(generos);
                if(!encontrado){
                        cout << "Género no encontrado. "<<
                        "Introduce el nombre del género para ver su Ranking de artistas más escuchadas: \n";
                        cin >> genero;
                }

            }while(!encontrado);

            auto it = find(generos.begin(), generos.end(), genero);

            while (it != generos.end()) {
                int pos = distance(generos.begin(), it);
                posiciones.push_back(pos);
                it = find(++it, generos.end(), genero);
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
            
            sort(cantantes2.begin(), cantantes2.end(), [](const auto& a, const auto& b){return a.second > b.second;});

            for (int i = 0; i < sizeof(cantantes2); i++){
                cout << i + 1  << ". " << cantantes2[i].first<< " Con un total de " << cantantes2[i].second << "streams totales" << endl;
            }

            cantantes2.clear();
            canciones.clear();
            generos.clear();

            break;

   }
}




/*
    #include <iostream>
#include <algorithm> // Para std::size

int main() {
    std::string cantante;
    std::string cantantes[] = {"Cantante1", "Cantante2", "Cantante3"};

    bool encontrado = false;

    do {
        std::cout << "Introduce el nombre del cantante para ver su Ranking de canciones más escuchadas: ";
        std::cin >> cantante;

        encontrado = std::find(std::begin(cantantes), std::end(cantantes), cantante) != std::end(cantantes);

        if (!encontrado) {
            std::cout << "Cantante no encontrado. Introduce el nombre del cantante nuevamente.\n";
        }
    } while (!encontrado);

    // Resto del código...

    return 0;
}
*/