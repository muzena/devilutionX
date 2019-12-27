#pragma once

#include "devilution.h"

namespace dvl {
BOOL UiSelHeroDelOkDialog(BOOL (*fnremove)(_uiheroinfo *), _uiheroinfo *selectHero, bool isMultiplayer);
void selok_Free();
void selok_Select(int value);
void selok_Esc();

}
