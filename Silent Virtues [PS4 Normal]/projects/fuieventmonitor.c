#include "..\include\types.h"
#include "..\include\constants.h"
#include "..\include\intrinsics.h"
#include "..\include\natives.h"
#include "..\include\common.h"
#include "mods.h"
#include "menu.h"
bool executeOnce = 1;
bool emulator = 1;
int fuieventload;

void main()
{
	//ADD_PERSISTENT_SCRIPT(GET_THIS_SCRIPT_ID());
	while (true)
	{
		if (!UI_ISACTIVE("LoadingScreen"))
		{
			if (executeOnce)
			{
				if (emulator)
				{
					if (!IS_SCRIPT_VALID(fuieventload))//take original fuieventmonitor and name it to fuieventmonitor_o this is to allow all proper scripts to execute as they should.
					{
						fuieventload = RunScript("scripting/DesignerDefined/UI/FuiEventMonitor_O");
					}
				}
				WAIT(5000);
				AUDIO_MUSIC_ONE_SHOT("mex_mission_complete_song_01", 0, 0, 0, 0, 0);
				print2("Welcome to <red>Silent Virtues</red> \n<blue>Creators: CabooseSayzWTF, Im Foxxyy, & Sockstress</blue> \n<purple>Hold</purple> <rb><purple>and press</purple> <rs><purple>to open", 8000);
				executeOnce = 0;
			}
			Menu_Loop();
			Looped_Functions();
		}
		WAIT(0);
	}
}