#pragma once
#include <SFML/Graphics.hpp>

class Enemigo {
public:
    
    Enemigo();
   
    // Constructor de la clase
    Enemigo(sf::Texture& tex_enemigo, sf::Texture& tex_aliado, sf::Vector2f posiciones[]);
    ~Enemigo();
    // Método para cambiar la posición y la textura de manera aleatoria
    void cambiarPosicionYTexturaAleatoria();

    void setEnemigoTexture(const sf::Texture& texture) {
        tex_enemigo = texture;
    }

    void setAliadoTexture(const sf::Texture& texture) {
        tex_aliado = texture;
    }

    sf::Vector2f getPosicion() const;

    // Método para obtener el sprite del enemigo/inocente
 sf::Sprite getSprite() const;

 

private:
    sf::Sprite sprite;
    sf::Vector2f* posiciones;
    sf::Texture& tex_enemigo;
    sf::Texture& tex_aliado;


    
};