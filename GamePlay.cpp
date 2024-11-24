#pragma once
#include "GamePlay.h"
#include "JugadorArchivo.h"
#include "Jugador.h"
#include "Funciones.h"

GamePlay::GamePlay()
{

            bufferganaste.loadFromFile("efectos de sonido/ganaste.wav");
            soundganaste.setBuffer(bufferganaste);

            bufferperdiste.loadFromFile("efectos de sonido/perdiste.wav");
            soundperdiste.setBuffer(bufferperdiste);
}

void GamePlay::jugar(sf::Music& musica, Configuracion& confi,Music& musica2)
{
    sf::RenderWindow window(sf::VideoMode(1500, 1050), "Game");
    window.setFramerateLimit(30);
    Menu menu(1500, 1050);


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }


            menu.navegarMenu(event);

        }
         if (musica.getDuration().asMilliseconds() - musica.getPlayingOffset().asMilliseconds() <= 50){

              musica2.play();

            }

        window.clear();
        window.draw(menu.bg);


        menu.draw(window);
        window.display();

        if (menu.getPagenum() == -1)
        {
            window.close();
        }
        else if (menu.getPagenum() == 0)
        {

            subMenuJugar(window, musica,confi,musica2);


            menu.setPagenum(1000);

        }

        if (menu.getPagenum() == -1)
        {
            window.close();
        }
        else if (menu.getPagenum() == 0)
        {

            subMenuJugar(window, musica,confi,musica2);
            menu.setPagenum(1000);

        }

        else if (menu.getPagenum() == 1)
        {

            historia(window,musica,confi,musica2);
        }

        else if (menu.getPagenum() == 2)
        {

            configuracion(window, musica,confi,musica2);
        }
        else if (menu.getPagenum() == 3)
        {

            creditos(window, musica,confi,musica2);
        }
        else if (menu.getPagenum() == 4)
        {


            estadisticas(window, musica,confi,musica2);
        }
        else if (menu.getPagenum() == 5)
        {
            jugador(window, musica,confi,musica2);

        }
    }
}

// Submenú de opciones de Jugar
void GamePlay::subMenuJugar(RenderWindow& window, sf::Music& musica,Configuracion& confi,Music& musica2) {

    Texture background;
    background.loadFromFile("imagen/fondo3.png");
    Sprite bg;
    bg.setTexture(background);

    sf::Font font;
    if (!font.loadFromFile("nulshock.otf")) {
        std::cerr << "Error al cargar la fuente." << std::endl;
    }

    // Crear los textos para las opciones del submenú
    sf::Text textOpcion1("1. Jugar sin registrarse", font, 45);
    sf::Text textOpcion2("2. Jugar registrado", font, 45);
    sf::Text textSeleccionar("Seleccione el modo deseado", font, 55);

    // Posicionar los textos
    textSeleccionar.setPosition(200, 250);
    textOpcion1.setPosition(200, 500);
    textOpcion2.setPosition(200, 750);

    // Establecer colores de texto
    textSeleccionar.setFillColor(sf::Color::White);
    textOpcion1.setFillColor(sf::Color::White);
    textOpcion2.setFillColor(sf::Color::White);

    int opc = 0; // Controlador para la opción seleccionada

    // Bucle para mostrar el submenú
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Navegar entre las opciones con las flechas
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Down) {
                    if (opc < 1) {
                        opc++;  // Mover hacia abajo
                    }
                }
                if (event.key.code == sf::Keyboard::Up) {
                    if (opc > 0) {
                        opc--;  // Mover hacia arriba
                    }
                }




                // Si se presiona "Enter", ejecutar la opción seleccionada
                if (event.key.code == sf::Keyboard::Return) {
                    if (opc == 0) { // Jugar sin registrarse
                        Jugador player;
                        display(window, name, player, musica,confi,musica2);  // Inicia el juego sin registro
                        return;  // Salir del bucle
                    } else if (opc == 1) { // Jugar registrado
                        pedirDNI(window, musica,confi,musica2);  // Pedir DNI para jugar registrado
                        return;  // Salir del bucle
                    }
                }
            }
        }
            if (musica.getDuration().asMilliseconds() - musica.getPlayingOffset().asMilliseconds() <= 50){

              musica2.play();

            }

        // Limpiar la ventana
        window.clear();

        // Resaltar la opción seleccionada
        if (opc == 0) {
            textOpcion1.setFillColor(sf::Color::Yellow); // Opción 1 seleccionada
            textOpcion2.setFillColor(sf::Color::White);  // Opción 2 no seleccionada
        } else if (opc == 1) {
            textOpcion1.setFillColor(sf::Color::White);  // Opción 1 no seleccionada
            textOpcion2.setFillColor(sf::Color::Yellow); // Opción 2 seleccionada
        }


        window.draw(bg);
        window.draw(textSeleccionar);
        window.draw(textOpcion1);
        window.draw(textOpcion2);

        // Mostrar en pantalla
        window.display();
    }
}

