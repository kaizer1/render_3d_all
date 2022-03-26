// Loskutnikov Games inc. 2022


#include <PreLoad.h>
#include <string>
#include <windows.h>
#include <iostream>
#include <fstream>
#include <chrono>

using namespace std::literals;
static constexpr auto VERTEX_OFFSET = 0;


#include <ShaderData.h>

#include <filesystem>
namespace fs = std::filesystem;

static const int OFFSEtF = 0;

enum textureFormat {
    kformatDefaultAuto = 0,
    kFormat5551,
    kFormat565,

    webpk8888,
    webpk888,
};


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
//PFNGLGETSTRINGPROC glGetString;
GLDEBUGPROCARB  glDebug;
PFNGLDEBUGMESSAGECONTROLARBPROC glDebugMessageControlARB;
PFNGLDEBUGMESSAGEINSERTARBPROC glDebugMessageInsertARB;
PFNGLDEBUGMESSAGECALLBACKARBPROC glDebugMessageCallbackARB;
PFNGLGETDEBUGMESSAGELOGARBPROC glGetDebugMessageLogARB;
// glGenTextures
// glBindTexture
// glTexParameteri
// glCompressedTexImage2D
//PFNGLGENTEXTURESPROC  glGenTextures;
//PFNGLBINDTEXTUREPROC  glBindTexture;
//PFNGLTEXPARAMETERIPROC  glTexParameteri;
PFNGLCOMPRESSEDTEXIMAGE2DPROC glCompressedTexImage2D;
PFNGLPUSHDEBUGGROUPPROC glPushDebugGroup;
PFNGLPOPDEBUGGROUPPROC glPopDebugGroup;


PFNGLISPROGRAMPROC glIsProgram;
PFNGLISSHADERPROC glIsShader;
// PFNWGLSWAPINTERVALEXTPROC wglSwapIntervalEXT;





inline void checkError(int a){

  
    auto erroLos = glGetError();

     if(erroLos != GL_NO_ERROR){
         std::cout << " error exists ! " << a << "\n";

 
  switch(erroLos){

    case GL_INVALID_ENUM: {

   std::cout << "GL_INVALID_ENUM \nAn unacceptable value is specified for an enumerated argument. The offending command is ignored and has no other side effect than to set the error flag. " << "\n";

    }
    break;
  

  case GL_INVALID_VALUE: {

   std::cout << "GL_INVALID_VALUE \nA numeric argument is out of range. The offending command is ignored and has no other side effect than to set the error flag." << "\n";

    }
    break;


 case GL_INVALID_OPERATION: {

   std::cout << "GL_INVALID_OPERATION\nThe specified operation is not allowed in the current state. The offending command is ignored and has no other side effect than to set the error flag." << "\n";

    }
    break;


 case GL_INVALID_FRAMEBUFFER_OPERATION: {

   std::cout << "GL_INVALID_FRAMEBUFFER_OPERATION\nThe framebuffer object is not complete. The offending command is ignored and has no other side effect than to set the error flag." << "\n";

    }
    break;



 case GL_OUT_OF_MEMORY: {

   std::cout << "GL_OUT_OF_MEMORY\nThere is not enough memory left to execute the command. The state of the GL is undefined, except for the state of the error flags, after this error is recorded." << "\n";

    }
    break;



 case GL_STACK_UNDERFLOW: {

   std::cout << "GL_STACK_UNDERFLOW\nAn attempt has been made to perform an operation that would cause an internal stack to underflow." << "\n";

    }
    break;



 case GL_STACK_OVERFLOW: {

   std::cout << "GL_STACK_OVERFLOW\nAn attempt has been made to perform an operation that would cause an internal stack to overflow." << "\n";

    }
    break;



  }
  









     }else{
        std::cout << " no error ! "  << a << "\n"; 






     }
}





PreLoad::PreLoad() : rotateY {0.0f} {
	

	AllocConsole();
	AttachConsole(GetCurrentProcessId());
	FILE *stream;
	freopen_s(&stream, "CONOUT$", "w+", stdout);
	freopen_s(&stream, "CONOUT$", "w+", stderr);
	SetConsoleTitle(TEXT(" Work in my Render "));
    
 
  std::cout << " calling this  ! " << "\n";






}


