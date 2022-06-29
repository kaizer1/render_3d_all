#pragma once

#include <windows.h>
#include <vulkan/vulkan.h>
#include <vulkan/vulkan_win32.h>


#include <string>
//#include <EasyVulkanMain.hpp>

#include <iostream>


struct VkDll {
    VkResult Initialize() {
#if defined(__linux__)
        library = dlopen("libvulkan.so", RTLD_NOW | RTLD_LOCAL);
        if (!library) library = dlopen("libvulkan.so.1", RTLD_NOW | RTLD_LOCAL);
#elif defined(_WIN32)
         std::cout << " pre load " << " \n";
        library = LoadLibrary(TEXT("vulkan-1.dll")); // was .dll
           std::cout << " post load " << " \n";
        if( !library)
           std::cout << " not loaded library !!! " << " \n";
#endif
#if !defined(__APPLE__)
        if (library == 0) return VK_ERROR_INITIALIZATION_FAILED;
#endif
        return VK_SUCCESS;
    }
    void Close() {
#if defined(__linux__)
        dlclose(library);
#elif defined(_WIN32)
        FreeLibrary(library);
#endif
#if !defined(__APPLE__)
        library = 0;
#endif
    }

#if defined(__APPLE__)
#define APPLE_FP(name) name
#else
#define APPLE_FP(nama) nullptr
#endif

