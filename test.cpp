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