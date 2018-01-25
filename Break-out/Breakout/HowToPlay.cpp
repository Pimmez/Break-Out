#include "HowToPlay.h"

HowToPlay::HowToPlay() //Constructor, loads the texture & the font, also sets the menu items 
{
	if (!tHowToPlay.loadFromFile(loadfile))
	{
		std::cout << "Error loading <HowToPlay texture> from file" << std::endl;
	}

	if (!font.loadFromFile(loadFont))
	{
		std::cout << "Error loading <opensans.ttf font> from file" << std::endl;
	}

	sHowToPlay.setTexture(tHowToPlay);
	sHowToPlay.setPosition(0, 0);

	htpItems[0].setFont(font);
	htpItems[0].setCharacterSize(30);
	htpItems[0].setFillColor(sf::Color::Blue);
	htpItems[0].setString("Start Game");
	htpItems[0].setPosition(sf::Vector2f(screenWidth / (MAX_NUMBER_OF_ITEMS + 1) * 0.5, 400));

	htpItems[1].setFont(font);
	htpItems[1].setCharacterSize(30);
	htpItems[1].setFillColor(sf::Color::White);
	htpItems[1].setString("Back");
	htpItems[1].setPosition(sf::Vector2f(screenWidth / (MAX_NUMBER_OF_ITEMS + 1) * 2, 400));

	selectedItemIndex = 0;
}

HowToPlay::~HowToPlay() 
{
	//Destructor
}

void HowToPlay::MoveLeft() //Changes color depending on selectedItemIndex, also ciruclates through them
{
	htpItems[selectedItemIndex].setFillColor(sf::Color::White);
	selectedItemIndex = (selectedItemIndex - 1 + MAX_NUMBER_OF_ITEMS) % MAX_NUMBER_OF_ITEMS;
	htpItems[selectedItemIndex].setFillColor(sf::Color::Blue);
}

void HowToPlay::MoveRight() //Changes color depending on selectedItemIndex, also ciruclates through them
{
	htpItems[selectedItemIndex].setFillColor(sf::Color::White);
	selectedItemIndex = (selectedItemIndex + 1) % MAX_NUMBER_OF_ITEMS;
	htpItems[selectedItemIndex].setFillColor(sf::Color::Blue);
}

int HowToPlay::GetPressedItem() //Getter, returns an integer
{
	return selectedItemIndex;
}

void HowToPlay::DrawTo(sf::RenderWindow &window) //Draws sprites to the window
{
	window.draw(sHowToPlay);

	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(htpItems[i]);
	}
}