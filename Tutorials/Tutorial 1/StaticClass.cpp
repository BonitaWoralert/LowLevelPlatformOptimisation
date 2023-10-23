#include "StaticClass.h"

static std::vector<int> intVec;

void StaticClass::WriteToVector(int newInt)
{
	intVec.push_back(newInt);
	std::cout << newInt << " has been written to the vector.\n";
}