static void glErrorLoskutnikov(GLenum source, GLenum type, GLuint id, GLenum severity,
                               GLsizei length, const GLchar* message, const void* userParam);



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


    callProgramGL();


     glDebugMessageControlARB(GL_DONT_CARE, GL_DONT_CARE, GL_DONT_CARE, 0, NULL, GL_TRUE);
     glDebugMessageInsertARB( GL_DEBUG_SOURCE_APPLICATION, GL_DEBUG_TYPE_MARKER, 100, 
        GL_DEBUG_SEVERITY_NOTIFICATION, -1, "los mes debug 01 ");

     glPushDebugGroup(GL_DEBUG_SOURCE_APPLICATION, 1, -1, "los mes 02 ");

     glDebugMessageCallbackARB(glErrorLoskutnikov, NULL);

    std::vector<GLuint>  a = {2147483647};
    glDebugMessageControlARB(DEBUG_SOURCE_OTHER, DEBUG_TYPE_PERFORMANCE, GL_DONT_CARE,
                             static_cast<GLuint>(a.size()), a.data(), GL_FALSE );

   

    glDebugMessageInsertARB(GL_DEBUG_SOURCE_APPLICATION, GL_DEBUG_TYPE_MARKER, 100, 
    GL_DEBUG_SEVERITY_NOTIFICATION, -1, "los mes 03 ");



    glPopDebugGroup();

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

  


     //checkError();
     glGetError();
    
     glBindAttribLocation(testRecrangleProgram, 0, "vertex_main");
     glBindAttribLocation(testRecrangleProgram, 1, "color_main");
     matrixTestRect = glGetUniformLocation(testRecrangleProgram, "matrix_main");

        glGetError();

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



checkError(0);
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
 
        glUseProgram(0);
        glBindVertexArray(0);
  checkError(1);



     l3DViewProgram = glCreateProgram();

 
      if(glIsProgram(l3DViewProgram)){
           std::cout << " ok l3DViewProgram is a program GL " << "\n";
      }else{
         std::cout << " not a program ! " << "\n";
      }




         checkError(4);
     GLuint shader3D_vertex = loadGLShaderRes(GL_VERTEX_SHADER, "assets/Shaders/l3dview.vert"); // loading .vert .frag  to path 
        checkError(5);
     GLuint shader3D_fragment = loadGLShaderRes(GL_FRAGMENT_SHADER, "assets/Shaders/l3dview.frag"); 
    checkError(3); 


      if (glIsShader(shader3D_vertex)){
   std::cout << " ok shader 1" << "\n";
      } else {
 std::cout << " not a shader 1 ! " << "\n";
      }


      if (glIsShader (shader3D_fragment)){
   std::cout << " ok shader 2" << "\n";
      }else{
               std::cout << " not a shader 2 ! " << "\n";
      }

     glAttachShader(l3DViewProgram, shader3D_vertex); // error ???
        checkError(7);
     glAttachShader(l3DViewProgram, shader3D_fragment); // error ???
        checkError(8); 
     glLinkProgram(l3DViewProgram);
         checkError(6);
     LinkProgramLos(l3DViewProgram);
     glValidateProgram(l3DViewProgram);

  
     //checkError();
    checkError(2);
    
     glBindAttribLocation(l3DViewProgram, 0, "vertex3d");
     glBindAttribLocation(l3DViewProgram, 1, "fragment3d");
     //glBindAttribLocation(l3DViewProgram, 2, "normal3d");
     matrix3dModelView = glGetUniformLocation(l3DViewProgram, "matrix3d_mv");
     matrix3dPositionView = glGetUniformLocation(l3DViewProgram, "matrix3d_p"); 
     vLight = glGetUniformLocation(l3DViewProgram, "vLight"); 
     vCam = glGetUniformLocation(l3DViewProgram, "vCam"); 
     samplerSword  = glGetUniformLocation(l3DViewProgram, "basecolor");

       glGetError();

       // Loaded 3D model 
       main3DObjects = LosModel();
       Loaded3DStaticModel(main3DObjects,"assets/Models/OurSword.bin", true);
        std::cout << " ok loaded model is " << "\n";
       // Loaded texture to this model
        checkError(29);
 

   GLint numberSupportTexture;
   glGetIntegerv(GL_NUM_COMPRESSED_TEXTURE_FORMATS, &numberSupportTexture);
       std::cout << " number supported texture == " << numberSupportTexture << "\n";
      GLint* textureSupport= new GLint[numberSupportTexture];
    glGetIntegerv(GL_COMPRESSED_TEXTURE_FORMATS, textureSupport);

   std::cout << " my texture = " << &textureSupport[0] << "\n";

             // for (auto tex : &textureSupport){
             //     std::cout << " my tex suppo " << tex << "\n";
             // }
       

       //LoadASTCImage("assets/Texture/SwordWood12.astc", losFormatASTC::tenForTen, &swordID);
       loadDDSTexture("assets/Texture/losSword.dds", &swordID);
    
