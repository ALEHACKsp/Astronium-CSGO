#ifndef INTERFACE_HPP
#define INTERFACE_HPP

typedef void* (*CreateInterfaceFn)(const char* pName, int* pReturnCode);
typedef void* (*InstantiateInterfaceFn)();

class InterfaceReg {
public:
	InstantiateInterfaceFn m_CreateFn;
	const char* m_pName;

	InterfaceReg* m_pNext;
	static InterfaceReg* s_pInterfaceRegs;
};

class IBaseInterface {
public:
	virtual	~IBaseInterface() {}
};

#endif 