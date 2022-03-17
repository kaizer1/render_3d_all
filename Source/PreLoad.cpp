// Loskutnikov Games inc. 2022


#include <PreLoad.h>
#include <string>
#include <windows.h>
#include <iostream>
#include <fstream>

using namespace std::literals;
static constexpr auto VERTEX_OFFSET = 0;

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

//PFNGLDRAWARRAYSPROC glDrawArrays;


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
     mainWidth = (int32_t)width;
     mainHeight = (int32_t)height;
     glViewport(0, 0, width, height);


    glGenVertexArrays(1, &testRec.vao);
    glBindVertexArray(testRec.vao);
    testRecrangleProgram = glCreateProgram();


     //GLuint vertexOne = loadGLShader(GL_VERTEX_SHADER, vertexShader); // loading shader for .h 
     //GLuint fragmeOne = loadGLShader(GL_FRAGMENT_SHADER, fragmentShader); // **** 
     GLuint vertexOne = loadGLShaderRes(GL_VERTEX_SHADER, "assets/Shaders/ver1.vert"); // loading .vert .frag  to path 
     GLuint fragmeOne = loadGLShaderRes(GL_FRAGMENT_SHADER, "assets/Shaders/fra1.frag"); 
     //GLuint vertexOne = loadGLShader(GL_VERTEX_SHADER, "assets/Shaders/vertex.glsl"); // loading .vert .frag  to path 
     //GLuint fragmeOne = loadGLShader(GL_FRAGMENT_SHADER, "assets/Shaders.fragment.glsl");


    
     glAttachShader(testRecrangleProgram, vertexOne);
     glAttachShader(testRecrangleProgram, fragmeOne);
     glLinkProgram(testRecrangleProgram);
     LinkProgramLos(testRecrangleProgram);
     glValidateProgram(testRecrangleProgram);

    
     glBindAttribLocation(testRecrangleProgram, 0, "vertex_main");
     glBindAttribLocation(testRecrangleProgram, 1, "color_main");
     matrixTestRect = glGetUniformLocation(testRecrangleProgram, "matrix_main");

        

     float  aVertexTestRect [9]= {
         0.2f, 0.4f, 0.0f,
         0.5f, 0.9f, 0.0f,
         1.0f, 0.4f, 0.0f 
     };

    float aFragmetnRect [6]= {
       0.238f, 0.218f,
       0.873f, 0.031f,
       0.461f, 0.001f
    };



        GLuint bufferf1, bufferf2, bufferf3, buUnirr4;
        glGenBuffers(1, &bufferf1);
        glGenBuffers(1, &bufferf2);
        //glGenBuffers(1, &bufferf3);
        //glGenBuffers(1, &buUnirr4);


          glBindBuffer(GL_ARRAY_BUFFER, bufferf1);
        {
            glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(float), aVertexTestRect, GL_STATIC_DRAW);
            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (const void*) VERTEX_OFFSET);
            glEnableVertexAttribArray(0);
        }

        glBindBuffer(GL_ARRAY_BUFFER, bufferf2);
        {
            glBufferData(GL_ARRAY_BUFFER,  6 * sizeof(float), aFragmetnRect, GL_STATIC_DRAW);
            glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, (const void*) VERTEX_OFFSET);
            glEnableVertexAttribArray(1);
        }
       
        // glBindBuffer(GL_ARRAY_BUFFER, bufferf3);
        // {
        //     glBufferData(GL_ARRAY_BUFFER,  normCountAssets * sizeof(float), bNPillar, GL_STATIC_DRAW);
        //     glVertexAttribPointer(2, 3, GL_HALF_FLOAT, GL_FALSE, 0, (const void*) VERTEX_OFFSET);
        //     glEnableVertexAttribArray(2);
        // }

        //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buUnirr4);

        // BIGS ERROR !!!
        // RY glBufferData (GLenum target, GLsizeiptr size, const void *data, GLenum usage)
       // GLsizei size = losIndexesAssets * sizeof(GL_UNSIGNED_SHORT);  // was losIndexesAssets * sizeof(GL_UNSIGNED_SHORT)
        //GLushort 

        //glBufferData(GL_ELEMENT_ARRAY_BUFFER, losIndexesAssets * sizeof(unsigned  short), bIndexAssets, GL_STATIC_DRAW);

        glBindVertexArray(0);

 
 std::cout << "we are resources loaded 3" << "\n";


    // GLuint computeCount = glGetUniformLocation(normComputeProgram, "vertex");
    // GLuint uvCount = glGetUniformLocation(normComputeProgram, "U");
    // GLuint indexCount = glGetUniformLocation(normComputeProgram, "indexCount");


   // loading astc texture's  etc, astc, dds, webp 
   


   // loading 3D model - gltf !  gltf, fbx, obj, filamesh   



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
    //glDrawArrays = (PFNGLDRAWARRAYSPROC)wglGetProcAddress("glDrawArrays");
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