checkError(30);

 
 std::cout << "we are resources loaded full" << "\n";


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
    GLint linkStatus; // was = GL_FALSE;
    std::cout << " setAxis 05 "<< "\n";
    glGetProgramiv(program, GL_LINK_STATUS, &linkStatus);
    std::cout << " my link status == " << linkStatus << " \n";
    if(linkStatus != GL_TRUE)
    {
        std::cout << "Not sucseecs " << "\n";
        GLint bufLength = 0;
        glGetProgramiv(program, GL_INFO_LOG_LENGTH, &bufLength);
        std::cout << " my bufLenght == " << bufLength << " \n";
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
        } else {
             std::cout << " bufLength <= o " << "\n";
        }
        std::cout << " not compile Programs etAxis " << "\n";
        glDeleteProgram(program);
    }
}



static void glErrorLoskutnikov(GLenum source, GLenum type, GLuint id, GLenum severity,
                               GLsizei length, const GLchar* message, const void* userParam) {


//    koPP* iptr22 = (koPP*)userParam;
//
//     std::string los{__FILE__};
//     constexpr int LineNumber = __LINE__;
//    std::cout(" los String == %s \n", los.c_str());
//    std::string::size_type n = los.rfind("/");
//    // print(n, s);
//    std::string finalE = los.substr(n);
//    finalE.erase(0, 1);
//    std::cout(" my substr == %s , %d\n", finalE.c_str(), LineNumber);
    std::cout <<  "LosDebug: "<< message << " s= " << source << " type = "<<  type << " \n";

      switch (source){

          case DEBUG_SOURCE_API:
              std::cout << " DEBUG_SOURCE_API " << "\n";
              break;

          case DEBUG_SOURCE_WINDOW_SYSTEM:
              std::cout << " GL_DEBUG_SOURCE_WINDOW_SYSTEM_ " << "\n";
              break;


          case DEBUG_SOURCE_SHADER_COMPILER:
              std::cout << " GL_DEBUG_SOURCE_SHADER_COMPILER " << "\n";
              break;

          case DEBUG_SOURCE_THIRD_PARTY:
              std::cout << " GL_DEBUG_SOURCE_THIRD_PARTY " << "\n";
              break;

          case DEBUG_SOURCE_APPLICATION:
              std::cout << " GL_DEBUG_SOURCE_APPLICATION "<< "\n";
              break;

          case DEBUG_SOURCE_OTHER:
              std::cout << " GL_DEBUG_SOURCE_OTHER " << "\n";
              break;

          default:
              std::cout << " empty "<< "\n";
              break;

      }


}



 void PreLoad::Loaded3DStaticModel(LosModel& model, const char* nameModel, bool vaos){

 
  std::ifstream t;
 
  std::cout << " start read buffer 3d model " << "\n"; 

   int length;
  t.open(nameModel);      // open input file
   t.seekg(0, std::ios::end);    // go to the end
  length = t.tellg();           // report location (this is the length)
  t.seekg(0, std::ios::beg);    // go back to the beginning
  unsigned char* buffer = new unsigned char[length];
 //  buffer = new char[length];    // allocate memory for a buffer of appropriate dimension
  
   static unsigned int losJokVertex;
  t.read(reinterpret_cast<char*>(&losJokVertex), sizeof(uint32_t));
 
  
   unsigned int losIndexesAssets = 0;
 t.read(reinterpret_cast<char*>(&losIndexesAssets), sizeof(uint32_t));
 
 unsigned int uvCountAssets = 0;
  t.read(reinterpret_cast<char*>(&uvCountAssets), sizeof(uint32_t));

 model.drawIndexs = losIndexesAssets;
  std::cout << " index to draw == " << losIndexesAssets << "\n";

   const int sladkjflkasdjf= 99999;
 
       static const int sdkfjh= losJokVertex;
 //       uint16 ksdflkj;
 // uint16 ksdflksdf[23];
 // uint16 ksdflkssdfdf[sladkjflkasdjf];
 uint16* ksdflkssdfdf= new uint16[losJokVertex];

     //  uint16 aStraw[sladkjflkasdjf];
     t.read(reinterpret_cast<char*>(ksdflkssdfdf), losJokVertex * sizeof(uint16));

  
 //   unsigned short bIndexAssets[losIndexesAssets];
  unsigned short* bIndexAssets = new unsigned short[losIndexesAssets];
   t.read(reinterpret_cast<char*>(bIndexAssets), losIndexesAssets * sizeof(unsigned short));


 // uint16 bUVAssets[uvCountAssets];
    
    uint16* bUVAssets = new uint16[uvCountAssets];
    t.read(reinterpret_cast<char*>(bUVAssets), uvCountAssets * sizeof(uint16));

 
  // this normal ! 


  t.close();   
     
     std::cout << " my buffers " << losJokVertex << " \n";

      
       glGenVertexArrays(1, &model.vao);
       glBindVertexArray(model.vao);
 

       GLuint bufferf1, bufferf2, bufferf3;
        glGenBuffers(1, &bufferf1);
        glGenBuffers(1, &bufferf2);
        glGenBuffers(1, &bufferf3);
   

       glBindBuffer(GL_ARRAY_BUFFER, bufferf1);
        {
            glBufferData(GL_ARRAY_BUFFER, losJokVertex * sizeof(uint16), &ksdflkssdfdf[0], GL_STATIC_DRAW);
            glVertexAttribPointer(0, 3, GL_HALF_FLOAT, GL_FALSE, 0, (const void*) VERTEX_OFFSET);
            glEnableVertexAttribArray(0);
        }

        glBindBuffer(GL_ARRAY_BUFFER, bufferf2);
        {
            glBufferData(GL_ARRAY_BUFFER,  uvCountAssets * sizeof(uint16), &bUVAssets[0], GL_STATIC_DRAW);
            glVertexAttribPointer(1, 2, GL_HALF_FLOAT, GL_FALSE, 0, (const void*) VERTEX_OFFSET);
            glEnableVertexAttribArray(1);
        }


        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferf3);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, losIndexesAssets * sizeof(GL_UNSIGNED_SHORT), &bIndexAssets[0], GL_STATIC_DRAW);


 
  glBindVertexArray(0);

  delete [] ksdflkssdfdf;
  delete [] bIndexAssets;
  delete [] bUVAssets;
  delete [] buffer;



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
    //glGenTextures = (PFNGLGENTEXTURESPROC)wglGetProcAddress("glGenTextures");
    //glBindTexture = (PFNGLBINDTEXTUREPROC)wglGetProcAddress("glBindTexture");
    //glTexParameteri = (PFNGLTEXPARAMETERIPROC)wglGetProcAddress("glTexParameteri");
    glCompressedTexImage2D = (PFNGLCOMPRESSEDTEXIMAGE2DPROC)wglGetProcAddress("glCompressedTexImage2D");
    

    // TODO: enable debug extension  *** GL_ARB_debug_output  ***
    glDebug = (GLDEBUGPROCARB)wglGetProcAddress("glDebug");
    glDebugMessageControlARB = (PFNGLDEBUGMESSAGECONTROLARBPROC)wglGetProcAddress("glDebugMessageControlARB");
    glDebugMessageInsertARB = (PFNGLDEBUGMESSAGEINSERTARBPROC)wglGetProcAddress("glDebugMessageInsertARB");
    glDebugMessageCallbackARB = (PFNGLDEBUGMESSAGECALLBACKARBPROC)wglGetProcAddress("glDebugMessageCallbackARB");
    glGetDebugMessageLogARB = (PFNGLGETDEBUGMESSAGELOGARBPROC)wglGetProcAddress("glGetDebugMessageLogARB");


    glPushDebugGroup = (PFNGLPUSHDEBUGGROUPPROC)wglGetProcAddress("glPushDebugGroup");
    glPopDebugGroup = (PFNGLPOPDEBUGGROUPPROC)wglGetProcAddress("glPopDebugGroup");


    glIsProgram = (PFNGLISPROGRAMPROC)wglGetProcAddress("glIsProgram");
    glIsShader = (PFNGLISSHADERPROC)wglGetProcAddress("glIsShader");
 


    //glGetString = (PFNGLGETSTRINGPROC)wglGetProcAddress("glGetString");
  
    // wglChoosePixelFormatARB = (PFNWGLCHOOSEPIXELFORMATARBPROC)wglGetProcAddress("wglChoosePixelFormatARB");
    // wglCreateContextAttribsARB = (PFNWGLCREATECONTEXTATTRIBSARBPROC)wglGetProcAddress("wglCreateContextAttribsARB");
    // wglSwapIntervalEXT = (PFNWGLSWAPINTERVALEXTPROC)wglGetProcAddress("wglSwapIntervalEXT");

