// Include this file in your project to enable ANSI support.

#ifndef __ANSI_H__
#define __ANSI_H__

#ifdef _WIN32 // (Windows)
    #include <windows.h>
    HANDLE ANSI_storage;
#endif


void disableANSI(){
    #ifdef _WIN32
        SetConsoleMode(ANSI_storage, 0);
    #endif
    //linux have a native support for ANSI, so no need to do anything
}

void enableANSI(){
    atexit(disableANSI);
    #ifdef _WIN32
        HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        ANSI_storage = hOut;
        DWORD mode = 0;
        GetConsoleMode(hOut, &mode);
        mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
        SetConsoleMode(hOut, mode);
    #endif
    //linux have a native support for ANSI, so no need to do anything
}


#endif