// Función para pedir el DNI del jugador
void GamePlay::pedirDNI(sf::RenderWindow& window, sf::Music& musica,Configuracion& confi,Music& musica2) {

    Texture background;
    background.loadFromFile("imagen/fondo3.png");
    Sprite bg;
    bg.setTexture(background);

    sf::Font font;
    if (!font.loadFromFile("nulshock.otf")) {
        std::cerr << "Error al cargar la fuente." << std::endl;
    }


    sf::Text textDNI("Ingrese su DNI para jugar:", font, 40);
    textDNI.setPosition(200, 250);
    textDNI.setFillColor(sf::Color::White);

    // Crear un campo de texto para que el jugador ingrese el DNI
    sf::Text textInput("", font, 40);  // Convertimos el texto ingresado en un texto visual
    textInput.setPosition(200, 350);
    textInput.setFillColor(sf::Color::White);

    // Crear el texto para mostrar mensajes de error (inicialmente vacío)
    sf::Text textError("", font, 30);
    textError.setPosition(200, 450);
    textError.setFillColor(sf::Color::Red); // Color rojo para los mensajes de error

    std::string input;  // Utilizamos un std::string para almacenar la entrada
    bool error = false;  // Flag para saber si hay un error
    sf::Clock errorClock;  // Temporizador para el mensaje de error

    // Bucle para pedir y leer el DNI
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }




            // Si se presiona una tecla
            if (event.type == sf::Event::TextEntered) {
                // Solo agregar números al input (para el DNI, se asume que solo deben ser números)
                if (event.text.unicode == 8 && !input.empty()) { // Backspace
                    input.pop_back();  // Eliminar el último carácter
                } else if (event.text.unicode >= '0' && event.text.unicode <= '9') {  // Solo números
                    input += static_cast<char>(event.text.unicode);  // Agregar el número al texto
                }
            }

            // Si se presiona "Enter", verificar el DNI
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return) {
                // Verificar si el campo de texto está vacío
                if (input.empty()) {
                    textError.setString("Por favor, ingrese un DNI válido.");  // Mostrar mensaje de error
                    error = true;  // Activar el error
                    errorClock.restart();  // Reiniciar el temporizador
                    continue;
                }

                // Convertir el input a un número entero (DNI)
                try {
                    int dni = std::stoi(input);  // Convertir el input a un número entero

                    JugadorArchivo pa;
                    int pos = pa.buscar(dni);

                    if (pos != -1) {
                        Jugador player = pa.leer(pos);
                        display(window, name, player, musica,confi,musica2); // Jugar con el jugador registrado
                        return; // Salir del bucle y continuar
                    } else {
                        textError.setString("DNI no encontrado. Debe registrarse primero.");  // Mostrar mensaje de error
                        error = true;  // Activar el error
                        errorClock.restart();  // Reiniciar el temporizador
                        continue; // Continuar el ciclo para que el mensaje siga apareciendo
                    }
                } catch (const std::invalid_argument& e) {
                    textError.setString("El DNI ingresado no es válido.");  // Mostrar mensaje de error
                    error = true;  // Activar el error
                    errorClock.restart();  // Reiniciar el temporizador
                }
            }
        }

        // Limpiar la ventana
        window.clear();
          if (musica.getDuration().asMilliseconds() - musica.getPlayingOffset().asMilliseconds() <= 50){

              musica2.play();

            }

        // Si hay un error y han pasado más de 3 segundos, restablecer
        if (error && errorClock.getElapsedTime().asSeconds() > 3) {
            textError.setString("");  // Borrar el mensaje de error
            error = false;  // Desactivar el flag de error
            input = "";  // Restablecer la entrada
            // Llamar al jugador sin registro
            Jugador player;  // Aquí inicializas un jugador vacío o por defecto
            display(window, name, player, musica,confi,musica2); // Jugar con el jugador registrado
            return;
        }

        // Actualizar el campo de texto con el contenido ingresado
        textInput.setString(input);

        // Dibujar los textos
        window.draw(bg);
        window.draw(textDNI);  // Texto que dice "Ingrese su DNI"
        window.draw(textInput);  // Campo de texto donde se muestra lo que el usuario ingresa
        window.draw(textError);  // Mostrar mensaje de error si es necesario

        // Mostrar la ventana
        window.display();
    }
}



