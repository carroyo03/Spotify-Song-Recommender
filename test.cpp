//Simulacro de examen Programación I - Dic 2021
//Solución de María Espinosa

#include <iostream>
#include <fstream> //librería necesaria para la lectura/escritura en archivos

using namespace std;

typedef struct{
    string ID;
    int nFaltas;
    double nExamen;
    double nClase;
    double nPracticas;
    double nFinal;
}Alumno; //declaramos el tipo Alumno con los campos iniciados en el enunciado

const int T = 100;
typedef struct{
    Alumno alumnos[T];
    int contador;
}Clase;//declaramos el tipo Clase, que contiene una lista de tipo Alumno (!) de tamaño máximo 100 y un contador

//Esta función muestra el menú por consola y pide al usuario que introduzca una opción, cuando la opción es válida, la devuelve
int menu();

//Dados una lista de alumnos (Clase c) y un nombre (String ID), busca al alumno con el nombre y devuelve un entero con la posición del alumno en la lista o -1 si no existe el alumno.
int buscaAlumno(Clase c, string ID);

//Devuelve true si el alumno se puede presentar a examen y false en caso contrario
bool puedePresentar(Alumno a);

//Muestra por pantalla los datos del alumno a
void informeIndividual(Alumno a);

//Carga los datos de los alumnos contenidos en el archivo alumnos.txt en la lista Clase c (parámetro por referencia) (!)
void cargaDatos(Clase &c);

//Muestra un informe general de aprobados a partir de los alumnos en la lista c
void informeGeneral(Clase c);

//Crea el archivo "informe.txt" y guarda los datos de los alumnos que pueden o no presentarse a examen
void generaInforme(Clase c);

