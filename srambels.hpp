#include<iostream>
#include<string.h>
#include<time.h>
#include<vector>
#include"funciones.hpp"

using namespace std;

string sc_3x3(int n){
    vector<string> sc;

    // todas
    string x[18] = {"R ","R' ","R2 ","U ","U' ","U2 ","L ","L' ","L2 ","D ","D' ","D2 ","B ","B' ","B2 ","F ","F' ","F2 "};

    // izquierda y derecha R_L
    string sin_R[15] = {"U ","U' ","U2 ","L ","L' ","L2 ","D ","D' ","D2 ","B ","B' ","B2 ","F ","F' ","F2 "};
    string R[3] = {"R ","R' ","R2 "};
    string sin_RL[12] = {"U ","U' ","U2 ","D ","D' ","D2 ","B ","B' ","B2 ","F ","F' ","F2 "};
    string sin_L[15] = {"R ","R' ","R2 ","U ","U' ","U2 ","D ","D' ","D2 ","B ","B' ","B2 ","F ","F' ","F2 "};
    string L[3] = {"L ","L' ","L2 "};

    // superior e inferior U_D
    string sin_U[15] = {"R ","R' ","R2 ","L ","L' ","L2 ","D ","D' ","D2 ","B ","B' ","B2 ","F ","F' ","F2 "};
    string U[3] = {"U ","U' ","U2 "};
    string sin_UD[12] = {"R ","R' ","R2 ","L ","L' ","L2 ","B ","B' ","B2 ","F ","F' ","F2 "};
    string sin_D[15] = {"R ","R' ","R2 ","U ","U' ","U2 ","L ","L' ","L2 ","B ","B' ","B2 ","F ","F' ","F2 "};
    string D[3] = {"D ","D' ","D2 "};

    // enfrente y atras F_B
    string sin_F[15] = {"R ","R' ","R2 ","U ","U' ","U2 ","L ","L' ","L2 ","D ","D' ","D2 ","B ","B' ","B2 "};
    string F[3] = {"F ","F' ","F2 "};
    string sin_FB[12] = {"R ","R' ","R2 ","U ","U' ","U2 ","L ","L' ","L2 ","D ","D' ","D2 "};
    string sin_B[15] = {"R ","R' ","R2 ","U ","U' ","U2 ","L ","L' ","L2 ","D ","D' ","D2 ","F ","F' ","F2 "};
    string B[3] = {"B ","B' ","B2 "};

    srand(time(NULL));

    for(int i=0;i<n;i++){
        sc.push_back(x[rand()%18]);
    }

    // evitar datos consecutivos repetidos 

    int aux;

    for(int j=0;j<(n-1);j++){
        for(int i=0;i<(n-1);i++){
            if(buscar(R,sc[i],3) && buscar(R,sc[i+1],3)){
                aux = rand()%15;
                sc[i+1] = sin_R[aux];
            }
            if(buscar(L,sc[i],3) && buscar(L,sc[i+1],3)){
                aux = rand()%15;
                sc[i+1] = sin_L[aux];
            }
            if(buscar(U,sc[i],3) && buscar(U,sc[i+1],3)){
                aux = rand()%15;
                sc[i+1] = sin_U[aux];
            }
            if(buscar(D,sc[i],3) && buscar(D,sc[i+1],3)){
                aux = rand()%15;
                sc[i+1] = sin_D[aux];
            }
            if(buscar(F,sc[i],3) && buscar(F,sc[i+1],3)){
                aux = rand()%15;
                sc[i+1] = sin_F[aux];
            }
            if(buscar(B,sc[i],3) && buscar(B,sc[i+1],3)){
                aux = rand()%15;
                sc[i+1] = sin_B[aux];
            }
        }
    }

    // evitar movimientos consecutivos paralelos

    for(int i=0;i<(n-2);i++){
        if(buscar(R,sc[i],3) && buscar(L,sc[i+1],3) && buscar(R,sc[i+2],3)){
            aux = rand()%12; 
            sc[i+1] = sin_RL[aux]; 
        }
        else if(buscar(L,sc[i],3) && buscar(R,sc[i+1],3) && buscar(L,sc[i+2],3)){
            aux = rand()%12; 
            sc[i+1] = sin_RL[aux]; 
        }
        else if(buscar(U,sc[i],3) && buscar(D,sc[i+1],3) && buscar(U,sc[i+2],3)){
            aux = rand()%12; 
            sc[i+1] = sin_UD[aux]; 
        }
        else if(buscar(D,sc[i],3) && buscar(U,sc[i+1],3) && buscar(D,sc[i+2],3)){
            aux = rand()%12; 
            sc[i+1] = sin_UD[aux]; 
        }
        else if(buscar(F,sc[i],3) && buscar(B,sc[i+1],3) && buscar(F,sc[i+2],3)){
            aux = rand()%12; 
            sc[i+1] = sin_FB[aux]; 
        }
        else if(buscar(B,sc[i],3) && buscar(F,sc[i+1],3) && buscar(B,sc[i+2],3)){
            aux = rand()%12; 
            sc[i+1] = sin_FB[aux]; 
        }
    }

    // creando el string 

    string scu;

    for(int i=0;i<sc.size();i++){
        scu+=sc.at(i);
    }

    return scu;
}