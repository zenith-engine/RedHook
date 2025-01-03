#pragma once

/*Windows includes*/
#include <windows.h>
#include <windowsx.h>

#include <string>
#include <xstring>

#include <sstream>
#include <fstream>
#include <iostream>

#include <unordered_map>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <chrono>

#include <memory>
#include <Psapi.h>

#include <timeapi.h>
#pragma comment(lib, "winmm.lib")

#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>

using namespace std;

inline HMODULE export_adress{ (HMODULE)0x63686970 };