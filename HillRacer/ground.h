/**
 * Copyright 2016 Amin Benali <Amin@benali.nl>
 *
 * @file ground.h
 *
 * @brief description of Ground behavior.
 */

#ifndef GROUND_H
#define GROUND_H

#include <rt2d/entity.h>

/// @brief The MyEntity class is the Entity implementation.
class Ground : public Entity
{
public:
	/// @brief Constructor
	Ground();
	/// @brief Destructor
	virtual ~Ground();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:

};

#endif /* MYENTITY_H */
