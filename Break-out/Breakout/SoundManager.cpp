#include "SoundManager.h"

SoundManager::SoundManager() //Constructor, Sets all the sounds to the soundbuffer
{
	if (!buffers[0].loadFromFile(loadSoundStartSound)) //0 = startgame Sound
	{
		std::cout << "Error loading <startGame sound> from file" << std::endl;
		return;
	}

	if (!buffers[1].loadFromFile(loadSoundMenuClick)) //1 = menuclick Sound
	{
		std::cout << "Error loading <menuClick sound> from file" << std::endl;
		return;
	}

	if (!buffers[2].loadFromFile(loadSoundLose)) //2 = lose Sound
	{
		std::cout << "Error loading <lose sound> from file" << std::endl;
		return;
	}

	if (!buffers[3].loadFromFile(loadSoundWin)) //3 = win Sound
	{
		std::cout << "Error loading <win sound> from file" << std::endl;
		return;
	}

	if (!buffers[4].loadFromFile(loadSoundDamage)) //4 = damage Sound
	{
		std::cout << "Error loading <damage sound> from file" << std::endl;
		return;
	}

	if (!buffers[5].loadFromFile(loadSoundBounce)) //5 = bounce Sound
	{
		std::cout << "Error loading <bounce sound> from file" << std::endl;
		return;
	}

	sounds[0].setBuffer(buffers[0]);
	sounds[1].setBuffer(buffers[1]);
	sounds[2].setBuffer(buffers[2]);
	sounds[3].setBuffer(buffers[3]);
	sounds[4].setBuffer(buffers[4]);
	sounds[5].setBuffer(buffers[5]);
}

SoundManager::~SoundManager()
{
	//Destructor
}

void SoundManager::isSoundPlaying(int i) //Checks if the sound is already playing and if not then play the sound
{
	if (sounds[i].getStatus() == sounds[i].Stopped)
	{
		sounds[i].play();
	}
	else if (sounds[i].getStatus() == sounds[i].Playing)
	{
		sounds[i].getStatus();
	}
}

void SoundManager::PlaySound(int i) //Play a sound effect
{
	sounds[i].play();
}

void SoundManager::StopSound(int i) //Stops the sound
{
	sounds[i].stop();
}