
#include <iostream>
#include <conio.h>
using namespace std;

struct Nodo{
    int dato;
    Nodo * siguiente;
};

void insertarlista(Nodo *&,int);
void show(Nodo*);
Nodo*lista = NULL; 
void menu();


int main(){
    menu();
    getch();
    return 0;
}

void menu(){
    int opcion,dato;
    
    do{
        cout<<"\nOpciones\n";
        cout<<"1. insertar nuevo dato\n";
        cout<<"2. imprimir lista\n";
        cout<<"3. Salir\n";
        cin>>opcion;
        
        if(opcion==1){

        cout<<"Inserte un numero ";
        cin>>dato;
        insertarlista(lista,dato);    
        }
        
        if(opcion==2){
        show(lista);    
        }
    }while(opcion !=3);
    
}

void insertarlista(Nodo*&lista, int x){
    Nodo*nuevo_nodo = new Nodo();
    nuevo_nodo ->dato=x;
    
    Nodo*aux1=lista;
    Nodo*aux2;
    
    while((aux1 != NULL)&&(aux1->dato<x)){
        aux2=aux1;
        aux1=aux1->siguiente;
    }
    if(lista==aux1){
        lista=nuevo_nodo;
    }
    else{
        aux2->siguiente=nuevo_nodo;
    }
    nuevo_nodo->siguiente=aux1;
    cout<<x<<" ha si ingresado en la lista";
    
}

void show(Nodo*lista){
    Nodo*act=new Nodo();
    act = lista;
    
    while(act != NULL){
        cout<<act->dato<< " -> ";
        act = act -> siguiente;
    }
}
