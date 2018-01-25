#include "Blocks.h"

Blocks::Blocks() //Constructor, Loads texture and makes a new spritesheet for all the items in the sprite block array, also places the blocks in rows
{
	if (!tBlocks.loadFromFile(loadFile))
	{
		std::cout << "Error loading <block texture> from file" << std::endl;
	}

	for (int i = 0; i < MAX_NUMBER_OF_BLOCKS; i++)
	{
		sBlocks[i] = new sf::Sprite;
	}

	for (int i = 1; i <= rowX; i++)
		for (int j = 1; j <= rowY; j++)
		{
			sBlocks[arrayNumber]->setTexture(tBlocks);
			sBlocks[arrayNumber]->setPosition(i * blockPosX, j * blockPosY);
			arrayNumber++;
		}
}

Blocks::~Blocks()
{
	//Destructor
}

void Blocks::ResetAll() //Resets all the blocks back to their standard value
{
	arrayNumber = 0;
	for (int i = 1; i <= rowX; i++)
		for (int j = 1; j <= rowY; j++)
		{
			sBlocks[arrayNumber]->setTexture(tBlocks);
			sBlocks[arrayNumber]->setPosition(i * blockPosX, j * blockPosY);
			arrayNumber++;
		}
}

int Blocks::GetNumber() //Gets the Maximum number of blocks
{
	return MAX_NUMBER_OF_BLOCKS;
}

void Blocks::DrawTo(sf::RenderWindow &window) //Draws all the sprites to the window
{
	for (int i = 0; i < arrayNumber; i++)
	{
		window.draw(*sBlocks[i]);
	}
}