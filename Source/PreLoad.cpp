// Loskutnikov Games inc. 2022


#include <PreLoad.h>
#include <windows.h>
#include <iostream>
#include <string_view>

#include <version>

using namespace std::literals;


#define COMPILER_FEATURE_VALUE(value) #value
#define COMPILER_FEATURE_ENTRY(name) { #name, COMPILER_FEATURE_VALUE(name) },

// was : losDLL {}
PreLoad::PreLoad()  {
	

  losDLL = std::make_unique<VkDll>();
	AllocConsole();
	AttachConsole(GetCurrentProcessId());
	FILE *stream;
	freopen_s(&stream, "CONOUT$", "w+", stdout);
	freopen_s(&stream, "CONOUT$", "w+", stderr);
	SetConsoleTitle(TEXT(" Work in my Render "));

 
  std::cout << " calling this  ! " << "\n";

  losDLL->Initialize();
  losDLL->InitializeDispatchPointers();

}



  PreLoad::~PreLoad(){

    //losDLL = {};
    losDLL.reset(nullptr);

  }



  void PreLoad::callMainBuildWindow() noexcept{

 

      std::cout <<  " count my building ! " << "\n";
     
        if (waitOrNorToExitConsole){
            std::cout << " wait or not is ok ! " << " \n";
            // while(1){ // это если мы хотим убедиться что всё завершилось нормально и хорошо ( в смысле отчистилось и прочее )

            // }
          
    }else{
    	
    	std::this_thread::sleep_for(8s);

    }
       

  }



 void PreLoad::handleMessages(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam){
  
        std::cout << " in handle messages " << "\n";

    
 } 


std::string_view to_string( VkResult r ){
    switch( r ){
        case VK_SUCCESS: return "VK_SUCCESS";
        case VK_NOT_READY: return "VK_NOT_READY";
        case VK_TIMEOUT: return "VK_TIMEOUT";
        case VK_EVENT_SET: return "VK_EVENT_SET";
        case VK_EVENT_RESET: return "VK_EVENT_RESET";
        case VK_INCOMPLETE: return "VK_INCOMPLETE";
        case VK_ERROR_OUT_OF_HOST_MEMORY: return "VK_ERROR_OUT_OF_HOST_MEMORY";
        case VK_ERROR_OUT_OF_DEVICE_MEMORY: return "VK_ERROR_OUT_OF_DEVICE_MEMORY";
        case VK_ERROR_INITIALIZATION_FAILED: return "VK_ERROR_INITIALIZATION_FAILED";
        case VK_ERROR_DEVICE_LOST: return "VK_ERROR_DEVICE_LOST";
        case VK_ERROR_MEMORY_MAP_FAILED: return "VK_ERROR_MEMORY_MAP_FAILED";
        case VK_ERROR_LAYER_NOT_PRESENT: return "VK_ERROR_LAYER_NOT_PRESENT";
        case VK_ERROR_EXTENSION_NOT_PRESENT: return "VK_ERROR_EXTENSION_NOT_PRESENT";
        case VK_ERROR_FEATURE_NOT_PRESENT: return "VK_ERROR_FEATURE_NOT_PRESENT";
        case VK_ERROR_INCOMPATIBLE_DRIVER: return "VK_ERROR_INCOMPATIBLE_DRIVER";
        case VK_ERROR_TOO_MANY_OBJECTS: return "VK_ERROR_TOO_MANY_OBJECTS";
        case VK_ERROR_FORMAT_NOT_SUPPORTED: return "VK_ERROR_FORMAT_NOT_SUPPORTED";
        case VK_ERROR_SURFACE_LOST_KHR: return "VK_ERROR_SURFACE_LOST_KHR";
        case VK_ERROR_NATIVE_WINDOW_IN_USE_KHR: return "VK_ERROR_NATIVE_WINDOW_IN_USE_KHR";
        case VK_SUBOPTIMAL_KHR: return "VK_SUBOPTIMAL_KHR";
        case VK_ERROR_OUT_OF_DATE_KHR: return "VK_ERROR_OUT_OF_DATE_KHR";
        case VK_ERROR_INCOMPATIBLE_DISPLAY_KHR: return "VK_ERROR_INCOMPATIBLE_DISPLAY_KHR";
        case VK_ERROR_VALIDATION_FAILED_EXT: return "VK_ERROR_VALIDATION_FAILED_EXT";
        case VK_ERROR_INVALID_SHADER_NV: return "VK_ERROR_INVALID_SHADER_NV";
        default: return "unrecognized VkResult code";
    }
}


