#include "IPanel.hpp"

#include "../../Helpers/Utils.hpp"

const char* IPanel::GetName(VPANEL vguiPanel) {
	return CallVirtualFunction<36, const char*>(this, vguiPanel);
}

IPanel* g_pPanel;