﻿#include "common.hpp"

using f_KeyboardHandler = void(*)(DWORD _Key, WORD _Repeats, BYTE _ScanCode, BOOL _IsExtended, BOOL _IsWithAlt, BOOL _WasDownBefore, BOOL _IsUpNow);

enum TextAlignment
{
	TextAlignment_Left,
	TextAlignment_Center,
	TextAlignment_Right
};

enum LogType
{
	Log_Info = 1,
	Log_Warning,
	Log_Error
};

int __declspec(dllexport) RH_GetMinorVersion() {
	static uint64_t function;
	if (!function)
		function = (uint64_t)GetProcAddress(export_adress, "rh_get_minor_version");

	return ((int(*)())function)();
}

int __declspec(dllexport) RH_GetMajorVersion() {
	static uint64_t function;
	if (!function)
		function = (uint64_t)GetProcAddress(export_adress, "rh_get_major_version");

	return ((int(*)())function)();
}

void __declspec(dllexport) keyboardHandlerRegister(f_KeyboardHandler _Function) {
	static uint64_t function;
	if (!function)
		function = (uint64_t)GetProcAddress(export_adress, "keyboard_handler_register");
	((void(*)(f_KeyboardHandler))function)(_Function);
}

void __declspec(dllexport) keyboardHandlerUnregister(f_KeyboardHandler _Function) {
	static uint64_t function;
	if (!function)
		function = (uint64_t)GetProcAddress(export_adress, "keyboard_handler_unregister");
	((void(*)(f_KeyboardHandler))function)(_Function);
}

void __declspec(dllexport) scriptWait(unsigned long waitTime) {
	static uint64_t function;
	if (!function)
		function = (uint64_t)GetProcAddress(export_adress, "script_wait");
	((void(*)(unsigned long))function)(waitTime);
}

void __declspec(dllexport) scriptRegister(HMODULE module, void(*_Function)()) {
	static uint64_t function;
	if (!function)
		function = (uint64_t)GetProcAddress(export_adress, "script_register");
	((void(*)(HMODULE, void(*)()))function)(module, _Function);
}

void __declspec(dllexport) scriptUnregister(HMODULE module) {
	static uint64_t function;
	if (!function)
		function = (uint64_t)GetProcAddress(export_adress, "script_unregister"); 
	((void(*)(HMODULE))function)(module);
}

void __declspec(dllexport) scriptUnregister(void(*_Function)()) { 
	static uint64_t function;
	if (!function)
		function = (uint64_t)GetProcAddress(export_adress, "script_unregister");
	((void(*)(void(*)()))function)(_Function);
}

void __declspec(dllexport) nativeInit(UINT64 hash) {
	static uint64_t function;
	if (!function)
		function = (uint64_t)GetProcAddress(export_adress, "native_call_begin"); 
	((void(*)(UINT64))function)(hash);
}

void __declspec(dllexport) nativePush64(UINT64 val) {
	static uint64_t function;
	if (!function)
		function = (uint64_t)GetProcAddress(export_adress, "native_push"); 
	((void(*)(UINT64))function)(val);
}

__declspec(dllexport) uint64_t* nativeCall() {
	static uint64_t function;
	if (!function)
		function = (uint64_t)GetProcAddress(export_adress, "native_call_end"); 
	return ((uint64_t*(*)())function)();
}

void __declspec(dllexport) Print(LogType _Type, const char* _Format, ...) {
	static uint64_t function;
	if (!function)
		function = (uint64_t)GetProcAddress(export_adress, "print");
	return ((void(*)(LogType, const char*))function)(_Type, _Format);
}

uint64_t  __declspec(dllexport) RH_LoadImage(const char* _FilePath) {
	static uint64_t function;
	if (!function)
		function = (uint64_t)GetProcAddress(export_adress, "rh_load_image"); 
	return ((uint64_t(*)(const char*))function)(_FilePath);
}

void __declspec(dllexport) RH_DrawImage(uint64_t _TextureId, float _X, float _Y, float _Width, float _Height, int _R, int _G, int _B, int _A) {
	static uint64_t function;
	if (!function)
		function = (uint64_t)GetProcAddress(export_adress, "rh_draw_image"); 
	((void(*)(uint64_t _TextureId, float _X, float _Y, float _Width, float _Height, int _R, int _G, int _B, int _A))function)(_TextureId, _X, _Y, _Width, _Height, _R, _G, _B, _A);
}

void __declspec(dllexport) RH_DrawRect(float _X, float _Y, float _Width, float _Height, int _R, int _G, int _B, int _A) {
	static uint64_t function;
	if (!function)
		function = (uint64_t)GetProcAddress(export_adress, "rh_draw_rect");
	return ((void(*)(float, float, float, float, int, int, int, int))function)(_X, _Y, _Width, _Height, _R, _G, _B, _A);
}

void __declspec(dllexport) RH_DrawText(const char* _Text, float _X, float _Y, int _FontId, float _FontScale, int _R, int _G, int _B, int _A, TextAlignment _TextAlignment) {
	static uint64_t function;
	if (!function)
		function = (uint64_t)GetProcAddress(export_adress, "rh_draw_text");
	return ((void(*)(const char*, float, float, int, float, int, int, int, int, int))function)(_Text, _X, _Y, _FontId, _FontScale, _R, _G, _B, _A, _TextAlignment);
}

float __declspec(dllexport) RH_GetTextWidth(const char* _Text, int _FontId, float _FontScale) {
	static uint64_t function;
	if (!function)
		function = (uint64_t)GetProcAddress(export_adress, "rh_get_text_width");
	return ((float(*)(const char*, int, float))function)(_Text, _FontId, _FontScale);
}

void __declspec(dllexport) RH_GetTextHeight(const char* _Text, int _FontId, float _FontScale, float* _OutputValue) {
	static uint64_t function;
	if (!function)
		function = (uint64_t)GetProcAddress(export_adress, "rh_get_text_height");
	return ((void(*)(const char*, int, float, float*))function)(_Text, _FontId, _FontScale, _OutputValue);
}

void __declspec(dllexport) RH_SetTextWrapWidth(float _WrapWidth) {
	static uint64_t function;
	if (!function)
		function = (uint64_t)GetProcAddress(export_adress, "rh_set_text_wrap_width");
	return ((void(*)(float))function)(_WrapWidth);
}

void __declspec(dllexport) RH_ActionDisable(const char* _ActionName, bool _Disabled) {
	static uint64_t function;
	if (!function)
		function = (uint64_t)GetProcAddress(export_adress, "rh_action_disable"); 
	return ((void(*)(const char*, bool))function)(_ActionName, _Disabled);
}

DWORD WINAPI MainThread(LPVOID lp) {
	while (true) {
		Sleep(5000);
	}
	return 1;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved) {
	switch (ul_reason_for_call) {
	case DLL_PROCESS_ATTACH:
		CreateThread(0, 0, MainThread, hModule, 0, 0);
		break;
	case DLL_THREAD_ATTACH:
		break;
	case DLL_THREAD_DETACH:
		break;
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}