int main (){
    Clase c; //instanciamos el tipo Clase (!) Esta será la única vez que lo hagamos en todo el código.
    c.contador=0; //inicializamos el contador.
    cargaDatos(c); //cargamos los datos del archivo en c
    
    int opcion = menu(); //guardamos en opción lo que nos devuelve menu()
    switch (opcion) { //miramos qué hay en opción para hacer una de las siguientes acciones:
        case 1:{ //1) Pedimos al usuario que introduzca el nombre del alumno y lo guardamos
            string nombre; //(!)tipo string
            int i;
            do{ //bucle para asegurarnos de que el nombre del alumno es correcto
                cout << "Introduce el nombre del alumno: ";
                cin >> nombre;
                i = buscaAlumno(c, nombre); //buscamos al alumno
                if(i != -1){
                    informeIndividual(c.alumnos[i]);
                }else{
                    cout << "El alumno no se encuentra en la lista" << endl;
                }
            }while(i == -1); //bucle mientras que el alumno no se encuentre
                break;
            }
        case 2: //2) informe general de la Clase 'c'
            informeGeneral(c);
            break;
        case 3: //3) informe "Puede presentarse"
            generaInforme(c);
            break;
        case 0: //salida
            cout << "Hasta Luego" << endl;
            break;
        }
            return 0;
    }
    
    int menu(){
        int opcion;
        do{
            cout << "0. Salir" << endl;
            cout << "1.Informe individual alumno" << endl;
            cout << "2.Informe general de la clase" << endl;
            cout << "3.Generar informe -Puede presentarse-" << endl;
            cout << "Elige:";
            cin >> opcion;
            if(opcion < 0 || opcion > 3){
                cout << "Opción inválida" << endl;
            }
        }while(opcion < 0 || opcion > 3);
        return opcion;
    }
    
    int buscaAlumno(Clase c, string ID){
        int indice = -1;
        for(int i =0; i < c.contador; i++){
            if (c.alumnos[i].ID == ID){
                indice = i; //guardamos la posición del alumno
                i = c.contador; //forzamos la salida del bucle
            }
        }
        return indice;
    }
    
    bool puedePresentar(Alumno a){
        return a.nFaltas < 10;
    }
    
    void informeIndividual(Alumno a){
        cout << "-------------------------------" << endl;
        cout << "INFORME INDIVIDUAL: " << a.ID<< endl ;
        cout << "-------------------------------" << endl;
        cout << "Nota Prácticas: " << a.nPracticas<< endl;
        cout << "Nota Clase: " << a.nClase << endl;
        cout << "Nota Examen: "<< a.nExamen<< endl ;
        cout << "Número de faltas: " << a.nFaltas << endl;
        cout << "NOTA FINAL: " << a.nFinal << endl;
    }
    
    void informeGeneral(Clase c){
        int aPracticas = 0, aExamen = 0;
        int nPPresentar = 0, aTotal = 0;
        for(int i =0; i < c.contador; i++){
            //usaremos este bucle para contabilizar cuantos alumnos han aprobado las diferentes actividades
            Alumno a = c.alumnos[i];
            if(a.nPracticas >= 5){
                aPracticas++;
            }
            if(a.nFinal >= 5){
                aTotal++;
            }
            if(a.nExamen >= 5){
                aExamen++;
            }
            if(!puedePresentar(a)){
                nPPresentar++;
            }
        }
        
        cout << "--------------------------------" << endl;
        cout << "INFORME GENERAL PROGRAMACIÓN I" << endl;
        cout << "--------------------------------" << endl;
        cout <<"La clase tiene "<< c.contador << " alumnos." << endl;
        cout << aPracticas <<" alumnos han aprobado las prácticas." << endl;
        cout << aExamen <<" alumnos han aprobado el examen." << endl;
        cout << nPPresentar <<" alumnos no se han podido presentar a examen." << endl;
        cout << aTotal <<" alumnos han aprobado la asignatura." << endl;
    }
    
    void cargaDatos(Clase &c){
        ifstream archivo; //(1)
        archivo.open("/Users/Maria/Desktop/Ex1/Ex1/alumnos.txt");//(2)
        if(archivo.is_open()){ //(3.a)
            archivo >> c.contador; //(3.b - lecturas)
            for(int i = 0; i < c.contador; i++){
                archivo >> c.alumnos[i].ID;
                archivo >> c.alumnos[i].nPracticas;
                archivo >> c.alumnos[i].nClase;
                archivo >> c.alumnos[i].nExamen;
                archivo >> c.alumnos[i].nFaltas;
                c.alumnos[i].nFinal = c.alumnos[i].nExamen*0.6 + c.alumnos[i].nPracticas*0.3 + c.alumnos[i].nClase*0.1;
            }
            archivo.close(); //(4) Solo cerramos el archivo en caso de haberlo abierto correctamente (dentro del if)
            //mostramos este mensaje para confirmar la carga de datos
            cout << "Se han cargado los datos de " << c.contador << " alumnos."<<  endl;
        }else{
            cout << "No se ha podido abrir el archivo" << endl;
        }
    }
    
    void generaInforme(Clase c){
        ofstream archivo; //(1)
        archivo.open("/Users/Maria/Desktop/Ex1/Ex1/informe.txt"); //(2)
        for (int i = 0; i < c.contador; i++){
            archivo << c.alumnos[i].ID << " "; //(3)
            if(puedePresentar(c.alumnos[i])){
                archivo << "Si";
            }
            else{
                archivo << "No" << endl;
            }
        }
        archivo.close(); //(4)
    }





