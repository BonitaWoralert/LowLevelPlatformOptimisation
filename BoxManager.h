#pragma once
#include "Structs.h"
#include <vector>
class BoxManager
{
private:

public:
	BoxManager(int boxCount);
	~BoxManager();

	void UpdateBoxPhysics(Box& box, const float deltaTime);
	void UpdateGravity(const float deltaTime);
	//void UpdateGravity();
	void UpdateVelocity(Box& box, const float deltaTime);
	void FloorCollision();
	void WallCollision();
	void OtherBoxCollision();

	std::vector<Box> boxes;
};

