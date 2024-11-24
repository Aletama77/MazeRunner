#include "Laberinto.h"

Laberinto::Laberinto() {
    srand(time(NULL));

    _textureMuro.loadFromFile("pictures/muro5.jpg");
    _spriteMuro.setTexture(_textureMuro);
    _textureGrass.loadFromFile("grass2.jpg");
    _spriteGrass.setTexture(_textureGrass);


     _rectSalida.setSize(sf::Vector2f(_spriteMuro.getGlobalBounds().width, _spriteMuro.getGlobalBounds().height));
    _rectSalida.setFillColor(sf::Color::Red);

    // seteo de texturas y sprites para consumibles


    _texturesumavida.loadFromFile("pictures/sumarvida1.png");
    _spritesumavida.setTexture(_texturesumavida);

    _texturerestavida.loadFromFile("pictures/restavida3.png");
    _spriterestavida.setTexture(_texturerestavida);

    _texturesumatiempo.loadFromFile("pictures/sumatiempo1.png");
    _spritesumatiempo.setTexture(_texturesumatiempo);

    _texturerestatiempo.loadFromFile("pictures/restatiempo1.png");
    _spriterestatiempo.setTexture(_texturerestatiempo);

    _textureaumentavision.loadFromFile("pictures/aumentavision1.png");
    _spritereaumentavision.setTexture(_textureaumentavision);

    _texturerestavision.loadFromFile("pictures/disminuyevision1.png");
    _spritererestavision.setTexture(_texturerestavision);

    _texturemostrarmapa.loadFromFile("pictures/mapa1.png");
    _spriteremostrarmapa.setTexture(_texturemostrarmapa);





}

void Laberinto::cargarParedes() {

    // cargar con paredes el laberinto
    for (int i = 0; i < contador + 2; i++) {
        for (int j = 0; j < contador + 2; j++) {
            matriz[i][j].setEstado(MURO);
        }
    }
    fila = rand() % contador + 1;
    matriz[fila][0].setEstado(CAMINO); // Se asegura que la entrada está en el borde izquierdo de la matriz
    matriz[fila][1].setEstado(CAMINO);
    columna = 1;

    filaInicial = fila;
    columnaInicial = columna-1;
    //std::cout << "fila: " << fila << std::endl;
    //std::cout << "columna: " << columna << std::endl;
}

void Laberinto::crearLaberinto() {
    while (columna != contador + 1) {
        direccion = rand() % 4;                     // 0 = arriba // 1 = abajo // 2 = izquierda // 3 = derecha.
        if (fueIzquierda == 1 && abajo == 1) {
            direccion = rand() % 2 + 1;
        }
        else if (fueIzquierda == 1 && abajo == 0) {
            direccion = rand() % 2;
            if (direccion == 1) {
                direccion++;
            }
        }

        switch (direccion) {
        case 0: // arriba
            if (fila > 1 && matriz[fila - 1][columna] == 1
                && matriz[fila - 2][columna] == 1
                && matriz[fila - 1][columna - 1] == 1
                && matriz[fila - 2][columna - 1] == 1
                && matriz[fila - 1][columna + 1] == 1
                && matriz[fila - 2][columna + 1] == 1)
            {
                //std::cout << "Se movio 1 arriba" << std::endl;
                matriz[fila - 1][columna].setEstado(CAMINO);
                fila--;
                abajo = 0;
                fueIzquierda = 0;
            }
            break;
        case 1: // abajo
            if (fila < contador
                && matriz[fila + 1][columna] == 1
                && matriz[fila + 2][columna] == 1
                && matriz[fila + 1][columna - 1] == 1
                && matriz[fila + 2][columna - 1] == 1
                && matriz[fila + 1][columna + 1] == 1
                && matriz[fila + 2][columna + 1] == 1)
                {
                    //std::cout << "Se movio 1 abajo" << std::endl;
                    matriz[fila + 1][columna].setEstado(CAMINO);
                    fila++;
                    abajo = 1;
                    fueIzquierda = 0;
                }
            break;
        case 2: // izquierda
            if (abajo == 1) {
                if (columna > 1
                    && fila < 22
                    && matriz[fila][columna - 1] == 1
                    && matriz[fila][columna - 2] == 1
                    && matriz[fila + 1][columna - 2] == 1
                    && matriz[fila + 2][columna - 2] == 1
                    && matriz[fila + 3][columna - 2] == 1)
                    {
                        //std::cout << "Se movio 1 a la izquierda abajo" << std::endl;
                        matriz[fila][columna - 1].setEstado(CAMINO);
                        columna--;
                        fueIzquierda = 1;
                    }
            }
            else if (abajo == 0) {
                if (columna > 1 && fila > 2
                    && matriz[fila][columna - 1] == 1
                    && matriz[fila - 1][columna - 2] == 1
                    && matriz[fila - 2][columna - 2] == 1
                    && matriz[fila - 3][columna - 2] == 1)
                    {
                        //std::cout << "Se movio 1 a la izquierda arriba" << std::endl;
                        matriz[fila][columna - 1].setEstado(CAMINO);
                        columna--;
                        fueIzquierda = 1;
                    }
            }
            break;
        case 3: // derecha
            if (columna == contador ||
                (matriz[fila][columna + 1] == 1
                && matriz[fila - 1][columna + 1] == 1
                && matriz[fila + 1][columna + 1] == 1
                && matriz[fila - 1][columna + 2] == 1
                && matriz[fila][columna + 2] == 1
                && matriz[fila + 1][columna + 2] == 1))
                {
                    //std::cout << "Se movio 1 a la derecha" << std::endl;
                    matriz[fila][columna + 1].setEstado(CAMINO);
                    columna++;
                    fueIzquierda = 0;
                }
            break;
        }
    }
    //std::cout << std::endl << "Solucion del laberinto" << std::endl;

    if (columna == contador+1) { // si estamos en la última columna
            if (matriz[fila][columna].getEstado() == CAMINO) {
                //matriz[fila][columna]=3; // es salida
                matriz[fila][columna].setEstado(SALIDA); // es salida
            }
        }


}

