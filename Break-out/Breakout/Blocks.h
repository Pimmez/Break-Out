#pragma once

#ifndef BLOCKS_H
#define BLOCKS_H

#define MAX_NUMBER_OF_BLOCKS 50 //A constant value for the maximum number of blocks in the array

#include <SFML/Graphics.hpp> //Required for variables with 'sf'
#include <iostream> //Required for use of std::cout, std::endl and more

class Blocks
{
public:
	Blocks(); //Constructor
	~Blocks(); //Destructor

	void ResetAll(); //Resets All The Blockss
	void DrawTo(sf::RenderWindow &window); //Draws to the Window for rendering
	int GetNumber(); //Getter GetNumber

	sf::Sprite *sBlocks[MAX_NUMBER_OF_BLOCKS]; //sBlocks -> SpriteBlocks, made of an array
private:
	int arrayNumber = 0; //Total intergers in the array
	sf::Texture tBlocks; //tBlocks -> TextureBlocks
	const float rowX = 10; //How many blocks there need to be drawn on the X axis
	const float rowY = 5; //How many blocks there need to be drawn on the Y axis
	const float blockPosX = 85; //The X position of the blocks when rendered
	const float blockPosY = 60; //The Y position of the blocks when rendered

	sf::String loadFile = "images/block.png"; //String with the path to the .png
};

#endif //!BLOCKS_H