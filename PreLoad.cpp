// Loskutnikov Games inc. 2022


#include <PreLoad.h>
#include <windows.h>
#include <iostream>

using namespace std::literals;


#ifdef OPENGL_VARIANT



PFNGLUSEPROGRAMPROC glUseProgram;
PFNGLCREATEPROGRAMPROC glCreateProgram;
PFNGLCREATESHADERPROC glCreateShader;

PFNGLSHADERSOURCEPROC  glShaderSource;
PFNGLCOMPILESHADERPROC  glCompileShader;
PFNGLDELETESHADERPROC glDeleteShader;
PFNGLGETSHADERINFOLOGPROC glGetShaderInfoLog;
PFNGLGETSHADERIVPROC glGetShaderiv;
PFNGLATTACHSHADERPROC glAttachShader;
PFNGLLINKPROGRAMPROC glLinkProgram;
PFNGLVALIDATEPROGRAMPROC glValidateProgram;
PFNGLBINDATTRIBLOCATIONPROC glBindAttribLocation;
PFNGLGETUNIFORMLOCATIONPROC glGetUniformLocation;
PFNGLBUFFERDATAPROC glBufferData;
PFNGLVERTEXATTRIBPOINTERPROC glVertexAttribPointer;
PFNGLENABLEVERTEXATTRIBARRAYPROC glEnableVertexAttribArray;
PFNGLBINDBUFFERPROC glBindBuffer;
PFNGLBINDVERTEXARRAYPROC glBindVertexArray;
PFNGLGENBUFFERSPROC glGenBuffers;
PFNGLGENVERTEXARRAYSPROC glGenVertexArrays;
PFNGLACTIVETEXTUREPROC glActiveTexture;
PFNGLUNIFORM1IPROC glUniform1i;
PFNGLUNIFORMMATRIX4FVPROC glUniformMatrix4fv;
PFNGLDELETEPROGRAMPROC glDeleteProgram;
PFNGLDELETEVERTEXARRAYSPROC glDeleteVertexArray;


// PFNWGLSWAPINTERVALEXTPROC wglSwapIntervalEXT;

#endif



PreLoad::PreLoad() {
	

	AllocConsole();
	AttachConsole(GetCurrentProcessId());
	FILE *stream;
	freopen_s(&stream, "CONOUT$", "w+", stdout);
	freopen_s(&stream, "CONOUT$", "w+", stderr);
	SetConsoleTitle(TEXT(" Work in my Render "));

 
  std::cout << " calling this  ! " << "\n";






}



const void PreLoad::setHWND(HWND* hwnds){
 
    hwndLos = hwnds;

RECT rect;
if(GetWindowRect(*hwndLos, &rect)){
     int width = rect.right - rect.left;
  int height = rect.bottom - rect.top;
  std::cout << " my wid & hei " << width <<" " <<height << "\n";
}


}


  PreLoad::~PreLoad(){


  }


   const bool PreLoad::LoadingOpenGLPrograms(int width, int height, HDC cinte)  {
 
     std::cout << "start loading resources " << "\n";

     mainContext = cinte;
     glViewport(0, 0, width, height);

     loadingAllElements = true;


     return true;
   }