void Laberinto::caminosAlternativos() {
    //std::cout << std::endl << "Laberinto completo:" << std::endl;
    for (int i = 2; i < contador; i++) {
        for (int j = 2; j < contador; j++) {
            if (matriz[i][j] == 1
                && matriz[i - 1][j - 1] == 1
                && matriz[i - 1][j + 1] == 1
                && matriz[i + 1][j - 1] == 1
                && matriz[i + 1][j + 1] == 1)
                {
                    conecto = 0;
                    matriz[i][j].setEstado(CAMINO_ALTERNATIVO);
                    while (conecto == 0) {

                        direccionAlternativos = rand() % 4; // 0 = arriba // 1 = abajo // 2 = izquierda // 3 = derecha.

                        switch (direccionAlternativos) {
                            case 0:                             // arriba
                                if (matriz[i][j - 1] == 1) {
                                    matriz[i][j - 1].setEstado(CAMINO_ALTERNATIVO);
                                }
                                else {
                                    conecto = 1;
                                }
                                break;
                            case 1: // abajo
                                if (matriz[i][j + 1] == 1) {
                                    matriz[i][j + 1].setEstado(CAMINO_ALTERNATIVO);
                                }
                                else {
                                    conecto = 1;
                                }
                                break;
                            case 2: // izquierda
                                if (matriz[i - 1][j] == 1) {
                                    matriz[i - 1][j].setEstado(CAMINO_ALTERNATIVO);
                                }
                                else {
                                    conecto = 1;
                                }
                                break;
                            case 3: // derecha
                                if (matriz[i + 1][j] == 1) {
                                    matriz[i + 1][j].setEstado(CAMINO_ALTERNATIVO);
                                }
                                else {
                                    conecto = 1;
                                }
                                break;
                        }
                    }
                }
        }
    }
}

void Laberinto::setconsumibles(){
 int contadorsumarvida=0;
 int contadorrestavida=0;
 int contadorsumatiempo=0;
 int contadorrestatiempo=0;
 int contadoraumentavision=0;
 int contadordisminuyevision=0;
 int contadormostrarmapa=0;
 int i=0,j=0;


    while(contadorsumarvida!=2)
    {
         i = rand() % contador ;
         j = rand() % contador ;
        if(matriz[i][j].getEstado()==4 && !matriz[i][j].gettieneconsumible()){
           matriz[i][j].settieneconsumible();
           matriz[i][j].settipoconsumible(SUMAVIDA);
          contadorsumarvida++;
          }
    }
    while(contadorrestavida!=5)
    {
         i = rand() % contador ;
         j = rand() % contador ;
        if(matriz[i][j].getEstado()==4 && !matriz[i][j].gettieneconsumible()){
           matriz[i][j].settieneconsumible();
           matriz[i][j].settipoconsumible(RESTAVIDA);
          contadorrestavida++;
          }
    }
     while(contadorsumatiempo!=2)
    {
         i = rand() % contador ;
         j = rand() % contador ;
        if(matriz[i][j].getEstado()==4 && !matriz[i][j].gettieneconsumible()){
           matriz[i][j].settieneconsumible();
           matriz[i][j].settipoconsumible(SUMATIEMPO);
          contadorsumatiempo++;
          }
    }
    while(contadorrestatiempo!=1)
    {
         i = rand() % contador ;
         j = rand() % contador ;
        if(matriz[i][j].getEstado()==4 && !matriz[i][j].gettieneconsumible()){
           matriz[i][j].settieneconsumible();
           matriz[i][j].settipoconsumible(RESTATIEMPO);
          contadorrestatiempo++;
          }
    }
    while(contadoraumentavision!=2)
    {
         i = rand() % contador ;
         j = rand() % contador ;
        if(matriz[i][j].getEstado()==4 && !matriz[i][j].gettieneconsumible()){
           matriz[i][j].settieneconsumible();
           matriz[i][j].settipoconsumible(AUMENTAVISION);
          contadoraumentavision++;
          }
    }
    while(contadordisminuyevision!=2)
    {
         i = rand() % contador ;
         j = rand() % contador ;
        if(matriz[i][j].getEstado()==4 && !matriz[i][j].gettieneconsumible()){
           matriz[i][j].settieneconsumible();
           matriz[i][j].settipoconsumible(RESTAVISION);
          contadordisminuyevision++;
          }
    }
    while(contadormostrarmapa!=1)
    {
         i = rand() % contador ;
         j = rand() % contador ;
        if(matriz[i][j].getEstado()==4 && !matriz[i][j].gettieneconsumible()){
           matriz[i][j].settieneconsumible();
           matriz[i][j].settipoconsumible(MOSTRARMAPA);
          contadormostrarmapa++;
          }
    }
}

