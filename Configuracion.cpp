#include "Configuracion.h"



Configuracion::Configuracion(){
  _volumenMainTheme=50;
  _volumenPartida=50;


};


Configuracion::~Configuracion(){

};
float  Configuracion::getvolumenPartida(){
     return _volumenPartida;
};
float  Configuracion::getvolumenMainTheme(){

     return _volumenMainTheme;
};
void Configuracion::setvolumenPartida(int n){
     _volumenPartida=n;
};
void Configuracion::setvolumenMainTheme(int n){
     _volumenMainTheme=n;
};
void Configuracion::setmute(){
    _volumenMainTheme=0;
    _volumenPartida=0;
};
