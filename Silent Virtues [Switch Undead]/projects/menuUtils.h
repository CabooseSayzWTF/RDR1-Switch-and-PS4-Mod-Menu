int optionCount;
int currentOption;
int maxOptions = 8;
int submenuLevel;
int lastSubmenu[20];
int lastOption[20];
int submenu = 0;
int value;
int ModReset = -1;
bool btnClick;
bool rightPress;
bool leftPress;
bool MenuOpen;
bool backPress;
bool optionPress;
char globalMenuBuffer[255];
char menuItemBuffers[8][37];
int pedname = 0;
int modelname = 0;
int vehintz = 1177;
int vehintz2 = 0;
int todg = 0;
int austel = 0;
int westeli = 0;
int mextel = 0;
int hidint = 0;
int outmapz = 0;
int weathint = 0;
int mspz = 0;
int wepzint = 0;
extern int PedWepz = 0;
int TestOne = 1;
int TestTwo = 1;
//
int famit = 0;
int monit = 0;
int muit = 0;
int yowtf3;
int yowtf4;
int menuoutsound = 0;
bool EnableThat = 1;//hacky left right switch stuff
void DrawMenuHeader(char* header)
{
	strcpy(globalMenuBuffer, "", 1);
	stradd_s(globalMenuBuffer, "<red>");
	stradd_s(globalMenuBuffer, header);
	stradd_s(globalMenuBuffer, "\n");
}

void DrawMenuItem(const char* text)
{
	optionCount++;
	if (currentOption == optionCount)
		stradd_s(globalMenuBuffer, "<purple>");
	if (currentOption <= maxOptions && optionCount <= maxOptions && optionCount != currentOption)
		stradd_s(globalMenuBuffer, "<blue>");
	else if ((optionCount > (currentOption - maxOptions)) && optionCount <= currentOption && optionCount != currentOption)
		stradd_s(globalMenuBuffer, "<blue>");

	if (currentOption == optionCount)
	{
		stradd_s(globalMenuBuffer, ">");
	}
	stradd_s(globalMenuBuffer, text);
	stradd_s(globalMenuBuffer, "\n");
}

bool GetButton(eButton input)
{
	return IS_BUTTON_PRESSED(1, input, 4, 4);
}


bool GetButtonDown(eButton input)
{
	return IS_BUTTON_DOWN(1, input, 4, 4);
}

int getOption()
{
	if (optionPress)
		return currentOption;
	else return 0;
}

void changeSubmenu(int newSubmenu)
{
	lastSubmenu[submenuLevel] = submenu;
	lastOption[submenuLevel] = currentOption;
	currentOption = 1;
	submenu = newSubmenu;
	submenuLevel++;
}

void add_title(char *header)
{
	DrawMenuHeader(header);
}

void add_option(const char *text)
{
	DrawMenuItem(text);
}

void DrawBoolOption(const char *option, bool BOOL)
{
	if (BOOL)
	{
		optionCount++;
		if (currentOption == optionCount)
			stradd_s(globalMenuBuffer, "<purple>");
		if (currentOption <= maxOptions && optionCount <= maxOptions && optionCount != currentOption)
			stradd_s(globalMenuBuffer, "<blue>");
		else if ((optionCount > (currentOption - maxOptions)) && optionCount <= currentOption && optionCount != currentOption)
			stradd_s(globalMenuBuffer, "<blue>");
		if (currentOption == optionCount)
		{
			stradd_s(globalMenuBuffer, ">");
		}
		stradd_s(globalMenuBuffer, option);
		stradd_s(globalMenuBuffer, ": ");
		stradd_s(globalMenuBuffer, "<green>");
		stradd_s(globalMenuBuffer, "ON");
		stradd_s(globalMenuBuffer, "\n");
	}
	else
	{
		optionCount++;
		if (currentOption == optionCount)
			stradd_s(globalMenuBuffer, "<purple>");
		if (currentOption <= maxOptions && optionCount <= maxOptions && optionCount != currentOption)
			stradd_s(globalMenuBuffer, "<blue>");
		else if ((optionCount > (currentOption - maxOptions)) && optionCount <= currentOption && optionCount != currentOption)
			stradd_s(globalMenuBuffer, "<blue>");
		if (currentOption == optionCount)
		{
			stradd_s(globalMenuBuffer, ">");
		}
		stradd_s(globalMenuBuffer, option);
		stradd_s(globalMenuBuffer, ": ");
		stradd_s(globalMenuBuffer, "<red>");
		stradd_s(globalMenuBuffer, "OFF");
		stradd_s(globalMenuBuffer, "\n");
	}
}

void DrawSubMenuOption(const char *option, int SubMenu)
{
	add_option(option);
	if (currentOption == optionCount)
	{
		if (optionPress) changeSubmenu(SubMenu);
	}
}

void DisplayMenu()
{
	HUD_CLEAR_HELP_QUEUE();
	PRINT_HELP_B(globalMenuBuffer, 1, false, 1, 2, 1, "", "");
}

void previous_option()
{
	if (GetButton(DPAD_UP))
	{
		currentOption--;
		if (currentOption < 1) currentOption = optionCount;
		PLAY_SOUND_FRONTEND("HUD_MENU_NAV_UP_MASTER");
	}
}

