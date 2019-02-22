#include "gengine.hpp"

Game3D::~Game3D(){
	if(!fail_gl) {
		if(this->win) {	glfwDestroyWindow(this->win); }
		if(!is_clean) clean();
	}
	
}