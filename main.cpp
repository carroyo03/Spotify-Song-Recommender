#include <iostream>

using namespace std;

int menu(){
  int opcion;
  
  do {
    cout << "========== Menú ==========" << endl;
    cout << "1. Salir" << endl;
    cout << "2. Recomendador de canciones" << endl;
    cout << "3. Recomendador de artistas" << endl;
    cout << "4. Análisis de canción" << endl;
    cout << "5. Ranking de cantantes" << endl;
    cout << "Ingrese su opción (1-5): ";
    cin >> opcion;
    
    switch(opcion) {
      case 1:
        cout << "Saliendo del programa..." << endl;
        break;
      case 2:
        cout << "Recomendador de canciones..." << endl;
        // Aquí iría el código para la opción 2
        break;
      case 3:
        cout << "Recomendador de artistas..." << endl;
        // Aquí iría el código para la opción 3
        break;
      case 4:
        cout << "Análisis de canción" << endl;
        // Aquí iría el código para la opción 4
        break;
      case 5:
        cout << "Rankings" << endl;
        // Aquí iría el código para la opción 5
        break;
      default:
        cout << "Opción inválida. Inténtelo de nuevo." << endl;
        break;
    }
    
  } while(opcion != 1);
  
  return 0;
}


int main(){
    int opcion = menu();
}