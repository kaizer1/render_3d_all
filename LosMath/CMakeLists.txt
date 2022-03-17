cmake_minimum_required(VERSION 3.18.1)

project(lMath)

file(GLOB PUBLIC_HEADERS_LMATH "include/*.hpp")

set(lMathLib
      LosMatrix3_3.cpp
      LosMatrix4_4.cpp
      LosQuaternion.cpp
      LosVector2.cpp
      LosVector3.cpp
      LosVector4.cpp
      MatAndVectOperators.cpp
       )


message("STATUS >    ok build los Math (lMath) ")


  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}" PARENT_SCOPE)
  set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG}" PARENT_SCOPE)
  set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE}" PARENT_SCOPE)
  set(CMAKE_C_FLAGS_DEFAULT "${CMAKE_C_FLAGS}" PARENT_SCOPE)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}" PARENT_SCOPE)
  set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG}" PARENT_SCOPE)
  set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE}" PARENT_SCOPE)
  set(CMAKE_CXX_LINK_FLAGS "${CMAKE_CXX_LINK_FLAGS}" PARENT_SCOPE)
  set(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE}" PARENT_SCOPE)

add_library(lMath STATIC ${PUBLIC_HEADERS_LMATH} ${lMathLib})

target_include_directories(lMath PRIVATE include/)
#target_link_libraries(lMath ${lMathLib})