void Laberinto::mostrarLaberinto(sf::RenderWindow& window) {

    // mostrar laberinto
    for (int i = 0; i < contador + 2; i++) {
        for (int j = 0; j < contador + 2; j++) {
            if (matriz[i][j].getEstado() ==1) {
                _spriteMuro.setPosition( j * _spriteMuro.getGlobalBounds().width, i * _spriteMuro.getGlobalBounds().height);
                window.draw(_spriteMuro);
            }
            else if (matriz[i][j].getEstado() == SALIDA) {
                _rectSalida.setPosition(j * _spriteMuro.getGlobalBounds().width, i * _spriteMuro.getGlobalBounds().height);
                window.draw(_rectSalida); //para la salida
            }
            if(matriz[i][j].getEstado() ==4 && matriz[i][j].gettieneconsumible() ){

                  if(matriz[i][j].gettipoconsumible()==1){
                   _spritesumavida.setPosition( j * _spritesumavida.getGlobalBounds().width, i * _spritesumavida.getGlobalBounds().height);
                     window.draw(_spritesumavida);


                  }
                  if(matriz[i][j].gettipoconsumible()==2){
                   _spriterestavida.setPosition( j * _spriterestavida.getGlobalBounds().width, i * _spriterestavida.getGlobalBounds().height);
                     window.draw(_spriterestavida);


                  }
                   if(matriz[i][j].gettipoconsumible()==3){
                   _spritesumatiempo.setPosition( j * _spritesumatiempo.getGlobalBounds().width, i * _spritesumatiempo.getGlobalBounds().height);
                     window.draw(_spritesumatiempo);


                  }
                   if(matriz[i][j].gettipoconsumible()==4){
                   _spriterestatiempo.setPosition( j * _spriterestatiempo.getGlobalBounds().width, i * _spriterestatiempo.getGlobalBounds().height);
                     window.draw(_spriterestatiempo);


                  }
                  if(matriz[i][j].gettipoconsumible()==5){
                   _spritereaumentavision.setPosition( j * _spritereaumentavision.getGlobalBounds().width, i * _spritereaumentavision.getGlobalBounds().height);
                     window.draw(_spritereaumentavision);


                  }
                  if(matriz[i][j].gettipoconsumible()==6){
                   _spritererestavision.setPosition( j * _spritererestavision.getGlobalBounds().width, i * _spritererestavision.getGlobalBounds().height);
                     window.draw(_spritererestavision);


                  }
                  if(matriz[i][j].gettipoconsumible()==7){
                   _spriteremostrarmapa.setPosition( j * _spriteremostrarmapa.getGlobalBounds().width, i * _spriteremostrarmapa.getGlobalBounds().height);
                     window.draw(_spriteremostrarmapa);


                  }
            }

        }
    }
}

int Laberinto::getcolumnaincial(){

   return columnaInicial;
}

int Laberinto::getfilainicial(){
return filaInicial;
}

sf::Sprite Laberinto::getspritegrass(){
           return _spriteGrass;
}

int Laberinto::getLaberinto(int x, int y){
      return matriz[x][y].getEstado();

}
bool Laberinto::getestadoconsumible(int x, int y){
      return matriz[x][y].gettieneconsumible();

}
void Laberinto::setestadoconsumible(int x, int y){
       matriz[x][y].settipoconsumible(NULO);
       matriz[x][y].settieneconsumibleFALSE();
}

int Laberinto::gettipoconsumible(int x, int y){

     return matriz[x][y].gettipoconsumible();
}

Laberinto::~Laberinto() {
    // dtor
}
///revisar
std::vector<sf::Vector2i> Laberinto::getCaminosAlternativos()
{
    std::vector<sf::Vector2i> caminosAlternativos;

    // celdas con el estado CAMINO_ALTERNATIVO
    for (int i = 0; i < contador + 2; i++)
    {
        for (int j = 0; j < contador + 2; j++)
        {
            if (matriz[i][j].getEstado() == CAMINO_ALTERNATIVO)
            {

                caminosAlternativos.push_back(sf::Vector2i(i, j));
            }
        }
    }

    return caminosAlternativos;
}
