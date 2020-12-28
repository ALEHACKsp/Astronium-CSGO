#ifndef IINPUTSYSTEM_HPP
#define IINPUTSYSTEM_HPP

#include "../Classes/IAppSystem.hpp"

#include "../Misc/ButtonCode.hpp"

class IInputSystem : public IAppSystem {
public:
	bool IsButtonDown(ButtonCode_t code);
};

extern IInputSystem* g_pInputSystem;

#endif