void GamePlay::display(sf::RenderWindow& window, std::string& nombre,Jugador& player, sf::Music& musica,Configuracion& confi,Music& musica2)
{

    window.setFramerateLimit(10);

    Menu menu(800, 700);
    Laberinto maze;
    maze.cargarParedes();
    maze.crearLaberinto();
    maze.caminosAlternativos();
    maze.setconsumibles();
    PersonajeJugador jugador(maze,confi);
    Niebla fog(jugador,maze,window);
    Minotauro minot(maze);

    sf::Clock cronometro;
    sf::Font font;
    font.loadFromFile("nulshock.otf");
    sf::Text cronometroTexto;
    cronometroTexto.setFont(font);
    cronometroTexto.setCharacterSize(24);
    cronometroTexto.setFillColor(sf::Color::White);
    cronometroTexto.setPosition(1050, 40);


    sf::Text playerDniTexto;
    sf::Text playerNombreTexto;
    sf::Text playerPuntajeTexto;

    playerDniTexto.setFont(font);
    playerDniTexto.setCharacterSize(24);
    playerDniTexto.setFillColor(sf::Color::White);
    playerDniTexto.setPosition(1050, 70);

    playerNombreTexto.setFont(font);
    playerNombreTexto.setCharacterSize(24);
    playerNombreTexto.setFillColor(sf::Color::White);
    playerNombreTexto.setPosition(1050, 100);

    playerPuntajeTexto.setFont(font);
    playerPuntajeTexto.setCharacterSize(24);
    playerPuntajeTexto.setFillColor(sf::Color::White);
    playerPuntajeTexto.setPosition(1050, 130);

    const float tiempoLimite = 40.0f;
    int segundos=0;
    int segundosactivacionmapa=0;
    int tiempoactivacionmapa=0;
    bool booldeniebla=false;

    sf::Text _vidaTexto;
    _vidaTexto.setFont(font);
    _vidaTexto.setCharacterSize(24);
    _vidaTexto.setFillColor(sf::Color::White);
    _vidaTexto.setPosition(1050, 10);

    sf::Texture   _texturaFondo;
    _texturaFondo.loadFromFile("pictures/fondo_grass4.png");
    sf::Sprite spriteFondo(_texturaFondo);

    musica.stop();
    musica2.stop();
    sf::Music musicapartida;
    musicapartida.openFromFile("musica/gametheme2.ogg");
    musicapartida.setLoop(false);
    musicapartida.setVolume(confi.getvolumenPartida());
    musicapartida.play();

    soundganaste.setVolume(confi.getvolumenPartida());
    soundperdiste.setVolume(confi.getvolumenPartida());

    bool juegoActivo = true;

    while (window.isOpen() && juegoActivo)
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            if(event.key.code == Keyboard::Escape)         // ver si lo dejamos aca, salis al menu en cualquier momento de la partida
            {
                window.close();
                musicapartida.stop();
                musica.play();

                jugar(musica,confi,musica2);
                menu.setSelected(0);
                menu.setPagenum(1000);
            }
        }

        jugador.update(maze, fog, segundos, booldeniebla);

        fog.update(jugador, maze);

        if (jugador.isCollision(minot))
        {
            jugador.setVida(0);
        }

        if (jugador.getVida() == 0)
        {
               musicapartida.stop();
            sf::Text gameOverText("Game Over", font, 50);
            gameOverText.setFillColor(sf::Color::Red);
            gameOverText.setPosition(window.getSize().x / 2 - gameOverText.getGlobalBounds().width / 2,
                                     window.getSize().y / 2 - gameOverText.getGlobalBounds().height / 2);

            window.clear();
            musicapartida.stop();

            soundperdiste.play();

            window.draw(gameOverText);
            window.display();
            sf::sleep(sf::seconds(3));
            juegoActivo = false;

                musica.play();
            menu.setSelected(0);
            menu.setPagenum(1000); // Cambiar _pagenum para evitar reiniciar el juego automáticamente
        }

        if (jugador.getSalida() == true)
        {

            if (player.getDni() != 0)//si es 0 es porque no esta registrado, no suma puntos
            {
                player.getPuntaje();
                player.incrementarPuntaje(10); //  puntaje cuando llega a la salida
                //std::cout << "Puntaje actual: " << player.getPuntaje() << std::endl;

                JugadorArchivo pa;
                int pos = pa.buscar(player.getDni()); // busca de nuevo al jugador por DNI

                if (pos != -1)
                {
                    pa.guardar(pos, player); // guarda puntaje actualizado
                }

            }


            sf::Text ganaste("GaNaStE", font, 50);
            ganaste.setFillColor(sf::Color::Red);
            ganaste.setPosition(window.getSize().x / 2 - ganaste.getGlobalBounds().width / 2,
                                window.getSize().y / 2 - ganaste.getGlobalBounds().height / 2);




             musicapartida.stop();

            soundganaste.play();

            window.clear();
            window.draw(ganaste);
            window.display();
            sf::sleep(sf::seconds(3));
             musica.play();
            juegoActivo = false;
            menu.setSelected(0);
            menu.setPagenum(1000); // Cambiar _pagenum para evitar reiniciar el juego automáticamente
        }

        sf::Time tiempoTranscurrido = cronometro.getElapsedTime();
        int tiempoRestante = static_cast<int>(tiempoLimite - tiempoTranscurrido.asSeconds()) + segundos;

        if (booldeniebla)
        {
            booldeniebla = false;
            tiempoactivacionmapa = tiempoRestante - 2;
        }
        if (tiempoRestante == tiempoactivacionmapa)
        {
            fog.restaurarniebla();
        }

        if (tiempoRestante <= 0)
        {
              musicapartida.stop();
              soundperdiste.play();
            sf::Text tiempoText("Te quedaste sin tiempo - Game Over", font, 50);
            tiempoText.setFillColor(sf::Color::Red);
            tiempoText.setPosition(window.getSize().x / 2 - tiempoText.getGlobalBounds().width / 2,
                                   window.getSize().y / 2 - tiempoText.getGlobalBounds().height / 2);


            window.clear();
            window.draw(tiempoText);
            window.display();
            sf::sleep(sf::seconds(3));
            juegoActivo = false;
            menu.setSelected(0);
            menu.setPagenum(1000); // se cambio esto, era lo que loopeaba

             musica.play();
        }

        window.clear();
        window.draw(spriteFondo);
        maze.mostrarLaberinto(window);
        window.draw(jugador);
        window.draw(minot);
        window.draw(fog, sf::BlendMultiply);

        cronometroTexto.setString("Tiempo: " + std::to_string(tiempoRestante));
        window.draw(cronometroTexto);
        _vidaTexto.setString("Vida: " + std::to_string(static_cast<int>(jugador.getVida())) + "%");
        window.draw(_vidaTexto);


        window.draw(playerDniTexto);
        window.draw(playerNombreTexto);
        window.draw(playerPuntajeTexto);

        playerDniTexto.setString("DNI: " + std::to_string(player.getDni()));
        playerNombreTexto.setString("Nombre: " + player.getNombre());
        playerPuntajeTexto.setString("Puntaje: " + std::to_string(player.getPuntaje()));




        window.display();
    }
}



