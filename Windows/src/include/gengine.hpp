#pragma once
// #define GLFW_DLL
#include "GLFW/glfw3.h" // GLFW
#include <string>
#include <cstdlib>
#include <functional>
#include <windows.h>

using namespace std;

#define WSTD_SIZE 480

class Game2D; 
class Game3D;

bool init();
void clean();

class Game2D{
private:
	GLFWwindow *win=NULL;	
	// bool failure;
	bool dev;

	typedef struct wp {
		int width;
		int height;
		string title;
		GLFWmonitor *monitor;
		GLFWwindow *share;
	}wp;
	
	wp win_params;
public:
	Game2D(bool);
	Game2D(string,bool);
	void run(function<void ()> ifunc,function<void ()> func);
	// void end(); // but not used
	~Game2D();
};
class Game3D{
private:
	GLFWwindow *win=NULL;
	// bool failure;
public:
	Game3D(bool);
	~Game3D();
};