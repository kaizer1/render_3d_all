
cmake_minimum_required(VERSION 3.18.1)

MESSAGE (WARNING " building start ")


set(NAME render_3d)


#set(CMAKE_CXX_COMPILER "C:/Program Files/LLVM/bin/clang++")
#set(CMAKE_C_COMPILER "C:/Program Files/LLVM/bin/clang")

#set(CMAKE_C_COMPILER clang)
#set(CMAKE_CXX_COMPILER clang++)

set(CMAKE_CXX_STANDARD 20)


project(${NAME})


 set(DXC_BUILD_ARCH "x64")

if ("$ENV{WIN10_SDK_PATH}$ENV{WIN10_SDK_VERSION}" STREQUAL "" )
  get_filename_component(WIN10_SDK_PATH "[HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows Kits\\Installed Roots;KitsRoot10]" ABSOLUTE CACHE)
  set (WIN10_SDK_VERSION ${CMAKE_VS_WINDOWS_TARGET_PLATFORM_VERSION})
elseif(TRUE)
  set (WIN10_SDK_PATH $ENV{WIN10_SDK_PATH})
  set (WIN10_SDK_VERSION $ENV{WIN10_SDK_VERSION})
endif ("$ENV{WIN10_SDK_PATH}$ENV{WIN10_SDK_VERSION}" STREQUAL "" )

  

  if (IS_DIRECTORY "${WIN10_SDK_PATH}/Include/${WIN10_SDK_VERSION}.0")
  set(WIN10_SDK_VERSION "${WIN10_SDK_VERSION}.0")
endif (IS_DIRECTORY "${WIN10_SDK_PATH}/Include/${WIN10_SDK_VERSION}.0")



find_path(D3D12_INCLUDE_DIR    # Set variable D3D12_INCLUDE_DIR
          d3d12.h                # Find a path with d3d12.h
          HINTS "${WIN10_SDK_PATH}/Include/${WIN10_SDK_VERSION}/um"
          DOC "path to WIN10 SDK header files"
          HINTS
          )

find_path(DXGI_INCLUDE_DIR    # Set variable DXGI_INCLUDE_DIR
          dxgi1_4.h           # Find a path with dxgi1_4.h
          HINTS "${WIN10_SDK_PATH}/Include/${WIN10_SDK_VERSION}/shared"
          DOC "path to WIN10 SDK header files"
          HINTS
          )
set(D3D12_INCLUDE_DIRS ${D3D12_INCLUDE_DIR} ${DXGI_INCLUDE_DIR})

set(D3D12_LIB_NAMES d3d12.lib dxgi.lib d3dcompiler.lib)


if ("${DXC_BUILD_ARCH}" STREQUAL "x64" )
    set(D3D12_HINTS_PATH ${WIN10_SDK_PATH}/Lib/${WIN10_SDK_VERSION}/um/x64)
elseif (CMAKE_GENERATOR MATCHES "Visual Studio.*ARM" OR "${DXC_BUILD_ARCH}" STREQUAL "ARM")
    set(D3D12_HINTS_PATH ${WIN10_SDK_PATH}/Lib/${WIN10_SDK_VERSION}/um/arm)
elseif (CMAKE_GENERATOR MATCHES "Visual Studio.*ARM64" OR "${DXC_BUILD_ARCH}" MATCHES "ARM64.*")
    set(D3D12_HINTS_PATH ${WIN10_SDK_PATH}/Lib/${WIN10_SDK_VERSION}/um/arm64)
elseif ("${DXC_BUILD_ARCH}" STREQUAL "Win32" )
    set(D3D12_HINTS_PATH ${WIN10_SDK_PATH}/Lib/${WIN10_SDK_VERSION}/um/x86)
else ("${DXC_BUILD_ARCH}" STREQUAL "x64")
   message(FATAL_ERROR "Cannot match platform.")
endif ("${DXC_BUILD_ARCH}" STREQUAL "x64")

set(D3D12_LIBRARIES)
foreach (D3D12_LIB_NAME ${D3D12_LIB_NAMES})
  find_library(${D3D12_LIB_NAME}_LOC NAMES ${D3D12_LIB_NAME} HINTS ${D3D12_HINTS_PATH})
  set(D3D12_LIBRARIES ${D3D12_LIBRARIES} ${${D3D12_LIB_NAME}_LOC})
endforeach(D3D12_LIB_NAME)


include(FindPackageHandleStandardArgs)
# handle the QUIETLY and REQUIRED arguments and set D3D12_FOUND to TRUE
# if all listed variables are TRUE
find_package_handle_standard_args(D3D12  DEFAULT_MSG
                                  D3D12_INCLUDE_DIRS D3D12_LIBRARIES)

mark_as_advanced(D3D12_INCLUDE_DIRS D3D12_LIBRARIES)


include_directories(  ${D3D12_INCLUDE_DIRS} include/)


add_executable(${NAME} WIN32 Source/EmptyWin.cpp Source/PreLoad.cpp)
target_compile_definitions(${NAME} PRIVATE "UNICODE" "_UNICODE")
target_link_libraries(${NAME} PRIVATE )
target_link_libraries (${NAME} PRIVATE ${WINLIBS} ${D3D12_LIBRARIES})