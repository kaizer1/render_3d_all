// windows empty 
#pragma warning(disable : 28251)
#pragma warning(disable : 28159)

#include <iostream>


#ifndef UNICODE
#define UNICODE
#endif 

#include <PreLoad.h>
#include <strsafe.h>

#pragma comment(linker, "/subsystem:windows")
#include <fcntl.h>
#include <io.h>


#define IDC_LOSVALIARNTALL            109

// OPENGL_VARIANT  VULKAN_VARIANT  DIRECTX_VARIANT DIRECTX_ULTRA_VARIANT
#ifdef OPENGL_VARIANT
// #include <GL/GL.h>
// #include <sstream>
// #include <GL/glext.h>

#pragma comment(lib, "opengl32.lib")

#define MAX_LOADSTRING 100

#define WGL_CONTEXT_MAJOR_VERSION_ARB     0x2091
#define WGL_CONTEXT_MINOR_VERSION_ARB     0x2092
#define WGL_CONTEXT_FLAGS_ARB             0x2094
#define WGL_CONTEXT_CORE_PROFILE_BIT_ARB  0x00000001
#define WGL_CONTEXT_PROFILE_MASK_ARB      0x9126

// #define WGL_DRAW_TO_WINDOW_ARB            0x2001
// #define WGL_ACCELERATION_ARB              0x2003
// #define WGL_SWAP_METHOD_ARB               0x2007
// #define WGL_SUPPORT_OPENGL_ARB            0x2010
// #define WGL_DOUBLE_BUFFER_ARB             0x2011
// #define WGL_PIXEL_TYPE_ARB                0x2013
// #define WGL_COLOR_BITS_ARB                0x2014
// #define WGL_DEPTH_BITS_ARB                0x2022
// #define WGL_STENCIL_BITS_ARB              0x2023
// #define WGL_FULL_ACCELERATION_ARB         0x2027
// #define WGL_SWAP_EXCHANGE_ARB             0x2028
// #define WGL_TYPE_RGBA_ARB                 0x202B
// #define WGL_CONTEXT_MAJOR_VERSION_ARB     0x2091
// #define WGL_CONTEXT_MINOR_VERSION_ARB     0x2092
// #define GL_ARRAY_BUFFER                   0x8892
// #define GL_STATIC_DRAW                    0x88E4
// #define GL_FRAGMENT_SHADER                0x8B30
// #define GL_VERTEX_SHADER                  0x8B31
// #define GL_COMPILE_STATUS                 0x8B81
// #define GL_LINK_STATUS                    0x8B82
// #define GL_INFO_LOG_LENGTH                0x8B84
// #define GL_TEXTURE0                       0x84C0
// #define GL_BGRA                           0x80E1
// #define GL_ELEMENT_ARRAY_BUFFER           0x8893


typedef HGLRC(WINAPI* PFNWGLCREATECONTEXTATTRIBSARBPROC) (HDC, HGLRC, const int*);

typedef const char* (WINAPI* PFNWGLGETEXTENSIONSSTRINGEXTPROC) (void);
typedef BOOL(WINAPI* PFNWGLSWAPINTERVALEXTPROC) (int);
typedef int (WINAPI* PFNWGLGETSWAPINTERVALEXTPROC) (void);




HGLRC ourOpenGLRenderingContext;
HDC ourWindowHandleToDeviceContext;
HDC m_deviceContext;
HGLRC m_renderingContext;

#endif




PreLoad* losLoad = nullptr;



const void callError(const char* textPreError) {
 

    LPVOID lpMsgBuf;
    LPVOID lpDisplayBuf;
    DWORD dw = GetLastError(); 

     if(dw == 0){
         std::cout << textPreError << " no error " << "\n";
        return;
     }else {

std::cout << "exists error = " << textPreError << '\n';
 if (dw == ERROR_INVALID_HANDLE){
         std::cout << " it error " << "\n";
      }

    FormatMessage(
        FORMAT_MESSAGE_ALLOCATE_BUFFER | 
        FORMAT_MESSAGE_FROM_SYSTEM |
        FORMAT_MESSAGE_IGNORE_INSERTS,
        NULL,
        dw,
        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
        (LPTSTR) &lpMsgBuf,
        0, NULL );
  
     // std::cout << " my strings == " << std::string(&lpMsgBuf) << "\n";

  //LPTSTR lpszFunction = TEXT("my eror");

 lpDisplayBuf = (LPVOID)LocalAlloc(LMEM_ZEROINIT, 
        (lstrlen((LPCTSTR)lpMsgBuf)  + 40) * sizeof(TCHAR)); 
    StringCchPrintf((LPTSTR)lpDisplayBuf, 
        LocalSize(lpDisplayBuf) / sizeof(TCHAR),
        TEXT(" failed with error %d: %s"), 
         dw, lpMsgBuf); 
    MessageBox(NULL, (LPCTSTR)lpDisplayBuf, TEXT("Error"), MB_OK); 

    LocalFree(lpMsgBuf);
    LocalFree(lpDisplayBuf);
    ExitProcess(dw); 


     }

}



LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)                        
{         


    HDC hdc;                       // handle to device context 
    RECT rcClient;                 // client area rectangle 
    POINT ptClientUL;              // client upper left corner 
    POINT ptClientLR;              // client lower right corner 
    static POINTS ptsBegin;        // beginning point 
    static POINTS ptsEnd;          // new endpoint 
    static POINTS ptsPrevEnd;      // previous endpoint 
    static BOOL fPrevLine = FALSE; // previous line flag 


    if (losLoad != NULL)                                                                        
    {         

   
      switch(uMsg) 
      {

         case WM_DESTROY:
             PostQuitMessage(0);
              return 0;


         case WM_PAINT:
          {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);

            losLoad->handleMessages(hWnd, uMsg, wParam, lParam);    


            FillRect(hdc, &ps.rcPaint, (HBRUSH) (COLOR_WINDOW+1));

            EndPaint(hWnd, &ps);
          }
          return 0;


          case WM_CREATE:
             {
               std::cout << "WM_CREATE " << "\n";
  
#ifdef OPENGL_VARIANT 

    HDC hdc = GetDC(hWnd);

    PIXELFORMATDESCRIPTOR pfd;
    memset(&pfd, 0, sizeof(PIXELFORMATDESCRIPTOR));
    pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
    pfd.nVersion = 1;
    pfd.dwFlags = PFD_SUPPORT_OPENGL | PFD_DRAW_TO_WINDOW | PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 24;
    pfd.cDepthBits = 32;
    pfd.cStencilBits = 8;
    pfd.iLayerType = PFD_MAIN_PLANE;
    int pixelFormat = ChoosePixelFormat(hdc, &pfd);
    SetPixelFormat(hdc, pixelFormat, &pfd);

    HGLRC tempRC = wglCreateContext(hdc);
    wglMakeCurrent(hdc, tempRC);

 
     std::cout << " gl version = " << glGetString(GL_VERSION) << " \n";
     //std::string versionString = glGetString(GL_VERSION);
     //std::string suVersionString = versionString.substr(0, 3);
     //std::cout << " my version strings == " << suVersionString.c_str() << "\n";
 
    GLint majVers, minVers;
    glGetIntegerv(GL_MAJOR_VERSION, &majVers);
    std::cout << " my major version == " << majVers << "\n";

    glGetIntegerv(GL_MINOR_VERSION, &minVers);
    std::cout << " my minor version == " << minVers << "\n";

    PFNWGLCREATECONTEXTATTRIBSARBPROC wglCreateContextAttribsARB = NULL;
    wglCreateContextAttribsARB = (PFNWGLCREATECONTEXTATTRIBSARBPROC)wglGetProcAddress("wglCreateContextAttribsARB");

   
   

    const int attribList[] = {
    WGL_CONTEXT_MAJOR_VERSION_ARB, majVers,
    WGL_CONTEXT_MINOR_VERSION_ARB, minVers,
    WGL_CONTEXT_FLAGS_ARB, 0,
    WGL_CONTEXT_PROFILE_MASK_ARB, WGL_CONTEXT_CORE_PROFILE_BIT_ARB,
    0,
    };

    HGLRC hglrc = wglCreateContextAttribsARB(hdc, 0, attribList);

 
    wglMakeCurrent(NULL, NULL);
    wglDeleteContext(tempRC);
    wglMakeCurrent(hdc, hglrc);




    PFNWGLGETEXTENSIONSSTRINGEXTPROC _wglGetExtensionsStringEXT = (PFNWGLGETEXTENSIONSSTRINGEXTPROC)wglGetProcAddress("wglGetExtensionsStringEXT");
    bool swapControlSupported = strstr(_wglGetExtensionsStringEXT(), "WGL_EXT_swap_control") != 0;

    int vsynch = 0;
    if (swapControlSupported) {
        PFNWGLSWAPINTERVALEXTPROC wglSwapIntervalEXT = (PFNWGLSWAPINTERVALEXTPROC)wglGetProcAddress("wglSwapIntervalEXT");
        PFNWGLGETSWAPINTERVALEXTPROC wglGetSwapIntervalEXT = (PFNWGLGETSWAPINTERVALEXTPROC)wglGetProcAddress("wglGetSwapIntervalEXT");

        if (wglSwapIntervalEXT(1)) {
            std::cout << "Enabled vsynch\n";
            vsynch = wglGetSwapIntervalEXT();
        }
        else {
            std::cout << "Could not enable vsynch\n";
        }
    }
    else { // !swapControlSupported
        std::cout << "WGL_EXT_swap_control not supported\n";
    }
    

      losLoad->LoadingOpenGLPrograms(400, 700, hdc);
      
  
#endif               



             }
             return 0;



  case WM_LBUTTONDOWN: 
          {
            // Capture mouse input. 
 
            SetCapture(hWnd); 
 
            // Retrieve the screen coordinates of the client area, 
            // and convert them into client coordinates. 
 
            GetClientRect(hWnd, &rcClient); 
            ptClientUL.x = rcClient.left; 
            ptClientUL.y = rcClient.top; 
            std::cout << " my points == " << ptClientUL.x << " s " << ptClientUL.y << "\n";
 
            // Add one to the right and bottom sides, because the 
            // coordinates retrieved by GetClientRect do not 
            // include the far left and lowermost pixels. 
 
            ptClientLR.x = rcClient.right + 1; 
            ptClientLR.y = rcClient.bottom + 1; 
            ClientToScreen(hWnd, &ptClientUL); 
            ClientToScreen(hWnd, &ptClientLR); 
 
            // Copy the client coordinates of the client area 
            // to the rcClient structure. Confine the mouse cursor 
            // to the client area by passing the rcClient structure 
            // to the ClipCursor function. 
 
            SetRect(&rcClient, ptClientUL.x, ptClientUL.y, 
                ptClientLR.x, ptClientLR.y); 
            ClipCursor(&rcClient); 
 
            // Convert the cursor coordinates into a POINTS 
            // structure, which defines the beginning point of the 
            // line drawn during a WM_MOUSEMOVE message. 
 
            ptsBegin = MAKEPOINTS(lParam); 
        }
            return 0; 
 
        case WM_MOUSEMOVE: 
      { 
            // When moving the mouse, the user must hold down 
            // the left mouse button to draw lines. 
 
            if (wParam & MK_LBUTTON) 
            { 
 
                // Retrieve a device context (DC) for the client area. 
 
                hdc = GetDC(hWnd); 
 
                // The following function ensures that pixels of 
                // the previously drawn line are set to white and 
                // those of the new line are set to black. 
 
                SetROP2(hdc, R2_NOTXORPEN); 
 
                // If a line was drawn during an earlier WM_MOUSEMOVE 
                // message, draw over it. This erases the line by 
                // setting the color of its pixels to white. 
 
                if (fPrevLine) 
                { 
                    MoveToEx(hdc, ptsBegin.x, ptsBegin.y, 
                        (LPPOINT) NULL); 
                    LineTo(hdc, ptsPrevEnd.x, ptsPrevEnd.y); 
                } 
 
                // Convert the current cursor coordinates to a 
                // POINTS structure, and then draw a new line. 
 
                ptsEnd = MAKEPOINTS(lParam); 
                MoveToEx(hdc, ptsBegin.x, ptsBegin.y, (LPPOINT) NULL); 
                LineTo(hdc, ptsEnd.x, ptsEnd.y); 
 
 
                fPrevLine = TRUE; 
                ptsPrevEnd = ptsEnd; 
                ReleaseDC(hWnd, hdc); 
            } 
        }
            break; 
 
        case WM_LBUTTONUP: 
 
            fPrevLine = FALSE; 
            ClipCursor(NULL); 
            ReleaseCapture(); 
            return 0; 



        case WM_CHAR:
        {
              switch (wParam)
                {
                      case 0x08:
                        break;
                      case 0x1B:
                       {
                         std::cout << " pree Escape " << "\n";
                         losLoad->QuitToApp();
                         PostQuitMessage(0);
                       }  
                }
        }
          break;




            return 0;

      }
                                      
    }    


    return (DefWindowProc(hWnd, uMsg, wParam, lParam));                                             
}       




