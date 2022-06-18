// Loskutnikov Games inc. 2022


#include <PreLoad.h>
#include <windows.h>
#include <iostream>
#include <wrl/client.h>
#include <exception>
#include <cassert>


using namespace std::literals;
using Microsoft::WRL::ComPtr;


#pragma comment (lib, "d3dcompiler.lib")
#pragma comment (lib, "D3D12.lib")
#pragma comment (lib, "dxgi.lib")

//#if defined(DEBUG) || defined(_DEBUG)
#include <dxgidebug.h> // IDXGIInfoQueue
//#endif


#define _FACDXGI    0x87a
//#define MAKE_DXGI_HRESULT(code) MAKE_HRESULT(1, _FACDXGI, code)

//#define DXGI_ERROR_INVALID_CALL                 MAKE_DXGI_HRESULT(1)

namespace DX
{
    inline void ThrowIfFailed(HRESULT hr)
    {
        if (FAILED(hr))
        { 

            switch(hr) {
                case E_ABORT:{
               std::cout << " E_ABORT " << "\n";
                }
                break;

                case E_FAIL:{
  std::cout << " E_ABORT 1" << "\n";
                }
                break;

                case E_HANDLE:{
  std::cout << " E_ABORT 2" << "\n";
                }
                break;

                default:{
  std::cout << " default " << "\n";
                }
            }

     
          std::cout <<  " error ! " <<   HRESULT_CODE(hr) << " " << hr <<"\n";
        //  std::cout << " SCode code " << SCODE_CODE()
            throw std::exception();
        }
    }
}


void PreLoad::QuitToApp(){

}


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
           
            // while(1){

            // }
          
    }else{
    	
    	std::this_thread::sleep_for(8s);

    }
       

  }



 void PreLoad::handleMessages(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam){
  
        std::cout << " in handle messages " << "\n";

    
 } 


 // typedef struct DXGI_SWAPCHAIN_DESC
 // {
 //    DXGI_MODE_DESC BufferDesc;
 //    DXGI_SAMPLE_DESC SampleDesc;
 //    DXGI_USAGE BufferUsage;
 //    UINT BufferCount;
 //    HWND OutputWindow;
 //    BOOL Windowed;
 //    DXGI_SWAP_EFFECT SwapEffect;
 //    UINT Flags;

 // } DXGI_SWAPCHAIN_DESC;


 // typedef struct DXGI_MODE_DESC {
 //    UINT Width;
 //    UINT Height;
 //    DXGI_RATIONAL RefreshRate;
 //    DXGI_FORMAT Format;
 //    DXGI_MODE_SCANLINE_ORDER ScanliOrdering;
 //    DXGI_MODE_SCALING Scaling; 
 // } DXGI_MODE_DESC;



