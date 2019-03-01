#pragma once
// #include "GLFW/glfw3.h" // GLFW
// #include <string>
// #include <cstdlib>
// #include <functional>
// #include <windows.h>
// #include <vector>
#include "defs.hpp"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_projection.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

#include "defs.hpp"
#include <string>
#include <cstdlib>
#include <functional>
#include <windows.h>
#include <vector>


using namespace std;





class GContext
{
private:
	GLFWwindow *winc;
public:

	GContext(GLFWwindow*);

	DrawRaw(int32_t,int32_t,);

	~GContext();
	
};


class GContext
{
private:
		
public:
	drawPixel();
	GContext();
	GContext();
	
};

class Window {
public:

private:
	Window(GContext*);
	~Window();
};
