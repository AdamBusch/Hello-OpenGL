cmake_minimum_required(VERSION 3.0.0)

# Created by Adam Busch on 12/29/18
# Basic CMake setup for small OpenGL projects

project(hello-opengl VERSION 0.1.0)

include(CTest)
enable_testing()

file(GLOB Sources "sources/*.cpp")

include_directories("headers")

# Extern packages
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS})
find_package(GLEW REQUIRED)
include_directories(${GLEW_INCLUDE_DIRS})

add_executable(hello-opengl ${Sources})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

target_link_libraries(hello-opengl ${SDL2_LIBRARIES} ${OPENGL_LIBRARIES} ${GLEW_LIBRARIES})