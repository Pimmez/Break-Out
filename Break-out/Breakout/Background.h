#pragma once

#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <SFML/Graphics.hpp> //Required for variables with 'sf'
#include <iostream> //Required for use of std::cout, std::endl and more

class Background
{
public:
	Background(); //Constructor
	~Background(); //Destructor

	void DrawTo(sf::RenderWindow &window); //Draws to the Window for rendering

private:
	sf::Texture tBackground; //tBackground -> textureBackground
	sf::Sprite sBackground; //sBackground -> spriteBackground

	sf::String loadFile = "images/background.png"; //String with the path to the .png
};

#endif //BACKGROUND_H