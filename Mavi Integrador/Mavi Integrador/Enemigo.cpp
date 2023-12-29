#include "Enemigo.h"
#include <cstdlib>
#include <iostream>



// Constructor de la clase Enemigo
Enemigo::Enemigo(sf::Texture& tex_enemigo, sf::Texture& tex_aliado, sf::Vector2f posiciones[])
	: tex_enemigo(tex_enemigo), tex_aliado(tex_aliado), posiciones(posiciones) {
	


	// Configurar la textura del enemigo
	sprite.setTexture(tex_enemigo);
	std::cout << "Enemigo creado con �xito." << std::endl;
	
	// Establecer la posici�n inicial aleatoria entre las posiciones disponibles
	sprite.setPosition(this->posiciones[rand() % 6]);
}
Enemigo::~Enemigo() {
	// Aqu� no hay nada espec�fico para liberar en este caso.
	// Si hay recursos que necesitan ser liberados, deber�as hacerlo aqu�.
}


// M�todo para cambiar la posici�n y la textura de manera aleatoria
void Enemigo::cambiarPosicionYTexturaAleatoria() {

	

	// Cambiar a una nueva posici�n aleatoria
	sprite.setPosition(posiciones[rand() % 6]);

	// Cambiar a una nueva textura aleatoria (enemigo o inocente)
	if (rand() % 2 == 0) {
		sprite.setTexture(tex_enemigo);
		std::cout << "Textura: Enemigo" << std::endl;
	}
	else {
		sprite.setTexture(tex_aliado);
		std::cout << "Textura: Aliado" << std::endl;
	}
}



// M�todo para obtener el sprite del enemigo/inocente
sf::Sprite Enemigo::getSprite() const {
	return sprite;
}


