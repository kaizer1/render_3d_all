
cmake_minimum_required(VERSION 3.18.1)

MESSAGE (WARNING " building start ")


set(NAME render_3d)


#set(CMAKE_CXX_COMPILER "C:/Program Files/LLVM/bin/clang++")
#set(CMAKE_C_COMPILER "C:/Program Files/LLVM/bin/clang")

#set(CMAKE_C_COMPILER clang)
#set(CMAKE_CXX_COMPILER clang++)

set(CMAKE_CXX_STANDARD 20)


project(${NAME})


find_package(OpenGL REQUIRED)
  

include_directories( ${OPENGL_INCLUDE_DIRS} include/)


add_executable(${NAME} EmptyWin.cpp PreLoad.cpp)
target_link_libraries (${NAME}  ${OPENGL_LIBRARIES} ${WINLIBS})