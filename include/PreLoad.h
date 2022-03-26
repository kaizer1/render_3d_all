// Loskuntikov Games inc. 2022
 
#include <windows.h>
#include <iostream>
#include <thread>
#include <vector>

#include <vulkan/vulkan.h>
#include <losVulkan.hpp>

class PreLoad {

 
   public: 
   	   PreLoad();
   	   ~PreLoad();


       void handleMessages(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
   	 void callMainBuildWindow() noexcept; 
       bool InstallWindow(HINSTANCE hInstance, int nCmdShow, HWND hWnd);


 private: 

   bool waitOrNorToExitConsole = true;
   VkDll losDLL;
   
  };  