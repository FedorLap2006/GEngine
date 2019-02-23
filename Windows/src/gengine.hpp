#pragma once
// #define GLFW_DLL
#include "defs.h"
// #include "GLFW/glfw3.h" // GLFW
using namespace std;

#include "game2d.hpp"
#include "game3d.hpp"


#define WSTD_SIZE 480




class Game2D; 
class Game3D;


class Game3D{
private:
	GLFWwindow *win=NULL;
	// bool failure;
public:
	Game3D(bool);
	~Game3D();
};