void PreLoad::PreRender()
 { 

   if(loadingAllElements){
 
     MainRender();
      
   }else {
    std::cout << " PreRender " << "\n";
   }


 }

static std::string textFileRead(const char *fileName);

static std::string textFileRead(const char *fileName) {
    std::string fileString = std::string(); // A string for storing the file contents
    std::string line = std::string(); // A string for holding the current line

    std::ifstream file(fileName); // Open an input stream with the selected file
    if (file.is_open()) { // If the file opened successfully
        while (!file.eof()) { // While we are not at the end of the file
            getline(file, line); // Get the current line
            fileString.append(line); // Append the line to our file string
            fileString.append("\n"); // Appand a new line character
        }
        file.close(); // Close the file
    }

    return fileString; // Return our string
}



 




 // loading .vert and .frag 
GLuint PreLoad::loadGLShaderRes(GLenum enumsha, const char* shaderSource )
{

  GLuint shaderL = 1;

    std::cout << " my path == " << shaderSource << "\n";
  
   fs::path p = shaderSource;

      if(fs::exists(p)){
        std::cout << "ok files exists " << "\n";



    GLuint shaderL;
    GLint compiled;

    shaderL = glCreateShader(enumsha);
    // logRun(" shader the 1 ! ");
 
 std::string vsText = textFileRead(shaderSource); 
  const char *vertexText = vsText.c_str();


    if(shaderL != 0)
    {
        //  logRun(" shader the 2 ! ");
        glShaderSource(shaderL, 1, &vertexText, NULL);

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
                    logBuffer = nullptr;
                }
                glDeleteShader(shaderL);
                shaderL = 0;
            }
        }
        std::cout << " compiled shader Cube "<< "\n";
    }
    return shaderL;

}


const void PreLoad::loadMyMatrix() const noexcept {

 
}


 
  void PreLoad::callChange() noexcept {
       rotateY += 1.0f;
  }

 void PreLoad::MainRender() noexcept {
      

 // start render time 

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.921F, 0.901F, 0.84F, 1.0F);

 
    loadMyMatrix();


        LosVector3 eye2 = LosVector3{0.2f, 1.3f, 1.9f};  // secondsCamera
     LosVector3 eye3 = LosVector3{-2.6f, 2.2f, -0.4f};  // thirdsCamera
     LosVector3 up {0, 1, 0};
    LosVector3 cent = LosVector3 {0.4f, 0.0f, 0.0f};
     LosMatrix4_4 er = identity();

 // w/ h
   LosMatrix4_4 pers = perspectiveLosRithg(45.0f, (float) mainWidth/mainHeight, 0.1f, 100.f);
   LosMatrix4_4  LookAt =  LookAt_RightLos(eye2, cent, up, er);
   //std::cout <<" in render " << "\n";

 

 // 2d 




  // 3d 


    glUseProgram(testRecrangleProgram); // forgot to add this program and get error : uniform data type is an invalid data type
    glBindVertexArray(testRec.vao);

    // glActiveTexture(GL_TEXTURE0);
    // glUniform1i(testRectImage, 0);
    // glBindTexture(GL_TEXTURE_2D, astcIDBall); // was  BallRecamp

    LosMatrix4_4 LosBamboo= identity();
    LosBamboo.ScaleLos(LosVector3(2.0f, 2.0f, 2.0f));
    LosBamboo.rotateLosY(rotateY);
    LosMatrix4_4 finalTestMatrix = pers * LookAt * LosBamboo;


    glUniformMatrix4fv(matrixTestRect, 1, GL_FALSE, &finalTestMatrix.elements[0][0]);
    glDrawArrays(GL_TRIANGLES, 0, 3); // no needed to proc exists !!

   // callChange();
    rotateY += 1.0f;


  SwapBuffers(mainContext);
 
 // end's render time 

  }