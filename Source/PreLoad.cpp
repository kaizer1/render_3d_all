// Loskutnikov Games inc. 2022


#include <PreLoad.h>
#include <windows.h>
#include <iostream>

using namespace std::literals;


PreLoad::PreLoad() {
	

	AllocConsole();
	AttachConsole(GetCurrentProcessId());
	FILE *stream;
	freopen_s(&stream, "CONOUT$", "w+", stdout);
	freopen_s(&stream, "CONOUT$", "w+", stderr);
	SetConsoleTitle(TEXT(" Work in my Render "));

 
  std::cout << " calling this  ! " << "\n";


}



  PreLoad::~PreLoad(){


  }



  void PreLoad::callMainBuildWindow() noexcept{

 

      std::cout <<  " count my Direct X  ! " << "\n";
     
        if (waitOrNorToExitConsole){
           
            while(1){

            }
          
    }else{
    	
    	std::this_thread::sleep_for(8s);

    }
       

  }



 void PreLoad::handleMessages(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam){
  
        std::cout << " in handle messages " << "\n";

    
 } 


 bool PreLoad::InstallWindow(HINSTANCE hInstance, int nCmdShow){


   return false;
 }