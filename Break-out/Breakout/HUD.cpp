#include "HUD.h"

HUD::HUD() //Constructor, Sets strings with points and lives. also sets the position, the font, the size and color
{
	oStringLives << "Lives: " << lives;
	oStringPoints << "Points: " << startPoints;
	if (!font.loadFromFile(loadFont))
	{
		std::cout << "Error loading <opensans.ttf font> from file" << std::endl;
	}
	textLives.setFont(font);
	textLives.setString(oStringLives.str());
	textLives.setPosition(850, 10);
	textLives.setCharacterSize(20);
	textLives.setFillColor(sf::Color::Red);
	textLives.setStyle(sf::Text::Bold);

	textPoints.setFont(font);
	textPoints.setString(oStringPoints.str());
	textPoints.setPosition(50, 10);
	textPoints.setCharacterSize(20);
	textPoints.setFillColor(sf::Color::Red);
	textPoints.setStyle(sf::Text::Bold);
}

HUD::~HUD()
{
	//Destructor
}

void HUD::AddScore() //Add and updates score
{
	oStringPoints.str("");
	startPoints = startPoints + increaseValue;
	oStringPoints << "Points: " << startPoints;
	textPoints.setString(oStringPoints.str());
}

void HUD::LoseLives() //Decreases and updates lives
{
	oStringLives.str("");
	lives--;
	oStringLives << "Lives: " << lives;
	textLives.setString(oStringLives.str());
}

void HUD::ResetAll() //Resets the score and the lives back to the original values.
{
	oStringLives.str("");
	lives = 3;
	oStringLives << "Lives: " << lives;
	textLives.setString(oStringLives.str());

	oStringPoints.str("");
	startPoints = 0;
	oStringPoints << "Points: " << startPoints;
	textPoints.setString(oStringPoints.str());
}

int HUD::GetPoints() //Getter returns the startPoints
{
	return startPoints;
}

int HUD::GetMaxPoints() //Getter returns the maximumPoints
{
	return maxPoints;
}

int HUD::GetLives() //Getter returns the lives
{
	return lives;
}

int HUD::GetMinLives() //Getter returns the minimumLives
{
	return minLives;
}

void HUD::DrawTo(sf::RenderWindow &window) //Draws texts to the window
{
	window.draw(textLives);
	window.draw(textPoints);
}

