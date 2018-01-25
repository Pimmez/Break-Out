#pragma once

#ifndef STARTMENU_H
#define STARTMENU_H
 
#define MAX_NUMBER_OF_ITEMS 3 //Maximum Number Of Items In The Array

#include <SFML/Graphics.hpp> //Required for variables with 'sf'
#include <iostream> //Required for use of std::cout, std::endl and more

class StartMenu
{
public:
	StartMenu(); //Constructor
	~StartMenu(); //Destructor

	void DrawTo(sf::RenderWindow &window); //Draws to the Window for rendering
	void MoveLeft(); //Method to circulate to the left
	void MoveRight(); //Method to circulate to the right
	int GetPressedItem(); //Method to get the pressed menu item

private:
	int selectedItemIndex; //Int to check what number gets pressed
	int screenWidth = 1000; //The screen width
	int screenHeight = 500; //The screen Height
	
	sf::Texture tMenuBackground; //tMenu -> TextureMenu
	sf::Sprite sMenuBackground; //sMenu -> SpriteMenu

	sf::Font font; //Variable of font
	sf::String loadFile = "images/startmenu.png"; //String with the path to the .png
	sf::String loadFont = "fonts/opensans.ttf"; //String with the path to the .ttf
	sf::Text menuItems[MAX_NUMBER_OF_ITEMS]; //Array of texts, with the maximum number of menu items in it
};

#endif //!STARTMENU_H