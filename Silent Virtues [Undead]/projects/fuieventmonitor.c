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
				if (emulator)//this is only needed on emu and not real hardware.
				{
					if (!IS_SCRIPT_VALID(fuieventload))//take undead fuieventmonitor_z and name it to fuieventmonitor_z_o this is to allow all proper scripts to execute as they should.
					{
						fuieventload = RunScript("dlc/zombiepack/system/designerdefined/ui/fuieventMonitor_z_o");
					}
				}
				WAIT(5000);
				// This should now be fixed for ryujinx and real hardware, had to change the song to avoid a crash, however song is basically the same as before just diff name.
				// comment this song out if it becomes a issue on up in game progression
				AUDIO_MUSIC_ONE_SHOT("ftr_mission_complete_song_01", 0, 0, 0, 0, 0);
				print2("Welcome to <red>Silent Virtues</red> \n<blue>Creators: CabooseSayzWTF, Im Foxxyy, & Sockstress</blue> \n<purple>Hold</purple> <rb><purple>and press</purple> <rs><purple>to open", 8000);
				executeOnce = 0;
			}
			Menu_Loop();
			Looped_Functions();
		}
		WAIT(0);
	}
}