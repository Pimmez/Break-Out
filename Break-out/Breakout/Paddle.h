#pragma once

#ifndef PADDLE_H
#define PADDLE_H

#include <SFML/Graphics.hpp> //Required for variables with 'sf'
#include <iostream> //Required for use of std::cout, std::endl and more

class Paddle
{
public:
	Paddle(); //Constructor
	~Paddle(); //Destructor

	void MovePaddle(); //Handles Paddle Movement
	void SetPaddleBorders(); //Required to let the paddle stay between the borders
	void ResetPaddle(); //Resets the paddle
	void DrawTo(sf::RenderWindow &window); //Draws to the Window for rendering
	float GetPaddlePosX(); //Getter paddlePosX
	void SetPaddlePosition(float n); //Setter paddlePosition
	void SetPaddleMoveSpeed(float n); //Setter moveSpeed

	sf::Sprite sPaddle; //sPaddle -> SpritePaddle

private:
	sf::Texture tPaddle; //tPaddle -> TexturePaddle

	sf::Vector2f paddleXYValue; //Vector2float used for the update of the paddle boundary
	float moveSpeed = 8; //The movement speed of the paddle
	float paddlePosX = 460; //The paddle position on the X axis
	const float paddlePosY = 490; //The paddle position on the Y axis
	
	int GameWidth = 1000; //The GameWidth
	int paddleLenght = 90; //The length of the paddle in pixels

	sf::String loadFile = "images/paddle.png"; //String with the path to the .png
};

#endif //PADDLE_H