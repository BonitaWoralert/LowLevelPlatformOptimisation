#pragma once
#include "Vec3.h"

// gravity - change it and see what happens (usually negative!)
const float gravity = -19.81f;

// the box (falling item)
struct Box {
    Vec3 position;
    Vec3 size;
    Vec3 velocity;
    Vec3 colour;
};