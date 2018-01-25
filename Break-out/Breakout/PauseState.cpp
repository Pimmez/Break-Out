#include "PauseState.h"

PauseState::PauseState() //Constructor, Sets strings with points and lives. also sets the position, the font, the size and color
{
	oStringPauseState << "Game Paused";

	if (!font.loadFromFile(loadFont))
	{
		std::cout << "Error loading <opensans.ttf font> from file" << std::endl;
	}
	textPauseState.setFont(font);
	textPauseState.setString(oStringPauseState.str());
	textPauseState.setPosition(400, 200);
	textPauseState.setCharacterSize(30);
	textPauseState.setFillColor(sf::Color::White);
	textPauseState.setStyle(sf::Text::Bold);
}

PauseState::~PauseState()
{
	//Destructor
}

void PauseState::DrawTo(sf::RenderWindow &window) //Draws text to window
{
	window.draw(textPauseState);
}