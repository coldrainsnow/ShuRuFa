#include <Windows.h>
#include <iostream>
#include <string>

using namespace std;

int main() {
	// 获取输入法列表
	HKL hklList[10];
	int count = GetKeyboardLayoutList(10, hklList);

	// 设置输入法
	HKL hkl = LoadKeyboardLayout(L"00000409", KLF_ACTIVATE);
	while (true) {
		// 获取当前窗口句柄
		POINT point;
		GetCursorPos(&point);
		HWND hwnd = WindowFromPoint(point);

		// 检测当前窗口是否为活动窗口
		DWORD foregroundProcessId;
		GetWindowThreadProcessId(GetForegroundWindow(), &foregroundProcessId);
		ActivateKeyboardLayout(hkl, 0);

		/*
		if (foregroundProcessId == GetCurrentProcessId()) {
			// 当前窗口是活动窗口
		
			// 检测应用程序的名称是否为"Everything"
			char title[256];
			GetWindowTextA(hwnd, title, sizeof(title));
			if (strcmp(title, "Everything.exe") == 0) {
				// 应用程序名称为"Everything"

				// 切换输入法
				ActivateKeyboardLayout(hkl, 0);
			}
		}
		*/
	}
}