/**
 * Copyright 2016 Amin Benali <Amin@benali.nl>
 *
 * @file myscene.h
 *
 * @brief description of MyScene behavior.
 */

#ifndef GAME_H
#define GAME_H

#include <rt2d/scene.h>
#include "car.h"

/// @brief The MyScene class is the Scene implementation.
class Game : public Scene
{
public:
	/// @brief Constructor
	Game();
	/// @brief Destructor
	virtual ~Game();


	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:
	/// @brief the rotating square in the middle of the screen
		/// @brief a Timer to rotate the color every n seconds
	Timer t;
	/// @brief a Car to drive
	Car* car;
};

#endif /* SCENE00_H */