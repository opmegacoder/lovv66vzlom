#include <Windows.h>
#include <iostream>

class memory
{
private:
	DWORD id = 0;
	HANDLE process = 0;
public:
	memory(const char* processName);
	~memory();

	DWORD GetProcessId();
	HANDLE GetProcessHandle();
	
	uintptr_t GetModuleAddress(const char* moduleName);
	template <typename T>
	T Read(uintptr_t address)
	{
		T value;
		ReadProcessMemory(this->process, (LPCVOID)address, &value, sizeof(T), 0);
		return value;
	}
	template <typename T>
	bool Write(uintptr_t address, T value)
	{
		return WriteProcessMemory(this->process, (LPVOID)address, &value, sizeof(T), 0);
	}
}



;