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
#include "ground.h"

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

	b2World* world;
	b2Body* myBodyDef;



private:
	/// @brief the rotating square in the middle of the screen
		/// @brief a Timer to rotate the color every n seconds
	Timer t;
	/// @brief a Car to drive
	Car* car;
	b2Body* dynamicBody;
	b2Body* groundBody;
	Ground* ground;
	//Line* line;



};

#endif /* SCENE00_H */
