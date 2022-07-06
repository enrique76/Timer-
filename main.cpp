#include<iostream>
#include<conio.h>
#include<windows.h>
#include<vector>
#include<string>
#include<chrono>
#include<thread>
#include"tiempo.hpp"
#include"srambels.hpp"

using namespace std;
using namespace std::chrono;
using namespace std::this_thread;

void menu();
void AgregarTiempo();
void Tiempos();
void CambiarComentario();
void salir();
void Contar();
void PararConteo();

vector<tiempo> v;
vector<double> s;
int opc;
double media;
bool V = true;
double aux;

int main(){

    while(true){
        system("cls");
        cout<<">> ";
        if(kbhit()){
            
            char tecla = getch();

            if(tecla == 32){
                AgregarTiempo();
            }
            else if(tecla == 't' || tecla == 'T'){
                Tiempos();

                cout<<"\n\nPresione cualquier tecla para continuar";
                getch();
            }    
            else if(tecla == 's' || tecla == 'S'){
                salir();
            }
            else if(tecla == 'c' || tecla == 'C'){
                CambiarComentario();
            }
        }
    }
    
    return 0;
}

void menu(){
    system("cls");
    cout<<"\n1.- Nuevo Tiempo";
    cout<<"\n2.- Ver Historia";
    cout<<"\n3.- Salir";
    cout<<"\n\nOpccion: "; cin>>opc;
    if(opc == 31){
        opc = 1;
    }
    if(opc < 1 || opc > 3){
        cout<<"\n\nOpccion invalida";
        Sleep(1500);
        menu();
    }
}

void AgregarTiempo(){
    tiempo t(sc_3x3(20));

    cout<<"\n \t"<<t.getScrambel();

    cout<<"\n\nPresione cualquier tecla para continuar";
    getch();

    auto inicio = chrono::system_clock::now();

    thread hilo1(&Contar);

    PararConteo();

    hilo1.join();

    auto final = chrono::system_clock::now(); 
    chrono::duration<float> duracion = final - inicio;

    V=true; 

    system("cls");

    cout<<"\n\t "<<t.getScrambel();
    cout<<"\n\t "<<aux<<"s"<<" \t Duracion: "<<duracion.count();

    getch();

    t.setSegundos(aux);
    s.push_back(aux);

    v.push_back(t);
    
    media = Media(s);
}

void Tiempos(){
    system("cls");
    for(int i=0;i<v.size();i++){
        cout<<"\n\nTiempo #"<<i+1<<"\n";
        v[i].Imprimir();
    }
}

void salir(){
    cout<<"\n\nSaliendo";
    Sleep(500);
    cout<<".";
    Sleep(500);
    cout<<".";
    Sleep(500);
    cout<<".";
    Sleep(500);
    cout<<".";
    system("cls");
    exit(1);
}

void CambiarComentario(){
    Tiempos();

    cout<<"\n\nNumero de Tiempo: "; cin>>opc;

    opc--;
    
    string nc;

    if(opc < 0 || opc > v.size()-1){
        cout<<"\n\nTiempo no encontrado";
        Sleep(1500);
        CambiarComentario();
    }

    cout<<"\n\nComentario Actual: "<<v[opc].getComentario();

    fflush(stdin);

    cout<<"\n\nNuevo Comentario: "; getline(cin,nc); 


    if(nc.empty()){
        cout<<"\n\nNo se Agrego ningun cambio";
        Sleep(1500);
    }
    else{
        

        v[opc].setComentario(nc);

        cout<<"\n\nCambio Agregado";
        Sleep(1500);
    }
}

void PararConteo(){
    while(V){
        if(kbhit()){
            char c = getch();
            if(c == 32){
                V = false;
            }
        }
    }
}

void Contar(){
    aux = 0;
    while(V){ 
        system("cls");
        aux+=0.01;
        cout<<aux;
    }
} 