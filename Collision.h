#pragma once
#include "Structs.h"

class Collision
{
public:
	void resolveCollision(Box& a, Box& b);

	bool checkCollision(const Box& a, const Box& b);

private:
	Vec3 normal;
	float length;
	float relativeVelocityX;
	float relativeVelocityY;
	float relativeVelocityZ;
	float impulse;
	float j;
	float e  = 0.01f;// Coefficient of restitution (0 = inelastic, 1 = elastic)
	float dampening =  0.9f;// Dampening factor (0.9 = 10% energy reduction)
};

