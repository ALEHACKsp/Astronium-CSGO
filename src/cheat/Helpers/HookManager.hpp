#ifndef HOOKMANAGER_HPP
#define HOOKMANAGER_HPP

class HookManager {
public:
	void Init();
	void Shutdown();
private:
	void* HookFunction(void* pClass, int nIndex, void* pHookFunction);
};

extern HookManager* g_pHookManager;

#endif