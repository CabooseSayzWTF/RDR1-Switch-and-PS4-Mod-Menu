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
				AUDIO_MUSIC_ONE_SHOT("mex_mission_complete_song_01", 0, 0, 0, 0, 0);
				print2("<purple>Hold</purple> <rb><purple>and press</purple> <dpadleft><purple>to open", 8000);
				executeOnce = 0;
			}
			Menu_Loop();
			Looped_Functions();
		}
		WAIT(0);
	}
}