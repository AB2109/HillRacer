/**
 * This class describes MyEntity behavior.
 *
 * Copyright 2016 Amin Benali <Amin@benali.nl>
 */

#include "car.h"

Car::Car() : Entity()
{
	this->addSprite("assets/car.tga");
	this->sprite()->color = WHITE;
}

Car::~Car()
{

}

void Car::update(float deltaTime)
{


}
