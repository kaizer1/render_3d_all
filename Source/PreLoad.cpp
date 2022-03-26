// Loskutnikov Games inc. 2022


#include <PreLoad.h>
#include <windows.h>
#include <iostream>

using namespace std::literals;


PreLoad::PreLoad() : losDLL{} {
	

	AllocConsole();
	AttachConsole(GetCurrentProcessId());
	FILE *stream;
	freopen_s(&stream, "CONOUT$", "w+", stdout);
	freopen_s(&stream, "CONOUT$", "w+", stderr);
	SetConsoleTitle(TEXT(" Work in my Render "));

 
  std::cout << " calling this  ! " << "\n";

  losDLL.Initialize();
  losDLL.InitializeDispatchPointers();

}



  PreLoad::~PreLoad(){

    losDLL = {};

  }



  void PreLoad::callMainBuildWindow() noexcept{

 

      std::cout <<  " count my building ! " << "\n";
     
        if (waitOrNorToExitConsole){
           
            while(1){

            }
          
    }else{
    	
    	std::this_thread::sleep_for(8s);

    }
       

  }



 void PreLoad::handleMessages(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam){
  
        std::cout << " in handle messages " << "\n";

    
 } 





 bool PreLoad::InstallWindow(HINSTANCE hInstance, int nCmdShow, HWND hWnd){
  
     
      VkResult res;
      uint32_t versionVulkan = 0;
      uint32_t currentVersionVulkan;

      std::cout << "build start vulkan " << "\n";
      res = losDLL.fp_vkEnumerateInstanceVersion(&versionVulkan);

     // int a;

     if (res != VK_SUCCESS) {
       std::cout << " ending apps " << "\n";
      
       exit;
     }else{

          uint16_t lMajor = VK_VERSION_MAJOR(versionVulkan);
          uint16_t lMinor = VK_VERSION_MINOR(versionVulkan);

          std::cout << " version vulkan == " << lMajor << " " << lMinor << "\n";
     }

     std::cout << "Initialize vulkan " << "\n";



  uint32_t instancExtensCount = 0;
  res = losDLL.fp_vkEnumerateInstanceExtensionProperties(nullptr, &instancExtensCount, nullptr);
  VkExtensionProperties* instaProperty = new VkExtensionProperties[instancExtensCount];
  res = losDLL.fp_vkEnumerateInstanceExtensionProperties(nullptr, &instancExtensCount, instaProperty);
  std::cout << " insta etension count == " << instancExtensCount << "\n";
 

 //insta etension count == 16
  /*  name extension VK_KHR_device_group_creation
    name extension VK_KHR_display
    name extension VK_KHR_external_fence_capabilities
    name extension VK_KHR_external_memory_capabilities
    name extension VK_KHR_external_semaphore_capabilities
    name extension VK_KHR_get_display_properties2
    name extension VK_KHR_get_physical_device_properties2
    name extension VK_KHR_get_surface_capabilities2
    name extension VK_KHR_surface
    name extension VK_KHR_surface_protected_capabilities
    name extension VK_KHR_win32_surface
    name extension VK_EXT_debug_report
    name extension VK_EXT_debug_utils
    name extension VK_EXT_direct_mode_display
    name extension VK_EXT_swapchain_colorspace
    name extension VK_NV_external_memory_capabilities*/



  std::vector<const char*> extensionForAdd;
  for (auto i = 0; i < instancExtensCount; i++) {
  
    std::cout << " name extension " << instaProperty[i].extensionName << " \n";
    extensionForAdd.push_back(instaProperty[i].extensionName);
  }
    

     VkApplicationInfo appInfo = {};
     appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
     appInfo.pApplicationName = "RenderLos";
     appInfo.applicationVersion = 0;
     appInfo.pEngineName = "Loskutnikov Engine";
     appInfo.engineVersion = 1;
     appInfo.apiVersion = VK_API_VERSION_1_3; // !!! 



  uint32_t numInstanceLayers = 0;
  losDLL.fp_vkEnumerateInstanceLayerProperties(&numInstanceLayers, nullptr);
  std::cout << " number layers count's  = " << numInstanceLayers << "\n";
  VkLayerProperties* layerProperties = (VkLayerProperties*)malloc(numInstanceLayers * sizeof(VkLayerProperties));
  losDLL.fp_vkEnumerateInstanceLayerProperties(&numInstanceLayers, layerProperties);

  std::vector<const char*> layName;
  layName.push_back("VK_LAYER_KHRONOS_validation");

 



 

   return false;
 }