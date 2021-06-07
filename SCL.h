#pragma once
#include<iostream>
#include<Windows.h>

HWND hwnd;
DWORD procID;
DWORD vacID;
HANDLE handle;

std::string print(std::string text)
{
	std::cout << text << std::endl;
	return text;
}

const char* read()
{
	std::string msg;
	std::cin >> msg;
	return 0;
}

void StartProcess(const char* pPath)
{
	system(pPath);
}

bool AttachToProcess(const char* wName)
{
	hwnd = FindWindowA(NULL, wName);
	GetWindowThreadProcessId(hwnd, &procID);
	handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, procID);
	return true;
}

void WriteMemory(int memAdress, int newValue)
{
	WriteProcessMemory(handle, (LPVOID)memAdress, &newValue, sizeof(newValue), 0);
}

void ReadMemory(int memAdress)
{
	ReadProcessMemory(handle, (LPVOID)memAdress, &memAdress, sizeof(memAdress), 0);
}

void Detach()
{
	Sleep(2000);
	exit(-1);
}

void AC_PROOF_MODE(std::string mode)
{
	HWND vacProc = FindWindowA(NULL, "VAC.exe");
	if (mode == "vac")
	{
		HANDLE vacHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, vacID);
		GetWindowThreadProcessId(vacProc, &vacID);
	}
	else
	{
		std::cout << "Bypass not Supported yet" << std::endl;
	}
}
