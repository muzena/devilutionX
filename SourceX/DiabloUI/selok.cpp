#include "selok.h"

#include "devilution.h"
#include "DiabloUI/diabloui.h"
#include "DiabloUI/text.h"

namespace dvl {

namespace {

char dialogText[256];

} // namespace

int selok_endMenu;
char selok_title[32];

void selok_Free()
{
	ArtBackground.Unload();
}

void selok_Select(int value)
{
	selok_endMenu = true;
}

void selok_Esc()
{
	selok_endMenu = true;
}

UiListItem SELOK_DIALOG_ITEMS[] = {
	{ "OK", 0 }
};

UiItem SELOK_DIALOG[] = {
	MAINMENU_BACKGROUND,
	MAINMENU_LOGO,
	UiArtText(selok_title, { 24, 161, 590, 35 }, UIS_CENTER | UIS_BIG),
	UiText(dialogText, { 140, 210, 400, 168 }, UIS_MED),
	UiList(SELOK_DIALOG_ITEMS, 230, 390, 180, 35, UIS_CENTER | UIS_BIG | UIS_GOLD)
};
UiArtText *SELOK_DIALOG_CONFIRMATION_MESSAGE = &SELOK_DIALOG[3].art_text;

UiItem SPAWNERR_DIALOG[] = {
	MAINMENU_BACKGROUND,
	MAINMENU_LOGO,
	UiText("The Rogue and Sorcerer are only available in the full retail version of Diablo. For ordering information visit https://www.gog.com/game/diablo.", { 140, 199, 400, 177 }),
	UiArtTextButton("OK", &selok_Esc, { 230, 407, 180, 43 }),
};

BOOL UiSelHeroDelOkDialog(bool isMultiplayer)
{
	LoadBackgroundArt("ui_art\\black.pcx");

	if (isMultiplayer) {
		strcpy(selok_title, "New Multi Player Hero");
	} else {
		strcpy(selok_title, "New Single Player Hero");
	}

	sprintf(dialogText, "Hi!");
	WordWrapArtStr(dialogText, SELOK_DIALOG_CONFIRMATION_MESSAGE->rect.w);

	UiInitList(0, 1, NULL, selok_Select, selok_Esc, SELOK_DIALOG, size(SELOK_DIALOG), true, NULL);

	selok_endMenu = false;
	while (!selok_endMenu) {
		UiRenderItems(SELOK_DIALOG, size(SELOK_DIALOG));
		UiPollAndRender();
	}

	BlackPalette();

	selok_Free();
	return true;
}
}
