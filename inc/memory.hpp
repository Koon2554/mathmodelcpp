// memory.hpp
#pragma once  // ป้องกัน include ซ้ำ

#ifdef _WIN32
#include <windows.h>
#include <psapi.h>

static SIZE_T before = 0;

SIZE_T getMemoryUsageKB() {
    PROCESS_MEMORY_COUNTERS pmc;
    GetProcessMemoryInfo(GetCurrentProcess(), &pmc, sizeof(pmc));
    return pmc.WorkingSetSize / 1024;
}

void start_memory() {
    before = getMemoryUsageKB();
}

SIZE_T stop_memory() {
    SIZE_T after = getMemoryUsageKB();
    return (after - before);
}

#else
// สำหรับ Linux / Colab / Kaggle
#include <sys/resource.h>
#include <unistd.h>
#include <chrono>
#include <thread>

static long long before = 0;

long long getMemoryUsageKB() {
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    return usage.ru_maxrss; // ru_maxrss เป็น KB
}

void start_memory() {
    before = getMemoryUsageKB();
}

long long stop_memory() {
    long long after = getMemoryUsageKB();
    return (after - before);
}

#endif
