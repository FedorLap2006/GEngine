#include "defs.hpp"

bool fail_gl;

bool is_init=false;
bool is_clean=false;

bool init(){
	if(glfwInit()) fail_gl=false;
	else fail_gl=true;
	is_init=true;
}
void clean(){
	if(!fail_gl) glfwTerminate();
	is_clean=true;
}
