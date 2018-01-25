#pragma once

#ifndef WINSTATE_H
#define WINSTATE_H

#include <SFML/Graphics.hpp> //Required for variables with 'sf'
#include <iostream> //Required for use of std::cout, std::endl and more

class WinState
{
public:
	WinState(); //Constructor
	~WinState(); //Destructor

	void DrawTo(sf::RenderWindow &window); //Draws to the Window for rendering

private:
	sf::Texture tWinState; //tWinState -> TextureWinState
	sf::Sprite sWinState; //sWinState -> SpriteWinState

	sf::String loadFile = "images/winscreen.png"; //String with the path to the .png
};

#endif //!WINSTATE_H