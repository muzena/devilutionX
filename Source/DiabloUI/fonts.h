#pragma once

#include <SDL_ttf.h>
#include <cstdint>

#include "DiabloUI/art.h"

namespace devilution {

enum _artFontTables : uint8_t {
	AFT_SMALL,
	AFT_MED,
	AFT_BIG,
	AFT_HUGE,
};

enum _artFontColors : uint8_t {
	AFC_SILVER,
	AFC_GOLD,
};

extern TTF_Font *font;
extern BYTE *FontTables[4];
extern Art ArtFonts[4][2];

void LoadArtFonts();
void UnloadArtFonts();

void LoadTtfFont();
void UnloadTtfFont();
void FontsCleanup();

} // namespace devilution
