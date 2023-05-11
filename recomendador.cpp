#include <iostream>
#include "recomendador.hpp"
#include "datos.hpp"

using namespace std;

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