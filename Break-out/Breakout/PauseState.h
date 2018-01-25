#pragma once

#ifndef PAUSESTATE_H
#define PAUSESTATE_H

#include <SFML/Graphics.hpp> //Required for variables with 'sf'
#include <iostream> //Required for use of std::cout, std::endl and more
#include <sstream> //Required for use of std::ostringstream and more

class PauseState
{
public:
	PauseState(); //Constructor
	~PauseState(); //Destructor

	void DrawTo(sf::RenderWindow &window); //Draws to the Window for rendering

private:
	sf::Text textPauseState; //The pauseState displayed in the window
	sf::Font font; //The Font

	std::ostringstream oStringPauseState; //Stringstreams can be used to both read strings and write data into strings.
	sf::String loadFont = "fonts/opensans.ttf"; //String with the path to the .ttf
};

#endif // !PAUSESTATE_H