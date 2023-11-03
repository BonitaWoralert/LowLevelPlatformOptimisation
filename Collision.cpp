#include "Collision.h"

void Collision::resolveCollision(Box& a, Box& b)
{
    normal = { a.position.x - b.position.x, a.position.y - b.position.y, a.position.z - b.position.z };
    length = std::sqrt(normal.x * normal.x + normal.y * normal.y + normal.z * normal.z);

    // Normalize the normal vector
    normal.normalise();

    relativeVelocityX = a.velocity.x - b.velocity.x;
    relativeVelocityY = a.velocity.y - b.velocity.y;
    relativeVelocityZ = a.velocity.z - b.velocity.z;

    // Compute the relative velocity along the normal
    impulse = relativeVelocityX * normal.x + relativeVelocityY * normal.y + relativeVelocityZ * normal.z;

    // Ignore collision if objects are moving away from each other
    if (impulse > 0) {
        return;
    }

    // Compute the collision impulse scalar
    j = -(1.0f + e) * impulse * dampening;

    // Apply the impulse to the boxes' velocities
    a.velocity.x += j * normal.x;
    a.velocity.y += j * normal.y;
    a.velocity.z += j * normal.z;
    b.velocity.x -= j * normal.x;
    b.velocity.y -= j * normal.y;
    b.velocity.z -= j * normal.z;
}

bool Collision::checkCollision(const Box& a, const Box& b)
{
    return (std::abs(a.position.x - b.position.x) * 2 < (a.size.x + b.size.x)) &&
        (std::abs(a.position.y - b.position.y) * 2 < (a.size.y + b.size.y)) &&
        (std::abs(a.position.z - b.position.z) * 2 < (a.size.z + b.size.z));
}
