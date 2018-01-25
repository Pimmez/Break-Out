#pragma once

#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp> //Required for variables with 'sf'
#include <iostream> //Required for use of std::cout, std::endl and more

class Ball
{
public:
	Ball(); //Constructor
	~Ball(); //Destructor

	void ResetBall(); //Resets the ball position
	void SetBallBorders(); //Sets the borders for the ball
	void DrawTo(sf::RenderWindow &window); //Draws to the Window for rendering
	
	float GetBallDeltaX(); //Getter DeltaX
	float GetBallDeltaY(); //Getter DeltaY
	void SetBallDeltaX(float n); //Setter DeltaX
	void SetBallDeltaY(float n); //Setter DeltaY
	
	float GetBallPosX(); //Getter PosX
	float GetBallPosY(); //Getter PosY
	void SetBallPosX(float n); //Setter PosX
	void SetBallPosY(float n); //Setter PosY

	sf::Sprite sBall; //sBall is spriteBall
private:
	sf::Texture tBall; //tBall is textureBall

	float deltaX = 5; //DeltaTime X, used for variably updating scenery based on the elapsed time since the game last updated 
	float deltaY = 5; //DeltaTime Y, used for variably updating scenery based on the elapsed time since the game last updated
	float ballPosX = 500; //The position on the X axis
	float ballPosY = 475; //The position on the Y axis
	
	const float ballHeight = 12; //the height of the ball
	const float ballWidth = 12; //the width of the ball
	const float screenWidth = 1000; //The width of the window 
	const float screenHeight = 500; //The height of the window 

	sf::String loadFile = "images/ball.png"; //String with the path to the .png
};

#endif //!BALL_H