static void DebugReportCallback(D3D12_MESSAGE_CATEGORY Category, D3D12_MESSAGE_SEVERITY Severity, D3D12_MESSAGE_ID ID, LPCSTR pDescription, void* pContext)
{
   std::cout << " this my debug callback ! " << "\n";
}


 bool PreLoad::InstallWindow(HINSTANCE hInstance, int nCmdShow, HWND* hwnd){

    
     // if debug is enabled 
    ComPtr<ID3D12Debug> debugController;
    ComPtr<ID3D12Device5> m3LosDevice; // was ID3D12Device 
    ComPtr<ID3D12Fence> mLosFence;



    std::cout << " pre my main error ! " << "\n";
    DX::ThrowIfFailed(D3D12GetDebugInterface(IID_PPV_ARGS(&debugController)));
    debugController->EnableDebugLayer();

// was IDXGIInfoQueue1
ComPtr<ID3D12InfoQueue1> dxgiInfoQueue;
 
DX::ThrowIfFailed(DXGIGetDebugInterface1(0, IID_PPV_ARGS(&dxgiInfoQueue)));
 std::cout<< " post debug " << "\n";

 if (SUCCEEDED(DXGIGetDebugInterface1(0, IID_PPV_ARGS(&dxgiInfoQueue)))) {
       //auto dxgiFactoryFlags = DXGI_CREATE_FACTORY_DEBUG;
        // DX12 does not support redirect debug layer message currently, see:
        // https://devblogs.microsoft.com/directx/d3d12-debug-layer-message-callback/
        // Sample code is:
        // ComPtr<IDXGIInfoQueue1> dxgiInfoQueue;
        // dxgiInfoQueue->RegisterMessageCallback(..);

DWORD callBackCookie = 0;
dxgiInfoQueue->RegisterMessageCallback(DebugReportCallback, D3D12_MESSAGE_CALLBACK_IGNORE_FILTERS, nullptr, &callBackCookie);
  std::cout << " my register  callback is ! " << "\n";
// dxgiInfoQueue->UnregisterMessageCallback(callBackCookie);

    }else{
      std::cout << " are this no ! " << "\n";
    }






    ComPtr<IDXGIFactory4> mdgiFactory;
    DX::ThrowIfFailed(CreateDXGIFactory2(DXGI_CREATE_FACTORY_DEBUG, IID_PPV_ARGS(&mdgiFactory)));




    HRESULT hardwareResult = D3D12CreateDevice(
       nullptr, // default device 
       D3D_FEATURE_LEVEL_12_0,   // ok - D3D_FEATURE_LEVEL_11_0
       IID_PPV_ARGS(&m3LosDevice));
      
      if(FAILED(hardwareResult)){
        std::cout << " failed load device's  " << "\n";
      }else{
        std::cout << " ok loading first device's " << "\n";
      }






    
    DX::ThrowIfFailed(m3LosDevice->CreateFence(0, D3D12_FENCE_FLAG_NONE, 
      IID_PPV_ARGS(&mLosFence)));

    auto mRtvDescriptorSize = m3LosDevice->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_RTV);
     std::cout << " rtv size == " <<  mRtvDescriptorSize << "\n"; // ok 32 =)) 
 
    auto mDsvDescriptionSize = m3LosDevice->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_DSV);
      std::cout << " dsv size == " <<  mDsvDescriptionSize << "\n"; 

    auto mCbvDescriptSize = m3LosDevice->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV);
      std::cout << " all sbv, uav, ...  size == " <<  mCbvDescriptSize << "\n"; // ok 32 =))   
  

   
     DXGI_FORMAT mBackBufferFormat = DXGI_FORMAT_R8G8B8A8_UNORM;

    D3D12_FEATURE_DATA_MULTISAMPLE_QUALITY_LEVELS msQualityLevels;
    msQualityLevels.Format = mBackBufferFormat;
    msQualityLevels.SampleCount = 4;
    msQualityLevels.Flags = D3D12_MULTISAMPLE_QUALITY_LEVELS_FLAG_NONE;
    msQualityLevels.NumQualityLevels = 0;

    DX::ThrowIfFailed(m3LosDevice->CheckFeatureSupport(
      D3D12_FEATURE_MULTISAMPLE_QUALITY_LEVELS,
      &msQualityLevels,
      sizeof(msQualityLevels)));
 
 


 


 
      // HRESULT losCheck = m3LosDevice->CheckFeatureSupport(
      //  D3D12_RAYTRACING_TIER_1_0,
      //  &dke,
      //  sizeof(dke));

      //  if(losCheck != S_OK){
      //     std::cout << " no support Ray - tracing's 1 " << "\n";
      //  }else{
      //    std::cout << " ok check ! " << "\n";
      //  }


    auto m4xMsaaQaulity = msQualityLevels.NumQualityLevels;
    assert(m4xMsaaQaulity > 0 && "Unexpected MSAA quality level ");

    std::cout << " my quality levels = " << m4xMsaaQaulity << "\n"; // ? 








     // command Queue & command List 
    ComPtr<ID3D12CommandQueue> mCommandQueue;
    ComPtr<ID3D12CommandAllocator> mDirectCmdListAllocator;
    ComPtr<ID3D12GraphicsCommandList> mCommandListGrap;

    D3D12_COMMAND_QUEUE_DESC queueDesc = {};
    queueDesc.Type = D3D12_COMMAND_LIST_TYPE_DIRECT;
    queueDesc.Flags = D3D12_COMMAND_QUEUE_FLAG_NONE;
    queueDesc.Priority = D3D12_COMMAND_QUEUE_PRIORITY_HIGH;

    DX::ThrowIfFailed(m3LosDevice->CreateCommandQueue(
        &queueDesc, IID_PPV_ARGS(&mCommandQueue)));

    
    DX::ThrowIfFailed(m3LosDevice->CreateCommandAllocator(
       D3D12_COMMAND_LIST_TYPE_DIRECT,
       IID_PPV_ARGS(mDirectCmdListAllocator.GetAddressOf())));


    DX::ThrowIfFailed(m3LosDevice->CreateCommandList(
      0, 
      D3D12_COMMAND_LIST_TYPE_DIRECT,
      mDirectCmdListAllocator.Get(),
      nullptr,
      IID_PPV_ARGS(mCommandListGrap.GetAddressOf())));  

      mCommandListGrap->Close();   







  RECT rect;
   if(GetWindowRect(*hwnd, &rect)){
      std::cout << " my width == " << rect.right - rect.left << "\n";
       std::cout << " my height == " << rect.bottom - rect.top << "\n";
   }

   
              ComPtr<IDXGISwapChain> mSwapChain;
     const auto  width = rect.right - rect.left;
     const auto height = rect.bottom - rect.top; 
       
       auto m4xMsaaState = true;
       mSwapChain.Reset();

       DXGI_SWAP_CHAIN_DESC df;
       df.BufferDesc.Width = width;
       df.BufferDesc.Height = height;
       df.BufferDesc.RefreshRate.Numerator = 60;
       df.BufferDesc.RefreshRate.Denominator = 1;
       df.BufferDesc.Format = mBackBufferFormat;
       df.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
       df.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
       df.SampleDesc.Count = 1; //m4xMsaaState ? 4 : 1;
       df.SampleDesc.Quality = 0; //m4xMsaaState ? (m4xMsaaQaulity - 1) : 0;
       df.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
       df.BufferCount = 2;
       df.OutputWindow = *hwnd;
       df.Windowed = true;
       df.SwapEffect = DXGI_SWAP_EFFECT_FLIP_SEQUENTIAL;
       df.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;

         std::cout << " this pre error !  " << "\n";
       DX::ThrowIfFailed(mdgiFactory->CreateSwapChain(
        mCommandQueue.Get(),
        &df,
        mSwapChain.GetAddressOf()));

 
      






   return false;
 }