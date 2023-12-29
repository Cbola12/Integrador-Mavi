

#include <cstdlib>
#include <ctime>
#include "Enemigo.h"
#include "Crosshair.h"

#include <iostream>
#include "stdafx.h"
class Juego
{
public:

     Juego();
    void Loop();



private:

    Enemigo enemy;

    int vidas = 5;
    int puntos = 0;
    int enemigoDerrotado = 0;

    sf::Texture _enemigo;
    sf::Texture _aliado;

    sf::Vector2f posiciones[6] = {
      sf::Vector2f(300.0f, 310.0f), //arriba izquierda
      sf::Vector2f(400.0f, 535.0f), //abajo izquierda
      sf::Vector2f(480.0f, 565.0f), //puerta principal
      sf::Vector2f(480.0f, 300.0f), //balcon
      sf::Vector2f(830.0f, 535.0f), //abajo derecha
      sf::Vector2f(830.0f, 310.0f) //arriba derecha
    };

      


    sf::Font Fuente;

   

    sf::Texture tex_stage;
    sf::Sprite stage;
    float escalaXstage;
    float escalaYstage;

    

    

    crosshair player;
    sf::RenderWindow window;

    bool juegoIniciado = false;
    float tiempoLimite;

    sf::Clock tiempoEnPantalla;

    void Dibujar();
  


};