#include "PollInputState.hpp"

#include "../Platform/EntryPoint.hpp"

#include "../SDK/Interfaces/IInputSystem.hpp"

PollInputState_t oPollInputState;
void FASTCALL hkPollInputState(void* ecx, void* edx, bool bIsInGame) {
	if(g_pInputSystem->IsButtonDown(KEY_DELETE)) cv.notify_one();
	
	return oPollInputState(ecx, bIsInGame);
}