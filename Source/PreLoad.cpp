// Loskutnikov Games inc. 2022


#include <PreLoad.h>
#include <windows.h>
#include <iostream>
#include <wrl/client.h>
#include <exception>

using namespace std::literals;
using Microsoft::WRL::ComPtr;







namespace DX
{
    inline void ThrowIfFailed(HRESULT hr)
    {
        if (FAILED(hr))
        {
            // Set a breakpoint on this line to catch DirectX API errors
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



 bool PreLoad::InstallWindow(HINSTANCE hInstance, int nCmdShow){

    
     // if debug is enabled 
    ComPtr<ID3D12Debug> debugController;
    ComPtr<ID3D12Device> m3LosDevice;
    ComPtr<ID3D12Fence> mLosFence;
    DX::ThrowIfFailed(D3D12GetDebugInterface(IID_PPV_ARGS(&debugController)));
    debugController->EnableDebugLayer();

    ComPtr<IDXGIFactory4> mdgiFactory;
    DX::ThrowIfFailed(CreateDXGIFactory1(IID_PPV_ARGS(&mdgiFactory)));

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
     std::cout << " first size == " <<  mRtvDescriptorSize << "\n"; // ok 32 =)) 



   return false;
 }