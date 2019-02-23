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
  #set(CMAKE_LEGACY_CYGWIN_WIN32 0)
set(CMAKE_MODULE_PATH ./cmake/modules)

#GLFW 
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(vendor/glfw)
target_link_libraries(${PROJECT_NAME} glfw)


find_package(OpenGL REQUIRED)
target_include_directories(myapp ${OPENGL_INCLUDE_DIR})
target_link_libraries(myapp ${OPENGL_gl_LIBRARY})
target_link_libraries(myapp ${OPENGL_glu_LIBRARY})

#==============================================

include_directories(
        ${OPENGL_INCLUDE_DIR}
        ${GLFW_INCLUDE_DIRS}
)

add_executable(${PROJECT_NAME} tests/main.cpp ${SOURCES} ${HEADERS})
target_link_libraries(${PROJECT_NAME}) 
target_include_directories(${PROJECT_NAME} PUBLIC include)
#install (TARGETS xlang DESTINATION bin)
