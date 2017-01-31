/**
 * This class describes Ground behavior.
 *
 * Copyright 2016 Amin Benali <Amin@benali.nl>
 */

#include "ground.h"

Ground::Ground() : Entity()
{
	//this->addSprite("assets/blokje.tga");
	//this->sprite()->color = CYAN;

	const int numverts = 8;
	float groundVertices[numverts] = {-200,-0,-130.128,5.08323,-89.0526,-0.105309,-31.5464,1.19183};



	Line tmp;
	for (int x = 0; x < numverts; x++) {
		tmp.addPoint( x*150, groundVertices[x] );
	}
	this->addLine(&tmp);

}

Ground::~Ground()
{

}

void Ground::update(float deltaTime)
{


}
