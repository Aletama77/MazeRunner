#include "Menu.h"


using namespace std;
using namespace sf;

Menu::Menu(float width, float height){

    font.loadFromFile("fonts/grec.ttf");
    fontNombre.loadFromFile("fonts/heorot.ttf");
    mainMenuBg.loadFromFile("imagen/fondoMenu1.png");
    bg.setTexture(mainMenuBg);

    nombreJuego.setFont(fontNombre);
    nombreJuego.setFillColor(Color{255,204,0});
    nombreJuego.setString("MAZZE RUNNER");
    nombreJuego.setCharacterSize(90);
    nombreJuego.setPosition(Vector2f(400,height/(4)-150));

        mainMenu[0].setFont(font);
    mainMenu[0].setFillColor(Color{255,204,0});
    mainMenu[0].setString("Jugar");
    mainMenu[0].setCharacterSize(60);
    mainMenu[0].setPosition(Vector2f(200,height/(4)-20));

    mainMenu[1].setFont(font);
    mainMenu[1].setFillColor(Color::White);
    mainMenu[1].setString("Historia");
    mainMenu[1].setCharacterSize(60);
    mainMenu[1].setPosition(Vector2f(200,height/(4)+60));

    mainMenu[2].setFont(font);
    mainMenu[2].setFillColor(Color::White);
    mainMenu[2].setString("Configuracion");
    mainMenu[2].setCharacterSize(60);
    mainMenu[2].setPosition(Vector2f(200,height/(4)+140));

    mainMenu[3].setFont(font);
    mainMenu[3].setFillColor(Color::White);
    mainMenu[3].setString("Creditos");
    mainMenu[3].setCharacterSize(60);
    mainMenu[3].setPosition(Vector2f(200,height/(4)+220));

    mainMenu[4].setFont(font);
    mainMenu[4].setFillColor(Color::White);
    mainMenu[4].setString("Estadisticas");
    mainMenu[4].setCharacterSize(60);
    mainMenu[4].setPosition(Vector2f(200,height/(4)+300));

    mainMenu[5].setFont(font);
    mainMenu[5].setFillColor(Color::White);
    mainMenu[5].setString("Jugador");
    mainMenu[5].setCharacterSize(60);
    mainMenu[5].setPosition(Vector2f(200,height/(4)+380));

    mainMenu[6].setFont(font);
    mainMenu[6].setFillColor(Color::White);
    mainMenu[6].setString("Salir");
    mainMenu[6].setCharacterSize(60);
    mainMenu[6].setPosition(Vector2f(200,height/(4)+460));

    _pagenum = 1000;
    selected = 0;
}

Menu::~Menu(){}

void Menu::setSelected(int n){
    selected = n;
}

void Menu::draw(RenderWindow& window){
    for(int i = 0; i < 7; i++){
            window.draw(mainMenu[i]);
    }
            window.draw(nombreJuego);
}

void Menu::MoveDown(){
    if(selected+1<=7) //not exit
    {
        mainMenu[selected].setFillColor(Color::White);
        selected++;
        if(selected == 7){
            selected = 0;
        }
        mainMenu[selected].setFillColor(Color{255,204,0});
    }
}

void Menu::MoveUp(){
    if(selected >= -1) //not play
    {
        mainMenu[selected].setFillColor(Color::White);
        selected--;
        if(selected ==-1){
            selected = 6;
        }
        mainMenu[selected].setFillColor(Color{255,204,0});
    }
}

void Menu::navegarMenu(Event& event){
    //navegar por el menu
    if(event.type==Event::KeyPressed)
    {
        if(event.key.code == Keyboard::Up)
        {
            MoveUp();
        }

        if(event.key.code == Keyboard::Down)
        {
            MoveDown();
        }
        if(event.key.code == Keyboard::Return)
        {
            if(pressed()==0){
               setPagenum(0);

            }
            if(pressed()==1){
               setPagenum(1);

            }
            if(pressed()==2){
               setPagenum(2);

            }
            if(pressed()==3){
               setPagenum(3);

            }
            if(pressed()==4){
               setPagenum(4);

            }

            if(pressed()==5){
               setPagenum(5);

            }
            if(pressed()==6){
               setPagenum(-1);

            }

        }
    }
}

void Menu::setPagenum(int pagenum){
        _pagenum = pagenum;
}

int Menu::getPagenum(){
    return _pagenum;
}


