#include <iostream>
#include <conio.h>
using namespace std;

struct Nodo {
    int dato;
    Nodo* siguiente;
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

    if (lista == NULL) {
        lista = nuevo_nodo;
        nuevo_nodo->siguiente = lista;  
    } 
    else {
        Nodo* aux1 = lista;
        Nodo* aux2;

        while ((aux1->siguiente != lista) && (aux1->dato < x)) {
            aux2 = aux1;
            aux1 = aux1->siguiente;
        }

        if (lista == aux1) {
            nuevo_nodo->siguiente = lista;
            lista = nuevo_nodo;
            aux1->siguiente = lista; 
        } else {
            aux2->siguiente = nuevo_nodo;
            nuevo_nodo->siguiente = aux1;
        }
    }

    cout << x << " ha sido ingresado en la lista";
}

void BuscarDato(Nodo*lista,int n){
    Nodo*actual = new Nodo();
    actual=lista;
    bool band = false;
    
    while ((actual!=0)&&(actual->dato<=n)){
        if(actual->dato==n){
            band = true;
        }
        actual=actual->siguiente;
    }
    if(band==true){
        cout<<"El numero "<<n<<" si se encunetra en la lista\n";
    }
    else{
        cout<<"El numero no se encuentra en la lista\n";
    }
    }


void show(Nodo*lista){
    Nodo*act=new Nodo();
    act = lista;
    
    while(act != NULL){
        cout<<act->dato<< " -> ";
        act = act -> siguiente;
    }
}

void EliminarDato(Nodo*&lista, int n){
    if(lista!=NULL){
        Nodo*borrar;
        Nodo*anterior=NULL;
        borrar=lista;
    
    while((borrar!=NULL)&&(borrar->dato!=n)){
        anterior=borrar;
        borrar=borrar->siguiente;
    }
    if(borrar==NULL){
        cout<<"El numero no se encuentra en la lista\n";
    }
    else if(anterior==NULL){
        lista=lista->siguiente;
        delete borrar;
        cout<<"El numero ha sido eliminado\n";
    }
    else{
        anterior->siguiente=borrar->siguiente;
        delete borrar;
        cout<<"El numero ha sido eliminado\n";

    }
    }
}