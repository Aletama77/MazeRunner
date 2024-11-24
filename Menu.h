#pragma once
#include "Minotauro.h"
#include "Laberinto.h"

#include "PersonajeJugador.h"
//#include <Vector>
#include <SFML\Graphics.hpp>
#include "Niebla.h"
//#include<string>


using namespace std;
using namespace sf;

class Menu
{
public:
    Text mainMenu[7];
    Text nombreJuego;
    Menu(float width, float height);
    void draw(RenderWindow& window);
    sf::Texture mainMenuBg;
    sf::Sprite bg;
    void MoveUp();
    void MoveDown();

    void setSelected(int n);
    void setPagenum(int pagenum);
    int pressed(){
        return selected;
    }
    void nav();
    ~Menu();
    void navegarMenu(Event& event);
    int getPagenum();

private:
    int selected;
    int _pagenum;
    Font font;
    Font fontNombre;

};