void GamePlay::historia(RenderWindow& window, sf::Music& musica,Configuracion& confi,Music& musica2)
{

    Menu menu(800,700);
    Texture background;
    background.loadFromFile("imagen/fondo3.png");
    Sprite bg;
    bg.setTexture(background);
    Font font;
    Font font1;
    font.loadFromFile("fonts/grec.ttf");
    font1.loadFromFile("fonts/Albe.otf");
    Text t1;
    Text volver;
    Text historia;
    t1.setFont(font);
    historia.setFont(font1);
    t1.setString("Historia");
    t1.setFillColor(Color::White);
    t1.setCharacterSize(70);
    t1.setPosition(530,150);

    volver.setString("Presione Escape para volver al menu principal");
    volver.setCharacterSize(40);
    volver.setPosition(325,800);
    volver.setFont(font);
    volver.setFillColor(Color::White);

    historia.setFont(font1);
    historia.setString("                                              La Leyenda del Laberinto del Minotauro \n En una tierra lejana, existía un antiguo reino llamado Cretonia. Este reino, conocido por su riqueza y prosperidad, escondía un oscuro secreto: \n un laberinto místico y peligroso, creado por los antiguos dioses como prueba para los más valientes.\n Cuenta la leyenda que aquel que consiga escapar del laberinto en el tiempo determinado demostrara ser el verdadero heroe de Cretonia, \n capaz de enfrentar cualquier desafio. Sin embargo, la tarea no es sencilla. \n El laberinto cambia constantemente de forma, creando nuevos pasadizos y trampas en cada intento. Nadie ha logrado descifrar el misterio que \n mantiene sus secretos seguros. \n                                                               El desafio \n Eres un valiente heroe, elegido por la reina de Cretonia, que ha decidido aventurarse en el laberinto. El camino esta lleno de desafios mortales y \n misterios ocultos. En tu travesia, encontraras diversos objetos: relojes magicos que pueden añadir o restar tiempo a tu cuenta, pociones de vida \n que te ayudaran a resistir los peligros y trampas traicioneras que podrian disminuir tu vitalidad. Ademas, tendras un radio de vision reducido \n que puedes ampliar o reducir dependiendo de los objetos que encuentres, simbolizados por ojos magicos: un ojo para ampliar y un ojo tachado \n para reducir tu vision. \n                                                        El guardian del laberinto \n El minotauro, una feroz bestia mitad hombre mitad toro, ronda las oscuras galerías del laberinto. Con ojos llenos de furia y fuerza descomunal, \n el minotauro es el guardián final del laberinto. Si te cruzas en su camino y te atrapa, perderas la partida y seras expulsado del laberinto, \n condenado a repetir el intento. \n                                                              El reto eterno \n Cada vez que te adentres en el laberinto, éste se reorganizará aleatoriamente, garantizando que ningún mapa sea igual al anterior. Con cada \n intento, enfrentarás nuevos desafíos y oportunidades para demostrar tu ingenio, valentía y habilidad.");

    historia.setFillColor(Color::White);
    historia.setCharacterSize(20);
    historia.setPosition(125,300);

    while(window.isOpen())
    {
        Event event;
        while(window.pollEvent(event))
        {


            //Event event;
            if(event.type==Event::Closed)
            {
                window.close();
                break;
            }
            if(event.key.code == Keyboard::Escape)
            {
                window.close();
                jugar(musica,confi,musica2);
                menu.setSelected(0);
                menu.setPagenum(1000);
            }

        }

           if (musica.getDuration().asMilliseconds() - musica.getPlayingOffset().asMilliseconds() <= 50){

              musica2.play();

            }

        window.clear();
        window.draw(bg);
        window.draw(t1);
        window.draw(historia);
        window.draw(volver);
        window.display();
    }

}


void GamePlay::updateText(sf::Text& text, const std::string& label, float volume) {
    text.setString(label + ": " + std::to_string(static_cast<int>(volume)) );
}

void GamePlay::configuracion(RenderWindow& window, sf::Music& musica,Configuracion& config,Music& musica2)
{
    Menu menu(800, 700);
    Texture background;
    background.loadFromFile("imagen/fondo3.png");
    Sprite bg;
    bg.setTexture(background);
    Font font;
    font.loadFromFile("fonts/grec.ttf");

      window.setFramerateLimit(60);

    sf::Text title("Configuración de Volumen", font, 70);
    title.setPosition(325, 50);
    title.setFillColor(Color{255,204,0});

    sf::Text instrucion("", font, 40);
    instrucion.setString("Utilice las flechas de arriba y abajo para navegar las opciones,\ny precione las teclas restar o sumar para modificar el volumen deseado.");
    instrucion.setPosition(100, 150);

    sf::Text generalVolumeText("", font, 44);
    generalVolumeText.setPosition(100, 350);
    generalVolumeText.setFillColor(Color{255,204,0});


    sf::Text gameVolumeText("", font, 44);
    gameVolumeText.setPosition(100, 450);

    sf::Text exitText("Presione Esc para salir", font, 40);
    exitText.setPosition(100, 650);

    updateText(generalVolumeText, "Volumen General", config.getvolumenMainTheme());
    updateText(gameVolumeText, "Volumen de Partida", config.getvolumenPartida());

    int selectedOption = 1;  // 1 = Volumen General, 2 = Volumen de Partida

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if(event.type==Event::Closed)
            {
                window.close();
                break;
            }
            if(event.key.code == Keyboard::Escape)
            {
                window.close();
                jugar(musica,config,musica2);
                menu.setSelected(0);
                menu.setPagenum(1000);
            }



            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Up) {
                    selectedOption = 1;
                    generalVolumeText.setFillColor(Color{255,204,0});
                    gameVolumeText.setFillColor(Color::White);
                } else if (event.key.code == sf::Keyboard::Down) {
                    selectedOption = 2;
                    generalVolumeText.setFillColor(Color::White);
                    gameVolumeText.setFillColor(Color{255,204,0});
                } else if (event.key.code == sf::Keyboard::Return) {
                    // Escoger ajuste
                    std::cout << "Seleccionada opción: " << selectedOption << std::endl;
                } else if (event.key.code == sf::Keyboard::Subtract) {
                    if (selectedOption == 1 && config.getvolumenMainTheme() != 0) {
                        config.setvolumenMainTheme(config.getvolumenMainTheme()-1);
                        musica.setVolume(config.getvolumenMainTheme());
                        musica2.setVolume(config.getvolumenMainTheme());
                    } else if (selectedOption == 2 && config.getvolumenPartida() != 0) {
                        config.setvolumenPartida(config.getvolumenPartida()-1);
                    }
                    updateText(generalVolumeText, "Volumen General", config.getvolumenMainTheme());
                    updateText(gameVolumeText, "Volumen de Partida", config.getvolumenPartida());
                } else if (event.key.code == sf::Keyboard::Add) {
                    if (selectedOption == 1 && config.getvolumenMainTheme() != 100) {
                       config.setvolumenMainTheme(config.getvolumenMainTheme()+1);
                       musica.setVolume(config.getvolumenMainTheme());
                       musica2.setVolume(config.getvolumenMainTheme());
                    } else if (selectedOption == 2 && config.getvolumenPartida() !=100) {
                        config.setvolumenPartida(config.getvolumenPartida()+1);
                    }
                    updateText(generalVolumeText, "Volumen General", config.getvolumenMainTheme());
                    updateText(gameVolumeText, "Volumen de Partida", config.getvolumenPartida());
                }
            }
        }
           if (musica.getDuration().asMilliseconds() - musica.getPlayingOffset().asMilliseconds() <= 50){

              musica2.play();

            }

        window.clear();
        window.draw(bg);
        window.draw(title);
        window.draw(instrucion);
        window.draw(generalVolumeText);
        window.draw(gameVolumeText);
        window.draw(exitText);
        window.display();
    }




}

