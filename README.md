# GEngine
opengl (GLFW) game engine

to build project, make build directory in repository root
and type this command:

cmake -DCMAKE_TOOLCHAIN_FILE=CMake/x86_64-w64-mingw32.cmake -DBUILD_SHARED_LIBS=ON ..

For get glfw submodule two commands need to be executed:
  **git submodule init** to initialize your local configuration file and 
  **git submodule update** to get all the data from the submodule
