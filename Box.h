#pragma once
#include "Vec3.h"

// the box (falling item)
struct Box {
    Vec3 position;
    Vec3 size;
    Vec3 velocity;
    Vec3 colour;
};