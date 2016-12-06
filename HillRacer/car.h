/**
 * Copyright 2016 Amin Benali <Amin@benali.nl>
 *
 * @file car.h
 *
 * @brief description of Car behavior.
 */

#ifndef CAR_H
#define CAR_H

#include <rt2d/entity.h>

/// @brief The MyEntity class is the Entity implementation.
class Car : public Entity
{
public:
	/// @brief Constructor
	Car();
	/// @brief Destructor
	virtual ~Car();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:
	/* add your private declarations */
};

#endif /* MYENTITY_H */
