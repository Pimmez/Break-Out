#include "Game.h"

Game::Game() : window(sf::VideoMode(WIDTH, HEIGHT), "Break-Out::C++") //Constructor
{
	//Set the framerate limit to 60
	window.setFramerateLimit(60);

	//Start Gamestates by START_MENU
	gStates = GameStates::START_MENU;
}

void Game::Run()
{
	//As long as the window is open. Play the processEvents
	while (window.isOpen())
	{
		ProcessEvents();
	}
}

void Game::ProcessEvents() //Handles Switch cases & Event Handlers
{
	sf::Event event;
	while (window.pollEvent(event)) //Handles Keyboard and Mouse Events
	{
		if (event.type == sf::Event::Closed) //Closes the application when pressing the close button.
		{
			window.close();
		}
		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Space && isBallOutsideScreen) //When the ball is out of bounds and you press spacebar, activate the ball and the paddle
			{
				ball.SetBallDeltaX((rand() % 5 - 5));
				ball.SetBallDeltaY(5);
				paddle.SetPaddleMoveSpeed(8);
				isBallOutsideScreen = false;
			}
			if (event.key.code == sf::Keyboard::Space && gStates == GameStates::GAME_LOOP) //Checks if the game has started
			{
				isGameStarting = true;
			}
			if (event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::A && gStates == GameStates::START_MENU) //Within StartMenu you can move selected item to the left
			{
				startMenu.MoveLeft();
			}
			if (event.key.code == sf::Keyboard::Right || event.key.code == sf::Keyboard::D && gStates == GameStates::START_MENU) //Within StartMenu you can move selected item to the left
			{
				startMenu.MoveRight();
			}
			if (event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::A && gStates == GameStates::HOW_TO_PLAY) //Within HowToPlay you can move selected item to the left
			{
				howToPlay.MoveLeft();
			}
			if (event.key.code == sf::Keyboard::Right || event.key.code == sf::Keyboard::D && gStates == GameStates::HOW_TO_PLAY) //Within HowToPlay you can move selected item to the right
			{
				howToPlay.MoveRight();
			}
			if (event.key.code == sf::Keyboard::Escape) //Closes the application when you press escape on your keyboard.
			{
				window.close();
			}
			if (event.key.code == sf::Keyboard::R)
			{
				if (gStates == GameStates::WIN_STATE)
				{
					blocks.ResetAll();
					hud.ResetAll();
					paddle.ResetPaddle();
					ball.ResetBall();
					gStates = GameStates::GAME_LOOP;
				}
				else if (gStates == GameStates::LOSE_STATE)
				{
					blocks.ResetAll();
					hud.ResetAll();
					paddle.ResetPaddle();
					ball.ResetBall();
					gStates = GameStates::GAME_LOOP;
				}
			}
			if (event.key.code == sf::Keyboard::Q) //Pauses the game when you press P on your keyboard.
			{
				if (gStates == GameStates::WIN_STATE)
				{
					blocks.ResetAll();
					hud.ResetAll();
					paddle.ResetPaddle();
					ball.ResetBall();
					gStates = GameStates::START_MENU;
				}
				else if (gStates == GameStates::LOSE_STATE)
				{
					blocks.ResetAll();
					hud.ResetAll();
					paddle.ResetPaddle();
					ball.ResetBall();
					gStates = GameStates::START_MENU;
				}
			}
			if (event.key.code == sf::Keyboard::P) //Pauses the game when you press P on your keyboard.
			{
				if (gStates == GameStates::PAUSE_GAME)
				{
					gStates = GameStates::GAME_LOOP;
				}
				else if(gStates == GameStates::GAME_LOOP)
				{
					gStates = GameStates::PAUSE_GAME;
				}	
			}
			if (event.key.code == sf::Keyboard::Return && gStates == GameStates::START_MENU) //A Switch case to check what state you are on
			{
				switch (startMenu.GetPressedItem())
				{
				case 0:
				{
					soundManager.StopSound(0);
					soundManager.PlaySound(1);
					gStates = GameStates::GAME_LOOP;
					break;
				}
				case 1:
				{
					soundManager.PlaySound(1);
					gStates = GameStates::HOW_TO_PLAY;
					break;
				}
				case 2:
				{
					window.close();
					break;
				}
				default:
					break;
				}
			}
			else if (event.key.code == sf::Keyboard::Return && gStates == GameStates::HOW_TO_PLAY) //A Switch case to check what state you are on
			{
				switch (howToPlay.GetPressedItem())
				{
				case 0:
				{
					soundManager.StopSound(0);
					soundManager.PlaySound(1);
					gStates = GameStates::GAME_LOOP;
					break;
				}
				case 1:
				{
					soundManager.PlaySound(1);
					gStates = GameStates::START_MENU;
					break;
				}
				default:
					break;
				}
			}
		}		
	}

	switch (gStates) //Handles GameStates, Updates & renders
	{
		case GameStates::START_MENU:
		{
			UpdateStartMenu();
			RenderStartMenu();
			break;
		}
		case GameStates::HOW_TO_PLAY:
		{
			UpdatesHowToPlay();
			RenderHowToPlay();
			break;
		}
		case GameStates::GAME_LOOP:
		{
			UpdateGameLoop();
			RenderGameLoop();
			break;
		}
		case GameStates::PAUSE_GAME:
		{
			RenderPauseState();
			break;
		}
		case GameStates::WIN_STATE:
		{
			RenderWinState();
			break;
		}
		case GameStates::LOSE_STATE:
		{
			RenderLoseState();
			break;
		}
		default:
		{
			break;
		}
	}
}

