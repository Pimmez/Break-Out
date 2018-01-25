#pragma once

#ifndef HUD_H
#define HUD_H

#include <SFML/Graphics.hpp> //Required for variables with 'sf'
#include <iostream> //Required for use of std::cout, std::endl and more
#include <sstream> //Required for use of std::ostringstream and more

class HUD
{
public:
	HUD(); //Constructor
	~HUD(); //Destructor

	void AddScore(); //Method to add score
	void LoseLives(); //Method to lose lives
	void ResetAll(); //Resets the lives and scores.
	int GetPoints(); //Getter points
	int GetMaxPoints(); //Getter maxPoints
	int GetLives(); //Getter lives
	int GetMinLives(); //Getter minLives
	void DrawTo(sf::RenderWindow &window);  //Draws to the Window for rendering

private:
	int startPoints = 0; //The points you start with
	int increaseValue = 10; //increases the startPoints with this amount
	int maxPoints = 500; //Total points to get (500 = 50 Blocks * 10 points)
	int lives = 3; //The lives you start with
	int minLives = 0; //The minimun lives you can reach

	sf::Text textLives; //The lives displayed in the HUD
	sf::Text textPoints; //the points displayed in the HUD
	sf::Font font; //The Font
	std::ostringstream oStringLives, oStringPoints; //Stringstreams can be used to both read strings and write data into strings.
	sf::String loadFont = "fonts/opensans.ttf"; //String with the path to the .ttf
};

#endif //HUD_H