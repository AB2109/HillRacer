/**
 * This class describes MyScene behavior.
 *
 * Copyright 2016 Amin Benali <Amin@benali.nl>
 */

#include <fstream>
#include <sstream>


#include <box2D.h>
#include "game.h"

Game::Game() : Scene()
{
	// start the timer.
	t.start();


	// create a single instance of Car.
	// the Sprite is added in Constructor of Car.
	car = new Car();
	car->position = Point2(100,100);


	// create the scene 'tree'
	// add car to this Scene as a child.
	this->addChild(car);
}


Game::~Game()
{
	// deconstruct and delete the Tree
	this->removeChild(car);

	// delete car from the heap (there was a 'new' in the constructor)
	delete car;
}

void Game::update(float deltaTime)
{
	// ###############################################################
	// Escape key stops the Scene
	// ###############################################################
	if (input()->getKeyUp( GLFW_KEY_ESCAPE )) {
		this->stop();
	}

	// ###############################################################
	// Spacebar scales myentity
	// ###############################################################
	if (input()->getKeyDown( GLFW_KEY_SPACE )) {
		car->scale = Point(0.5f, 0.5f);
	}
	if (input()->getKeyUp( GLFW_KEY_SPACE )) {
		car->scale = Point(1.0f, 1.0f);
	}

	// ###############################################################
	// Rotate color
	// ###############################################################
	if (t.seconds() > 0.0333f) {
		RGBAColor color = car->sprite()->color;
		car->sprite()->color = Color::rotate(color, 0.01f);
		t.start();
	}
}
