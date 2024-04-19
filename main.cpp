#include <iostream>
#include "funciones.h"
#include <conio.h>
using namespace std;

int main() {
    int opcion;
    do {
        menu(opcion);
        switch (opcion) {
            case 1:
                int turno;
                jugar();
                break;
            case 2:
                estadisticas();
                break;
            case 3:
                Cerditos();
                break;
            case 0:
                cout << "Saliendo del juego" << endl;
                break;
        }
    } while (opcion != 0);

    getch();
    return 0;
}