void GamePlay::creditos(RenderWindow& window, sf::Music& musica,Configuracion& confi,Music& musica2)
{
    // Configuración inicial
    Menu menu(800, 700);
    Texture background;
    background.loadFromFile("imagen/fondo2.png");
    Sprite bg;
    bg.setTexture(background);
    Font font;
    Font font2;
    font.loadFromFile("fonts/Albe.otf");
    font2.loadFromFile("fonts/Albe.otf");

    // Título de los créditos
    Text titulo;
    Text volver;
    titulo.setFont(font2);
    titulo.setString("Creditos");
    titulo.setCharacterSize(70);
    titulo.setFillColor(Color::White);
    titulo.setPosition(550, 150);


    volver.setString("Presione Esc para volver al menu principal");
    volver.setCharacterSize(40);
    volver.setPosition(325,775);

    volver.setFont(font2);
    volver.setFillColor(Color::White);

    // Nombres de los creadores

    Text creador1;
    creador1.setFont(font);
    creador1.setString("- Tamashiro Alexander");
    creador1.setCharacterSize(60);
    creador1.setFillColor(Color::White);
    creador1.setPosition(350, 250);

    Text creador2;
    creador2.setFont(font);
    creador2.setString("- Dichiera Ludmila");
    creador2.setCharacterSize(60);
    creador2.setFillColor(Color::White);
    creador2.setPosition(350, 350);

    Text creador3;
    creador3.setFont(font);
    creador3.setString("- Viscito Nahuel Martin");
    creador3.setCharacterSize(60);
    creador3.setFillColor(Color::White);
    creador3.setPosition(350, 450);

    Text creador4;
    creador4.setFont(font);
    creador4.setString("- Michilini Aureliano");
    creador4.setCharacterSize(60);
    creador4.setFillColor(Color::White);
    creador4.setPosition(350, 550);

    Text musicalizacion;
    musicalizacion.setFont(font);
    musicalizacion.setString("- Banda sonora: Axel Caino");

    musicalizacion.setCharacterSize(60);
    musicalizacion.setFillColor(Color::White);
    musicalizacion.setPosition(350, 650);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
                break;
            }
            if (event.key.code == Keyboard::Escape)
            {
                window.close();
                jugar(musica,confi,musica2);
                menu.setSelected(0);
                menu.setPagenum(1000);
            }
        }
           if (musica.getDuration().asMilliseconds() - musica.getPlayingOffset().asMilliseconds() <= 50){

              musica2.play();

            }



        window.clear();
        window.draw(bg);
        window.draw(titulo);
        window.draw(volver);
        window.draw(creador1);
        window.draw(creador2);
        window.draw(creador3);
        window.draw(creador4);
        window.draw(musicalizacion);
        window.display();
    }
}

