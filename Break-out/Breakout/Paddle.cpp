#include "Paddle.h"

Paddle::Paddle() //Constructor, loads texture, sets texture and sets sprite position
{
	if (!tPaddle.loadFromFile(loadFile))
	{
		std::cout << "Error loading <paddle image> from file" << std::endl;
	}
	sPaddle.setTexture(tPaddle);
	sPaddle.setPosition(paddlePosX, paddlePosY);
}

Paddle::~Paddle()
{
	//Destructor
}

void Paddle::MovePaddle() //Uses the keyboard events to change the movement of the paddle
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		sPaddle.move(-moveSpeed, 0);
	}
	else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)))
	{
		sPaddle.move(moveSpeed, 0);
	}
}

void Paddle::SetPaddleBorders() //Sets the borders for the paddle 
{
	paddleXYValue = sPaddle.getPosition();
	paddlePosX = paddleXYValue.x;
	
	//Set Paddle within the boundary
	if (paddlePosX < 0)
		sPaddle.setPosition(0, paddlePosY);
	if (paddlePosX >= GameWidth - paddleLenght)
		sPaddle.setPosition(GameWidth - paddleLenght, paddlePosY);
}

void Paddle::ResetPaddle() //Resets the paddle to the original value
{
	SetPaddleMoveSpeed(0);
	SetPaddlePosition(460);
}

float Paddle::GetPaddlePosX() //Getter returns paddlePosX
{
	return paddlePosX;
}

void Paddle::SetPaddlePosition(float n) //Setter for the paddle position (parameter float)
{
	sPaddle.setPosition(n,paddlePosY);
}

void Paddle::SetPaddleMoveSpeed(float n) //Setter for the paddle movement speed (parameter float)
{
	moveSpeed = n;
}

void Paddle::DrawTo(sf::RenderWindow &window) //Draws sprite to the window
{
	window.draw(sPaddle);
}
