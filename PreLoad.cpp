// Loskutnikov Games inc. 2022


#include <PreLoad.h>
#include <windows.h>
#include <iostream>

using namespace std::literals;


#ifdef OPENGL_VARIANT

#include <ShaderData.h>


#include <filesystem>
namespace fs = std::filesystem;



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
PFNGLGETPROGRAMIVPROC glGetProgramiv; 
PFNGLGETPROGRAMINFOLOGPROC glGetProgramInfoLog;


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

     CallingLoadingExtension();

     mainContext = cinte;
     glViewport(0, 0, width, height);
 
 std::cout << "we are resources loaded 2" << "\n";
    //TODO: sdfwf

   // build simple program 
 std::cout << "we are resources loaded 2.1" << "\n";
    glGenVertexArrays(1, &VAo_toSimpleProgram);
     std::cout << "we are resources loaded 2.2" << "\n";
    glBindVertexArray(VAo_toSimpleProgram);
 std::cout << "we are resources loaded 3" << "\n";
     simpleProgram = glCreateProgram();
      std::cout << "we are resources loaded 4" << "\n";


   // GLuint vertexOne = loadGLShader(GL_VERTEX_SHADER, vertexShader); // loading shader for .h 
   // GLuint fragmeOne = loadGLShader(GL_FRAGMENT_SHADER, fragmentShader); // **** 

     
       
     GLuint vertexOne = loadGLShaderRes(GL_VERTEX_SHADER, "assets/Shaders/ver1.vert"); // loading .vert .frag  to path 
     GLuint fragmeOne = loadGLShaderRes(GL_FRAGMENT_SHADER, "assets/Shaders/fra1.frag"); 


     //GLuint vertexOne = loadGLShader(GL_VERTEX_SHADER, "assets/Shaders/vertex.glsl"); // loading .vert .frag  to path 
     //GLuint fragmeOne = loadGLShader(GL_FRAGMENT_SHADER, "assets/Shaders.fragment.glsl");



    // glAttachShader(simpleProgram, vertexOne);
    // glAttachShader(simpleProgram, fragmeOne);
    // glLinkProgram(simpleProgram);
    // LinkProgramLos(simpleProgram);
    // glValidateProgram(simpleProgram);
    // glDeleteShader(vertexOne);
    // glDeleteShader(fragmeOne);



 
 std::cout << "we are resources loaded 3" << "\n";


    // GLuint computeCount = glGetUniformLocation(normComputeProgram, "vertex");
    // GLuint uvCount = glGetUniformLocation(normComputeProgram, "U");
    // GLuint indexCount = glGetUniformLocation(normComputeProgram, "indexCount");


   // loading astc texture's 
   


   // loading 3D model - gltf !    



 std::cout << "we are resources loaded final " << "\n";
     loadingAllElements = true;


     return true;
   }