/*
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// Estructura de datos para almacenar información de las canciones
struct Cancion {
    string titulo;
    string artista;
    string genero;
    int escuchas;
};

// Función para cargar datos del archivo de texto en un vector
vector<Cancion> cargarDatos(string archivo) {
    vector<Cancion> canciones;
    ifstream ifs(archivo);
    if (!ifs.is_open()) {
        cerr << "No se puede abrir el archivo " << archivo << endl;
        exit(EXIT_FAILURE);
    }
    string linea;
    while (getline(ifs, linea)) {
        Cancion cancion;
        cancion.titulo = linea.substr(0, linea.find(","));
        linea = linea.substr(linea.find(",") + 1);
        cancion.artista = linea.substr(0, linea.find(","));
        linea = linea.substr(linea.find(",") + 1);
        cancion.genero = linea.substr(0, linea.find(","));
        linea = linea.substr(linea.find(",") + 1);
        cancion.escuchas = stoi(linea);
        canciones.push_back(cancion);
    }
    ifs.close();
    return canciones;
}

// Función para imprimir una lista de canciones
void imprimirCanciones(vector<Cancion>& canciones) {
    for (int i = 0; i < canciones.size(); i++) {
        cout << i+1 << ". " << canciones[i].titulo << " - " << canciones[i].artista << endl;
    }
}

// Función para imprimir una lista de artistas
void imprimirArtistas(map<string, int>& artistas) {
    int i = 1;
    for (auto it = artistas.begin(); it != artistas.end(); it++) {
        cout << i++ << ". " << it->first << " - " << it->second << " escuchas" << endl;
    }
}

// Función para imprimir los géneros más populares y su porcentaje de participación
void analizarGeneros(vector<Cancion>& canciones) {
    map<string, int> generos;
    int total = 0;
    for (int i = 0; i < canciones.size(); i++) {
        generos[canciones[i].genero]++;
        total += canciones[i].escuchas;
    }
    cout << "Generos mas populares:" << endl;
    for (auto it = generos.begin(); it != generos.end(); it++) {
        float porcentaje = (it->second * 100.0f) / total;
        cout << "- " << it->first << ": " << porcentaje << "%" << endl;
    }
}

int main() {
    // Cargar los datos del archivo de texto en un vector
    vector<Cancion> canciones = cargarDatos("canciones.txt");

    // Menú principal
    while (true) {
        cout << endl;
        cout << "MENU:" << endl;
        cout << "1. Salir" << endl;
        cout << "2. Recomendador de canciones" << endl;
        cout << "3. Recomendador de artistas" << endl;
        cout << "4. Analista de estilo musical" << endl;
        cout << "5. Ranking de cantantes" << endl;
        int opcion;
        cout << "Ingrese una opcion: ";
        cin >> opcion

    if (opcion == 1) {
        break;
    } else if (opcion == 2) {
        // Recomendador de canciones
        cout << "Ingrese el genero de musica que mas le gusta: ";
        string genero;
        cin.ignore();
        getline(cin, genero);
        vector<Cancion> recomendaciones;
        for (int i = 0; i < canciones.size(); i++) {
            if (canciones[i].genero == genero) {
                recomendaciones.push_back(canciones[i]);
            }
        }
        sort(recomendaciones.begin(), recomendaciones.end(),
            [](const Cancion& a, const Cancion& b) -> bool {
                return a.escuchas > b.escuchas;
            });
        cout << "Canciones recomendadas en el genero " << genero << ":" << endl;
        imprimirCanciones(recomendaciones);
    } else if (opcion == 3) {
        // Recomendador de artistas
        cout << "Ingrese el genero de musica que desea: ";
        string genero;
        cin.ignore();
        getline(cin, genero);
        map<string, int> artistas;
        for (int i = 0; i < canciones.size(); i++) {
            if (canciones[i].genero == genero) {
                artistas[canciones[i].artista] += canciones[i].escuchas;
            }
        }
        cout << "Artistas recomendados en el genero " << genero << ":" << endl;
        imprimirArtistas(artistas);
    } else if (opcion == 4) {
        // Analista de estilo musical
        analizarGeneros(canciones);
    } else if (opcion == 5) {
        // Ranking de cantantes
        map<string, int> cantantes;
        for (int i = 0; i < canciones.size(); i++) {
            cantantes[canciones[i].artista] += canciones[i].escuchas;
        }
        cout << "Ranking de cantantes:" << endl;
        imprimirArtistas(cantantes);
    } else {
        cout << "Opcion invalida" << endl;
    }
}

return 0;
*/







// MAIN

