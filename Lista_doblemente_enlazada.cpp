#include <iostream>
#include <conio.h>
using namespace std;

struct Nodo {
    int dato;
    Nodo* siguiente;
    Nodo* anterior;
};

void insertarlista(Nodo*&, int);
void show(Nodo*);
Nodo* lista = NULL;
void menu();
void BuscarDato(Nodo*, int);
void EliminarDato(Nodo*&, int);

int main() {
    menu();
    return 0;
}

void menu() {
    int opcion, dato;

    do {
        cout << "\nOpciones\n";
        cout << "1. Insertar nuevo dato\n";
        cout << "2. Imprimir lista\n";
        cout << "3. Buscar numero\n";
        cout << "4. Eliminar numero\n";
        cout << "5. Salir\n";
        cin >> opcion;

        if (opcion == 1) {
            cout << "Inserte un numero ";
            cin >> dato;
            insertarlista(lista, dato);
        }

        if (opcion == 2) {
            show(lista);
        }

        if (opcion == 3) {
            cout << "Ingrese el numero que desea buscar ";
            cin >> dato;
            BuscarDato(lista, dato);
        }

        if (opcion == 4) {
            cout << "Ingrese el numero que desea eliminar ";
            cin >> dato;
            EliminarDato(lista, dato);
        }
    } while (opcion != 5);
}

void insertarlista(Nodo*& lista, int x) {
    Nodo* nuevo_nodo = new Nodo();
    nuevo_nodo->dato = x;
    nuevo_nodo->siguiente = NULL;
    nuevo_nodo->anterior = NULL;

    if (lista == NULL) {
        lista = nuevo_nodo;
    } 
    else {
        Nodo* aux = lista;
        while (aux->siguiente != NULL) {
            aux = aux->siguiente;
        }
        aux->siguiente = nuevo_nodo;
        nuevo_nodo->anterior = aux;
    }

    cout << x << " ha sido ingresado en la lista";
}

void show(Nodo* lista) {
    Nodo* actual = lista;

    while (actual != NULL) {
        cout << actual->dato << " -> ";
        actual = actual->siguiente;
    }
}

void BuscarDato(Nodo* lista, int n) {
    Nodo* actual = lista;
    bool bandera = false;

    while (actual != NULL) {
        
        if (actual->dato == n) {
            bandera = true;
        }
        
        actual = actual->siguiente;
    }

    if (bandera==true) {
        cout << "El numero " << n << " se encuentra en la lista\n";
    } 
    else {
        cout << "El numero no se encuentra en la lista\n";
    }
}

void EliminarDato(Nodo*& lista, int n) {
    if (lista != NULL) {
        Nodo * actual = lista;

        while (actual != NULL && actual->dato != n) {
            actual = actual->siguiente;
        }

        if (actual != NULL) {
            
            if (actual->anterior != NULL) {
                actual->anterior->siguiente = actual->siguiente;
            }
            else {
                lista = actual->siguiente;
            }

            if (actual->siguiente != NULL) {
                actual->siguiente->anterior = actual->anterior;
            }

            delete actual;
            cout << "El numero ha sido eliminado\n";
        } 
        else {
            cout << "El numero no se encuentra en la lista\n";
        }
    }
}