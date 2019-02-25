cmake_minimum_required (VERSION 2.6)
project(GEngine)

set(CMAKE_CXX_STANDARD 14)

if (CYGWIN)
  #FOR GLFW COMPILATION
  set (WIN32 1)
  find_library(GDI32_LIBRARY gdi32)
endif()

if (MINGW)
#	target_compile_options(${PROJECT_NAME} -finput-charset=UTF-8 -fexec-charset=UTF-8)
endif()
if (MSVC)
#	target_compile_options(${PROJECT_NAME} /p:CharacterSet=Unicode) 
endif()

set(SOURCES
   src/draw.cpp
   src/game2d.cpp
   src/defs.cpp
   src/gengine.cpp
    )

set(HEADERS
   include/draw.hpp
   include/game2d.hpp
   include/defs.hpp
   include/gengine.hpp
    )

set(CMAKE_MODULE_PATH ./cmake/modules)


#GLFW 

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(vendor/glfw)
add_subdirectory(vendor/glm)
find_package(OpenGL REQUIRED)
#==============================================

include_directories(
        ${OPENGL_INCLUDE_DIR}
        ${GLM_INCLUDE_DIRS}
        "${PROJECT_SOURCE_DIR}/include"
)


# add_executable(${PROJECT_NAME} tests/main.cpp ${SOURCES} ${HEADERS})

target_link_libraries(${PROJECT_NAME} glfw)
target_link_libraries(${PROJECT_NAME} glm)
target_link_libraries(${PROJECT_NAME} ${OPENGL_gl_LIBRARY})
target_link_libraries(${PROJECT_NAME} ${OPENGL_glu_LIBRARY})
target_include_directories(${PROJECT_NAME} PUBLIC include)
if (WIN32)
  target_link_libraries(${PROJECT_NAME} ${GDI32_LIBRARY})
endif()

if ( BUILD_SHARED_LIBS ) 
	add_library(${PROJECT_NAME} SHARED 
		${SOURCES}
	)
else()
	add_library(${PROJECT_NAME} STATIC
		${SOURCES}
	)
endif()
