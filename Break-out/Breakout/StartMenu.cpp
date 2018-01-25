#include "StartMenu.h"

StartMenu::StartMenu() //Constructor, loads the texture & the font, also sets the menu items  
{
	if (!tMenuBackground.loadFromFile(loadFile))
	{
		std::cout << "Error loading <menuBackground texture> from file" << std::endl;
	}

	if (!font.loadFromFile(loadFont))
	{
		std::cout << "Error loading <opensans.ttf> from file" << std::endl;
	}

	sMenuBackground.setTexture(tMenuBackground);
	sMenuBackground.setPosition(0, 0);

	menuItems[0].setFont(font);
	menuItems[0].setCharacterSize(30);
	menuItems[0].setFillColor(sf::Color::Blue);
	menuItems[0].setString("Play");
	menuItems[0].setPosition(sf::Vector2f(screenWidth / (MAX_NUMBER_OF_ITEMS + 1) * 0.8, screenHeight / 2));

	menuItems[1].setFont(font);
	menuItems[1].setCharacterSize(30);
	menuItems[1].setFillColor(sf::Color::White);
	menuItems[1].setString("How To Play");
	menuItems[1].setPosition(sf::Vector2f(screenWidth / (MAX_NUMBER_OF_ITEMS + 1) * 1.5, screenHeight / 2));

	menuItems[2].setFont(font);
	menuItems[2].setCharacterSize(30);
	menuItems[2].setFillColor(sf::Color::White);
	menuItems[2].setString("Exit");
	menuItems[2].setPosition(sf::Vector2f(screenWidth / (MAX_NUMBER_OF_ITEMS + 1) * 2.8, screenHeight / 2));

	selectedItemIndex = 0;
}
StartMenu::~StartMenu()
{
	//Destructor
}

void StartMenu::MoveLeft() //Changes color depending on selectedItemIndex, also ciruclates through them
{
	menuItems[selectedItemIndex].setFillColor(sf::Color::White);
	selectedItemIndex = (selectedItemIndex - 1 + MAX_NUMBER_OF_ITEMS) % MAX_NUMBER_OF_ITEMS;
	menuItems[selectedItemIndex].setFillColor(sf::Color::Blue);
}

void StartMenu::MoveRight() //Changes color depending on selectedItemIndex, also ciruclates through them
{
	menuItems[selectedItemIndex].setFillColor(sf::Color::White);
	selectedItemIndex = (selectedItemIndex + 1) % MAX_NUMBER_OF_ITEMS;
	menuItems[selectedItemIndex].setFillColor(sf::Color::Blue);
}

int StartMenu::GetPressedItem() //Getter, returns an integer
{
	return selectedItemIndex;
}

void StartMenu::DrawTo(sf::RenderWindow &window) //Draws sprites to the window
{
	window.draw(sMenuBackground);
	
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menuItems[i]);
	}
}