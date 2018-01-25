#pragma once

#ifndef HOWTOPLAY_H
#define HOWTOPLAY_H

#define MAX_NUMBER_OF_ITEMS 2 //A constant value for the maximum number of menu items in the array

#include <SFML/Graphics.hpp> //Required for variables with 'sf'
#include <iostream> //Required for use of std::cout, std::endl and more

class HowToPlay
{
public:
	HowToPlay(); //Constructor
	~HowToPlay(); //Destructor

	void DrawTo(sf::RenderWindow &window); //Draws to the Window for rendering
	void MoveLeft(); //Method to circulate to the left
	void MoveRight(); //Method to circulate to  the right
	int GetPressedItem(); //Method to get the pressed menu item

private:
	int selectedItemIndex; //Int to check what number gets pressed
	int screenWidth = 1000; //The screen width
	int screenHeight = 500; //The screen Height

	sf::Text htpItems[MAX_NUMBER_OF_ITEMS]; //Array of texts, with the maximum number of menu items in it. (htpItems stands for HowToPlayItems)
	sf::Texture tHowToPlay; //tLoseState -> TextureLoseState
	sf::Sprite sHowToPlay; //sHowToPlay -> TextureHowToPlay
	sf::String loadfile = "images/howtoplay.png"; //String with the path to the .png
	sf::Font font; //Variable of font
	sf::String loadFont = "fonts/opensans.ttf"; //String with the path to the .ttf
};

#endif //!HOWTOPLAY_H