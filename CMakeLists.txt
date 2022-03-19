
cmake_minimum_required(VERSION 3.18.1)

MESSAGE (STATUS " building start ")


set(NAME render_3d)


# ok start Release !!! 
#set(CMAKE_CONFIGURATION_TYPES "Release" CACHE STRING "" FORCE)
set(CMAKE_CXX_COMPILER "C:/Program Files/LLVM/bin/clang++")
set(CMAKE_C_COMPILER "C:/Program Files/LLVM/bin/clang")

set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)

set(CMAKE_CXX_STANDARD 20)

#IF(MSVC) and ok wort, warning disable 
    MESSAGE (STATUS " in MSVC compile")
    SET(CMAKE_CXX_FLAGS "/EHsc")



# enable Vulkan, DirectX, OpenGL 
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DOPENGL_VARIANT" -ffast-math)


project(${NAME})

add_subdirectory(LosMath)
list(APPEND EXTRA_LIBS LosMath)

#target_link_libraries(${NAME} PUBLIC Extern/LosMath)



find_package(OpenGL REQUIRED)



include_directories( ${OPENGL_INCLUDE_DIRS} include/  LosMath/include)



add_executable(${NAME} Source/EmptyWin.cpp Source/PreLoad.cpp Source/ASTC.cpp )  # was Source/ASTC.cpp 
target_link_libraries (${NAME}  ${OPENGL_LIBRARIES} ${WINLIBS}  lMath )
#target_compile_definitions(${NAME} PRIVATE $<$<CONFIG:Release>:RELEASE_BUILD> )