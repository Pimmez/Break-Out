#include "WinState.h"

WinState::WinState() //Constructor, Loads the WinState texture and sets it to the WinState sprite.
{
	if (!tWinState.loadFromFile(loadFile))
	{
		std::cout << "Error loading <winState texture> From File" << std::endl;
	}
	sWinState.setTexture(tWinState);
	sWinState.setPosition(0, 0);
}

WinState::~WinState()
{
	//Destructor
}

void WinState::DrawTo(sf::RenderWindow &window) //Draws sprite to the window
{
	window.draw(sWinState);
}