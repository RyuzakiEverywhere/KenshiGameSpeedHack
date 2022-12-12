// dllmain.cpp : Defines the entry point for the DLL application.
#include <Windows.h> //Windows Include :D
#include <iostream> //for FILE and using namespace std :D
#include "Kenshi_GameSpeedHack.h"
using namespace std;

bool OpenConsole() {
    FILE* fp;
    freopen_s(&fp, "CONOUT$", "w", stdout); //Opening Console :D
    SetConsoleTitleA("KenshiGameSpeedHack by RyuzakiEverywhere");
    return true;
}

DWORD WINAPI KenshiThread(HMODULE m) 
{
    if (FindWindowA(0, "Kenshi 1.0.59 - x64 (Newland)")) 
    {
        if (OpenConsole())
        {
            std::cout << "Console Is Successfully Opened" << std::endl;
            Sleep(5000);
            Speedhack::Setup();
            while (1)
            {
                Sleep(2000);
                if (GetAsyncKeyState(VK_F6) && 1) 
                {
                    cout << "\nSpeed is Set to 5.0" << endl;
                    Speedhack::SetSpeed(5.0);
                }
                if (GetAsyncKeyState(VK_F7) && 1) 
                {
                    cout << "\nSpeed is Set to 10.0" << endl;
                    Speedhack::SetSpeed(10.0);
                }
                if (GetAsyncKeyState(VK_F8) && 1)
                {
                    cout << "\nSpeed is Set to 20.0" << endl;
                    Speedhack::SetSpeed(20.0);
                }
                if (GetAsyncKeyState(VK_INSERT) && 1) 
                {
                    Speedhack::Detach();
                    cout << "Detour and Console Successfully Detached" << endl;
                    Sleep(5000);
                    FreeConsole();
                }
            }
        }
       
    }
    else {
        return FALSE;
    }
    return TRUE;
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CreateThread(0, 0, (LPTHREAD_START_ROUTINE)KenshiThread, 0, 0, 0);
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

