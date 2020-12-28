#ifndef UTILS_HPP
#define UTILS_HPP

#include "../Platform/CallingConventions.hpp"

#include <cassert>

template <unsigned int nIndex, typename ReturnType, typename... Args>
FORCEINLINE ReturnType CallVirtualFunction(const void* pClass, Args... args) {
	assert(pClass != nullptr);
	assert(nIndex >= 0);

	typedef ReturnType(THISCALL* Fn)(void*, Args...);

	auto function = (*(Fn**)pClass)[nIndex];
	return function(pClass, args...);
}

#endif