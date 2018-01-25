#include "Background.h"

Background::Background() //Constructor, Loads the background texture and sets it to the background sprite.
{
	if (!tBackground.loadFromFile(loadFile))
	{
		std::cout << "Error loading <background image> from file" << std::endl;
	}
	sBackground.setTexture(tBackground);
	sBackground.setPosition(0, 0);
}

Background::~Background()
{
	//Destructor
}

void Background::DrawTo(sf::RenderWindow &window) //Draws the sprite to the window.
{
	window.draw(sBackground);
}