void Game::UpdateStartMenu() //Handles the soundtrack;
{
	soundManager.isSoundPlaying(0);
}

void Game::UpdatesHowToPlay() //Handles the soundtrack;
{
	soundManager.isSoundPlaying(0);
}

void Game::UpdateGameLoop() //Updates GameLoop
{
	if (isGameStarting) //When the game starts
	{
		paddle.MovePaddle(); //Move the paddle
		paddle.SetPaddleBorders(); //Activate the borders for the paddle
		ball.SetBallBorders(); //Activate the borders for the ball

		ball.SetBallPosX(ball.GetBallPosX() - ball.GetBallDeltaX()); //Moves the ball in the X direction
		//For every block, check if there is collision on the left and right sides of the blocks.
		for (int i = 0; i < blocks.GetNumber(); i++)
		{
			//If there is Collision
			if (sf::FloatRect(ball.GetBallPosX(), ball.GetBallPosY(), 6, 6).intersects(blocks.sBlocks[i]->getGlobalBounds()))
			{
				ball.SetBallDeltaX(-ball.GetBallDeltaX()); //Flips the ball direction
				soundManager.PlaySound(4); //Play damage sound
				hud.AddScore(); //Add score to the hud

				delete blocks.sBlocks[i]; //Delete the damaged block
				blocks.sBlocks[i] = new sf::Sprite; //Set a empty sprite on the position of the block that got hit.
				//if i don't use a new sprite, the array of blocks will be out of range and it will give an Acces Violation Error
			}
		}

		ball.SetBallPosY(ball.GetBallPosY() - ball.GetBallDeltaY());  //Moves the ball in the Y direction
		//For every block, check if there is collision on the top and bottom sides of the blocks.
		for (int i = 0; i < blocks.GetNumber(); i++)
		{
			//If there is Collision
			if (sf::FloatRect(ball.GetBallPosX(), ball.GetBallPosY(), 6, 6).intersects(blocks.sBlocks[i]->getGlobalBounds()))
			{
				ball.SetBallDeltaY(-ball.GetBallDeltaY()); //Flips the ball direction
				soundManager.PlaySound(4); //Play damage sound
				hud.AddScore(); //Add score to the hud

				delete blocks.sBlocks[i]; //Delete the damaged block
				blocks.sBlocks[i] = new sf::Sprite; //Set a empty sprite on the position of the block that got hit.
				//if i don't use a new sprite, the array of blocks will be out of range and it will give an Acces Violation Error
			}
		}
		if (ball.GetBallPosY() > HEIGHT) //When the ball moves out of bounds
		{
			hud.LoseLives(); //Lose a life
			soundManager.PlaySound(2); //Play death sound
			ball.ResetBall(); //Reset the ball position
			paddle.ResetPaddle(); //Reset the paddle position
			isBallOutsideScreen = true; //Set the boolean to true
		}

		//When the ball hits the paddle
		if (ball.sBall.getGlobalBounds().intersects(paddle.sPaddle.getGlobalBounds()))
		{
			ball.SetBallDeltaY((rand() % 8 + 2)); //Bounce back between 8 and 2; 
			soundManager.PlaySound(5); //Play bounce sound
		}

		//This makes sure that the sprite of the ball moves
		ball.sBall.setPosition(ball.GetBallPosX(), ball.GetBallPosY());
	}

	//if your points are egual to the maximum points you can get, then go to the winstate
	if (hud.GetPoints() == hud.GetMaxPoints())
	{
		soundManager.PlaySound(3); //Play win sound
		gStates = GameStates::WIN_STATE; //Switch to the winState gamestate
	}
	//if your lives are equal to the minimum lives you can reach, then go to the losestate
	if (hud.GetLives() == hud.GetMinLives())
	{
		soundManager.PlaySound(2); //Play lose sound
		gStates = GameStates::LOSE_STATE; //Switch to the loseState gamestate
	}
}

//------------------------------------------------

void Game::RenderStartMenu() //Renders StartMenu
{
	window.clear();

	startMenu.DrawTo(window);

	window.display();
}

void Game::RenderHowToPlay()
{
	window.clear();

	howToPlay.DrawTo(window);

	window.display();
}

void Game::RenderGameLoop() //Renders GameLoop
{
	window.clear();

	background.DrawTo(window);
	hud.DrawTo(window);
	ball.DrawTo(window);
	blocks.DrawTo(window);
	paddle.DrawTo(window);

	window.display();
}

void Game::RenderWinState() //Renders WinState
{
	window.clear();

	winState.DrawTo(window);

	window.display();
}

void Game::RenderLoseState() //Renders LoseState
{
	window.clear();

	loseState.DrawTo(window);

	window.display();
}

void Game::RenderPauseState() //Renders PauseState
{
	window.clear();

	background.DrawTo(window);
	ball.DrawTo(window);
	blocks.DrawTo(window);
	paddle.DrawTo(window);
	hud.DrawTo(window);
	pauseState.DrawTo(window);
	
	window.display();
}