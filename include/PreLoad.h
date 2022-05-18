// Loskuntikov Games inc. 2022
 
#include <windows.h>
#include <iostream>
#include <thread>
#include <vector>

#include <d3d12.h>
#include <D3d12SDKLayers.h>

#include <dxgi1_4.h>



class PreLoad {

 
   public: 
   	   PreLoad();
   	   ~PreLoad();


       void handleMessages(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
   	   void callMainBuildWindow() noexcept; 
       bool InstallWindow(HINSTANCE hInstance, int nCmdShow, HWND* hwnd);
       void QuitToApp();


 private: 

   bool waitOrNorToExitConsole = true;

  };  