/*#include <iostream>
#include "cancion.h"
#include "recomendador.h"
#include "analista.h"
#include "ranking.h"

using namespace std;

int main() {
    // Carga los datos del archivo de texto
    vector<Cancion> canciones = cargarCanciones("canciones.txt");

    int opcion = 0;

    do {
        // Muestra el menú y lee la opción del usuario
        cout << "-------------------------" << endl;
        cout << "Recomendador de canciones" << endl;
        cout << "-------------------------" << endl;
        cout << "1. Salir" << endl;
        cout << "2. Recomendador de canciones" << endl;
        cout << "3. Recomendador de artistas" << endl;
        cout << "4. Analista de estilo musical" << endl;
        cout << "5. Ranking de cantantes" << endl;

        cout << "Ingrese su opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                // Salir del programa
                cout << "Saliendo..." << endl;
                break;
            case 2:
                // Recomendador de canciones
                recomendadorCanciones(canciones);
                break;
            case 3:
                // Recomendador de artistas
                recomendadorArtistas(canciones);
                break;
            case 4:
                // Analista de estilo musical
                analistaEstiloMusical(canciones);
                break;
            case 5:
                // Ranking de cantantes
                rankingCantantes(canciones);
                break;
            default:
                // Opción inválida
                cout << "Opcion invalida. Intente de nuevo." << endl;
        }
    } while (opcion != 1);

    return 0;
}
*/


// CANCION.H

/*#ifndef CANCION_H
#define CANCION_H

#include <string>
#include <vector>

using std::string;
using std::vector;

class Cancion {
public:
    Cancion(string t, string a, string g, int e) : titulo(t), artista(a), genero(g), escuchas(e) {}

    string getTitulo() const { return titulo; }
    string getArtista() const { return artista; }
    string getGenero() const { return genero; }
    int getEscuchas() const { return escuchas; }

private:
    string titulo;
    string artista;
    string genero;
    int escuchas;
};

vector<Cancion> cargarCanciones(string archivo);

#endif // CANCION_H
*/


// CANCION.CPP

/*#include <iostream>
#include <fstream>
#include <sstream>
#include "cancion.h"

vector<Cancion> cargarCanciones(string archivo) {
    vector<Cancion> canciones;

    std::ifstream input(archivo);

    if (!input) {
        std::cerr << "Error al abrir el archivo " << archivo << std::endl;
        return canciones;
    }

    string titulo, artista, genero, linea;
    int escuchas;

    while (getline(input, linea)) {
        std::istringstream iss(linea);

        if (iss >> titulo >> artista >> genero >> escuchas) {
            Cancion cancion(titulo, artista, genero,
* */


// TERCERA OPCIÓN

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Song {
    string name;
    string artist;
    string genre;
    int plays;
};

vector<Song> read_file(string filename) {
    vector<Song> songs;
    ifstream file(filename);
    if (!file) {
        cout << "Error: could not open file " << filename << endl;
        return songs;
    }
    string line;
    while (getline(file, line)) {
        Song song;
        int pos = line.find(",");
        song.name = line.substr(0, pos);
        line.erase(0, pos + 1);
        pos = line.find(",");
        song.artist = line.substr(0, pos);
        line.erase(0, pos + 1);
        pos = line.find(",");
        song.genre = line.substr(0, pos);
        line.erase(0, pos + 1);
        song.plays = stoi(line);
        songs.push_back(song);
    }
    file.close();
    return songs;
}

void print_songs(vector<Song> songs) {
    for (Song song : songs) {
        cout << song.name << " - " << song.artist << " (" << song.genre << ") - " << song.plays << " plays" << endl;
    }
}

vector<Song> filter_songs_by_genre(vector<Song> songs, string genre) {
    vector<Song> filtered_songs;
    for (Song song : songs) {
        if (song.genre == genre) {
            filtered_songs.push_back(song);
        }
    }
    return filtered_songs;
}

