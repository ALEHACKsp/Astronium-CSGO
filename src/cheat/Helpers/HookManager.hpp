#ifndef HOOKMANAGER_HPP
#define HOOKMANAGER_HPP

class HookManager {
public:
	void Init();
	void Shutdown();
private:
	void* HookFunction(const void* pClass, int nIndex, const void* pHookFunction);
};

extern HookManager* g_pHookManager;

#endif