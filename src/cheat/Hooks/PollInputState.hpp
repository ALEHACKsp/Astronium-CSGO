#ifndef POLLINPUTSTATE_HPP
#define POLLINPUTSTATE_HPP

#include "../Platform/CallingConventions.hpp"

typedef void(THISCALL* PollInputState_t)(const void*, bool);
extern PollInputState_t oPollInputState;

void FASTCALL hkPollInputState(void* ecx, void* edx, bool bIsInGame = false);

#endif