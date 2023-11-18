#include "BoxManager.h"
#include <thread>
BoxManager::BoxManager(int boxCount)
{
	for (int i = 0; i < boxCount; ++i) {
		Box box;

        // Assign random x, y, and z positions within specified ranges
        box.position.x = static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / 20.0f));
        box.position.y = 10.0f + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / 1.0f));
        box.position.z = static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / 20.0f));

        box.size = { 1.0f, 1.0f, 1.0f };

        // Assign random x-velocity between -1.0f and 1.0f
        box.velocity = { -1.0f + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / 2.0f)) , 0.0f, 0.0f };

        // Assign a random color to the box
        box.colour.x = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
        box.colour.y = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
        box.colour.z = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);

		boxes.push_back(box);
	}
}

BoxManager::~BoxManager()
{
}

void BoxManager::UpdateBoxPhysics(Box& box, const float deltaTime)
{
    //std::thread AAAAAAA(UpdateGravity, box, deltaTime);
    //std::thread BBBBBBB(UpdateVelocity, box, deltaTime);
    //AAAAAAA.join();
    //BBBBBBB.join();
}

void BoxManager::UpdateGravity(const float deltaTime)
{
    for (Box& box : boxes)
        box.velocity.y += gravity * deltaTime;
}


void BoxManager::UpdateVelocity(Box& box, const float deltaTime)
{
    box.position.x += box.velocity.x * deltaTime;
    box.position.y += box.velocity.y * deltaTime;
    box.position.z += box.velocity.z * deltaTime;
}