void GamePlay::estadisticas(RenderWindow& window, sf::Music& musica,Configuracion& confi,Music& musica2)
{
        Menu menu(800, 700);
    Texture background;
    background.loadFromFile("imagen/fondo3.png");
    Sprite bg;
    bg.setTexture(background);
    Font font;
    if (!font.loadFromFile("fonts/grec.ttf")) {
        std::cerr << "Error al cargar la fuente." << std::endl;
        return;
    }

    Text t1;
    Text volver;
    t1.setFont(font);
    t1.setString("Estadisticas - Top 5");
    t1.setFillColor(Color{255,204,0});
    t1.setCharacterSize(70);
    t1.setPosition(525, 50);
    volver.setFont(font);
    volver.setString("Presione Escape para volver al menú principal");
    volver.setFillColor(Color{255,204,0});
    volver.setCharacterSize(40);
    volver.setPosition(325, 800);

    JugadorArchivo pa;
    Jugador *players;
    int cantidad = pa.getCantidad();
    players = new Jugador[cantidad];
    pa.leerTodos(players, cantidad);

    // Ordenamiento por burbujeo
    for (int i = 0; i < cantidad; i++)
    {
        for (int j = 0; j < cantidad - 1; j++)
        {
            if (players[j].getPuntaje() < players[j + 1].getPuntaje())
            {
                Jugador aux = players[j + 1];
                players[j + 1] = players[j];
                players[j] = aux;
            }
        }
    }

    // clase de SFML "Text" crea array de texto para mostrar las estadísticas de los jugadores
    Text arrayEstadisticaJugador[15];  //  10 jugadores (3 textos por jugador)
    int indexJugador = 0;
    int jugadoresMostrados = 0;


    for (int i = 0; i < cantidad && jugadoresMostrados < 5; i++)    // si bien mostramos 5 jugadores en caso que tengamos menos es necesario limitar el
    {                                                                // ciclo a la cantidad que existen
     const int baseX = 100;  // Posición inicial en X
    const int baseY = 200;  // Posición inicial en Y
    const int espacioX = 350;  // Espacio horizontal ajustado para tamaño de carácter 40
    const int espacioY = 100;  // Espacio vertical entre filas para mejor visibilidad
    if (!players[i].getEliminado()){
    // Dni
    arrayEstadisticaJugador[indexJugador].setFont(font);
    arrayEstadisticaJugador[indexJugador].setCharacterSize(40);  // Tamaño del carácter ajustado
    arrayEstadisticaJugador[indexJugador].setFillColor(sf::Color::White);
    arrayEstadisticaJugador[indexJugador].setPosition(baseX, baseY + jugadoresMostrados * espacioY);
    arrayEstadisticaJugador[indexJugador].setString("Dni: " + std::to_string(players[i].getDni()));
    indexJugador++;

    // Nombre
    arrayEstadisticaJugador[indexJugador].setFont(font);
    arrayEstadisticaJugador[indexJugador].setCharacterSize(40);
    arrayEstadisticaJugador[indexJugador].setFillColor(sf::Color::White);
    arrayEstadisticaJugador[indexJugador].setPosition(baseX + espacioX, baseY + jugadoresMostrados * espacioY);
    arrayEstadisticaJugador[indexJugador].setString("Nombre: " + players[i].getNombre());
    indexJugador++;

    // Puntaje
    arrayEstadisticaJugador[indexJugador].setFont(font);
    arrayEstadisticaJugador[indexJugador].setCharacterSize(40);
    arrayEstadisticaJugador[indexJugador].setFillColor(sf::Color::White);
    arrayEstadisticaJugador[indexJugador].setPosition(baseX + 2 * espacioX, baseY + jugadoresMostrados * espacioY);
    arrayEstadisticaJugador[indexJugador].setString("Puntaje: " + std::to_string(players[i].getPuntaje()));
    indexJugador++;

    jugadoresMostrados++;
    }
     }
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }
            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
            {
                window.close();
                jugar(musica, confi,musica2);
                menu.setSelected(0);
                menu.setPagenum(1000);
                return;
            }
        }
           if (musica.getDuration().asMilliseconds() - musica.getPlayingOffset().asMilliseconds() <= 50){

              musica2.play();

            }


        window.clear();
        window.draw(bg);
        window.draw(t1);
        window.draw(volver);

        // Dibujar las estadísticas de los jugadores
        for (int i = 0; i < indexJugador; i++)
        {
            window.draw(arrayEstadisticaJugador[i]);
        }

        window.display();
    }

    delete[] players;

}

//*******************************************************************************


void GamePlay::jugador(RenderWindow& window, sf::Music& musica,Configuracion& confi,Music& musica2)
{
    Funciones funciones;
    Jugador jugador;

    Menu menu(800, 700);
    Texture background;
    background.loadFromFile("imagen/fondo3.png");
    Sprite bg;
    bg.setTexture(background);
    Font font;
    font.loadFromFile("fonts/grec.ttf");
    Text jugad;
    Text agregar;
    Text borrar;
    Text mostrar;
    Text volver;

    jugad.setFont(font);
    jugad.setString("JUGADOR");
    jugad.setFillColor(Color{255,204,0});
    jugad.setCharacterSize(70);
    jugad.setPosition(600,150);

    agregar.setFont(font);
    agregar.setString("Agregar jugador");
    agregar.setFillColor(sf::Color::White);
    agregar.setCharacterSize(60);
    agregar.setPosition(200,250);

    borrar.setFont(font);
    borrar.setString("Borrar jugador");
    borrar.setFillColor(sf::Color::White);
    borrar.setCharacterSize(60);
    borrar.setPosition(200,400);

    mostrar.setFont(font);
    mostrar.setString("Mostrar jugador");
    mostrar.setFillColor(sf::Color::White);
    mostrar.setCharacterSize(60);
    mostrar.setPosition(200,550);

    volver.setString("Presione Escape para volver al menu principal");
    volver.setCharacterSize(40);
    volver.setPosition(325,800);
    volver.setFont(font);
    volver.setFillColor(Color{255,204,0});

    int opc = 0; // Controlador para la opción seleccionada

    // Bucle para mostrar el submenú
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if(event.key.code == Keyboard::Escape)
            {
                window.close();
                jugar(musica,confi,musica2);
                menu.setSelected(0);
                menu.setPagenum(1000);
            }

            // Navegar entre las opciones con las flechas
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Down) {
                    if (opc < 2) {
                        opc++;  // Mover hacia abajo
                    }
                }
                if (event.key.code == sf::Keyboard::Up) {
                    if (opc > 0) {
                        opc--;  // Mover hacia arriba
                    }
                }

                // Si se presiona "Enter", ejecutar la opción seleccionada
                if (event.key.code == sf::Keyboard::Return) {
                    window.close();
                    if (opc == 0) { // Agregar jugador
                       agregJugador(musica,confi,musica2);

                        return;  // Salir del bucle

                    } else if (opc == 1) { // Borrar jugador
                         elimJugador(musica,confi,musica2);


                        return;  // Salir del bucle

                    } else if (opc == 2) { // Mostrar
                        mostJugador(musica,confi,musica2);


                        return;  // Salir del bucle
                    }
                }
            }
        }
           if (musica.getDuration().asMilliseconds() - musica.getPlayingOffset().asMilliseconds() <= 50){

              musica2.play();

            }


        // Limpiar la ventana
        window.clear();

        // Resaltar la opción seleccionada
        if (opc == 0) {
            agregar.setFillColor(sf::Color::Yellow); // Opción seleccionada
            borrar.setFillColor(sf::Color::White);  // Opción  no seleccionada
            mostrar.setFillColor(sf::Color::White);  // Opción  no seleccionada
        } else if (opc == 1) {
            agregar.setFillColor(sf::Color::White);  // Opción  no seleccionada
            borrar.setFillColor(sf::Color::Yellow); // Opción  seleccionada
            mostrar.setFillColor(sf::Color::White); // Opción  seleccionada
        } else if (opc == 2) {
            agregar.setFillColor(sf::Color::White);  // Opción  no seleccionada
            borrar.setFillColor(sf::Color::White); // Opción  seleccionada
            mostrar.setFillColor(sf::Color::Yellow); // Opción  seleccionada
        }


        window.clear();
        window.draw(bg);
        window.draw(jugad);
        window.draw(agregar);
        window.draw(borrar);
        window.draw(mostrar);
        window.draw(volver);
        window.display();
    }

}