std::string_view to_string( VkDebugReportObjectTypeEXT o ){
    switch( o ){
        case VK_DEBUG_REPORT_OBJECT_TYPE_UNKNOWN_EXT: return "unknown";
        case VK_DEBUG_REPORT_OBJECT_TYPE_INSTANCE_EXT: return "Instance";
        case VK_DEBUG_REPORT_OBJECT_TYPE_PHYSICAL_DEVICE_EXT: return "PhysicalDevice";
        case VK_DEBUG_REPORT_OBJECT_TYPE_DEVICE_EXT: return "Device";
        case VK_DEBUG_REPORT_OBJECT_TYPE_QUEUE_EXT: return "Queue";
        case VK_DEBUG_REPORT_OBJECT_TYPE_SEMAPHORE_EXT: return "Semaphore";
        case VK_DEBUG_REPORT_OBJECT_TYPE_COMMAND_BUFFER_EXT: return "CommandBuffer";
        case VK_DEBUG_REPORT_OBJECT_TYPE_FENCE_EXT: return "Fence";
        case VK_DEBUG_REPORT_OBJECT_TYPE_DEVICE_MEMORY_EXT: return "DeviceMemory";
        case VK_DEBUG_REPORT_OBJECT_TYPE_BUFFER_EXT: return "Buffer";
        case VK_DEBUG_REPORT_OBJECT_TYPE_IMAGE_EXT: return "Image";
        case VK_DEBUG_REPORT_OBJECT_TYPE_EVENT_EXT: return "Event";
        case VK_DEBUG_REPORT_OBJECT_TYPE_QUERY_POOL_EXT: return "QueryPool";
        case VK_DEBUG_REPORT_OBJECT_TYPE_BUFFER_VIEW_EXT: return "BufferView";
        case VK_DEBUG_REPORT_OBJECT_TYPE_IMAGE_VIEW_EXT: return "ImageView";
        case VK_DEBUG_REPORT_OBJECT_TYPE_SHADER_MODULE_EXT: return "ShaderModule";
        case VK_DEBUG_REPORT_OBJECT_TYPE_PIPELINE_CACHE_EXT: return "PipelineCache";
        case VK_DEBUG_REPORT_OBJECT_TYPE_PIPELINE_LAYOUT_EXT: return "PipelineLayout";
        case VK_DEBUG_REPORT_OBJECT_TYPE_RENDER_PASS_EXT: return "RenderPass";
        case VK_DEBUG_REPORT_OBJECT_TYPE_PIPELINE_EXT: return "Pipeline";
        case VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_SET_LAYOUT_EXT: return "DescriptorSetLayout";
        case VK_DEBUG_REPORT_OBJECT_TYPE_SAMPLER_EXT: return "Sampler";
        case VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_POOL_EXT: return "DescriptorPool";
        case VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_SET_EXT: return "DescriptorSet";
        case VK_DEBUG_REPORT_OBJECT_TYPE_FRAMEBUFFER_EXT: return "Framebuffer";
        case VK_DEBUG_REPORT_OBJECT_TYPE_COMMAND_POOL_EXT: return "Command pool";
        case VK_DEBUG_REPORT_OBJECT_TYPE_SURFACE_KHR_EXT: return "SurfaceKHR";
        case VK_DEBUG_REPORT_OBJECT_TYPE_SWAPCHAIN_KHR_EXT: return "SwapchainKHR";
        case VK_DEBUG_REPORT_OBJECT_TYPE_DEBUG_REPORT_EXT: return "DebugReport";
        default: return "unrecognized";
    }
}


