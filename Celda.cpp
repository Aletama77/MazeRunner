#include "Celda.h"
#include "Consumible.h"
Celda::Celda(){
    _estado = ESTADO::MURO;
    _tieneconsumible=false;
}

Celda::~Celda(){
    //dtor
}

void Celda::setEstado(int estado){
    _estado = estado;
}

int Celda::getEstado(){
    return _estado;
}
void Celda::settieneconsumible(){
    _tieneconsumible = true;
}
void Celda::settieneconsumibleFALSE(){
    _tieneconsumible = false;
}

bool Celda::gettieneconsumible(){
    return _tieneconsumible;
}

void Celda::settipoconsumible(int n){
    obj.setTipo(n);
}
int Celda::gettipoconsumible(){
    return obj.getTipo();
}
