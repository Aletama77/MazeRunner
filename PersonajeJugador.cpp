#include "PersonajeJugador.h"


PersonajeJugador::PersonajeJugador(Laberinto& lab,Configuracion& confi) {
    _velocity = 2;
    _personajeSprint = 0;
    _texture.loadFromFile("pictures/caballero1.png");
    _sprite.setTexture(_texture);
    _sprite.setTextureRect(sf::IntRect(0, 0, 74.33, 103));
    _sprite.setScale(.3f, .3f);

    playerPos = sf::Vector2i(lab.getfilainicial(), lab.getcolumnaincial()); // inicia playerPos
    _sprite.setPosition(
        playerPos.y * lab.getspritegrass().getGlobalBounds().width,
        playerPos.x * lab.getspritegrass().getGlobalBounds().height
    );


    _vida = 100;
    _salida = false;


    _buffercomer.loadFromFile("efectos de sonido/comer.wav");
     _soundcomer.setBuffer(_buffercomer);
     _soundcomer.setVolume(confi.getvolumenPartida());




}

void PersonajeJugador::update(Laberinto& laberinto, Niebla& nie,int& s,bool& activacionniebla) {
    _personajeSprint++;

    sf::Vector2i prevPos = playerPos; // posición anterior

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        playerPos.x--;
        _sprite.setTextureRect(sf::IntRect(_personajeSprint % 3 * 74.33, 313, 74.33, 103));
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        playerPos.y--;
        _sprite.setTextureRect(sf::IntRect(_personajeSprint % 3 * 74.33, 98, 74.33, 103));
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        playerPos.x++;
        _sprite.setTextureRect(sf::IntRect(_personajeSprint % 3 * 74.30, 0.f, 74.33, 103));
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        playerPos.y++;
        _sprite.setTextureRect(sf::IntRect(_personajeSprint % 3 * 74.33, 206, 74.33, 103));
    }

    if (laberinto.getLaberinto(playerPos.x, playerPos.y) == MURO) {
        playerPos = prevPos; // vuelve posición anterior si es muro
    }
    else {
        _sprite.setPosition(
            playerPos.y * laberinto.getspritegrass().getGlobalBounds().width, //si no hay muro se actualiza la pos actual
            playerPos.x * laberinto.getspritegrass().getGlobalBounds().height
        );
    }
    if (laberinto.getestadoconsumible(playerPos.x, playerPos.y)) {
        int x=laberinto.gettipoconsumible(playerPos.x, playerPos.y);
         switch(x){
        case 1:
            sumarvida();
            _soundcomer.play();
            laberinto.setestadoconsumible(playerPos.x, playerPos.y);
            break;

        case 2:
            restarvida();
            _soundcomer.play();
            laberinto.setestadoconsumible(playerPos.x, playerPos.y);
            break;
        case 3:
            s = 5;
            _soundcomer.play();
            laberinto.setestadoconsumible(playerPos.x, playerPos.y);
            break;
        case 4:
            s = -5;
            _soundcomer.play();
            laberinto.setestadoconsumible(playerPos.x, playerPos.y);
            break;
        case 5:
            nie.aumentarradio();
            _soundcomer.play();
            laberinto.setestadoconsumible(playerPos.x, playerPos.y);
            break;
        case 6:
            nie.disminuirradio();
            _soundcomer.play();
            laberinto.setestadoconsumible(playerPos.x, playerPos.y);
            break;
        case 7:
             activacionniebla=true;
             nie.revelarmapa();
             _soundcomer.play();
            laberinto.setestadoconsumible(playerPos.x, playerPos.y);
            break;
         }



    }

    //  salida
    if (laberinto.getLaberinto(playerPos.x, playerPos.y) == SALIDA) {

        _salida = true;
    }


}

void PersonajeJugador::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(_sprite, states);

}

sf::FloatRect PersonajeJugador::getBounds() const {
    return _sprite.getGlobalBounds();
}

void PersonajeJugador::setVida(float vida) {
    _vida = vida;
}

void PersonajeJugador::setSalida(bool salida) {
    _salida = salida;
}

float PersonajeJugador::getVida() const {
    return _vida;
}

bool PersonajeJugador::isGameOver() const {
    return _vida == 0;
}

bool PersonajeJugador::getSalida() const {
    return _salida;
}

bool PersonajeJugador::ganador() const {
    return _salida == true;
}
int PersonajeJugador::getx(){
     return playerPos.x;

}
    int PersonajeJugador::gety(){
     return playerPos.y;
    }
void PersonajeJugador::restarvida(){
       _vida-=20;


}

void PersonajeJugador::sumarvida(){

       if(_vida<81){
       _vida+=20;
       }
}