#endif

  }


const void PreLoad::QuitToApp() const noexcept{

  std::cout <<  " exit in PreLoad " << " \n";
  FreeConsole(); // not working !!! 
}


 void PreLoad::handleMessages(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam){
  
        std::cout << " in handle messages " << "\n";
       
       // PreRender();

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

 // GLuint shaderL = 0;

    std::cout << " my path == " << shaderSource << "\n";
  
   fs::path p = shaderSource;

  GLuint  shaderL = glCreateShader(enumsha);
      if(fs::exists(p)){
        std::cout << "ok files exists " << "\n";

    GLint compiled;

 
    // std::cout(" shader the 1 ! ");
 
 std::string vsText = textFileRead(shaderSource); 
  const char *vertexText = vsText.c_str();


    if(shaderL != 0)
    {
          std::cout << " shader not null  " << "\n";
        glShaderSource(shaderL, 1, &vertexText, NULL);

        //   std::cout(" shader the 2.5s ! ");


        glCompileShader(shaderL);


        //std::cout(" shader the 3s ! ");
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
    // std::cout(" shader source == %s \n", shaderSource);

    shaderL = glCreateShader(enumsha);
    // std::cout(" shader the 1 ! ");


    if(shaderL != 0)
    {
        //  std::cout(" shader the 2 ! ");
        glShaderSource(shaderL, 1, &shaderSource, NULL);

        //   std::cout(" shader the 2.5s ! ");


        glCompileShader(shaderL);


        //std::cout(" shader the 3s ! ");
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
     const std::chrono::time_point startInRenderTwo = std::chrono::steady_clock::now();

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

 

 // 2d  (UI)

   
   



  // 3d  simple 


    glUseProgram(testRecrangleProgram); // forgot to add this program and get error : uniform data type is an invalid data type
    glBindVertexArray(testRec.vao);

    // glActiveTexture(GL_TEXTURE0);
    // glUniform1i(testRectImage, 0);
    // glBindTexture(GL_TEXTURE_2D, astcIDBall); // was  BallRecamp

    LosMatrix4_4 LosBamboo= identity();
    //LosBamboo.ScaleLos(LosVector3(2.0f, 2.0f, 2.0f));
    LosBamboo.rotateLosY(rotateY);
    //LosBamboo.
    LosMatrix4_4 finalTestMatrix = pers * LookAt * LosBamboo;


    glUniformMatrix4fv(matrixTestRect, 1, GL_FALSE, &finalTestMatrix.elements[0][0]);
    glDrawArrays(GL_TRIANGLES, 0, 3); // no needed to proc exists !!

   // callChange();
    rotateY += 1.0f;
    //std::cout << " my rotate == " << rotateY << "\n";
 



   // 3d hard 
  
 

     glUseProgram(l3DViewProgram);
     glBindVertexArray(main3DObjects.vao);
     glActiveTexture(GL_TEXTURE0);
     glUniform1i(samplerSword, 0);
     glBindTexture(GL_TEXTURE_2D, swordID);



   LosMatrix4_4 swordIdenMat = identity();  // kolobush7
   //LosBearM.ScaleLos(LosVector3(2.0f, 2.0f, 2.0f));
   //LosKolobush.rotateLosY(rotateY); // 0.314 -0.157f  // -0.122843, 0.157486  + = 0.279
   //swordIdenMat.Transposition(LosVector3(0.145f, 0.06f, 0.0f));
   //swordIdenMat.rotateLosY(rotateY);
   LosMatrix4_4 finalSwordMa = LookAt * swordIdenMat;

//    float vLight[] = {light_movex, 0.04f, 0.05f};
//    float vCamPosit[] = { 3.5f, 3.1f, 2.2f};  // 3.5f, 3.1f, 2.2f
//
//    glUniform3fv(vectorLightPOsi, 1, vLight);
//    glUniform3fv(vectorCamePos, 1, vCamPosit);
//    glUniform1f(fAmbient, 0.13f); // was 0.15 my old primer

    glUniformMatrix4fv(matrix3dPositionView, 1, GL_FALSE, &pers.elements[0][0]); 
    glUniformMatrix4fv(matrix3dModelView, 1, GL_FALSE, &finalSwordMa.elements[0][0]); 
    glDrawElements(GL_TRIANGLES, main3DObjects.drawIndexs, GL_UNSIGNED_SHORT, 0); 


glUseProgram(0);
glBindVertexArray(0);



  SwapBuffers(mainContext);
 

  const auto diff434 = std::chrono::high_resolution_clock::now() - startInRenderTwo;
 // std::cout << " " << (size_t)std::chrono::duration<double, std::milli>(diff434).count() / 1000.0f << " fps" <<" \n"; // was std::milli
 // end's render time 

  }




void PreLoad::LoadASTCImage(const char* name, losFormatASTC astcs, unsigned int* texutID)
{

   std::cout << "Current path is " << fs::current_path() << '\n'; 

   // std::string filename = "C:\\Users\\loskutnikov\\Desktop\\cpp\\Out\\Values.bin";
    std::ifstream is (name, std::ifstream::binary);
      
    is.seekg (0, is.end);
    const int length = is.tellg();
    is.seekg (0, is.beg);
 std::cout << " in image load 001 " << "\n";

    //AAssetManager *mgrLok = backAssetMan();
    //AAsset* assetImage = AAssetManager_open(mgrLok, name, AASSET_MODE_STREAMING); // was AASSET_MODE_STREAMING // AASSET_MODE_BUFFER
    
std::cout << " in image load 002 " <<  length <<"\n";
    //size_t nSizeImageLos = AAsset_getLength(assetImage);

    unsigned char* buffer_forLosImage = (unsigned char*)calloc(length, sizeof(unsigned char));
std::cout << " in image load 003 " << "\n";
    buffer_forLosImage = new unsigned char[length]; // was  nSizeImageLos + 1]
std::cout << " in image load 004 " << "\n";
   // AAsset_read(assetImage, buffer_forLosImage, nSizeImageLos);

   is.read(reinterpret_cast<char*>(buffer_forLosImage), sizeof(length));
   is.close();
   // AAsset_close(assetImage);
std::cout << " in image load 01 " << "\n";
    unsigned int n_bytes_to_read = 0;
    int xblocks = 0;
    int yblocks = 0;
    int zblocks = 0;

    /* Number of bytes for each dimension. */
    int xsize = 0;
    int ysize = 0;
    int zsize = 0;

     astc_header* astc_data_ptr = (astc_header*) buffer_forLosImage;

   /* Merge x,y,z-sizes from 3 chars into one integer value. */
    xsize = astc_data_ptr->xsize[0] + (astc_data_ptr->xsize[1] << 8) + (astc_data_ptr->xsize[2] << 16);
    ysize = astc_data_ptr->ysize[0] + (astc_data_ptr->ysize[1] << 8) + (astc_data_ptr->ysize[2] << 16);
    zsize = astc_data_ptr->zsize[0] + (astc_data_ptr->zsize[1] << 8) + (astc_data_ptr->zsize[2] << 16);

std::cout << " middle load images " << "\n";
    /* Compute number of blocks in each direction. */
    xblocks = (xsize + astc_data_ptr->blockdim_x - 1) / astc_data_ptr->blockdim_x;
    yblocks = (ysize + astc_data_ptr->blockdim_y - 1) / astc_data_ptr->blockdim_y;
    zblocks = (zsize + astc_data_ptr->blockdim_z - 1) / astc_data_ptr->blockdim_z;

    /* Each block is encoded on 16 bytes, so calculate total compressed image data size. */
    n_bytes_to_read = xblocks * yblocks * zblocks << 4;

    /* We now have file contents in memory so let's fill a texture object with the data. */
    (glGenTextures(1, texutID));
    (glBindTexture(GL_TEXTURE_2D, *texutID));


   checkError(23);
     //         BIG versus стрелочка вниз !
     //  GL_COMPRESSED_RGBA_ASTC_10x8_KHR  or GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x8_KHR
    GLenum compressed_data_internal_format;

    switch (astcs)
    {
        case  tenForsixe:
            compressed_data_internal_format = GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x6_KHR;
            break;

        case tenForEight:
            compressed_data_internal_format = GL_COMPRESSED_RGBA_ASTC_10x8_KHR;
            break;

        case tenForTen:
            compressed_data_internal_format = GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x10_KHR;
            break;

        case   tenForTenNotAlpha:
            compressed_data_internal_format = GL_COMPRESSED_RGBA_ASTC_10x10_KHR;
            break;


         default:
             compressed_data_internal_format = GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x8_KHR;
           break;
    }


   // GLenum compressed_data_internal_format = GL_COMPRESSED_RGBA_ASTC_10x8_KHR;
    /* Upload texture data to ES. */
    checkError(25);
    (glCompressedTexImage2D(GL_TEXTURE_2D,
                                    0,
                                    compressed_data_internal_format,
                                    xsize,
                                    ysize,
                                    0,
                                    n_bytes_to_read,
                                    (const GLvoid*)&astc_data_ptr[1]));
checkError(26);

    (glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
    (glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
    (glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,     GL_REPEAT));
    (glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,     GL_REPEAT));

checkError(27);
   
    (glBindTexture(GL_TEXTURE_2D, 0));
checkError(28);

std::cout << " final load images " << "\n";

 delete [] buffer_forLosImage;
}





void PreLoad::loadDDSTexture(const char* path, unsigned int* texutID){



unsigned char* header;
    
    unsigned int width;
    unsigned int height;
    unsigned int mipMapCount;
    
    unsigned int blockSize;
    unsigned int format;
    
    unsigned int w;
    unsigned int h;
    
    unsigned char* buffer = 0;
    
    GLuint tid = 0;
    
  // open the DDS file for binary reading and get file size
    FILE* f;
    if((f = fopen(path, "rb")) == 0)
        return;

    fseek(f, 0, SEEK_END);
    long file_size = ftell(f);
    fseek(f, 0, SEEK_SET);
   


// allocate new unsigned char space with 4 (file code) + 124 (header size) bytes
  // read in 128 bytes from the file
   // header = malloc(128);
    header = new unsigned char[128];
    fread(header, 1, 128, f);
  
  // compare the `DDS ` signature
    if(memcmp(header, "DDS ", 4) != 0){
         std::cout << " this no DDS " << "\n";
  //        goto exit;
         return;
    }else{
  
     std::cout << " ok dds  ! " << "\n";

    }
    
  // extract height, width, and amount of mipmaps - yes it is stored height then width
    height = (header[12]) | (header[13] << 8) | (header[14] << 16) | (header[15] << 24);
    width = (header[16]) | (header[17] << 8) | (header[18] << 16) | (header[19] << 24);
    mipMapCount = (header[28]) | (header[29] << 8) | (header[30] << 16) | (header[31] << 24);
    
  // figure out what format to use for what fourCC file type it is
  // block size is about physical chunk storage of compressed data in file (important)
    if(header[84] == 'D') {
        switch(header[87]) {
            case '1': // DXT1
                format = GL_COMPRESSED_RGBA_S3TC_DXT1_EXT;
                blockSize = 8;
                break;
            case '3': // DXT3
                format = GL_COMPRESSED_RGBA_S3TC_DXT3_EXT;
                blockSize = 16;
                break;
            case '5': // DXT5
                format = GL_COMPRESSED_RGBA_S3TC_DXT5_EXT;
                blockSize = 16;
                break;
            case '0': // DX10
                // unsupported, else will error
                // as it adds sizeof(struct DDS_HEADER_DXT10) between pixels
                // so, buffer = malloc((file_size - 128) - sizeof(struct DDS_HEADER_DXT10));
            default: 
            std::cout << " default this ! " << "\n";
            return;
        }
    } else // BC4U/BC4S/ATI2/BC55/R8G8_B8G8/G8R8_G8B8/UYVY-packed/YUY2-packed unsupported
       {
        std::cout << " enter exit " << "\n";
       }
    
  // allocate new unsigned char space with file_size - (file_code + header_size) magnitude
  // read rest of file
   // buffer = malloc(file_size - 128);
      buffer = new unsigned char [file_size - 128]; 
    if(buffer == 0){
          std::cout << " exit buffer == 0 " << "\n";
          return;
        //goto exit;
    }
    fread(buffer, 1, file_size, f);
    
  // prepare new incomplete texture
    glGenTextures(1, texutID);
    if(tid == 0){
    std::cout << "dsf" << '\n';
        //goto exit;
     return;
    }
    
  // bind the texture
  // make it complete by specifying all needed parameters and ensuring all mipmaps are filled
    glBindTexture(GL_TEXTURE_2D, *texutID);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_BASE_LEVEL, 0);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAX_LEVEL, mipMapCount-1); // opengl likes array length of mipmaps
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR); // don't forget to enable mipmaping
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
      
    // prepare some variables
        unsigned int offset = 0;
        unsigned int size = 0;
        w = width;
        h = height;
    
    // loop through sending block at a time with the magic formula
    // upload to opengl properly, note the offset transverses the pointer
    // assumes each mipmap is 1/2 the size of the previous mipmap
        for (unsigned int i=0; i<mipMapCount; i++) {
            if(w == 0 || h == 0) { // discard any odd mipmaps 0x1 0x2 resolutions
                mipMapCount--;
                continue;
            }
            size = ((w+3)/4) * ((h+3)/4) * blockSize;
            glCompressedTexImage2D(GL_TEXTURE_2D, i, format, w, h, 0, size, buffer + offset);
            offset += size;
            w /= 2;
            h /= 2;
        }
        // discard any odd mipmaps, ensure a complete texture
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAX_LEVEL, mipMapCount-1);
    // unbind
    glBindTexture(GL_TEXTURE_2D, 0);
    
  // easy macro to get out quick and uniform (minus like 15 lines of bulk)

    delete [] buffer ;
    delete [] header;
    fclose(f);
  
  //  return tid;

}