const void PreLoad::CallingLoadingExtension() const noexcept{


#ifdef OPENGL_VARIANT
    
    glCreateProgram = (PFNGLCREATEPROGRAMPROC)wglGetProcAddress("glCreateProgram");
    glUseProgram = (PFNGLUSEPROGRAMPROC)wglGetProcAddress("glUseProgram");
    glCreateShader = (PFNGLCREATESHADERPROC)wglGetProcAddress("glCreateShader");
    glShaderSource = (PFNGLSHADERSOURCEPROC)wglGetProcAddress("glShaderSource");
    glCompileShader = (PFNGLCOMPILESHADERPROC)wglGetProcAddress("glCompileShader");
    glDeleteShader = (PFNGLDELETESHADERPROC)wglGetProcAddress("glDeleteShader");
    glGetShaderInfoLog = (PFNGLGETSHADERINFOLOGPROC)wglGetProcAddress("glGetShaderInfoLog");
    glGetShaderiv = (PFNGLGETSHADERIVPROC)wglGetProcAddress("glGetShaderiv");
    glAttachShader = (PFNGLATTACHSHADERPROC)wglGetProcAddress("glAttachShader");

    glLinkProgram = (PFNGLLINKPROGRAMPROC)wglGetProcAddress("glLinkProgram");
    glValidateProgram = (PFNGLVALIDATEPROGRAMPROC)wglGetProcAddress("glValidateProgram");
    glBindAttribLocation = (PFNGLBINDATTRIBLOCATIONPROC)wglGetProcAddress("glBindAttribLocation");
    glGetUniformLocation = (PFNGLGETUNIFORMLOCATIONPROC)wglGetProcAddress("glGetUniformLocation");
    glBufferData = (PFNGLBUFFERDATAPROC)wglGetProcAddress("glBufferData");
    glVertexAttribPointer = (PFNGLVERTEXATTRIBPOINTERPROC)wglGetProcAddress("glVertexAttribPointer");
    glEnableVertexAttribArray = (PFNGLENABLEVERTEXATTRIBARRAYPROC)wglGetProcAddress("glEnableVertexAttribArray");
    glBindBuffer = (PFNGLBINDBUFFERPROC)wglGetProcAddress("glBindBuffer");
    glBindVertexArray = (PFNGLBINDVERTEXARRAYPROC)wglGetProcAddress("glBindVertexArray");
    glGenBuffers = (PFNGLGENBUFFERSPROC)wglGetProcAddress("glGenBuffers");
    glGenVertexArrays = (PFNGLGENVERTEXARRAYSPROC)wglGetProcAddress("glGenBuffers");
    glActiveTexture = (PFNGLACTIVETEXTUREPROC)wglGetProcAddress("glActiveTexture");
    glUniform1i = (PFNGLUNIFORM1IPROC)wglGetProcAddress("glUniform1i");
    glUniformMatrix4fv = (PFNGLUNIFORMMATRIX4FVPROC)wglGetProcAddress("glUniformMatrix4fv");

    glDeleteProgram = (PFNGLDELETEPROGRAMPROC)wglGetProcAddress("glDeleteProgram");
    glDeleteVertexArray = (PFNGLDELETEVERTEXARRAYSPROC)wglGetProcAddress("glDeleteVertexArray");
  
    // wglChoosePixelFormatARB = (PFNWGLCHOOSEPIXELFORMATARBPROC)wglGetProcAddress("wglChoosePixelFormatARB");
    // wglCreateContextAttribsARB = (PFNWGLCREATECONTEXTATTRIBSARBPROC)wglGetProcAddress("wglCreateContextAttribsARB");
    // wglSwapIntervalEXT = (PFNWGLSWAPINTERVALEXTPROC)wglGetProcAddress("wglSwapIntervalEXT");

#endif

  }


const void PreLoad::QuitToApp() const noexcept{

  std::cout <<  " exit in PreLoad " << " \n";
  FreeConsole(); // not working !!! 
}

  void PreLoad::callMainBuildWindow() noexcept{

 

      std::cout <<  " count my building ! " << "\n";
     
    //     if (waitOrNorToExitConsole){
           
    //         while(1){

    //         }
          
    // }else{
    	
    // 	std::this_thread::sleep_for(8s);

    // }
       

  }



 void PreLoad::handleMessages(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam){
  
        std::cout << " in handle messages " << "\n";

 } 


 bool PreLoad::InstallWindow(HINSTANCE hInstance, int nCmdShow){


   return false;
 }


 const void PreLoad::PreRender() const
 { 

   if(loadingAllElements){
 
     MainRender();
      
   }else {
    std::cout << " PreRender " << "\n";
   }


 }



  const void PreLoad::MainRender() const noexcept {
      

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.921F, 0.901F, 0.84F, 1.0F);



  SwapBuffers(mainContext);


  }