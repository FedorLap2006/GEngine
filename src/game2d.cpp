#include "gengine.hpp"
#include "SDL.h"
Game2D::Game2D(string title,bool dev){
	if(!is_init) init();
	if(!fail_gl) {
		this->win_params = wp{WSTD_SIZE,WSTD_SIZE,title,NULL,NULL};
			this->dev=dev;
		//	this->win = glfwCreateWindow(WSTD_SIZE,WSTD_SIZE,title.c_str(),NULL,NULL);
		//	glfwMakeContextCurrent(win);
		// protected ( if user don't call start method -> glfw don't create window)
	}	
}


Game2D::Game2D(bool dev){
	if(!is_init) init();
	if(!fail_gl) {
		this->win_params = wp{WSTD_SIZE,WSTD_SIZE,"Game",NULL,NULL};
			this->dev=dev;
		//	this->win = glfwCreateWindow(WSTD_SIZE,WSTD_SIZE,title.c_str(),NULL,NULL);
		//	glfwMakeContextCurrent(win);
		// protected ( if user don't call start method -> glfw don't create window)
	}
}
Game2D::~Game2D(){
	if(!fail_gl) {
		if(this->win) {	glfwDestroyWindow(this->win); }
		if(!is_clean) clean();
	}
}

void Game2D::run(function<void ()> ifunc,function<void ()> func){
	if(!is_init) init();
	if(fail_gl) {
		return;
	}
	if(!this->dev) FreeConsole();
	wp p = this->win_params;
	this->win = glfwCreateWindow(p.width,p.height,p.title.c_str(),p.monitor,p.share);

	glfwMakeContextCurrent(this->win);

	ifunc();

	while(!glfwWindowShouldClose(win)) {
		func(); // run user code
		glClear(GL_COLOR_BUFFER_BIT);
		glFlush();
		glfwSwapBuffers(win);
		glfwPollEvents();
	}
}
