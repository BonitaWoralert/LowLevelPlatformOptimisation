#pragma once
#include <stdlib.h>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>

#include "Vec3.h"
#include "Structs.h"
#include "Collision.h"
#include "MemAlloc.h"
#include "BoxManager.h"

using namespace std::chrono;

// this is the number of falling physical items. 
#define NUMBER_OF_BOXES 50

// these is where the camera is, where it is looking and the bounds of the continaing box. You shouldn't need to alter these

#define LOOKAT_X 10
#define LOOKAT_Y 10
#define LOOKAT_Z 50

#define LOOKDIR_X 10
#define LOOKDIR_Y 0
#define LOOKDIR_Z 0

#define minX -10.0f
#define maxX 30.0f
#define minZ -30.0f
#define maxZ 30.0f

//std::vector<Box> boxes;
Collision* collision;
BoxManager* boxManager;

std::thread t1, t2;
