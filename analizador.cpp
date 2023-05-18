#include "analizador.hpp"







database::database(vector <Song> songss){
    songs = songss;
}




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
            
            for (int i = 0; i < 5; i++){
                int j = rand ()% sizeof(posiciones);
                artistasRec.push_back(songs[posiciones[j]].nombreArtista);
            }
            
           return artistasRec;
        
            
        


        }
        void Analizador::Rankings1(){}
        void Analizador::Rankings2(){}
        void Analizador::Rankings3(){}


