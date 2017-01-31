/**
 * This class describes MyScene behavior.
 *
 * Copyright 2016 Amin Benali <Amin@benali.nl>
 */

#include <fstream>
#include <sstream>
#include <stdio.h>

#include <box2D.h>
#include "game.h"

Game::Game() : Scene()
{

	//@param New car entity.
	car = new Car();

	//@param New ground entity..
	ground = new Ground();

	//@param New line entity.
	Line* line = ground->line();
	glm::vec3 p = line->points()[2];
	std::cout << p.x << ", " << p.y << std::endl;

	// Construct a world object, which will hold and simulate the rigid bodies.
	world = new b2World(b2Vec2(0,9.81f));
	world->SetAllowSleeping(false);



	// Ground
	//set up our _body variable which will eventually contain the track
	 b2BodyDef bd;
	 bd.position.Set(0, 0);
	 bd.type = b2_staticBody;
	 groundBody = world->CreateBody(&bd);



	//Define new car
	b2BodyDef myBodyDef;
	myBodyDef.type = b2_dynamicBody; //this will be a dynamic body
	myBodyDef.position.Set(car->position.x*0.20f, car->position.y *0.20f);
	myBodyDef.angle = 0; //set the starting angle
	dynamicBody = world->CreateBody(&myBodyDef);
	b2PolygonShape boxShape;
	boxShape.SetAsBox(1,1);
	//Puts car in middle of screen.
	dynamicBody->SetTransform( b2Vec2(10,2), 0 );








	// start the timer.
	t.start();



	// create the scene 'tree'
	// add car to this Scene as a child.
	this->addChild(car);
	this->addChild(ground);
}


Game::~Game()
{
	// deconstruct and delete the Tree
	this->removeChild(car);
	this->removeChild(ground);

	// delete car from the heap (there was a 'new' in the constructor)
	delete car;
	delete ground;
}

void Game::update(float deltaTime)
{

	world->Step(deltaTime,8,5);
	car->position 		= Point2(dynamicBody->GetPosition().x * 50.0f, dynamicBody->GetPosition().y * 50.0f);
	ground->position = Point2(50.0f, 700.0f);
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
	// Arrow moves car
	// ###############################################################
	if (input()->getKeyDown( GLFW_KEY_D )) {
		car->position.x += 10.5f;
	}

	if (input()->getKeyUp( GLFW_KEY_D )) {
		car->position.x += 0.0f;
	}

	if (input()->getKeyDown( GLFW_KEY_A )) {
		car->position.x -= 10.5f;
	}
	if (input()->getKeyUp( GLFW_KEY_A )) {
		car->position.x -= 0.0f;
	}

	if (input()->getKeyDown( GLFW_KEY_W )) {
		car->position.y -= 10.5f;
		//dynamicBody->ApplyForce(b2Vec2(0,50), dynamicBody->GetWorldCenter(),0);
		dynamicBody->ApplyForce( b2Vec2(50,-10000), dynamicBody->GetWorldCenter() ,true);
		//dynamicBody->ApplyImpulse(force,dynamicBody.GetWorldCenter());
	}

	if (input()->getKeyUp( GLFW_KEY_W )) {
		car->position.y -= 0.0f;
	}

	if (input()->getKeyDown( GLFW_KEY_S )) {
		car->position.y += 10.5f;
	}
	if (input()->getKeyUp( GLFW_KEY_S )) {
		car->position.y += 0.0f;
	}


	if (input()->getKeyDown( GLFW_KEY_B )) {

			b2Vec2 position = groundBody->GetPosition();
			printf("%4.2f %4.2f\n", position.x, position.y);
	}

}
