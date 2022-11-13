#define UNICODE 
#define _UNICODE

#include <Windows.h>
#include <CommCtrl.h>
#include <string>
#include <iostream>

#pragma comment(lib, "ComCtl32.lib")

LPCWSTR locator = L"werui.dll";

HINSTANCE hDllInst = LoadLibrary(locator);
HICON hIcon = LoadIcon(hDllInst, MAKEINTRESOURCE(404));


HRESULT CALLBACK DialogCallback(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam, LONG_PTR lpRefData) {
	if (uMsg == TDN_CREATED) {
		SendMessage(hWnd, WM_SETICON, ICON_BIG, NULL);
		SendMessage(hWnd, WM_SETICON, ICON_SMALL, reinterpret_cast<LPARAM>(nullptr, hIcon));
	}
	return 0;
}

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
	TASKDIALOGCONFIG dconf = { 0 };
	dconf.cbSize = sizeof(dconf);
	dconf.dwFlags = TDF_USE_COMMAND_LINKS;
	dconf.hInstance = hInstance;

	dconf.pszMainInstruction = TEXT("tnn1nja.exe is not responding");
	dconf.pszContent = TEXT("If you restart or close the program it will try to recover your information.");
	dconf.pszWindowTitle = TEXT("This Stream");

	const TASKDIALOG_BUTTON buttonsArray[3] = {
		{
			0, TEXT("Be Patient")
		},
		{
			1, TEXT("Complain in Chat")
		},
		{
			2, TEXT("Wait for him to come back annoyedly")
		}
	};

	dconf.pButtons = buttonsArray;
	dconf.cButtons = 3;
	dconf.nDefaultButton = 2;

	dconf.pfCallback = DialogCallback;

	dconf.cxWidth = 50;

	int buttonPressed;
	do {
		buttonPressed = -1;
		TaskDialogIndirect(&dconf, &buttonPressed, NULL, NULL);

		switch (buttonPressed) {
		case 0:
			MessageBox(NULL, TEXT("You pay with your blood"), TEXT("Wrong answer"), MB_OK | MB_ICONEXCLAMATION);
			break;
		case 1:
			MessageBox(NULL, TEXT("You pay with your blood"), TEXT("Wrong answer"), MB_OK | MB_ICONEXCLAMATION);
			break;
		case 2:
			MessageBox(NULL, TEXT("Congratulations! You won!"), TEXT("Congratulations!"), MB_OK | MB_ICONASTERISK);
			break;
		};
	} while (buttonPressed != 2);

	return 0;
}