void next_option()
{
	if (GetButton(DPAD_DOWN))
	{
		currentOption++;
		if (currentOption > optionCount) currentOption = 1;
		PLAY_SOUND_FRONTEND("HUD_MENU_NAV_DOWN_MASTER");
	}
}

void MenuSounds()
{
	optionPress = GetButton(BUTTON_A);
	if (optionPress)
	{
		PLAY_SOUND_FRONTEND("HUD_MENU_SELECT_MASTER");
	}
	if (GetButton(BUTTON_O))
	{
		PLAY_SOUND_FRONTEND("HUD_MENU_BACK_MASTER");
	}
}

void 
Hook()
{
	if (EnableThat)
	{
		if (GetButtonDown(BUTTON_R1) && (GetButton(BUTTON_R3)))
		{
			if (MenuOpen == true)
			{
				print2("Menu Already Open", 2000);
			}
			if (MenuOpen == false)
			{
				menuoutsound = 1;
				submenu = Main_Menu;
				submenuLevel = 1;
				currentOption = 1;
				MenuOpen = true;
				PLAY_SOUND_FRONTEND("HUD_MP_UNLOCK_MASTER");
			}
		}
		if (GetButton(BUTTON_O))
		{
			if (submenu == Main_Menu)
			{
				SET_PLAYER_CONTROL(0, true, false, false);
				submenu = Closed;
				submenuLevel = 0;
				currentOption = 0;
				MenuOpen = false;
				HUD_CLEAR_HELP_QUEUE();
				if (DECOR_CHECK_EXIST(GET_PLAYER_ACTOR(0), "DISABLE_HORSE_WHISTLE"))
				{
					DECOR_REMOVE(GET_PLAYER_ACTOR(0), "DISABLE_HORSE_WHISTLE");
				}
				if (menuoutsound == 1)
				{
					PLAY_SOUND_FRONTEND("DEAD_EYE_START_MASTER");
					menuoutsound = 0;
				}
			}
			else
			{
				submenu = lastSubmenu[submenuLevel - 1];
				currentOption = lastOption[submenuLevel - 1];
				submenuLevel--;
			}
		}
		if (MenuOpen)
		{
			int framesPerSecond = (1.0f / GET_LAST_FRAME_TIME());
			vector3 yoco;
			DisplayMenu();
			previous_option();
			next_option();
			MenuSounds();
			DECOR_SET_BOOL(GET_PLAYER_ACTOR(0), "DISABLE_HORSE_WHISTLE", 1);
			CANCEL_CURRENTLY_PLAYING_AMBIENT_SPEECH(GET_PLAYER_ACTOR(0));
			if (!IS_SCRIPT_USE_CONTEXT_VALID(yowtf3))
			{
				//fps and health
				yowtf3 = ADD_SCRIPT_USE_CONTEXT("Generic_Dbuffer128_2", 0, 11, 0, 0, 0, 0, -1, 0);
			}
			if (!IS_SCRIPT_USE_CONTEXT_VALID(yowtf4))
			{
				//your position in the world
				yowtf4 = ADD_SCRIPT_USE_CONTEXT("Generic_Dbuffer128_1", 0, 8, 0, 0, 0, 0, -1, 0);
			}
			//self pos when menu open
			GET_POSITION(GET_PLAYER_ACTOR(0), &yoco);
			char Temp4[255];
			stradd_s(Temp4, "<purple>Your POS:<purple> ");
			stradd_s(Temp4, "<red>X</red>:");
			stradd_s(Temp4, _FLOAT_TO_STRING(yoco.x, 1, 1));
			stradd_s(Temp4, " <red>Y</red>:");
			stradd_s(Temp4, _FLOAT_TO_STRING(yoco.y, 1, 1));
			stradd_s(Temp4, " <red>Z</red>:");
			stradd_s(Temp4, _FLOAT_TO_STRING(yoco.z, 1, 1));
			stradd_s(Temp4, " <red>H</red>:");
			stradd_s(Temp4, _FLOAT_TO_STRING(GET_HEADING(GET_PLAYER_ACTOR(0)), 1, 1));
			UI_SET_STRING("Generic_Dbuffer128_1", Temp4);
			//fps info when menu open
			char Temp[255];
			stradd_s(Temp, "<green>FPS</green>:");
			stradd_s(Temp, INT_TO_STRING(framesPerSecond));
			stradd_s(Temp, " <blue>HP</blue>:");
			stradd_s(Temp, _FLOAT_TO_STRING(GET_ACTOR_HEALTH(GET_PLAYER_ACTOR(0)), 1, 1));
			UI_SET_STRING("Generic_Dbuffer128_2", Temp);
		}
		optionPress = GetButton(BUTTON_A);
	}
}


unsafe float GetStatArrayValue(int globalIndex)
{
	__getFrame(0);
	__getGlobalP(54086);
	__getArray(1);
	return __popF();
}

void resetVars()
{
	optionPress = false;
	//leftPress = false;
	//rightPress = false;

	char buf[sizeof(globalMenuBuffer)];
	stradd_s(globalMenuBuffer, buf);
	if (MenuOpen == false)
	{
		if (IS_SCRIPT_USE_CONTEXT_VALID(yowtf3))
		{
			RELEASE_SCRIPT_USE_CONTEXT(yowtf3);
		}
		if (IS_SCRIPT_USE_CONTEXT_VALID(yowtf4))
		{
			RELEASE_SCRIPT_USE_CONTEXT(yowtf4);
		}
	}
}