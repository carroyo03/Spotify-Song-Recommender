#include <iostream>
#include "recomendador.hpp"
#include "datos.hpp"
void mostrarRecomendacion(std::vector <Song> songs){
    std::vector <std::string> generos;int i = 0;
    for (Song s : songs){
        for (std::string str : generos){
            if(str == s.genero){
                break;
            }
        }
        generos.push_back(s.genero);
    }
    std::cout << "Elige tu género favorito"<< std::endl;
    for (std::string genero : generos){
        i++;
        std::cout<<i<<". "<<genero<<std::endl;
    }

}

void mostrarCantantes(std::vector <Song> songs){
    std::vector <std::string> cantantes;int i = 0;
    for (Song s : songs){
        for (std::string str : cantantes){
            if(str == s.nombreArtista){
                break;
            }
        }
        cantantes.push_back(s.nombreArtista);
    }
    std::cout << "Elige tu cantante favorito"<< std::endl;
    for (std::string cantante : cantantes){
        i++;
        std::cout<<i<<". "<<cantante<<std::endl;
    }
}