VKAPI_ATTR VkBool32 VKAPI_CALL myAirCallbackDebug (
VkDebugReportFlagsEXT msgFlags,
        VkDebugReportObjectTypeEXT objType,
        uint64_t srcObject,
        size_t /*location*/,
        int32_t msgCode,
        const char* pLayerPrefix,
        const char* pMsg,
        void* /*pUserData*/
  );


VKAPI_ATTR VkBool32 VKAPI_CALL myAirCallbackDebug(
        VkDebugReportFlagsEXT msgFlags,    // was VkDebugReportFlagsEXT
        VkDebugReportObjectTypeEXT objType,
        uint64_t srcObject,
        size_t /*location*/,
        int32_t msgCode,
        const char* pLayerPrefix,
        const char* pMsg,
        void* /*pUserData*/
){

   std::string report = std::string(to_string( objType )) + ", " + pLayerPrefix + ", " + pMsg;
 
  switch( msgFlags ){
        case VK_DEBUG_REPORT_INFORMATION_BIT_EXT:
            std::cout << "Info: " <<  report.c_str()  << " \n"; 
            break;

        case VK_DEBUG_REPORT_WARNING_BIT_EXT:
            std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! " << "\n";
            std::cout << "WARNING: " <<  report.c_str() << " \n";
            std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << "\n";
            break;

        case VK_DEBUG_REPORT_PERFORMANCE_WARNING_BIT_EXT:
            std::cout <<  "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! " << "\n";
            std::cout << "PERFORMANCE: " <<  report.c_str() << "\n";
            std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << "\n";
            break;

        case VK_DEBUG_REPORT_ERROR_BIT_EXT:
            std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << "\n";
            std::cout << "ERROR:  " <<  report.c_str() << "\n";
            std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! " << "\n";
            break;

        case VK_DEBUG_REPORT_DEBUG_BIT_EXT:
            report += "Debug: ";
            break;
    }


   return VK_FALSE;
}



