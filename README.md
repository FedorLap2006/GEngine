# GEngine
opengl (GLFW) game engine

[![CodeFactor](https://www.codefactor.io/repository/github/fedorlap2006/gengine/badge)](https://www.codefactor.io/repository/github/fedorlap2006/gengine)

to build project, make build directory in repository root
and type this command:

```cmake -DCMAKE_TOOLCHAIN_FILE=CMake/x86_64-w64-mingw32.cmake -DBUILD_SHARED_LIBS=ON ..```

if your platform is Windows then add to flags ```-DWIN32=ON```

For get glfw submodule two commands need to be executed:
  **```git submodule init```** to initialize your local configuration file and 
  **```git submodule update```** to get all the data from the submodule
