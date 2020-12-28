#include "PollInputState.hpp"

PollInputState_t oPollInputState;
void FASTCALL hkPollInputState(void* ecx, void* edx, bool bIsInGame) {
	return oPollInputState(ecx, bIsInGame);
}