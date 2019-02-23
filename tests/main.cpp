#include "gengine.hpp"
// #include <windows.h>

void Init(){

}
void Loop(){
	glClearColor(0.1,0.3,0.5,1.0);
}

int main(int argc,char** argv) 
{
	Game2D g("test example",true);
	g.run(Init,Loop);
}