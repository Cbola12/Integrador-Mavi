#include "Juego.h"

#include <cstdlib>
#include <ctime>
#include "Enemigo.h"
#include "Crosshair.h"
#include <iostream>
#include "stdafx.h"


Juego::Juego() : window(sf::VideoMode(1024, 720), "Dragon shoot Z"), enemy (_enemigo, _aliado, posiciones) {

    

    Fuente.loadFromFile("SaiyanSans.ttf");

    tex_stage.loadFromFile("stage.png");
    stage.setTexture(tex_stage);

    

    
    _enemigo.loadFromFile("freezer.png");
    _aliado.loadFromFile("Krillin.png");

    // Pasa las texturas inicializadas a Enemigo
    enemy.setEnemigoTexture(_enemigo);
    enemy.setAliadoTexture(_aliado);

    //if (!tex_enemigo.loadFromFile("freezer.png") || !tex_aliado.loadFromFile("Krillin.png")) {
     //   std::cout << "Falta textura"; // Salir si hay un error al cargar alguna textura
   // }

   
  
    

    sf::Vector2u dimensionesStage = tex_stage.getSize();
    float escalaXstage = 1024.0f / dimensionesStage.x;
    float escalaYstage = 600.0f / dimensionesStage.y;
    stage.setScale(escalaXstage, escalaYstage);


    sf::Clock tiempoEnPantalla;
    float tiempoLimite = 5.5f;

     


   // srand(static_cast<unsigned int>(time(0)));
    //bool juegoIniciado = false;
    //bool juegoTerminado = false;
    //sf::Clock tiempoPantallaFinal;
    
}


void Juego::Loop() {

    


    while (window.isOpen()) {
        sf::Event evt;
        while (window.pollEvent(evt)) {
            // Eventos de la ventana principal
            if (evt.type == sf::Event::Closed) {
                window.close();
            }
            else if (evt.type == sf::Event::MouseMoved) {
                player.Posicionar(evt.mouseMove.x, evt.mouseMove.y);
            }
        }



        // Tiempo de exposición del enemigo en pantalla
        if (tiempoEnPantalla.getElapsedTime().asSeconds() > tiempoLimite) {
            if (enemy.getSprite().getTexture() == &_enemigo) {
                vidas--;
            }

            enemy.cambiarPosicionYTexturaAleatoria();
            tiempoEnPantalla.restart();
        }

        window.clear();
        
        window.draw(enemy.getSprite());
        std::cout << "Posición del sprite del enemigo: (" << enemy.getSprite().getPosition().x << ", " << enemy.getSprite().getPosition().y << ")" << std::endl;

        sf::Text textoVidas("Vidas: " + std::to_string(vidas), Fuente, 50);
        textoVidas.setPosition(20, 630);

        sf::Text textoEnemigoDerrotado("Enemigos Derrotados: " + std::to_string(enemigoDerrotado), Fuente, 50);
        textoEnemigoDerrotado.setPosition(300, 630);

        sf::Text textoPuntaje("Puntaje: " + std::to_string(puntos), Fuente, 50);
        textoPuntaje.setPosition(750, 630);

        window.draw(textoPuntaje);
        window.draw(textoVidas);
        window.draw(textoEnemigoDerrotado);

        player.Dibujar(window);

        window.display();

    }

}

        
        