inline void cb(VkResult myResult ) noexcept {

    if(myResult == VK_SUCCESS){
        std::cout << " vk_success is very all good " << "\n";
    }else{
        switch (myResult) {
            case VK_NOT_READY:
                std::cout <<  " vk not ready ! " << "\n";
                break;

            case VK_INCOMPLETE:
                std::cout <<  " vk is not Incompete " << "\n";
                break;

            case  VK_EVENT_SET:
                std::cout <<   " vk event set " << " \n";
                break;

            case VK_EVENT_RESET:
                std::cout <<  " vk event reset " << "\n";
                break;

                /*     case VK_INCOMPLETE:
                     std::cout << (  " vk incomplete \n";
                       break;*/

            case VK_ERROR_OUT_OF_HOST_MEMORY:
                std::cout <<   " VK_ERROR_OUT_OF_HOST_MEMORY  this error " << " \n";
                break;


            case VK_ERROR_OUT_OF_DEVICE_MEMORY:
                std::cout <<  " VK_ERROR_OUT_OF_DEVICE_MEMORY error " << "\n";
                break;


            case  VK_ERROR_INITIALIZATION_FAILED:
                std::cout << " VK_ERROR_INITIALIZATION_FAILED error " << "\n";
                break;

            case VK_ERROR_DEVICE_LOST:
                std::cout <<  "VK_ERROR_DEVICE_LOST " <<" \n";
                break;

            case VK_ERROR_MEMORY_MAP_FAILED:
                std::cout <<  "VK_ERROR_MEMORY_MAP_FAILED " << "\n";
                break;

            case VK_ERROR_LAYER_NOT_PRESENT:
                std::cout << " VK_ERROR_LAYER_NOT_PRESENT " <<"\n";
                break;

            case VK_ERROR_EXTENSION_NOT_PRESENT:
                std::cout << " VK_ERROR_EXTENSION_NOT_PRESENT " << "\n";
                break;


            case VK_ERROR_FEATURE_NOT_PRESENT:
                std::cout << "VK_ERROR_FEATURE_NOT_PRESENT " << " \n";
                break;


            case VK_ERROR_INCOMPATIBLE_DRIVER:
                std::cout << "VK_ERROR_INCOMPATIBLE_DRIVER " <<" \n";
                break;

            case VK_ERROR_TOO_MANY_OBJECTS:
                std::cout <<  "VK_ERROR_TOO_MANY_OBJECTS  " << "\n";
                break;


            case VK_ERROR_FORMAT_NOT_SUPPORTED:
                std::cout <<  " VK_ERROR_FORMAT_NOT_SUPPORTED error " << "\n";
                break;

            case VK_ERROR_FRAGMENTED_POOL:
                std::cout << "  VK_ERROR_FRAGMENTED_POOL " << "\n";
                break;

//             case VK_ERROR_UNKNOWN:
//                 std::cout << (  "VK_ERROR_UNKNOWN \n");
//                 break;



            case VK_ERROR_OUT_OF_POOL_MEMORY:
                std::cout << "VK_ERROR_OUT_OF_POOL_MEMORY " << " \n";
                break;


            case VK_ERROR_INVALID_EXTERNAL_HANDLE:
                std::cout <<  "VK_ERROR_INVALID_EXTERNAL_HANDLE " << "\n";
                break;

//             case VK_ERROR_FRAGMENTATION:
//                 std::cout << (  " eror m y VK_ERROR_FRAGMENTATION \n");
//                 break;


//             case VK_ERROR_INVALID_OPAQUE_CAPTURE_ADDRESS:
//                 std::cout << (  "VK_ERROR_INVALID_OPAQUE_CAPTURE_ADDRESS \n");
//                 break;


            case VK_ERROR_SURFACE_LOST_KHR:
                std::cout <<  "VK_ERROR_SURFACE_LOST_KHR " << "\n";
                break;



            case VK_ERROR_NATIVE_WINDOW_IN_USE_KHR:
                std::cout <<   "VK_ERROR_NATIVE_WINDOW_IN_USE_KHR " << " \n";
                break;


            case VK_SUBOPTIMAL_KHR:
                std::cout <<  "VK_SUBOPTIMAL_KHR " << "\n";
                break;



            case VK_ERROR_OUT_OF_DATE_KHR:
                std::cout << "VK_ERROR_OUT_OF_DATE_KHR " << "\n ";
                break;


            case VK_ERROR_INCOMPATIBLE_DISPLAY_KHR:
                std::cout << "VK_ERROR_INCOMPATIBLE_DISPLAY_KHR " << "\n";
                break;
                // VK_ERROR_OUT_OF_POOL_MEMORY = -1000069000,
                // VK_ERROR_INVALID_EXTERNAL_HANDLE = -1000072003,
                // VK_ERROR_FRAGMENTATION = -1000161000,

            case VK_ERROR_VALIDATION_FAILED_EXT:
                std::cout <<  "VK_ERROR_VALIDATION_FAILED_EXT " << "\n";
                break;


            case VK_ERROR_INVALID_SHADER_NV:
                std::cout << "VK_ERROR_INVALID_SHADER_NV " << "\n";
                break;


            case VK_ERROR_INVALID_DRM_FORMAT_MODIFIER_PLANE_LAYOUT_EXT:
                std::cout <<  "VK_ERROR_INVALID_DRM_FORMAT_MODIFIER_PLANE_LAYOUT_EXT " << "\n";
                break;


            case VK_ERROR_NOT_PERMITTED_EXT:
                std::cout <<   "VK_ERROR_NOT_PERMITTED_EXT " << "\n"; 
                break;



            case VK_ERROR_FULL_SCREEN_EXCLUSIVE_MODE_LOST_EXT:
                std::cout <<   "VK_ERROR_FULL_SCREEN_EXCLUSIVE_MODE_LOST_EXT " << "\n";
                break;



//             case VK_THREAD_IDLE_KHR:
//                 std::cout << (  "VK_THREAD_IDLE_KHR \n");
//                 break;


//             case VK_THREAD_DONE_KHR:
//                 std::cout << (  "VK_THREAD_DONE_KHR \n");
//                 break;
//
//
//
//             case VK_OPERATION_DEFERRED_KHR:
//                 std::cout << (  "VK_OPERATION_DEFERRED_KHR \n");
//                 break;
//
//
//
//             case VK_OPERATION_NOT_DEFERRED_KHR:
//                 std::cout << (  "VK_OPERATION_NOT_DEFERRED_KHR \n");
//                 break;
//
//
//             case VK_PIPELINE_COMPILE_REQUIRED_EXT:
//                 std::cout << (  "VK_PIPELINE_COMPILE_REQUIRED_EXT");
//                 break;

            default:
                std::cout <<  " not found error's " << "\n ";
        }
    }


}



