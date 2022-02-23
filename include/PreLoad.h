// Loskuntikov Games inc. 2022
 
#include <windows.h>
#include <iostream>
#include <thread>
#include <vector>


#ifdef OPENGL_VARIANT
#include <GL/GL.h>
#include <sstream>
#include <GL/glext.h>
//#include <glad.h>

#endif

class PreLoad {

 
   public: 
   	   PreLoad();
   	   ~PreLoad();


       void handleMessages(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
   	 void callMainBuildWindow() noexcept; 
       bool InstallWindow(HINSTANCE hInstance, int nCmdShow);
       const void QuitToApp() const noexcept;
       const void CallingLoadingExtension() const noexcept;
       const void PreRender() const;
       const bool LoadingOpenGLPrograms(int w, int h, HDC cinte);



 private: 

   bool waitOrNorToExitConsole = true;
   bool loadingAllElements = false;
  const void MainRender() const noexcept;
  HDC mainContext;

  };  