    // Function pointers, loaded from the dll
    PFN_vkCreateInstance fp_vkCreateInstance = APPLE_FP(vkCreateInstance);
    PFN_vkEnumerateInstanceExtensionProperties fp_vkEnumerateInstanceExtensionProperties =
        APPLE_FP(vkEnumerateInstanceExtensionProperties);
    PFN_vkEnumerateInstanceLayerProperties fp_vkEnumerateInstanceLayerProperties = APPLE_FP(vkEnumerateInstanceLayerProperties);
    PFN_vkDestroyInstance fp_vkDestroyInstance = APPLE_FP(vkDestroyInstance);
    PFN_vkEnumeratePhysicalDevices fp_vkEnumeratePhysicalDevices = APPLE_FP(vkEnumeratePhysicalDevices);
    PFN_vkGetPhysicalDeviceFeatures fp_vkGetPhysicalDeviceFeatures = APPLE_FP(vkGetPhysicalDeviceFeatures);
    PFN_vkGetPhysicalDeviceFormatProperties fp_vkGetPhysicalDeviceFormatProperties = APPLE_FP(vkGetPhysicalDeviceFormatProperties);
    PFN_vkGetPhysicalDeviceImageFormatProperties fp_vkGetPhysicalDeviceImageFormatProperties =
        APPLE_FP(vkGetPhysicalDeviceImageFormatProperties);
    PFN_vkGetPhysicalDeviceProperties fp_vkGetPhysicalDeviceProperties = APPLE_FP(vkGetPhysicalDeviceProperties);
    PFN_vkGetPhysicalDeviceQueueFamilyProperties fp_vkGetPhysicalDeviceQueueFamilyProperties =
        APPLE_FP(vkGetPhysicalDeviceQueueFamilyProperties);
    PFN_vkGetPhysicalDeviceMemoryProperties fp_vkGetPhysicalDeviceMemoryProperties = APPLE_FP(vkGetPhysicalDeviceMemoryProperties);
    PFN_vkGetInstanceProcAddr fp_vkGetInstanceProcAddr = APPLE_FP(vkGetInstanceProcAddr);
    PFN_vkGetDeviceProcAddr fp_vkGetDeviceProcAddr = APPLE_FP(vkGetDeviceProcAddr);
    PFN_vkCreateDevice fp_vkCreateDevice = APPLE_FP(vkCreateDevice);
    PFN_vkDestroyDevice fp_vkDestroyDevice = APPLE_FP(vkDestroyDevice);
    PFN_vkEnumerateDeviceExtensionProperties fp_vkEnumerateDeviceExtensionProperties =
        APPLE_FP(vkEnumerateDeviceExtensionProperties);
    PFN_vkGetDeviceQueue fp_vkGetDeviceQueue = APPLE_FP(vkGetDeviceQueue);
    PFN_vkCreateImage fp_vkCreateImage = APPLE_FP(vkCreateImage);
    PFN_vkDestroyImage fp_vkDestroyImage = APPLE_FP(vkDestroyImage);
    PFN_vkGetBufferMemoryRequirements fp_vkGetBufferMemoryRequirements = APPLE_FP(vkGetBufferMemoryRequirements);
    PFN_vkGetImageMemoryRequirements fp_vkGetImageMemoryRequirements = APPLE_FP(vkGetImageMemoryRequirements);
    PFN_vkGetImageSparseMemoryRequirements fp_vkGetImageSparseMemoryRequirements = APPLE_FP(vkGetImageSparseMemoryRequirements);
    PFN_vkEnumerateInstanceVersion fp_vkEnumerateInstanceVersion = APPLE_FP(vkEnumerateInstanceVersion);
    PFN_vkEnumeratePhysicalDeviceGroups fp_vkEnumeratePhysicalDeviceGroups = APPLE_FP(vkEnumeratePhysicalDeviceGroups);
    PFN_vkGetPhysicalDeviceFeatures2 fp_vkGetPhysicalDeviceFeatures2 = APPLE_FP(vkGetPhysicalDeviceFeatures2);
    PFN_vkGetPhysicalDeviceProperties2 fp_vkGetPhysicalDeviceProperties2 = APPLE_FP(vkGetPhysicalDeviceProperties2);
    PFN_vkGetPhysicalDeviceFormatProperties2 fp_vkGetPhysicalDeviceFormatProperties2 =
        APPLE_FP(vkGetPhysicalDeviceFormatProperties2);
    PFN_vkGetPhysicalDeviceQueueFamilyProperties2 fp_vkGetPhysicalDeviceQueueFamilyProperties2 =
        APPLE_FP(vkGetPhysicalDeviceQueueFamilyProperties2);
    PFN_vkGetPhysicalDeviceMemoryProperties2 fp_vkGetPhysicalDeviceMemoryProperties2 =
        APPLE_FP(vkGetPhysicalDeviceMemoryProperties2);
    PFN_vkDestroySurfaceKHR fp_vkDestroySurfaceKHR = APPLE_FP(vkDestroySurfaceKHR);
    PFN_vkCreateSemaphore fp_vkCreateSemaphore = APPLE_FP(vkCreateSemaphore);
    PFN_vkDeviceWaitIdle fp_vkDeviceWaitIdle = APPLE_FP(vkDeviceWaitIdle);
    //PFN_vkEnumerateInstanceLayerProperties fp_vkEnumerateInstanceLayerProperties = APPLE_FP(vkEnumerateInstanceLayerProperties);

#ifdef VK_USE_PLATFORM_XLIB_KHR
    PFN_vkCreateXlibSurfaceKHR fp_vkCreateXlibSurfaceKHR = APPLE_FP(vkCreateXlibSurfaceKHR);
#endif  // VK_USE_PLATFORM_XLIB_KHR
#ifdef VK_USE_PLATFORM_XLIB_KHR
    PFN_vkGetPhysicalDeviceXlibPresentationSupportKHR fp_vkGetPhysicalDeviceXlibPresentationSupportKHR =
        APPLE_FP(vkGetPhysicalDeviceXlibPresentationSupportKHR);
#endif  // VK_USE_PLATFORM_XLIB_KHR
#ifdef VK_USE_PLATFORM_XCB_KHR
    PFN_vkCreateXcbSurfaceKHR fp_vkCreateXcbSurfaceKHR = APPLE_FP(vkCreateXcbSurfaceKHR);
#endif  // VK_USE_PLATFORM_XCB_KHR
#ifdef VK_USE_PLATFORM_XCB_KHR
    PFN_vkGetPhysicalDeviceXcbPresentationSupportKHR fp_vkGetPhysicalDeviceXcbPresentationSupportKHR =
        APPLE_FP(vkGetPhysicalDeviceXcbPresentationSupportKHR);
#endif  // VK_USE_PLATFORM_XCB_KHR
#ifdef VK_USE_PLATFORM_WAYLAND_KHR
    PFN_vkCreateWaylandSurfaceKHR fp_vkCreateWaylandSurfaceKHR = APPLE_FP(vkCreateWaylandSurfaceKHR);
#endif  // VK_USE_PLATFORM_WAYLAND_KHR
#ifdef VK_USE_PLATFORM_WAYLAND_KHR
    PFN_vkGetPhysicalDeviceWaylandPresentationSupportKHR fp_vkGetPhysicalDeviceWaylandPresentationSupportKHR =
        APPLE_FP(vkGetPhysicalDeviceWaylandPresentationSupportKHR);
#endif  // VK_USE_PLATFORM_WAYLAND_KHR
#ifdef VK_USE_PLATFORM_ANDROID_KHR
    PFN_vkCreateAndroidSurfaceKHR fp_vkCreateAndroidSurfaceKHR = APPLE_FP(vkCreateAndroidSurfaceKHR);
#endif  // VK_USE_PLATFORM_ANDROID_KHR
#ifdef _WIN32 // was VK_USE_PLATFORM_WIN32_KHR
    PFN_vkCreateWin32SurfaceKHR fp_vkCreateWin32SurfaceKHR = APPLE_FP(vkCreateWin32SurfaceKHR);
#endif  // VK_USE_PLATFORM_WIN32_KHR
#ifdef _WIN32
    PFN_vkGetPhysicalDeviceWin32PresentationSupportKHR fp_vkGetPhysicalDeviceWin32PresentationSupportKHR =
        APPLE_FP(vkGetPhysicalDeviceWin32PresentationSupportKHR);
#endif  // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_MACOS_MVK
    PFN_vkCreateMacOSSurfaceMVK fp_vkCreateMacOSSurfaceMVK = APPLE_FP(vkCreateMacOSSurfaceMVK);
#endif  // VK_USE_PLATFORM_MACOS_MVK
#ifdef VK_USE_PLATFORM_METAL_EXT
    PFN_vkCreateMetalSurfaceEXT fp_vkCreateMetalSurfaceEXT = APPLE_FP(vkCreateMetalSurfaceEXT);
#endif  // VK_USE_PLATFORM_METAL_EXT
    void InitializeDispatchPointers() {
        Load(fp_vkCreateInstance, "vkCreateInstance");
        Load(fp_vkDestroyInstance, "vkDestroyInstance");
        Load(fp_vkEnumeratePhysicalDevices, "vkEnumeratePhysicalDevices");
        Load(fp_vkGetPhysicalDeviceFeatures, "vkGetPhysicalDeviceFeatures");
        Load(fp_vkGetPhysicalDeviceFormatProperties, "vkGetPhysicalDeviceFormatProperties");
        Load(fp_vkGetPhysicalDeviceImageFormatProperties, "vkGetPhysicalDeviceImageFormatProperties");
        Load(fp_vkGetPhysicalDeviceProperties, "vkGetPhysicalDeviceProperties");
        Load(fp_vkGetPhysicalDeviceQueueFamilyProperties, "vkGetPhysicalDeviceQueueFamilyProperties");
        Load(fp_vkGetPhysicalDeviceMemoryProperties, "vkGetPhysicalDeviceMemoryProperties");
        Load(fp_vkGetInstanceProcAddr, "vkGetInstanceProcAddr");
        Load(fp_vkGetDeviceProcAddr, "vkGetDeviceProcAddr");
        Load(fp_vkCreateDevice, "vkCreateDevice");
        Load(fp_vkDestroyDevice, "vkDestroyDevice");
        Load(fp_vkEnumerateInstanceExtensionProperties, "vkEnumerateInstanceExtensionProperties");
        Load(fp_vkEnumerateDeviceExtensionProperties, "vkEnumerateDeviceExtensionProperties");
        Load(fp_vkEnumerateInstanceLayerProperties, "vkEnumerateInstanceLayerProperties");
        Load(fp_vkGetDeviceQueue, "vkGetDeviceQueue");
        Load(fp_vkCreateImage, "vkCreateImage");
        Load(fp_vkDestroyImage, "vkDestroyImage");
        Load(fp_vkGetBufferMemoryRequirements, "vkGetBufferMemoryRequirements");
        Load(fp_vkGetImageMemoryRequirements, "vkGetImageMemoryRequirements");
        Load(fp_vkGetImageSparseMemoryRequirements, "vkGetImageSparseMemoryRequirements");
        Load(fp_vkEnumerateInstanceVersion, "vkEnumerateInstanceVersion");
        Load(fp_vkEnumeratePhysicalDeviceGroups, "vkEnumeratePhysicalDeviceGroups");
        Load(fp_vkGetPhysicalDeviceFeatures2, "vkGetPhysicalDeviceFeatures2");
        Load(fp_vkGetPhysicalDeviceProperties2, "vkGetPhysicalDeviceProperties2");
        Load(fp_vkGetPhysicalDeviceFormatProperties2, "vkGetPhysicalDeviceFormatProperties2");
        Load(fp_vkGetPhysicalDeviceQueueFamilyProperties2, "vkGetPhysicalDeviceQueueFamilyProperties2");
        Load(fp_vkGetPhysicalDeviceMemoryProperties2, "vkGetPhysicalDeviceMemoryProperties2");
        Load(fp_vkDestroySurfaceKHR, "vkDestroySurfaceKHR");
       // Load(fp_vkEnumerateInstanceLayerProperties, "vkEnumerateInstanceLayerProperties");

#ifdef VK_USE_PLATFORM_XLIB_KHR
        Load(fp_vkCreateXlibSurfaceKHR, "vkCreateXlibSurfaceKHR");
#endif  // VK_USE_PLATFORM_XLIB_KHR
#ifdef VK_USE_PLATFORM_XLIB_KHR
        Load(fp_vkGetPhysicalDeviceXlibPresentationSupportKHR, "vkGetPhysicalDeviceXlibPresentationSupportKHR");
#endif  // VK_USE_PLATFORM_XLIB_KHR
#ifdef VK_USE_PLATFORM_XCB_KHR
        Load(fp_vkCreateXcbSurfaceKHR, "vkCreateXcbSurfaceKHR");
#endif  // VK_USE_PLATFORM_XCB_KHR
#ifdef VK_USE_PLATFORM_XCB_KHR
        Load(fp_vkGetPhysicalDeviceXcbPresentationSupportKHR, "vkGetPhysicalDeviceXcbPresentationSupportKHR");
#endif  // VK_USE_PLATFORM_XCB_KHR
#ifdef VK_USE_PLATFORM_WAYLAND_KHR
        Load(fp_vkCreateWaylandSurfaceKHR, "vkCreateWaylandSurfaceKHR");
#endif  // VK_USE_PLATFORM_WAYLAND_KHR
#ifdef VK_USE_PLATFORM_WAYLAND_KHR
        Load(fp_vkGetPhysicalDeviceWaylandPresentationSupportKHR, "vkGetPhysicalDeviceWaylandPresentationSupportKHR");
#endif  // VK_USE_PLATFORM_WAYLAND_KHR
#ifdef VK_USE_PLATFORM_ANDROID_KHR
        Load(fp_vkCreateAndroidSurfaceKHR, "vkCreateAndroidSurfaceKHR");
#endif  // VK_USE_PLATFORM_ANDROID_KHR
#ifdef _WIN32
        Load(fp_vkCreateWin32SurfaceKHR, "vkCreateWin32SurfaceKHR");
#endif  // VK_USE_PLATFORM_WIN32_KHR
#ifdef _WIN32
        Load(fp_vkGetPhysicalDeviceWin32PresentationSupportKHR, "vkGetPhysicalDeviceWin32PresentationSupportKHR");
#endif  // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_MACOS_MVK
        Load(fp_vkCreateMacOSSurfaceMVK, "vkCreateMacOSSurfaceMVK");
#endif  // VK_USE_PLATFORM_MACOS_MVK
#ifdef VK_USE_PLATFORM_METAL_EXT
        Load(fp_vkCreateMetalSurfaceEXT, "vkCreateMetalSurfaceEXT");
#endif  // VK_USE_PLATFORM_METAL_EXT
    }

private:
    template <typename T>
    void Load(T& func_dest, const char* func_name) {
#if defined(__linux__)
        func_dest = reinterpret_cast<T>(dlsym(library, func_name));
#elif defined(_WIN32)
        func_dest = reinterpret_cast<T>(GetProcAddress(library, func_name));
#endif
    }
#if defined(__linux__)
    void* library;
#elif defined(_WIN32)
    HMODULE library;
#endif
};