void PreLoad::PreDestroy(){

  std::cout << " in destroy " << "\n";
}


 bool PreLoad::InstallWindow(HINSTANCE hInstance, int nCmdShow, HWND hWnd){
  
     
      VkResult res;
      uint32_t versionVulkan = 0;
      uint32_t currentVersionVulkan;

      std::cout << "build start vulkan " << "\n";
      res = losDLL->fp_vkEnumerateInstanceVersion(&versionVulkan);

     // int a;

     if (res != VK_SUCCESS) {
       std::cout << " ending apps " << "\n";
      
       //exit;
       return false;
     }else{

          uint16_t lMajor = VK_VERSION_MAJOR(versionVulkan);
          uint16_t lMinor = VK_VERSION_MINOR(versionVulkan);

          std::cout << " version vulkan == " << lMajor << " " << lMinor << "\n";
     }

     std::cout << "Initialize vulkan " << "\n";



  uint32_t instancExtensCount = 0;
  res = losDLL->fp_vkEnumerateInstanceExtensionProperties(nullptr, &instancExtensCount, nullptr);
  VkExtensionProperties* instaProperty = new VkExtensionProperties[instancExtensCount];
  res = losDLL->fp_vkEnumerateInstanceExtensionProperties(nullptr, &instancExtensCount, instaProperty);
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
  losDLL->fp_vkEnumerateInstanceLayerProperties(&numInstanceLayers, nullptr);
  std::cout << " number layers count's  = " << numInstanceLayers << "\n";
  VkLayerProperties* layerProperties = (VkLayerProperties*)malloc(numInstanceLayers * sizeof(VkLayerProperties));
  losDLL->fp_vkEnumerateInstanceLayerProperties(&numInstanceLayers, layerProperties);

  std::vector<const char*> layName;
  layName.push_back("VK_LAYER_KHRONOS_validation");

 


  // create 

  VkInstanceCreateInfo instanceInfo = {};
  instanceInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
  instanceInfo.pNext = nullptr;
  instanceInfo.pApplicationInfo = &appInfo;
  instanceInfo.enabledLayerCount = 1;
  instanceInfo.ppEnabledLayerNames = layName.data();
  

  const char* extensionToAdd[7];

   extensionToAdd[0] = "VK_KHR_display";
   extensionToAdd[1] = "VK_KHR_surface";
   extensionToAdd[2] = "VK_KHR_win32_surface";
   extensionToAdd[3] = "VK_EXT_debug_report";
   extensionToAdd[4] = "VK_EXT_debug_utils";
   extensionToAdd[5] = "VK_EXT_direct_mode_display";
   extensionToAdd[6] = "VK_EXT_swapchain_colorspace";


  instanceInfo.enabledExtensionCount = 7;
  instanceInfo.ppEnabledExtensionNames= extensionToAdd;

  res = losDLL->fp_vkCreateInstance(&instanceInfo, nullptr, &losInstance);
  cb(res);

  // check instance is ok ??? 

  
  VkDebugReportCallbackCreateInfoEXT  callbackLos =  {
    VK_STRUCTURE_TYPE_DEBUG_REPORT_CREATE_INFO_EXT,
    nullptr,
    VK_DEBUG_REPORT_ERROR_BIT_EXT | VK_DEBUG_REPORT_WARNING_BIT_EXT,
    myAirCallbackDebug,
    nullptr
  
  };


// COMPILER_FEATURE_ENTRY(__cpp_lib_ranges)
  std::cout << " my version c++ " << __cplusplus << " \n";

 // load polymorphic allocator 

    PFN_vkVoidFunction templaCreateDebugCallbackExt = losDLL->fp_vkGetInstanceProcAddr(losInstance, "vkCreateDebugReportCallbackEXT");
    if (!templaCreateDebugCallbackExt) throw "failed to load vkCreateDebugReportCallbackEXT";

    PFN_vkCreateDebugReportCallbackEXT losFCreateDebugCallbackExt = reinterpret_cast<PFN_vkCreateDebugReportCallbackEXT>(templaCreateDebugCallbackExt);

    losFCreateDebugCallbackExt(losInstance, &callbackLos, nullptr, &cb1); // ok work best 

    
    // vkDestroyDebugReportCallbackEXT
        PFN_vkVoidFunction templaDestroyDebugCallbackExt = losDLL->fp_vkGetInstanceProcAddr(losInstance, "vkDestroyDebugReportCallbackEXT");
    if (!templaDestroyDebugCallbackExt) throw "failed to load vkDestroyDebugReportCallbackEXT";

    PFN_vkDestroyDebugReportCallbackEXT losFDestroyDebugCallbackExt = reinterpret_cast<PFN_vkDestroyDebugReportCallbackEXT>(templaDestroyDebugCallbackExt);


   
    PFN_vkVoidFunction templaEnumaratedDevicesPhysics = losDLL->fp_vkGetInstanceProcAddr(losInstance, "vkEnumeratePhysicalDevices");
    if (!templaEnumaratedDevicesPhysics) throw "failed to load vkEnumeratePhysicalDevices";

    PFN_vkEnumeratePhysicalDevices losPhysicalEnumeratedDevices = reinterpret_cast<PFN_vkEnumeratePhysicalDevices>(templaEnumaratedDevicesPhysics);

    uint32_t physciNumber = 0;
    res = losPhysicalEnumeratedDevices(losInstance, &physciNumber, nullptr);
    cb(res);
     std::cout << " my physical == " << physciNumber << " \n";

 
    VkPhysicalDevice *mpPhysicalDevices = new VkPhysicalDevice[physciNumber];
    res = losPhysicalEnumeratedDevices(losInstance, &physciNumber, mpPhysicalDevices);
    auto myPhysicalDevice = mpPhysicalDevices[0];

    PFN_vkVoidFunction DevicePhysicalProperties = losDLL->fp_vkGetInstanceProcAddr(losInstance, "vkGetPhysicalDeviceProperties");
    if (!DevicePhysicalProperties) throw " failed to load DevicePhysicalProperties";

    PFN_vkGetPhysicalDeviceProperties losGetPhysicalDevicPropetries = reinterpret_cast<PFN_vkGetPhysicalDeviceProperties>(DevicePhysicalProperties);
    VkPhysicalDeviceProperties lPhysicalDeviceProperties;
    losGetPhysicalDevicPropetries(myPhysicalDevice, &lPhysicalDeviceProperties);
    std::cout << " my device property api: " <<  lPhysicalDeviceProperties.apiVersion;
    std::cout << " my device type : " << lPhysicalDeviceProperties.deviceType << " \n";
    std::cout << " my device name : " << lPhysicalDeviceProperties.deviceName << "\n";
    std::cout << " my device Limits.maxMemoryAllocationCount: " << lPhysicalDeviceProperties.limits.maxMemoryAllocationCount << " \n";
    std::cout << " my device Limits.minMemoryMapAlignment : " << lPhysicalDeviceProperties.limits.minMemoryMapAlignment << " \n";
    std::cout << " my device Limits.timestampPeriod : " << lPhysicalDeviceProperties.limits.timestampPeriod << " \n"; 



 
   PFN_vkVoidFunction tempDeviceMemoryProperties = losDLL->fp_vkGetInstanceProcAddr(losInstance, "vkGetPhysicalDeviceMemoryProperties");
   if(!tempDeviceMemoryProperties) throw " Failed to load vkGetPhysicalDeviceMemoryProperties";

   PFN_vkGetPhysicalDeviceMemoryProperties losGetPhysicalMemmoryDeviceProperties = reinterpret_cast<PFN_vkGetPhysicalDeviceMemoryProperties>(tempDeviceMemoryProperties);
   losGetPhysicalMemmoryDeviceProperties(myPhysicalDevice, &myPhysicalDeviceMemoryPropertises2);



   std::cout << " my memory properties (type count) : " << myPhysicalDeviceMemoryPropertises2.memoryTypeCount << "\n";
   std::cout << " my memory properties (memoryHeapCount) : " << myPhysicalDeviceMemoryPropertises2.memoryHeapCount << "\n";
    for( int i =0; i < myPhysicalDeviceMemoryPropertises2.memoryHeapCount; i++){
      
      //std::cout << " my memory flags " << 
   
          if(myPhysicalDeviceMemoryPropertises2.memoryHeaps[i].flags == 0x00000001){
            std::cout << " my type memory head ==  VK_MEMORY_HEAP_DEVICE_LOCAL_BIT " << "\n";
          }else if (myPhysicalDeviceMemoryPropertises2.memoryHeaps[i].flags == 0x00000002){
            std::cout << " my type memory head == VK_MEMORY_HEAP_MULTI_INSTANCE_BIT "  << "\n";
          }

std::cout << " my memory properties flags type ()" << " " << myPhysicalDeviceMemoryPropertises2.memoryHeaps[i].flags << "\n";
      std::cout << " my memory properties ()" << " " << myPhysicalDeviceMemoryPropertises2.memoryHeaps[i].size << "\n";
    }






// y memory properties (memoryHeapCount) : 3
//  my type memory head ==  VK_MEMORY_HEAP_DEVICE_LOCAL_BIT
//  my memory properties flags type () 1
//  my memory properties () 8421113856
//  my memory properties flags type () 0
//  my memory properties () 17132777472
//  my type memory head ==  VK_MEMORY_HEAP_DEVICE_LOCAL_BIT
//  my memory properties flags type () 1
//  my memory properties () 224395264


    
 // memoryHeapCount



   PFN_vkVoidFunction tempEnumerateDevicesExtenProper = losDLL->fp_vkGetInstanceProcAddr(losInstance, "vkEnumerateDeviceExtensionProperties");
   if(!tempEnumerateDevicesExtenProper) throw " Failed to load vkEnumerateDeviceExtensionProperties";

   PFN_vkEnumerateDeviceExtensionProperties losGetPhysicalMemmoryDevExtensionEnum = reinterpret_cast<PFN_vkEnumerateDeviceExtensionProperties>(tempEnumerateDevicesExtenProper);
   //losGetPhysicalMemmoryDevExtensionEnum(myPhysicalDevice, &myPhysicalDeviceMemoryPropertises2);

   uint32_t deviceExten = 0;
   VkExtensionProperties *deviceExtenPo = nullptr;
   res = losGetPhysicalMemmoryDevExtensionEnum(myPhysicalDevice, nullptr, &deviceExten, nullptr);
   std::cout << " my nubmer exten ==  " << deviceExten << " \n";


   VkBool32 swapchainExtFound = 0;
   VkExtensionProperties* deveExten1 = new VkExtensionProperties[deviceExten];
   res = losGetPhysicalMemmoryDevExtensionEnum(myPhysicalDevice, nullptr, &deviceExten,deveExten1);
   
      // const char *extensionNames[16] = {0};
       for (uint32_t i = 0; i < deviceExten; i++)
       {
        std::cout  << " my extension this == " <<  deveExten1[i].extensionName << " \n";
       }


       // SwapChain ! main values
 

  // HINSTANCE hInstance, int nCmdShow, HWND hWnd
      VkWin32SurfaceCreateInfoKHR surface_los = {
           VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR,
           nullptr,
           0,
           hInstance,
           hWnd
      };


      res = vkCreateWin32SurfaceKHR(losInstance, &surface_los, nullptr, &mySurfaceLos);
      std::cout << " call pre vulkan load " << " \n";
      cb(res);


       // or create Devices and Queue index




     

 delete [] deveExten1;
 // destroySurface 
 losFDestroyDebugCallbackExt(losInstance, cb1, nullptr);
 losDLL->fp_vkDestroyInstance(losInstance, NULL);

   return false;
 }