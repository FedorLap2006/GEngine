cmake_minimum_required (VERSION 2.6)
include_directories("${PROJECT_SOURCE_DIR}/include")
set(SOURCES
   src/draw.cpp
   src/game2d.cpp
   #src/game3d.cpp
   src/gengine.cpp
    )
set(HEADERS
   include/draw.hpp
   include/gengine.hpp
    )
set(CMAKE_LEGACY_CYGWIN_WIN32 0)
set(CMAKE_MODULE_PATH ./cmake)
set(NO_GLFW_X11 true)
find_package(OpenGL REQUIRED)

#find_package(PkgConfig REQUIRED)
find_package(GLFW REQUIRED glfw3)



include_directories(
        ${OPENGL_INCLUDE_DIR}
        ${GLFW_INCLUDE_DIRS}
)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
target_link_libraries(${PROJECT_NAME} ${OPENGL_gl_LIBRARY} ${GLFW_LIBRARIES})
target_include_directories(${PROJECT_NAME} PUBLIC include)
#install (TARGETS xlang DESTINATION bin)
