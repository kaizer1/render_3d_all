
cmake_minimum_required(VERSION 3.18.1)

MESSAGE (STATUS " building start ")


set(NAME render_3d)


set(CMAKE_CXX_COMPILER "C:/Program Files/LLVM/bin/clang++")
set(CMAKE_C_COMPILER "C:/Program Files/LLVM/bin/clang")

set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)

set(CMAKE_CXX_STANDARD 20)

#IF(MSVC) and ok wort, warning disable 
    MESSAGE (STATUS " in MSVC compile")
    SET(CMAKE_CXX_FLAGS "/EHsc")



# enable Vulkan, DirectX, OpenGL 
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DOPENGL_VARIANT")



project(${NAME})


find_package(OpenGL REQUIRED)



include_directories( ${OPENGL_INCLUDE_DIRS} include/ )


add_executable(${NAME} EmptyWin.cpp PreLoad.cpp ASTC.cpp )
target_link_libraries (${NAME}  ${OPENGL_LIBRARIES} ${WINLIBS})