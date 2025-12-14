// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "pch.h"
#include <windows.h>
#include <DbgHelp.h>
#pragma comment(lib, "Dbghelp.lib")

LONG WINAPI MyUnhandledExceptionFilter(EXCEPTION_POINTERS* pExceptionInfo)
{
	// 生成 dump 文件
	HANDLE hFile = CreateFile(L"CrashDump.dmp",
		GENERIC_WRITE,
		0,
		nullptr,
		CREATE_ALWAYS,
		FILE_ATTRIBUTE_NORMAL,
		nullptr);

	if (hFile != INVALID_HANDLE_VALUE)
	{
		MINIDUMP_EXCEPTION_INFORMATION dumpInfo;
		dumpInfo.ThreadId = GetCurrentThreadId();
		dumpInfo.ExceptionPointers = pExceptionInfo;
		dumpInfo.ClientPointers = FALSE;

		MINIDUMP_TYPE dumpType = static_cast<MINIDUMP_TYPE>(
			MiniDumpWithFullMemory | MiniDumpWithDataSegs | MiniDumpWithHandleData
			);

		MiniDumpWriteDump(GetCurrentProcess(),
			GetCurrentProcessId(),
			hFile,
			dumpType,
			&dumpInfo,
			nullptr,
			nullptr);

		CloseHandle(hFile);
	}

	return EXCEPTION_EXECUTE_HANDLER;
}

BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		// 注册全局未处理异常处理器
		SetUnhandledExceptionFilter(MyUnhandledExceptionFilter);
		break;
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}


