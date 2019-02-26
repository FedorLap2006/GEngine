#pragma once

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <string>
#include <cstdlib>
#include <functional>
#include <windows.h>



extern bool fail_gl;
extern bool is_init;
extern bool is_clean;

bool init();
void clean();
