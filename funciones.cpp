#include <iostream>
#include "funciones.h"
#include <ctime>
using namespace std;

void menu(int &opcion){
    cout<<"GRAN CERDO" <<endl;
    cout<<" --------------------"<<endl;
    cout<<"1 - JUGAR"<<endl;
    cout<<"2 - ESTADISTICAS"<<endl;
    cout<<"3 - CERDITOS"<<endl;
    cout<<"---------------------"<<endl;
    cout<<"0 - SALIR"<<endl;
    cout<<endl;
    cout<<"ingrese la opcion: ";
    cin>>opcion;
    system("pause");
}

void mostrarDado(int valor) {
    switch(valor) {
        case 1:
            cout << "+-------+" << endl;
            cout << "|       |" << endl;
            cout << "|   x   |" << endl;
            cout << "|       |" << endl;
            cout << "+-------+" << endl;
            break;
        case 2:
            cout << "+-------+" << endl;
            cout << "| x     |" << endl;
            cout << "|       |" << endl;
            cout << "|     x |" << endl;
            cout << "+-------+" << endl;
            break;
        case 3:
            cout << "+-------+" << endl;
            cout << "| x     |" << endl;
            cout << "|   x   |" << endl;
            cout << "|     x |" << endl;
            cout << "+-------+" << endl;
            break;
        case 4:
            cout << "+-------+" << endl;
            cout << "| x   x |" << endl;
            cout << "|       |" << endl;
            cout << "| x   x |" << endl;
            cout << "+-------+" << endl;
            break;
        case 5:
            cout << "+-------+" << endl;
            cout << "| x   x |" << endl;
            cout << "|   x   |" << endl;
            cout << "| x   x |" << endl;
            cout << "+-------+" << endl;
            break;
        case 6:
            cout << "+-------+" << endl;
            cout << "| x   x |" << endl;
            cout << "| x   x |" << endl;
            cout << "| x   x |" << endl;
            cout << "+-------+" << endl;
            break;
        default:
            cout << "Dado inválido." << endl;
            break;

    }
}

int LanzarDado(){
    return rand()%6+1;
}


int determinarQuienComienza(int &turno) {
    srand(time(0)); // Semilla basada en el tiempo actual

    int resultados[4];
    resultados[0]=LanzarDado();
    resultados[1]=LanzarDado();
    resultados[2]=LanzarDado();
    resultados[3]=LanzarDado();


    cout << "Jugador 1:" << endl;
    mostrarDado(resultados[0]);
    mostrarDado(resultados[1]);

    cout << "Jugador 2:" << endl;
    mostrarDado(resultados[2]);
    mostrarDado(resultados[3]);

    int sumaJugador1 = resultados[0]+resultados[1];
    int sumaJugador2 = resultados[2]+resultados[3];

    if (sumaJugador1 > sumaJugador2) {
        cout << "¡Jugador 1 comienza!" << endl;
        return 1; // Jugador 1 comienza
    } else if (sumaJugador1 < sumaJugador2) {
        cout << "¡Jugador 2 comienza!" << endl;
        return 2; // Jugador 2 comienza
    } else {
        // En caso de empate, se considera el dado más alto
        int maximoJugador1 = max(resultados[0], resultados[1]);
        int maximoJugador2 = max(resultados[2], resultados[3]);

        if (maximoJugador1 > maximoJugador2) {
            cout << "¡Jugador 1 comienza!" << endl;
            return 1; // Jugador 1 comienza
        } else if (maximoJugador1 < maximoJugador2) {
            cout << "¡Jugador 2 comienza!" << endl;
            return 2; // Jugador 2 comienza
        } else {
            cout << "Empate. Repitiendo" << endl;
            return determinarQuienComienza(turno); // Repetir el proceso si hay un empate en los dados más altos
        }
    }
}



void jugar(){
    string nombrejugador1, nombrejugador2;
    cout << "Ingrese el nombre del primer jugador: ";
    cin >> nombrejugador1;

    cout << "Ingrese el nombre del segundo jugador: ";
    cin >> nombrejugador2;
    cout << "Comenzando el juego con: " << nombrejugador1 << " y " << nombrejugador2 << endl;


    int trufasJ1 = 0, trufasJ2 = 0, ronda = 1;

    int turno = determinarQuienComienza(turno);

    while (ronda <= 5) {
        cout << "Ronda " << ronda << endl;
        cout << "Turno de " << (turno == 1 ? nombrejugador1 : nombrejugador2) << endl;

        // Lanzamiento de los dados
        int dado1, dado2, dado3;
        char continuar;

        if (ronda == 1) {
            dado1 = LanzarDado();
            dado2 = LanzarDado();
            cout << "Resultado del lanzamiento: " << dado1 << ", " << dado2 << endl;
        } else {
            dado1 = LanzarDado();
            dado2 = LanzarDado();
            dado3 = LanzarDado();
            cout << "Resultado del lanzamiento: " << dado1 << ", " << dado2 << ", " << dado3 << endl;
        }

        // Verificamos si hay dos caras iguales y una distinta
        if ((dado1 == dado2 && dado2 != dado3) || (dado1 == dado3 && dado1 != dado2) || (dado2 == dado3 && dado1 != dado2)) {
            cout << "Dos caras iguales y una distinta. ¿Desea seguir lanzando? (s/n): ";
            cin >> continuar;
        } else {
            // Son distintas y ninguna es as
            if (dado1 != 1 && dado2 != 1 && dado3 != 1) {
                int sumaTrufas = dado1 + dado2 + dado3;
                if (turno == 1) {
                    trufasJ1 += sumaTrufas;
                } else {
                    trufasJ2 += sumaTrufas;
                }
                cout << "Trufas acumuladas: " << sumaTrufas << endl;

                cout << "¿Desea seguir lanzando? (s/n): ";
                cin >> continuar;
            } else {
                cout << "¿Desea seguir lanzando? (s/n): ";
                cin >> continuar;
            }
        }

        // Cambiar turno
        if (turno == 1) {
            turno = 2;
        } else {
            turno = 1;
        }

        ronda++;
    }

    // Mostrar resultado final
    cout << "Resultado final:" << endl;
    cout << nombrejugador1 << ": " << trufasJ1 << " trufas" << endl;
    cout << nombrejugador2 << ": " << trufasJ2 << " trufas" << endl;
}




void estadisticas(){
    cout<<"todo lo que concierne a estadistica." <<endl;
}

void Cerditos(){
    cout<<"Equipo:  tatata"<<endl;
    cout<<"Integrantes: "<<endl;
    cout<<"1. Galarza Galmes Gonzalo, legajo numero 28218" <<endl;
    cout<<"2. Castro Jose Ignacio, legajo numero 28018"<<endl;
    cout<<"3. Valenzuela Nahuel, legajo 28056 "<<endl;
    cout<<"4. Nigro Valentin, legajo 29840"<<endl;
}