int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow)    
{

  

   // UNREFERENCED_PARAMETER(hPrevInstance);
   // UNREFERENCED_PARAMETER(pCmdLine);
 losLoad = new PreLoad();


 const auto CLASS_NAME = (LPCWSTR)"Sample Window Class";
    
    WNDCLASS wc = { };

    wc.lpfnWndProc   = WndProc;
    wc.hInstance     = hInstance;
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);


  HWND hwnd = CreateWindowEx(
        0,                               // Optional window styles.
        CLASS_NAME,                      // Window class
        (LPCWSTR) L"Loading 3d Scene !", // Window text
        WS_OVERLAPPEDWINDOW,             // Window style

        // Size and position
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

        NULL,       // Parent window    
        NULL,       // Menu
        hInstance,  // Instance handle
        NULL        // Additional application data
        );

    if (hwnd == NULL)
    {
         std::cout << " this null hwnd " << "\n";
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);

 HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LOSVALIARNTALL));
   MSG msg = { };
    while (GetMessage(&msg, NULL, 0, 0))
    {

         if(!TranslateAccelerator(msg.hwnd, hAccelTable , &msg))
         {

        TranslateMessage(&msg);
        DispatchMessage(&msg);
         }
  

      losLoad->PreRender(); //  RenderLos()
    }

 

 //losLoad->InstallWindow(hInstance, nCmdShow);

 std::cout << " calling start console printed " << "\n";


     for (int32_t i = 0; i < __argc; i++) {  std::cout << " wefwe " << "\n"; };



 losLoad->callMainBuildWindow();


return 1;

 
  }