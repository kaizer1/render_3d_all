// Loskuntikov Games inc. 2022
 
#include <windows.h>
#include <iostream>
#include <thread>
#include <vector>
#include <sstream>

#ifdef OPENGL_VARIANT
//#include <ASTC.h>
// #include <GL/GL.h>
// #include <GL/glext.h>

#include <glmain.h>
//#include <glad.h>

#endif


// TODO: Controllers 

//#include <xinput.h> 



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
       const void setHWND(HWND* hwnds);



 private: 

   bool waitOrNorToExitConsole = true;
   bool loadingAllElements = false;
  const void MainRender() const noexcept;
  HDC mainContext;
  HWND *hwndLos = nullptr;
  GLuint  loadGLShader(GLenum enumsha, const char* shaderSource );
  void  LinkProgramLos(GLuint program);

  GLuint VAo_toSimpleProgram;
  GLuint simpleProgram;

  };  