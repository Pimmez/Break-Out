#pragma once

#ifndef GAME_H
#define GAME_H

#include "GameStates.h" 
#include "Background.h"
#include "Ball.h"
#include "Blocks.h"
#include "Paddle.h"
#include "HUD.h"
#include "WinState.h"
#include "LoseState.h"
#include "PauseState.h"
#include "SoundManager.h"
#include "StartMenu.h"
#include "HowToPlay.h"

#define WIDTH 1000 //A constant value for the width of the window
#define HEIGHT 500 //A constant value for the height of the window

class Game
{
public:
	Game(); //Constructor
	void Run(); //Handles the whole game

private:
	void ProcessEvents(); //Handles All Switch cases & Event Handlers
	void UpdateGameLoop(); //Updates GameLoop
	void UpdateStartMenu(); //Updates StartMenu
	void UpdatesHowToPlay(); //Updates HowToPlay

	void RenderGameLoop(); //Renders the GameLoop
	void RenderStartMenu(); //Renders StartMenu
	void RenderWinState(); //Renders WinState 
	void RenderLoseState(); //Renders LoseState
	void RenderPauseState(); //Renders PauseState
	void RenderHowToPlay(); //Renders HowToPlay

	HUD hud;
	Ball ball;
	Blocks blocks;
	Paddle paddle;
	WinState winState;
	GameStates gStates;
	LoseState loseState;
	HowToPlay howToPlay;
	PauseState pauseState;
	StartMenu startMenu;
	Background background;
	SoundManager soundManager;

	sf::RenderWindow window; //variable to access the renderwindow

	float screenHeightOffset = 40; //Screen height offset for the HUD.
	float screenwidthOffset = 12; //Screen width offset for the laser
	bool isBallOutsideScreen; //Checks if the ball is outside the screen.
	bool isGameStarting = false; //Checks if the game has started
};

#endif //GAME_H