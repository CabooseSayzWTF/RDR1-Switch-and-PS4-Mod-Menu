/***********************************************************************
* FILENAME :	natives32.h					START DATE :	10 Sept 16
*
* DESCRIPTION :
*		Native functions to be used with all RDR targets and platforms of SC-CL.
*
* NOTES :
*		This file is part of SC-CL's include library.
*
* LICENSE :
*
*		Copyright 2016 SC-CL
*
*		Redistribution and use in source and binary forms, with or without
*		modification, are permitted provided that the following conditions are met:
*
*		* Redistributions of source code must retain the above copyright
*		notice, this list of conditions and the following disclaimer.
*
*		* Redistributions in binary form must reproduce the above copyright
*		notice, this list of conditions and the following disclaimer in the
*		documentation and/or other materials provided with the distribution.
*
*		* Neither SC-CL nor its contributors may be used to endorse or promote products
*		derived from this software without specific prior written permission.
*
*		* Redistribution of this software in source or binary forms shall be free
*		of all charges or fees to the recipient of this software.
*
*		THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
*		ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
*		WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
*		DISCLAIMED. IN NO EVENT SHALL SC-CL BE LIABLE FOR ANY
*		DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
*		(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
*		LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
*		ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
*		(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
*		SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
* AUTHORS :
*		Rocko Tompkins
*		Nathan James
* 
* 
* NATIVES UPDATED : 2020 - 2023
*		Panah (Sockstress)
*		ImFoxxyyy
*		Rouletteboi
*		CabooseSayzWTF
* 		xTheDevilRazedMe
*/

#pragma once
//Idk if this is needed or not, for switch this doesn't seem needed
#include "types.h"
#include "constants.h"

//Fix for intellisense nonsense
#ifndef _MSC_VER
#define _native __attribute((native))
#define _native32(hash) __attribute((native(hash)))
#define l ;
#else
#define _native
#define _native32(hash)
#define l {};
#endif

#define SIN SIN_DEGREE
#define COS COS_DEGREE
#define TAN TAN_DEGREE
#define ATAN ATAN_DEGREE
#define ATAN2 ATAN2_DEGREE

//////////////////////////////////
//System
/////////////////////////////////
extern _native void WAIT(int ms)l
extern _native void WAITUNWARPED(int ms)l
extern _native void WAITUNPAUSED(int ms)l
extern _native int START_NEW_SCRIPT(const char* scriptName, int stackSize)l
extern _native int START_NEW_SCRIPT_WITH_ARGS(const char* scriptName, int stackSize, void* args, int argCount)l
extern _native void SETTIMERA(int value)l
extern _native float TIMESTEP()l
extern _native void PRINTSTRING(char* str)l
extern _native void PRINTFLOAT(float value)l
extern _native void PRINTINT(int value)l
extern _native void PRINTNL()l
extern _native void PRINTVECTOR(float x, float y, float z)l
extern _native float SQRT(float value)l
extern _native float POW(float base, float exponent)l
extern _native float EXP(float value)l
extern _native float VMAG(vector3 vector)l//or x, y, z
extern _native float VDIST(float x1, float y1, float z1, float x2, float y2, float z2)l
extern _native float VDIST2(float x1, float y1, float z1, float x2, float y2, float z2)l
extern _native int SHIFT_LEFT(int value, int bitShift)l
extern _native int SHIFT_RIGHT(int value, int bitShift)l
extern _native int FLOOR(float value)l
extern _native int CEIL(float value)l
extern _native int ROUND(float value)l
extern _native int TO_FLOAT(int value)l//float
extern _native void SNAPSHOT_GLOBALS()l
extern _native const char* GET_LATEST_CONSOLE_COMMAND()l
extern _native void RESET_LATEST_CONSOLE_COMMAND()l
extern _native const char* GET_CONSOLE_COMMAND_TOKEN(int pram0)l//idk there was a param here
extern _native int GET_NUM_CONSOLE_COMMAND_TOKENS()l
//////////////////////////////////
//Ambience Audio
/////////////////////////////////
extern _native void AMBIENCE_AUDIO_ENTITY_UPDATE_TERRITORY(const char* territory)l
extern _native void AMBIENCE_AUDIO_ENTITY_UPDATE_LOCATION(const char* territory, const char* p1)l
extern _native void AMBIENCE_AUDIO_VALIDATE_REGION(const char* p0, const char* p1)l
//////////////////////////////////
//Dynamic Mixer
/////////////////////////////////
extern _native void DYNAMICMIXER_TRIGGERSTATE(const char* p0)l
extern _native void DYNAMICMIXER_TRIGGERSTATE_PERSISTENT(const char* p0, int pram1)l
extern _native void DYNAMICMIXER_DETRIGGERSTATE(int pram0, bool pram1)l
extern _native void UNK_0xADCC16A2()l//_DYNAMICMIXER_2 what roulette had
//////////////////////////////////
//Ped Audio Manager
/////////////////////////////////
extern _native bool CAN_ACTOR_ENUM_PLAY_SPEECH_CONTEXT(Actor actor, int context)l
extern _native void REGISTER_ACTOR_SPEECH_CONTEXT(int pram0, const char* pram1, int pram2, int pram3, bool pram4, int pram5, int pram6)l
extern _native void FINISH_REGISTERING_ACTOR_SPEECH_CONTEXTS()l
extern _native void REGISTER_NUM_SPEECH_CONTEXTS(int count)l
extern _native void REGISTER_NUM_CONTEXT_TYPES()l
//////////////////////////////////
//Audio
/////////////////////////////////
extern _native bool NEW_SCRIPTED_CONVERSATION()l
extern _native void ADD_LINE_TO_CONVERSATION(int pram0, const char* p1, const char* p2, int pram3, int pram4, bool pram5, int pram6, int pram7)l
extern _native void ADD_NEW_CONVERSATION_SPEAKER(int pedIndex, int actor, const char* p2)l
extern _native void ADD_NEW_FRONTEND_CONVERSATION_SPEAKER(int speakers, const char* p1)l
extern _native void START_SCRIPT_CONVERSATION(bool p0, bool p1)l
extern _native bool IS_SCRIPTED_CONVERSATION_ONGOING()l
extern _native void PAUSE_SCRIPTED_CONVERSATION(bool p0, bool p1)l//(int p0, int p1, int p2)
extern _native void RESTART_SCRIPTED_CONVERSATION()l
extern _native int ABORT_SCRIPTED_CONVERSATION(bool p0)l
//SET_MAX_SCRIPTED_CONVERSATION_DISTANCE 0x1CFC44F9
extern _native void RESET_MAX_SCRIPTED_CONVERSATION_DISTANCE()l
extern _native int HAS_SCRIPTED_CONVERSATION_PLAYED_RECENTLY()l
extern _native void UNREGISTER_SCRIPT_WITH_AUDIO()l
extern _native int REQUEST_MISSION_AUDIO_BANK(const char* pram0)l
extern _native void MISSION_AUDIO_BANK_NO_LONGER_NEEDED()l
extern _native int AMBIENT_AUDIO_BANK_NO_LONGER_NEEDED()l
extern _native int GET_SOUND_ID()l
extern _native void RELEASE_SOUND_ID(int pram0)l
extern _native bool IS_SOUND_ID_VALID(int sound)l
extern _native void PLAY_SOUND(int pram0)l
//PLAY_SOUND_INIT_PARAMS 0x9DA2503
extern _native int PLAY_SOUND_INIT_PARAMS_PERSISTENT(int p0, int p1, int p2)l
extern _native void PLAY_SOUND_FRONTEND(const char* soundName)l
extern _native void PLAY_SOUND_FRONTEND_INITPARAMS(int pram0, int pram1)l
extern _native void PLAY_SOUND_FRONTEND_PERSISTENT(int pram0, int pram1)l
extern _native void PLAY_SOUND_FROM_POSITION(const char* SoundName, vector3 Position)l
extern _native int PLAY_SOUND_FROM_POSITION_INITPARAMS(int p0, float p1, float p2, float p3, int p4, int p5, int p6) l
extern _native void PLAY_SOUND_FROM_POSITION_PERSISTENT(int pram0, int pram1, int pram2, int pram3, int pram4)l
extern _native void PLAY_WALLA_SOUND_FROM_POSITION_PERSISTENT(int pram0, int pram1, int pram2, int pram3, int pram4)l
extern _native int PLAY_SOUND_FROM_ACTOR(int pram0, int pram1, int pram2)l
extern _native int PLAY_WALLA_SOUND_FROM_ACTOR(int pram0, int pram1, int pram2)l
extern _native int PLAY_SOUND_FROM_OBJECT(Object object, const char* sound)l
extern _native int AUDIO_SET_VEHICLE_DAMAGED(int pram0)l
extern _native void STOP_SOUND(int pram0)l
extern _native bool HAS_SOUND_FINISHED(int pram0)l
extern _native void AUDIO_ATTACH_MICROPHONE_TO_ACTOR(int pram0)l
extern _native void AUDIO_SET_MISSION_NAME_FOR_JOURNAL(int pram0)l
extern _native void AUDIO_CLEAR_MISSION_NAME_FOR_JOURNAL()l
extern _native void AUDIO_RESET_SPEECH_HISTORY()l
extern _native void AUDIO_RESET_SCRIPTED_SPEECH_HISTORY()l
extern _native32(0x3DFD83DE) bool _HAS_SCRIPTED_CONVERSATION_PLAYED_ALREADY(int pram0)l
extern _native32(0xDD0320CB) void _CLEAR_SCRIPTED_CONVERSATION_HISTORY()l
extern _native32(0x31BAF169) void _SAY_AMBIENT_SPEECH(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5, int pram6, int pram7, int pram8, int pram9)l
extern _native void SAY_SINGLE_LINE_STRING(Actor actor, const char* name, int pram2, int pram3, int pram4, int pram5, int pram6, int pram7)l//_SAY_SINGLE_LINE_SPEECH 0xBA734A15
extern _native void SAY_SINGLE_LINE_STRING_WITH_REPLY(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5, int pram6, int pram7)l
extern _native32(0x0871084C) void _SAY_AMBIENT_SPEECH_OVER_PAIN(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5, int pram6, int pram7, int pram8)l
extern _native32(0x12D077CA) void _SAY_SINGLE_LINE_SPEECH_OVER_PAIN(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5)l
extern _native void SAY_SINGLE_LINE_STRING_WITH_REPLY_OVER_PAIN(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5, int pram6, int pram7)l
extern _native32(0xFDA41D54) void _SAY_SINGLE_LINE_SPEECH_THROUGH_BLOCK(int p0, int p1, int p2, int p3)l
extern _native void SAY_SINGLE_LINE_STRING_WITH_BACKUPS(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5, int pram6, int pram7)l
extern _native void SAY_SINGLE_LINE_SCRIPTED(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5, int pram6, int pram7)l
extern _native int SAY_SINGLE_LINE_STRING_BEAT(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5, int pram6, int pram7, int pram8, int pram9)l
extern _native32(0x3F226995) int _SAY_SINGLE_LINE_SPEECH_SCRIPTED_INTERRUPT(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5, int pram6, int pram7, int pram8, int pram9, int pram10, int pram11, int pram12)l
extern _native void AUDIO_PLAY_VOCAL_EFFECT(int pram0, int pram1, int pram2)l
extern _native void AUDIO_PLAY_VOCAL_EFFECT_EVEN_IF_DEAD(int pram0, int pram1)l
extern _native void AUDIO_PLAY_PAIN(int pram0, int pram1)l
extern _native void AUDIO_TRIGGER_PLAYER_KILLED_EVERYONE_SPEECH(int pram0, int pram1, int pram2)l
extern _native void TREAT_AMBIENT_SPEECH_AS_SCRIPTED(int pram0, int pram1)l
extern _native void SET_AMBIENT_VOICE_NAME(int pram0, int pram1)l
extern _native void CLEAR_ALTERNATE_SPEECH_CONTEXT_FOR_PAIN(int pram0)l
extern _native void CANCEL_CURRENTLY_PLAYING_AMBIENT_SPEECH(Actor actor)l
extern _native bool IS_AMBIENT_SPEECH_PLAYING(Actor actor)l
extern _native bool IS_SCRIPTED_SPEECH_PLAYING(int pram0)l
extern _native bool IS_ANY_SPEECH_PLAYING(int pram0)l
extern _native void AUDIO_STOP_PAIN(int pram0)l
extern _native void AUDIO_PLAY_PLAYER_HOGTIE_LINE(Actor actor)l
extern _native void AUDIO_TRIGGER_PLAYER_LOOTING_MALE_SPEECH()l
extern _native void AUDIO_TRIGGER_PLAYER_LOOTING_FEMALE_SPEECH()l
extern _native int AUDIO_TRIGGER_PLAYER_LOOTING_FEMALE_ZOMBIE_SPEECH(int pram0, int pram1, int pram2)l
extern _native int AUDIO_TRIGGER_PLAYER_LOOTING_MALE_ZOMBIE_SPEECH(int pram0, int pram1, int pram2)l
extern _native void AUDIO_SHUT_OFF_WALLA()l
extern _native void AUDIO_TURN_ON_WALLA()l
extern _native void SET_LOCAL_PLAYER_VOICE(int pram0)l
extern _native void SET_LOCAL_PLAYER_PAIN_VOICE(int pram0)l
extern _native int AUDIO_TURN_OFF_PAIN_VOCALS(int pram0)l
extern _native void AUDIO_TURN_ON_PAIN_VOCALS(bool enable)l
extern _native32(0xE4D418D1) int _AUDIO_TURN_OFF_VOCAL_EFFECTS(int pram0)l
extern _native void AUDIO_SET_PLAYER_MOOD(int pram0, int pram1)l
extern _native void AUDIO_ALLOW_PREDUEL_SPEECH(int pram0)l
extern _native void AUDIO_DISALLOW_PREDUEL_SPEECH(int pram0)l
extern _native void AUDIO_CLEAR_PLAYER_DISABLED_CONTEXT_LIST()l
extern _native void AUDIO_ADD_TO_PLAYER_DISABLED_CONTEXT_LIST(char* unk)l
extern _native void AUDIO_DISABLE_PLAYER_TAUNTS()l
extern _native void AUDIO_ENABLE_PLAYER_TAUNTS()l
extern _native void AUDIO_INIT_CAUCASIAN_ARMY_AE_RANGE(int pram0, int pram1)l
extern _native void AUDIO_INIT_MEXICAN_ARMY_AE_RANGE(int pram0, int pram1)l
extern _native void AUDIO_INIT_MISSION_CHARACTER_AE_RANGE(int pram0, int pram1)l
extern _native void AUDIO_INIT_RCM_CHARACTER_AE_RANGE(int pram0, int pram1)l
extern _native void AUDIO_INIT_FAC_INVALID_VALUE(int pram0)l
extern _native void AUDIO_INIT_FAC_CATTLE_RUSTLER_VALUE(int pram0)l
extern _native void AUDIO_INIT_FAC_DRUNKNDIRTY_VALUE(int pram0)l
extern _native void AUDIO_INIT_FAC_GENERIC_CRIMINAL_VALUE(int pram0)l
extern _native void AUDIO_INIT_FAC_INDIAN_LAW_ENFORCEMENT_VALUE(int pram0)l
extern _native void AUDIO_INIT_FAC_INDIAN_RAIDER_VALUE(int pram0)l
extern _native void AUDIO_INIT_FAC_LAW_ENFORCEMENT_VALUE(int pram0)l
extern _native void AUDIO_INIT_FAC_MEXICAN_BANDITO_VALUE(int pram0)l
extern _native void AUDIO_INIT_FAC_MEXICAN_LAW_ENFORCEMENT_VALUE(int pram0)l
extern _native void AUDIO_INIT_FAC_MEXICAN_REBEL_VALUE(int pram0)l
extern _native void AUDIO_INIT_FAC_MEXICAN_SOLDIER_VALUE(int pram0)l
extern _native void AUDIO_INIT_FAC_SMUGGLERS_VALUE(int pram0)l
extern _native32(0x5FCF3B85) void _AUDIO_INIT_FAC_US_LAW_ENFORCEMENT_VALUE(int pram0)l
extern _native void AUDIO_INIT_ZOMBIE_BRUISER_AE_RANGE(int pram0, int pram1)l
extern _native void AUDIO_INIT_ZOMBIE_FAST_AE_RANGE(int pram0, int pram1)l
extern _native void AUDIO_INIT_ZOMBIE_TOXIC_AE_RANGE(int pram0, int pram1)l
extern _native void AUDIO_INIT_ZOMBIE_MP_PLAYER_AE_RANGE(int pram0, int pram1)l
extern _native void AUDIO_INIT_ZOMBIE_MP_FEMALE_VALUE(int pram0)l
extern _native void AUDIO_INIT_FAC_ZOMBIE_VALUE(int pram0)l
extern _native void AUDIO_SET_CURRENT_AREA_IS_UNDER_ZOMBIE_ATTACK(int pram0)l
extern _native void AUDIO_INIT_ZOMBIE_ZONE()l
extern _native void AUDIO_INIT_ZOMBIE_PACK_INFO()l
extern _native void AUDIO_INIT_NUN_AE_RANGE(int pram0, int pram1, int pram2, int pram3)l
extern _native32(0x8A6D03BE) void _AUDIO_SET_MAX_FOOTSTEPS_UPDATE(int pram0)l
extern _native void UNK_0x90DD37E7(int pram0, int pram1, int pram2)l
extern _native void STOP_PED_SPEAKING(int pram0, int pram1)l
extern _native void AUDIO_MISSION_INIT()l
extern _native void AUDIO_MISSION_RELEASE()l
extern _native void AUDIO_PLAY_DISTANT_THUNDER()l
extern _native void AUDIO_MUSIC_FORCE_TRACK(const char* SongName, const char* Mood, int pram2, int pram3, int pram4, float pram5, int pram6)l
extern _native int AUDIO_MUSIC_FORCE_TRACK_HASH(int pram0)l
extern _native int UNK_0x2ACEE2ED(int p0, const char* p1, float p2, float p3, int p4, int p5, int p6)l//_AUDIO_MUSIC_PLAY_TRACK_2 what roulette has
extern _native int UNK_0x85A35B18(int  p0, const char* p1, float p2, float p3, int  p4, int  p5, int  p6)l//_AUDIO_MUSIC_PLAY_TRACK what roulette has
extern _native void AUDIO_MUSIC_SET_MOOD(const char* Mood, float pram1, int pram2, int pram3)l
extern _native void AUDIO_MUSIC_ONE_SHOT(char* songName, int unk1, int unk2, int unk3, int unk4, int unk5)l
extern _native bool AUDIO_MUSIC_PLAY_PREPARED()l
extern _native32(0x704DBAC9) int _AUDIO_MUSIC_GET_RANDOM_TRACK_HASH_FROM_TRACK_LIST(int pram0)l
extern _native bool AUDIO_MUSIC_IS_PREPARED()l
extern _native void AUDIO_MUSIC_SET_STATE(int pram0)l
extern _native void AUDIO_MUSIC_RELEASE_CONTROL(int time, int alwaysZero)l
extern _native void AUDIO_MUSIC_SUSPEND(int time)l
extern _native void AUDIO_MUSIC_RESUME()l
extern _native bool AUDIO_IS_MUSIC_PLAYING()l
extern _native bool AUDIO_IS_SCRIPTED_MUSIC_PLAYING()l
extern _native bool AUDIO_IS_FRONTEND_MUSIC_PLAYING()l
extern _native void AUDIO_MUSIC_SET_SUSPENSE_ALLOWED()l
extern _native void AUDIO_MUSIC_PLAY_UNSCRIPTED_NOW()l
extern _native void AUDIO_PLAY_ALL_LINES_FOR_ACTOR(int pram0)l
extern _native32(0xB3C3FF5E) void _AUDIO_MINIGAME_START()l
extern _native32(0xEA2B35DB) void _AUDIO_MINIGAME_STOP()l
extern _native32(0x0CCE435E) void _AUDIO_FILLET_MINIGAME_START(int pram0, int pram1, int pram2)l
extern _native32(0x7784BB85) void _AUDIO_FILLET_MINIGAME_HIT_FINGER()l
extern _native32(0x24AE7AFB) void _AUDIO_FILLET_MINIGAME_HIT_TABLE()l
extern _native32(0xDE7C65CE) void _AUDIO_FILLET_MINIGAME_PULL_FROM_TABLE()l
extern _native32(0x338DF299) void _AUDIO_FILLET_MINIGAME_END()l
extern _native void AUDIO_ADD_ALTERNATE_CONTEXT(int pram0, int pram1, int pram2)l
extern _native32(0x900C489A) int _AUDIO_CLEAR_ALL_ALTERNATE_CONTEXT()l
extern _native int LOAD_AUDIO_METADATA(const char* type, const char* datFileName, const char* name)l
//UNLOAD_AUDIO_METADATA 0xB73AC04A
extern _native int LOAD_AUDIO_SPEECH_DATA(int pram0)l
extern _native int SET_AUDIO_SEARCH_PATH()l//unsure 0x37FD00EA
extern _native32(0x98CD7340) bool _AUDIO_GET_BANK_LOADING_STATUS(const char* refName, const char* bankPath)l
extern _native void LOAD_AUDIO_BANK(const char* refName, const char* bankPath)l
extern _native32(0x176E921C) void _AUDIO_MAKE_SLOT_STATIC(const char* pram0)l
extern _native32(0xBAEC56D1) void _AUDIO_SET_MS_BETWEEN_PLAYER_TALKS_TO_SELF(int pram0)l
//////////////////////////////////
//Core
/////////////////////////////////
extern _native void SET_DEBUG_DRAW(int pram0)l
extern _native int GET_DEBUG_DRAW_STATE()l//0xFF0B53EF
//0x6DE957C6
extern _native void SCRIPT_BREAKPOINT(int pram0)l
extern _native void GRINGO_DEBUG_CHECK_SOUND(int pram0)l//0x5AC72FCC
extern _native32(0x9FEFA743) void _DISABLE_ACTOR_REF_COUNTING(int pram0)l
extern _native const char* GET_SCRIPT_NAME()l
extern _native const char* GET_SHORT_SCRIPT_NAME()l
extern _native void TERMINATE_THIS_SCRIPT()l
extern _native Script GET_THIS_SCRIPT_ID()l
extern _native bool IS_SCRIPT_VALID(Script script)l
extern _native bool DOES_SCRIPT_EXIST(const char* scriptPath)l
extern _native bool IS_EXITFLAG_SET()l
extern _native32(0x4417C9F2) int _IS_ANY_NAMED_SCRIPT_RUNNING(int pram0)l
extern _native32(0x5719022) void _TERMINATE_ALL_CHILD_SCRIPTS(const char* str)l
extern _native void TERMINATE_SCRIPT(Script script)l
extern _native void ADD_PERSISTENT_SCRIPT(Script script)l
extern _native void REMOVE_PERSISTENT_SCRIPT(Script script)l
extern _native32(0x4C48EA4D) int _GET_MAX_INSTRUCTION_COUNT()l
extern _native32(0xD058BD70) int _GET_USED_INSTRUCTION_COUNT()l
extern _native32(0x26884138) int _GET_REMAINING_INSTRUCTION_COUNT()l
extern _native void RAND_SET_SEED(int pram0)l
extern _native int RAND_INT_RANGE(int min, int max)l
extern _native float RAND_FLOAT_RANGE(float min, float max)l
extern _native int RAND_INT_RANGE_DIFFERENT(int pram0, int pram1, int pram2)l//_RAND_RANGE_DIFFERENT_RANDOM_INT 0x1D69F321
extern _native int RAND_FLOAT_GAUSSIAN(int pram0, int pram1)l
extern _native void FILE_START_PATH(int pram0)l
extern _native void FILE_ADD_TO_PATH(int pram0)l
extern _native void FILE_END_PATH()l
extern _native32(0x6F323C5F) int _FILE_GET_PATH()l
extern _native float GET_X(vector3 value)l
extern _native float GET_Y(vector3 pram0)l
extern _native float GET_Z(vector3 value)l
extern _native void VNORMALIZE(int pram0)l
extern _native void VCROSS(int pram0, int pram1, int pram2)l
extern _native int VDOT(int pram0, int pram1)l
extern _native void VSCALE(vector3 * vector, float scale)l
extern _native32(0xF1A53C41) void _VDIRECTION_VECTOR_FROM_EULERS(int pram0, int pram1, int pram2, int pram3)l
extern _native32(0xF76F2BB3) void _VROTATE_VECTOR_FROM_EULERS(int pram0, int pram1, int pram2, int pram3)l
extern _native32(0x65DAA654) void _VROTATE_EULER_FROM_EULERS(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5)l
extern _native32(0x1BD78730) void _VROTATE_VECTOR_XZ(int pram0, int pram1, int pram2)l
extern _native32(0x141201A3) int _CONSTRUCT_MATRIX_AND_TRANSFORM(float p0, float p1, float p2, float p3, float p4, float p5, int p6, int p7, int p8, int p9, int p10)l
extern _native float FABS(float f)l
extern _native int ABS(float value)l
extern _native float SIN_DEGREE(float value)l
extern _native float COS_DEGREE(float value)l
extern _native float TAN_DEGREE(float value)l
extern _native float ATAN_DEGREE(float value)l
extern _native float ATAN2_DEGREE(float y, float x)l//x y is what we had
extern _native32(0x9C40E671) float _GET_VECTOR_HEADING_DEGS(vector3 pram0)l
extern _native32(0xADF7D54B) int _GET_VECTOR_HEADING_RADS(int pram0)l
extern _native32(0x3DD1DC3F) int _GET_ANGLE_BETWEEN_VECTOR_DEGS(int pram0, int pram1)l
extern _native32(0x44986367) void _CREATE_VECTOR_FROM_HEADING(int pram0, int pram1)l
extern _native32(0xBB3CDF72) int _TRANSFORM_WORLD_TO_SCREEN(int p0, float p1, float p2)l
extern _native float GET_CURRENT_GAME_TIME()l//_GET_CURRENT_TIME 0x5842B9D1
extern _native int GET_CURRENT_UNWARPED_TIME()l
extern _native float GET_SYSTEM_TIME()l//unsure 0x17CEE67A
extern _native int GET_TIMESTAMP()l
extern _native int GET_UTC_TIME()l
extern _native int GET_UNWARPED_REALTIME_SECONDS()l
extern _native int GET_PROFILE_TIME()l
extern _native float GET_LAST_FRAME_TIME()l
extern _native void LOG_MESSAGE(char* message)l
extern _native void LOG_WARNING(char* message)l
extern _native void LOG_ERROR(char* message)l
extern _native Actor GET_TARGET_ACTOR()l
extern _native void GRINGO_SET_TARGET_OBJECT(int pram0, int pram1, int pram2)l
extern _native int GET_TARGET_OBJECT()l
extern _native bool IS_GRINGO_VALID(int gringo)l
extern _native void GET_GRINGO_ACTIVATION_SPHERE(int pram0, int pram1, int pram2)l
extern _native void DISABLE_GRINGO_STREAMING_CHECKS()l
extern _native void ENABLE_GRINGO_STREAMING_CHECKS()l
extern _native void GRINGO_ALLOW_ACTIVATION(int gringo, bool allow)l
extern _native32(0x52261CE0) bool _GRINGO_IS_USE_ALLOWED(int p0)l
extern _native32(0x358F874F) bool _IS_DEBUG_KEY_DOWN(eKey keyCode)l
extern _native32(0xCBC97619) bool _IS_DEBUG_KEY_PRESSED(eKey KeyCode)l
extern _native bool IS_BUTTON_DOWN(Controller Controller, eButton Button, int Unk1, int Unk0)l
extern _native bool IS_BUTTON_PRESSED(Controller Controller, eButton Button, int Unk1, int Unk0)l
extern _native bool IS_BUTTON_RELEASED(Controller Controller, eButton Button, int Unk1, int Unk0)l
extern _native float GET_ANALOG_BUTTON_VALUE(Controller Controller, eButton Analog, bool Unk1)l
extern _native float GET_STICK_X(Controller Controller, bool IsRightStick, int unk1)l
extern _native float GET_STICK_Y(Controller Controller, bool IsRightStick, int unk1)l
extern _native void UNK_0x52B2F3F0(int pram0)l
extern _native int UNK_0xD4DEBC08(int pram0)l
extern _native int UNK_0xBEC2871A(int pram0)l
extern _native int UNK_0xEF4F4F20(int pram0)l
extern _native void DEBUG_DRAW_VECTOR(int p0, int p1)l
extern _native void DEBUG_DRAW_LINE(int p0, int p1, int p2, int p3)l
extern _native int DEBUG_DRAW_SPHERE(int p0, int p1, int p2, int p3, int p4, int p5, int p6)l
extern _native int DEBUG_DRAW_STRING()l
extern _native32(0x3C2D93C1) void _DEBUG_DRAW_STRING_ON_SCREEN(float x, float y, const char* Text, float r, float g, float b, float a)l
extern _native void SET_DEBUG_FADE_STATE(int pram0)l
extern _native int UNK_0xD1D88EB8(int pram0)l
extern _native int UNK_0x21E19CD5(int pram0)l
extern _native int UNK_0x1B6FE39B(int pram0)l
extern _native int UNK_0xAAEBAC28(int pram0)l
extern _native int UNK_913A5CB6()l
extern _native int UNK_0xD34F7B3A()l
extern _native int ACTOR_NOTE_USAGE_CHEAT()l//0x191658C0 what fox had
extern _native32(0x00EF33EF) int UNK_0x95132289()l
extern _native void DECOR_SET_COLD_BREATH(int pram0)l//0xEB8325B3 what fox had
extern _native int UNK_0xD3FE15FB()l
extern _native int UNK_0x32D1DEB0()l
extern _native void RETRIEVE_GAME_STATE(int* gameStruct, int state, bool unk)l
extern _native void STORE_GAME_STATE(int pram0, int pram1, int pram2)l
extern _native32(0xE1124E00) void _RESET_SCRIPT_STORED_DATA()l
extern _native void RESET_GAME()l
extern _native bool IS_GAME_RESETTING()l
extern _native32(0xC7612A79) char* _GET_PARAM_VALUE(int pram0, int pram1)l
extern _native int GET_DISTRICTS_NAME()l
extern _native int LOAD_GAME(int saveID)l
extern _native int LOAD_SOFT_SAVE(int saveID)l
extern _native int SAVE_GAME(const char* save)l
extern _native void SAVE_SOFT_SAVE(int saveID)l
extern _native32(0xED40F27D) void _HARD_SAVE(int pram0)l
extern _native32(0x8C710D3E) int _HARD_LOAD(int pram0)l
extern _native32(0x17F34613) void _CREATE_SAVE_DISPLAY_NAME(int pram0)l
extern _native32(0x20CE8AA8) void _REGISTER_DATA(int pram0, int pram1, int pram2, int pram3, int pram4)l
extern _native32(0x8E867DDD) void _SET_SCRIPT_SAVE_VERSION_OLD(int pram0)l
extern _native32(0x6E79F939) void _SET_SCRIPT_SAVE_VERSION(int pram0, int pram1)l
extern _native32(0x3E647734) void _CREATE_SAVE_FILE(int pram0, int pram1, int pram2)l
extern _native32(0xE8637D2B) void _SAVE_REGISTER_STATS(int pram0, int pram1, int pram2, int pram3, int pram4)l
extern _native32(0x6D59A25F) void _SAVE_REGISTER_PROFILE_STATS(int pram0, int pram1)l
extern _native32(0x1D177160) int _IS_SAVING_DISABLED()l
extern _native32(0x1ADA1769) int _IS_SP_SAVING_DISABLED()l
extern _native bool DOES_FILE_EXIST(int pram0)l
extern _native void UNK_0xD44F7102(const char* debugMessage, const char* debugPath, int pedType)l
extern _native bool IS_DEV_BUILD()l
extern _native int IS_PS3()l
extern _native int IS_PS4()l
extern _native int IS_SWITCH()l
extern _native32(0xB427CB25) bool _ARE_BUMPER_BUTTONS_SWAPPED()l
extern _native bool IS_DISK_CACHE_PRIMED()l//int
extern _native bool IS_PLAYER_SIGNED_IN()l
extern _native char* GET_LOCAL_PLAYER_NAME(int player)l
extern _native int GET_NUM_WORLD_CAMERAS()l
extern _native int GET_WORLD_CAMERA_AT_INDEX(int pram0, int pram1, int pram2)l
extern _native int GET_CLOSEST_WORLD_CAMERA(vector3 position, float unk1, vector3 unk2, vector3 unk3)l //unk1 is always 256.0f in scripts
extern _native void PAUSE_GAME(int pram0)l
extern _native void UNPAUSE_GAME()l
extern _native bool IS_GAME_PAUSED()l
extern _native void SET_SCRIPT_CUTSCENE_ACTIVE(bool active)l
//SET_TREE_COST_MODIFIER 0x81A7CDB6
//SET_USES_QUAD_IK_FIX 0x2A04518E
//SET_VISIBILITY_FOV_CLAMP 0x4FC61E5F
extern _native void SET_MISSION_INFO(int pram0, int pram1)l
extern _native void CLEAR_MISSION_INFO()l
extern _native32(0x6CD7DCE1) void _GET_START_POS(int pram0, int pram1)l
extern _native void SET_START_POS(float posX, float posY, float posZ, float heading, int unkZero)l
extern _native32(0x3B004817) bool _IS_START_POS_IN_COMMAND_LINE()l
extern _native32(0x3B004817) int _WAS_LAST_RESET_FOR_MULTIPLAYER()l
extern _native void SCRIPT_DONE_LOADING()l
extern _native Script LAUNCH_NEW_SCRIPT(const char* scriptDir, int alwaysZero)l
extern _native int LAUNCH_NEW_SCRIPT_WITH_ARGS(const char* script, int pram1, int arg1, int arg2)l
extern _native int IS_LAUNCH_RETAIL()l
extern _native bool IS_SIMULATE_START_PRESS()l
extern _native bool IS_SIMULATE_START_MULTIPLYER()l
//0xD90DB78D
extern _native bool IS_DISPLAY_WIDESCREEN()l
extern _native32(0x6226328F) int _GET_EXP_MODE_PROMPT()l
extern _native32(0x59F98CA9) void _SET_EXP_MODE_PROMPT(int pram0)l
extern _native int GET_GAME_EDITION()l
//////////////////////////////////
//Play Stats
/////////////////////////////////
extern _native void UNK_0x2547029C(int pram0, int pram1)l
extern _native void UNK_0x6F6D942B(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5, int pram6)l
extern _native void UNK_0x713B1D7F(int pram0, int pram1)l
extern _native32(0x9C80A3A4) void _START(int pram0, int pram1, int pram2, int pram3, int pram4)l//foxxy named this + below
extern _native32(0x27A00456) void _MP_DEED_START(int pram0)l
extern _native32(0x120E6123) void _MP_DEED_COMPLETE(int pram0)l
extern _native32(0x4585821E) void _MP_DEED_COMPLETE_EX(int pram0, int pram1, int pram2, int pram3)l
extern _native32(0x46C39437) void _MP_COOP_COMPLETE(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5)l
//////////////////////////////////
//Targeting
/////////////////////////////////
extern _native Actor GET_ACTOR_UNDER_RETICLE(Actor actor, int value)l
extern _native int GET_RETICLE_TARGET_POINT(Actor actor, vector3 * SurfacePos)l
extern _native int SET_PLAYER_PERFECT_ACCURACY(int p0, int p1)l
extern _native void OVERRIDE_PLAYER_TARGETING_WEIGHTS(int pram0, int pram1, int pram2, int pram3)l
extern _native void SET_ACTOR_BASE_SCORE(int pram0, int pram1, int pram2)l
extern _native void SET_ACTOR_HARDLOCK_BIAS(int pram0, int pram1, int pram2)l
extern _native void SET_ACTOR_USE_FULLSCREEN_ACQUISITION(int pram0, int pram1)l
extern _native void SET_ACTOR_CAN_BE_TARGETED(int pram0, int pram1)l
extern _native void SET_ACTOR_CAN_BE_TARGETED_CASUAL_ONLY(int pram0, int pram1)l
extern _native32(0xF4429710) void _SET_ACTOR_CAN_BE_HARD_LOCKED(int pram0, int pram1)l
extern _native32(0x1468DD56) bool _CAN_ACTOR_BE_HARD_LOCKED(int p0, int p1, int p2, int p3, int p4, int p5)l//int p6, int p7 scripts show 6 params rouletteboi has 8 idk why
extern _native void SET_ACTOR_CAN_BE_SOFTLOCKED(int pram0, int pram1)l
extern _native void SET_ACTOR_CAN_BE_AIMASSISTED(Actor actor, bool allow)l
extern _native void SET_ACTOR_CAN_BE_BUMPTARGETED(int pram0, int pram1)l
extern _native32(0x5CC16A49) void _SET_ONLY_TARGET_IF_HOSTILE(int pram0, int pram1)l
extern _native32(0x5CC16A49) int _IS_ACTOR_WITHIN_ACCURACY_RANGE()l//unsure
extern _native32(0x1EEE7494) void _SET_ACTOR_HARD_LOCK_NEUTRALS(int pram0, int pram1)l
extern _native int CALCULATE_NORMALIZED_SCREEN_DISTANCE_FROM_RETICLE(int pram0, int pram1)l
//////////////////////////////////
//Camera
/////////////////////////////////
extern _native Camera GET_GAME_CAMERA()l//camera
extern _native void CAMERA_RESET(int unkValue)l
//SET_GAME_CAMERA_DRIFTZ 0x39E59CD8
//_CAMERA_CUT_MANUAL 0x5E07BF3F
extern _native bool CAMERA_PROBE(vector3 * result, vector3 source, vector3 target, Actor owner, int flag)l
extern _native32(0x1EEE7494) int _RESET_GAME_CAMERA_ARC_TRANSITIONS()l
extern _native32(0x0B071844) int _GET_CAMERA_RESET_POSITION(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5, int pram6)l
extern _native Camera SET_CAMERA_FOLLOW_ACTOR(Actor actor)l
extern _native int SET_CAMERA_FOLLOW_ACTOR_EX(int pram0, int pram1)l
extern _native32(0x9B083FD2) int _GET_ROAM_LOOK_STICK_INVERT_Y()l//_GET_Y_STICK_INVERT
extern _native32(0x063F900A) void _SET_ROAM_LOOK_STICK_INVERT_Y(bool invert)l
extern _native void SET_GAME_CAMERA_CURVE_OVERRIDE(int pram0, int pram1)l
extern _native void RESET_GAME_CAMERA_CURVE_OVERRIDES()l
extern _native void FORCE_VEHICLE_CINEMATIC_CAMERA(Vehicle vehicle)l
extern _native int IS_VEHICLE_CINEMATIC_CAMERA_FORCED_ON()l
extern _native32(0x382C47C5) void _SET_GAME_CAMERA_VEHICLE_CAMERA_MODE(int pram0)l
extern _native void ALLOW_GAME_CAMERA_AUTO_CENTERING(int pram0, int pram1)l
extern _native32(0xE13B49BD) int _IS_GAME_CAMERA_AUTO_CENTERING(int pram0)l
extern _native void ALLOW_GAME_CAMERA_AUTO_TILTING(int pram0, int pram1)l
extern _native int CREATE_AIMRAMP_IN_LAYOUT(int pram0, int pram1)l
extern _native32(0x4062688A) int _IS_GAME_CAMERA_AUTO_TILTING(int pram0)l
extern _native void SET_GAME_CAMERA_FOCUS(int pram0, int pram1, int pram2, int pram3)l
extern _native void ENABLE_GAME_CAMERA_FOCUS(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5, int pram6, int pram7)l
extern _native void DISABLE_GAME_CAMERA_FOCUS()l
extern _native bool IS_GAME_CAMERA_FOCUS_ENABLED()l
extern _native int SET_DEBUG_CAMERA_MODE()l
extern _native32(0xAE168124) int _IS_SWITCH_CAMERA_BUTTOM_MODE_ENABLED()l
extern _native32(0x9F1F8669) void _SET_SWITCH_CAMERA_BUTTOM_MODE_ENABLED(int pram0)l
//////////////////////////////////
//GOH Camera
/////////////////////////////////
extern _native Camera CREATE_CAMERA_IN_LAYOUT(Layout layout, const char* pram0, int pram1)l
extern _native32(0xBCC98808) int _GET_CURRENT_CAMERA_FROM_CHANNEL_TYPE(int pram0)l
extern _native void SET_CURRENT_CAMERA_ON_CHANNEL(Camera cam, int pram1, int pram2, int pram3, int pram4, int pram5, int pram6, int pram7, int pram8, int pram9)l
extern _native void REMOVE_CAMERA_FROM_CHANNEL(Camera cam, int unk)l
extern _native int GET_CAMERA_CHANNEL_POSITION(int pram0, int pram1)l
extern _native vector3 GET_CAMERA_CHANNEL_DIRECTION(Camera cam, int channel)l
extern _native32(0x9A4CD54B) int _IS_CAMERA_CHANNEL_TRANSITIONING(int pram0)l
extern _native int IS_CAMERA_ACTIVE_ON_CHANNEL(int pram0, int pram1)l
extern _native void INIT_CAMERA_FROM_GAME_CAMERA(Camera cam)l
extern _native void INIT_CAMERA_FROM_CHANNEL(int pram0, int pram1)l
//extern _native void SET_CAMERA_POSITION(Camera camera, float posX, float posY, float posZ)l
extern _native void SET_CAMERA_POSITION(Camera camera, vector3 outPosition)l
extern _native void GET_CAMERA_POSITION(Camera camera, vector3 * outPosition)l
extern _native void SET_CAMERA_DIRECTION(Camera Cam, vector3 Direction, bool Unk1)l
extern _native void GET_CAMERA_DIRECTION(Camera camera, vector3 * outDirection)l
extern _native void GET_CAMERA_UP_VECTOR(int pram0, int pram1)l
extern _native void SET_CAMERA_FOV(Camera cam, float value)l
extern _native float GET_CAMERA_FOV(Camera camera)l
extern _native void SET_CAMERA_ASPECT_RATIO(int pram0, int pram1)l
extern _native int GET_CAMERA_ASPECT_RATIO(int pram0)l
extern _native void SET_CAMERA_NEAR_CLIP_PLANE(Camera cam, float value)l
extern _native void SET_CAMERA_FAR_CLIP_PLANE(int pram0, int pram1)l
//extern _native void SET_CAMERA_ORIENTATION(Camera camera, float posX, float posY, float posZ, bool unk)l
extern _native void SET_CAMERA_ORIENTATION(Camera camera, vector3 outPosition, bool unk)l
extern _native void SET_CAMERA_TARGET_POSITION(int pram0, int pram1, int pram2, int pram3, int pram4)l
extern _native void SET_CAMERA_TARGET_OBJECT(int pram0, int pram1, int pram2)l
extern _native void SET_CAMERA_COLLISION_PARAMETERS(int pram0, int pram1, int pram2)l
extern _native void ADD_CAMERA_COLLISION_EXCLUSION(int pram0, int pram1, int pram2)l
extern _native void REMOVE_CAMERA_COLLISION_EXCLUSION(int pram0, int pram1)l
extern _native void RESET_CAMERA_TARGET(int pram0, int pram1)l
extern _native void SET_CAMERA_COLLISION_ENABLED(int pram0, int pram1)l
extern _native int SET_CAMERA_TARGETDOF_FOCAL_LENGTH(int p0, float p1)l
extern _native void SET_CAMERA_TARGETDOF_USING_SOFT_DOF(int pram0, int pram1, int pram2)l
extern _native void RESET_CAMERA_TARGETDOF(int pram0)l
extern _native int SET_CAMERA_LIGHTING_SCHEME(Camera cam, char* unkScheme)l
extern _native int CAMERA_GET_CURRENT_TRANSITION_TYPE(int pram0)l
extern _native bool CAMERA_IS_VISIBLE_OBJECT(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5, int pram6)l
extern _native bool CAMERA_IS_VISIBLE_ACTOR(Camera camera, Actor actor, int pram2, int pram3, bool pram4, bool pram5, bool pram6)l
extern _native bool CAMERA_IS_VISIBLE_POINT(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5, int pram6, int pram7, int pram8)l
extern _native bool CAMERA_IS_VISIBLE_VOLUME(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5, int pram6)l
extern _native int CREATE_CAMERASHOT_IN_LAYOUT(int pram0, int pram1)l
extern _native void INIT_CAMERASHOT_FROM_GAME_CAMERA(Camera camreaShot)l
extern _native void FORCE_CAMERASHOT_UPDATE(int pram0)l
extern _native void SET_CAMERASHOT_POSITION(int pram0, int pram1, int pram2, int pram3)l
extern _native void GET_CAMERASHOT_POSITION(int pram0, vector3 * pram1)l
extern _native void SET_CAMERASHOT_DIRECTION(int pram0, int pram1, int pram2, int pram3, int pram4)l
extern _native void GET_CAMERASHOT_DIRECTION(int pram0, int pram1)l
extern _native int GET_CAMERASHOT_UP_VECTOR(int p0, int p1)l
extern _native int GET_CAMERASHOT_X_VECTOR(int p0, int p1)l
extern _native void SET_CAMERASHOT_FOV(Camera camera, float fov)l
extern _native int GET_CAMERASHOT_FOV(Camera camreaShot)l
extern _native void SET_CAMERASHOT_ASPECT_RATIO(int pram0, int pram1)l
extern _native void SET_CAMERASHOT_NEAR_CLIP_PLANE(int pram0, int pram1)l
extern _native void SET_CAMERASHOT_FAR_CLIP_PLANE(int pram0, int pram1)l
extern _native int GET_CAMERASHOT_FAR_CLIP_PLANE(int pram0)l
extern _native void SET_CAMERASHOT_ORIENTATION(int pram0, int pram1, int pram2, int pram3, int pram4)l
extern _native void SET_CAMERASHOT_TARGET_POSITION(int pram0, int pram1, int pram2, int pram3, int pram4)l
extern _native void SET_CAMERASHOT_TARGET_OBJECT(int pram0, int pram1, int pram2)l
extern _native void SET_CAMERASHOT_TARGET_OBJECT_OFFSETS(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5, int pram6, int pram7)l
extern _native void SET_CAMERASHOT_TARGET_OBJECT_ROLL(int pram0, int pram1)l
extern _native void SET_CAMERASHOT_TARGET_OBJECT_BONE(int p0, int p1, int p2)l
extern _native void SET_CAMERASHOT_FROM_LENS(int pram0, int pram1)l
extern _native void SET_CAMERASHOT_TARGETDOF_OBJECT(int pram0, int pram1)l
extern _native void SET_CAMERASHOT_TARGETDOF_TARGET_OFFSET(int pram0, int pram1)l
extern _native void SET_CAMERASHOT_TARGETDOF_FIXED_DISTANCE(int pram0, int pram1)l
extern _native void SET_CAMERASHOT_TARGETDOF_FOCAL_LENGTH(int pram0, int pram1)l
extern _native void SET_CAMERASHOT_TARGETDOF_CUTOFF_DISTANCE(int pram0, int pram1)l
extern _native void SET_CAMERASHOT_TARGETDOF_SMOOTHING(int pram0, float pram1)l
extern _native void SET_CAMERASHOT_TARGETDOF_USING_SOFT_DOF(int pram0, int pram1, int pram2)l
extern _native void SET_CAMERASHOT_TARGETDOF_FILTERTYPE(int pram0, int pram1)l
extern _native void SET_CAMERASHOT_TARGETDOF_FSTOP(int pram0, int pram1)l
extern _native void RESET_CAMERASHOT_TARGETDOF(int pram0)l
extern _native void SET_CAMERASHOT_COLLISION_PARAMETERS(int pram0, int pram1, int pram2)l
extern _native void ADD_CAMERASHOT_COLLISION_EXCLUSION(int pram0, int pram1, int pram2)l
extern _native void ADD_CAMERASHOT_COLLISION_BOUNDFLAG(int pram0, int pram1)l
extern _native void RESET_CAMERASHOT_TARGET(int pram0, int pram1)l
extern _native void SET_CAMERASHOT_PERSPECTIVE(int pram0, int pram1)l
extern _native void SET_CAMERASHOT_CONTROL_SEQUENCE_VEC3(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5, int pram6, int pram7, int pram8, int pram9)l
extern _native int ADD_CAMERA_SHOT_TRANSITION_HOLD(int p0, int p1, int p2, float p3, int p4, int p5)l
extern _native int ADD_CAMERA_SHOT_TRANSITION_INDEFINITE(int pram0, int pram1, int pram2)l
extern _native int ADD_CAMERA_SHOT_TRANSITION_EASE_OUT(int p0, int p1, int p2, int p3, int p4, float p5, int p6, int p7, const char* p8)l
extern _native int ADD_CAMERA_SHOT_TRANSITION_EASE_IN_OUT(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5)l
extern _native void SET_FIXED_TRANSITION_T(int pram0, int pram1)l
extern _native void SET_TRANSITION_COLLISION_PARAMS(int pram0, int pram1, int pram2)l
extern _native int GET_CAMERA_SHOT_TRANSITION(int pram0)l
extern _native bool IS_PROCESSING_CAMERA_SHOT_TRANSITION(int pram0)l
extern _native void END_CURRENT_CAMERA_SHOT_TRANSITION(int pram0)l
extern _native void SET_CAMERASHOT_COLLISION_ENABLED(int pram0, int pram1)l
extern _native void SET_CUTSCENE_STREAMING_LOAD_SCENE(int pram0, int pram1)l
extern _native int ATTACH_CAMERASHOT(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5, int pram6, int pram7, int pram8, int pram9, int pram10, int pram11)l
extern _native void DETACH_CAMERASHOT(int pram0)l
extern _native int CAMERASHOT_IS_VISIBLE_ACTOR(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5, int pram6)l
extern _native void CAMERASHOT_ADD_ARC_BEHAVIOR(Camera cameraShot, const char* arcItemName)l
extern _native void CAMERASHOT_ADD_LOOKSTICK_ROTATION_BEHAVIOR(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5, int pram6)l
extern _native int CREATE_AIMRAMP_IN_LAYOUT(int pram0, int pram1)l
extern _native void UPDATE_AIMRAMP(int pram0, int pram1, int pram2, int pram3, int pram4)l
extern _native int CREATE_CUTSCENEOBJECT_IN_LAYOUT(Layout layout, char* cutscene, int pram2, int pram3)l
extern _native Camera GET_CAMERA_FROM_CUTSCENEOBJECT(int cutscene)l
extern _native void PLAY_CUTSCENEOBJECT(int cutscene, int pram1, float pram2, float pram3, int pram4, int pram5, int pram6, int pram7, int pram8, int pram9)l
extern _native int GET_CAMERASHOT_FROM_CUTSCENEOBJECT(int pram0, int pram1)l
extern _native int CUTSCENEOBJECT_ADD_TRANSITION_HOLD(int pram0, int pram1, int pram2, int pram3)l
extern _native int CUTSCENEOBJECT_ADD_TRANSITION_LERP(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5)l
extern _native int CUTSCENEOBJECT_ADD_TRANSITION_EASE_IN(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5)l
extern _native int CUTSCENEOBJECT_ADD_TRANSITION_EASE_OUT(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5)l
extern _native int CUTSCENEOBJECT_ADD_TRANSITION_EASE_IN_OUT(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5)l
extern _native int CUTSCENEOBJECT_ADD_TRANSITION_INDEFINITE(int pram0, int pram1, int pram2)l
extern _native int CUTSCENEOBJECT_ADD_TRANSITION_DECORATOR(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5, int pram6)l
extern _native int CUTSCENEOBJECT_ADD_TRANSITION_FIXED(int pram0, int pram1, int pram2, int pram3, int pram4)l
extern _native int CUTSCENEOBJECT_GET_CURRENT_TRANSITION_TYPE(int pram0)l
extern _native void END_CURRENT_TRANSITION_FROM_CUTSCENEOBJECT(int pram0)l
extern _native void SET_CUTSCENEOBJECT_PAUSED(int pram0, int pram1)l
extern _native bool IS_CUTSCENEOBJECT_PAUSED(int cutscene)l
extern _native int CHECK_CUTSCENE_COLLISIONS(int pram0)l
extern _native int GET_CUTSCENEOBJECT_SEQUENCE(int pram0)l
extern _native32(0xDCD3A7DE) void _CUTSCENE_SET_RECENTER_GAMECAM(int pram0, int pram1)l
extern _native int SET_CUTSCENEINPUTS_TARGET_GUID(int pram0, int pram1, int pram2)l
extern _native void ADD_CAMERATRANSITION_EVENT_HUDFADEIN(int pram0, int pram1, int pram2, int pram3)l
extern _native void ADD_CAMERATRANSITION_EVENT_HUDFADEOUT(int pram0, int pram1, int pram2, int pram3)l
extern _native void ADD_CAMERATRANSITION_EVENT_GAMECAMERARESET(int pram0, int pram1, int pram2, int pram3)l
extern _native void ADD_CAMERATRANSITION_EVENT_GAMECAMERARESETTILT(int pram0, int pram1, int pram2)l
extern _native void ADD_CAMERATRANSITION_EVENT_CUTGAMECAMERABEHINDPLAYER(int pram0, int pram1, int pram2)l
extern _native32(0xCDA6BB6C) bool _IS_CUTSCENE_TUNER_PLAYING_BACK()l
extern _native void CANCEL_CUTSCENE_TUNER_PLAYBACK()l
extern _native32(0x93050734) int _GET_CUTSCENE_TUNER_CUTSCENE_OBJECT()l
extern _native32(0xFF1F1730) bool _GET_CUTSCENE_TUNER_CUTSCENE_INPUTS_OBJECT()l
extern _native int GET_CUTSCENE_TUNER_SCRIPT_NAME(int pram0)l
extern _native32(0xD8218A5B) int _GET_CUTSCENE_TUNER_SCRIPT_CUTSCENE_INDEX()l
extern _native32(0x6AD6A400) int _CREATE_CAMERA_FOCUS_IN_LAYOUT_POINT(int p0, int p1, int p2, float p3, float p4, float p5, float p6, float p7)l
extern _native32(0x76876FEA) int _CREATE_CAMERA_FOCUS_IN_LAYOUT_OBJECT(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5, int pram6, int pram7)l
extern _native32(0x7A6146DB) Camera _CREATE_CAMERA_FOCUS_IN_LAYOUT_OBJECT_EX(Layout layout, int unk1, Object prop, char* focusName, float unk2, float unk3)l
extern _native bool IS_CAMERA_FOCUS_ACTIVE(int pram0)l
extern _native void SET_CAMERA_FOCUS_ENABLED(int pram0, int pram1)l
extern _native bool IS_CAMERA_FOCUS_ENABLED(int pram0)l
extern _native void SET_CAMERA_FOCUS_PROMPT_ENABLED(int pram0, int pram1)l
extern _native bool IS_CAMERA_FOCUS_PROMPT_ENABLED(Camera camera)l
extern _native void SET_CAMERA_FOCUS_PLAYER_INPUT_DISABLED(int pram0, int pram1)l
extern _native void SET_CAMERA_FOCUS_PLAYER_INVULNERABLE(int pram0, int pram1)l
extern _native void SET_CAMERA_FOCUS_PROMPT_TEXT(Camera cam, char* promptText)l
extern _native void SET_CAMERA_FOCUS_OBJECT(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5)l
//////////////////////////////////
//Inventory
/////////////////////////////////
extern _native int ADD_ITEM(const char* itemName, Actor actor, bool DisplayText)l//displaytext was set as int, I assume this is a bool for text display
extern _native int ADD_ITEM_BY_CRC(int pram0, int pram1, int pram2)l
extern _native int HAS_INVENTORY_COMPONENT(int pram0)l
extern _native int GET_ITEM_COUNT(int pram0, int pram1)l
extern _native int GET_ITEM_COUNT_BY_CRC(int pram0, Actor actor)l
extern _native int GET_MAX_ITEM_COUNT(int pram0)l
extern _native void SET_MAX_ITEM_COUNT(int pram0, int pram1)l
extern _native int ADD_ACCESSORY(const char* bindType, Actor actor, int unk)l
extern _native int ADD_ACCESSORY_BY_CRC(int pram0, int pram1, int pram2)l
extern _native int ADD_COLLECTABLE(char* collectableName, Actor actor, bool DisplayText)l//displaytext was set as int, I assume this is a bool for text display
extern _native void REMOVE_COLLECTABLE(char* collectableName, Actor actor)l
extern _native void READY_ITEM(const char* ItemName, Actor Actor)l
extern _native bool HAS_ITEM(int pram0, int pram1)l
extern _native bool HAS_ACCESSORY(int pram0)l
extern _native void DELETE_ITEM(const char* itemName, Actor actor, int countMaybe)l//countmaybe is really unknown, could be count or a unused bool for text display for removed ? ?
extern _native void DELETE_ACCESSORY(const char* bindType, Actor actor)l
extern _native32(0x7BF75BCE) int _GET_ITEM_CRC_AT_INDEX(int pram0, Actor actor)l
extern _native32(0x7F4D5AE0) int _GET_ACCESSORY_CRC_AT_INDEX(int pram0, Actor actor)l
extern _native32(0x608DCAEF) int _GET_COLLECTABLE_CRC_AT_INDEX(int pram0, int pram1)l
extern _native int IS_ITEM_WEAPON_BY_CRC(int pram0)l
extern _native int GET_ITEM_IN_HAND_EQUIPSLOT(int pram0)l//_GET_ITEM_IN_HAND_EQUIP_SLOT 0x3A899B0E
extern _native32(0x0E0EFB13) int _GET_EQUIP_SLOT(Weapon weapon)l
extern _native void ACTOR_DISABLE_WEAPON_RENDER(Actor actor, int weapon, bool disable)l
extern _native void ACTOR_FORCE_WEAPON_RENDER(int pram0, int pram1, int pram2)l
extern _native bool IS_WEAPON_DRAWN(Actor actor)l
extern _native void GIVE_WEAPON_TO_ACTOR(Actor actor, int weaponID, float unk0, int unk1, int unk2)l
extern _native void ACTOR_SET_NEXT_WEAPON(Actor actor, int weaponID)l//_READY_ENUMERATED_WEAPON 0xBFD6D55F
extern _native int ACTOR_PUT_WEAPON_IN_HAND(int pram0, int pram1, int pram2)l
extern _native int ACTOR_HAS_WEAPON_IN_HAND(int pram0, int pram1)l
extern _native void ACTOR_PUT_ITEM_AWAY()l//unsure 0x13A63AA7
extern _native32(0x5CAFCBD4) bool _HAS_ENUMERATED_WEAPON_READY(int p0, int p1)l
extern _native32(0x5CAFCBD4) int _SET_INVENTORY_NEXT_USE_SLOT_WEAPON_ENUM(int pram0, int pram1, int pram2)l
extern _native32(0x3417766E) int _SET_INVENTORY_NEXT_USE_SLOT(Actor actor, int value1, int value2)l
extern _native32(0xCC02BBD3) int _GET_INVENTORY_NEXT_USE_SLOT(int pram0)l
extern _native32(0xA8040D70) int _GET_INVENTORY_CURRENT_USE_SLOT(int pram0)l
extern _native int ACTOR_HAS_WEAPON(int pram0, int pram1)l
extern _native Weapon ACTOR_GET_BEST_WEAPON_OF_TYPE(Actor actor, int unkValue)l
extern _native void DELETE_WEAPON_FROM_ACTOR(Actor actor, Weapon weapon)l
extern _native Weapon GET_WEAPON_EQUIPPED(Actor actor, int index)l
extern _native int UNK_0x6262DC5E(Actor actor, Weapon weapon)l
extern _native int GET_WEAPON_IN_HAND(Actor actor)l
extern _native int GET_WEAPON_IN_HAND_CRC(Actor actor)l
extern _native void UNK_0x612066E5(int pram0)l
extern _native int GET_WEAPON_ENUM_FROM_CRC(int pram0)l
extern _native void ACTOR_USE_ITEM_NOW(int pram0)l
extern _native void SET_EQUIP_SLOT_ENABLED(Actor actor, eWeapon weaponID, bool enable)l
extern _native int GET_EQUIP_SLOT_ENABLED(Weapon weapon)l
extern _native void EQUIP_ACCESSORY(int pram0, int pram1, int pram2)l
extern _native void DEEQUIP_ACCESSORY(int pram0, int pram1)l
extern _native bool HAS_ACCESSORY_ENUM(Actor actor, int pram1)l
extern _native32(0xE094DB31) int _IS_ACCESSORY_EQUIPPED(int pram0, int pram1)l
extern _native int DROP_ACCESSORY_ENUM(int pram0, int pram1)l
extern _native int ACTOR_SET_WEAPON_AMMO(Actor actor, int weaponId, float ammo)l
extern _native void ACTOR_SET_WEAPON_AMMO_BY_CRC(int pram0, int pram1, int pram2)l
extern _native void ACTOR_ADD_WEAPON_AMMO(Actor actor, int weaponID, int ammo)l
extern _native int ACTOR_GET_WEAPON_AMMO(int pram0, int pram1)l
extern _native void ACTOR_DISCARD_WEAPON_AMMO(int pram0, int pram1)l
extern _native bool ACTOR_HAS_VARIABLE_MESH(int pram0, int pram1)l//_HAS_MESH_BIT 0xA091179F
extern _native int GET_AMMOENUM_FOR_WEAPONENUM(int weaponID)l//_GET_AMMO_ENUM_FOR_WEAPON_ENUM 0x17883570
extern _native int GET_WEAPONENUM_FOR_AMMOENUM(int pram0, int pram1)l//_GET_WEAPON_ENUM_FOR_AMMO_ENUM 0xA8F64D32
extern _native void SET_WEAPON_GOLD(Actor actor, eWeapon weaponID, bool gold)l
extern _native int GET_WEAPON_GOLD(Actor Actor, Weapon Weapon)l
extern _native int IS_GOLDEN_GUNS_ON()l
extern _native void FIRE_PROJECTILE(Actor actor, const char* weapGroup, float pram2, vector3 * origin, vector3 * target)l
extern _native32(0x98B3ABFA) void _ADD_AMMO_OF_TYPE(Actor actor, int ammoType, int ammoAmmount, int pram3, bool usePrintStat)l
extern _native32(0x4372593E) void _SET_AMMO_OF_TYPE(Actor actor, int weaponID, float unk, bool unk2)l
extern _native32(0x6ADAAD87) void _SET_MAX_AMMO_AMOUNT(int pram0, int pram1, int pram2)l
extern _native32(0x4FE2B586) void _SET_INFINITE_AMMO_FLAG(Actor actor, eWeapon weaponId, bool infinite)l
extern _native32(0xE224AC6F) int _GET_AMMO_AMOUNT(Actor Actor, int ammoType, bool unk)l
extern _native32(0x7AB368CF) int _GET_MAX_AMMO_AMOUNT(int pram0, int pram1)l
extern _native32(0xC666B987) bool _GET_INFINITE_AMMO_FLAG(Actor Actor, int pram1)l
extern _native void ACTOR_SHOULD_DROP_ITEMS_ON_DEATH(int pram0, int pram1, int pram2)l
extern _native void ACTOR_SET_DROP_ITEM_ON_DEATH_ENUMERATED(int pram0, int pram1, int pram2)l//NET_POP_TEXT_MISSIONS what fox had
extern _native int CREATE_WEAPON_PICKUP(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5, int pram6)l
extern _native void REMOVE_ALL_PICKUPS()l
extern _native int GET_NUM_WEAPONS_IN_INVENTORY(Actor actor)l
extern _native32(0x78A3CD3D) int _GET_NUM_ACCESSORIES(Actor actor)l
extern _native32(0x2C23CBE7) int _GET_NUM_COLLECTABLES(int pram0)l
extern _native32(0xD695F857) void _DELETE_ALL_WEAPONS(Actor actor)l
extern _native32(0x96AC812B) void _DELETE_ALL_ACCESSORIES(Actor actor)l
extern _native32(0x5AEB2E4F) void _DELETE_ALL_INVENTORY(Actor actor)l//_REMOVE_HAT
extern _native void SETUP_ASSOCIATED_FRAGMENTS(Actor actor)l//_ADD_HAT 0x3E8E7D7B
extern _native int UNK_0x7BF01CCB()l
extern _native void UNK_0x8EA46104(int pram0)l
extern _native void UNK_0xD2A140BC()l
//////////////////////////////////
//Inventory Manager
/////////////////////////////////
extern _native void SET_INDICATOR_DRAW(int pram0, int pram1)l
//////////////////////////////////
//Ambient
/////////////////////////////////
extern _native void AMBIENT_SET_UPDATES_ENABLED(int pram0)l
extern _native void AMBIENT_SET_POINT_SPACING(float spacing)l
extern _native void AMBIENT_SET_SLOPE_VALUES(int pram0, int pram1, int pram2, int pram3)l
extern _native void AMBIENT_RESET_USED_CELLS()l
extern _native void AMBIENT_SET_SCAN_CENTER(int pram0, int pram1, int pram2)l
extern _native void AMBIENT_SET_SCAN_CENTER_PLAYER()l
extern _native void AMBIENT_RESET_FILTER(int pram0)l
extern _native void AMBIENT_SET_RANDOM_SEARCH_ORDER(int pram0)l
extern _native void AMBIENT_SET_ONESHOT_QUERIES(int pram0)l
extern _native void AMBIENT_SET_SEARCH_CENTER(int pram0, int pram1, int pram2)l
extern _native void AMBIENT_SET_SEARCH_CENTER_ACTOR(int pram0)l
extern _native void AMBIENT_SET_SEARCH_CENTER_PLAYER()l
extern _native void AMBIENT_SET_SLOPE_FILTER(int p0, int p1, float p2)l
extern _native void AMBIENT_ENABLE_SLOPE_FILTER(bool enable)l
extern _native void AMBIENT_SET_SLOPE_FILTER_PRECISE(int pram0, int pram1, int pram2)l
extern _native void AMBIENT_ENABLE_SLOPE_FILTER_PRECISE(int pram0)l
extern _native void AMBIENT_SET_BUMP_FILTER(int pram0, int pram1, int pram2)l
extern _native void AMBIENT_ENABLE_BUMP_FILTER(bool enable)l
extern _native void AMBIENT_SET_DISTANCE_FILTER(float dis1, float dis2)l
extern _native void AMBIENT_ENABLE_DISTANCE_FILTER(bool enable)l
extern _native void AMBIENT_SET_ELEVATION_FILTER(int pram0, int pram1)l
extern _native void AMBIENT_SET_QUADRANT_FILTER(int pram0, int pram1, int pram2, int pram3)l
extern _native void AMBIENT_ENABLE_QUADRANT_FILTER(bool enable)l
extern _native void AMBIENT_ENABLE_OFFSCREEN_FILTER(int pram0)l
extern _native void AMBIENT_ENABLE_MATERIAL_AT_POINT_FILTER(int pram0)l
extern _native32(0xB1609063) void _AMBIENT_SET_MATERIAL_AT_POINT_INCLUDES_FILTER(int pram0)l
extern _native void AMBIENT_ENABLE_MATERIAL_IN_AREA_INCLUDES_FILTER(int pram0, int pram1)l
extern _native void AMBIENT_SET_MATERIAL_IN_AREA_INCLUDES_FILTER(int pram0, int pram1, int pram2)l
extern _native const char* AMBIENT_ENABLE_MATERIAL_IN_AREA_EXCLUDES_FILTER(int p0, int p1)l
extern _native void AMBIENT_SET_MATERIAL_IN_AREA_EXCLUDES_FILTER(int pram0, int pram1, int pram2)l
extern _native32(0x30C67D05) void _AMBIENT_ENABLE_ELEVATION_IN_AREA_RANGE_FILTER(int pram0)l
extern _native32(0x0AC99007) void _AMBIENT_SET_ELEVATION_IN_AREA_RANGE_FILTER(int pram0, int pram1)l
extern _native32(0xC8B149B4) void _AMBIENT_ENABLE_ELEVATION_DERIVATIVE_AREA_FILTER(int pram0)l
extern _native32(0x54BD1C65) void _AMBIENT_SET_ELEVATION_DERIVATIVE_AREA_FILTER(int pram0, int pram1)l
extern _native void AMBIENT_SET_EXCLUSION_VOLUME(int pram0)l//_AMBIENT_SET_EXCLUSION_VOLUME_FILTER 0x90008899
extern _native int AMBIENT_GET_POINT(int pram0, int pram1)l
//////////////////////////////////
//GOH Object
/////////////////////////////////
extern _native void VERIFY_TYPE_COUNT(int pram0)l
extern _native void VERIFY_EVENT_COUNT(int pram0)l
extern _native int UNK_0x26011C78(int pram0)l
extern _native void UNK_0xC8C0C708(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5)l
extern _native void UNK_0x9A756A72(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5, int pram6)l
extern _native bool IS_LAYOUTREF_VALID(Layout layout)l
extern _native bool IS_OBJECT_VALID(Object obj)l
extern _native bool IS_ITERATOR_VALID(Iterator iterator)l
extern _native bool IS_PERS_CHAR_VALID(Actor persistentChar)l
extern _native bool IS_POPSET_VALID(int propset)l
extern _native bool IS_ZONE_VALID(int pram0)l
extern _native bool IS_CRIME_VALID(int crime)l
extern _native int GET_OBJECT_TYPE(Object obj)l
extern _native int GET_NUM_OBJECTS_OF_TYPE(int type)l
extern _native int GET_MAX_NUM_OBJECTS_OF_TYPE(int pram0)l
extern _native Layout FIND_NAMED_LAYOUT(const char* layoutName)l
extern _native const char* GET_ACTOR_NAME(Actor actor)l
extern _native const char* GET_OBJECT_NAME(Object object)l
extern _native const char* GET_LAYOUT_NAME(Layout layout)l
extern _native const char* GET_OBJECT_MODEL_NAME(Object object)l
extern _native const char* GET_POPULATION_SET_NAME(int p0)l
extern _native int GET_COVER_LOCATION_FROM_OBJECT(Object obj)l//_GET_COVER_LOCATION_FROM_OBJECT_REF 0x2CF0010F
extern _native const char* GET_GRINGO_FROM_OBJECT(Object obj)l//int
extern _native int GET_PROP_FROM_OBJECT(int pram0)l
extern _native Object GET_OBJECT_FROM_GRINGO(int gringo)l
extern _native Object GET_OBJECT_FROM_ACTOR(Actor actor)l
extern _native int GET_OBJECT_FROM_VOLUME(int pram0)l
extern _native Object GET_OBJECT_FROM_PERS_CHAR(Actor actor)l
extern _native int GET_OBJECT_FROM_SQUAD(int pram0)l
extern _native Object GET_OBJECT_FROM_CRIME(int crime)l
extern _native Object GET_OBJECT_FROM_PHYSINST(int physinst)l//0x550E178
extern _native Actor GET_ACTOR_FROM_OBJECT(Object obj)l
extern _native int GET_VOLUME_FROM_OBJECT(Object object)l
extern _native Actor GET_PERS_CHAR_FROM_OBJECT(Object object)l//0x24B2FFC
extern _native Iterator GET_ITERATOR_FROM_OBJECT(Object object)l
extern _native int GET_SQUAD_FROM_OBJECT(Object obj)l
extern _native Layout GET_LAYOUT_FROM_OBJECT(Object obj)l//0x51D6DA2C
extern _native int UNK_0x6B72661F(int pram0)l
extern _native int GET_CRIME_FROM_OBJECT(int pram0)l
extern _native Camera GET_CAMERA_FROM_OBJECT(Object obj)l
extern _native int UNK_0x50A7E334(int pram0)l
extern _native Layout CREATE_LAYOUT(const char* layoutName)l
extern _native Layout CREATE_MOBILE_LAYOUT(int unkValue)l
extern _native int CREATE_CORPSE_IN_LAYOUT(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5, int pram6, int pram7, int pram8, int pram9, int pram10)l
extern _native int CREATE_CORPSE_IN_LAYOUT_RANDOM(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5, int pram6, int pram7, int pram8, int pram9)l
extern _native int CREATE_CORPSE_VARIATION_IN_LAYOUT(int p0, int p1)l
extern _native int CREATE_CORPSE_VARIATION_IN_LAYOUT_RANDOM(int p0, int p1)l
extern _native int CREATE_COVER_LOCATION_IN_LAYOUT(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5, int pram6, int pram7, int pram8)l
extern _native int CREATE_POINT_IN_LAYOUT(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5, int pram6, int pram7)l
extern _native int CREATE_POINT_LIGHT_IN_LAYOUT(Layout layout, const char* pointLightName, vector3 position, float unk1, float unk2, float unk3, float unk4)l
extern _native int CREATE_VOLUME_IN_LAYOUT(Layout layout, char* volumeName, int unk, vector3 position, vector3 globalPosition, float x2, float y2, float z2)l
extern _native32(0x177A3843) int _CREATE_AGGREGATE_VOLUME_IN_LAYOUT(int pram0, int pram1)l
extern _native int CREATE_GRINGO_IN_LAYOUT(Layout layout, const char* idk, const char* animname, vector3 position, vector3 rotation)l
extern _native int CREATE_GRINGO_ON_OBJECT(Object obj, char* action, char* gringoPath, vector3 position, vector3 rotation)l
extern _native int CREATE_GRINGO_IN_LAYOUT_BY_ID(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5, int pram6, int pram7, int pram8)l
extern _native int CREATE_GRINGO_ON_OBJECT_BY_ID(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5, int pram6, int pram7, int pram8)l
extern _native int CREATE_PROPSET_IN_LAYOUT(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5, int pram6, int pram7, int pram8)l
extern _native Object CREATE_PROP_IN_LAYOUT(Layout layout, const char* propName, const char* fragmentPath, vector3 position, vector3 rotation, bool frozen)l
extern _native int CREATE_PROP_IN_LAYOUT_BY_ID(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5, int pram6, int pram7, int pram8, int pram9)l
extern _native int CREATE_COVER_PROP_IN_LAYOUT(int p0, int p1)l
extern _native int CREATE_SPAWN_POINT_IN_LAYOUT(int p0, int p1, int p2, int p3, float p4, float p5, float p6, float p7, float p8, float p9, float p10)l
extern _native int CREATE_PATH_IN_LAYOUT(int pram0, int pram1, int pram2)l
extern _native int CREATE_PATH_IN_LAYOUT_FROM_TABLE(int pram0, int pram1, int pram2)l
extern _native int CREATE_OBSTACLE_IN_LAYOUT(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5, int pram6, int pram7, int pram8, int pram9, int pram10)l
extern _native int CREATE_OBSTACLE_ON_OBJECT(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5, int pram6, int pram7, int pram8, int pram9, int pram10)l
extern _native int CREATE_SQUAD_IN_LAYOUT(Layout layout, const char* squadName)l
extern _native int CREATE_FORMATION_IN_LAYOUT(int pram0, int pram1, int pram2)l
extern _native int CREATE_CRIME_IN_LAYOUT(Layout layout)l
extern _native int CREATE_AI_SPEECH_PACKAGE_IN_LAYOUT(int pram0, int pram1)l
extern _native32(0xA936E73B) int _SET_LAYOUT_CONSIDER_AS_WHOLE(int pram0, int pram1)l
extern _native void RELEASE_LAYOUT_REF(Layout layout)l
extern _native void RELEASE_LAYOUT_OBJECTS(int pram0)l
extern _native void DESTROY_LAYOUT_OBJECTS(Layout layout)l
extern _native32(0x000079CB) int _FIXUP_TRANSFORMS(int pram0)l
extern _native32(0x3CD2C250) int _STORE_CURRENT_TRANSFORMS(int pram0)l
extern _native32(0x7EEC1F40) int _MAKE_CHILD_OBJECTS_RELATIVE(int p0, int p1, int p2)l
extern _native int TRANSFORM_OBJECT_RELATIVE(int pram0, int pram1)l
extern _native void MARK_OBJECT_FOR_AGGRESSIVE_CLEANUP(int pram0, int pram1)l
extern _native void RELEASE_OBJECT_REF(Object obj)l
extern _native void RELEASE_ACTOR(Actor actor)l
extern _native void RELEASE_VOLUME(int volume)l
extern _native void RELEASE_PERS_CHAR(int pram0)l
extern _native void DESTROY_VOLUME(int pram0)l
extern _native void DESTROY_ACTOR(Actor actor)l
extern _native void DESTROY_LAYOUT(Layout layout)l
extern _native void DESTROY_OBJECT(Object Object)l
extern _native void DESTROY_ITERATOR(Iterator iterator)l
extern _native void DESTROY_PERS_CHAR(Actor persistentChar)l
extern _native void DESTROY_POINT_LIGHT(int pram0)l
extern _native void DESTROY_POPULATION_SET(int pram0)l
extern _native void DESTROY_ZONE(int pram0)l
extern _native void DESTROY_CRIME(int crime)l
extern _native int GIVE_OBJECT_TO_ACTOR(Object obj, Actor actor)l
extern _native int UNK_0x2D160228(int pram0, int pram1)l
extern _native Object GET_OBJECT_OWNER(int pram0)l
extern _native32(0x86B0B004) void _EMPTY_GC(int pram0, int pram1)l
extern _native32(0x65C3D8F6) int _WAS_LAST_OBJECT_ALREADY_IN_GAME()l
extern _native Layout GET_AMBIENT_LAYOUT()l
extern _native int GET_ART_GRINGO_LAYOUT()l
extern _native Layout GET_GC_LAYOUT()l//garbage collection layout
extern _native int CREATE_OBJECTSET_IN_LAYOUT(Layout layout, Actor object, int unkValue, int unkValue2)l
extern _native bool IS_OBJECTSET_VALID(int pram0)l
extern _native int ADD_OBJECT_TO_OBJECTSET(Object obj, int objectset)l
extern _native int GET_OBJECTSET_SIZE(int pram0)l
extern _native Object GET_OBJECT_FROM_OBJECTSET(int objectset)l
extern _native int GET_OBJECTSET_FROM_OBJECT(Object object)l
extern _native32(0x50D39153) int _GET_OBJECT_FROM_OBJECTSET(int pram0, int pram1)l
extern _native bool IS_OBJECT_IN_OBJECTSET(int pram0, int pram1)l
extern _native void REMOVE_OBJECT_FROM_OBJECTSET(int pram0, int pram1)l
extern _native void CLEAN_OBJECTSET(int pram0)l
extern _native void DISBAND_OBJECTSET(int pram0)l
extern _native void DESTROY_OBJECTSET(int pram0)l
extern _native void SET_CORPSE_PERMANENT(int pram0, int pram1)l//int instead of void?
extern _native bool IS_POINT_LIGHT_VALID(int pointLight)l//0x44C07DA5
extern _native void SET_ENABLE_POINT_LIGHT(int pram0, int pram1)l
extern _native bool IS_OBJECT_IN_VOLUME(Object obj, int volume)l
extern _native int LOCATE_NAMED_POINT(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5)l//_LOCATE_OBJECT_OF_NAME 0xCB3F7DA5
extern _native Actor LOCATE_NAMED_ACTOR(float posX, float posY, float posZ, float maybeRadius, char* actorName, int alwaysZero)l//0xA36ED4A6
extern _native int LOCATE_NAMED_VOLUME(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5)l//_LOCATE_VOLUME_OF_NAME 0x6F513950
extern _native32(0x35C8FD4A) int _LOCATE_OBJECTS_IN_VOLUME(int pram0, int pram1, int pram2, int pram3)l
extern _native int UNK_0x0F701FF7(int pram0, int pram1, int pram2, int pram3)l
extern _native void SET_VOLUME_PARAMS(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5, int pram6, int pram7, int pram8, int pram9)l
extern _native void UNK_0xB104FF3E(int pram0, int pram1)l
extern _native int COPY_VOLUME(int pram0, int pram1, int pram2, int pram3)l
extern _native void SCALE_VOLUME(int pram0, int pram1)l
extern _native void SET_ACTOR_STAY_OUTSIDE_OF_VOLUME(int pram0, int pram1, int pram2, int pram3)l
extern _native void ADD_ACTOR_STAY_OUTSIDE_OF_VOLUME(int pram0, int pram1)l
extern _native void SET_ACTOR_STAY_WITHIN_VOLUME(int pram0, int pram1, int pram2, int pram3)l
extern _native void ADD_ACTOR_STAY_WITHIN_VOLUME(int pram0, int pram1)l
extern _native void CLEAR_ACTOR_STAY_WITHIN_VOLUME(int pram0)l
extern _native void SET_ACTOR_VOLUME_PARAMETERS(int pram0, int pram1, int pram2)l
extern _native void REMOVE_ACTOR_STAY_WITHIN_VOLUME(int pram0, int pram1)l
extern _native void REMOVE_ACTOR_STAY_OUTSIDE_OF_VOLUME(int pram0, int pram1)l
extern _native void ADD_CORPSE_RETAINMENT_VOLUME_OBJ(int pram0)l
extern _native void REMOVE_CORPSE_RETAINMENT_VOLUME_OBJ(int pram0)l
extern _native void ADD_CORPSE_REMOVAL_VOLUME_OBJ(int volume)l
extern _native void REMOVE_CORPSE_REMOVAL_VOLUME_OBJ(int volume)l
extern _native void ADD_CORPSE_PREVENT_INTERFERENCE_VOLUME_OBJ(int volume)l
extern _native void REMOVE_CORPSE_PREVENT_INTERFERENCE_VOLUME_OBJ(int pram0)l
extern _native void TOGGLE_COVER_PROPS(bool toggle)l
extern _native int TOGGLE_COVER_PROP(Object p0, int p1)l
extern _native int CREATE_ZONE_VOLUME(int pram0)l
extern _native32(0x9189EB8B) int _CREATE_VOLUME_SPAWNING_ZONE_FROM_VOLUME(int pram0)l
extern _native int CREATE_POPULATION_SET(int pram0)l
extern _native int CREATE_POPULATION_SET_IN_LAYOUT(int pram0, int pram1, int pram2)l
extern _native int CREATE_NAMED_POPULATION_SET(int pram0, int pram1)l
extern _native int CREATE_GATEWAY_IN_LAYOUT(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5, int pram6, int pram7, int pram8, int pram9)l
extern _native32(0x64BEDDEA) int _CREATE_GATEWAY_FROM_PARAMS(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5, int pram6, int pram7, int pram8, int pram9, int pram10, int pram11, int pram12, int pram13, int pram14, int pram15, int pram16, int pram17)l
extern _native void CREATE_GATEWAY_TYPE(int pram0, int pram1)l
extern _native int SNAP_ACTOR_TO_GRINGO(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5)l
extern _native32(0x6745191B) int _RMPTFX_EFFECT_START(int pram0, float pram1, float pram2, float pram3)l
extern _native32(0x276EFF8E) int _RMPTFX_EFFECT_START_AND_FADE_IN(int pram0, int pram1, int pram2, int pram3)l
extern _native32(0xE18028C1) int _RMPTFX_EFFECT_STOP(int pram0)l
extern _native32(0x7246F438) int _RMPTFX_EFFECT_STOP_AND_RESET(int pram0)l
extern _native32(0x1A59E608) int _RMPTFX_EFFECT_STOP_AND_FADE_OUT(int pram0)l
extern _native32(0x0AFC0B99) int _RMPTFX_RESET_ALL()l
extern _native32(0x547166A7) void _RMPTFX_RESET_IN_VOLUME(int pram0)l
extern _native32(0xF1F8AFCA) int _CREATE_RMPTFX_EFFECT_IN_LAYOUT(int actor, char* unk, char* unk2, vector3 position)l
extern _native32(0xFF8CBD07) int _CREATE_RMPTFX_EFFECT_ON_OBJECT(int pram0, const char* pram1, int pram2, int pram3, int pram4, int pram5, int pram6, int pram7)l
extern _native32(0x2A902148) int _CREATE_RMPTFX_EFFECT_ON_BONE(int unk1, const char* unk2, const char* bodyPart, Actor actorEmit, float x, float y, float z, Actor actorEmit2)l
extern _native32(0x39286DE5) int _CREATE_RMPTFX_EFFECT_ON_CURVE(int pram0, int pram1, int pram2, int pram3)l
extern _native32(0xD3A523FD) int _IS_RMPTFX_FINISHED(int pram0)l
extern _native32(0x1A4C98C1) int _RMPTFX_SCALE_EFFECT(int pram0, int pram1)l
extern _native32(0x21BCC0A9) int _RMPTFX_HIDE_EFFECT(int pram0)l
extern _native32(0x5B417C9C) int _RMPTFX_SHOW_EFFECT(int pram0)l
extern _native void START_RECORDING_SHOOT_EVENTS_FOR_ACTOR(int mySelf)l
extern _native void STOP_RECORDING_SHOOT_EVENTS_FOR_ACTOR(int pram0)l
extern _native int ADD_FORMATION_LOCATION(int pram0, int pram1)l
extern _native void GET_FORMATION_LOCATION(int pram0, int pram1, int pram2)l
extern _native int GET_NUM_FORMATION_LOCATIONS(int pram0)l
extern _native int GET_CRIME_POSITION(int pram0, int pram1)l
extern _native int GET_CRIME_TYPE(int crime)l
extern _native int GET_CRIME_BEGIN_TIMESTAMP(int pram0)l
extern _native int GET_CRIME_END_TIMESTAMP(int crime)l
extern _native int GET_CRIME_WITNESSED(int pram0)l
extern _native Actor GET_CRIME_CRIMINAL(int crime)l
extern _native Object GET_CRIME_VICTIM(int crime)l
extern _native int GET_CRIME_WORLD_REGION(int pram0)l
extern _native int GET_CRIME_FACTION(int pram0)l
extern _native int GET_CRIME_COUNTER(int crime)l
extern _native int IS_CRIME_TALLIED(int pram0)l
extern _native bool IS_CRIME_IN_PROGRESS(int crime)l
extern _native Object GET_CRIME_OBJECTSET(int crime)l
extern _native void SET_CRIME_OBJECTSET(int pram0, int pram1)l
extern _native int SET_CRIME_POSITION(int pram0, int pram1, int pram2, int pram3)l
extern _native void SET_CRIME_TYPE(int pram0, int pram1)l
extern _native void SET_CRIME_BEGIN_TIMESTAMP(int pram0, int pram1)l
extern _native void SET_CRIME_END_TIMESTAMP(int pram0, int pram1)l
extern _native void SET_CRIME_WITNESSED(int pram0, int pram1)l
extern _native void SET_CRIME_CRIMINAL(int pram0, int pram1)l
extern _native void SET_CRIME_VICTIM(int pram0, int pram1)l
extern _native void SET_CRIME_WORLD_REGION(int pram0, int pram1)l
extern _native void SET_CRIME_FACTION(int pram0, int pram1)l
extern _native void SET_CRIME_COUNTER(int pram0, int pram1)l
extern _native void SET_CRIME_TALLIED(int pram0, int pram1)l
extern _native void SET_CRIME_IN_PROGRESS(int crime, int pram1)l
extern _native Iterator CREATE_OBJECT_ITERATOR(Layout layout)l
extern _native int CREATE_NAMED_OBJECT_ITERATOR(int pram0, int pram1)l
extern _native Object START_OBJECT_ITERATOR(Iterator iterator)l
extern _native Object OBJECT_ITERATOR_NEXT(Iterator iterator)l
extern _native int OBJECT_ITERATOR_PREV(int pram0)l
extern _native Object OBJECT_ITERATOR_CURRENT(Iterator iterator)l
extern _native void OBJECT_ITERATOR_RESET(Iterator iterator)l
extern _native void ITERATE_ON_PARTIAL_NAME(int pram0, int pram1)l
extern _native void ITERATE_ON_PARTIAL_MODEL_NAME(int pram0, int pram1)l
extern _native void ITERATE_ON_OBJECT_TYPE(Iterator iterator, int objectType)l
extern _native int ITERATE_IN_AREA(int p0, float p1, float p2, float p3, float p4, float p5, float p6)l
extern _native void ITERATE_IN_SPHERE(int pram0, int pram1, int pram2, int pram3, int pram4)l
extern _native void ITERATE_IN_VOLUME(int pram0, int pram1)l
extern _native void ITERATE_EVERYWHERE(int pram0)l
extern _native void ITERATE_IN_LAYOUT(Iterator iterator, Layout layout)l
extern _native void ITERATE_IN_SET(Iterator iterator, IterationSet iterationSet)l
extern _native void ITERATE_IN_EVENT_TRAP(int pram0, int pram1)l
extern _native void ITERATE_IN_VOLUME_SET(int pram0, int pram1)l//_ITERATE_ON_TARGET 0x8BCB6B86
extern _native int GET_ITERATOR_PARENT(int pram0)l
extern _native int GET_NUM_ITERATOR_MATCHES(Iterator iterator)l
extern _native Object FIND_OBJECT_IN_OBJECT(Object obj, char* objectName)l
extern _native Object FIND_OBJECT_IN_LAYOUT(Layout layout, const char* objectName)l
extern _native Actor FIND_ACTOR_IN_LAYOUT(Layout layout, const char* actorName)l
extern _native int FIND_VOLUME_IN_LAYOUT(Layout layout, char* volumeName)l//0xAC830865
extern _native32(0xC9365FBC) void _CLEAR_NON_MISSION_OBJECTS_IN_SPHERE(int pram0, int pram1, int pram2, int pram3, int pram4)l
extern _native32(0xBB77E597) void _CLEAR_NON_MISSION_OBJECTS_IN_VOLUME(int volume, int type)l
extern _native int GET_OBJECT_POSITION(Object obj, vector3 * outCoords)l
extern _native int ROTATE_OBJECT_AROUND_AXIS(int pram0, int pram1, int pram2)l
extern _native int GET_OBJECT_AXIS(int pram0, int pram1, int pram2)l
extern _native int GET_OBJECT_RELATIVE_POSITION(int pram0, int pram1, int pram2, int pram3, int pram4)l
extern _native int GET_OBJECT_RELATIVE_OFFSET(int pram0, int pram1, int pram2, int pram3, int pram4)l
extern _native int GET_OBJECT_RELATIVE_ORIENTATION(int pram0, int pram1, int pram2, int pram3, int pram4)l
extern _native int GET_OBJECT_RELATIVE_ORIENTATION_IN_OBJECT_SPACE(int pram0, int pram1, int pram2, int pram3, int pram4)l
extern _native int PREPARE_CORPSE_FOR_ANIMAL_CONSUMPTION(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5)l
extern _native32(0x663F1464) int _GET_POSITION_OBJECT_RELATIVE(int pram0, int pram1, int pram2, int pram3, int pram4)l
extern _native int GET_OBJECT_ORIENTATION(Object obj, vector3 * outOrientation)l
extern _native float GET_OBJECT_HEADING(Object obj)l
extern _native int SET_OBJECT_POSITION(Object object, vector3 position)l
extern _native int SET_OBJECT_POSITION_ON_GROUND(Object Obj, vector3 Position)l
extern _native int SET_OBJECT_ORIENTATION(Object object, float x1, float y1, float z1)l
extern _native bool SNAP_OBJECT_TO_GROUND(Object point, float pram1, int pram2, int pram3)l
extern _native int GET_OBJECT_NAMED_BONE_POSITION(Actor actor, const char* bone, vector3* pos)l//might have to fix
extern _native int GET_OBJECT_NAMED_BONE_ORIENTATION(int pram0, int pram1, int pram2)l
extern _native int TELEPORT_OBJECT_TO_OBJECT(Object actor, int volume, vector3 position, vector3 rotation, int unkValue)l
extern _native bool IS_OBJECT_ATTACHED(Object obj)l
extern _native32(0x78B73E47) int _GET_OBJECT_ATTACHMENT(int pram0)l
extern _native Object GET_OBJECT_ATTACHED_TO(Object obj)l
extern _native Object ATTACH_OBJECTS(Object obj1, Object obj2, const char* locator, vector3 posOffset, vector3 rotOffset, int unk)l
extern _native int ATTACH_OBJECTS_NO_DRV(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5, int pram6, int pram7, int pram8)l
extern _native int ATTACH_OBJECTS_USING_LOCATOR(int pram0, int pram1, int pram2, int pram3, int pram4)l
extern _native int ATTACH_OBJECTS_CONTINUOUS(int pram0, int pram1, int pram2)l
extern _native int ATTACH_OBJECTS_PHYSICAL(int pram0, int pram1, int pram2, int pram3, int pram4)l
extern _native32(0x325F7E50) int _SET_ATTACHMENT_ROTATIONAL_CONSTRAINT(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5)l
extern _native bool IS_ATTACHMENT_VALID(int attachment)l
extern _native void REMOVE_OBJECT_ATTACHMENT(Object obj)l
extern _native void REMOVE_OBJECT_FROM_ATTACHMENT(int pram0)l
extern _native void REMOVE_ALL_OBJECT_ATTACHMENTS(int pram0)l
extern _native void SET_ATTACHMENT_LOCAL_ROTATION(Object attachment, float rotX, float rotY, float rotZ)l
extern _native void SET_ATTACHMENT_LOCAL_OFFSET(Object attachment, float x, float y, float z)l
extern _native void SET_ATTACHMENT_IGNORE_ROTATION(Object attachment, bool ignore)l
extern _native void REFERENCE_OBJECT(Object obj)l
extern _native void REFERENCE_ACTOR(Actor actor)l
extern _native void DEREFERENCE_OBJECT(Object obj)l
extern _native void DEREFERENCE_ACTOR(Actor actor)l
extern _native32(0xCBA75200) void _INIT_ACTOR_ENUM_PLAYER(int pram0, int pram1, int pram2, int pram3)l
extern _native32(0x88FD9623) void _INIT_ACTOR_ENUM_HUMAN(int pram0, int pram1, int pram2, int pram3)l
extern _native32(0x192973A0) void _INIT_ACTOR_ENUM_ANIMAL(int pram0, int pram1, int pram2, int pram3)l
extern _native32(0x4D42E285) void _INIT_ACTOR_ENUM_RIDEABLE_ANIMAL(int pram0, int pram1, int pram2, int pram3)l
extern _native32(0xE694F53A) void _INIT_ACTOR_ENUM_FLYING_ANIMAL(int pram0, int pram1, int pram2, int pram3)l
extern _native32(0x6D0B8619) void _INIT_ACTOR_ENUM_VEHICLE(int pram0, int pram1, int pram2, int pram3)l
extern _native32(0x807B9519) void _INIT_ACTOR_ENUM_TRAIN(int pram0, int pram1, int pram2, int pram3)l
extern _native32(0x1904CC1D) void _INIT_ACTOR_ENUM_DLC_PLAYER(int pram0, int pram1, int pram2, int pram3)l
extern _native32(0x1957B498) void _INIT_ACTOR_ENUM_DLC_HUMAN(int pram0, int pram1, int pram2, int pram3)l
extern _native32(0x10BD98C9) void _INIT_ACTOR_ENUM_DLC_ANIMAL(int pram0, int pram1, int pram2, int pram3)l
extern _native32(0x10BD98C9) void _INIT_ACTOR_ENUM_DLC_RIDEABLE_ANIMAL(int pram0, int pram1, int pram2, int pram3)l
extern _native32(0x10BD98C9) void _INIT_ACTOR_ENUM_DLC_FLYING_ANIMAL(int pram0, int pram1, int pram2, int pram3)l
extern _native32(0x10BD98C9) void _INIT_ACTOR_ENUM_DLC_VEHICLE(int pram0, int pram1, int pram2, int pram3)l
extern _native32(0x10BD98C9) void _INIT_ACTOR_ENUM_DLC_TRAIN(int pram0, int pram1, int pram2, int pram3)l
extern _native bool IS_ACTORENUM_DLC(int actorID)l//0xF2140DEE
extern _native bool UNK_0x9B903F45(int pram0)l
extern _native int UNK_0x16D1E1B4(int pram0)l
extern _native void UNK_0xC741F051(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5, int pram6)l
extern _native Actor CREATE_ACTOR_IN_LAYOUT(Layout layout, const char* actorName, eActor actorID, vector3 position, vector3 rotation)l
extern _native int CREATE_PLAYER_ACTOR_IN_LAYOUT(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5, int pram6, int pram7, int pram8, int pram9)l
extern _native int CREATE_PERS_CHAR_IN_LAYOUT(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5, int pram6)l
extern _native32(0xCCC0A3F3) int _CREATE_ACTOR_IN_LAYOUT_USING_VARIABLE_INDEX(int p0)l
extern _native Actor RESPAWN_PLAYER_ACTOR_IN_LAYOUT(Layout layout, Actor actor, const char* actorInLayout, eActor actorID, vector3 position, vector3 rotation, int unk)l
extern _native bool IS_ACTOR_INITED(Actor actor)l
extern _native int GET_ACTOR_ENUM(Actor actor)l
extern _native const char* GET_ACTOR_ENUM_STRING(Actor actor)l
extern _native int GET_ACTOR_ENUM_FROM_STRING(char* pram0)l
extern _native const char* GET_ACTOR_ENUM_STRING_FROM_ENUM(int pram0)l//int
extern _native32(0xB50E95D7) int _GET_NUM_ACTOR_ENUM_VARIATIONS(Actor actor)l
extern _native int GET_ACTOR_ENUM_FACTION(Actor actor)l
extern _native32(0x7AB17813) void _SET_ACTOR_ENUM_VARIATION(Actor actor, int outfitID)l//_SET_ACTOR_OUTFITS
extern _native32(0x95FBA0B0) void _SET_PLAYER_TO_ENUM(Actor actor, int value)l
extern _native void TURN_ACTOR_INTO_ZOMBIE(Actor actor, int unk)l
extern _native32(0x12A86E9D) void _SET_ACTOR_ENUM_HARD_LOCK_AQUIRE_BONE_CASUAL(Actor actor, const char* bone)l
extern _native32(0x5613615B) void _SET_ACTOR_ENUM_HARD_LOCK_AQUIRE_BONE(Actor actor, const char* bone)l
extern _native int GET_CURRENT_ACTOR_ENUM_VARIATION(Actor actor)l
extern _native int REQUEST_ASSET(const char* assetDir, eAssetType assetType)l
extern _native int GET_ASSET_ID(const char* assetPath, eAssetType assetType)l
extern _native int REMOVE_ASSET(const char* assetName, eAssetType assetType)l
extern _native32(0x55E6227E) int _GET_TYPE_ID_USING_ACTOR_ENUM(int pram0, int pram1)l
extern _native const char* GET_ASSET_NAME(int pram0, int pram1)l
extern _native32(0x214AFB8C) bool _IS_ASSET_VALID(int asset)l//_IS_TYPE_ID_VALID 0x214AFB8C
extern _native32(0xFDF42AAC) int _IS_ASSET_VALID_BY_STRING(int pram0, int pram1)l//_IS_TYPE_ID_VALID_BY_STRING 0xFDF42AAC
extern _native int GET_CORPSE_ACTOR_ENUM(int pram0)l
extern _native int GET_PREVIOUS_ACTOR_FROM_CORPSE(int p0, int p1)l
extern _native int REQUEST_ARTICULATED_CORPSE(int pram0)l
extern _native int REQUEST_FIXED_CORPSE(int corpse, int pram1)l
extern _native32(0xCEC355CE) void _SET_OBJECT_COLLIDES_WITH_WORLD(int pram0, int pram1)l
extern _native32(0x418A22D5) void _SET_OBJECT_COLLIDES_WITH_MOVABLES(int pram0, int pram1)l
extern _native32(0x77403213) void _SET_OBJECT_COLLIDES_WITH_OBJECT(int pram0, int pram1, int pram2)l
extern _native void SET_OBJECT_COLLIDE_WITH_WORLD(int pram0, int pram1)l//0x601FC9F4
extern _native void SET_OBJECT_COLLIDE_WITH_MOVABLES(int pram0, int pram1)l//0x05D69EA6
extern _native void SET_OBJECT_COLLIDE_WITH_OBJECT(int pram0, int pram1, int pram2)l//0x9AC1CA75
extern _native int SET_PROP_AI_OBSTACLE_ENABLED(int pram0, int pram1)l
extern _native int GET_CURVE_FROM_OBJECT(Object obj)l
extern _native32(0xDF93BD7C) void _DESTROY_CURVE(int pram0)l
extern _native void DESTROY_CAMERA(Camera camera)l
extern _native void DESTROY_CAMERA_SHOT(Actor actor)l
extern _native int CREATE_WORLD_SECTOR(int pram0, int pram1)l
extern _native int IS_WORLD_SECTOR_LOADED(int pram0)l
extern _native void MARK_REGION_READY(int pram0)l
extern _native32(0xA5F229C9) int _GET_WORLD_CHILD_OBJECT(int pram0, int pram1, int pram2)l
extern _native int UNK_0x0F146D2C(int p0)l
extern _native int UNK_0xF46FC138()l
extern _native32(0x03B2D067) int _SAVE_POP_SET_FOR_BIRDS_SPAWNING_FROM_TREES(int pram0)l
extern _native void SET_TOWN_VOLUME_FOR_AMBIENT_PEDS(int pram0)l
extern _native32(0xC1195126) int _SAVE_POP_SET_FROM_HUMANS_SPAWNING_IN_TOWN(int pram0)l
extern _native32(0x00CDD849) int _SAVE_POP_SET_FROM_HUMANS_SPAWNING_IN_TOWN_CONVERSATION_FULL(int pram0)l
extern _native32(0x6138B1B8) int _SAVE_POP_SET_FROM_HUMANS_SPAWNING_IN_TOWN_CONVERSATION_RESPONSE(int pram0)l
extern _native void SET_AGRESSIVE_EVENT_TOWN_BBX(int p0)l//int not void??
extern _native void SET_AGRESSIVE_EVENT_TIME_RANGE()l//int not void??
extern _native void SET_AGRESSIVE_EVENT_LOOP()l//int not void??
extern _native void SET_AGRESSIVE_EVENT_ON(int value)l
extern _native void SET_TOWN_DENSITY(int pram0)l
extern _native void SET_WEATHER_POP_DENSITY(int pram0, int pram1)l
extern _native void SET_SPAWN_PEDS_ON_SIDEWALK(bool pram0)l
//////////////////////////////////
//Vehicles
/////////////////////////////////
extern _native Vehicle GET_ACTOR_MOST_RECENT_VEHICLE(Actor actor)l
extern _native bool IS_ACTOR_ON_TRAIN(Actor actor, int unk)l
extern _native bool IS_ACTOR_ON_BOAT(Actor actor)l
extern _native bool IS_ACTOR_VEHICLE(Actor actor)l
extern _native bool IS_ACTOR_DRAFT_VEHICLE(Actor actor)l
extern _native bool IS_ACTOR_DRIVING_VEHICLE(Actor actor)l
extern _native bool IS_ACTOR_JACKING_VEHICLE(Actor actor)l
extern _native bool IS_ACTOR_INSIDE_VEHICLE(Actor actor)l
extern _native bool IS_ACTOR_RIDING_VEHICLE(Actor actor)l
extern _native Vehicle GET_VEHICLE(Actor actor)l
extern _native int GET_ACTOR_VEHICLE_STATE(int pram0, int pram1, int pram2)l
extern _native int GET_NUM_DRAFTED_ACTORS(Actor actor)l
extern _native bool SET_ACTOR_IN_VEHICLE(Actor actor, Actor vehicle, int seatID)l
extern _native Actor GET_DRAFT_ACTOR(int unk, Actor actorDraft)l
extern _native bool IS_ACTOR_DRAFTED(Actor actor)l
extern _native Actor GET_ACTOR_DRAFTED_TO(int pram0)l
extern _native bool IS_SEAT_OCCUPIED(Actor vehicle, int seatID)l
extern _native Actor GET_ACTOR_IN_VEHICLE_SEAT(Vehicle Veh, int SeatID)l
extern _native int GET_NUM_AVAILABLE_SEATS(Vehicle vehcile)l//_GET_NUM_SEATS_AVAILABLE 0x3ACE659E
extern _native int GET_NUM_OCCUPIED_SEATS(Vehicle vehicle)l//_GET_NUM_SEATS_OCCUPIED 0xF0354E46
extern _native bool ENABLE_VEHICLE_SEAT(Actor Vehicle, int SeatId, bool Enable)l
extern _native void STOP_VEHICLE(Vehicle vehicle)l
extern _native void START_VEHICLE(Vehicle vehicle)l
extern _native32(0xB12584C8) int _ACCESORIZE_VEHICLE_HORSES(int pram0, int pram1)l
extern _native32(0xD85CA776) int _GET_NUM_DRAFT_SLOTS(Actor actor)l
extern _native int ATTACH_DRAFT_TO_VEHICLE(Actor actorDraft, Vehicle vehicle, int draft, bool attach)l
extern _native void DETACH_DRAFT_FROM_VEHICLE_BY_ACTOR(int p0, int p1, int p2, int p3)l
extern _native void DETACH_DRAFT_FROM_VEHICLE_BY_INDEX(int p0)l
extern _native int TRAIN_CREATE_NEW_TRAIN(int pram0, int pram1, int pram2)l
extern _native void TRAIN_DESTROY_TRAIN(int pram0)l
extern _native void TRAIN_RELEASE_TRAIN(int pram0, int pram1)l
extern _native bool TRAIN_IS_VALID(int train)l
extern _native32(0xA7A672FA) void _TRAIN_ADD_NEW_TRAIN_CAR_FROM_ENUM(int train, eActor trainID)l
extern _native int TRAIN_GET_VELOCITY(int pram0)l
extern _native void TRAIN_SET_TARGET_POS(int pram0, int pram1)l
extern _native void TRAIN_SET_SPEED(float train)l
extern _native void TRAIN_SET_TARGET_SPEED(int train, float speed)l
extern _native void TRAIN_SET_MAX_ACCEL(int pram0, int pram1)l
extern _native void TRAIN_SET_MAX_DECEL(int pram0, int pram1)l
extern _native void TRAIN_SET_ENGINE_ENABLED(int pram0, int pram1)l
extern _native int TRAIN_GET_NUM_CARS(int pram0)l
extern _native void TRAIN_SET_POSITION_DIRECTION(int train, vector3 position, vector3 offsets)l
extern _native void TRAIN_SET_POSITION_DIRECTION_PRECISELY(int pram0, int pram1, int pram2, int pram3)l
extern _native void TRAIN_SET_FX(int pram0)l
extern _native32(0x1440C806) void _TRAIN_PLAY_WHISTLE(int pram0, int pram1)l
extern _native void TRAIN_ENABLE_VISUAL_DEBUG(int pram0)l
extern _native void TRAIN_DESTROY_CAR(int pram0, int pram1)l
extern _native int TRAIN_GET_LOD_LEVEL(int pram0)l
extern _native void TRAIN_FORCE_HIGH_LOD(int pram0, int pram1)l
extern _native int TRAIN_GET_CAR(int pram0, int pram1)l
extern _native void TRAIN_SET_PARTICLE_EFFECTS_ENABLED(int pram0, int pram1, int pram2)l
extern _native32(0xADE865AE) void _TRAIN_SET_AUTOPILOT_ENABLED(int pram0, int pram1)l
extern _native32(0xADE865AE) void _TRAIN_SET_AUDIO_ENABLE(int pram0)l
extern _native int TRAIN_SET_JUNCTION_STATE(int pram0, int pram1, int pram2)l
extern _native void TRAIN_GET_CURVE_NETWORK_POINT(int pram0, int pram1, int pram2)l
extern _native int TRAIN_GET_NEAREST_POI_DISTANCE(int pram0)l
extern _native void TRAIN_GET_POSITION(int pram0, int pram1)l
extern _native void SET_BOAT_EXTRA_STEER(int pram0, int pram1)l
extern _native void SET_VEHICLE_ENGINE_RUNNING(Actor Vehicle, bool Running)l
extern _native int IS_VEHICLE_ENGINE_RUNNING(int pram0)l
extern _native void SET_VEHICLE_ALLOWED_TO_DRIVE(Actor vehicle, bool allowed)l
extern _native void IS_VEHICLE_ALLOWED_TO_DRIVE(int pram0)l
extern _native void SET_VEHICLE_PASSENGERS_ALLOWED(Actor actor, bool allowed)l
extern _native void SET_VEHICLE_EJECTION_ENABLED(int pram0, int pram1)l
extern _native void VEHICLE_SET_HANDBRAKE(Actor Vehicle, bool Handbreak)l
extern _native int IS_ANY_VEHICLE_WHEEL_DETACHED(int pram0, int pram1, int pram2)l
extern _native int GET_VEHICLE_WHEEL_COUNT_INITIAL(Actor actor)l
extern _native bool GET_VEHICLE_WHEEL_COUNT_CURRENT(Actor vehicle)l
//////////////////////////////////
//Event
/////////////////////////////////
extern _native bool IS_EVENT_VALID(int pram0)l
extern _native int GET_EVENT_FROM_OBJECT(Object obj)l
extern _native Object GET_OBJECT_FROM_EVENT(int pram0)l
extern _native int COPY_EVENT(int event, Layout layout)l
extern _native Layout GET_EVENT_LAYOUT()l
extern _native int GET_EVENT_TYPE(int pram0)l
extern _native Object GET_EVENT_TARGET_AS_OBJECT(int event)l
extern _native int GET_EVENT_TARGET_AS_PHYSINST(int pram0)l
extern _native Object GET_EVENT_PERPETRATOR(Actor actor)l
extern _native32(0x17CF885F) int _ADD_EVENT_RESPONSE(int pram0, int pram1, int pram2, int pram3)l
extern _native32(0x8DF144C2) int _ADD_RANGED_EVENT_RESPONSE(int pram0, int pram1, int pram2, int pram3, int pram4)l
extern _native int REMOVE_EVENT_RESPONSE(int pram0, int pram1, int pram2)l
extern _native void RANGED_EVENT_RESPONSE_INIT_COMPLETE()l
extern _native void REGISTER_FOR_CREATION_EVEN(int pram0)l
extern _native int GET_EVENT_TIME(int event)l
extern _native32(0xBC58F1EA) IterationSet _GET_OBJECT_SET_FOR_EVENT_TYPE(int setId)l//_GET_ITERATION_SET what fox and roulette had
extern _native int CREATE_EVENT_TRAP(int pram0, int pram1, int pram2)l
extern _native void EVENT_TRAP_ON_VOLUME(int pram0, int pram1)l
extern _native int EVENT_TRAP_ON_SPHERE(int p0, float p1, float p2, float p3, float p4)l
extern _native void EVENT_TRAP_ON_PERPETRATOR(int pram0, int pram1)l
extern _native void EVENT_TRAP_ON_TARGET(int pram0, int pram1)l
extern _native void EVENT_TRAP_ON_OWNER(int pram0, int pram1)l
extern _native void EVENT_TRAP_STORE_EVENTS(int pram0, int pram1)l
extern _native void EVENT_TRAP_CLEAR_EVENTS(int pram0)l
extern _native bool EVENT_TRAP_SUCCESSFUL_TRAP(Object object)l
extern _native void EVENT_TRAP_CLEAR_TRAP_FLAG(int pram0)l
extern _native int GET_NUM_EVENT_RESPONSES()l
extern _native int GET_EVENT_RESPONSE_ID(int event)l
extern _native int GET_EVENT_FOR_RESPONSE(int pram0)l
//////////////////////////////////
//Riding
/////////////////////////////////
extern _native void SET_MOST_RECENT_MOUNT(int pram0, int pram1)l
extern _native Actor GET_MOST_RECENT_MOUNT(Actor actor)l
extern _native int GET_MOST_RECENT_RIDER(int pram0)l
extern _native bool IS_ACTOR_HORSE(Actor actor)l
extern _native bool IS_ACTOR_MULE(Actor actor)l
extern _native bool IS_ACTOR_RIDING(Actor actor)l
extern _native int IS_ACTOR_RIDING_AND_IN_SADDLE(int pram0)l
extern _native int IS_ACTOR_MOUNTED(int pram0)l
extern _native Actor GET_RIDER(Actor actor)l
extern _native Actor GET_MOUNT(Actor actor)l
extern _native void SET_MOUNTS_AS_PASSENGER(int pram0, int pram1)l
extern _native int ACTOR_MOUNT_ACTOR(Actor actorWhoMount, Actor actorToMount)l
extern _native int REMOVE_HORSE_ACCESSORY(Actor horse, int accessory)l
extern _native int DOES_HORSE_HAVE_ACCESSORY(int pram0, int pram1)l
extern _native int ACCESSORIZE_HORSE(Actor actor, int unk)l
extern _native void HORSE_ENABLE_AUTO_JUMP_FOR_AI_RIDERS(int pram0, int pram1)l
extern _native void HORSE_AUTO_JUMP_ENABLED_FOR_AI_RIDERS(int pram0, int pram1)l
extern _native int HORSE_ADD_REPULSION_EXCLUSION_VOLUME(int pram0)l
extern _native int HORSE_REMOVE_REPULSION_EXCLUSION_VOLUME(int pram0)l
extern _native int HORSE_SET_CURR_FRESHNESS(Actor actorHorse, int freshness)l
extern _native int HORSE_GET_CURR_FRESHNESS(int pram0)l
extern _native int HORSE_LOCK_FRESHNESS(Actor actorHorse)l
extern _native int HORSE_UNLOCK_FRESHNESS(Actor actorHorse)l
extern _native void HORSE_SET_INFINITE_FRESHNESS_CHEAT(bool activate)l
//////////////////////////////////
//Prop
/////////////////////////////////
extern _native int GET_PHYSINST_FROM_OBJECT(Object object)l
extern _native32(0x6517FF1B) int _GET_NEW_PROP_IN_SPHERE(int pram0, int pram1, int pram2, int pram3, int pram4)l
extern _native bool IS_PROP_FIXED(int pram0)l
extern _native void SET_PROP_FIXED(int pram0, int pram1)l
extern _native int REMOVE_PHYSINST(int pram0)l
extern _native int GET_CENTER_OF_GRAVITY(int pram0, int pram1)l
extern _native bool HAS_PROP_BEEN_DAMAGED(Object obj)l
extern _native float GET_PROP_HEALTH(Object obj)l
extern _native void SET_PROP_HEALTH(int pram0, int pram1)l
extern _native void RESET_PROPS_IN_WORLD()l
extern _native void RESET_PROPS_IN_VOLUME(int pram0, int pram1)l
extern _native void RESET_PROP(int pram0)l
extern _native void SET_PROP_TARGETABLE(int pram0, int pram1, int pram2)l
extern _native void SET_PROP_TARGETABLE_ACQUISITION_RADIUS(int pram0, int pram1)l
extern _native void SET_PROP_TARGETABLE_TARGET_BOX_SIZE(int pram0, int pram1, int pram2)l
extern _native void SET_PROP_TARGETABLE_SCORE_BIAS(int pram0, int pram1)l
extern _native void SET_PROP_TARGETABLE_AS_ENEMY(int pram0, int pram1)l
extern _native void SET_PROP_CAUSE_ARM_UP(int p0, int p1)l//int not void??
extern _native bool IS_PROP_STREAMED_IN(Object prop)l
extern _native bool GRAVE_IS_DUG_UP(int p0, int p1, int p2, int p3, int p4, int p5)l
extern _native void GRAVE_SET_DUG_UP(int pram0, int pram1)l
extern _native int GET_GRAVE_FROM_OBJECT(int pram0)l
extern _native int PLAY_SIMPLE_PROP_ANIMATION(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5)l
extern _native void SET_DRAW_OBJECT(int pram0, int pram1)l
extern _native int GET_DRAW_OBJECT(int pram0)l
extern _native32(0x375A33F0) bool _FRAGMENT_IS_VARIABLE_MESH_ENABLED(int pram0, int pram1)l
extern _native32(0x8287F8B3) bool _FRAGMENT_ENABLE_VARIABLE_MESH(int pram0, int pram1, int pram2)l//disables body parts but not all just on models that have toggle body parts
extern _native32(0x4BCFADB1) int _FRAGMENT_REMAP(const char* OriginalFragment, const char* ChangeToThisFragment)l//seems to work with world objects etc but not player model?
extern _native32(0x6D555332) int _CLEAR_FRAGMENT_REMAP(int pram0)l
//////////////////////////////////
//Curve
/////////////////////////////////
extern _native int ENABLE_CURVE(int pram0, int pram1)l
extern _native int ARE_CURVES_IN_RANGE(int pram0, int pram1, int pram2, int pram3, int pram4)l
extern _native int START_CURVE_QUERY(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5, int pram6, int pram7, int pram8)l//_CREATE_CURVE_QUERY_IN_LAYOUT 0xE018669
extern _native int GET_CURVE_BY_NAME(int pram0, int pram1)l
extern _native bool IS_CURVE_QUERY_VALID(int pram0)l
extern _native int GET_NUM_POINTS_IN_CURVE_QUERY(int pram0)l
extern _native int GET_NUM_CURVES_IN_CURVE_QUERY(int pram0)l
extern _native32(0xE531DCAE) int _GET_CURVE_POINT(int pram0, int pram1, int pram2)l
extern _native32(0xB4D1D8A3) int _GET_CURVE_FROM_CURVE_QUERY(int pram0, int pram1)l
extern _native32(0xBD4E48A6) int _GET_CURVE_FROM_CURVE_QUERY_USING_POINT_INDEX(int pram0, int pram1)l
extern _native32(0x90B514B9) int _GET_CLOSEST_POINT_TO_CURVE_IN_QUERY(int pram0, int pram1, int pram2)l
extern _native void REMOVE_CURVE_FROM_CURVE_QUERY_USING_CURVE(int pram0, int pram1)l
extern _native32(0x04D89A35) void _TRAVEL_DISTANCE_ON_CURVE_FROM_CURVE_POINT(int pram0, int pram1, int pram2, int pram3, int pram4)l
extern _native void UNK_0x19D652F9(int pram0, int pram1, int pram2, int pram3)l
extern _native32(0x39DA0B3A) int _CALCULATE_CURVE_DISTANCE_BY_STEP_SIZE(int pram0, int pram1, int pram2, int pram3)l
extern _native32(0x49D2C1DA) int _CALCULATE_CURVE_DISTANCE_BY_SUBDIVISION_COUNT(int pram0, int pram1, int pram2, int pram3)l
extern _native void RELEASE_CURVE(int curve)l
extern _native int GET_CURVE_TYPE(int pram0)l
extern _native const char* GET_CURVE_NAME(int curve)l
extern _native void GET_CURVE_POINT(int pram0, int pram1, int pram2, int pram3)l
extern _native void SET_CURVE_ACTIVE(int pram0, int pram1)l
extern _native void SET_CURVE_WEIGHT(int pram0, int pram1)l
extern _native int CURVE_NETWORK_POINT_GET_DISTANT_POINT(int p0, int p1, int p2)l
//////////////////////////////////
//Social Club
/////////////////////////////////
extern _native void UI_CHALLENGE_CREATE(int pram0, int pram1, int pram2)l
extern _native void UI_CHALLENGE_SET_DESCRIPTION(int pram0, int pram1)l
extern _native void UI_CHALLENGE_SET_TITLE_TEXTURE(int pram0, int pram1)l
extern _native void UI_CHALLENGE_SET_PROGRESS(int pram0, int pram1, int pram2, int pram3, int pram4)l
extern _native void UI_CHALLENGE_SET_PROGRESS_DETAIL(int pram0, int pram1)l
extern _native void UI_CHALLENGE_SET_TROPHY_TYPE(int pram0, int pram1)l
extern _native void UI_CHALLENGE_SET_OBJECTIVE(int pram0, int pram1, int pram2)l
extern _native void UI_CHALLENGE_SET_OBJECTIVE_STYLE(int pram0, int pram1, int pram2)l
extern _native void UI_CHALLENGE_SET_OBJECTIVE_STYLE_B(int pram0, int pram1, int pram2)l
extern _native void UI_CHALLENGE_SET_COLUMN_HEADER(int pram0, int pram1, int pram2)l
extern _native void UI_CHALLENGE_SET_TIME_HEADER(int pram0, int pram1)l
extern _native void UI_CHALLENGE_SET_TIME_INFO(int pram0, int pram1, int pram2)l
extern _native void UI_CHALLENGE_MAKE_CURRENT(int pram0)l
//////////////////////////////////
//Shop
/////////////////////////////////
extern _native void SHOP_CLEAR()l
extern _native void SHOP_REFRESH(int pram0)l
extern _native void SHOP_SET_PLAYER_BANK(int pram0)l
extern _native int SHOP_ADD_ITEM(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5, int pram6)l
extern _native void SHOP_SET_ITEM_QUANTITY(int pram0, int pram1)l
extern _native int SHOP_GET_ITEM_QUANTITY(int pram0)l
extern _native void SHOP_SET_ITEM_PURCHASE_PRICE(int pram0, int pram1)l
extern _native int SHOP_GET_ITEM_PURCHASE_PRICE(int pram0)l
extern _native int SHOP_GET_ITEM_SELL_PRICE(int pram0)l
extern _native void SHOP_SET_ITEM_BLOCKED(int pram0, int pram1)l
extern _native bool SHOP_IS_ITEM_BLOCKED(int pram0)l
extern _native int SHOP_GET_ITEM_MISC_FLAG(int pram0)l
extern _native bool SHOP_IS_SELL_SELECTED()l
extern _native void SHOP_SET_CURRENT_TAB(int pram0)l
extern _native void SHOP_LOCK_INPUT(int pram0)l
extern _native void SATCHEL_SET_ENABLED(bool enabled)l
extern _native void SATCHEL_TOGGLE_NO_PAUSE_OUTFIT(int pram0)l
extern _native int SATCHEL_CREATE_OUTFIT(int pram0, int pram1, int pram2)l
extern _native void SATCHEL_SET_OUTFIT_STATE(int pram0, int pram1)l
extern _native int SATCHEL_GET_OUTFIT_STATE(int pram0)l
extern _native void SATCHEL_SET_OUTFIT_TEXTURE(uint hash, int pram1)l
extern _native void SATCHEL_ALLOW_OUTFIT_CHANGE(int pram0)l
extern _native void SATCHEL_SET_CURRENT_OUTFIT(int pram0)l
//////////////////////////////////
//Stat
/////////////////////////////////
extern _native void CREATE_STAT(int pram0, int pram1, int pram2, int pram3)l
extern _native void HIDE_STAT(int pram0, int pram1)l
extern _native void UPDATE_STAT(int pram0, int pram1, int pram2)l
extern _native void ENABLE_JOURNAL_REPLAY(int pram0)l
extern _native void SET_JOURNAL_INFO_LABEL(int pram0, int pram1)l
extern _native32(0x5545C218) int _GET_SAG_PLAYER_STAT_FLOAT(int pram0)l
extern _native32(0xE623B382) int _GET_SAG_PLAYER_STAT_INT(int pram0)l
extern _native32(0x2104B1C0) void _SET_SAG_PLAYER_STAT_FLOAT(int pram0, int pram1)l
extern _native32(0xF1A723D0) void _SET_SAG_PLAYER_STAT_INT(int pram0, int pram1)l
extern _native int GET_NUM_KILLS_LAST_DEADEYE()l
//////////////////////////////////
//Journal
/////////////////////////////////
extern _native void SET_EXCLUSIVE_JOURNAL_ID(int pram0)l
extern _native void RESET_EXCLUSIVE_JOURNAL_ID()l
extern _native void TOGGLE_COOP_JOURNAL_UI(int pram0)l
extern _native void TOGGLE_JOURNAL_UI(int pram0, int pram1)l
extern _native int GET_JOURNAL_ENTRY(int pram0)l
extern _native int CREATE_JOURNAL_ENTRY(int pram0, int pram1, int pram2, int pram3)l
extern _native int CREATE_JOURNAL_ENTRY_BY_HASH(int pram0, int pram1, int pram2, int pram3)l
extern _native int IS_JOURNAL_ENTRY_IN_LIST(int pram0, int pram1)l
extern _native int GET_NUM_JOURNAL_ENTRIES_IN_LIST(int pram0)l
extern _native int GET_JOURNAL_ENTRY_IN_LIST(int pram0, int pram1)l
extern _native void PREPEND_JOURNAL_ENTRY(int pram0, int pram1)l
extern _native int APPEND_JOURNAL_ENTRY(int p0, int p1, int p2, int p3)l
extern _native void REMOVE_JOURNAL_ENTRY(int pram0, int pram1)l
extern _native void CLEAR_JOURNAL_ENTRY(int journalEntry)l
extern _native void PREPEND_JOURNAL_ENTRY_DETAIL(int pram0, int pram1, int pram2, int pram3, int pram4)l
extern _native void APPEND_JOURNAL_ENTRY_DETAIL(int pram0, int pram1, int pram2, int pram3, int pram4)l
extern _native void CLEAR_JOURNAL_ENTRY_DETAIL_LIST(int pram0, int pram1)l
extern _native int GET_JOURNAL_ENTRY_NUM_DETAILS(int pram0)l
extern _native int GET_JOURNAL_ENTRY_DETAIL_HASH_BY_INDEX(int pram0, int pram1)l
extern _native int GET_JOURNAL_ENTRY_DETAIL_STYLE_BY_HASH(int pram0, int pram1)l
extern _native void SET_JOURNAL_ENTRY_DETAIL_STYLE(int pram0, int pram1, int pram2, int pram3)l
extern _native void SET_JOURNAL_ENTRY_DETAIL_STYLE_BY_HASH(int pram0, int pram1, int pram2, int pram3)l
extern _native bool IS_JOURNAL_ENTRY_TARGETED(int journalEntry)l
extern _native int GET_JOURNAL_ENTRY_TYPE(int pram0)l
extern _native int IS_JOURNAL_ENTRY_UPDATED(int pram0)l
extern _native int GET_JOURNAL_ENTRY_MISC_FLAG(int pram0)l
extern _native int GET_TARGETED_JOURNAL_ENTRY()l
extern _native void TARGET_JOURNAL_ENTRY(int journalEntry)l
extern _native void SET_JOURNAL_ENTRY_UPDATED(int pram0, int pram1)l
extern _native void SET_JOURNAL_ENTRY_TROPHY(int pram0, int pram1)l
extern _native void DEACTIVATE_JOURNAL_ENTRY(int pram0, int pram1)l
extern _native void SET_JOURNAL_ENTRY_PROGRESS(int pram0, int pram1, int pram2, int pram3)l
extern _native int GET_JOURNAL_ENTRY_PROGRESS(int pram0)l
extern _native void SET_JOURNAL_ENTRY_DISALLOW_TRACKING(int pram0, int pram1)l
extern _native int GET_JOURNAL_ENTRY_DISALLOW_TRACKING(int pram0)l
extern _native void SET_JOURNAL_ENTRY_CURRENT_OBJECTIVE(int pram0, int pram1, int pram2)l
extern _native int GET_LAST_NOTE_OBJECTIVE()l
extern _native int APPEND_JOURNAL_NOTE(int pram0, int pram1, int pram2)l
//////////////////////////////////
//Misc
/////////////////////////////////
extern _native int CREATE_OBJECT_LOCATOR(int pram0, int pram1)l
extern _native32(0xB514ECA7) int _ATTACH_LOCATOR_TO_OBJECT_BONE(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5, int pram6, int pram7, int pram8)l
extern _native32(0xE25F407D) int _ATTACH_LOCATOR_TO_FRAGMENT_LOCATOR(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5, int pram6, int pram7, int pram8)l
extern _native32(0xEB33480A) int _ATTACH_LOCATOR_TO_OBJECT(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5, int pram6, int pram7)l
extern _native32(0x88F7432C) int _GET_LOCATOR_LOCAL_ROT(int pram0, int pram1)l
extern _native32(0x04507DBC) int _GET_LOCATOR_LOCAL_POS(int pram0, int pram1)l
//////////////////////////////////
//Object
/////////////////////////////////
extern _native32(0x7080E24A) int _ROTATE_OBJECT_UPRIGHT(int pram0, int pram1, int pram2)l
//0x1D7845B7
//////////////////////////////////
//Leash
/////////////////////////////////
extern _native int CREATE_LEASH_OBJECT(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5, int pram6, int pram7, int pram8, int pram9, int pram10, int pram11, int pram12, int pram13, int pram14)l
extern _native int LEASH_CONSTRAIN(int pram0)l
extern _native int LEASH_RESTART(int pram0)l
extern _native int LEASH_SET_CONSTRAINT_LENGTH(int pram0, int pram1)l//_ADJUST_CONSTRAIN_LENGTH 0x7F190CA3
extern _native int LEASH_SET_LEASH_LENGTH(int pram0, int pram1)l//_ADJUST_ROPE_LENGTH 0x14BEC6F5
extern _native int LEASH_RELEASE_CONSTRAINT(int pram0)l
extern _native int LEASH_ATTACH_TO_WORLD(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5, int pram6, int pram7)l
extern _native int LEASH_ATTACH_TO_OBJECT(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5, int pram6, int pram7, int pram8, int pram9)l
extern _native int LEASH_ATTACH_TO_FRAGMENT_LOCATOR(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5, int pram6, int pram7, int pram8, int pram9, int pram10)l
extern _native int LEASH_ATTACH_TO_OBJECT_BONE(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5, int pram6, int pram7, int pram8, int pram9, int pram10, int pram11)l
extern _native int LEASH_ATTACH_TO_OBJECT_BONE_VISUAL(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5, int pram6, int pram7, int pram8, int pram9, int pram10, int pram11)l
//LEASH_SET_LOCATOR_POSITION_VISUAL 0xC1265E7F
extern _native int LEASH_DETACH_OBJECT(int pram0, int pram1)l
extern _native bool LEASH_IS_BROKEN(int pram0)l
extern _native int LEASH_BREAK(int pram0, int pram1)l
extern _native int CREATE_ROPE_FOR_BRIDGE_LEFT(int pram0, int pram1, int pram2)l
extern _native int CREATE_ROPE_FOR_BRIDGE_RIGHT(int pram0, int pram1, int pram2)l
extern _native int LEASH_STAY_CONSTRAINED(int pram0, int pram1)l
//SET_LEASH_COLLIDES 0x1A8494E6
//////////////////////////////////
//World
/////////////////////////////////
extern _native int FIND_INTERSECTION(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5, int pram6)l
extern _native float FIND_GROUND_INTERSECTION(vector3 pram0, float pram1, vector3 pram2, int pram3)l
extern _native int FIND_GROUND_INTERSECTION_WITH_MATERIAL(int pram0, int pram1, int pram2, int pram3, int pram4)l
extern _native int FIND_WATER_INTERSECTION(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5, int pram6, int pram7)l
extern _native int GET_MATERIAL_AT_VECTOR(vector3 position)l
extern _native int GET_ACTOR_GROUND_MATERIAL(Actor actor)l
extern _native int IS_POSITION_INDOORS(int pram0, int pram1, int pram2)l
//////////////////////////////////
//Cutscene
/////////////////////////////////
extern _native bool CUTSCENE_MANAGER_DOES_CUTSCENE_EXIST(char* cutscene)l
extern _native void CUTSCENE_MANAGER_LOAD_CUTFILE(char* pram0, int pram1, int pram2, int pram3, int pram4, int pram5)l
extern _native bool CUTSCENE_MANAGER_IS_CUTFILE_LOADED()l
extern _native const char* CUTSCENE_MANAGER_GET_LOADED_CUTFILE()l
extern _native void CUTSCENE_MANAGER_RESUME_LOADING()l
extern _native void CUTSCENE_MANAGER_LOAD_CUTSCENE(char* cutscenePath, int pram1, int pram2, int pram3, int pram4, int pram5)l
extern _native bool CUTSCENE_MANAGER_IS_CUTSCENE_LOADED()l
extern _native void CUTSCENE_MANAGER_UNLOAD_CUTSCENE()l
extern _native void CUTSCENE_MANAGER_PLAY_CUTSCENE()l
extern _native void CUTSCENE_MANAGER_STOP_CUTSCENE(int pram0, int pram1)l
extern _native bool CUTSCENE_MANAGER_IS_CUTSCENE_PLAYING()l
extern _native bool CUTSCENE_MANAGER_IS_CUTSCENE_FINISHED()l
//_CUTSCENE_MANAGER_SET_TRANSITION_FROM_GAME_CAMERA 0x82F80FEA
//_CUTSCENE_MANAGER_SET_TRANSITION_TO_GAME_CAMERA 0xCBE7BE6A
extern _native32(0x9E6A776F) void _CUTSCENE_MANAGER_RESET_GAME_CAMERA_ON_EXIT(int pram0, int pram1)l
extern _native32(0x47FAE768) void _CUTSCENE_MANAGER_ORIENT_GAME_CAMERA_ON_EXIT(int pram0, int pram1, int pram2, int pram3, int pram4)l
//CUTSCENE_MANAGER_SKIP_UI_STACK_POP 0x93F356F4
extern _native void CUTSCENE_MANAGER_SET_SKIP_UI_STACK_POP(int pram0)l
extern _native32(0xE0BE8235) void _CUTSCENE_MANAGER_SET_HIDE_NON_CUTSCENE_ACTORS(int pram0)l
extern _native int CUTSCENE_MANAGER_CAN_SET_POST_CUTSCENE_POSES()l
extern _native void CUTSCENE_MANAGER_CLEAR_CAN_SET_POST_CUTSCENE_POSES()l
extern _native int CUTSCENE_MANAGER_GET_CURRENT_TIME()l
extern _native int CUTSCENE_MANAGER_GET_CURRENT_FRAME()l
extern _native int CUTSCENE_MANAGER_GET_TOTAL_FRAMES()l
//CUTSCENE_MANAGER_ENUMERATE_CUTXML_NAMES 0x1501F924
//CUTSCENE_MANAGER_GET_NUM_CUTXML_NAMES 0xC677BF51
//CUTSCENE_MANAGER_GET_CUTXML_NAME 0xC2B5BDDF
extern _native int CUTSCENE_MANAGER_GET_NUM_CUTSCENE_ACTORS()l
extern _native int CUTSCENE_MANAGER_GET_CUTSCENE_ACTOR_NAME(int pram0)l
extern _native void CUTSCENE_MANAGER_CLEAR_SCRIPT_EVENT()l
extern _native Actor CUTSCENE_MANAGER_GET_CUTSCENE_ACTOR(int pram0)l
//CUTSCENE_MANAGER_GET_CUTSCENE_ACTORENUM 0xEA8E6112
extern _native int CUTSCENE_MANAGER_GET_CUTSCENE_ACTOR_BY_INDEX_START_ORIENT(int pram0, int pram1, int pram2)l
extern _native int CUTSCENE_MANAGER_GET_CUTSCENE_ACTOR_BY_INDEX_END_ORIENT(int pram0, int pram1, int pram2)l
extern _native int CUTSCENE_MANAGER_GET_NUM_CUTSCENE_PROPS()l
extern _native int CUTSCENE_MANAGER_GET_CUTSCENE_PROP_NAME(int pram0)l
extern _native Object CUTSCENE_MANAGER_GET_CUTSCENE_PROP(int cutscene)l
//CUTSCENE_MANAGER_GET_CUTSCENE_PROP_BY_NAME 0x3BDB2ADF
extern _native int CUTSCENE_MANAGER_GET_CUTSCENE_PROP_BY_INDEX_START_ORIENT(int pram0, int pram1, int pram2)l
extern _native int CUTSCENE_MANAGER_GET_CUTSCENE_PROP_BY_INDEX_END_ORIENT(int pram0, int pram1, int pram2)l
extern _native int CUTSCENE_MANAGER_HIDE_ACTOR(Actor actor)l
extern _native int CUTSCENE_MANAGER_SHOW_ACTOR(Actor actor)l
extern _native int CUTSCENE_MANAGER_GET_INITIAL_STREAMING_LOAD_SCENE_EXT(vector3 * scenePos, vector3 * sceneDir)l
//CUTSCENE_MANAGER_GET_FINAL_STREAMING_LOAD_SCENE_EXT 0x5C553565
extern _native void CUTSCENE_MANAGER_SET_FINAL_STREAMING_LOAD_SCENE_EXT(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5)l
//CUTSCENE_MANAGER_SET_ASSET_OVERRIDE 0x35DBDD67
//CUTSCENE_MANAGER_SET_ASSET_OVERRIDE_ACTORENUM 0x250232CF
extern _native void CUTSCENE_MANAGER_SET_ASSET_OVERRIDE_ACTOR(int pram0, int pram1)l
extern _native int CUTSCENE_MANAGER_GET_SCRIPT_EVENT_DATA()l
//CUTSCENE_MANAGER_GET_SCRIPT_EVENT_DESCRIPTION 0xDE79FA4E
//CUTSCENE_MANAGER_CLEAR_SCRIPT_EVENT 0x2B45FADE
extern _native void CUTSCENE_MANAGER_SET_WAS_JOHN_NOW_JACK_IN_RCM_CUTSCENE(int pram0)l
//////////////////////////////////
//Gateway
/////////////////////////////////
extern _native int GATEWAY_GET_ACTOR(int pram0)l
extern _native void GATEWAY_SET_ACTOR(int pram0, int pram1)l
extern _native int GATEWAY_GET_VOLUME(int pram0)l
extern _native int GATEWAY_GET_MARKER(int pram0)l
extern _native int GATEWAY_UPDATE(int pram0)l
extern _native void GATEWAY_DISABLE_ALL(bool disable)l
extern _native void GATEWAY_DISABLE(int pram0, int pram1)l
extern _native int GATEWAYS_ARE_DISABLED()l
extern _native int GATEWAY_IS_DISABLED(int pram0)l
//////////////////////////////////
//Volume
/////////////////////////////////
extern _native bool IS_VOLUME_VALID(int volume)l
extern _native bool IS_POINT_IN_VOLUME(int pram0, int pram1, int pram2, int pram3)l
extern _native bool IS_ACTOR_IN_VOLUME(Actor actor, int volume)l
extern _native void DELETE_PROJECTILES_IN_VOLUME(int volume)l
extern _native void GET_VOLUME_CENTER(int volume, vector3 * outCoords)l
extern _native void SET_VOLUME_ENABLED(int pram0, int pram1)l
extern _native bool IS_VOLUME_ENABLED(int volume)l
extern _native float GET_VOLUME_HEADING(int volume)l
extern _native void GET_VOLUME_SCALE(int pram0, int pram1)l
extern _native void GENERATE_RANDOM_POINT_IN_VOLUME(int pram0, int pram1)l
extern _native void FIND_VOL_SURFACE_POINTS_FOR_POINT(int pram0, int pram1, int pram2, int pram3)l
//////////////////////////////////
//Turret
/////////////////////////////////
extern _native bool IS_USING_TURRET(int volume)l
//////////////////////////////////
//String
/////////////////////////////////
extern _native bool IS_STRING_VALID(const char* string)l
extern _native32(0x8218D693) bool _STRING_COMPARE(const char* str1, const char* str2)l
extern _native32(0xEC28CA8E) int _STRING_COMPARE_CLAMPED(int pram0, int pram1, int pram2)l
extern _native int STRING_CONTAINS_STRING(int pram0, int pram1)l
extern _native float STRING_TO_FLOAT(const char* string)l
extern _native int STRING_TO_INT(const char* string)l
extern _native Hash STRING_TO_HASH(const char* string)l
extern _native int STRING_LENGTH(const char* string)l
extern _native int STRINGTABLE_LENGTH(int pram0)l
extern _native const char* STRING_LOWER(const char* string)l
extern _native const char* STRING_UPPER(const char* string)l
extern _native32(0x346E91C2) int _TOKENIZE_STRING(int pram0, int pram1)l
extern _native int STRING_NUM_TOKENS()l
extern _native int STRING_GET_TOKEN(int pram0)l
extern _native void STRING_CLEAR_TOKENIZER()l
extern _native void SS_INIT(int pram0)l
extern _native int SS_REGISTER(int pram0, int pram1, int pram2)l
extern _native const char* SS_GET_STRING(int unk, int item)l
extern _native int SS_GET_STRING_ID(int pram0, int pram1)l
extern _native void SS_FINALIZE()l
extern _native void SS_UNFINALIZE()l
extern _native int SS_SET_TABLE_SIZE(int pram0, int pram1)l
//////////////////////////////////
//Population
/////////////////////////////////
extern _native void BEGIN_POPULATION_DEFINITION()l
extern _native void END_POPULATION_DEFINITION()l
//LINK_ACTORENUM_TO_POPULATION 0xC1B8DEA
//LINK_ACTORENUM_TO_POPULATION_TIMED 0x93B6135B
//UNLINK_ACTORENUM_FROM_POPULATION 0x84F75008
extern _native void SET_ACCESSORYSET_ON_SPAWN(int pram0, int pram1, int pram2)l
extern _native void SET_ZONE_POPULATION_ANIMAL_DOMESTICATION(int pram0, int pram1)l
extern _native void SET_ZONE_POPULATION_COUNT(int pram0, int pram1)l
extern _native void SET_ZONE_POPULATION_COUNT_RANDOM(int pram0, int pram1, int pram2)l
extern _native void SET_ZONE_POPULATION_DENSITY(int pram0, int pram1)l
extern _native void SET_ZONE_POPULATION_TYPE(int pram0, int pram1)l
extern _native void SET_ZONE_POPULATION_SPAWN_MULTI_PER_POINT(int pram0, int pram1)l
extern _native void SET_ZONE_RESTRICT_ACTORS(int pram0, int pram1)l
extern _native void SET_ZONE_POPULATION_IS_FLOCK(int pram0, int pram1)l
extern _native void SET_ZONE_POPULATION_MIN_FLOCK_SIZE(int pram0, int pram1)l
extern _native void SET_ZONE_POPULATION_MAX_FLOCK_SIZE(int pram0, int pram1)l
extern _native32(0x354DDFED) void _SET_ZONE_POPULATION_MAX_ACTORS_PER_CELL(int pram0, int pram1)l
extern _native32(0x7ABDE1F0) void _SET_FLOCK_DEFAULT_MAX_ACTORS_PER_CELL(int pram0)l
extern _native32(0x7D7F9770) void _SET_INDIVIDUAL_DEFAULT_MAX_ACTORS_PER_CELL(int pram0)l
extern _native void SET_ZONE_PRIORITY(int pram0, int pram1)l
extern _native void SET_ZONE_FORCE_SPAWN_DISTANCE(int pram0, int pram1)l
extern _native void SET_ZONE_RESERVE_GRINGOS(int pram0, int pram1)l
extern _native void SET_ZONE_SPAWN_ONLY_AT_GRINGOS(int pram0, int pram1)l
extern _native void CLEAR_ZONE_ALLOWED_GRINGO_TYPE_LIST(int pram0)l
extern _native void ADD_TO_ZONE_ALLOWED_GRINGO_TYPE_LIST(int pram0, int pram1)l
extern _native void SET_ZONE_RESPECT_VOLUME_RESTRICTIONS(int pram0, int pram1, int pram2)l
extern _native void SET_DEFAULT_POPULATION_DENSITY(int pram0)l
extern _native void SET_DEFAULT_POPULATION_TYPE(int pram0)l
extern _native int GET_RAND_ACTORENUM_FROM_POPULATION_NATIVE(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5, int pram6, int pram7)l
extern _native void MAKE_NEXT_RAND_ACTORENUMS_UNIQUE(int pram0)l
extern _native bool IS_POPULATION_SET_READY(int pram0, int pram1, int pram2)l
extern _native bool IS_POPULATION_SET_REQUIRED_RESIDENT(int pram0)l
extern _native int FIND_NAMED_POPULATION_SET(int pram0)l
extern _native int GET_NUM_ACTORENUMS_IN_POPULATION(int pram0)l
extern _native int GET_ACTORENUM_IN_POPULATION(int pram0, int pram1)l
extern _native int GET_ACTORENUM_IN_POPULATION_WEIGHT(int pram0, int pram1)l
extern _native int MARKETING_GET_AMBIENT_DENSITY_LEVEL()l
extern _native32(0x84FB15FA) void _SET_ZONE_ALLOWED_TP_SPAWN_AND_READY_TOO_CLOSE(int pram0, int pram1)l
extern _native void AMBIENT_SPAWN_PRESTREAM_SET(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5)l
extern _native int AMBIENT_SPAWN_PRESTREAM_CLEAR()l
//////////////////////////////////
//Physics
/////////////////////////////////
extern _native int GET_PHYSINST_VELOCITY(int pram0, int pram1)l
extern _native int IS_PHYSINST_ACTIVE(int pram0)l
extern _native void SET_PHYSINST_COLLIDES_AGAINST_INACTIVE(int pram0, int pram1)l
extern _native void SET_PHYSINST_FROZEN(int unkObject, bool frozen)l
extern _native int IS_PHYSINST_FROZEN(int pram0)l
extern _native void SET_PHYSINST_HIDE(int pram0)l
extern _native int IS_PHYSINST_HIDE(int pram0)l
extern _native void BREAK_OFF_ABOVE(int pram0, int pram1)l
extern _native int GET_LOCATOR_OFFSETS(int pram0, int pram1, int pram2, int pram3)l
extern _native32(0xFD759593) int _SET_HAS_INFINITE_MASS_VS_MOVERS(int pram0, int pram1)l//void idk the params
extern _native void SET_GLOBAL_DISABLE_SPU_COLLIDER_UPDATE(bool enable)l
extern _native void SET_GLOBAL_AGGRESSIVE_CORPSE_RECYCLING(int pram0)l
extern _native void LIQUID_TEST_SET_VELOCITY_SCALE(float scale)l
extern _native void CLEAN_CACHE_ENTRIES()l
//////////////////////////////////
//Pers Char
/////////////////////////////////
extern _native int ACTIVATE_ACTOR_FOR_PERS_CHAR(int pram0)l
extern _native int DEACTIVATE_ACTOR_FOR_PERS_CHAR(int pram0)l
extern _native void DEACTIVATE_ACTORS_FOR_PERS_CHARS_IN_VOLUME(int pram0)l
extern _native Actor GET_ACTOR_FROM_PERS_CHAR(Actor actor)l
extern _native int GET_PERS_CHAR_DEATH_TIMESTAMP(int pram0)l
extern _native Actor GET_PERS_CHAR_FROM_ACTOR(Actor actor)l
extern _native int SET_PERS_CHAR_SAFE_ZONE(Actor persistentChar, float radius)l
extern _native bool IS_PERS_CHAR_ALIVE(int pram0)l
extern _native int REVIVE_PERS_CHAR(int pram0, int pram1)l
extern _native void SET_PERS_CHAR_EXEMPT_FROM_AMBIENT_RESTRICTIONS(int pram0, int pram1)l
extern _native void SET_PERS_CHAR_ENABLED(Actor persistentChar, bool enabled)l
extern _native void SET_PERS_CHAR_ALLOW_SPAWN_ELSEWHERE(int pram0, int pram1)l
//////////////////////////////////
//Path
/////////////////////////////////
extern _native void SET_PATH_LOOPING(int pram0, int pram1)l
extern _native int ADD_POINT_TO_PATH(int pram0, int pram1, int pram2, int pram3)l
extern _native void SET_POINT_IN_PATH(int p0, int p1, float p2, float p3, float p4)l
extern _native int GET_NUM_PATH_POINTS(int pram0)l
extern _native int GET_PATH_NUM_POINTS(int pram0)l
extern _native void GET_PATH_POINT(int pram0, int pram1, int pram2)l
extern _native float ESTIMATE_PATH_LENGTH(int pram0)l
extern _native int ESTIMATE_DISTANCE_ALONG_PATH(int p0, int p1, int p2, float p3, int p4)l
extern _native void ESTIMATE_TWO_DISTANCES_ALONG_PATH(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5)l
//////////////////////////////////
//Nav Query
/////////////////////////////////
extern _native int CREATE_NAV_QUERY(int pram0, int pram1)l
extern _native int NAV_QUERY_IS_DONE(int pram0)l
extern _native int NAV_QUERY_CAN_PATH_TO_POINT(int pram0)l
extern _native void NAV_QUERY_RECEIVE_CAN_PATH_TO_POINT(int pram0, int pram1)l
extern _native void NAV_QUERY_START_CAN_PATH_TO_POINT(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5, int pram6, int pram7)l
extern _native void NAV_QUERY_STOP(Object obj)l
//////////////////////////////////
//Lasso
/////////////////////////////////
extern _native int GET_LASSO_TARGET(int pram0)l
extern _native int GET_LASSO_USER(int pram0)l
extern _native int GET_HOGTIED_MASTER(int pram0)l
extern _native int GET_ATTACHED_HOGTIE_VICTIM(int pram0)l
extern _native void DETACH_LASSO(int pram0)l
extern _native void FREE_FROM_HOGTIE(Actor actor)l
extern _native void LASSO_EVENT(int pram0, int pram1)l
extern _native int SET_INTENDED_HOGTIE_MASTER(int pram0, int pram1)l
extern _native bool IS_ACTOR_BEING_DRAGGED(int pram0, int pram1)l
extern _native bool IS_ACTOR_HOGTIED(Actor actor)l
extern _native bool IS_ACTOR_IN_HOGTIE(Actor actor)l
extern _native int GET_ACTOR_HOGTIE_STATE(Actor actor)l
extern _native void HOGTIE_ACTOR(Actor actor)l
extern _native int ATTACH_HOGTIE_ACTOR_TO_ACTOR(int pram0, int pram1)l
extern _native void SET_HOGTIE_ATTACH_VICTIM(int pram0, int pram1)l
extern _native void CLEAR_HOGTIE_ATTACH_VICTIM(int pram0)l
extern _native bool IS_ACTOR_HOGTIE_ATTACHED(Actor actor)l
extern _native int IS_HOGTIE_PUTDOWN_OBSTRUCTED(int pram0)l
extern _native bool IS_HOGTIE_PICKUP_OBSTRUCTED(int pram0, int pram1)l
extern _native bool IS_HOGTIE_CUTFREE_OBSTRUCTED(int pram0, int pram1)l
extern _native32(0x9634D42E) int _IS_HOGTIE_PICKUP_FROM_HORSE_OBSTRUCTED(int pram0, int pram1)l
extern _native int IMMEDIATELY_LASSO_TARGET(int pram0, int pram1, int pram2)l
//////////////////////////////////
//Greeting
/////////////////////////////////
extern _native void SET_GREETING_CONTEXT(int pram0)l
extern _native void SET_NON_VERBAL_GREETING_PROBABILITY(int pram0)l
extern _native32(0x25A42C69) void _SET_LOOK_AT_ANGLE_DEFAULT(int pram0)l
extern _native32(0x40121E4F) void _SET_LOOKING_AT_ANGLE_ACTOR_SPECIFIC(int pram0, int pram1)l
extern _native32(0x86CB8CFB) void _SET_PROBABILITY_NPC_DEFAULT(int pram0)l
extern _native32(0xD6AD0016) void _SET_PROBABILITY_PLAYER_DEFAULT(int pram0)l
extern _native32(0xDE84B637) void _SET_LOOK_AT_ANGLE_ACTOR_SPECIFIC(int pram0, int pram1)l
extern _native32(0x8C00C0BE) void _SET_MIN_TIME_INTERVAL(int pram0)l
extern _native32(0x7CC67B30) void _SET_MIN_TIME_INTERVAL_SAME_TARGET(int pram0)l
extern _native32(0xD4ECD97D) void _SET_MAX_DISTANCE(int pram0)l
extern _native32(0x826BB889) void _SET_MIN_MOVEMENT_SPEED(float pram0)l
extern _native32(0x5473B93A) void _SET_MAX_MOVEMENT_ANGLE(int pram0)l
extern _native32(0x1B1EFCCB) void _SET_ANIM_SIGNAL_TIMEOUT_DURATION(int pram0)l
//////////////////////////////////
//Game
/////////////////////////////////
extern _native void DISABLE_PLAYER_GRINGO_USE(int pram0, int pram1)l
extern _native bool IS_MISSION_SCRIPT()l
extern _native void SET_IS_MISSION_SCRIPT(bool set)l
extern _native32(0x45589499) void _SET_SCRIPT_AVOIDS_ST(int pram0)l
extern _native int GET_GAME_STATE()l
extern _native void SET_PAUSE_SCRIPT(int pram0)l
extern _native void ENABLE_USE_CONTEXTS(bool enable)l
extern _native int ARE_USE_CONTEXTS_ENABLED()l
extern _native int IS_SCRIPT_USE_CONTEXT_VALID(int pram0)l
extern _native int ADD_SCRIPT_USE_CONTEXT_IN_VOLUME(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5, int pram6, int pram7, int pram8, int pram9)l
extern _native int ADD_SCRIPT_USE_CONTEXT(char* context, int unk1, eButton button, int unk2, int unk3, int unk4, int unk5, int unk6, int unk7)l
extern _native32(0xF48F8F09) int _ADD_SCRIPT_USE_CONTEXT_STICK_NO_VOLUME(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5, int pram6, int pram7, int pram8)l
extern _native bool IS_SCRIPT_USE_CONTEXT_PRESSED(int pram0)l
extern _native bool WAS_SCRIPT_USE_CONTEXT_EVER_PRESSED(int pram0)l
extern _native void SET_USE_CONTEXT_TEXT(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5)l
extern _native void RELEASE_SCRIPT_USE_CONTEXT(int pram0)l
extern _native bool NET_MAILBOX_IS_SIGNED_INTO_SC()l
extern _native int NET_MAILBOX_GET_MAX_NUM_CHALLENGES()l
extern _native int NET_MAILBOX_GET_NUM_CHALLENGES()l
extern _native int NET_MAILBOX_GET_CHALLENGE_BY_INDEX(int pram0)l
extern _native int NET_MAILBOX_GET_CHALLENGE_BY_ID(int pram0)l
extern _native bool NET_MAILBOX_IS_CHALLENGE_VALID(int pram0)l
extern _native int SC_CHALLENGE_LAUNCH(int pram0)l
extern _native void SC_CHALLENGE_CLEAN_UP(int pram0)l
extern _native bool SC_CHALLENGE_IS_RUNNING(int pram0)l
extern _native bool SC_CHALLENGE_IS_ACTIVE(int pram0)l
extern _native int SC_CHALLENGE_GET_COMMUNITY_TOTAL(int pram0)l
extern _native int SC_CHALLENGE_GET_COMMUNITY_VALUE(int pram0)l
extern _native void SC_CHALLENGE_PROCESS_EXPIRATION(int pram0)l
extern _native int SC_CHALLENGE_GET_EXPIRATION_STATE(int pram0)l
extern _native void SC_CHALLENGE_RESET_EXPIRATION_STATE(int pram0)l
extern _native bool SC_CHALLENGE_IS_VAR_VALID(int pram0, int pram1)l
extern _native int SC_CHALLENGE_GET_VAR_FLOAT(int pram0, int pram1)l
extern _native int SC_CHALLENGE_GET_VAR_INT(int pram0, int pram1)l
extern _native int SC_CHALLENGE_GET_VAR_BOOL(int pram0, int pram1)l
extern _native void SC_CHALLENGE_RELEASE(int pram0)l
extern _native int SC_CHALLENGE_GET_LEADERBOARD_ID(int pram0, int pram1)l
extern _native int SC_CHALLENGE_GET_MIN_LB_REFRESH_DELAY_SECS()l
extern _native int SC_CHALLENGE_GET_MIN_SUBMIT_DELAY_SECS()l
//////////////////////////////////
//Cover
/////////////////////////////////
extern _native int FIND_NEAREST_COVER_LOCATION(int pram0, int pram1, int pram2, int pram3, int pram4)l
extern _native32(0x9265B24B) int _GET_COVER_LOCATIONS_IN_VOLUME(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5)l
extern _native void GET_COVER_LOCATION_BASE_POSITION(int pram0, int pram1)l
extern _native float GET_COVER_LOCATION_DIRECTION(int pram0)l
extern _native int GET_COVER_LOCATION_POSITION(int pram0, int pram1)l
extern _native bool IS_COVER_LOCATION_VALID(int coverLocation)l
extern _native int ADD_AI_COVERSET_FOR_PROPSET(int pram0)l
//////////////////////////////////
//Object Animator
/////////////////////////////////
extern _native bool IS_OBJECT_ANIMATOR_VALID(int pram0)l
extern _native int CREATE_OBJECT_ANIMATOR(int pram0, int pram1, int pram2, int pram3, int pram4)l
extern _native int CREATE_OBJECT_ANIMATOR_ON_OBJECT(int pram0, int pram1, int pram2, int pram3)l
extern _native bool IS_OBJECT_ANIMATOR_READY(int pram0)l
extern _native int GET_OBJECT_ANIMATOR_ON_OBJECT(int pram0)l
extern _native int SET_OBJECT_ANIMATOR_NODE(int pram0, int pram1)l
extern _native int SET_OBJECT_ANIMATOR_PHASE(Object obj, float value)l
extern _native int SET_OBJECT_ANIMATOR_RATE(Object obj, float rate)l
extern _native int GET_OBJECT_ANIMATOR_PHASE(int pram0)l
extern _native32(0x188B6431) int _SET_BONE_RANGE_ARRAY(int pram0, int pram1, int pram2, int pram3, int pram4)l
extern _native32(0xB57D4110) int _SET_CURRENT_ANIM(Object obj, const char* animation, bool unk)l
extern _native32(0x46A69DAF) bool _IS_OBJECT_ANIMATOR_ANIM_PLAYING(int p0, int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8, int p9, int p10, int p11, int p12, int p13, int p14, int p15, int p16)l
extern _native void DESTROY_OBJECT_ANIMATOR(int pram0)l
extern _native int GET_OBJECT_FROM_ANIMATOR(int pram0)l
extern _native int LINK_OBJECT_ANIMATOR_TO_ACTOR(int pram0, int pram1, int pram2)l
//////////////////////////////////
//Actor
/////////////////////////////////
extern _native bool IS_ACTOR_VALID(Actor actor)l
extern _native int GET_ACTORENUM_FROM_STRING(const char* actorName)l //case sensitive
extern _native bool IS_ACTOR_ON_FOOT(Actor actor)l
extern _native int GET_ACTOR_OFFSET_WORLD_COORDS(Actor actor, vector3 pos1, vector3 pos2)l
extern _native int UNK_0xB89CC342(int pram0, int pram1, int pram2)l
extern _native bool ACTORS_IN_RANGE(Actor actor1, Actor actor2, float distance)l
extern _native int GET_ACTOR_VELOCITY(Actor actor, vector3 * outSpeed)l
extern _native int GET_ACTOR_HEIGHT(int pram0)l
extern _native void SET_GLOBAL_ACTOR_WEAPON_BIAS(int pram0)l//AMBIENT_INIT_NO_CURVE what fox had
extern _native void RESET_GLOBAL_ACTOR_WEAPON_BIAS()l
extern _native32(0xA2DEC153) Actor _LOCATE_ACTOR(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5)l
extern _native int IS_AREA_OBSTRUCTED(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5)l
extern _native int IS_AREA_OBSTRUCTED2(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5, int pram6)l
extern _native int GET_ACTORENUM_SPECIES(int pram0)l
extern _native32(0xEE0AB3DD) int _GET_AE_ACTOR_BASE_TYPE(int actorID)l
extern _native int GET_ACTORENUM_AVATAR_GROUP(eActor actorID)l
extern _native32(0x7D397CAA) char* _GET_MP_ANIM_SET_NAME(int actorEnum)l
extern _native32(0x8DAC4359) char* _GET_MP_VOICE_NAME(int pram0)l
extern _native void SET_ACTOR_STAMINA(Actor actor, float stamina)l
extern _native int GET_ACTOR_GAIT_TYPE(int pram0)l
extern _native int GET_ACTOR_POSTURE(int pram0)l
extern _native void SET_ACTOR_POSTURE(int pram0, int pram1)l
extern _native void RESET_ACTOR_GAITS(int pram0, int pram1)l
extern _native int GET_ACTOR_TYPE(Actor actor)l
extern _native bool IS_ACTOR_MALE(Actor actor)l
extern _native void SET_ACTOR_SEX(int pram0, int pram1)l
extern _native void SET_ACTOR_IS_COMPANION(int pram0, int pram1)l
extern _native void SET_ACTOR_IS_THE_BEASTMASTER(Actor actor, bool beast)l
extern _native int SET_ACTOR_TIME_OF_LAST_CRIME(int pram0, int pram1)l
extern _native void DESTROY_IMPAIRED_ACTORS()l
extern _native bool IS_PLAYER_WEAPON_ZOOMED(Actor actor)l
extern _native bool IS_ACTOR_ANIMAL(Actor actor)l
extern _native bool IS_ACTOR_CROUCHING(Actor actor)l
extern _native bool IS_ACTOR_FLYING(Actor actor)l
extern _native bool IS_ACTOR_HUMAN(Actor actor)l
extern _native bool IS_ACTOR_JUMPING(Actor actor)l
extern _native bool IS_ACTOR_SHOOTING(Actor Actor)l
extern _native bool IS_ACTOR_BLINDFIRING(Actor actor)l
extern _native bool IS_ACTOR_RELOADING(Actor actor)l
extern _native int IS_ACTOR_THROWING(int pram0)l
extern _native bool IS_ACTOR_WHISTLING(Actor actor)l
extern _native bool IS_ACTOR_ON_LADDER(Actor actor)l
extern _native int IS_ACTOR_OUTDOORS(int pram0)l
extern _native void SUSPEND_MOVER(int pram0)l
extern _native void ENABLE_MOVER(int pram0)l
extern _native void SET_MOVER_FROZEN(Actor actor, bool frozen)l
extern _native bool IS_MOVER_FROZEN(Actor actor)l
extern _native int SET_ACTOR_USE_COARSE_BOUNDS(Actor actor, bool use)l//int
extern _native32(0x61664EC0) void _SUPPRESS_MOVE_COLLISIONS(Actor actor, Object physinstObj, bool suppress)l
extern _native bool IS_ACTOR_ON_GROUND(Actor actor)l
extern _native bool IS_ACTOR_ON_PATH(Actor actor, int p1, int p2, int p3, int p4)l
extern _native32(0x4A2DE1D0) int _IS_MOVER_ON_VEHICLE_PATH(Actor actor, int p1, int p2, int p3, int p4)l
extern _native bool IS_ACTOR_IN_WATER(Actor actor)l
extern _native32(0xA6AA7B9E) bool _IS_MOVER_IN_WATER_OF_DEPTH(Actor actor, float depth)l
extern _native int GET_ACTOR_STUCK_STATE(Actor actor)l
extern _native int IS_ACTOR_IN_FIRE_VOLUME(int pram0)l
extern _native bool IS_ACTOR_RIDEABLE(Actor actor)l
extern _native void SET_ACTOR_RIDEABLE(Actor actor, bool rideable)l
extern _native int GET_VEHICLE_BUMP_COUNT(Vehicle vehicle)l
extern _native void RESET_VEHICLE_BUMP_COUNT(Vehicle vehicle)l
extern _native32(0x5FEA3E61) void _SET_CUSTOM_ANIM_SPEED_SCALE(int anim, float scale)l
extern _native int ACTOR_RESET_ANIMS(Actor actor, bool reset)l
extern _native32(0x4A1D2E25) int _SCHEDULE_STOP_CUSTOM_UNSUSPEND(int pram0)l
extern _native32(0x817B6952) int _SCHEDULE_STOP_CUSTOM_UNFREEZE(int pram0)l
extern _native32(0xC17BAD12) int _SCHEDULE_STOP_REPLICATION(int pram0)l
extern _native void SET_ACTOR_CAN_PLAY_BORED_IDLES(int pram0, int pram1)l
extern _native void SET_ACTOR_CAN_PLAY_GESTURES(int pram0, int pram1)l
extern _native void ACTOR_ENABLE_VARIABLE_MESH(Actor actor, int meshBit, bool enable)l//3x int
extern _native bool ACTOR_IS_VARIABLE_MESH_ENABLED(Actor actor, int mesh)l
extern _native void ACTOR_SET_GRABBED_BY_CUTSCENE(int pram0, int pram1)l
extern _native bool ACTOR_IS_GRABBED_BY_CUTSCENE(int pram0)l
extern _native bool ACTOR_IS_HIDDEN_BY_CUTSCENE(Actor actor)l
extern _native32(0x0CC3D8F6) int _IS_ACTOR_FULLY_FADED(int pram0, int pram1)l
extern _native int SET_ACTOR_HEARING_MAX_RANGE(int pram0, int pram1)l
extern _native float GET_ACTOR_VISION_FIELD_OF_VIEW(Actor actor)l
extern _native int SET_ACTOR_VISION_FIELD_OF_VIEW(Actor actor, float fov)l
extern _native int GET_ACTOR_VISION_MAX_RANGE(int pram0)l
extern _native int SET_ACTOR_VISION_MAX_RANGE(int pram0, int pram1, int pram2)l
extern _native int SET_UNIVERSAL_VISION_RANGE_MULTIPLIER(float pram0)l
extern _native int SET_ACTOR_VISION_XRAY(Actor actor, int pram1)l
extern _native int GET_ACTOR_VISION_XRAY(int pram0)l
extern _native int GET_ACTOR_CURRENT_WEAPON_AI_PARAMETERS(int pram0, int pram1)l
extern _native int GET_ACTOR_ALLOW_BUMP_REACTIONS(int pram0)l
extern _native void SET_ACTOR_ALLOW_BUMP_REACTIONS(Actor actor, bool allow)l
extern _native32(0xEB7B0FAA) void _SET_ALLOW_NM_BUMP(int pram0, int pram1)l
extern _native void SET_RCM_ACTOR_CALL_OVER_ENABLE(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5, int pram6, int pram7, int pram8, int pram9)l
extern _native void SET_RCM_WAS_JOHN_NOW_JACK(int pram0, int pram1)l
extern _native void SET_RCM_ACTOR_CALL_OVER_SUPPRESS(int pram0)l
extern _native32(0xC28A5950) void _SET_ALLOW_PLAYER_GREET_RESPONSES(int pram0, int pram1)l
extern _native void SET_ACTOR_ALLOW_WEAPON_REACTIONS(int pram0, int pram1)l
extern _native void SET_ACTOR_ALLOW_WEAPON_REACTION_FLEE(Actor actor, bool allowReaction)l
extern _native int GET_ACTOR_WEAPON_REACTION_ACTOR_TYPE(int pram0)l
extern _native void SET_ACTOR_WEAPON_REACTION_ACTOR_TYPE(int pram0, int pram1)l
extern _native int SET_PLAYER_CAUSE_WEAPON_REACTIONS(int p0, int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8, int p9)l
extern _native void SET_ACTOR_WEAPON_REACTION_NO_FLEE_HACK(Actor actor, bool set)l
extern _native int SET_ACTOR_OBSERVED_TARGETED_REACTIONS(int p0, int p1)l
extern _native void SET_PLAYER_CAUSE_WEAPON_REACTION_COMBAT(int pram0, int pram1)l
extern _native int SET_ACTOR_REACT_TO_LASSO(int p0, const char* p1)l
extern _native void SET_ACTOR_ALLOW_DISARM(int pram0, int pram1)l
extern _native void SET_ANIMAL_CAN_ATTACK(int pram0, int pram1)l
extern _native int GET_CURRENT_GRINGO(int pram0)l
extern _native void SET_ACTOR_GRINGO_RESTRICTION(int pram0, int pram1)l//_SET_GRINGO_RESTRICTION 0x527CB774
extern _native void CLEAR_ACTOR_GRINGO_RESTRICTION(Actor actor)l//_CLEAR_GRINGO_RESTRICTION 0x660DBDDD
extern _native int MAKE_ACTOR_READY_FOR_ACTION(int pram0, int pram1)l
extern _native int IS_ACTOR_READY_FOR_ACTION(int pram0)l
extern _native void REPORT_GRINGO_USE_PHASE(int pram0, int pram1)l
extern _native32(0x9028B082) void _DESTROY_ALL_CORPSES()l
extern _native int CAN_PLAYER_DIE()l
extern _native void CLEAR_ACTOR_MAX_SPEED(Actor actor)l
extern _native void SET_ACTOR_MAX_SPEED(Actor actor, float maxSpeed)l
extern _native void SET_ACTOR_MAX_SPEED_ABSOLUTE(Actor actor, float speed)l
extern _native void CLEAR_ACTOR_MIN_SPEED(Actor actor)l
extern _native void SET_ACTOR_MIN_SPEED(int pram0, int pram1)l
extern _native int SET_ACTOR_MIN_SPEED_ABSOLUTE(Actor actor, float p1)l
extern _native float GET_ACTOR_MAX_SPEED(Actor actor)l
extern _native int GET_ACTOR_MAX_SPEED_ABSOLUTE(int pram0)l
extern _native float GET_ACTOR_MIN_SPEED(Actor actor)l
extern _native void SET_ACTOR_SPEED(int pram0, int pram1)l
extern _native void CLEAR_LAST_ATTACK(Actor actor)l
extern _native int GET_LAST_ATTACK_TARGET(Actor actor)l
extern _native int GET_LAST_ATTACK_TIME(int pram0)l
extern _native32(0x8C221B4D) int _GET_LOCAL_PLAYER_DAMAGE(int pram0)l
extern _native int GET_ACTOR_COMBAT_CLASS(Actor actor)l
extern _native32(0x8062BD74) void _DLC_SHOTGUN_SPREAD_OVERRIDE(Actor actor, int unk1, float unk2)l
extern _native int BEGIN_DUEL(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5, int pram6, int pram7, int pram8, int pram9, int pram10, int pram11, int pram12)l
extern _native int CANCEL_DUEL(int p0, int p1, int p2, int p3, int p4)l
extern _native int ADD_DUEL_HOSTAGE(int pram0, int pram1)l
extern _native int GET_CURRENT_DUEL_SCORE(int pram0)l
extern _native int SET_DUEL_DIFFICULTY(int pram0, int pram1, int pram2, int pram3)l
extern _native int GET_ACTOR_EXEMPT_FROM_AMBIENT_RESTRICTIONS(int pram0)l
extern _native void SET_ACTOR_EXEMPT_FROM_AMBIENT_RESTRICTIONS(Actor actor, bool exempt)l
extern _native32(0x6695E185) void _ADD_CAPABILITY_TO_ACTOR(int pram0, int pram1)l
extern _native32(0x29AEB2DB) void _REMOVE_CAPABILITY_FROM_ACTOR(int pram0, int pram1)l
extern _native32(0xD3D8E8ED) int _ACTOR_HAS_CAPABILITY(int pram0, int pram1)l
extern _native int GET_LAST_ON_SCREEN_TIME_FOR_ACTOR(int pram0)l
extern _native int NET_SET_NODE_REPLICATION(int pram0, int pram1, int pram2)l
extern _native void SET_ACTOR_ACTION_SIGNAL(int pram0, int pram1, int pram2)l
extern _native void TOGGLE_ACTOR_ACTION_SIGNAL_ON(int pram0, int pram1, int pram2)l
extern _native void TOGGLE_ACTOR_ACTION_SIGNAL_OFF(int pram0)l
extern _native Actor GET_ACTOR_MELEE_TARGETED_BY(Actor actor)l
extern _native void SET_ACTOR_CAN_DEADEYE_TAG_ANYTHING(Actor actor, bool enable)l
extern _native void SET_ACTOR_AUTO_TRANSITION_TO_DRIVER_SEAT(Actor actor, bool autoTransition)l
extern _native int SET_ACTOR_FLY_FX(Actor actor, int pram1)l
extern _native void SET_ACTOR_MOVE_CONFLICT_HIGH_PRIORITY(int pram0, int pram1)l
extern _native void SET_ACTOR_MOVE_CONFLICT_ALLOWED_TO_RUN_OVER_SMALL_ANIMALS(int pram0, int pram1)l
extern _native void SET_ACTOR_IS_AMBIENT(Actor actor, bool ambient)l
extern _native void SET_ACTOR_IS_SHOPKEEPER(int pram0, int pram1, int pram2)l
extern _native void SET_ACTOR_SHOULD_TAUNT(int pram0, int pram1)l
extern _native void SET_ACTOR_CAN_BUMP(Actor actor, bool allow)l
extern _native int SET_ACTOR_MAX_FRESHNESS(int pram0, int pram1)l
extern _native int GET_ACTOR_MAX_FRESHNESS(int pram0)l
extern _native void MAKE_BIRD_FLY_FROM_POINT(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5, int pram6)l
//////////////////////////////////
//GOH Decorator
/////////////////////////////////
extern _native32(0x9AC89564) int _DECOR_PEEK_BOOL(int pram0, int pram1, int pram2)l
extern _native32(0xFAC315B7) int _DECOR_PEEK_FLOAT(int pram0, int pram1, int pram2)l
extern _native32(0x1F003E6C) int _DECOR_PEEK_INT(int pram0, const char* pram1, int pram2)l
extern _native int DECOR_SET_BOOL(Actor actor, const char* decorName, bool set)l
extern _native int DECOR_SET_FLOAT(Object object, const char* decorName, float value)l
extern _native int DECOR_SET_INT(int pram0, int pram1, int pram2)l
extern _native int DECOR_SET_VECTOR(int pram0, int pram1, int pram2, int pram3, int pram4)l
extern _native int DECOR_SET_STRING(int pram0, int pram1, int pram2)l
extern _native int DECOR_SET_OBJECT(int pram0, int pram1, int pram2)l
extern _native int DECOR_CHECK_STRING(Object decor, const char* eventType, const char* eventName)l
extern _native Hash DECOR_GET_STRING_HASH(int event, const char* decorName)l
extern _native int DECOR_GET_BOOL(int pram0, int pram1)l
extern _native int DECOR_GET_FLOAT(int pram0, int pram1)l
extern _native int DECOR_GET_INT(int pram0, int pram1)l
extern _native int DECOR_GET_VECTOR(int pram0, int pram1, int pram2)l
extern _native int DECOR_GET_OBJECT(int pram0, int pram1)l
extern _native int DECOR_CHECK_EXIST(Actor actor, const char* decorName)l
extern _native int DECOR_REMOVE(Actor actor, char* decor)l
extern _native int DECOR_REMOVE_ALL(int pram0)l
//////////////////////////////////
//Weapon
/////////////////////////////////
extern _native32(0xBAC27559) void _INIT_WEAPON_ENUM_PISTOL(int pram0, int pram1, int pram2)l
extern _native32(0xA534CD14) void _INIT_WEAPON_ENUM_RIFLE(int pram0, int pram1, int pram2)l
extern _native32(0xA72B6620) void _INIT_WEAPON_ENUM_REPEATER(int pram0, int pram1, int pram2)l
extern _native32(0x92FE3677) void _INIT_WEAPON_ENUM_SNIPER_RIFLE(int pram0, int pram1, int pram2)l
extern _native32(0xEA06907B) void _INIT_WEAPON_ENUM_SHOTGUN(int pram0, int pram1, int pram2)l
extern _native32(0xE0DF7B3B) void _INIT_WEAPON_ENUM_THROWN(int pram0, const char* pram1, int pram2)l
extern _native32(0xA2597101) void _INIT_WEAPON_ENUM_THROWN_EXPLODING(int pram0, int pram1, int pram2)l
extern _native32(0x2AD5D078) void _INIT_WEAPON_ENUM_BOW(int pram0, int pram1, int pram2)l
extern _native32(0xA6C4E59F) void _INIT_WEAPON_ENUM_MELEE(int pram0, int pram1, int pram2)l
extern _native32(0xF82711CC) void _INIT_WEAPON_ENUM_LASSO(int pram0, int pram1, int pram2)l
extern _native32(0x82609DC7) void _INIT_WEAPON_ENUM_TURRET(int pram0, int pram1, int pram2)l
extern _native32(0x628E3173) void _INIT_WEAPON_ENUM_CANNON(int pram0, int pram1, int pram2)l
extern _native32(0xCE5CCF2E) void _INIT_AMMO_ENUM(int pram0, int pram1)l
extern _native32(0x6A9CFA2A) int _GET_WEAPON_ENUM_STRING(int pram0)l
extern _native const char* GET_WEAPON_DISPLAY_NAME(eWeapon weaponID)l
extern _native int GET_WEAPON_INTERNAL_NAME(int pram0)l
extern _native32(0xBE06C265) const char* _GET_WEAPON_ICON_NAME(int weapon)l
extern _native int GET_WEAPON_FRAGMENT_NAME(int pram0)l
extern _native32(0x01C7193C) void _REGISTER_WEAPON_ENUM_CATEGORY(int pram0, int pram1)l
extern _native32(0x0A23A69C) void _FINALIZE_CATEGORIES()l
extern _native32(0x0E4B7A33) void _SET_WEAPON_ENUM_LOCKED(eWeapon weaponID, bool unlock)l
extern _native32(0xCCE4A339) int _IS_WEAPON_ENUM_LOCKED(int pram0)l
extern _native32(0xDB679ED9) int _GET_WEAPON_ENUM_CATEGORY(int pram0)l
extern _native int GET_AMMO_ENUM(eWeapon weaponID)l
extern _native void SET_AMMO_DROP_BIAS(int pram0, int pram1)l
extern _native32(0xCCB57C38) int _GET_AMMO_ENUM_STRING(int pram0)l
extern _native int GET_AMMO_ENUM_ICON_NAME(int pram0)l
extern _native int GET_WEAPON_MAX_AMMO(int pram0)l//_GET_MAX_AMMO_PER_CLIP 0xA677B204
extern _native32(0xD291A820) void _RESOLVE_DLC_WEAPON_ENUM(int pram0)l
extern _native32(0xF4641CF4) void _ADD_IDLE_FX_TO_WEAPON(int pram0, int pram1, int pram2, int pram3, int pram4)l
//////////////////////////////////
//Gringo
/////////////////////////////////
extern _native bool IS_GRINGO_ACTIVE()l
extern _native bool IS_GRINGO_READY(int pram0)l
extern _native int GRINGO_IS_ACTIVE(int pram0)l
extern _native int GRINGO_GET_TARGET(int pram0)l
extern _native void GRINGO_WAIT(int pram0)l
extern _native int GRINGO_FORCE_UPDATE(int p0, int p1, int p2, int p3)l
extern _native void GRINGO_STOP()l
extern _native int GRINGO_STAY_ACTIVE(int pram0, int pram1)l
extern _native int GRINGO_DEACTIVATE(int pram0)l
extern _native int GRINGO_DEACTIVATE_AND_RESET_ACTORS(int gringo)l
extern _native void GRINGO_ENABLE_TYPE(int pram0)l
extern _native void GRINGO_DISABLE_TYPE(int pram0)l
extern _native int GRINGO_ENABLE_SPAWN(int pram0, int pram1)l
extern _native int LOCATE_GRINGO_OF_TYPE(char* gringoPath, vector3 coords, float heading, int pram3)l
extern _native int LOCATE_GRINGO_OF_TYPE_BY_ID(int pram0, int pram1, int pram2)l
extern _native int LOCATE_GRINGOS_OF_TYPE(int pram0, int pram1, int pram2, int pram3, int pram4)l
extern _native int LOCATE_GRINGO_OF_NAME(int pram0, int pram1, int pram2, int pram3)l
extern _native int LOCATE_GRINGOS_OF_NAME(int pram0, int pram1, int pram2, int pram3, int pram4)l
extern _native32(0xFA37C0FA) int _CAN_ACTOR_USE_GRINGO(int pram0, int pram1, int pram2)l
extern _native int GRINGO_SETUP_PROP_ASSOCIATION(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5, int pram6, int pram7, int pram8, int pram9, int pram10)l
extern _native32(0xC426D16F) int _GRINGO_SETUP_ATTRIBUTE_ASSOCIATION(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5, int pram6, int pram7, int pram8, int pram9, int pram10, int pram11)l
extern _native int GRINGO_CLEAR_PROP_ASSOCIATION(int pram0, int pram1, int pram2)l
extern _native void GRINGO_LOAD_ANIMATION(int pram0)l
extern _native void GRINGO_UNLOAD_ANIMATION(int pram0)l
extern _native void GRINGO_LOAD_ANIMATION_FOR_USER(int pram0, int pram1)l
extern _native void GRINGO_UNLOAD_ANIMATION_FOR_USER(int pram0, int pram1)l
extern _native int GRINGO_HAS_ANIMSET_LOADED(int pram0, int pram1)l
extern _native void GRINGO_LOAD_ANIMATION_FOR_ACTOR_ENUM_EXT(int pram0, int pram1, int pram2, int pram3)l
extern _native void GRINGO_UNLOAD_ANIMATION_FOR_ACTOR_ENUM_EXT(int pram0, int pram1, int pram2, int pram3)l
extern _native int GRINGO_HAS_ANIMSET_LOADED_FOR_ACTOR_ENUM_EXT(int pram0, int pram1, int pram2, int pram3)l
extern _native void GRINGO_ENABLE_PLAYER_CONTROL(int pram0, int pram1)l
extern _native int GRINGO_IS_USABLE_BY_PLAYER(int p0, int p1, int p2, int p3, int p4, int p5)l
extern _native32(0x80317230) void _GRINGO_SET_IS_USABLE_BY_PLAYER(int pram0, int pram1, int pram2)l
extern _native32(0xE2DCFF34) int _CAN_ACTOR_ENUM_USE_GRINGO(int pram0, int pram1, int pram2)l
extern _native bool GRINGO_DEBUG_IS_SELECTED()l//_GRINGO_IS_SELECTED 0xF4015EFC
extern _native32(0x0A0E660E) int _GRINGO_PLAYER_OVERRIDE_ON()l
extern _native32(0x5F7176D6) int _GRINGO_GET_MY_SCRIPT_ID()l
extern _native int GRINGO_GET_MY_GRINGO_ID()l
extern _native32(0xBBB2780E) int _GRINGO_IS_BREAK_TOGGLE_SET()l
extern _native32(0x761BA4BD) void _GRINGO_SET_ALL_USE_CASE_OWNERS(int pram0, int pram1)l
extern _native32(0x6E86FCB5) void _GRINGO_SET_USE_CASE_OWNER(int pram0, int pram1, int pram2)l
extern _native32(0x89DE8A75) void _GRINGO_SET_CHILD_ACTIVATIONS(int pram0, int pram1)l
extern _native32(0x53B9569C) void _GRINGO_SET_COMMON_LAYER_ACTIVATIONS(int pram0, int pram1)l
extern _native int GRINGO_HANDLES_MOVEMENT(int pram0)l
extern _native bool IS_GRINGO_COMPONENT_VALID(int pram0)l
extern _native32(0xA766EA5C) int _GRINGO_COMPONENT_OF_NAME(int pram0, int pram1)l
extern _native int GRINGO_GET_COMPONENT_HASH(int pram0)l
extern _native int GRINGO_IS_COMPONENT_OF_TYPE(int pram0, int pram1)l
extern _native int GRINGO_GET_FIRST_NAMED_CHILD(int pram0, int pram1, int pram2)l//_GRINGO_GET_FIRST_TYPED_CHILD_COMPONENT_FUNC 0xE4C686BA
extern _native int GRINGO_GET_FIRST_CHILD(int pram0, int pram1)l//0x3E8F94BE
extern _native32(0xDD807723) int _GRINGO_GET_INDEX_OF_TYPED_CHILD_COMPONENT_FUNC(int pram0, int pram1, int pram2, int pram3)l
extern _native int UNK_0xD6EE9534(int pram0, int pram1, int pram2)l
extern _native int GRINGO_GET_CHILD_COMPONENT_COUNT(int pram0)l
extern _native int GRINGO_GET_INDEXED_CHILD_COMPONENT(int pram0, int pram1)l//NET_POSSE_GET_CARRIAGE_OCCUPIED what foxxy and roulette had
extern _native int GRINGO_GET_PROP_FROM_COMPONENT(int pram0)l
extern _native int GRINGO_GET_PROP_FROM_COMPONENT_EXT(int pram0, int pram1)l
extern _native int GRINGO_GET_PARENT_COMPONENT(int pram0, int pram1)l
extern _native int GRINGO_GET_USER_POS_WITH_OFFSET(int pram0, int pram1, int pram2)l
extern _native void GRINGO_SET_MESSAGE_RETURN(int pram0)l
extern _native int GRINGO_GET_MSG_COMPONENT_CONTEXT()l
extern _native bool GRINGO_HAS_PENDING_MESSAGE()l
extern _native int GRINGO_GET_MESSAGE_TYPE()l
extern _native Actor GRINGO_GET_REQUESTING_ACTOR()l//_GRINGO_GET_USE_REQUEST_ACTOR 0x2F096285
extern _native void GRINGO_SET_REQUEST_STRING(int pram0)l
extern _native32(0x8CAF5C5C) void _GRINGO_SET_REQUEST_FAIL_REASON(int pram0)l
extern _native int GRINGO_IS_FORCE_QUITTING()l
extern _native int GRINGO_IS_CAPABLE_OF_USE(int pram0, int pram1)l
extern _native int GRINGO_SHOULD_SUSPEND_MOVER(int pram0)l
extern _native int GRINGO_SHOULD_FIX_MOVER(int pram0)l
extern _native int GRINGO_GET_USE_COMPONENT_POSITION(int pram0, int pram1)l
extern _native int GRINGO_GET_USE_COMPONENT_POSITION_EXT(int gringo, char* unk1, int pram2)l
extern _native int GRINGO_GET_USE_COMPONENT_OFFSET_POSITION_EXT(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5)l
extern _native int GRINGO_GET_USE_COMPONENT_EXT(int pram0, int pram1)l
extern _native int GRINGO_GET_USE_COMPONENT_POSITION_LOCAL(int pram0, int pram1)l
extern _native32(0x51581898) int _GRINGO_REQUIRES_OBSTACLE(int pram0)l
extern _native32(0xD62D413C) int _GRINGO_IS_AUTO_PLAYER_USE(int pram0)l
extern _native int GRINGO_GET_TASKED_USER_EXTERNAL(int pram0, int pram1)l
extern _native32(0x8C2914C4) void _GRINGO_GET_LAST_USER_REQUEST_TIME(int pram0, int pram1)l
extern _native int GRINGO_GET_USE_COMPONENT_HEADING(int pram0)l
extern _native float GRINGO_GET_USE_COMPONENT_HEADING_EXT(int gringo, char* actorClass)l
extern _native void GRINGO_SET_AVAILABILITY(int gringo, bool set)l
extern _native bool GRINGO_GET_AVAILABILITY(int gringo1, const char* gringo2)l
extern _native int GRINGO_SET_AVAILABILITY_EXT(int pram0, int pram1, int pram2)l
extern _native int GRINGO_GET_REQUEST_MID_ACTION()l
extern _native void GRINGO_SET_COMPONENT_USER(int pram0, int pram1)l
extern _native int GRINGO_GET_COMPONENT_USER(int pram0)l
extern _native void GRINGO_CLEAR_COMPONENT_USER(int pram0)l
extern _native int GRINGO_QUERY_NAMED_COMPONENT_USER(int pram0, int pram1)l
extern _native int GRINGO_REWARD_ACTOR(int pram0, int pram1, int pram2)l//_GRINGO_APPLY_REWARD 0x217B4264
extern _native int GRINGO_REPORT_USE_FINISHED(Actor actor, bool unk)l
extern _native int GRINGO_WAS_USE_SUCCESSFUL(int pram0)l
extern _native void GRINGO_SATISFY_MOTIVES_OF_ACTOR(int pram0, int pram1)l
extern _native32(0xE18BCD70) int _GRINGO_START_ANIMATION_ON_ACTOR(int pram0, int pram1, int pram2)l
extern _native bool GRINGO_IS_ACTOR_PLAYING_ANIM(int pram0, int pram1)l//_GRINGO_IS_PLAYING_ANIM 0x35279C3F
extern _native int GRINGO_RETURN_ACTOR_TO_DEFAULT_ANIMS(int pram0)l
extern _native bool GRINGO_OWNS_ACTOR_ANIMS(Actor actor)l
extern _native32(0xB8C419C3) int _GRINGO_START_ANIMATION_ON_ACTOR_WITH_PROP_COMPONENT(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5)l
extern _native32(0xB9AE52F) void _GRINGO_ACTOR_DROP_ALL_PROPS(int pram0)l
extern _native int ATTACH_PROP_TO_ANIM(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5)l//_GRINGO_ATTACH_PROP_COMPONENT_TO_ANIM 0x436C0BF
extern _native int UNK_0x4DB7C61C(int pram0, int pram1, int pram2, int pram3, int pram4)l
extern _native int GRINGO_GET_PROP_ATTACH_SLOT(int pram0)l
extern _native int ATTACH_SLOT_FROM_STRING(int pram0)l//_GRINGO_ATTACH_SLOT_FROM_STRING 0x4A61BD63
extern _native32(0xADBF3ADF) int _GRINGO_GET_ANIM_AST_FILENAME(int pram0)l
extern _native32(0x721FC9A4) int _GRINGO_GET_ANIM_ACT_FILENAME(int pram0)l
extern _native32(0x87BA5FE9) int _GRINGO_GET_ANIM_AST_SPECIFIC_FILENAME(int pram0, int pram1)l
extern _native32(0x6263F909) int _GRINGO_GET_ANIM_ACT_ROOTNODE(int pram0)l
extern _native32(0xB555A648) int _GRINGO_IS_SUBNODE_PLAYING_BY_HASH(int pram0, int pram1, int pram2)l
extern _native32(0xAFD53217) int _GRINGO_PLAY_NODE_BY_HASH(int pram0, int pram1, int pram2)l
extern _native int GRINGO_ACTOR_FACE(int pram0, int pram1, int pram2)l
extern _native int GRINGO_ACTOR_MOVE_TO(int pram0, int pram1, int pram2, int pram3, int pram4)l
extern _native int GRINGO_ACTOR_MOVE_TO_AND_FACE(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5, int pram6, int pram7, int pram8)l
extern _native int UNK_0xEEE9C799(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5, int pram6, int pram7, int pram8, int pram9)l//_GRINGO_ACTOR_MOVE_TO_AND_FACE_2
extern _native void GRINGO_SET_PROP_COLLISIONS(int pram0, int pram1)l
extern _native32(0x6BA667B5) void _GRINGO_VALIDATE_PROP(int pram0)l
extern _native bool GRINGO_IS_PROP_READY(int pram0)l
extern _native int GRINGO_GET_PHYSINST(int pram0)l//_GRINGO_GET_PHYS_INST_FROM_COMPONENT 0x5EC1CABF
extern _native void GRINGO_PROP_RESET_GRACEFULLY(int pram0)l
extern _native int GRINGO_IS_TARGET_OBJECT_READY()l
extern _native int GET_GRINGO_BOOL_ATTR(int pram0, int pram1, int pram2)l//_GRINGO_GET_BOOL_ATTR 0xFACF08C7
extern _native int GET_GRINGO_INT_ATTR(int pram0, int pram1, int pram2)l//_GRINGO_GET_INT_ATTR 0x8A86AF8B
extern _native32(0x869D5D92) int _GRINGO_GET_REF_ATTR(int pram0, int pram1, int pram2)l
extern _native int GET_GRINGO_STRUCT_ATTR(int pram0, int pram1, int pram2, int pram3)l//_GRINGO_GET_SP_ATTR 0xFA22A365
extern _native int GET_GRINGO_FLOAT_ATTR(int pram0, int pram1, int pram2)l//_GRINGO_GET_FLOAT_ATTR 0x2EFD2B55
extern _native int GET_GRINGO_VECTOR_ATTR(int pram0, int pram1, int pram2)l//_GRINGO_GET_VECTOR_ATTR 0x5851C408
extern _native32(0x1F74EE6C) int _GRINGO_GET_RELATIVE_POSITION_VECTOR_ATTRIBUTE(int pram0, int pram1, int pram2)l
extern _native32(0x7E4681E8) int _GRINGO_GET_RELATIVE_ORIENTATION_VECTOR_ATTRIBUTE(int pram0, int pram1, int pram2)l
extern _native int GET_GRINGO_STRING_ATTR(int pram0, int pram1, int pram2)l//_GRINGO_GET_STRING_ATTR 0x6BA58AC7
extern _native int SET_GRINGO_BOOL_ATTR(int pram0, int pram1, int pram2)l//_GRINGO_SET_BOOL_ATTR 0xCF6822D7
extern _native int SET_GRINGO_INT_ATTR(int pram0, int pram1, int pram2)l//_GRINGO_SET_INT_ATTR 0x377B2C54
extern _native32(0xAFF7D382) int _GRINGO_SET_REF_ATTR(int pram0, int pram1, int pram2)l
extern _native int SET_GRINGO_FLOAT_ATTR(int pram0, int pram1, int pram2)l
extern _native int SET_GRINGO_VECTOR_ATTR(int pram0, int pram1, int pram2)l//_GRINGO_SET_VECTOR_ATTR 0x5C6831F9
extern _native int GRINGO_QUERY_BOOL(int pram0, int pram1, int pram2, int pram3)l
extern _native int GRINGO_QUERY_INT(int pram0, int pram1, int pram2, int pram3)l
extern _native int GRINGO_QUERY_OBJECT_REF(int gringo, const char* pram1, const char* pram2, int pram3)l//_GRINGO_QUERY_REF 0x15D6F3C7
extern _native int GRINGO_QUERY_STRUCT(int pram0, int pram1, int pram2, int pram3, int pram4)l//_GRINGO_QUERY_SP 0x1528F08B
extern _native int GRINGO_QUERY_FLOAT(int pram0, int pram1, int pram2, int pram3)l
extern _native int GRINGO_QUERY_STRING(int pram0, int pram1, int pram2, int pram3)l
extern _native int GRINGO_QUERY_PROP(int pram0, int pram1)l
extern _native int GRINGO_UPDATE_BOOL(int pram0, int pram1, int pram2, int pram3)l
extern _native int GRINGO_UPDATE_INT(int pram0, int pram1, int pram2, int pram3)l
extern _native int GRINGO_UPDATE_OBJECT_REF(int pram0, int pram1, int pram2, int pram3)l//_GRINGO_UPDATE_REF 0x4685D538
extern _native int GRINGO_UPDATE_STRUCT(int pram0, int pram1, int pram2, int pram3, int pram4)l//_GRINGO_UPDATE_SP 0x4DE50AD9
extern _native int GRINGO_GET_ATTRIBUTE_COUNT(int pram0)l
extern _native int GRINGO_GET_ATTRIBUTE(int pram0, int pram1)l
extern _native bool GRINGO_IS_ATTRIBUTE_VALID(int pram0)l
extern _native int GRINGO_GET_ATTRIBUTE_HASH(int pram0)l
extern _native32(0xF0991C9F) int _GRINGO_GET_VECTOR_ATTRIBUTE_VALUE_FROM_HANDLE(int pram0, int pram1)l
extern _native32(0xD7BB1792) int _GRINGO_GET_STRING_ATTRIBUTE_VALUE_FROM_HANDLE(int pram0, int pram1)l
extern _native32(0xF573B7DE) bool _GRINGO_GET_INT_ATTRIBUTE_VALUE_FROM_HANDLE(int pram0, int pram1)l
extern _native32(0xBF322F5C) int _GRINGO_GET_ATTRIBUTE_TYPE_BY_HANDLE(int pram0)l
//////////////////////////////////
//DLC
/////////////////////////////////
extern _native void DLC_PRE_INIT_CONTENT()l
extern _native void DLC_INIT_CONTENT()l
extern _native32(0x57D9950B) void _FRAG_INIT_CLASS(const char* p0)l
extern _native32(0xF4D0807E) void _INIT_STRING_TABLE_STREAMABLES(int pram0, int pram1)l
extern _native bool DLC_IS_CONTENT_PURCHASED_FLAGS(int pram0)l
extern _native int UNK_0x2F78AEFA(int pram0)l//idk how many params it really has
//////////////////////////////////
//Net
/////////////////////////////////
extern _native void NET_SET_TUNING_PARAM(int p0, float p1)l
extern _native void UNK_0x50E637D7()l
extern _native void NET_LOG(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5, int pram6)l
extern _native int NET_DUMP_STATE()l
extern _native int NET_ENABLE_MULTIPLAYER(bool enable)l
extern _native bool NET_IS_MANAGER_INITIALIZED()l
extern _native bool NET_IS_IN_SESSION()l
extern _native int NET_IS_ONLINE_AVAILABLE()l
extern _native int NET_IS_CONNECTED_FOR_PLAY()l
extern _native int NET_GET_PLAYMODE()l
extern _native int NET_APPLY_PROTOCOL_MASK(int pram0)l
extern _native void NET_SET_SOCIAL_CLUB_URLS(const char* result, const char* p1, int p2)l
extern _native bool NET_IS_SESSION_HOST()l
extern _native int NET_IS_SESSION_CLIENT()l
extern _native void NET_GET_MAC_ADDRESS32(int pram0)l
extern _native int NET_GET_NAT_TYPE()l
extern _native bool NET_IS_BUSY()l
extern _native int NET_GET_NET_TIME()l
extern _native void NET_ENABLE_KICKING(int pram0)l
extern _native bool NET_IS_LOCAL_GAMER_ONLINE()l
extern _native int NET_GET_LOCAL_GAMER_NAME()l
extern _native void NET_APPLY_RELEVANCY_OVERRIDE()l
extern _native void NET_CLEAR_RELEVANCY_OVERRIDE()l
extern _native int GET_SLOT_FOR_HOST()l
extern _native int GET_NUM_PLAYERS()l
extern _native int NET_START_NEW_SCRIPT(int pram0, int pram1)l
extern _native int NET_SCRIPTMSG_SEND(int channelId, int headerSize, int* buffer, int count, bool pushToQueue)l
extern _native32(0xE2163ECC) int _NET_SCRIPTMSG_IS_PENDING(int channelId, int* data)l
extern _native32(0xB13DD691) int _NET_SCRIPTMSG_GET_NEXT(int channelId, int* buffer, int count)l
extern _native int NET_SCRIPTMSG_REGISTER_HANDLER(int pram0, int pram1)l
extern _native int NET_SCRIPTMSG_QUERY_HANDLER(int functionId, void* funcPtr)l
extern _native void REGISTER_HOST_BROADCAST_VARIABLES(int pram0, int pram1)l
extern _native void REGISTER_CLIENT_BROADCAST_VARIABLES(int pram0, int pram1)l
extern _native void UNREGISTER_HOST_BROADCAST_VARIABLES()l
extern _native void UNREGISTER_CLIENT_BROADCAST_VARIABLES()l
extern _native32(0xF81E2097) int _NET_IS_SLOT_VALID_IN_CLIENT_BROADCAST_VARIABLES(int pram0, int pram1)l
extern _native32(0x64C2DD40) int _NET_IS_CLIENT_DATA_VALID_FOR_ALL_SLOTS(int pram0, int pram1)l
extern _native32(0xA80C6DE6) int _NET_IS_DATA_VALID_FOR_ALL_SLOTS_IN_CLIENT_BROADCAST_VARIABLES(int pram0)l
extern _native bool NET_IS_OBJECT_LOCAL(Object obj)l
extern _native int NET_REQUEST_OBJECT(int pram0)l
extern _native32(0x47C5E353) void _NET_PUSH_OBJECT_REPLICATION_MODE(int pram0, int pram1)l
extern _native32(0x3932B786) void _NET_POP_OBJECT_REPLICATION_MODE(int pram0)l
extern _native bool NET_OBJECT_GET_REPLICATION_MODE(Actor actor)l
extern _native void NET_OBJECT_SET_REPLICATION_MODE(Actor actor, int pram2)l//SET_OBJECT_SCENE_GLOBAL_LOD what fox had, originally was _NET_VISIBILITY for invis mod
extern _native int NET_OBJECT_LOCK_OWNERSHIP(int pram0, int pram1)l
extern _native32(0x1306549E) void _NET_SET_REPLICATE_ALWAYS_TO_LAYOUT(int pram0, int pram1)l
extern _native32(0x5C4CAE3A) void _NET_SET_LAYOUT_OBJECTS_REPLICATE_TO_LAYOUT(int pram0)l
extern _native32(0x579C2014) int _NET_GET_SCRIPT_INT(int pram0)l
extern _native32(0x7837890B) void _NET_SET_EQUIP_TYPE(int equipType)l
extern _native32(0xA6D794FE) void _NET_SET_SCRIPT_INT(int pram0, int pram1)l
extern _native void UNK_0x1C147E14(int pram0, int pram1)l
extern _native int UNK_0xCA6231C1(int pram0)l
extern _native32(0xC09B114B) void _NET_SET_ALLOW_BLIP_SYNC(int pram0, int pram1)l
extern _native32(0x7284A71B) void _NET_SET_GRINGO_NAV_COMPLETE(int pram0, int pram1)l
extern _native int NET_GET_SESSION_GAMER_COUNT()l
extern _native int AWARD_ACHIEVEMENT(int achievement)l//int
extern _native bool HAS_ACHIEVEMENT_BEEN_PASSED(int achievement)l
extern _native int ARE_ACHIEVEMENTS_READY()l
extern _native int AWARD_AVATAR(int avatar)l
extern _native int NET_GET_POSSE_COUNT()l
extern _native bool NET_IS_POSSE_LEADER()l
extern _native int NET_GET_POSSE_LEADER_SLOT()l
extern _native int NET_GET_GAMER_POSSE_LEADER(int playerID)l
extern _native int NET_GET_GAMER_POSSE_SIZE(int playerID)l
extern _native int NET_POSSE_REMOVE_GAMER(int slotID)l
extern _native32(0x106CE441) int _NET_PARTY_IS_INVITE_PRESENT(int pram0)l//player colors (foxxyy had this??)
extern _native32(0x6A7B9FAD) int _NET_PARTY_IS_REQUEST_PRESENT(int pram0)l
extern _native int NET_RUN_SEARCH_BOT(int pram0)l
extern _native int NET_GET_NUMBER_OF_SESSIONS()l
extern _native int NET_IS_SEARCHBOT_BUSY()l
extern _native32(0xF6E40FF3) int _NET_SESSION_SET_SEARCHBOT_PARAMS(int pram0, int pram1, int pram2, int pram3, int pram4)l
extern _native32(0xC0849D70) void _NET_SESSION_USE_QUICK_MATCH_FILTER()l
extern _native32(0x8DF05A4F) int _NET_SESSION_QUICK_JOIN(int pram0)l//id??
extern _native int NET_SESSION_LEAVE_SESSION()l
extern _native bool NET_IS_FACTION_SAFE(int pram0)l
extern _native int NET_SESSION_START_GAMEPLAY()l
extern _native int NET_SESSION_END_GAMEPLAY()l
extern _native int NET_SESSION_SET_INVITABLE(int pram0)l
extern _native32(0xFA0E1F8B) int _NET_SET_SESSION_MAX_GAMERS_OVERRIDE(int playerCount)l//host? reduce players?
extern _native32(0xCC7D0431) int _NET_SET_SESSION_CLOSED(bool closed)l//host? Make public basically private?
extern _native bool NET_SESSION_IS_GAMEPLAY_STARTED()l
extern _native32(0xD923CD1B) void _NET_SET_QM_RANGE(int pram0, int pram1)l//QM quick match?
extern _native32(0x7540959C) int _NET_REQUEST_BECOME_GAME_HOST(int p0, int p1, int p2, int p3)l//0x7540959C what roulette has
extern _native void NET_SET_THIS_SCRIPT_IS_NET_SCRIPT(int pram0)l
extern _native void NET_UNREGISTER_AS_NET_SCRIPT()l
extern _native int NET_GET_SCRIPT_STATUS()l
extern _native int NET_IS_PLAYER_PARTICIPANT(int pram0)l
extern _native bool NET_IS_HOST_OF_THIS_SCRIPT()l
extern _native int NET_GET_HOST_OF_THIS_SCRIPT()l
extern _native void NET_ALLOW_PLAYERS_TO_JOIN(bool enable)l
extern _native bool NET_IS_SCRIPT_REGISTERED_AS_NET_SCRIPT()l
extern _native int NET_SCRIPT_GET_NUM_PARTICIPANTS()l
extern _native void SET_RICH_PRESENCE(int value1, int value2, int unk1, int unk2, int unk3)l //Last 3 params seems to be always zero...
extern _native32(0x50C18480) void _NET_SET_GAMER_DATA(char* text, int value)l
extern _native32(0xE5645CB3) int _NET_SET_KILL_EFFECT_ON()l
extern _native void NET_VOICE_BROADCAST_ENABLE()l
extern _native void NET_VOICE_BROADCAST_DISABLE()l
extern _native bool NET_ARE_UNLOCKS_READY()l
extern _native bool NET_IS_UNLOCKED(int netValue)l
extern _native int NET_GET_OVERLOAD_STATE_FOR_SLOT(int slotID)l
extern _native int NET_GET_AREA_OVERLOAD_STATE_FOR_SLOT(int pram0)l
extern _native32(0xE5645CB3) void _NET_SET_OVERLOAD_REDUCTION_LEVEL()l
extern _native void NET_SET_SYNC_PRIORITY_LIMITS()l
extern _native void UPDATE_PROFILE_STAT(const char* stat, int value, bool update)l
extern _native void UPDATE_STRING_PROFILE_STAT(int pram0, int pram1)l
extern _native32(0x97F15B69) int _NET_AH_LAG_HACK_KILL_PROTECTION_ENABLE(int p0, int p1, int p2, int p3)l
extern _native32(0xCA0739A8) int _NET_AH_LAG_HACK_MOVE_PROTECTION_ENABLE(int p0, int p1, int p2, int p3)l
extern _native void NET_BROADCAST_EXPLODE_TARGET_EVENT(Actor actor)l//_NET_EXPLODE_ACTOR
extern _native int DO_FILE_CRC(int p0, int p1, int p2)l
extern _native void FLAG_FILE_CRC_MISMATCH()l//force into modders pool
extern _native void NET_SET_UNLOCK(int netID)l//idk how many params but it may be 2, should be able to unlock the net id controlling ER now
//////////////////////////////////
//Player Names
/////////////////////////////////
extern _native void NET_GAMER_SET_ACTOR_OVERRIDE(Actor actor, int value)l
extern _native void NET_GAMER_SET_TEAM(int slot, int team)l
extern _native32(0xFD91BE0D) int _NET_GAMER_SET_MY_JPN_TITLE(int pram0)l
extern _native int NET_GAMER_GET_JPN_TITLE(int pram0)l
extern _native32(0xCE8F6304) void _NET_SET_PLAYER_SLOT_BARKER_ACCEPTED(int slotID)l
extern _native32(0xAB32D5D9) void _NET_SET_PLAYER_SLOT_BARKER_REJECTED(int slotID)l
extern _native void NET_GAMER_SET_TITLE(int slotID, const char* title)l
//_NET_GAMER_SET_ICON_LIFE 0x2357CA74
extern _native32(0x160E79C6) void _NET_GAMER_FORCE_ICON_VISIBLITY(int pram0, int pram1)l
extern _native32(0xB5DDEF68) void _NET_GAMER_SET_TIMER(int slotID, bool add)l
//_NET_GAMER_SET_ICON_FORCE_HIDDEN 0x34960D06
extern _native32(0xE783219A) void _NET_GAMER_FORCE_TEXT_VISIBLE_IF_ICON_INVISIBLE(int pram0)l
extern _native32(0x1958F478) void _NET_GAMER_SET_ICONS_FORCE_VISIBLE(int pram0)l//END_SCRIPTED_REQUEST what foxxyyy and rouletteboi had
extern _native32(0x2FB85996) void _NET_GAMER_SHOW_LOCAL_ICON(bool pram0)l
extern _native32(0xF34B8448) void _NET_GAMER_SET_STEALTH_LEVEL_FOR_ICONS(int pram0)l
extern _native32(0x796E66E7) void _NET_GAMER_SET_STEALTH_LEVEL_FOR_BLIPS(int pram0)l
extern _native32(0x650A7440) int _NET_GAMER_PROCESS_TUNE_VALUE(int pram0, int pram1)l
extern _native void NET_GAMER_SET_ICON_STEALTH_OVERRIDE(int slotID, int unkValue)l
extern _native void NET_GAMER_SET_BLIP_STEALTH_OVERRIDE(int slotID, int unkValue)l
extern _native void NET_GAMER_SET_BLIP_OVERRIDE(int slotID, int blipID)l
extern _native32(0x08D84437) void _NET_GAMER_SET_BLIPS_FORCE_VISIBLE(int pram0)l
extern _native32(0x784F04DD) void _NET_GAMER_SHOW_BLIPS_FOR_POSSE_MEMBERS(int pram0)l
//NET_GAMER_SET_BLIP_FORCE_HIDDEN 0x3DD6E36A
extern _native32(0xE5FE0A6A) void _NET_GAMER_SHOW_PLAYER_BLIPS_ON_FULL_MAP(int pram0)l
//NET_GAMER_IS_BLIP_VISIBLE 0x25F8C46A
extern _native32(0x3248D20E) void _NET_GAMER_TREAT_COVER_STATE_AS_ALIVE_FOR_BLIPS(int pram0)l
extern _native bool NET_POSSE_GET_LEADER_WAYPOINT(vector3 * outCoords)l
extern _native int NET_POSSE_IS_LEADER_WAYPOINT_VALID()l
//////////////////////////////////
//Score Graph
/////////////////////////////////
extern _native void NET_SCOREGRAPH_SETUP(int pram0, int pram1, int pram2)l
extern _native void NET_SCOREGRAPH_CLEAR_MARKERS()l
extern _native void NET_SCOREGRAPH_ADD_PLAYER_SCORE(int pram0, int pram1, int pram2, int pram3)l
extern _native void NET_SCOREGRAPH_ADD_PLAYER_LABEL(int pram0, int pram1, int pram2, int pram3)l
extern _native void NET_SCOREGRAPH_ADD_TEAM_SCORE(int pram0, int pram1, int pram2, int pram3)l
extern _native void NET_SCOREGRAPH_ADD_TEAM_LABEL(int pram0, int pram1, int pram2, int pram3)l
//////////////////////////////////
//Score Table Current Item
/////////////////////////////////
extern _native void NET_PLAYER_LIST_SET_CURRENT_ITEM(int pram0)l
extern _native int NET_PLAYER_LIST_SET_CURRENT_ITEM_BY_SLOT(int pram0)l
extern _native int NET_PLAYER_LIST_SET_CURRENT_ITEM_MSCORE_STRING(int menuColumna, char* text)l // draws right text
extern _native int NET_PLAYER_LIST_SET_CURRENT_ITEM_MSCORE_INT(int pram0, int pram1)l
extern _native int NET_PLAYER_LIST_SET_CURRENT_ITEM_TEAM(int groupColor)l //team but also controlls color due to team based
extern _native void NET_PLAYER_LIST_SET_CURRENT_ITEM_PRIORITY(int pram0)l
extern _native int NET_PLAYER_LIST_SET_CURRENT_ITEM_DEAD(int pram0)l
//////////////////////////////////
//Score Table
/////////////////////////////////
extern _native void NET_PLAYER_LIST_RESET()l
extern _native int NET_PLAYER_LIST_ADD_ITEM(char* text, int menuEntry)l//we had const char*
extern _native int NET_PLAYER_LIST_ADD_GAMER_SLOT(int pram0, int pram1)l
extern _native void NET_PLAYER_LIST_SET_HIGHLIGHT(int menuIndex)l
extern _native void NET_PLAYER_LIST_SET_TOP_TEAM(int pram0)l
extern _native void NET_PLAYER_LIST_SET_TEAM_SCORE(int team, int probScore, const char* uiString)l
extern _native void NET_PLAYER_LIST_SET_TEAM_SORT(bool disable)l
extern _native void NET_PLAYER_LIST_SET_TITLE(char* entry)l
extern _native void NET_PLAYER_LIST_SET_TEMPLATE(int menuTemplate)l
extern _native void NET_PLAYER_LIST_SET_HEADER(int menuColumna, char* entry)l
extern _native void NET_PLAYER_LIST_SET_DESCRIPTION(const char* uiSubtitle)l
extern _native void NET_PLAYER_LIST_TIMER_SET(int pram0)l
extern _native32(0xD4C7E0D5) void _NET_PLAYER_LIST_SET_TIMER_ENABLE_FLASHING(int pram0)l
//////////////////////////////////
//UI Net
/////////////////////////////////
extern _native int NET_GET_AND_CLEAR_GAME_MODE_REQUEST()l
extern _native int NET_GET_AND_CLEAR_PLAYLIST_REQUEST()l
extern _native int NET_GET_AND_CLEAR_QUIT_GAME_REQUEST()l
extern _native int NET_GET_FREE_ROAM_MODE()l //returns 0, 1 or 2
extern _native void NET_SET_FREE_ROAM_MODE(int mode)l //0, 1 or 2 (normal, hardcore, friendly)
extern _native void NET_REGISTER_GAME_TYPE(char* pram0, int pram1)l
extern _native void NET_REGISTER_PLAYLIST_TYPE(int pram0, int pram1, int pram2)l
extern _native void NET_SET_PLAYLIST_LOCKED(int pram0, int pram1)l
extern _native32(0x03962973) int _NET_GET_JOIN_WISH_PAD()l
extern _native int NET_AUTHENTICATE_GAMER(int val, const char* netAction)l
//_NET_GET_PLAYER_COLOR 0xC00C8C94
extern _native32(0x9BC05C90) const char* _NET_GET_COLORED_GAMER_NAME(int slotID, int value)l
extern _native bool NET_GET_GAMER_RGB_COLOR(int slotID, float* r, float* g, float* n)l
extern _native32(0xFE83A4FE) bool _NET_IS_RADAR_BLIP_VISIBLE_FOR_GAMER(float value)l
extern _native32(0x8DEC3E03) void _NET_SYS_UI_SET_POSITION(vector3 pos)l
extern _native void NET_PLAYER_BARKER_RESET(int slotID, int pram1, int pram2, int pram3)l
extern _native int NET_GET_USING_SPHERE_CURVES(int pram0)l
extern _native void NET_PLAYER_SHOW_CONTEXT_MENU(int playerSlot, const char* event)l
extern _native void NET_TICKER_REPORTF(char* text1, char* text2, char* text3, int pram3, int pram4, int pram5, int pram6)l//_PRINT_CHAT
extern _native void NET_TICKER_CLEAR()l//clears killfeed text aka print chat
extern _native32(0xA6403262) void _NET_XPCOUNTER_REPORT_CHANGE(int pram0, int pram1)l
//////////////////////////////////
//Net Session
/////////////////////////////////
extern _native32(0x79AFAB1F) int _NET_SESSION_GET_NORMALIZE_POSITION(int pram0, int pram1)l
extern _native32(0x581CAC89) int _NET_SESSION_GET_CURRENT_SEARCH_GENERATION()l
extern _native32(0xA174152C) int _NET_SESSION_GET_GENERATION_FOR_NET_SESSION_OBJECT(int pram0)l
extern _native32(0x0183A3F0) int _NET_SESSION_GET_JOINED_GENERATION_FROM_NET_SESSION_OBJECT(int pram0)l
extern _native32(0x63034F52) int _NET_SESSION_JOIN_NET_SESSION_FROM_OBJECT(int pram0)l
extern _native32(0xE9EAC45C) int _NET_GET_SESSION_GAMEMODE_TYPE(int pram0)l
extern _native32(0xBDF22FCA) int _NET_IS_SESSION_CURRENTLY_JOINED_SESSION(int pram0)l
extern _native32(0x9EA132A3) void _NET_SESSION_SET_LOCALE(int pram0)l//figure how to pull this data
extern _native void NET_SESSION_SET_GAME_MODE_TYPE(int gameMode)l
//////////////////////////////////
//Net Gametype Instance Data
/////////////////////////////////
extern _native32(0x55C5BB93) int _NET_GAMETYPE_ADD_GAMETYPE_ENTRY(int pram0)l
extern _native32(0xFAD5A270) bool _NET_GAMETYPE_GET_GAMETYPE_ENTRY(int pram0, int pram1)l
extern _native32(0x4A721118) int _NET_GAMETYPE_ITERATOR_START(int pram0)l
extern _native32(0x4500B98A) int _NET_GAMETYPE_ITERATE_NEXT(int pram0)l
extern _native32(0x85049505) int _NET_GAMETYPE_SET_REGION_FOR_GAMETYPE(int pram0, int pram1)l
extern _native32(0x5C51D43C) int _NET_GAMETYPE_ADD_PLAYLIST(int pram0, int pram1)l
extern _native32(0x0E2C4B68) int _NET_GAMETYPE_GET_PLAYLIST(int pram0, int pram1)l
extern _native32(0xB514ECA7) int _NET_GAMETYPE_GET_PLAYLIST_BY_NAME(int pram0, int pram1)l
//////////////////////////////////
//Net Stats
/////////////////////////////////
extern _native void NET_UPDATE_LEADERBOARD(int pram0, int pram1, int pram2, int pram3)l
extern _native32(0x4D0C8AA4) void _NET_START_LEADERBOARD_UPDATE(int pram0)l
extern _native32(0x89277EA3) void _NET_END_LEADERBOARD_UPDATE()l
extern _native void NET_CREATE_FRIEND_SCORE_READER(int pram0)l
extern _native void NET_REPORT_FRIEND_SCORES(int pram0, int pram1, int pram2)l
extern _native32(0x87A3A38D) void _NET_GET_SCORE_INFO_FOR_LOCAL_GAMER(int pram0)l
extern _native32(0xD7572C68) void _NET_GET_SCORE_FOR_TOP_SELECTED_FRIEND(int pram0)l
extern _native32(0x76F09F04) int _NET_GET_TOP_SELECTED_FRIEND_NAME()l
extern _native32(0xA684E813) int _NET_GET_SLOT_FOR_TOP_SELECTED_FRIEND()l
extern _native32(0xE5C5CE63) int _NET_IS_FRIEND_DATA_AVAILABLE()l
extern _native32(0x4F652A00) int _NET_GET_RANK_FOR_LOCAL_GAMER()l
extern _native32(0xFC564903) int _NET_GET_SELECTED_FRIEND_RANK()l
extern _native32(0x7154D15B) void _NET_SELECT_NEAREST_FRIENDS()l
extern _native32(0x86BC0A55) int _NET_CREATE_CHALLENGE_LB_READER(int pram0, int pram1)l
extern _native32(0xEB4A6D85) void _NET_DESTROY_CHALLENGE_LB_READER()l
extern _native32(0x5FD52711) int _NET_DOES_CHALLENGE_LB_READER_EXIST()l
extern _native32(0xD0808C42) int _NET_IS_CHALLENGE_LB_READ_COMPLETE()l
extern _native32(0x097BB984) int _NET_IS_LOCAL_GAMER_INFO_VALID_FOR_CHALLENGE_LB()l
extern _native32(0xEA7ADF42) int _NET_GET_LOCAL_GAMER_NAME_FOR_CHALLENGE_LB()l
extern _native32(0x3A8C77AD) int _NET_GET_LOCAL_GAMER_STATS_FOR_CHALLENGE_LB(int pram0)l
extern _native32(0xE89C6E4F) int _NET_IS_TOP_FRIEND_INFO_VALID_FOR_CHALLENGE_LB()l
extern _native32(0x0791F35A) int _NET_GET_TOP_FRIEND_NAME_FOR_CHALLENGE_LB()l
extern _native32(0x49C2B05F) int _NET_GET_TOP_FRIEND_STATS_FOR_CHALLENGE_LB(int pram0)l
extern _native32(0xC813DBEF) int _NET_IS_TOP_SCORER_INFO_VALID_FOR_CHALLENGE_LB()l
extern _native32(0xE6B4F505) int _NET_GET_TOP_SCORER_NAME_FOR_CHALLENGE_LB()l
extern _native32(0x70AF0351) int _NET_GET_TOP_SCORER_STATS_FOR_CHALLENGE_LB(int pram0)l
extern _native32(0x293C3288) int _NET_IS_SCORER_ABOVE_PLAYER_INFO_VALID_FOR_CHALLENGE_LB()l
extern _native32(0xA7F231B0) int _NET_GET_SCORER_ABOVE_PLAYER_NAME_FOR_CHALLENGE_LB()l
extern _native32(0x984749B4) int _NET_GET_SCORER_ABOVE_PLAYER_STATS_FOR_CHALLENGE_LB(int pram0)l
//////////////////////////////////
//Entity Component
/////////////////////////////////
extern _native void SET_DRAW_ACTOR(Actor actor, bool draw)l
extern _native bool GET_DRAW_ACTOR(Actor actor)l
//////////////////////////////////
//PPP Elements
/////////////////////////////////
extern _native32(0x598815BD) void _SET_WANTED_OPACITY(int pram0)l
extern _native32(0xD1C91A7F) void _SCR_FIRE_BLOOD_SPLAT(int pram0, int pram1, int pram2, int pram3)l
extern _native32(0x7E0CDD87) void _CLEAR_DEATH_EFFECT()l
extern _native32(0xE6C1DBD9) void _BINOCULARS_SET_ACTIVE(int pram0)l
extern _native32(0x00EF33EF) int _BINOCULARS_IS_LOADED()l
extern _native32(0x598815BD) void _SET_ZOMBIE_MODE(bool enable)l
extern _native32(0xE613AE52) void _SET_TEXTURE_OPACITY(int pram0)l
extern _native32(0x84F3DD81) void _SET_TEXTURE_POSITION(float pram0, float pram1)l
extern _native32(0xF55B50ED) void _SET_TEXTURE_ENABLED(int pram0)l
extern _native32(0x6336182D) void _SET_TEXTURE_NAME(int pram0)l
extern _native32(0x3A6960B2) void _SET_TEXTURE_SCALE(int pram0)l
//////////////////////////////////
//World Movie
/////////////////////////////////
extern _native32(0x7614AEBA) void _START_WORLD_MOVIE(const char* bikPath, int theater)l // 0 = armadillo, 1 = blackwater
extern _native32(0x69FC319E) void _STOP_WORLD_MOVIE()l
extern _native32(0xD036DF91) int _IS_WORLD_MOVIE_PLAYING()l
//////////////////////////////////
//Icon
/////////////////////////////////
extern _native32(0x724B4E9B) void _ADD_ICON_CB(int pram0, int pram1)l
//////////////////////////////////
//Gravestone
/////////////////////////////////
extern _native32(0xF62EE158) int _GRAVESTONE_IS_CURRENT_SECTOR_READY()l
extern _native32(0x449D4A89) void _GRAVESTONE_SET_CURRENT_SECTOR(int pram0)l
extern _native int CREATE_GRAVESTONE_TEXT_IN_LAYOUT(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5)l
extern _native32(0x211DE185) int _CREATE_GRAVESTONE_TEXT_AT_LOCATOR(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5, int pram6, int pram7, int pram8, int pram9)l
extern _native Object CREATE_MP_TEXT(Object prop, const char* unkStr, const char* textToDisplay, vector3 position, vector3 rotation, bool maybeIsStringLiteral)l//_CREATE_GRAVESTONE_TEXT 0x5BF5A39C
//////////////////////////////////
//Fx
/////////////////////////////////
extern _native void UNK_0xA5A6A3E3(int pram0, int pram1, int pram2)l
extern _native int UNK_0x3736FF43(int pram0)l
//0x65B4197
extern _native void CLEAR_DECALS()l//_FX_CLEAR_DECALS 0x43939FD8
extern _native void CREATE_DECAL(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5, int pram6)l//_FX_CREATE_DECAL 0x21588246
extern _native void CREATE_DIRECTION_DECAL(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5, int pram6, int pram7, int pram8)l//_FX_CREATE_DIRECTIONAL_DECAL 0xFB4CFBA0
extern _native void CREATE_DECAL_WITH_NORMAL(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5, int pram6, int pram7, int pram8, int pram9, int pram10)l//_FX_CREATE_DECAL_WITH_NORMAL 0x7BCE4845
//_FX_CREATE_FOOT_PRINT 0x9E54C297
extern _native32(0x013A0D25) void _FX_SET_MELEE_MARKER_POS(int pram0, int pram1, int pram2)l
extern _native32(0x1182C34F) void _FX_SET_MELEE_MARKER_SIZE(int pram0)l
extern _native32(0xD0FB6AF0) void _FX_SET_MELEE_MARKER_COLOR(int pram0, int pram1, int pram2, int pram3)l
extern _native32(0xC00F8181) void _FX_SET_MELEE_MARKER_STROBE_INTENSITY(float intensity)l
extern _native32(0x4897DD37) void _FX_ENABLE_SCRIPT_MELEE_MARKER(bool enable)l
extern _native void PPP_LOAD_PRESET(const char* pppElement)l
extern _native void PPP_UNLOAD_PRESET(const char* pppElement)l
extern _native void PPP_SET_ELEMENT_MAGNITUDE(int pram0, int pram1)l
extern _native int PPP_GET_ELEMENT_MAGNITUDE(int pram0)l
extern _native void CANCEL_DEADEYE()l
extern _native32(0xFA43DCC5) void _FX_FIRE_SCRIPT(int pram0)l
extern _native void SET_SHOCK_SPEED(int pram0)l
extern _native void SET_SHOCK_AMPLITUDE(int pram0)l
extern _native void DOF_PUSH()l//_FX_PUSH_DOF 0xF665F9D1
extern _native void DOF_POP()l//_FX_POP_DOF 0x5EBE0C41
extern _native void DOF_SET(int pram0, int pram1, int pram2, int pram3)l//_FX_SET_DOF 0xEA8964CC
extern _native void DOF_SET_KERNEL(int pram0)l//_FX_SET_DOF_KERNEL 0x47A8DDED
extern _native32(0x3B32AB84) int _FX_CREATE_GLOW_INDICATOR_ATTACHED(int pram0, int pram1, int pram2, int pram3)l
extern _native void REMOVE_GLOW_INDICATOR(int pram0)l
extern _native void CREATE_OBJECT_GLOW(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5)l
extern _native void DESTROY_OBJECT_GLOW(int pram0)l//_FX_REMOVE_GLOW_FROM_OBJECT 0xFC261530
extern _native void CLEAR_TUMBLEWEEDS()l
extern _native void ALLOW_TUMBLEWEEDS(bool allow)l
extern _native int ADD_ZOMBIE_TO_ACTOR(int pram0, int pram1, int pram2)l
extern _native void ADD_BLOOD_TO_ACTOR(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5, int pram6)l
//ADD_BLOOD_TO_CORPSE 0x50904C66
extern _native void CLEAR_CHARACTER_BLOOD()l
extern _native void CLEAR_PLAYER_BLOOD()l
extern _native void SET_PLAYER_BLOOD_FADE_RATE(float rate)l
extern _native void PRICK_PLAYER_FINGER(Actor actor)l
extern _native void BURN_ACTOR(int pram0, int pram1, int pram2)l
extern _native void LIMIT_BLOOD_ON_ACTOR(int pram0, int pram1)l
extern _native void LOAD_PTFX_DLC_ASSETS(int pram0)l
extern _native32(0xA0AE0C98) void _FX_ADD_SHADER(int pram0, int pram1)l
//////////////////////////////////
//Time of Day
/////////////////////////////////
extern _native32(0x7C3D1193) int _TIME_OF_DAY_AS_MINUTES(int pram0)l
//GET_TIME_OF_DAY_AS_INT 0x61A2A3C
extern _native int GET_TOTAL_MINUTES(int pram0)l//_GET_TOD_TOTAL_MINUTES 0xC52F07A8
extern _native int UNK_0x57FC0E16(int pram0)l
extern _native void SET_DAY(int pram0)l
extern _native int GET_HOUR(Time T)l
extern _native int GET_MINUTE(Time time)l
extern _native int GET_SECOND(Time time)l
extern _native int GET_DAY(Time T)l
extern _native void ADD_TIME(int pram0, int pram1, int pram2, int pram3, int pram4)l
extern _native void ADD_TIME_USING_TIME_OF_DAY(int pram0, int pram1)l
extern _native Time GET_TIME_OF_DAY()l
extern _native Time MAKE_TIME_OF_DAY(int hour, int minute, int second)l
extern _native int MAKE_TIME_OF_DAY_EX(int pram0, int pram1, int pram2, int pram3)l
extern _native int UNK_0x2DB3AC0F(int pram0, int pram1)l
extern _native int UNK_0x9C9529D8(int pram0, int pram1)l
extern _native int TIME_IS_IN_RANGE(int pram0, int pram1, int pram2)l
extern _native void ADVANCE_TIME_HOURS(int pram0)l
extern _native void SET_TIME_OF_DAY(Time unixTime)l
extern _native void SET_TIME_ACCELERATION(int pram0)l
extern _native int GET_TIME_ACCELERATION()l
extern _native void SET_TIME_WARP(int p0)l
extern _native void CANCEL_TIME_WARP(bool cancel)l
//////////////////////////////////
//HUD GUI
/////////////////////////////////
extern _native int GUI_MAKE_WINDOW(GUIWindow Parent, int pram1, const char* WindowName, const char* pram3)l
extern _native int GUI_MAKE_TEXT(int GUIHandle, SizedArray Position, const char* MenuTitle, const char* textFont, float size)l
extern _native int GUI_MAKE_OVERLAY(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5)l
extern _native32(0xF6207DF5) GUIWindow _GUI_GET_WINDOW(int GUIHandle, const char* windowName)l
extern _native int UNK_0xA7FF2899(int pram0, int pram1, int pram2)l
extern _native int GUI_CLOSE_WINDOW(GUIWindow window)l
extern _native bool GUI_WINDOW_VALID(GUIWindow window)l
extern _native int GUI_SET_TEXT(int TextHandle, const char* MenuName)l
extern _native int GUI_SET_TEXT_JUSTIFY(int TextHandle, int JustifyType)l
extern _native int GUI_SET_TEXT_COLOR(int TextHandle, float* ColorArea)l
extern _native GUIWindow GUI_MAIN_WINDOW()l
//0xB498108A
//0xC7DEB717
extern _native int UNK_0xD019FF37(int pram0)l
//0x4803C120
extern _native const char* UNK_0xFA6BDD8E(float value, int unk, int precision)l
extern _native const char* UNK_0x47EF426D(int GTLValue)l
extern _native int UNK_0x52C10147(int pram0)l
extern _native int FLOAT_TO_STRING_VERBOSE(int pram0)l
extern _native32(0x8ED1FF95) const char* _FLOAT_TO_STRING(float value, int unk, int precision)l
extern _native const char* INT_TO_STRING(int i)l
extern _native const char* VECTOR_TO_STRING(vector3 * vector)l
//////////////////////////////////
//HUD
/////////////////////////////////
extern _native void UI_SET_PROMPT_STRING(int pram0, int pram1)l
extern _native void UI_SET_PROMPT_ICON(int pram0, int pram1)l
extern _native void UI_HIDE_PROMPT(int pram0)l
extern _native int FLASH_SET_BOOL(int pram0, int pram1, int pram2)l
extern _native int FLASH_SET_INT(const char* scaleformName, const char* scaleformVarName, int value)l
extern _native int FLASH_SET_FLOAT(int pram0, int pram1, int pram2)l
extern _native int FLASH_SET_ARRAY_INT(int pram0, int pram1, int pram2, int pram3)l
extern _native int FLASH_SET_STRING(const char* scaleformName, const char* scaleformVarName, int pram2, int pram3)l
extern _native int FLASH_SET_ARRAY_STRING(int pram0, int pram1, int pram2, int pram3, int pram4)l
//FLASH_GET_BOOL 0xFA266B15
extern _native int FLASH_GET_INT(const char* scaleformName, const char* scaleformVarName)l
extern _native int FLASH_GET_FLOAT(int pram0, int pram1)l
extern _native32(0xE39B92B7) int _SET_FLASH_STRING_FORMATTED_ARRAY_VARIABLE(const char* pram0, const char* pram1, int pram2, int pram3, int pram4, int pram5, int pram6, int pram7, int pram8)l
extern _native void PRINT_BIG(const char* text, int pram1, float time, int pram3, int pram4)l
extern _native void PRINT_SMALL_B(char* text1, float time, bool isStringLiteral, int unk2, int unk3, char* text2, char* text3)l
extern _native void PRINT_HELP_B(const char* txt, float time, bool playSound, int p3, int p4, bool p5, const char* unk, const char* audioName)l
extern _native void PRINT_OBJECTIVE_B(char* txt, float time, bool isStringLiteral, int printType, bool pram4, const char* pram5, bool pram6, const char* pram7)l//first param we had const char*
extern _native void PRINT_MONEY(int statID, float statValue, int pram2, float time, int unk, const char* soundAlert)l
extern _native void PRINT_BIG_FORMAT(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5, int pram6, int pram7)l
extern _native void PRINT_SMALL_FORMAT(int unk1, char* text, char* fmt1, char* fmt2, char* fmt3, char* fmt4, int unk2, int unk3, int unk4)l
extern _native void PRINT_OBJECTIVE_FORMAT(float time, char* entry, char* name, int unk1, int unk2, int unk3, int unk4, int unk5, int unk6, int unk7, int unk8)l
extern _native void PRINT_HELP_FORMAT(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5, int pram6, int pram7, int pram8)l
extern _native int GET_LAST_PRINTED_OBJECTIVE()l
extern _native void CLEAR_PRINTED_OBJECTIVE()l
extern _native bool HUD_IS_SHOWING_SMALL_TEXT()l
extern _native bool HUD_IS_SHOWING_BIG_TEXT()l
extern _native int HUD_IS_SHOWING_OBJECTIVE()l
extern _native32(0x4B2FCAF6) bool _HUD_IS_SHOWING_HELP()l
extern _native void HUD_CLEAR_SMALL_TEXT()l
extern _native void HUD_CLEAR_BIG_TEXT()l
extern _native void HUD_CLEAR_COUNTER()l
extern _native void HUD_CLEAR_OBJECTIVE()l
extern _native void HUD_CLEAR_HELP()l
extern _native void HUD_CLEAR_SMALL_TEXT_QUEUE()l//_HUD_CLEAR_SUBTITLE_QUEUE 0x2E1E708
extern _native void HUD_CLEAR_BIG_TEXT_QUEUE()l//_HUD_CLEAR_GENERAL_MESSAGE_QUEUE 0x777A1CA2
extern _native void HUD_CLEAR_OBJECTIVE_QUEUE()l
extern _native void HUD_CLEAR_HELP_QUEUE()l
//SET_RADAR_STREAMING 0xA07FE74
extern _native int ADD_BLIP_FOR_ACTOR(int pram0, int pram1, int pram2, int pram3, int pram4)l
extern _native int ADD_BLIP_FOR_OBJECT(Object obj, int blipID, float pram2, int pram3, int pram4)l
extern _native int ADD_BLIP_FOR_COORD(int pram0, int pram1, int pram2, int pram3, int pram4)l
extern _native void CHANGE_BLIP_ICON(int pram0, int pram1)l
extern _native void SET_BLIP_POS(int pram0, int pram1)l//_SET_BLIP_POSITION 0xB2EAF8DD
extern _native void SET_BLIP_SCALE(int blip, float scale)l
extern _native void SET_BLIP_COLOR(int blip, float r, float g, float b, float alpha)l
extern _native void SET_BLIP_PRIORITY(int blip, int priority)l
extern _native void SET_BLIP_BLINK(int blip, int pram1, int pram2, int pram3)l
extern _native void SET_BLIP_FLAG(int pram0, int pram1, int pram2)l
extern _native void SET_BLIP_VISIBLE(int pram0, int pram1)l
extern _native bool IS_BLIP_VISIBLE(int blip)l
extern _native bool IS_BLIP_VALID(int blip)l
extern _native void REMOVE_BLIP(int blip)l
extern _native int GET_BLIP_ON_ACTOR(Actor actor)l
extern _native int GET_BLIP_ON_OBJECT(Object Obj)l
extern _native int GET_BLIP_ICON(int pram0)l
extern _native int SET_CURRENT_MAP(int pram0)l
extern _native void SET_STAMINA_BLINK(int pram0)l
extern _native void SET_DEADEYE_BLINK(int pram0)l
extern _native void SET_HUD_MAP_SCALE_WALK(int pram0)l
extern _native void SET_HUD_MAP_SCALE_DRIVE(int pram0)l
extern _native void SET_HUD_MAP_SCALE_OVERRIDE(int pram0, int pram1)l
extern _native int GET_RADAR_RADIUS()l
extern _native void ABORT_HUD_MAP_SCALE_OVERRIDE()l
//IS_HUD_MAP_SCALE_OVERRIDE_SET 0x1D85FB58
extern _native void UNK_0x2148AC15(int pram0, int pram1)l
extern _native void UNK_0x444C3C32(int pram0, int pram1, int pram2)l
extern _native32(0x1E98AFEC) void _SET_HUD_MAP_OBJECTIVE_ONLY(int pram0, int pram1)l
extern _native32(0xFF3DB575) void _SET_PAUSE_MAP_OBJECTIVE_ONLY(int blip, int pram1)l
extern _native int GET_BLIP_IMPAIRMENT_MASK(int blip)l
extern _native void SET_BLIP_IMPAIRMENT_MASK(int blip, int mask)l
extern _native void SET_BLIP_MAX_DISTANCE(int blip, float maxDistance)l
extern _native void SET_BLIP_MIN_DISTANCE(int blip, float minDistance)l
extern _native32(0x6077F3AE) void _SET_BLIP_HEIGHT_ENABLED(int pram0, int pram1)l
extern _native void SET_BLIP_NAME(int blip, const char* name)l
extern _native void CLEAR_REGIONS()l
extern _native int APPEND_REGION(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5, int pram6)l
extern _native void UNK_0x970AC1F7(int pram0, int pram1)l
extern _native int IS_HUD_MAP_DRAW_ENABLED()l
extern _native void SET_HUD_MAP_DRAW_ENABLED(int pram0)l
extern _native void SET_HUD_MAP_DRAW_ENABLED_TIMED(bool unk1, float unk2, bool unk3)l
extern _native bool IS_HUD_MAP_VISIBLE()l
extern _native void SET_RADAR_TILES_VISIBLE(int pram0)l
extern _native32(0x4FCE7B9D) void _HUD_GET_SHOOT_BLIP_MAX_DISTANCE(int pram0)l
extern _native32(0x14585073) void _HUD_SET_SHOOT_BLIP_ENABLED_ON_ACTOR(int pram0, int pram1)l
extern _native32(0x5EA2E02D) void _HUD_CLEAR_SHOOT_BLIP_ENABLED_ON_ACTOR(int pram0)l
extern _native int HUD_GET_SHOOT_BLIP_ICON_FOR_ACTOR(int pram0)l
extern _native void HUD_SET_SHOOT_BLIP_ICON_FOR_ACTOR(int pram0, int pram1)l
extern _native void SET_STAT_MESSAGE(Hash hashMessage, char* text2, int pram2, char* text3, int pram4, int pram5, int pram6, int pram7, int pram8, int pram9, int pram10, int pram11, int pram12)l
extern _native void CLEAR_STAT_MESSAGE()l
extern _native32(0x919142BE) int _IS_SHOWING_STAT_MESSAGE()l
extern _native void HUD_TIMER_DISPLAY(int pram0)l
extern _native int HUD_TIMER_GET()l
extern _native int HUD_TIMER_SET(float value)l
//HUD_TIMER_COUNTUP 0x2395C147
extern _native void HUD_TIMER_COUNTDOWN(int pram0)l
extern _native void HUD_TIMER_PAUSE()l
extern _native int HUD_TIMER_UNPAUSE()l
extern _native32(0x31A55281) void _HUD_SET_WANTED(int pram0)l
extern _native32(0x651C1FC2) void _HUD_SET_WANTED_LEVEL(int pram0)l
extern _native void HUD_COUNTER_DISPLAY(int pram0)l
extern _native void HUD_COUNTER_SET(int pram0)l
extern _native void HUD_ENABLE(bool enable)l
extern _native void HUD_SET_FADE_COLOR(int pram0, int pram1, int pram2, int pram3)l
extern _native void HUD_FADE_OUT(float pram0, int pram1, int pram2)l
extern _native void HUD_FADE_TO_LOADING_SCREEN()l
extern _native void HUD_FADE_IN(float scale, int value)l
extern _native void HUD_FADE_IN_NOW(int pram0, int pram1)l
extern _native bool HUD_IS_FADED()l
extern _native bool HUD_IS_FADING()l
extern _native32(0xC6E36B1D) void _HUD_SHOW_MISSION_LOADING_SCREEN(int pram0)l
extern _native32(0xEF270DC9) void _HUD_SHOW_RANDOM_LOADING_SCREEN()l
extern _native void FLASH_INTRO_SHUTDOWN()l
extern _native void FLASH_INTRO_FADE_LOGO(int pram0)l
extern _native void FLASH_INTRO_FADE_PRESS_START(int pram0)l
extern _native int FLASH_INTRO_ARE_LEGALS_COMPLETED()l
//MOVIE_PLAYER_STOP_MOVIE 0xC197810
extern _native int UI_IS_SHOWING_DIALOG()l
extern _native void UI_TRANSITION_TO(int pram0)l
extern _native int UI_GET_REBOOT_REASON(Controller controller)l
extern _native void UI_SEND_EVENT(const char* eventID)l
extern _native void UI_ENTER(const char* uiLayer)l
extern _native void CLEAR_NEWSPAPER()l
extern _native void SHOW_NEWSPAPER(int pram0, int pram1, int pram2, int pram3)l
extern _native void SET_NEWSPAPER_INFO(int pram0, int pram1)l
extern _native void SET_GPS_PATH(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5, int pram6, int pram7, int pram8)l
extern _native int IS_GPS_RECOMPUTE(int pram0)l
extern _native void CLEAR_GPS_PATH(int pram0)l
extern _native bool GET_USER_DEFINED_WAYPOINT(vector3 * a1)l
extern _native int IS_USER_DEFINED_WAYPOINT_CLEARED()l
extern _native int FIND_TRAFFIC_PATH(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5)l
extern _native int IS_TELEPORTATION(int pram0)l
extern _native int GET_LAST_NEAREST_POINT(int pram0, int pram1)l
extern _native int UNK_0xD12802AF(int pram0)l
extern _native void HUD_STAMINA_OVERRIDE(int pram0, int pram1, int pram2)l
extern _native int UI_CHEAT_GET_VALUE(int unk)l//AMBIENT_TEST_NEW_LOD what fox had
extern _native void UI_CHEAT_SET_VALUE(int p0, int p1)l
extern _native int UI_CHEAT_GET_STATE(int pram0)l
extern _native void UI_CHEAT_SET_STATE(int pram0, int pram1)l
extern _native void UI_CHEAT_SET_CODE(int pram0, int pram1)l
extern _native void UI_SET_HAS_CHEATED(bool activate)l
extern _native bool UI_HAS_CHEATED()l
extern _native void UI_DUMP_MESSAGE_QUEUE_TO_NOTES(int pram0)l
extern _native void UI_CLEAR_MESSAGE_QUEUE(const char* uiLayer)l
extern _native int UI_IS_MESSAGE_QUEUE_EMPTY(int pram0)l
extern _native void UI_REMOVE_MESSAGE_IN_QUEUE(char* unk, int unk2, int unk3)l
extern _native void HUD_SET_CENTER_BLIP_SHOWN(int pram0)l
extern _native32(0x6CC9CCE7) bool _HUD_IS_RUNNING_ZOMBIE_MODE()l//int
extern _native32(0x8701F1F6) bool _HUD_IS_RUNNING_HARD_MODE()l//int
extern _native32(0x3842B89F) int _HUD_SET_ZOMBIE_THEME()l
extern _native32(0xFDB5FC03) int _HUD_SET_RED_DEAD_THEME()l
//////////////////////////////////
//World
/////////////////////////////////
extern _native int CLEAR_AREA_OF_TREE_TYPE(int pram0, int pram1, int pram2, int pram3, int pram4)l
extern _native void RESET_TREE_TYPE_CLEARING()l
extern _native void RESET_THIS_TREE_TYPE_CLEARING(int pram0)l
extern _native int SET_DUST_LEVEL(float DustLevel)l
extern _native int SET_DUST_LEVEL_MODIFIER(int pram0)l
extern _native int SET_DUST_LEVEL_MID(int pram0)l
extern _native int SET_DUST_LEVEL_FAR(int pram0)l
extern _native int CLEAR_AREA_OF_GRASS(int pram0, int pram1, int pram2, int pram3)l
extern _native int CLEAR_AREA_OF_BREAKABLE_TREES(int pram0, int pram1, int pram2, int pram3)l
extern _native void RESET_THIS_BREAKABLE_TREE_CLEARING(int pram0)l
extern _native void RESET_ALL_BREAKABLE_TREE_CLEARINGS()l
extern _native void RELOAD_SMICTIONARY_LIST()l//SET_VEHICLE_APPOINTMENT_TARGET() what fox and roulette had
//_SET_IS_ZOMBIE_DLC_ACTIVE 0x28246500
//_IS_ZOMBIE_DLC_ACTIVE 0x8CF15FCB
extern _native32(0x4A8066FB) int _LOAD_ZOMBIE_DLC_ASSETS()l
//_LOAD_ZOMBIE_DLC_ASSETS_MP 0x1DDB57A6
extern _native32(0x88863344) int _UNLOAD_ZOMBIE_DLC_ASSETS()l
extern _native32(0xE7371670) int _IS_ZOMBIE_DLC_LOAD_COMPLETE()l
//_IS_ZOMBIE_DLC_UNLOAD_COMPLETE 0x3E2B631
extern _native32(0xCA840DBB) void _ENABLE_PHOSPHORUS_ROUNDS(bool enable)l
//0x4F3F3CA5
//CREATE_FIRE_ON_OBJECT 0xC587FA2B
extern _native int CREATE_FIRE_IN_VOLUME(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5, int pram6, int pram7, int pram8, int pram9)l
extern _native void STOP_ALL_FIRES()l
//0x8011737F
extern _native int CREATE_FIRE_PROPERTY()l
//GET_FIRE_PROPERTY 0x2AC74780
extern _native void UNK_0x466C02BA(int pram0, int pram1, int pram2, int pram3)l
//0xEC3A9EBB
//REPLACE_WORLD_SECTOR 0xADB3E8D9
extern _native void REPLACE_WORLD_SECTOR_LOAD_BOUNDING_BOX(int pram0)l
extern _native void ENABLE_WORLD_SECTOR(const char* sector)l
extern _native void DISABLE_WORLD_SECTOR(const char* sector)l
extern _native void ENABLE_CHILD_SECTOR(const char* sector)l
extern _native void DISABLE_CHILD_SECTOR(const char* sector)l
//HIDE_CHILD_SECTOR 0x4E6A78B5
//SHOW_CHILD_SECTOR 0x63A83655
//SET_USE_ACTOR_STAGGER 0xE437932A
extern _native int FIRE_CREATE_HANDLE()l
extern _native bool FIRE_IS_HANDLE_VALID(int fire)l//_IS_FIRE_DESCRIPTOR_GUID_VALID 0xA488E930
extern _native void FIRE_RELEASE_HANDLE(int fire, Actor actor)l
//_RELEASE_INFINITE_FIRE_DESCRIPTOR 0xD2BB733E
extern _native32(0x91396EB7) int _FIND_FIRE_DESCRIPTOR_FROM_ATTACHED_ACTOR(int pram0)l
extern _native void FIRE_CREATE_ON_ACTOR(int fire, Actor actor)l
extern _native int FIRE_CREATE_IN_VOLUME(int fire, int volume, int unk1, int unk2)l
extern _native bool FIRE_IS_ACTOR_ON_FIRE(Actor actor)l
extern _native32(0x15001332) void _STOP_ALL_FIRES()l
extern _native void FIRE_STOP_ON_ACTOR(Actor actor)l
extern _native32(0x11A65FFB) void _STOP_FLAMES_IN_VOLUME(int volume)l
extern _native int FIRE_GET_OWNER(int pram0)l
extern _native void FIRE_SET_OWNER(int pram0, int pram1)l
extern _native void FIRE_SET_DAMAGE_ALLOWED(int fire, bool damage)l
extern _native void FIRE_SET_CONTROL_VOLUME(int fire, Layout layout)l
extern _native void FIRE_SET_MAX_FLAMES(int fire, int maxFlames)l
extern _native void FIRE_SET_TARGET_FILL_PERCENT(int fire, float percent)l
extern _native void FIRE_SET_GROW_RATE(int fire, float grow)l
//FIRE_SET_DECAY_RATE 0x7906A950
extern _native void FIRE_SET_EXPIRE_ALLOWED(int fire, bool expire)l
extern _native void FIRE_SET_GROW_ALLOWED(int fire, bool allow)l
extern _native int COUNT_FLAMES_IN_SPHERE(int pram0, int pram1, int pram2, int pram3)l
extern _native int COUNT_FLAMES_IN_VOLUME(int volume)l
extern _native int FIRE_ARE_ANY_FLAMES_IN_VOLUME(int pram0)l
extern _native int FIRE_SET_GUNS_BLAZING_ACTIVE(bool activate)l
//////////////////////////////////
//Prop
/////////////////////////////////
extern _native bool IS_PROP_BROKEN(int pram0)l
extern _native int GET_PROP_VELOCITY(int pram0, int pram1)l
extern _native int SET_PROP_VELOCITY(int pram0, int pram1)l
extern _native32(0x544BCE48) int _SET_PROP_ANG_VELOCITY_DEGS(int pram0, int pram1)l
extern _native int SET_PROP_VELOCITY_ON_AXIS(int pram0, int pram1, int pram2)l
extern _native bool IS_PHYSINST_VALID(int physinst)l
extern _native bool IS_PHYSINST_READY(int pram0)l
extern _native bool IS_PHYSINST_IN_LEVEL(int pram0)l
extern _native void SET_SLEEP_TOLERANCE(int pram0, int pram1)l
extern _native void SET_BRIDGE_STIFFNESS(int pram0, int pram1)l
extern _native void ACTIVATE_PHYSINST(int pram0)l
extern _native int HAS_PHYSINST_BROKEN_APART(int pram0)l
extern _native32(0x734CC17B) int _FIND_NEAREST_NAMED_PHYSINST(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5)l
extern _native32(0x4FF36FA7) int _FIND_NEAREST_PARTIALLY_NAMED_PHYSINST(float posX, float posY, float posZ, float radius, const char* propName, int unk)l
extern _native32(0xC5E372BC) int _FIND_ALL_PARTIALLY_NAMED_PHYSINST(int objectSet, int volume, const char* objectName, bool unk)l
//ATTACH_PHYSINST_TO_WORLD2 0x441CDD55
extern _native int ATTACH_PHYSINST_TO_WORLD2_HIGH_QUALITY(int pram0, int pram1, int pram2, int pram3, int pram4)l
extern _native void RELEASE_CONSTRAINT(int pram0)l
extern _native void HIDE_PHYSINST(int pram0)l
extern _native void SHOW_PHYSINST(int pram0)l
extern _native void SET_SECTOR_PROPS_SUPER_LOCKED(int pram0, int pram1)l
extern _native void LIGHTS_SET_ON_TIME(int pram0, int pram1)l
extern _native void LIGHTS_SET_OFF_TIME(int pram0, int pram1)l
extern _native void SET_PROP_NO_FADE(int pram0)l
//////////////////////////////////
//Streaming
/////////////////////////////////
extern _native void STREAMING_REQUEST_ACTOR(eActor actor, bool unk1, bool unk2)l
extern _native bool STREAMING_IS_ACTOR_LOADED(eActor actor, bool pram1)l
extern _native void STREAMING_EVICT_ACTOR(int pram0, int pram1)l
extern _native bool STREAMING_IS_WORLD_LOADED()l
extern _native bool STREAMING_IS_WORLD_LOADED_PRIORITY(int unkValue)l //value used by R* are either 1, 4 or 5
extern _native bool STREAMING_ARE_BOUNDS_LOADED(int pram0, int pram1, int pram2, int pram3)l
extern _native int STREAMING_REQUEST_PROP(int assetID, int unk)l //.xft
extern _native bool STREAMING_IS_PROP_LOADED(int pram0)l //.xft
extern _native void STREAMING_EVICT_PROP(int pram0)l
extern _native void STREAMING_REQUEST_PROPSET(int pram0)l
extern _native bool STREAMING_IS_PROPSET_LOADED(Object propset)l
extern _native void STREAMING_EVICT_PROPSET(int pram0)l
extern _native void STREAMING_REQUEST_GRINGO(int assetID)l
extern _native bool STREAMING_IS_GRINGO_LOADED(int pram0)l
extern _native void STREAMING_EVICT_GRINGO(int pram0)l
extern _native void STREAMING_REQUEST_GRINGO_DICTIONARY(int assetID)l //.xgd
extern _native bool STREAMING_IS_GRINGO_DICTIONARY_LOADED(int gringoDictionnary)l //.xgd
extern _native void STREAMING_EVICT_GRINGO_DICTIONARY(int pram0)l
extern _native void STREAMING_REQUEST_SCRIPT(int assetID)l //.xsc
extern _native bool STREAMING_IS_SCRIPT_LOADED(int scriptId)l //.xsc
extern _native void STREAMING_EVICT_SCRIPT(int pram0)l
//STREAMING_LOAD_ALL_REQUESTS_NOW 0x7B5C28F3
extern _native void STREAMING_LOAD_SCENE_EXT(vector3 pos, vector3 ext, int probablyBoolean)l
extern _native void STREAMING_UNLOAD_SCENE()l
//STREAMING_GET_POI_POS 0x55EF7A3
extern _native void STREAMING_OVERRIDE_MAIN_POI(vector3 coord1, vector3 coord2)l
extern _native void STREAMING_RELEASE_MAIN_POI()l
extern _native int STREAMING_HAS_OVERRIDE_MAIN_POI()l
extern _native void STREAMING_GET_OVERRIDE_MAIN_POI_POS(int pram0)l
extern _native void STREAMING_ENABLE_POI_STREAMING(bool toggle)l
extern _native void STREAMING_PREVENT_SNIPER_MODE(int pram0)l
extern _native void STREAMING_SET_CUTSCENE_MODE(bool enable)l
extern _native void STREAMING_ENABLE_BOUNDS(int pram0)l
extern _native void STREAMING_LOAD_BOUNDS(int pram0, int pram1, int pram2, int pram3, int pram4)l
extern _native void STREAMING_LOAD_BOUNDS_EXT(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5)l
extern _native void STREAMING_UNLOAD_BOUNDS()l
//0xF7BABE84
extern _native void STREAMING_EVICT_ALL()l
extern _native int IS_PLAYER_TELEPORTING()l
extern _native void DUMP_MEMORY_STATS()l
extern _native void UNK_0xE74C4851()l
extern _native void UNK_0x6F9C399B(int pram0)l
extern _native void STREAMING_ENABLE_FORCE_FRAGMENT_HIGH_LOD(int pram0)l
extern _native void UNK_0xB226E8E3(int pram0)l
extern _native void STREAMING_ENABLE_FORCE_CHILD_SECTOR_HIGH_LOD(int pram0)l
extern _native void STREAMING_DISABLE_FORCE_CHILD_SECTOR_HIGH_LOD(int pram0)l
extern _native void RESIZE_ACTOR_SET()l
//////////////////////////////////
//Explosion
/////////////////////////////////
extern _native32(0xE7023D23) void _CREATE_EXPLOSION(vector3 * coords, const char* explosionName, bool pram2, vector3 * damageVector, bool pram4)l
extern _native void ENABLE_REPLICATION_SET_EXPLOSION(int pram0)l
//////////////////////////////////
//Weather
/////////////////////////////////
extern _native void SET_WEATHER(eWeather weatherType, Time time)l
extern _native int GET_WEATHER()l
extern _native void SET_WEATHER_COMPLEX(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5, int pram6, int pram7, int pram8, int pram9, int pram10, int pram11, int pram12, int pram13, int pram14)l
extern _native void SET_WIND(int pram0, int pram1, int pram2)l
extern _native void SET_AUTO_WIND()l
extern _native void SET_RAIN_AMOUNT(float amount)l
extern _native void SET_LIGHTNING_AMOUNT(float amount)l
extern _native void SET_WEATHER_TYPE_GOOD(int pram0)l
extern _native void SET_WEATHER_TYPE_RAINY(int pram0)l
extern _native void TRIGGER_LIGHTNING_SEQUENCE(int pram0)l
extern _native void TRIGGER_CLOUD_LIGHTNING_SEQUENCE(int p0, int p1, int p2)l
extern _native void ENABLE_WEATHER_SPHERE(int pram0, int pram1)l
extern _native bool IS_WEATHER_SPHERE_ENABLED(int pram0)l
extern _native32(0x21A68D47) void _SET_SKY_IS_INTRO_RUNNING(int pram0)l
//////////////////////////////////
//Render
/////////////////////////////////
extern _native32(0x6AF07F86) void _ENABLE_CHARACTER_CLIPPING(int pram0)l
extern _native void PRINT_FRAME_TIME(int pram0)l
extern _native32(0x9D4CDEF) void _SET_MAXIMUM_SHADOW_SPOTLIGHT_CASCADE_COUNT(int pram0)l//unsure of param count
//////////////////////////////////
//Door
/////////////////////////////////
extern _native Object FIND_NEAREST_DOOR(vector3 position, float range)l
extern _native int GET_DOOR_FROM_OBJECT(int pram0)l
extern _native bool IS_DOOR_VALID(int door)l
extern _native bool IS_DOOR_LOCKED(int door)l
extern _native int SET_DOOR_LOCK(Object object, bool locked)l//void
extern _native bool IS_DOOR_CLOSED(int door)l
extern _native bool IS_DOOR_OPENED(int door)l
extern _native bool IS_DOOR_OPENING(int door)l
extern _native bool IS_DOOR_CLOSING(int door)l
extern _native void SET_DOOR_AUTO_CLOSE(int pram0, int pram1)l
extern _native void SET_DOOR_CURRENT_SPEED(int pram0, int pram1, int pram2)l
extern _native void OPEN_DOOR(Object door, int pram1, int pram2)l
extern _native void OPEN_DOOR_DIRECTION(int pram0, int pram1)l
extern _native void OPEN_DOOR_FAST(int pram0, int pram1)l
extern _native void OPEN_DOOR_DIRECTION_FAST(int pram0, int pram1)l
extern _native void CLOSE_DOOR(int pram0, int pram1)l
extern _native void CLOSE_DOOR_FAST(int door)l
extern _native void SET_ALL_DOOR_LOCKS_VISIBLE(int pram0)l
extern _native void SET_DOOR_LOCK_VISIBLE(int pram0, int pram1)l
extern _native bool IS_DOOR_OPEN_IN_DIRECTION(int pram0, int pram1)l
//////////////////////////////////
//UI
/////////////////////////////////
extern _native void UNK_0x97A50E69(int pram0)l
extern _native32(0xB1A2028A) void _UI_ENTER_EXCLUSIVE(char* scaleformLayer)l
extern _native void UI_POP(const char* pram0)l
extern _native void UI_PUSH(const char* uiLayer)l
extern _native void UI_GOTO(const char* uiLayer)l
extern _native void UI_EXIT(const char* uiLayer)l
extern _native void UI_SHOW(const char* uiLayer)l
extern _native void UI_REFRESH(const char* pram0)l
extern _native void UI_HIDE(const char* uiLayer)l
extern _native void UI_ENABLE(const char* uiLayer)l
extern _native void UI_DISABLE(const char* uiLayer)l
extern _native bool UI_ISACTIVE(const char* uiLayer)l
extern _native void UI_ACTIVATE(const char* uiLayer)l
extern _native void UI_DEACTIVATE(const char* pram0)l
extern _native void UI_EXCLUDE(const char* uiLayer)l
extern _native void UI_INCLUDE(const char* uiLayer)l
extern _native int UI_ISFOCUSED(const char* uiLayer)l
extern _native void UI_FOCUS(const char* uiLayer)l
extern _native void UI_UNFOCUS(const char* uiLayer)l
extern _native void UI_RESTORE(char* uiLayer)l
extern _native void UI_SUPPRESS(char* uiLayer)l
extern _native void UI_SENDEVENT()l//(char* uiLayer)unsure
extern _native int UI_GET_SELECTED_INDEX(const char* uiLayer, bool unk)l
extern _native void UI_SET_STYLE(int pram0, int pram1)l
extern _native void UI_ADD_CHILD(int pram0, int pram1)l
extern _native void UI_SET_DATA(int pram0, int pram1, int pram2)l
extern _native int UI_GET_NUM_CHILDREN(int pram0)l
extern _native void UI_ANIM_SETUP(int pram0, int pram1, int pram2, int pram3)l
extern _native void UI_ANIM_RESTART(int pram0)l
extern _native float UI_ANIM_GET_TIME(int pram0)l
extern _native void UI_REGISTER_STREAMING_TEXTURE(int pram0, int pram1, int pram2, int pram3)l
extern _native void UI_SET_STRING(char* entry, char* string)l
extern _native void UI_SET_STRING_FORMAT(const char* entry, const char* formatString, const char* formatedText1, const char* formatedText2, const char* formatedText3)l
extern _native void UI_SET_MONEY(const char* uiID, const char* uiDecorType, float money)l
extern _native const char* UI_GET_STRING(const char* string)l
extern _native const char* UI_GET_STRING_BY_HASH(int value)l
extern _native void UI_MESSAGEBOX_SET_DESCRIPTION(char* pram0, char* pram1)l
extern _native void UI_LABEL_SET_TEXT(char* pram0, int pram1)l
extern _native void UI_LABEL_SET_VALUE(const char* label, int value)l
extern _native void UI_LABEL_SET_VALUE_B(int pram0, int pram1)l//AI_SET_SPECIAL_AREAS_TIME what fox and roulette had
extern _native void UI_BUTTON_SET_TEXT(int pram0, int pram1)l
extern _native void UI_TEXTURE_SET_NAME(const char* textureID, const char* textureName)l
extern _native void UI_TEXTURE_SET_HASH(int pram0, int pram1)l
extern _native void UI_SET_TEXT(char* entry, char* text)l
extern _native void UI_SET_TEXT_HASH(int pram0, int pram1)l
extern _native32(0xE5D53722) void _UI_SET_PROGRESS_BAR(int pram0, int pram1)l
extern _native void UI_SET_PROGRESS_BAR_CHANGE(int pram0, int pram1)l
extern _native32(0xD792B93B) void _UI_SET_AUTO_EXIT_TIME(int pram0, int pram1)l
extern _native void UI_SET_ICON(int pram0, int pram1)l
extern _native void UI_DISABLE_INPUT(const char* uiLayer)l
extern _native32(0x9D20BDC4) int _UI_IS_MOVIE_LOADED(int pram0)l
extern _native32(0x1E732914) int _UI_DISBALE_USE_CONTEXT_PROMPT(int p0, int p1)l
//////////////////////////////////
//String Table
/////////////////////////////////
extern _native32(0xB3E44649) void _APPEND_STRING_TABLE(const char* path)l
extern _native void REQUEST_STRING_TABLE(const char* assetName)l //.xst
extern _native bool HAS_STRING_TABLE_LOADED(const char* stringTablePath)l //.xst
extern _native void REMOVE_STRING_TABLE(const char* stringtable)l
//////////////////////////////////
//Player
/////////////////////////////////
extern _native void TELEPORT_ACTOR(Actor actor, vector3 * position, bool unk1, bool unk2, bool unk3)l
extern _native void TELEPORT_ACTOR_WITH_HEADING(Actor actor, vector3 position, float heading, bool unk1, bool unk2, bool unk3)l
extern _native float GET_MAX_SPEED(Actor actor)l
extern _native void GET_POSITION(Actor actor, vector3 * outCoords)l
extern _native float GET_HEADING(Actor actor)l
extern _native int GET_ACTOR_AXIS(int pram0, int pram1, int pram2)l
extern _native void SET_ACTOR_HEADING(Actor actor, float heading, bool unk1)l
extern _native void SET_ACTOR_ONE_SHOT_DEATH(int pram0, int pram1)l
extern _native int GET_ACTOR_ONE_SHOT_DEATH_STATUS(int pram0)l
extern _native int GET_PHYSINST_FROM_ACTOR(Actor actor)l
extern _native int CAN_ACTOR_HOGTIE_TARGET(int pram0, int pram1)l
extern _native bool IS_ACTOR_PLAYER(Actor actor)l
extern _native bool IS_ACTOR_LOCAL_PLAYER(int actor)l
extern _native32(0xB114332D) int _GET_DEBUG_PAD_INDEX()l
extern _native32(0x524F6981) Controller _GET_ACTOR_CONTROLLER(int ActorId)l//_GET_PLAYER_PAD_INDEX 0x524F6981
extern _native32(0xCF02D1D6) int _GET_PLAYER_PAD_INDEX_NO_ACTOR(int pram0)l
extern _native32(0x8F82B7D4) void _SET_PLAYER_PAD_INDEX(int pram0, int pram1)l
extern _native void SET_ENABLE_NAV_STICK_INPUT(Actor actor, bool enable)l
extern _native void SET_PLAYER_CONTROL(int player, bool control, bool pram2, bool pram3)l
extern _native void SET_PLAYER_ENABLE_MOUNT_USE_CONTEXTS(int pram0, int pram1)l
extern _native void SET_PLAYER_ALLOW_PICKUP(Actor actor)l
extern _native void SET_PLAYER_MELEE_MODE_SELECTED(Actor actor, int mode)l
extern _native void SET_PLAYER_DISABLE_TARGETING(int pram0, int pram1)l
extern _native32(0x9613C2D0) bool _GET_PLAYER_CONTROL(int pram0)l
extern _native bool IS_PLAYER_IN_COMBAT(Actor actor)l
extern _native int IS_PLAYER_IN_COMBAT_WITHIN(int pram0, int pram1)l
extern _native void SET_RETICLE_DRAW_DISABLED_BY_SCRIPT(int pram0, int pram1)l
extern _native void SET_PLAYER_CONTROL_RUMBLE(int pram0, int pram1)l
extern _native void RESET_RUMBLE()l
extern _native int GET_PLAYER_CONTROL_CONFIG(int player)l
extern _native void SET_PLAYER_CONTROL_CONFIG(int pram0, int pram1)l
extern _native void PLAYER_RUMBLE(int pram0, int pram1, int pram2)l
extern _native void SET_PLAYER_CURRENT_NOTORIETY(Actor actor, int NotorietyLevel)l
extern _native void SET_PLAYER_CURRENT_HONOR(int pram0, int pram1)l
extern _native void SET_PLAYER_COMBATMODE(int pram0)l
extern _native int GET_PLAYER_COMBATMODE()l
extern _native void SET_PLAYER_COMBATMODE_OVERRIDE(int pram0)l
extern _native void SET_PLAYER_COMBATMODE_EXCLUSION(int pram0)l
extern _native void SET_PLAYER_VEHICLE_INPUT(int player, int p1, int p2, int p3)l
extern _native void ADD_PLAYER_CONTROL_HORSE_FOLLOW(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5, int pram6)l
extern _native void REM_PLAYER_CONTROL_HORSE_FOLLOW(int pram0, int pram1)l
extern _native void CLEAR_PLAYER_CONTROL_HORSE_FOLLOW(Actor actor, int p1)l
extern _native bool IS_PLAYER_IN_HORSE_FOLLOW(int player, int p1)l
extern _native Actor GET_PLAYER_ACTOR(int playerIndex)l
extern _native bool IS_LOCAL_PLAYER(int pram0)l
extern _native bool IS_LOCAL_PLAYER_VALID(int mySelf)l
extern _native bool IS_SLOT_VALID(int slotID)l
extern _native Actor GET_SLOT_ACTOR(int slotID)l
extern _native int GET_ACTOR_SLOT(Actor actorPlayer)l
extern _native int GET_LOCAL_SLOT()l
extern _native const char* GET_SLOT_NAME(int slot)l
extern _native int GET_SLOT_POSITION(int slot, vector3 * outCoords)l
extern _native int GET_SLOT_FACING(int pram0, int pram1)l
extern _native int IS_PLAYER_TARGETTING_ACTOR(int pram0, int pram1, int pram2)l
extern _native bool IS_PLAYER_TARGETTING_OBJECT(int player, Object obj)l
extern _native bool IS_PLAYER_DEADEYE(Actor actor)l
extern _native void SET_PLAYER_DEADEYE_MODE(Actor actor, bool deadeye)l
extern _native void SET_FORCE_PLAYER_AIM_MODE(int pram0, int pram1)l
extern _native void SET_PLAYER_ENDLESS_READYMODE(int pram0, int pram1)l
extern _native int GET_PLAYER_ZOOM_STATE(int pram0)l
extern _native bool IS_PLAYER_USING_COVER(int playerID)l
extern _native void ATTACH_PLAYER_TO_COVER(int pram0, int pram1, int pram2)l
extern _native void SIMULATE_PLAYER_INPUT_GAIT(int pram0, int pram1, int pram2, int pram3)l
extern _native void ACTOR_POP_NEXT_GAIT(int pram0, int pram1, int pram2)l
extern _native void ACTOR_SET_MAX_GAIT(Actor actor, int p1)l
extern _native bool IS_ACTOR_USING_COVER(Actor actor)l
extern _native bool IS_ACTOR_USING_LEDGE(Actor actor)l
extern _native void SET_PLAYER_DEADEYE_POINTS(Actor actor, int points, int probablyBoolEnable)l
extern _native void ADD_PLAYER_DEADEYE_POINTS(int pram0, int pram1, int pram2)l
extern _native int GET_PLAYER_DEADEYE_POINTS(int pram0)l
extern _native void SET_DISABLE_DEADEYE(Actor actor, bool disable)l
extern _native void SET_DEADEYE_POINT_MODIFIER(int pram0, int pram1)l
extern _native void SET_MAX_DEADEYE_POINTS(int pram0, int pram1)l
extern _native void SET_DEADEYE_MULTILOCK_ENABLE(Actor actor, bool enable)l
extern _native void SET_DEADEYE_TARGETPAINT_ENABLE(Actor actor, bool enable)l
extern _native void SET_DEADEYE_INVULNERABILITY(Actor actor, bool invulnerability)l
extern _native void SET_DEADEYE_DAMAGE_SCALING(Actor actor, float scaling)l
extern _native void SET_DEADEYE_TIME_LIMIT(Actor actor, float timelimit)l
extern _native void SET_DEADEYE_REGENERATION_RATE(Actor actor, float regenerationRate, int pram2)l
extern _native void SET_DEADEYE_REGENERATION_RATE_MULTIPLIER(int pram0, int pram1)l
extern _native void SET_DEADEYE_TIMESCALE(Actor actor, float timeScale)l
extern _native void SET_INFINITE_DEADEYE(Actor actor, bool infinite)l
extern _native32(0x7F454A92) int _LAST_TIME_SHOT_NEAR_BY(int pram0)l
extern _native void SET_WAGON_TO_WAGON_JACK_ENABLE(int p0, int p1)l
extern _native void SET_PLAYER_POSTURE(int pram0, int pram1, int pram2)l
extern _native void SET_ACTOR_ALLOW_DISMOUNT(int pram0, int pram1)l
extern _native void SET_ACTOR_INVULNERABILITY(Actor actor, bool invulnerable)l
extern _native int GET_ACTOR_INVULNERABILITY(int pram0)l
extern _native void SET_TOUGH_ACTOR(Actor actor, bool toggle)l
extern _native void SET_ACTOR_UNKILLABLE(Actor actor, bool invulnerable)l
extern _native int SET_ACTOR_PERMANENT(Actor actor)l
extern _native void SET_ACTOR_PERMANENT_DEAD(Actor actor)l
extern _native int SET_ACTOR_FROZEN_AFTER_CORPSIFY(int p0)l
extern _native void CLEAR_ACTOR_PROOF(Actor actor, int proof)l
extern _native void CLEAR_ACTOR_PROOF_ALL(Actor actor)l
extern _native int GET_ACTOR_PROOF(Actor actor)l
extern _native void SET_ACTOR_PROOF(Actor actor, int proof)l
extern _native void SET_ACTOR_OVERHEALTH_MODE(int pram0, int pram1)l
extern _native32(0x437588E6) void _REPAIR_INCAPACITATION(Actor actor)l
extern _native int GET_ACTOR_INCAPACITATED(Actor actor)l
extern _native void SET_ALLOW_RIDE_BY_AI(int pram0, int pram1)l
extern _native bool GET_ALLOW_RIDE_BY_PLAYER(Actor actor)l
extern _native void SET_ALLOW_RIDE_BY_PLAYER(Actor Actor, bool Ride)l
extern _native void SET_ALLOW_RIDE(int pram0, int pram1)l
extern _native bool GET_ALLOW_RIDE(Actor actor)l
extern _native void SET_ALLOW_JACK(int pram0, int pram1)l
extern _native void SET_ALLOW_EXECUTE(int pram0, int pram1)l
extern _native void SET_ALLOW_DEADEYE_LOCKS(int pram0, int pram1)l
extern _native void SET_DEADEYE_LOCKS_ON_HEAD_ONLY(int pram0, int pram1)l
extern _native int SET_ALLOW_MELEE_SPECIAL_MOVE(int p0, int p1)l
extern _native int SET_ALLOW_LASSO_MINI_GAME(int p0, int p1)l
extern _native void ACTOR_DISMOUNT_NOW(Actor actor)l
extern _native int IS_ACTOR_REACTING(int pram0)l
extern _native int GET_ACTOR_UPDATE_PRIORITY(int pram0)l
extern _native void SET_ACTOR_UPDATE_PRIORITY(Actor actor, int priority)l
extern _native32(0xA4E29C31) void _SET_ACTOR_FORCE_HIGH_LOD_UPDATE(Actor actor, int value)l
extern _native void ACTOR_FORCE_NEXT_UPDATE(Actor actor)l
extern _native int IS_ANY_ACTOR_IN_SPHERE(int pram0, int pram1)l
extern _native void SET_NPC_TO_NPC_CRIPPLE_DISABLE(int pram0)l
extern _native void SET_NPC_TO_NPC_DAMAGE_SCALE_FACTOR(int pram0)l
extern _native void SET_PLAYER_TO_PLAYER_DAMAGE_SCALE_FACTOR(int pram0)l
extern _native void SET_NPC_TO_ACTOR_DAMAGE_SCALE_FACTOR(int pram0, int pram1)l
extern _native void SET_ACTOR_LOW_DROP_DAMAGE(int p0, float p1)l
extern _native void SET_ACTOR_MEDIUM_DROP_DAMAGE(int p0, int p1, int p2, int p3, int p4, int p5, int p6, int p7, float p8)l
extern _native void SET_ACTOR_HIGH_DROP_DAMAGE(int p0, int p1, int p2, int p3, int p4, int p5, int p6, int p7, float p8)l
extern _native void SET_ACTOR_DEATH_DROP_DISTANCE(int pram0, int pram1)l
extern _native void SET_DAMAGE_SCALE_ENABLE(int pram0, int pram1)l
extern _native void SET_CRIPPLE_ENABLE(Actor actor, bool enable)l
extern _native void SET_CRIPPLE_FLAG(int pram0, int pram1)l
extern _native bool IS_ACTOR_CRIPPLED(int pram0, int pram1)l
extern _native bool IS_ACTOR_HANDSUP(Actor actor)l
extern _native void SET_ALLOW_COLD_WEATHER_BREATH(int pram0, int pram1)l
extern _native void SET_DLC_FALLBACK_AVATAR(int value)l
extern _native void SET_EMOTION(int pram0, int pram1, int pram2)l
extern _native void SET_ACTOR_STOP_UPDATE(Actor actor, bool stopUpdate)l
extern _native Actor GET_ACTOR_STOP_UPDATE(Actor actor)l
extern _native bool IS_ACTOR_IN_ROOM(Actor actor)l
extern _native void REGISTER_TRAFFIC_OBJECTSET(int pram0)l
extern _native void REGISTER_TRAFFIC_ACTOR(int pram0, int pram1)l
extern _native void REGISTER_GPS_CURVE_OBJECTSET(int pram0)l
extern _native void SET_PLAYER_TARGET_WEIGHT(float pram0)l
extern _native void RESET_PLAYER_TARGET_WEIGHT()l
extern _native void SET_HARDLOCK_TARGET_ANGLE_WEIGHTING(float p0, float p1)l
extern _native void SET_ZOMBIE_TARGET_MODE(int pram0)l
extern _native void SET_ACTOR_SKIP_VISIBILITY_CHECK(Actor actor, bool skip)l
extern _native bool GET_ACTOR_SKIP_VISIBILITY_CHECK(Actor actor)l
extern _native void FEED_CODE_WARP_DIST(int pram0)l
extern _native32(0x0911BA31) void _IS_ACTOR_IN_ROOM(int pram0, int pram1)l
//////////////////////////////////
//Motive
/////////////////////////////////
extern _native void SET_MOTIVE_BY_ENUM(int pram0, int pram1, int pram2)l
//////////////////////////////////
//Health
/////////////////////////////////
extern _native Actor GET_LAST_ATTACKER(Actor actor)l
extern _native int GET_LAST_HIT_TIME(int pram0)l
extern _native int GET_LAST_HIT_WEAPON(int pram0)l
extern _native int GET_LAST_HIT_FLAGS(int pram0)l
extern _native int GET_LAST_DAMAGE(int pram0)l
extern _native int GET_LAST_HIT_ZONE(Actor actor, int* out)l
extern _native int GET_CORPSE_LAST_HIT_WEAPON(Actor actor)l//unsure
extern _native void CLEAR_LAST_HIT(Actor actor)l
extern _native void KILL_ACTOR(Actor actor)l
extern _native void KILL_ACTOR_WITH_KILLER(Actor actor, Actor actor2)l
extern _native bool IS_ACTOR_ALIVE(Actor actor)l
extern _native bool IS_ACTOR_DEAD(Actor actor)l
extern _native bool IS_ACTOR_RAGDOLL(Actor actor)l
extern _native void SET_ACTOR_HEALTH(Actor actor, float health)l
extern _native float GET_ACTOR_HEALTH(Actor actor)l
extern _native float GET_ACTOR_MAX_HEALTH(Actor actor)l
extern _native void SET_ACTOR_MAX_HEALTH(int pram0, int pram1)l
extern _native32(0x7A207FFE) int _ACTOR_HAS_KO_POINTS(int pram0)l
extern _native void SET_ACTOR_KO_POINTS(int pram0, int pram1)l
extern _native float GET_ACTOR_KO_POINTS(Actor actor)l//maybe int?
extern _native float GET_ACTOR_MAX_KO_POINTS(int pram0)l//maybe int?
extern _native void UNK_0x4EEC6628(int pram0, int pram1)l
extern _native void UNK_0x479B997B(Actor actor, int pram1)l
extern _native bool IS_ACTOR_DRUNK(Actor actor)l
extern _native void SET_ACTOR_DRUNK(Actor actor, bool drunk)l
extern _native void SET_ACTOR_PASSED_OUT(int pram0, int pram1)l
extern _native void SET_ACTOR_HANGING_FROM_NOOSE(int pram0, int pram1)l
extern _native void UNK_0x6287203C(int pram0)l
extern _native void UNK_0x1082715D()l
//////////////////////////////////
//Faction
/////////////////////////////////
extern _native void RELOAD_FACTIONS(int pram0)l
extern _native void RESET_FACTIONS()l
extern _native int GET_ACTOR_FACTION(Actor actor)l
extern _native void SET_ACTOR_FACTION(Actor actor, int faction)l
extern _native bool IS_FACTION_VALID(int faction)l
extern _native void VERIFY_FACTION_ENUM(int pram0, int pram1)l
extern _native void SET_FACTION_IS_LAWFUL_TO_ATTACK(int pram0, int pram1)l
extern _native int GET_FACTION_IS_LAWFUL_TO_ATTACK(int faction)l
extern _native32(0xD771AF0B) void _SET_FACTION_STATUS_ONE_WAY(int pram0, int pram1, int pram2)l
extern _native32(0x4C28B11E) void _SET_FACTION_STATUS_TWO_WAY(int faction, int val1, int val2)l
extern _native32(0x6118212B) void _SET_AMBIENT_FACTION_STATUS_TWO_WAY(int pram0, int pram1, int pram2)l
extern _native32(0xF9C5DC76) void _RESET_AMBIENT_FACTION_STATUS_TWO_WAY(int pram0, int pram1)l
extern _native32(0x902781BF) void _RESET_FACTION_STATUS_TWO_WAY(int pram0, int pram1)l
extern _native int GET_FACTIONS_STATUS(int faction)l
extern _native void SET_FACTION_TO_FACTION_ACCURACY_SCALE_FACTOR(int pram0, int pram1, int pram2)l
extern _native void SET_FACTION_TO_FACTION_DAMAGE_SCALE_FACTOR(int pram0, int pram1, int pram2)l
extern _native void CLEAR_FACTION_STATUS_TO_INDIVIDUAL_ACTOR(int pram0, int pram1)l
extern _native int GET_FACTION_STATUS_TO_INDIVIDUAL_ACTOR(int pram0, int pram1)l
extern _native void SET_FACTION_STATUS_TO_INDIVIDUAL_ACTOR(int pram0, int pram1, int pram2)l
//////////////////////////////////
//Actor Set
/////////////////////////////////
extern _native int CREATE_ACTORSET_IN_LAYOUT(Layout layout, char* actorSet, bool unk)l
extern _native bool IS_ACTORSET_VALID(int actorSet)l
extern _native int FIND_NAMED_ACTORSET(int pram0)l
extern _native int DESTROY_ACTORSET(int pram0)l
extern _native int DISBAND_ACTORSET(int pram0)l
extern _native int ADD_ACTORSET_MEMBER(int actorSet, Actor actor)l
extern _native int REMOVE_ACTORSET_MEMBER(int pram0, int pram1)l
extern _native bool IS_ACTOR_IN_ACTORSET(int actorSet, Actor actor)l
extern _native Actor GET_ACTOR_FROM_ACTORSET(int pram0, int pram1)l
extern _native int GET_ACTORSET_SIZE(int actorSet)l
//////////////////////////////////
//AI Conversation
/////////////////////////////////
extern _native void AI_CONVERSE_SET_GREETING_CONTEXT(int pram0)l
extern _native void AI_CONVERSE_SET_GOSSIP_AMBIENT_CONTEXT(int pram0)l
extern _native void AI_CONVERSE_SET_GOSSIP_REPLY_CONTEXT(int pram0)l
extern _native void AI_CONVERSE_SET_GOODBYE_START_CONTEXT(int pram0)l
extern _native void AI_CONVERSE_SET_GOODBYE_CONTEXT(int pram0)l
extern _native void AI_CONVERSE_INIT_CAMPFIRE_CONTEXT_STORAGE()l
extern _native void AI_CONVERSE_SET_CAMPFIRE_INVITE_CONTEXT(int pram0)l
extern _native void AI_CONVERSE_SET_CAMPFIRE_CONTEXT(int pram0, int pram1)l
extern _native void AI_CONVERSE_SET_CAMPFIRE_STORY_CONTEXT(int pram0, int pram1)l
extern _native void AI_CONVERSE_SET_CAMPFIRE_STORY_DONE_CONTEXT(int pram0)l
extern _native void AI_CONVERSE_SET_CAMPFIRE_STORY_LEAVE_CONTEXT(int pram0)l
extern _native void AI_CONVERSE_SET_CAMPFIRE_RESPONSE_CONTEXT(int pram0)l
extern _native void AI_SET_CAMPFIRE_STORY_ENABLED(int pram0)l
extern _native void AI_CONVERSE_SET_GIDDYUP_CONTEXT(int pram0)l
extern _native void AI_CONVERSE_SET_WOAH_CONTEXT(int pram0)l
extern _native void AI_CONVERSE_DISABLE(int pram0)l
extern _native void AI_CONVERSE_ENABLE(int pram0)l
extern _native void AI_CONVERSE_ADD_CAMPFIRE_CONVERSER(int pram0)l
extern _native void AI_CONVERSE_REMOVE_CAMPFIRE_CONVERSER(int pram0)l
extern _native void AI_CONVERSE_SET_GREET_SAUCY_CONTEXT(int pram0)l
extern _native void AI_CONVERSE_SET_SOLICIT_CONTEXT(int pram0)l
extern _native void AI_CONVERSE_SET_REJECTION_CONTEXT(int pram0)l
extern _native void AI_CONVERSE_SET_COY_REJECTION_CONTEXT(int pram0)l
extern _native void AI_CONVERSE_SET_GREET_PLAYER_CONTEXT(int pram0)l
//////////////////////////////////
//AI Attention
/////////////////////////////////
extern _native32(0x945F518F) int _AI_ATTENTION_ADD_TARGET(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5, int pram6, int pram7)l
//////////////////////////////////
//Weapon Reasoner
/////////////////////////////////
extern _native int ACTOR_HOLSTER_WEAPON(int pram0, int pram1)l
extern _native int ACTOR_START_FORCE_HOLSTER(Actor actor, bool unk1, bool unk2)l
extern _native int ACTOR_END_FORCE_HOLSTER(Actor actor)l
extern _native int ACTOR_DRAW_LAST_WEAPON(Actor actor, bool draw)l
extern _native int ACTOR_DRAW_ANY_WEAPON(Actor actor, bool draw)l
extern _native void ACTOR_DRAW_WEAPON(Actor actor, int weapon, bool draw)l
extern _native int ACTOR_IS_HOLSTERED(int pram0)l
extern _native32(0x2E84E682) void _ACTOR_SET_ENABLED(int pram0, int pram1)l
extern _native32(0x261A4C0E) void _ACTOR_SET_MIN_RANGE(int pram0, int pram1, int pram2)l
extern _native32(0x79EFDF7E) void _ACTOR_SET_MIN_RANGE_DEFAULT(int pram0, int pram1)l
extern _native32(0x5D863C30) void _ACTOR_SET_MAX_RANGE(int p0, int p1, float p2)l
extern _native32(0x79EFDF7E) void _ACTOR_SET_BASE_PRIORITY(int p0, int p1, float p2)l
extern _native32(0xCA669478) void _ACTOR_SET_BASE_PRIORITY_DEFAULT(int pram0, int pram1)l
extern _native32(0x7DA34015) void _ACTOR_SET_CAN_USE_INDOORS(int pram0, int pram1)l
//////////////////////////////////
//AI Speech Context
/////////////////////////////////
extern _native void SPEECH_CONTEXT_INIT_DATA(int pram0)l
extern _native void SPEECH_CONTEXT_ADD_CHILD(int pram0, int pram1, int pram2)l
extern _native void SPEECH_CONTEXT_SET_TIME_RESTRICTION(int pram0, int pram1, int pram2)l
extern _native void SPEECH_CONTEXT_SET_OPPOSITE_GENDER_RESTRICTION(int pram0)l
extern _native void SPEECH_CONTEXT_SET_ETHNICITY_RESTRICTION(int pram0, int pram1)l
extern _native32(0x4F64116B) void _SPEECH_CONTEXT_SET_LAW_RESTRICTION(int pram0)l
extern _native void SPEECH_CONTEXT_SET_WEATHER_RESTRICTION_GOOD(int pram0)l
extern _native void SPEECH_CONTEXT_SET_WEATHER_RESTRICTION_RAINY(int pram0)l
extern _native void SPEECH_CONTEXT_SET_TARGET_PLAYER(int pram0)l
extern _native32(0x3C6FE75D) void _SPEECH_CONTEXT_SET_TARGET_FACTION(int pram0, int pram1)l
extern _native void SPEECH_CONTEXT_SET_PLAYER_IDENTITY_RESTRICTION(int pram0, int pram1)l
extern _native void SPEECH_CONTEXT_SET_ALLOW_PHRASE_REUSE(int pram0, int pram1)l
extern _native32(0xAC72E757) void _SPEECH_CONTEXT_DISABLE_NON_COMBAT_SPEECH_UNIVERSAL(int pram0)l
extern _native32(0x99AFD2D1) void _SPEECH_CONTEXT_DISABLE_NON_COMBAT_SPEECH_INDIVIDUAL(int pram0, int pram1, int pram2)l
//////////////////////////////////
//AI Task
/////////////////////////////////
extern _native void TASK_ACTION_PERFORM(int pram0, int pram1)l
//TASK_ACTION_PERFORM_AT_POSITION 0x3F20B619
//TASK_ACTION_PERFORM_ON_TARGET 0xD7E582B1
extern _native void TASK_ANIMAL_PATROL(int pram0, int pram1)l
extern _native void TASK_ANIMAL_CIRCLE_AGGRESSIVELY(int pram0, int pram1)l
//TASK_ANIMAL_FOLLOW_AGGRESSIVELY 0x7ED7676D
//TASK_ANIMAL_HUNT 0xD9B07798
//TASK_BE_DEAD 0x23AFEB8A
//TASK_BE_DEAD_RANDOM 0x8EB3D852
//TASK_BIRD_FLY_NEAR_COORD 0x4730AC93
//TASK_BIRD_LAND 0x525B028A
extern _native void TASK_BIRD_LAND_AT_COORD(int pram0, int pram1)l
//TASK_BIRD_SOAR 0x2C5F5E1B
extern _native void TASK_BIRD_SOAR_AT_COORD(int pram0, int pram1, int pram2, int pram3)l
extern _native void TASK_CROUCH(int pram0, int pram1)l
extern _native void TASK_DISMOUNT(int pram0, int pram1)l
extern _native void TASK_DIVE(int pram0, int pram1)l
//TASK_DIVEAWAYFROM 0xF1A3F362
//TASK_DIVETOWARD 0x342F21D2
//TASK_DOOR_ACTION 0xFDD2905C
extern _native void TASK_DRAW_HOLSTER_WEAPON(int pram0, int pram1)l
extern _native void TASK_FACE_ACTOR(int pram0, int pram1, int pram2, int pram3)l
extern _native void TASK_FACE_COORD(int pram0, int pram1, int pram2)l
extern _native void TASK_FLEE_COORD(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5)l
extern _native void TASK_FLEE_ACTOR(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5, int pram6)l
extern _native void TASK_FLEE_ACTORSET(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5, int pram6)l
extern _native void TASK_FOLLOW_ACTOR(Actor actor, Actor actorToFollow)l
extern _native void TASK_FOLLOW_AND_ATTACK_OBJECT(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5, int pram6, int pram7, int pram8)l
//TASK_FOLLOW_AND_ATTACK_OBJECT_ALONG_PATH 0x467D0FD5
extern _native void TASK_FOLLOW_OBJECT(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5, int pram6, int pram7, int pram8, int pram9)l
extern _native void TASK_FOLLOW_OBJECT_ALONG_PATH(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5)l
extern _native void TASK_FOLLOW_OBJECT_AT_DISTANCE(int pram0, int pram1, int pram2, int pram3)l
//TASK_FOLLOW_OBJECT_IN_FORMATION 0xE2104FED
extern _native void TASK_FOLLOW_PATH(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5, int pram6)l
extern _native void TASK_FOLLOW_PATH_FROM_NEAREST_POINT(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5, int pram6)l
//TASK_FOLLOW_PATH_FROM_POINT 0xCC8B2ECC
extern _native void TASK_GO_NEAR_ACTORSET(int pram0, int pram1, int pram2, int pram3)l
extern _native void TASK_GO_NEAR_COORD(int pram0, int pram1, int pram2, int pram3)l
extern _native void TASK_GO_NEAR_OBJECT(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5)l
extern _native void TASK_GO_TO_COORD(int pram0, int pram1, int pram2)l
extern _native void TASK_GO_TO_COORD_AND_STAY(int pram0, int pram1, int pram2, int pram3)l
extern _native void TASK_GO_TO_COORD_NONSTOP(int pram0, int pram1, int pram2, int pram3)l
extern _native void TASK_GO_TO_COORD_PRECISELY(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5, int pram6, int pram7)l
//TASK_GO_TO_COORD_USING_MATERIAL 0xAA3E5851
extern _native void TASK_GO_TO_OBJECT(int pram0, int pram1, int pram2, int pram3, int pram4)l
//TASK_GUARD_PATROL_AUTO 0x1AF7CE0E
extern _native void TASK_GUARD_PATROL_PATH(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5, int pram6)l
extern _native void TASK_GUARD_STAND(int pram0, int pram1, int pram2)l
extern _native void TASK_HIDE_AT_COVER(int pram0, int pram1, int pram2, int pram3, int pram4)l
extern _native void TASK_HORSE_ACTION(int pram0, int pram1)l
//TASK_JUMP_OVER_OBSTRUCTION 0x97BDA4C8
//TASK_JUMP_TO_OBJECT 0x46A326E6
extern _native void TASK_KILL_CHAR(int pram0, int pram1)l
//TASK_LEDGE_ACTION 0x145B7C2B
extern _native void TASK_MELEE_ATTACK(int pram0, int pram1, int pram2)l
extern _native void TASK_MOUNT(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5)l
//TASK_PLAY_ANIM 0x5AB552C6
extern _native void TASK_POINT_GUN_AT_COORD(Actor actor, vector3 coord, float unk)l
extern _native void TASK_POINT_GUN_AT_OBJECT(int pram0, int pram1, int pram2, int pram3)l
extern _native void TASK_RESPOND_TO_HORSE_WHISTLE(int pram0, int pram1)l
extern _native void TASK_SEARCH(int pram0, int pram1, int pram2)l
extern _native void TASK_SEARCH_FOR_OBJECT(int pram0, int pram1, int pram2, int pram3)l
extern _native void TASK_SEEK_COVER_FROM_ACTOR(int pram0, int pram1)l
//TASK_SEEK_COVER_FROM_COORD 0x3B0F53F4
extern _native void TASK_SEQUENCE_PERFORM(int pram0, int pram1)l
extern _native void TASK_SEQUENCE_PERFORM_REPEATEDLY(int pram0, int pram1, int pram2)l
extern _native void TASK_SHOOT_AT_COORD(int pram0, int pram1, int pram2)l
extern _native void TASK_SHOOT_AT_COORD_FROM_POSITION(int pram0, int pram1, int pram2, int pram3)l
extern _native void TASK_SHOOT_ENEMIES_FROM_ANY_COVER(int pram0, int pram1)l
extern _native void TASK_SHOOT_ENEMIES_FROM_COVER(int pram0, int pram1, int pram2, int pram3)l
extern _native void TASK_SHOOT_ENEMIES_FROM_POSITION(int pram0, int pram1, int pram2, int pram3)l
//TASK_SHOOT_ENEMIES_FROM_PREFERRED_COVER 0x1813667D
extern _native void TASK_SHOOT_FROM_COVER(int pram0, int pram1, int pram2, int pram3, int pram4)l
extern _native void TASK_SHOOT_FROM_POSITION(int pram0, int pram1, int pram2)l
//TASK_SIMPLE_BEHAVIOR 0xDE18EDA3
extern _native void TASK_STAND_STILL(Actor actor, int unk1, int unk2, int unk3)l
//TASK_STEALTH_ATTACK 0x86A98E99
extern _native void TASK_SURROUND_ACTOR(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5)l
extern _native void TASK_TAUNT_ACTOR(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5)l
extern _native void TASK_TAUNT_ACTOR_IN_PLACE(int pram0, int pram1, int pram2)l
//TASK_TR_ACTION 0x1C7834B1
//TASK_TR_ACTION_ON_ACTOR 0xCFA55B6
extern _native void TASK_USE_GRINGO(Actor actor, int pram1, int pram2, int pram3, int pram4)l
//TASK_USE_GRINGO_GROUP 0x65D93BD
extern _native void TASK_USE_LASSO(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5)l
extern _native void TASK_USE_TURRET(int pram0, int pram1, int pram2)l
extern _native void TASK_USE_TURRET_AGAINST_COORD(int pram0, int pram1, int pram2, int pram3)l
extern _native void TASK_USE_TURRET_AGAINST_OBJECT(int pram0, int pram1, int pram2, int pram3)l
extern _native void TASK_VEHICLE_ENTER(int pram0, int pram1, int pram2, int pram3)l
extern _native void TASK_VEHICLE_ENTER_SPECIFIC_LOCATION(int pram0, int pram1, int pram2, int pram3, int pram4)l
extern _native void TASK_VEHICLE_LEAVE(int pram0)l
extern _native void TASK_WANDER(int pram0, int pram1)l
extern _native void TASK_WANDER_IN_BOX(int pram0, int pram1, int pram2, int pram3)l
extern _native void TASK_WANDER_IN_VOLUME(int pram0, int pram1, int pram2)l
//TASK_WARN_CHAR 0x9ABE6BC0
extern _native void TASK_GO_NEAR_ACTOR(int pram0, int pram1, int pram2, int pram3)l
extern _native int GET_TASK_STATUS(int pram0, int pram1)l
extern _native int IS_TASKED_TO_USE_GRINGO_FOREVER(int pram0, int pram1)l
extern _native int GET_NTH_TASK_STATUS(int pram0, int pram1)l
extern _native int GET_TASK_SEQUENCE_CURRENT_TASK_INDEX(int pram0, int pram1)l
extern _native int GET_TASK_NEXT_POINT_ON_PATH(int pram0, int pram1)l
extern _native void TASK_CLEAR(Actor actor)l
extern _native void TASK_OVERRIDE_CLEAR_MOVETYPE(int pram0)l
extern _native void TASK_OVERRIDE_CLEAR_POSTURE(int pram0)l
extern _native void TASK_OVERRIDE_SET_MOVETYPE(int pram0, int pram1)l
extern _native void TASK_OVERRIDE_SET_MOVESPEED_ABSOLUTE(int pram0, int pram1)l
extern _native void TASK_OVERRIDE_SET_MOVESPEED_NORMALIZED(int pram0, int pram1)l
extern _native void TASK_OVERRIDE_SET_POSTURE(int pram0, int pram1)l
extern _native void TASK_PRIORITY_SET(int pram0, int pram1)l
extern _native int TASK_SEQUENCE_OPEN()l
extern _native void TASK_SEQUENCE_CLOSE()l
extern _native void TASK_SEQUENCE_RELEASE(int pram0, int pram1)l
extern _native void SET_ACTOR_FACE_STYLE(int pram0, int pram1)l
extern _native void AI_SET_ENABLE_STICKUP_OVERRIDE(int pram0, int pram1)l
extern _native void AI_SET_ENABLE_HORSE_CHARGE_REACTIONS(int pram0, int pram1)l
extern _native void AI_SET_ENABLE_DEAD_BODY_REACTIONS(int pram0, int pram1)l
extern _native void TASK_FAILURE_MODE_SET(int pram0, int pram1)l
//////////////////////////////////
//AI Squad
/////////////////////////////////
extern _native int SQUAD_GET(int pram0)l
extern _native bool SQUAD_IS_VALID(int pram0)l
extern _native void SQUAD_JOIN(int pram0, int pram1)l
extern _native void SQUAD_LEAVE(Actor actor)l
extern _native void SQUAD_MAKE_EMPTY(int pram0)l
extern _native void SQUADS_MERGE(int pram0, int pram1)l
extern _native int SQUAD_GET_ACTOR_BY_INDEX(int pram0, int pram1)l
extern _native int SQUAD_GET_SIZE(int pram0)l
extern _native int SQUAD_COMPUTE_CENTROID(int pram0, int pram1)l
extern _native void SQUAD_SET_FACTION(int pram0, int pram1)l
extern _native int SQUAD_GOAL_ADD_BATTLE_ALLIES(int pram0, int pram1, int pram2, int pram3)l
extern _native int SQUAD_GOAL_ADD_BATTLE_DEFEND_VOLUME(int pram0, int pram1, int pram2, int pram3)l
extern _native int SQUAD_GOAL_ADD_COMBAT(int pram0, int pram1, int pram2, int pram3)l
extern _native int SQUAD_GOAL_ADD_FACTION_STATUS_WITHIN_GOAL(int pram0, int pram1, int pram2)l
extern _native int SQUAD_GOAL_ADD_FLOCK(int p0, int p1, int p2)l
extern _native int SQUAD_GOAL_ADD_FOLLOW_OBJECT_IN_FORMATION(int p0, int p1, int p2, int p3, int p4, int p5, int p6, int p7)l
extern _native int SQUAD_GOAL_ADD_FOLLOW_PATH_IN_FORMATION(int p0, int p1, int p2, int p3, int p4, int p5, int p6, int p7)l
extern _native int SQUAD_GOAL_ADD_FOLLOW_TRAFFIC_CURVE(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5, int pram6)l
extern _native int SQUAD_GOAL_ADD_GENERAL_TASK(int pram0, int pram1, int pram2, int pram3)l
extern _native int SQUAD_GOAL_ADD_GUARD_POSITION(int p0, int p1, int p2, float p3)l//maybe squad then vector3 as a shortcut, or squad, x y z
extern _native int SQUAD_GOAL_ADD_HUNT_ENEMIES(int p0, int p1, int p2, int p3, int p4)l
extern _native int SQUAD_GOAL_ADD_MEET_AT_POSITION(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5)l
extern _native int SQUAD_GOAL_ADD_RESTRICT_INVESTIGATION_DISTANCE_FROM_SQUAD(int pram0, int pram1, int pram2)l
extern _native int SQUAD_GOAL_ADD_SHARE_PERCEPTION(int pram0, int pram1)l
extern _native int SQUAD_GOAL_ADD_STAY_OUTSIDE_OF_VOLUME(int pram0, int pram1, int pram2, int pram3, int pram4)l
extern _native int SQUAD_GOAL_ADD_STAY_WITHIN_VOLUME(int pram0, int pram1, int pram2, int pram3, int pram4)l
extern _native int UNK_0x48588CCB(int pram0, int pram1, int pram2, int pram3)l
extern _native int SQUAD_GOAL_GET_STATUS(int pram0, int pram1)l
extern _native int SQUAD_GOAL_IS_VALID(int pram0)l
extern _native int SQUAD_GOAL_REMOVE(int p0, int p1)l
extern _native void SQUAD_GOALS_CLEAR(int pram0)l
extern _native int SQUAD_IS_GOAL_CONTROLLING_ACTOR(int pram0, int pram1, int pram2)l
extern _native int SQUAD_GET_SINGLE_ACTOR_CONTROLLED_BY_GOAL(int pram0, int pram1)l
extern _native int SQUAD_GOAL_LINK_MODIFIER_TO_OTHER_GOAL(int pram0, int pram1, int pram2)l
extern _native void SQUAD_FLOCK_SET_EXTERNAL_MOVEMENT_TUNING(int pram0, int pram1, int pram2, int pram3, int pram4)l
extern _native int SQUAD_FLOCK_SET_FLOCKING_PARAMETER(int p0, int p1, int p2, int p3, int p4, float p5)l
extern _native int SQUAD_FLOCK_SET_BOOL_FLOCKING_PARAMETER(int p0, int p1, int p2, int p3, int p4, int p5)l
extern _native void SQUAD_FLOCK_ADD_EXTERNAL_ALERT(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5)l
extern _native void SQUAD_FLOCK_ADD_EXTERNAL_ATTRACTION_PATH(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5, int pram6)l
extern _native void SQUAD_FLOCK_ADD_EXTERNAL_REPULSION(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5, int pram6, int pram7)l
extern _native void SQUAD_FLOCK_ADD_EXTERNAL_VELOCITY_MATCH(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5)l
extern _native void SQUAD_FLOCK_PLAYER_PROXIMITY_BOOST_SET_ENABLED(int pram0, int pram1, int pram2)l
extern _native void SQUAD_FLOCK_PLAYER_WHISTLE_BOOST_SET_ENABLED(int pram0, int pram1, int pram2)l
extern _native int SQUAD_FLOCK_EVENT_BOOST_SET_ENABLED(int p0, int p1, int p2, int p3)l
extern _native void UNK_0x175BE678(int pram0, int pram1, int pram2, int pram3, int pram4)l//_SQUAD_FLOCK_GET_FLOCKING_PARAMETER_2
extern _native32(0x5AEA32D1) int _SQUAD_FLOCK_CLEAR_EXTERNAL_INFLUENCES(int p0, int p1)l
extern _native32(0x484643F6) int _SQUAD_FLOCK_CLEAR_EXTERNAL_INFLUENCES_FROM_OBJECT(int p0, int p1, int p2)l
extern _native int UNK_0x1CEB8BFF(int p0, int p1, int p2, float p3, float p4)l//_SQUAD_FLOCK_ADD_EXTERNAL_ALERT_2
extern _native void UNK_0xB4D9B233(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5, int pram6, int pram7)l//_SQUAD_FLOCK_ADD_EXTERNAL_REPULSION_2
extern _native int SQUAD_FLOCK_SET_ALLOW_STRAGGLERS(int p0, int p1, int p2)l
extern _native void SQUAD_HUNT_ENEMIES_SET_DEFAULT_BLIP_ALERTED(int pram0)l
extern _native void SQUAD_HUNT_ENEMIES_SET_DEFAULT_BLIP_INVESTIGATING(int pram0)l
extern _native void SQUAD_HUNT_ENEMIES_SET_DEFAULT_BLIP_UNALERTED(int pram0, int pram1)l
extern _native int SQUAD_GET_NUM_ELIMINATED_ACTORS(int pram0)l
extern _native int SQUAD_GET_NUM_NOT_ELIMINATED_ACTORS(int pram0)l
extern _native void SQUAD_SET_NOT_ELIMINATED_IMPAIRMENT_MASK(int pram0, int pram1)l
extern _native int SQUAD_GET_NOT_ELIMINATED_IMPAIRMENT_MASK(int pram0)l
extern _native int SQUAD_BATTLE_ALLIES_SET_OBJECTIVE(int p0, int p1, int p2)l
extern _native void SQUAD_BATTLE_ALLIES_SET_FORMATION_DENSITY(int pram0, int pram1, int pram2)l
extern _native int SQUAD_FOLLOW_TRAFFIC_CURVE_GET_ALL_BEHAVIOR_FLAGS(int p0, int p1)l
extern _native int SQUAD_FOLLOW_TRAFFIC_CURVE_SET_ALL_BEHAVIOR_FLAGS(int p0, int p1, int p2)l
extern _native bool SQUAD_FOLLOW_TRAFFIC_CURVE_GET_BEHAVIOR_FLAG(int p0, int p1, int p2)l
extern _native void SQUAD_FOLLOW_TRAFFIC_CURVE_SET_BEHAVIOR_FLAG(int pram0, int pram1, int pram2, int pram3)l
extern _native int SQUAD_FOLLOW_TRAFFIC_CURVE_SET_CURVE(int p0, int p1, int p2, int p3)l
extern _native void SQUAD_FOLLOW_TRAFFIC_CURVE_ENQUEUE_CURVE(int pram0, int pram1, int pram2, int pram3)l
extern _native int SQUAD_FOLLOW_TRAFFIC_CURVE_SET_SPEED(int p0, int p1)l
extern _native int SQUAD_FOLLOW_TRAFFIC_CURVE_SET_SPEED_ABSOLUTE(int p0, int p1, float p2)l
extern _native int SQUAD_FOLLOW_TRAFFIC_CURVE_SET_SPEED_NORMALIZED(int p0, int p1, float p2)l
extern _native void SQUAD_FOLLOW_TRAFFIC_CURVE_SET_TASK_PRIORITY(int pram0, int pram1, int pram2)l
extern _native int SQUAD_FOLLOW_TRAFFIC_CURVE_SET_OFFSET_X(int p0, int p1, float p2)l
extern _native int SQUAD_FOLLOW_TRAFFIC_CURVE_SET_ALLOW_PLAYER_JOIN(int p0)l
extern _native int SQUAD_FOLLOW_TRAFFIC_CURVE_SET_DESIRED_LEADER(int p0, int p1, int p2)l
extern _native int SQUAD_FOLLOW_TRAFFIC_CURVE_CLEAR_DESIRED_LEADER(int p0, int p1)l
extern _native int SQUAD_FOLLOW_TRAFFIC_CURVE_IS_CURVE_ALREADY_IN_LIST(int pram0, int pram1, int pram2, int pram3, int pram4)l
extern _native int SQUAD_FOLLOW_PATH_IN_FORMATION_GET_ALL_BEHAVIOR_FLAGS(int p0, int p1)l
extern _native int SQUAD_FOLLOW_PATH_IN_FORMATION_SET_ALL_BEHAVIOR_FLAGS(int p0, int p1, int p2)l
extern _native bool SQUAD_FOLLOW_PATH_IN_FORMATION_GET_BEHAVIOR_FLAG(int p0, int p1, int p2)l
extern _native int SQUAD_FOLLOW_PATH_IN_FORMATION_SET_BEHAVIOR_FLAG(int p0, int p1, int p2, int p3)l
extern _native int SQUAD_FOLLOW_PATH_IN_FORMATION_SET_PATH(int p0, int p1, int p2)l
extern _native int SQUAD_FOLLOW_PATH_IN_FORMATION_SET_SPEED(int p0)l
extern _native int SQUAD_FOLLOW_PATH_IN_FORMATION_SET_SPEED_ABSOLUTE(int p0, float p1)l
extern _native int SQUAD_FOLLOW_PATH_IN_FORMATION_SET_SPEED_NORMALIZED(int p0, float p1)l
extern _native int SQUAD_FOLLOW_PATH_IN_FORMATION_SET_TASK_PRIORITY(int p0, int p1, int p2)l
extern _native int SQUAD_FOLLOW_PATH_IN_FORMATION_SET_OFFSET_X(int p0, int p1, float p2)l
extern _native int SQUAD_FOLLOW_PATH_IN_FORMATION_SET_ALLOW_PLAYER_JOIN(int p0, int p1, int p2, int p3)l
extern _native int SQUAD_FOLLOW_PATH_IN_FORMATION_SET_NONSTOP(int p0, int p1, int p2)l
extern _native int SQUAD_FOLLOW_PATH_IN_FORMATION_SET_DESIRED_LEADER(int p0, int p1, int p2)l
extern _native int SQUAD_FOLLOW_PATH_IN_FORMATION_CLEAR_DESIRED_LEADER(int p0, int p1)l
//////////////////////////////////
//AI World
/////////////////////////////////
extern _native void ENABLE_AMBIENT_SPAWNING(bool enable)l
extern _native void SET_AMBIENT_FORCE_WAIT_STATE(int pram0)l
extern _native void SET_POP_DENSITY_MULTIPLIER(int pram0)l
extern _native void DESTROY_AMBIENT_ACTORS_IF_POSSIBLE()l
extern _native int FORCE_AMBIENT_NUM_ACTORS_REQUESTED_FOR_MISSIONS()l
extern _native void SET_AMBIENT_NUM_ACTORS_REQUESTED_FOR_MISSIONS(int pram0)l
extern _native int GET_AMBIENT_NUM_ACTORS_GRANTED_FOR_MISSIONS()l
extern _native int GET_AMBIENT_MAX_NUM_TOTAL_ACTORS()l
extern _native void SET_AMBIENT_MAX_NUM_TOTAL_ACTORS(int pram0)l
extern _native32(0x1C8CA53C) void _SET_ACTOR_SPEED_SCALE_RANGE(Actor actor, float speed)l
extern _native void SET_AMBIENT_TUNING_MAX_VISIBLE_RANGE(int pram0)l
extern _native void CLEAR_AMBIENT_ALL_RESTRICTIONS()l
extern _native void CLEAR_AMBIENT_MOVE_RESTRICTIONS()l
extern _native void CLEAR_AMBIENT_SPAWN_RESTRICTIONS()l
extern _native void ADD_AMBIENT_SPAWN_TYPE_RESTRICTION(int pram0)l
extern _native void CLEAR_AMBIENT_SPAWN_TYPE_RESTRICTION(int pram0)l
extern _native void CLEAR_ALL_AMBIENT_SPAWN_TYPE_RESTRICTIONS()l
extern _native void SET_AMBIENT_STREAMING_REQUIRED_POP_ACTOR_SCALE(int pram0)l
extern _native32(0xC519E3F3) void _SET_AMBIENT_ANIMALS_AGGRESSIVENESS(int pram0)l
extern _native void ADD_AI_MOVE_RESTRICTION_STAY_OUTSIDE_OF_VOLUME_SET(int pram0, int pram1)l
extern _native void REMOVE_AI_MOVE_RESTRICTION_STAY_OUTSIDE_OF_VOLUME_SET(int pram0, int pram1)l
extern _native void ADD_AMBIENT_MOVE_RESTRICTION_STAY_OUTSIDE_OF_VOLUME(int pram0)l
extern _native void ADD_AMBIENT_SPAWN_RESTRICTION_STAY_OUTSIDE_OF_VOLUME(int pram0)l
extern _native void REMOVE_AMBIENT_MOVE_RESTRICTION_STAY_OUTSIDE_OF_VOLUME(int restriction)l
extern _native void REMOVE_AMBIENT_SPAWN_RESTRICTION_STAY_OUTSIDE_OF_VOLUME(int restriction)l
extern _native bool DOES_AMBIENT_MOVE_RESTRICTION_VOLUME_EXIST(int restriction)l
extern _native int DOES_AMBIENT_SPAWN_RESTRICTION_VOLUME_EXIST(int restriction)l
extern _native void RELEASE_ACTOR_AS_AMBIENT(Actor actor)l
extern _native bool WOULD_ACTOR_BE_VISIBLE(eActor id, vector3 pos, int unk)l
extern _native void UNK_0x515E17DC(int pram0)l
extern _native int ACTIVATE_EMERGENCY_TELEPORT_FOR_ACTOR(int pram0, int pram1, int pram2, int pram3, int pram4)l
extern _native int DEACTIVATE_EMERGENCY_TELEPORT_FOR_ACTOR(int pram0)l
extern _native int IS_POINT_IN_AMBIENT_MOVE_RESTRICTION_VOLUME(int pram0)l
extern _native void SET_ACTOR_OBEY_AMBIENT_MOVE_RESTRICTIONS(int pram0, int pram1)l
extern _native int DOES_ACTOR_OBEY_AMBIENT_MOVE_RESTRICTIONS(int pram0)l
extern _native void SET_AMBIENT_DEAD_COUNT_DECAY_RATE(int pram0)l
//////////////////////////////////
//AI Vision
/////////////////////////////////
extern _native int CAN_ANYONE_OF_FACTION_SEE_OBJECT(int pram0, int pram1)l
//////////////////////////////////
//AI Speech
/////////////////////////////////
extern _native int AI_SPEECH_ADD_PHRASE(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5, int pram6)l
extern _native void AI_SPEECH_ADD_TAG_FOR_PHRASE(int pram0, int pram1, int pram2)l
extern _native void AI_SPEECH_REGISTER_EVENT(int pram0, int pram1)l
extern _native void AI_SPEECH_REGISTER_TAG(int pram0, int pram1, int pram2, int pram3)l
extern _native void AI_SPEECH_REGISTER_TAGS_BEGIN(int pram0)l
extern _native void AI_SPEECH_REGISTER_TAGS_END()l
extern _native int AI_SPEECH_GET_ALLOW_FOR_ACTOR(int pram0)l
extern _native void AI_SPEECH_SET_ALLOW_CONTEXT_FOR_ACTOR(int pram0, int pram1, int pram2)l
extern _native void AI_SPEECH_SET_ALLOW_CONTEXT_GLOBAL(int pram0, int pram1)l
extern _native void AI_SPEECH_SET_ALLOW_FOR_ACTOR(int pram0, int pram1)l
extern _native void AI_SPEECH_SET_DEFAULT_PACKAGE(int pram0)l
extern _native Actor AI_GET_ACTOR_CONVERSATION_TARGET(int pram0)l
extern _native int AI_IS_ACTOR_SOCIALIZING(Actor actor)l
//////////////////////////////////
//AI Ride
/////////////////////////////////
extern _native void AI_RIDING_SET_ATTRIBUTE(int p0, int p1, float p2)l
extern _native void AI_RIDING_SET_ENABLED(int pram0, int pram1)l
//////////////////////////////////
//AI Perception
/////////////////////////////////
extern _native void AI_PERCEPTION_SET_HEARING_GLOBAL_RANGE_FACTOR(int pram0)l//DISABLE_VERIFY_SS what fox and roulette had
extern _native void AI_PERCEPTION_SET_VISUAL_ID_DISTANCE(int pram0, int pram1)l
extern _native void AI_PERCEPTION_SET_VISUAL_ID_TIME(int pram0, int pram1)l
extern _native void AI_DISABLE_PERCEPTION(int pram0)l
extern _native void AI_ENABLE_PERCEPTION(int pram0)l
//////////////////////////////////
//AI Nav Mesh Moveable
/////////////////////////////////
extern _native bool STREAMING_IS_MOVABLE_NAV_MESH_RESIDENT(int pram0)l //.xnm
extern _native void STREAMING_REQUEST_MOVABLE_NAV_MESH(int assetID)l //.xnm
extern _native void STREAMING_UNREQUEST_MOVABLE_NAV_MESH(int pram0)l
extern _native void SET_ACTOR_MOVABLE_NAV_MESH(int p0)l
//////////////////////////////////
//AI Nav
/////////////////////////////////
extern _native void AI_CLEAR_NAV_MATERIAL_USAGE(int pram0)l
extern _native void AI_RESET_NAV_ACTOR_WIDTH(int pram0)l
extern _native void AI_SET_NAV_ACTOR_WIDTH(int pram0, int pram1)l
extern _native void AI_SET_NAV_HAZARD_AVOIDANCE_ENABLED(int pram0, int pram1, int pram2)l
extern _native void AI_SET_NAV_MATERIAL_USAGE(int pram0, int pram1, int pram2)l
extern _native void AI_SET_NAV_PATHFINDING_ENABLED(int pram0, int pram1)l
extern _native void AI_SET_NAV_PATHFINDING_ENABLED_WHEN_DRIVING(int pram0, int pram1)l
extern _native void AI_SET_NAV_MAX_SLOPE(int p0, float p1)l
extern _native void AI_SET_NAV_MAX_WATER_DEPTH_LEVEL(int pram0, int pram1)l
extern _native void AI_SET_NAV_ACTOR_AVOIDANCE_MODE(int pram0, int pram1)l
extern _native void AI_SET_NAV_ACTOR_AVOIDANCE_ALLOW_TURNS(int pram0, int pram1)l
extern _native int AI_GET_NAV_ACTOR_AVOIDANCE_ALLOW_TURNS(int pram0)l
extern _native void AI_RESET_NAV_SUBGRID_CELL_SIZE(int pram0)l
extern _native void AI_SET_NAV_SUBGRID_CELL_SIZE(int pram0, int pram1)l
extern _native void AI_SET_NAV_FAILSAFE_MOVEMENT_ENABLED(int pram0, int pram1)l
extern _native int AI_GET_NAV_FAILSAFE_MOVEMENT_ENABLED(int pram0)l
extern _native void AI_SET_NAV_UNALERTED_PREFER_PEDPATH(int pram0, int pram1)l
extern _native void AI_SET_NAV_ALLOW_TWEAK_DESIRED_MOVEMENT(int p0, const char* p1)l
extern _native int AI_GET_NAV_ALLOW_TWEAK_DESIRED_MOVEMENT(int pram0)l
extern _native void AI_SWAP_NAV_DATA(int pram0)l
//////////////////////////////////
//AI Misc
/////////////////////////////////
extern _native void AI_BEHAVIOR_SET_ALLOW(int pram0, int pram1, int pram2)l
//AI_ACTION_IS_ACTIVE 0x8F428EDF
//AI_GOAL_AIM_AT_COORD 0x671851D4
extern _native void AI_GOAL_AIM_AT_OBJECT(int pram0, int pram1, int pram2)l
extern _native void AI_GOAL_AIM_CLEAR(int pram0)l
extern _native void AI_GOAL_LOOK_AT_ACTOR(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5, int pram6)l
extern _native void AI_GOAL_LOOK_AT_COORD(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5)l
extern _native void AI_GOAL_LOOK_AT_ACTOR_NEW(int pram0, int pram1, int pram2, int pram3)l
//AI_GOAL_LOOK_AT_COORD_NEW 0x245D0CFD
extern _native void AI_GOAL_LOOK_AT_NEUTRAL(int pram0, int pram1)l
extern _native void AI_GOAL_LOOK_CLEAR(int pram0)l
//AI_GOAL_SHOOT_AT_OBJECT 0x10674B4F
extern _native void AI_GOAL_SHOOT_AT_COORD(int pram0, int pram1)l
extern _native void AI_GOAL_SHOOT_CLEAR(int pram0)l
//AI_GOAL_STAND_AT_COORD 0xD9B27A9E
//AI_GOAL_STAND_CLEAR 0xEADB58EB
extern _native int AI_PREDICATE_FIND_NAMED(int pram0, int pram1)l
extern _native int AI_PREDICATE_IS_VALID(int pram0)l
extern _native void AI_PREDICATE_OVERRIDE_CLEAR(int pram0, int pram1)l
extern _native void AI_PREDICATE_OVERRIDE_CLEAR_ALL(int pram0)l
extern _native void AI_PREDICATE_OVERRIDE_SET_BOOL(int pram0, int pram1, int pram2)l
extern _native int AI_IGNORE_ACTOR(Actor actor)l
extern _native int AI_STOP_IGNORING_ACTOR(Actor actor)l
extern _native void AI_STOP_IGNORING_ACTORS()l
extern _native void AI_DONT_HARM_ACTOR(int pram0)l
extern _native void AI_CLEAR_DONT_HARM_ACTOR(int pram0)l
extern _native void AI_SET_ALLOW_HOSTILE_ATTACK_AI(int pram0)l
extern _native void AI_SET_ALLOW_HOSTILE_ATTACK_PLAYER(int pram0)l
//AI_SHOOT_TARGET_CLEAR_OFFSET 0x548541C1
//AI_SHOOT_TARGET_SET_OFFSET 0x39C69C4
extern _native void AI_SHOOT_TARGET_SET_BONE(int pram0, int pram1, int pram2)l
//_AI_PLAYER_GOAL_LOOK_AT_COORD_LEGACY 0xFF36BAED
//_AI_FORCE_STOP_LOOK_AT_COORD 0x6F37F42C
extern _native void SET_FORCED_LOOK_ENABLE(int pram0, int pram1)l
//GET_FORCED_LOOK_ENABLE 0xF0511878
//0xE56D3FCE
extern _native void UNK_0x6C194C1F(int pram0)l
extern _native void FORCE_LOOK_AT_ACTOR(int pram0, int pram1, int pram2)l
extern _native void SET_AUTO_CONVERSATION_LOOK(int pram0, int pram1)l
extern _native void AI_GOAL_LOOK_AT_PLAYER_WHEN_WITHIN(int pram0, int pram1)l
//AI_GOAL_LOOK_AT_PLAYER_WHEN_WITHIN_CLEAR 0x4DB11394
extern _native void CLEAR_ACTORS_HORSE(Actor actor)l
extern _native Actor GET_ACTORS_HORSE(Actor actor)l
extern _native void SET_ACTORS_HORSE(int pram0, int pram1)l
extern _native int IS_AI_ACTOR_IN_COMBAT(int pram0)l
//IS_AI_ACTOR_PERFORMING_TASK 0x6718D199
extern _native bool IS_AI_ACTOR_UNALERTED(int pram0)l
extern _native void AI_SET_RANGE_ACCURACY_MODIFIER(int pram0, int pram1, int pram2)l
extern _native void AI_SET_DISARMED(Actor actor, bool disarmed)l
extern _native int AI_IMPAIRMENT_MASK_GET_CURRENT_FOR_ACTOR(int pram0)l
extern _native int AI_IMPAIRMENT_MASK_MATCHES(int pram0, int pram1)l
extern _native void AI_ACTOR_FORCE_SPEED(Actor actor, int speed)l
extern _native void AI_ACTOR_SET_MATCH_WALK_SPEED_ENABLED(Actor actor, bool enabled)l
extern _native void AI_SET_WEAPON_MAX_RANGE(int pram0, int pram1)l
extern _native void AI_SET_WEAPON_MIN_RANGE(int pram0, int pram1)l
extern _native void AI_SET_WEAPON_DESIRED_RANGE(int pram0, int pram1)l
extern _native void AI_SET_BURST_DURATION(int pram0, int pram1)l
extern _native void AI_SET_BURST_DURATION_RANDOMNESS(int pram0, int pram1)l
extern _native void AI_SET_FIRE_DELAY(Actor actor, float delay)l
extern _native void AI_SET_FIRE_DELAY_RANDOMNESS(Actor actor, float random)l
extern _native void AI_SET_SHOTS_PER_BURST(int pram0, int pram1)l
extern _native void AI_CLEAR_BURST_DURATION(int pram0)l
extern _native void AI_CLEAR_BURST_DURATION_RANDOMNESS(int pram0)l
extern _native void AI_CLEAR_FIRE_DELAY(int pram0)l
extern _native void AI_CLEAR_FIRE_DELAY_RANDOMNESS(int pram0)l
extern _native void AI_CLEAR_SHOTS_PER_BURST(int pram0)l
extern _native void AI_RESET_FIRING_FSM(int pram0)l
extern _native void AI_SET_GATLING_MAX_HORIZONTAL_DEGREES(Actor actor, float rotation)l
extern _native int AI_IS_HOSTILE_OR_ENEMY(int pram0, int pram1)l
extern _native void AI_QUICK_EXIT_GRINGO(Actor actor, int pram1)l
extern _native int AI_IS_AGGROING(int pram0, int pram1)l
extern _native void AI_SET_ALLOWED_MOUNT_DIRECTIONS(int pram0, int pram1)l
extern _native void AI_AVOID_IGNORE_ACTOR(int pram0, int pram1)l
//AI_AVOID_CLEAR_IGNORE_ACTOR 0x1A96EFB9
extern _native bool IS_AI_ACTOR_ENGAGED_IN_COMBAT(int pram0)l
extern _native bool WAS_AI_ACTOR_PLAYER_WEAPON_THREATENED_BY(int pram0, int pram1, int pram2)l
extern _native void AI_SET_ALLOW_ATTACK_HOGTIED_ACTORS(int pram0, int pram1)l
extern _native int AI_GET_IS_RETREATING(int pram0)l
//AI_HAS_PLAYER_FIRED_GUN_WITHIN 0x1530A3DE
extern _native bool AI_HAS_PLAYER_PROJECTILE_IMPACTED_WITHIN(int pram0, int pram1)l
extern _native bool AI_HAS_PLAYER_PROJECTILE_NEAR_MISSED_WITHIN(int pram0, int pram1, int pram2)l
extern _native void AI_SET_PLAYER_PROJECTILE_IMPACT_HEAR_RANGE(int pram0, int pram1)l
//AI_DONT_SLOW_DOWN_TO_WALK_FOR_TURNS 0xA421F94
extern _native int AI_HAS_ACTOR_BUMPED_INTO_ME(int pram0, int pram1, int pram2)l
extern _native int AI_WAS_PUSHED_OVER(int pram0, int pram1)l
extern _native bool AI_WAS_PUSHED_OVER_BY(int p0, int p1, int p2, int p3, int p4, float p5)l
extern _native bool AI_SELF_DEFENSE_GET_PLAYER_ATTACKED_FIRST(int p0)l
extern _native int AI_SELF_DEFENSE_GET_ATTACKED_PLAYER_FIRST(int pram0)l
extern _native int AI_SELF_DEFENSE_SET_PLAYER_ATTACKED_FIRST(int p0)l
extern _native int AI_SET_IGNORE_OPEN_AREA_MATERIAL(int p0, const char* p1)l
extern _native int AI_GET_IGNORE_OPEN_AREA_MATERIAL(int p0)l
extern _native int AI_SET_ENABLE_REACTION_VO(int p0, const char* p1)l
extern _native int AI_GET_TASK_RETREAT_FLAG(int pram0)l
extern _native void PREVENT_DESPAWN_CLEAR()l
extern _native void PREVENT_DESPAWN_SET_SPHERE(int pram0, int pram1, int pram2, int pram3)l
extern _native bool AI_HAS_ACTOR_THREATENED_RECENTLY(int pram0)l
extern _native void AI_REPLACE_ALL_TR(int pram0)l
extern _native void AI_SET_TR_PROGRAM_FOR_ACTOR(int pram0, int pram1)l
//////////////////////////////////
//AI Memory
/////////////////////////////////
extern _native void MEMORY_CLEAR_EVENTS(int pram0, int pram1)l
extern _native void MEMORY_CLEAR_ALL(int pram0)l
extern _native void MEMORY_CONSIDER_ACCORDING_TO_FACTION(int pram0, int pram1)l
extern _native void MEMORY_CONSIDER_AS(int pram0, int pram1, int pram2)l
extern _native void MEMORY_CONSIDER_AS_ENEMY(int pram0, int pram1)l
extern _native int MEMORY_GET_IS_IDENTIFIED(int pram0, int pram1)l
extern _native int MEMORY_GET_IS_VISIBLE(int pram0, int pram1)l
extern _native int MEMORY_GET_WAS_VISIBLE_WITHIN_TIME(int pram0, int pram1, int pram2)l
extern _native void MEMORY_IDENTIFY(int pram0, int pram1)l
extern _native void MEMORY_REPORT_POSITION(int pram0, int pram1, int pram2)l
extern _native void MEMORY_REPORT_POSITION_AUTO(int pram0, int pram1, int pram2)l
extern _native int MEMORY_GET_MUST_IDENTIFY(int pram0, int pram1)l
extern _native void MEMORY_ATTACK_ON_SIGHT(int pram0, int pram1)l
extern _native void MEMORY_CLEAR_RIDING_PREFERENCE(int pram0)l
extern _native void MEMORY_PREFER_RIDING(int pram0, int pram1)l
extern _native void MEMORY_PREFER_WALKING(int pram0, int pram1)l
extern _native void MEMORY_PREFER_MELEE(int pram0, int pram1)l
extern _native void MEMORY_FORCE_MELEE(int pram0, int pram1)l//0xC175F2B5
extern _native void MEMORY_ALLOW_SHOOTING(int pram0, int pram1)l
extern _native void MEMORY_ALLOW_TAKE_COVER(Actor actor, bool allow)l
extern _native void MEMORY_ALLOW_THROWING_EXPLOSIVES(int pram0, int pram1)l
extern _native int MEMORY_ALLOW_PICKUP_WEAPONS(int p0, int p1, int p2, int p3, int p4, int p5)l
extern _native int MEMORY_GET_WEAPON_DRAW_PREFERENCE(int p0)l
extern _native void MEMORY_CLEAR_WEAPON_DRAW_PREFERENCE(int pram0)l
extern _native void MEMORY_SET_WEAPON_DRAW_PREFERENCE(int pram0, int pram1)l
extern _native int MEMORY_GET_POSITION_LAST_KNOWN_TIME(int pram0, int pram1)l
extern _native void MEMORY_EVERYBODY_FORGET_ABOUT(int pram0)l
extern _native void MEMORY_EVERYBODY_FORGET_ABOUT_EVERYTHING()l
extern _native void MEMORY_SHOULD_ALWAYS_PATHFIND_IN_FORMATION(int pram0, int pram1)l
extern _native void AI_GLOBAL_CLEAR_ALL_DANGER()l
extern _native void AI_GLOBAL_CLEAR_DANGER(int pram0)l
extern _native int AI_GLOBAL_GET_PERMANENT_DANGER(int pram0)l
extern _native int AI_GLOBAL_IS_DANGER(int pram0, int pram1)l
extern _native void AI_GLOBAL_SET_PERMANENT_DANGER(Actor actor, bool set)l
extern _native void AI_GLOBAL_REPORT_DANGER(int pram0)l
extern _native int MEMORY_SET_UNARMED_RETREAT(int p0)l
//////////////////////////////////
//AI Combat Class
/////////////////////////////////
extern _native void COMBAT_CLASS_AI_CLEAR_ALL_ATTRIBS(int pram0)l
extern _native int COMBAT_CLASS_AI_GET_ATTRIB_BOOL(int p0, int p1)l
extern _native int COMBAT_CLASS_AI_GET_ATTRIB_FLOAT(int pram0, int pram1)l
extern _native int COMBAT_CLASS_AI_GET_RANGE_ACCURACY(int pram0)l
extern _native void COMBAT_CLASS_AI_SET_ATTRIB_BOOL(int pram0, int pram1, int pram2)l
extern _native void COMBAT_CLASS_AI_SET_ATTRIB_FLOAT(Actor actor, int combatClass, float value)l
extern _native void COMBAT_CLASS_AI_SET_FIGHT_ATTACK_DISTANCE(int pram0, int pram1, int pram2)l
extern _native void COMBAT_CLASS_AI_SET_FIGHT_DESIRED_DISTANCE(int pram0, int pram1, int pram2)l
extern _native int COMBAT_CLASS_AI_SET_FIGHT_TIME_BETWEEN_ATTACKS_MULTIPLIER(int p0, float p1)l
extern _native void COMBAT_CLASS_AI_SET_FIGHT_TIME_BETWEEN_ATTACKS(int pram0, int pram1)l
extern _native void COMBAT_CLASS_AI_SET_FRIENDLY_FIRE_CONSIDERATION(Actor actor, bool consideration)l
extern _native void COMBAT_CLASS_AI_SET_RANGE_ACCURACY(int pram0, int pram1)l
extern _native void COMBAT_CLASS_AI_SET_RANGE_BETWEEN_BURSTS_DELAY(int pram0, int pram1, int pram2)l
extern _native void COMBAT_CLASS_NAME_REGISTER_INT(int pram0, int pram1)l
extern _native bool COMBAT_CLASS_REQUEST_EXISTS()l
extern _native Actor COMBAT_CLASS_REQUEST_GET_ACTOR()l
extern _native int COMBAT_CLASS_REQUEST_GET_ENUM_INT()l
extern _native void COMBAT_CLASS_REQUEST_COMPLETED()l
extern _native void COMBAT_CLASS_SERVER_SET_SCRIPT(int pram0)l
extern _native void AI_COMBAT_SET_NEW_STATE_MACHINE_ENABLED(Actor actor, bool enabled)l
//////////////////////////////////
//AI Animal
/////////////////////////////////
extern _native void ANIMAL_SPECIES_FLOCK_AND_TUNING_CLEAR_ALL()l
extern _native void ANIMAL_SPECIES_NEEDS_DOMESTICATION_LEVELS(int pram0)l
extern _native void ANIMAL_SPECIES_SET_SPECIAL_USE_GRINGO(int pram0, int pram1, int pram2, int pram3, int pram4)l
extern _native void ANIMAL_SPECIES_SET_UNALERTED_BEHAVIOR(int pram0, int pram1, int pram2, int pram3)l
extern _native void ANIMAL_SPECIES_FLOCK_SET_ENABLED(int pram0, int pram1, int pram2, int pram3)l
extern _native void ANIMAL_SPECIES_FLOCK_SET_PARAMETER(int pram0, int pram1, int pram2, int pram3, int pram4)l
extern _native void ANIMAL_SPECIES_FLOCK_SET_BOOLEAN_PARAMETER(int pram0, int pram1, int pram2, int pram3, int pram4)l
extern _native int  ANIMAL_SPECIES_ADD_EXTERNAL_PATH_ATTRACTION(float p0, float p1, float p2, float p3, int p4, int p5, int p6)l
extern _native int ANIMAL_SPECIES_REMOVE_EXTERNAL_PATH_ATTRACTION(int p0, int p1, int p2)l
extern _native void ANIMAL_SPECIES_ADD_EXTERNAL_RANDOM_NOISE(int pram0, int pram1, int pram2, int pram3, int pram4)l
extern _native void ANIMAL_SPECIES_ADD_EXTERNAL_REPULSION(int pram0, int pram1, int pram2, int pram3, int pram4)l
extern _native void ANIMAL_SPECIES_ADD_EXTERNAL_INFLUENCE_FLOCK_REASONER(int pram0, int pram1)l
extern _native int ANIMAL_SPECIES_TUNING_GET_ATTRIB_FLOAT(int pram0, int pram1, int pram2)l
extern _native void ANIMAL_SPECIES_TUNING_SET_ATTRIB_BOOL(int pram0, int pram1, int pram2, int pram3)l
extern _native void ANIMAL_SPECIES_TUNING_SET_ATTRIB_FLOAT(int pram0, int pram1, int pram2, int pram3)l
extern _native void ANIMAL_SPECIES_TUNING_MOVE_SET_ATTRIB(int pram0, int pram1, int pram2, int pram3, int pram4)l
extern _native void ANIMAL_SPECIES_TUNING_SET_ATTACHMENT_WITH_OFFSET(int pram0, int pram1, int pram2, int pram3, int pram4, int pram5, int pram6, int pram7, int pram8)l
extern _native void ANIMAL_SPECIES_TUNING_SET_ATTACHMENT_WITH_CHILDBONE(int pram0, int pram1, int pram2, int pram3)l
extern _native void ANIMAL_SPECIES_TUNING_SET_HUNTING_PREY_PROP(int pram0, int pram1)l
extern _native void ANIMAL_SPECIES_TUNING_SET_ATTRIB_FLOAT_FROM_TIME(int pram0, int pram1, int pram2, int pram3)l
extern _native void ANIMAL_SPECIES_INIT_BEGIN(int pram0)l
extern _native void ANIMAL_SPECIES_INIT_REGISTER(int pram0, int pram1)l
extern _native void ANIMAL_SPECIES_INIT_END()l
extern _native void ANIMAL_SPECIES_GRINGO_CLEAR_ALL()l
extern _native void ANIMAL_SPECIES_GRINGO_LOAD_ALL()l
extern _native void ANIMAL_SPECIES_REL_CLEAR_ALL()l
extern _native void ANIMAL_SPECIES_REL_SET_ATTACK_GRAB_ENABLED(int pram0, int pram1, int pram2)l
extern _native void ANIMAL_SPECIES_REL_SET_PREDATOR_AND_PREY(int pram0, int pram1)l
extern _native void ANIMAL_SPECIES_REL_SET_THREAT(int pram0, int pram1, int pram2)l
extern _native void ANIMAL_SPECIES_REL_SET_AVOID(int pram0, int pram1, int pram2)l
extern _native void ANIMAL_SPECIES_REL_SET_PLAY_HUNT(int pram0, int pram1, int pram2)l
extern _native void ANIMAL_SPECIES_REL_SET_PLAY_CHASE(int pram0, int pram1, int pram2)l
extern _native void ANIMAL_SPECIES_REL_SET_PLAY_BEG(int pram0, int pram1, int pram2)l
extern _native void ANIMAL_SPECIES_REL_SET_PLAY_GROWL(int pram0, int pram1, int pram2)l
extern _native void ANIMAL_SPECIES_REL_SET_PLAY_SNIFF(int pram0, int pram1, int pram2)l
extern _native int ANIMAL_SPECIES_REL_GET_CAN_ATTACK(int pram0, int pram1)l
extern _native void ANIMAL_SPECIES_REL_SET_CAN_ATTACK(int pram0, int pram1, int pram2)l
extern _native void ANIMAL_SPECIES_REL_SET_CAN_WARN(int pram0, int pram1, int pram2)l
extern _native void ANIMAL_SPECIES_REL_SET_EAT_GRINGO(int pram0, int pram1, int pram2)l
extern _native int ANIMAL_ACTOR_GET_DOMESTICATION(int pram0)l
extern _native void ANIMAL_ACTOR_SET_DOMESTICATION(Actor actor, bool domestication)l
extern _native int ANIMAL_ACTOR_GET_SPECIES(int pram0)l
extern _native void ANIMAL_TUNING_SET_ATTRIB_BOOL(int pram0, int pram1, int pram2)l
extern _native void ANIMAL_TUNING_SET_ATTRIB_FLOAT(int pram0, int pram1, int pram2)l
extern _native void ANIMAL_ACTOR_SET_DOCILE(Actor Actor, bool Docile)l
extern _native bool ANIMAL_ACTOR_GET_DOCILE(int p0, int p1, int p2, int p3, int p4)l
extern _native int ANIMAL_ACTOR_GET_GRABBED_BY(int p0, int p1)l
//////////////////////////////////
//Animation
/////////////////////////////////
extern _native int GET_ACTOR_ANIM_CURRENT_TIME(int pram0, int pram1)l
extern _native int SET_ACTOR_ANIM_CURRENT_TIME(int pram0, int pram1)l
extern _native bool IS_ACTOR_ANIM_PLAYING(int pram0, int pram1)l
extern _native bool ACTOR_HAS_ANIM_LOADED(int p0, int p1)l
extern _native int ACTOR_HAS_ANIM_SET(int pram0, int pram1)l
extern _native32(0x3E30A514) void _SET_ANIMATION_RATE_OVERRIDE_SCALE(Actor actor, float scale)l
extern _native int SET_PANIM_PARAMS(int pram0, int pram1, int pram2)l
extern _native int SET_PANIM_PHASE(int pram0, int pram1)l
extern _native void SET_ACTOR_ANIM_PHASE_LOCK(int pram0, int pram1)l
extern _native void RELEASE_ACTOR_ANIM_PHASE_LOCK(int pram0)l
extern _native bool IS_ACTOR_ANIM_PHASE_LOCKED(Actor actor)l
extern _native void SET_ACTOR_CUTSCENE_MODE(Actor actor, bool enable)l
extern _native void REQUEST_ANIM_SET(const char* assetName, int unk)l
extern _native bool HAS_ANIM_SET_LOADED(const char* assetName)l
extern _native void REMOVE_ANIM_SET(int pram0)l
extern _native int SET_ANIM_SET_FOR_ACTOR(Actor actor, const char* assetName, int unk)l
extern _native void RESET_ANIM_SET_FOR_ACTOR(Actor actor, bool reset)l
extern _native32(0xB1B643E0) void _REPLACE_EXISTING_ANIM_SET(int pram0)l
extern _native int REQUEST_ACTION_TREE(const char* assetName)l
extern _native bool HAS_ACTION_TREE_LOADED(const char* assetName)l
extern _native void REMOVE_ACTION_TREE(int pram0)l
extern _native int SET_ACTION_NODE_FOR_ACTOR(int pram0, int pram1)l
extern _native int SET_REACT_NODE_FOR_ACTOR(int pram0, int pram1)l
extern _native void RESET_REACT_NODE_FOR_ACTOR(int pram0)l
extern _native32(0x07EC142B) void _RESET_ACTION_TREE_FOR_ACTOR(int pram0)l
extern _native int SET_LINKED_ANIM_TARGET(int pram0, int pram1)l
extern _native int GET_LINKED_ANIM_TARGET(int pram0)l
extern _native int CLEAR_LINKED_ANIM_TARGET(int pram0)l
extern _native bool IS_ACTOR_PERFORMING_LINKED_ANIMATION(Actor actor)l
extern _native bool IS_ACTION_NODE_PLAYING(int pram0, int pram1)l
extern _native int IS_ACTION_NODE_PLAYING_PARTIAL(int pram0, int pram1)l
extern _native int IS_ACTOR_PLAYING_NODE_IN_TREE(int pram0, int pram1)l
extern _native float GET_CURR_ACTION_NODE_PLAY_TIME(int p0)l
extern _native int TOUGH_ARMOUR_GET_TUNING_REGENERATION_RATE(int pram0)l
extern _native void TOUGH_ARMOUR_SET_TUNING_HIT_DEDUCTION(int pram0, int pram1, int pram2)l
extern _native void TOUGH_ARMOUR_SET_TUNING_PAD_ARMOUR(int pram0, int pram1)l
extern _native void TOUGH_ARMOUR_SET_TUNING_REGENERATION_RATE(int pram0, int pram1)l
extern _native32(0xBEF6031B) void _SET_ACTOR_CHARACTER_CLOTHING_SCALED_PINNING(int pram0, int pram1)l
extern _native void SET_ACTOR_TO_SEAT(Actor actor, int seat)l
//////////////////////////////////
//Minigame
/////////////////////////////////
extern _native void START_MINIGAME(int pram0)l
extern _native void PUSH_MINIGAME_INPUT(int pram0, int pram1)l
extern _native bool IS_MINIGAME_RUNNING()l
extern _native void END_CURRENT_MINIGAME()l
extern _native int UNK_0x6AAD0420(int pram0, int pram1, int pram2, int pram3)l
extern _native int SET_CURRENT_MINIGAME_INT(const char* minigame, int value)l//0x627DDEC
extern _native32(0x2DC768BB) int _SET_CURRENT_MINIGAME_SCRIPT_OVERRIDE(const char* p0)l
extern _native32(0x8275FDD4) void _SET_CURRENT_MINIGAME_WIN_STATE(int pram0)l
//////////////////////////////////
//Unknown But Used
/////////////////////////////////
extern _native int UNK_0x655D350B(int pram0, int pram1, int pram2, int pram3)l
////////////////////////////////////////////////////////////////////
//Unknown Used In Test Scripts [Probably Removed From Executables]
///////////////////////////////////////////////////////////////////
extern _native void UNK_0x868E29C1(int pram0, int pram1)l
extern _native void UNK_0x02DB5C93(int pram0, int pram1, int pram2)l
extern _native void UNK_0x8DD4BC60(int pram0)l
extern _native void UNK_0xD5501B1B(int pram0, int pram1)l
extern _native void UNK_0x1CB7C07D(int pram0)l
extern _native void UNK_0x4C3F3C71(const char* unk)l
extern _native void UNK_0xAF7D851C()l
extern _native void UNK_0x18D7E687(int pram0, int pram1, int pram2, int pram3)l
extern _native void UNK_0xC3BE5695()l
extern _native void UNK_0xF38E8BBE()l
extern _native void UNK_0xBD829B6B()l
extern _native void UNK_0x7306CC72(int pram0)l
extern _native void UNK_0x9631DFD0(int pram0, int pram1, int pram2)l
extern _native void UNK_0x3BED7D9F()l
extern _native void UNK_0x77C8F279(int pram0)l
extern _native void UNK_0x868E29C1(int pram0, int pram1)l
extern _native void UNK_0xCEED74A5()l

//Unknown natives but listed in other native list
//STREAMING_SET_CUSTCENE_MODE
//NET_SESSION_GAMER_COUNT
//SET_GRINGO_STRUCT_ATTR

#undef _native
#undef _native32
#undef l