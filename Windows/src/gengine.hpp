#pragma once
// #define GLFW_DLL
#include "GLFW/glfw3.h" // GLFW
#include <string>
#include <cstdlib>
#include <functional>
#include <windows.h>

using namespace std;

#define WSTD_SIZE 480

static bool fail_gl;

static bool is_init=false;
static bool is_clean=false;

bool init(){
	if(glfwInit()) fail_gl=false;
	else fail_gl=true;
	is_init=true;
}
void clean(){
	if(!fail_gl) glfwTerminate();
	is_clean=true;
}



class Game2D; 
class Game3D;

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