void GamePlay::agregJugador(sf::Music& musica, Configuracion& confi,Music& musica2)
{
    Menu menu(800, 700);
    Texture background;
    background.loadFromFile("imagen/fondo3.png");
    Sprite bg;
    bg.setTexture(background);
    Font font;
    font.loadFromFile("fonts/grec.ttf");
    Text t1;
    Text volver;
    Text dniText;
    Text nombreText;
    Text feedback;
    std::string dniStr = "";
    std::string nombreStr = "";
    bool enterDni = true;

    t1.setFont(font);
    t1.setString("Agregar Jugador");
    t1.setFillColor(sf::Color{255, 204, 0});
    t1.setCharacterSize(70);
    t1.setPosition(525, 150);

    volver.setString("Presione Escape para volver al menu principal");
    volver.setCharacterSize(40);
    volver.setPosition(325, 800);
    volver.setFont(font);
    volver.setFillColor(sf::Color{255, 204, 0});

    dniText.setFont(font);
    dniText.setCharacterSize(40);
    dniText.setFillColor(sf::Color::White);
    dniText.setPosition(500, 300);
    dniText.setString("Ingrese DNI: " + dniStr);

    nombreText.setFont(font);
    nombreText.setCharacterSize(40);
    nombreText.setFillColor(sf::Color::White);
    nombreText.setPosition(500, 400);
    nombreText.setString("Ingrese Nombre: " + nombreStr);

    feedback.setFont(font);
    feedback.setCharacterSize(30);
    feedback.setFillColor(sf::Color::Green);
    feedback.setPosition(500, 600);

    sf::RenderWindow window(sf::VideoMode(1500, 1050), "Game");
    window.setFramerateLimit(30);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
                break;
            }
            if (event.key.code == sf::Keyboard::Escape)
            {
                window.close();
                jugar(musica, confi,musica2);
                menu.setSelected(5);
                menu.setPagenum(5);
            }
            if (event.type == sf::Event::TextEntered)
            {
                if (enterDni)
                {
                    if (event.text.unicode >= '0' && event.text.unicode <= '9')
                    {
                        dniStr += static_cast<char>(event.text.unicode);
                    }
                    else if (event.text.unicode == 8 && !dniStr.empty()) // Backspace
                    {
                        dniStr.pop_back();
                    }
                }
                else
                {
                    if (event.text.unicode >= 32 && event.text.unicode <= 126)
                    {
                        nombreStr += static_cast<char>(event.text.unicode);
                    }
                    else if (event.text.unicode == 8 && !nombreStr.empty()) // Backspace
                    {
                        nombreStr.pop_back();
                    }
                }
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)
            {
                if (enterDni)
                {
                    if (!dniStr.empty())
                    {
                        enterDni = false;
                    }
                    else
                    {
                        feedback.setString("El DNI no puede estar vacío.");
                    }
                }
                else
                {
                    if (!nombreStr.empty())
                    {
                        JugadorArchivo pa;
                        int dni = std::stoi(dniStr);
                        int pos = pa.buscar(dni);

                        if (pos != -1)
                        {
                            feedback.setString("El jugador ya esta registrado.");
                        }
                        else
                        {
                            Jugador p(dni, 0, nombreStr);
                            if (pa.guardar(p))
                            {
                                feedback.setString("Jugador guardado con exito!");
                            }
                            else
                            {
                                feedback.setString("No se pudo guardar el jugador.");
                            }
                        }
                        enterDni = true;
                        dniStr = "";
                        nombreStr = "";
                    }
                    else
                    {
                        feedback.setString("El nombre no puede estar vacío.");
                    }
                }
            }
        }

          if (musica.getDuration().asMilliseconds() - musica.getPlayingOffset().asMilliseconds() <= 50){

              musica2.play();

            }

        dniText.setString("Ingrese DNI: " + dniStr);
        nombreText.setString("Ingrese Nombre: " + nombreStr);

        window.clear();
        window.draw(bg);
        window.draw(t1);
        window.draw(volver);
        window.draw(dniText);
        window.draw(nombreText);
        window.draw(feedback);
        window.display();
    }
}