vector<string> get_artists_by_genre(vector<Song> songs, string genre) {
    vector<string> artists;
    for (Song song : songs) {
        if (song.genre == genre) {
            bool found = false;
            for (string artist : artists) {
                if (artist == song.artist) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                artists.push_back(song.artist);
            }
        }
    }
    vector<int> plays(artists.size(), 0);
    for (Song song : songs) {
        for (int i = 0; i < artists.size(); i++) {
            if (song.artist == artists[i] && song.genre == genre) {
                plays[i] += song.plays;
                break;
            }
        }
    }
    for (int i = 0; i < artists.size() - 1; i++) {
        for (int j = i + 1; j < artists.size(); j++) {
            if (plays[i] < plays[j]) {
                swap(plays[i], plays[j]);
                swap(artists[i], artists[j]);
            }
        }
    }
    return artists;
}

vector<Song> get_songs_by_genre(vector<Song> songs, string genre) {
    vector<Song> filtered_songs = filter_songs_by_genre(songs, genre);
    for (int i = 0; i < filtered_songs.size() - 1; i++) {
        for (int j = i + 1; j < filtered_songs.size(); j++) {
            if (filtered_songs[i].plays < filtered_songs[j].plays) {
                swap(filtered_songs[i], filtered_songs[j]);
            }
        }
    }
    return filtered_songs;
}

int main() {
    vector<Song> songs = read_file("songs.txt");
    if (songs.empty()) {
            return 0;
}
int option;
do {
    cout << "Menu:" << endl;
    cout << "1. Salir" << endl;
    cout << "2. Recomendador de canciones" << endl;
    cout << "3. Recomendador de artistas" << endl;
    cout << "4. Analista de estilo musical" << endl;
    cout << "5. Ranking de cantantes" << endl;
    cout << "Ingrese una opcion: ";
    cin >> option;
    switch (option) {
        case 1:
            break;
        case 2: {
            string genre;
            cout << "Ingrese el genero que desea: ";
            cin >> genre;
            vector<Song> filtered_songs = get_songs_by_genre(songs, genre);
            print_songs(filtered_songs);
            break;
        }
        case 3: {
            string genre;
            cout << "Ingrese el genero que desea: ";
            cin >> genre;
            vector<string> artists = get_artists_by_genre(songs, genre);
            for (string artist : artists) {
                cout << artist << endl;
            }
            break;
        }
        case 4: {
            vector<string> genres;
            for (Song song : songs) {
                bool found = false;
                for (string genre : genres) {
                    if (genre == song.genre) {
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    genres.push_back(song.genre);
                }
            }
            for (string genre : genres) {
                vector<Song> filtered_songs = filter_songs_by_genre(songs, genre);
                int total_plays = 0;
                for (Song song : filtered_songs) {
                    total_plays += song.plays;
                }
                double avg_plays = total_plays / static_cast<double>(filtered_songs.size());
                cout << genre << ": " << avg_plays << " plays por cancion" << endl;
            }
            break;
        }
        case 5: {
            vector<string> artists;
            for (Song song : songs) {
                bool found = false;
                for (string artist : artists) {
                    if (artist == song.artist) {
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    artists.push_back(song.artist);
                }
            }
            vector<int> plays(artists.size(), 0);
            for (Song song : songs) {
                for (int i = 0; i < artists.size(); i++) {
                    if (song.artist == artists[i]) {
                        plays[i] += song.plays;
                        break;
                    }
                }
            }
            for (int i = 0; i < artists.size() - 1; i++) {
                for (int j = i + 1; j < artists.size(); j++) {
                    if (plays[i] < plays[j]) {
                        swap(plays[i], plays[j]);
                        swap(artists[i], artists[j]);
                    }
                }
            }
            for (int i = 0; i < artists.size(); i++) {
                cout << i + 1 << ". " << artists[i] << " - " << plays[i] << " plays" << endl;
            }
            break;
        }
        default:
            cout << "Opcion invalida" << endl;
            break;
    }
} while (option != 1);
return 0;



