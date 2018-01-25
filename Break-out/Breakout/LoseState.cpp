#include "LoseState.h"

LoseState::LoseState() //Constructor, Loads texture, sets texture and sets position of the sprite
{
	if (!tLoseState.loadFromFile(loadFile))
	{
		std::cout << "Error loading <tLoseState> from file" << std::endl;
	}

	sLoseState.setTexture(tLoseState);
	sLoseState.setPosition(0, 0);
}

LoseState::~LoseState()
{
	//Destructor
}

void LoseState::DrawTo(sf::RenderWindow &window) //Draws sprite to the window
{
	window.draw(sLoseState);
}