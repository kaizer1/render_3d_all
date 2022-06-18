// Loskuntikov Games inc. 2022
 
#include <windows.h>
#include <iostream>
#include <thread>
#include <vector>

#include <vulkan/vulkan.h>
#include <losVulkan.hpp>
#include <string>
#include <memory>


class PreLoad {

 
   public: 
   	   PreLoad();
   	   ~PreLoad();


       void handleMessages(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
   	   void callMainBuildWindow() noexcept; 
       bool InstallWindow(HINSTANCE hInstance, int nCmdShow, HWND hWnd);
       VkInstance  losInstance;
       void PreDestroy();
       VkPhysicalDeviceMemoryProperties myPhysicalDeviceMemoryPropertises2;

 private: 

   bool waitOrNorToExitConsole = true;
   // was // VkDll losDLL;
   std::unique_ptr<VkDll> losDLL; 
   VkDebugReportCallbackEXT cb1;
  };  