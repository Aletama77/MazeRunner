#include "Consumible.h"




Consumible::Consumible(){
   _tipo=TIPO::NULO;
};


Consumible::~Consumible(){

};

void Consumible::setTipo(int n){
     _tipo=n;

}

int Consumible::getTipo(){
    return _tipo;

}
