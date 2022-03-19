// windows empty 
 
#include <iostream>


#ifndef UNICODE
#define UNICODE
#endif 


#include <PreLoad.h>

#pragma comment(linker, "/subsystem:windows")
#include <fcntl.h>
#include <io.h>








PreLoad* losLoad = nullptr;


LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)                        
{                                                                                                   
    if (losLoad != NULL)                                                                        
    {     

     switch (uMsg)
    {
         case WM_CREATE: 
           {



           }

           return 0;

    }




        //losLoad->handleMessages(hWnd, uMsg, wParam, lParam);                                    
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
        0,                              // Optional window styles.
        CLASS_NAME,                     // Window class
        (LPCWSTR) L"Hello, bolvanka",    // Window text
        WS_OVERLAPPEDWINDOW,            // Window style

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

   MSG msg = { };
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

 

 losLoad->InstallWindow(hInstance, nCmdShow);

 std::cout << " calling start console printed " << "\n";


     for (int32_t i = 0; i < __argc; i++) {  std::cout << " wefwe " << "\n"; };



 losLoad->callMainBuildWindow();
 

 



return 1;

 
  }