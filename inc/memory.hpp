#ifndef MEMORY_HPP
#define MEMORY_HPP

#define _HAS_STD_BYTE 0
#include <iostream>

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <psapi.h>

#pragma comment(lib, "psapi.lib")

using namespace std;

static SIZE_T before = 0;

SIZE_T getMemoryUsageKB() {
    PROCESS_MEMORY_COUNTERS pmc;
    if (GetProcessMemoryInfo(GetCurrentProcess(), &pmc, sizeof(pmc))) {
        return pmc.WorkingSetSize / 1024;
    }
    return 0;
}

void start_memory() {
    before = getMemoryUsageKB();
}

void stop_memory() {
    SIZE_T after = getMemoryUsageKB();
    cout << "Memory used: " << (after - before) << " KB" << endl;
}

#endif