void  PreLoad::LinkProgramLos(GLuint program)
{
    GLint linkStatus = GL_FALSE;
    std::cout << " setAxis 05 "<< "\n";
    glGetProgramiv(program, GL_LINK_STATUS, &linkStatus);
    if(linkStatus != GL_TRUE)
    {
        std::cout << "Not sucseecs " << "\n";
        GLint bufLength = 0;
        glGetProgramiv(program, GL_INFO_LOG_LENGTH, &bufLength);
        if(bufLength > 0)
        {
            char* logBuffer = (char*) malloc(bufLength);

            if(logBuffer != NULL)
            {
                glGetProgramInfoLog(program, bufLength, NULL, logBuffer);
                std::cout << " Count not link program setAxis: " << logBuffer << "\n";
                free(logBuffer);
                logBuffer = NULL;
            }
        }
        std::cout << " not compile Programs etAxis " << "\n";
        glDeleteProgram(program);
    }
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
    glGenVertexArrays = (PFNGLGENVERTEXARRAYSPROC)wglGetProcAddress("glGenVertexArrays");
    glActiveTexture = (PFNGLACTIVETEXTUREPROC)wglGetProcAddress("glActiveTexture");
    glUniform1i = (PFNGLUNIFORM1IPROC)wglGetProcAddress("glUniform1i");
    glUniformMatrix4fv = (PFNGLUNIFORMMATRIX4FVPROC)wglGetProcAddress("glUniformMatrix4fv");

    glDeleteProgram = (PFNGLDELETEPROGRAMPROC)wglGetProcAddress("glDeleteProgram");
    glDeleteVertexArray = (PFNGLDELETEVERTEXARRAYSPROC)wglGetProcAddress("glDeleteVertexArray");

    glGetProgramiv = (PFNGLGETPROGRAMIVPROC)wglGetProcAddress("glGetProgramiv");
    glGetProgramInfoLog = (PFNGLGETPROGRAMINFOLOGPROC)wglGetProcAddress("glGetProgramInfoLog");
    
  
  
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

    

//      DWORD dwResult;    
// for (DWORD i=0; i< XUSER_MAX_COUNT; i++ )
// {
//     XINPUT_STATE state;
//     ZeroMemory( &state, sizeof(XINPUT_STATE) );

//     // Simply get the state of the controller from XInput.
//     dwResult = XInputGetState( i, &state );

//     if( dwResult == ERROR_SUCCESS )
//     { 
//        std::cout << " controller is connected ! " << "\n";
//         // Controller is connected
//     }
//     else
//     {
//       std::cout << " controller is diSconnected ! " << "\n";
//         // Controller is not connected
//     }
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


GLuint PreLoad::loadGLShaderRes(GLenum enumsha, const char* shaderSource )
{

  GLuint shaderL = 1;

    std::cout << " my path == " << shaderSource << "\n";
  
   fs::path p = shaderSource;

      if(fs::exists(p)){
        std::cout << "ok files exists " << "\n";

  
   GLuint shaderL;
    GLint compiled;
// ShaderT
   //struct  ShaderT s{};
    // logRun(" shader source == %s \n", shaderSource);

    shaderL = glCreateShader(enumsha);
    // logRun(" shader the 1 ! ");
 
  

   FILE* shaderFile = fopen( shaderSource, "r");
int fileSize = 0;
char* vertex_shader = NULL;

//Getting File Size
fseek( shaderFile, 0, SEEK_END );
fileSize = ftell( shaderFile );
rewind( shaderFile );
 std::cout << " size my shader = " << fileSize << "\n";


vertex_shader = (char*)malloc( sizeof( char) * (fileSize+1) );
fread( vertex_shader, sizeof( char ), fileSize, shaderFile );
//vertex_shader[ fileSize] = '\0';
fclose( shaderFile );



    if(shaderL != 0)
    {
        //  logRun(" shader the 2 ! ");
        glShaderSource(shaderL, 1, (const GLchar**)&vertex_shader, NULL);

        //   logRun(" shader the 2.5s ! ");


        glCompileShader(shaderL);


        //logRun(" shader the 3s ! ");
        compiled = 0;
        glGetShaderiv(shaderL, GL_COMPILE_STATUS, &compiled);
        if(compiled != GL_TRUE)
        {

            std::cout <<  "compiled not true !" << "\n";
            GLint infoLen = 0;
            glGetShaderiv(shaderL, GL_INFO_LOG_LENGTH, &infoLen);
            if(infoLen > 0)
            {

                char * logBuffer = (char*) malloc(infoLen);
                if(logBuffer != NULL)
                {
                    glGetShaderInfoLog(shaderL, infoLen, NULL, logBuffer);
                    std::cout << " Could not Compile shader " << logBuffer << "\n";
                    free(logBuffer);
                    logBuffer = NULL;
                }
                glDeleteShader(shaderL);
                shaderL = 0;
            }
        }
        std::cout << " compiled shader Cube "<< "\n";
    }














      }else {
         std::cout << " files not exists !" << "\n";
      }
   // filesystem check file exists ! 


  return shaderL;

}



GLuint  PreLoad::loadGLShader(GLenum enumsha, const char* shaderSource ) {
    
    GLuint shaderL;
    GLint compiled;
// ShaderT
   //struct  ShaderT s{};
    // logRun(" shader source == %s \n", shaderSource);

    shaderL = glCreateShader(enumsha);
    // logRun(" shader the 1 ! ");


    if(shaderL != 0)
    {
        //  logRun(" shader the 2 ! ");
        glShaderSource(shaderL, 1, &shaderSource, NULL);

        //   logRun(" shader the 2.5s ! ");


        glCompileShader(shaderL);


        //logRun(" shader the 3s ! ");
        compiled = 0;
        glGetShaderiv(shaderL, GL_COMPILE_STATUS, &compiled);
        if(compiled != GL_TRUE)
        {

            std::cout <<  "compiled not true !" << "\n";
            GLint infoLen = 0;
            glGetShaderiv(shaderL, GL_INFO_LOG_LENGTH, &infoLen);
            if(infoLen > 0)
            {

                char * logBuffer = (char*) malloc(infoLen);
                if(logBuffer != NULL)
                {
                    glGetShaderInfoLog(shaderL, infoLen, NULL, logBuffer);
                    std::cout << " Could not Compile shader " << logBuffer << "\n";
                    free(logBuffer);
                    logBuffer = NULL;
                }
                glDeleteShader(shaderL);
                shaderL = 0;
            }
        }
        std::cout << " compiled shader Cube "<< "\n";
    }
    return shaderL;

}

  const void PreLoad::MainRender() const noexcept {
      

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.921F, 0.901F, 0.84F, 1.0F);

 
   //std::cout <<" in render " << "\n";


  SwapBuffers(mainContext);


  }