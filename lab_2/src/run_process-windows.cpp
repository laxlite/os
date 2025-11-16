#include<windows.h>
#include<iostream>
#include"run_process-windows.hpp"

using std::cout, std::endl;

int run_process(int time, LPCSTR path_to_file, LPSTR options){
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    if(!CreateProcess(path_to_file, 
        options,
        NULL,
        NULL,
        false,
        0,
        NULL,
        NULL,
        &si,
        &pi
    )){
        cout << "CreateProcess failed: " << GetLastError() << endl;
        exit(1);
    }
    cout << "Child process was started" << endl;
    WaitForSingleObject(pi.hProcess, time * 1000);

    LPDWORD exit_code;    
    GetExitCodeProcess(pi.hProcess, exit_code);
    cout << "Child process was complete with status: " <<  exit_code << endl;
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
}