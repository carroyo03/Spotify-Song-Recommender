#include <iostream>
#include "recomendador.hpp"


using namespace std;


void mostrarRecomendacion(vector <Song> songs){//@author Carlos Arroyo
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

void mostrarCantantes(vector <Song> songs){ //@author Gabriel Nassri and Carlos Arroyo

 
    vector <string> cantantes;int i = 0;
    for (int i=0; i<10;i++){
        for (string str : cantantes){
            if(str == songs[i].nombreArtista){
                break;
            }
        }
        cantantes.push_back(songs[i].nombreArtista);
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

