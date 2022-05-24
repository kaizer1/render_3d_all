
cmake_minimum_required(VERSION 3.18.1)

MESSAGE (WARNING " building start ")


set(NAME render_3d)


#set(CMAKE_CXX_COMPILER "C:/Program Files/LLVM/bin/clang++")
#set(CMAKE_C_COMPILER "C:/Program Files/LLVM/bin/clang")

#set(CMAKE_C_COMPILER clang)
#set(CMAKE_CXX_COMPILER clang++)

set(CMAKE_CXX_STANDARD 20)



	find_library(Vulkan_LIBRARY NAMES vulkan-1 vulkan PATHS "C:/VulkanSDK/1.3.211.0/Lib" )
		IF (Vulkan_LIBRARY)
			set(Vulkan_FOUND ON)
			MESSAGE("Using bundled Vulkan library version")
		ENDIF()


project(${NAME})

  

include_directories(  include/)


add_executable(${NAME} Source/EmptyWin.cpp Source/PreLoad.cpp)
target_link_libraries (${NAME} ${Vulkan_LIBRARY} ${WINLIBS})