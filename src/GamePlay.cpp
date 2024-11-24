#include "GamePlay.h"

GamePlay::GamePlay()
{
    //ctor
}

void GamePlay::jugar(){

    RenderWindow window(VideoMode(1000, 800), "Game");
    Menu menu(800, 600);

    while (true){
        while(window.isOpen()){
            Event event;
            while(window.pollEvent(event)) {
                if(event.type==Event::Closed){
                    window.close();
                    break;
                }

                if(event.type==Event::KeyPressed){
                    if(event.key.code == Keyboard::Up);
                    menu.MoveUp();
                }
                if(event.type==Event::KeyPressed){
                    if(event.key.code == Keyboard::Down);
                    menu.MoveDown();
                }
            }
            window.clear();
            menu.draw(window);
            window.display();
        }
    }

}

GamePlay::~GamePlay()
{
    //dtor
}
