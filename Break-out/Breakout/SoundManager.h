#pragma once

#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H

#define MAX_NUMBER_OF_SOUNDS 6

#include <SFML/Graphics.hpp> //Required for variables with 'sf'
#include <SFML/Audio.hpp> //Required for accessing the Sound class
#include <iostream> //Required for use of std::cout, std::endl and more

class SoundManager
{
public:
	SoundManager(); //Constructor
	~SoundManager(); //Destructor

	void StopSound(int i); //Stops the sound
	void isSoundPlaying(int i); //checks if the sound is already playing
	void PlaySound(int i); //With this method you can set the sound you want to play

private:
	sf::Sound sounds[MAX_NUMBER_OF_SOUNDS]; //Array of sounds[Total number of sounds]
	sf::SoundBuffer buffers[MAX_NUMBER_OF_SOUNDS]; //Array of soundBuffers[Total number of loaded sounds files]

	sf::String loadSoundDamage = "sounds/damage.wav"; //String with the path to the .wav
	sf::String loadSoundWin = "sounds/win.wav"; //String with the path to the .wav
	sf::String loadSoundLose = "sounds/lose.wav"; //String with the path to the .wav
	sf::String loadSoundBounce = "sounds/bounce.wav"; //String with the path to the .wav
	sf::String loadSoundStartSound = "sounds/startsound.wav"; //String with the path to the .wav
	sf::String loadSoundMenuClick = "sounds/menuclick.wav"; //String with the path to the .wav
};

#endif //!SOUNDMANAGER_H