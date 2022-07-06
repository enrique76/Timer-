#include<iostream>

using namespace std;

class tiempo{
    private:
        double segundos;
        string comentario;
        string scrambel;
    public:
        tiempo(string scrambel){
            this->scrambel = scrambel;
        }

        string getScrambel(){
            return this->scrambel;
        }

        string getComentario(){
            return this->comentario;
        }

        void setComentario(string comentario){
            this->comentario = comentario;
        }

        void setSegundos(double segundos){
            this->segundos = segundos;
        }

        void Imprimir(){
            cout<<"\nScrambel: "<<this->scrambel;
            cout<<"\nTiempo: "<<this->segundos;
            cout<<"\nComentario: "<<this->comentario;
        }
};