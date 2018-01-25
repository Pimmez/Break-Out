#include "Ball.h"

Ball::Ball() //Constructor, Loads the ball texture and sets it to the ball sprite. Also sets the ball sprite to the correct position
{
	if (!tBall.loadFromFile(loadFile))
	{
		std::cout << "Error loading file <ball texture> from loadfile " << std::endl;
	}
	sBall.setTexture(tBall);
	sBall.setPosition(ballPosX, ballPosY);
}

Ball::~Ball()
{
	//Destructor
}

void Ball::ResetBall() //Stops the movement of the ball and sets the ball to a specific position
{
	SetBallDeltaX(0);
	SetBallDeltaY(0);
	SetBallPosX(500);
	SetBallPosY(475);
}

void Ball::SetBallBorders() //Makes sure that the ball stays between the screen borders
{
	if (ballPosX < 0 || ballPosX > screenWidth - ballWidth)
	{
		SetBallDeltaX(-deltaX);
	}
	if (ballPosY < 40)
	{
		SetBallDeltaY(-deltaY);
	}
}

float Ball::GetBallDeltaX() //Getter for deltaX
{
	return deltaX;
}

float Ball::GetBallDeltaY() //Getter for deltaY
{
	return deltaY;
}

void Ball::SetBallDeltaX(float n) //Setter for DeltaX (parameter float)
{
	deltaX = n;
}

void Ball::SetBallDeltaY(float n) //Setter for DeltaY (parameter float)
{
	deltaY = n;
}

float Ball::GetBallPosX() //Getter ballPosX
{
	return ballPosX;
}

float Ball::GetBallPosY() //Getter ballPosY
{
	return ballPosY;
}

void Ball::SetBallPosX(float n) //Setter ballPosX (parameter float)
{
	ballPosX = n;
}

void Ball::SetBallPosY(float n) //Setter ballPosY (parameter float)
{
	ballPosY = n;
}

void Ball::DrawTo(sf::RenderWindow &window) //Draws the sprite to the window
{
	window.draw(sBall);
}