void GamePlay::elimJugador(sf::Music& musica, Configuracion& confi,Music& musica2)
{
    Menu menu(800, 700);
    Texture background;
    background.loadFromFile("imagen/fondo3.png");
    Sprite bg;
    bg.setTexture(background);
    Font font;
    font.loadFromFile("fonts/grec.ttf");
    Text t1;
    Text volver;
    Text dniText;
    Text feedback;
    std::string dniStr = "";
    bool enterDni = true;

    t1.setFont(font);
    t1.setString("Eliminar Jugador");
    t1.setFillColor(sf::Color{255, 204, 0});
    t1.setCharacterSize(70);
    t1.setPosition(525, 150);

    volver.setString("Presione Escape para volver al menu principal");
    volver.setCharacterSize(40);
    volver.setPosition(325, 800);
    volver.setFont(font);
    volver.setFillColor(sf::Color{255, 204, 0});

    dniText.setFont(font);
    dniText.setCharacterSize(40);
    dniText.setFillColor(sf::Color::White);
    dniText.setPosition(500, 300);
    dniText.setString("Ingrese DNI: " + dniStr);

    feedback.setFont(font);
    feedback.setCharacterSize(30);
    feedback.setFillColor(sf::Color::Green);
    feedback.setPosition(500, 500);

    sf::RenderWindow window(sf::VideoMode(1500, 1050), "Game");
    window.setFramerateLimit(30);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
                break;
            }
            if (event.key.code == sf::Keyboard::Escape)
            {
                window.close();
                jugar(musica, confi,musica2);
                menu.setSelected(5);
                menu.setPagenum(5);
            }
            if (event.type == sf::Event::TextEntered)
            {
                if (enterDni)
                {
                    if (event.text.unicode >= '0' && event.text.unicode <= '9')
                    {
                        dniStr += static_cast<char>(event.text.unicode);
                    }
                    else if (event.text.unicode == 8 && !dniStr.empty()) // Backspace
                    {
                        dniStr.pop_back();
                    }
                }
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)
            {
                if (!dniStr.empty())
                {
                    JugadorArchivo pa;
                    int dni = std::stoi(dniStr);
                    int pos = pa.buscar(dni);

                    if (pos != -1)
                    {
                        Jugador p = pa.leer(pos);
                        p.setEliminado(true);

                        if (pa.guardar(pos, p))
                        {
                            feedback.setString("El jugador ha sido eliminado.");
                        }
                        else
                        {
                            feedback.setString("No se pudo eliminar el jugador.");
                        }
                    }
                    else
                    {
                        feedback.setString("El jugador no se encuentra en el sistema.");
                    }
                    dniStr = "";
                }
                else
                {
                    feedback.setString("El DNI no puede estar vacío.");
                }
            }
        }
          if (musica.getDuration().asMilliseconds() - musica.getPlayingOffset().asMilliseconds() <= 50){

              musica2.play();

            }

        dniText.setString("Ingrese DNI: " + dniStr);

        window.clear();
        window.draw(bg);
        window.draw(t1);
        window.draw(volver);
        window.draw(dniText);
        window.draw(feedback);
        window.display();
    }
}

void GamePlay::mostJugador(sf::Music& musica, Configuracion& confi,Music& musica2)
{
    Menu menu(800, 700);
    Texture background;
    background.loadFromFile("imagen/fondo3.png");
    Sprite bg;
    bg.setTexture(background);
    Font font;
    font.loadFromFile("fonts/grec.ttf");
    Text t1;
    Text volver;
    Text dniText;
    Text jugadorInfo;
    std::string dniStr = "";
    bool enterDni = true;

    t1.setFont(font);
    t1.setString("Mostrar Jugador");
    t1.setFillColor(sf::Color{255, 204, 0});
    t1.setCharacterSize(70);
    t1.setPosition(525, 150);

    volver.setString("Presione Escape para volver al menu principal");
    volver.setCharacterSize(40);
    volver.setPosition(325, 800);
    volver.setFont(font);
    volver.setFillColor(sf::Color{255, 204, 0});

    dniText.setFont(font);
    dniText.setCharacterSize(40);
    dniText.setFillColor(sf::Color::White);
    dniText.setPosition(500, 300);
    dniText.setString("Ingrese DNI: " + dniStr);

    jugadorInfo.setFont(font);
    jugadorInfo.setCharacterSize(30);
    jugadorInfo.setFillColor(sf::Color::Green);
    jugadorInfo.setPosition(500, 500);

    sf::RenderWindow window(sf::VideoMode(1500, 1050), "Game");
    window.setFramerateLimit(30);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
                break;
            }
            if (event.key.code == sf::Keyboard::Escape)
            {
                window.close();
                jugar(musica, confi,musica2);
                menu.setSelected(5);
                menu.setPagenum(5);
            }
            if (event.type == sf::Event::TextEntered)
            {
                if (enterDni)
                {
                    if (event.text.unicode >= '0' && event.text.unicode <= '9')
                    {
                        dniStr += static_cast<char>(event.text.unicode);
                    }
                    else if (event.text.unicode == 8 && !dniStr.empty()) // Backspace
                    {
                        dniStr.pop_back();
                    }
                }
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)
            {
                if (!dniStr.empty())
                {
                    JugadorArchivo pa;
                    int dni = std::stoi(dniStr);
                    int pos = pa.buscar(dni);

                    if (pos != -1)
                    {
                        Jugador p = pa.leer(pos);
                        jugadorInfo.setString("Datos del jugador:\nDNI: " + std::to_string(p.getDni()) + "\nNombre: " + p.getNombre() + "\nPuntaje: " + std::to_string(p.getPuntaje()));
                    }
                    else
                    {
                        jugadorInfo.setString("El jugador no se encuentra en el sistema.");
                    }
                    dniStr = "";
                }
                else
                {
                    jugadorInfo.setString("El DNI no puede estar vacío.");
                }
            }
        }
          if (musica.getDuration().asMilliseconds() - musica.getPlayingOffset().asMilliseconds() <= 50){

              musica2.play();

            }

        dniText.setString("Ingrese DNI: " + dniStr);

        window.clear();
        window.draw(bg);
        window.draw(t1);
        window.draw(volver);
        window.draw(dniText);
        window.draw(jugadorInfo);
        window.display();
    }
}

//*******************************************************************************




GamePlay::~GamePlay()
{


}
