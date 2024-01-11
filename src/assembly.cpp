#include "assembly.h"

#if CPPLM_PLATFORM_WINDOWS
#include <windows.h>
#elif CPPLM_PLATFORM_LINUX
#include <dlfcn.h>
#elif CPPLM_PLATFORM_APPLE
#include <dlfcn.h>
#else
#error "Platform is not supported!"
#endif

namespace cpplm {
    thread_local static std::string lastError;

    std::unique_ptr<Assembly> Assembly::LoadFromPath(const std::filesystem::path& assemblyPath) {
#if CPPLM_PLATFORM_WINDOWS
        void* handle = static_cast<void*>(LoadLibraryW(assemblyPath.c_str()));
#else
        void* handle = dlopen(assemblyPath.string().c_str(), RTLD_LAZY);
#endif // CPPLM_PLATFORM_WINDOWS
        if (handle) {
            return std::unique_ptr<Assembly>(new Assembly(handle));
        }
#if CPPLM_PLATFORM_WINDOWS
        uint32_t errorCode = GetLastError();
        if (errorCode != 0) {
            LPSTR messageBuffer = nullptr;
            size_t size = FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
                NULL, errorCode, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPSTR)&messageBuffer, 0, NULL);
            lastError = std::string(messageBuffer, size);
            LocalFree(messageBuffer);
        }
#else
        lastError = dlerror();
#endif // CPPLM_PLATFORM_WINDOWS
        return nullptr;
    }

    std::string Assembly::GetError() {
        return lastError;
    }

    Assembly::Assembly(void* handle) : _handle{handle} {
    }

    Assembly::~Assembly() {
#if CPPLM_PLATFORM_WINDOWS
        FreeLibrary(static_cast<HMODULE>(_handle));
#else
        dlclose(_handle);
#endif
    }

    void* Assembly::GetFunction(const char* functionName) const {
#if CPPLM_PLATFORM_WINDOWS
        return reinterpret_cast<void*>(GetProcAddress(static_cast<HMODULE>(_handle), functionName));
#else
        return dlsym(_handle, functionName);
#endif
    }
}
