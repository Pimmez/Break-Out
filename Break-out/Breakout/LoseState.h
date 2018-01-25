#pragma once

#ifndef LOSESTATE_H
#define LOSESTATE_H

#include <SFML/Graphics.hpp> //Required for variables with 'sf'
#include <iostream> //Required for use of std::cout, std::endl and more

class LoseState
{
public:
	LoseState(); //Constructor
	~LoseState(); //Destructor

	void DrawTo(sf::RenderWindow &window); //Draws to the Window for rendering

private:
	sf::Texture tLoseState; //tLoseState -> TextureLoseState
	sf::Sprite sLoseState; //sLoseState -> SpriteLoseState

	sf::String loadFile = "images/losescreen.png"; //String with the path to the .png
};

#endif //!LOSESTATE_H
