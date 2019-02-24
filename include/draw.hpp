#pragma once
#include "GLFW/glfw3.h" // GLFW
#include <string>
#include <cstdlib>
#include <functional>
#include <windows.h>
#include <vector>

using namespace std;

typedef PC GLFloat;

typedef Vec2 GLFloat**;
typedef Vec3 GLFloat***;


class Draw
{
public:
	drawPixel(PC,PC,PC);
	drawPixel(PC,PC);
	Draw();
	~Draw();
	
};