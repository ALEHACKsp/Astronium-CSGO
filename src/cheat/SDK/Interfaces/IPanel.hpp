#ifndef IPANEL_HPP
#define IPANEL_HPP

#include "../Misc/Interface.hpp"

#include "../Misc/VGUI.hpp"

class IPanel : public IBaseInterface {
public:
	const char* IPanel::GetName(VPANEL vguiPanel);
};

extern IPanel* g_pPanel;

#endif