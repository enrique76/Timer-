#include<iostream>
#include<vector>

using namespace std;

double Media(vector<double> v){

    //if(v.size() > 0){
        double suma = 0;
        for(int i=0;i<v.size();i++){
            suma+=v[i];
        }

        double media = suma/v.size();

        return media;
   // }
   // else{
    //    return 0;
    //}
}

bool buscar(string t,string x){
    if(t.find(x)!=string::npos){
        // si se encuentra
        return true;
    }
    else{
        // no se encuentra
        return false;
    }
}

bool buscar(string v[],string x,int n){
    for(int i=0;i<n;i++){
        if(v[i].compare(x) == 0){
            // si se encuentra
            return true;
            break;
        }
    }

    return false;
}