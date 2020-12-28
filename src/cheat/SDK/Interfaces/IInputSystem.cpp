#include "IInputSystem.hpp"

#include "../../Helpers/Utils.hpp"

bool IInputSystem::IsButtonDown(ButtonCode_t code) {
	return CallVirtualFunction<15, bool>(this, code);
}

IInputSystem* g_pInputSystem;