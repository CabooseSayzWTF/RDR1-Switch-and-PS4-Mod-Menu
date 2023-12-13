#include "menuUtils.h"
#define self GET_PLAYER_ACTOR(0)
#define CurrentMount GET_ACTOR_ENUM(GET_MOUNT(self))

//some of this is unused, will clean up bools, ints, etc later.
//code is a hot mess, have fun looking at it ;)
bool AnimalBypassON, NoClip2, aimbott2, lodmod, God, HrsStam, ExplosiveRounds, DeleteGun, BurnGun, MedusaKill, MedusaDestroy, MedusaXplode, MedusaBurn, AntiRagDoll, IgnoreON, IrishDrunk, DeadEye1Hit, NoclipON, DeadEyeInf1, isSaved = false, StandStillFucker = false, PedzFollow, CopyGun, nReload, Timez, FlameON, CarSpeedBoost;
int CombatModeSave = 0, TargetMode = 0, modelgotloaded, SpawnPed[10], SpawnMount1, SpawnDra[4];
vector3 savedPos, pedztp, animaltp, ve15, ve16, ve17, ve18, ve19, ve20, ve23, ve24, ve25, ve40, ve41, waypointpos1, positionWP;
eActor SpawnCar1;
bool ToggleSpoof13;
bool NoWanted;
bool UnlimitedAmmo;
bool GoldIt;
bool BGPAI2;
bool cular;
bool pausew;
int tghat = 0, lawID, bountedit, pedtask;
bool AiControl, PedCrip, PedZomb;
bool TODLoop;
bool TODLoop2;
bool AutoDead;
bool aimbott;
bool Phos;
int undercolor = 0;
int testwtf, outfitsave;
int testwtf2;
int deafx;
int deafx2;
int war1, war2, war3, war4, war5, war6, war7, war8, war9, war10, war11, war12, war13, war14, war15, war16, war17, war18;
int pedint2 = 0;
int cusvideo = 1;
int cusvideo2 = 0;
int weathint2;
int animID;
int Animint = 0;
int uVar5;//gringo object
static Camera camera;
static float camX = 0.0, camY = 0.0;
static float xStickLeft, yStickLeft, xStickRight, yStickRight;
static vector3 camDirection, positionFC;
static vector3 SavedPosIntLoader;
int tban = 0;
int statset = 0;
bool BGuard;
bool SavedMountON;
int BGuardTarget = 16, DefautSavedModel, SavedMount, Cscript = 1, cs[11], QModel = 0;
int selectorz = 0;
int zombi = 0;
int workz = 0;
int gangz = 0;
int lawz = 0;
int prostz = 0;
int animalzz = 0;
int miscz = 0;
int interiorint = 0;

int troph = 1, consume = 79, proved = 146;//provisions is starting at 148 for give all safe items as first display option, consumables editor is starting at 79 for give all safe items as first display
bool Fireround;
bool Slugz;
bool SuperJump;
int jtest1;
bool ClearDE;
bool BlueDE;
bool RedDE;
int DEColorSwap;
int DETog = 0;
int DELvl = 0;
int DETime = 0;
bool AntiRagDoll2;
bool tpwp;
static int songIndex = 0;
Iterator animalridez1, animalridez2, animalridez3;
char* QuickM[] = { "Nun01", "Bonnie", "Toxic Zombie", "Young Jack", "NakedGuy", "NakedGirl", "Paperboy", "MirandaFortuna", "DeadDutch", "MysteryGuy", "HerbertMoon" };
char* NAChar[] = { "Armadillo", "MacFarlanes Ranch", "Tumbleweed", "Fort Mercer", "Gaptooth Breach", "Twin Rocks", "Plainview", "Rathskeller Fork", "Ridgewood Farm", "Thieves' Landing", "Benedict Point", "Lake Don Julio", "Coot's Chapel", "Pike's Basin" };
char* WEChar[] = { "Blackwater","Cochinay", "Beechers Hope", "Manzanita Post", "Pacific Union RR", "Aurora Basin", "Serendipitys Wreck" };
char* MTChar[] = { "Escalera", "Chuparosa", "Las Hermanas", "Tesoro Azul", "El Presidio", "Casa Madrugada", "Nosalida", "El Matadero", "Agave Viejo", "Torquemada", "Rancho Polvo", "Manteca Falls", "Campo Mirada" };
char* HIChar[] = { "Macfarlane House", "Armadillo Theatre", "Armadillo Saloon Room 1", "Armadillo Saloon Room 2", "Thieves' Landing Mystery", "Blackwater Jail", "Blackwater Butcher", "Blackwater Theatre", "Blackwater Hotel Room", "Blackwater Anthropology", "Blackwater Restaurant", "Blackwater Bank", "Blackwater Poker Room", "Blackwater Barn", "Marston House", "Escalera Room 1", "Escalera Room 2", "Escalera Room 3", "Escalera Villa Room", "Hermanas Church 1", "Hermanas Church 2", "Chuparosa Marstons Room", "Chuparosa Bank Vault" };
char* OoMChar[] = { "Outfitter", "Snowy Mountain", "Wasteland1", "Wasteland2", "Wasteland3", "MexicoValley" };
char* WTChar[] = { "Clear", "Fair", "Cloudy", "Rainy", "Stormy", "Snowy", "Cave", "Thieves", "Forest", "Location A", "Location B", "Location C", "Interior Clear", "Interior Fair", "Interior Cloudy", "Interior Rainy", "Interior Stormy", "Interior Snowy", "Interior Thieves", "Interior Forest", "Interior Location A", "Interior Location B", "Interior Location C" };
char* MSChar[] = { "Dead Horse", "Zebra Donkey", "Undead War Horse", "Undead Death Horse", "Undead Famine Horse", "Undead Pestilence Horse", "Undead Unicorn", "Undead Horse01", "Undead Horse02", "Undead Horse03", "Undead Horse04", "Stallion", "Regular Horse", "Cleveland Bay", "Painted Quarter Horse", "Kentucky Saddler", "American Standardbred", "Standardbred Pinto", "Painted Standardbred", "Hungarian Halfbred", "Highland Chestnut", "Quarter Horse", "Welsh Mountain", "Dutch Warmblood", "Turkmen", "Tobiano Pinto", "Lusitano", "Ardennais", "Tersk", "War Horse", "Dark Horse", "Lusitano Nag", "Infested Ardennais", "Jaded Tersk", "El Senor", "El Hedor", "El Picor", "Buffalo", "Albino Buffalo", "Bull", "Bessy", "Ferdinand", "Bonzo Bull", "Super Bull", "Brown Cow", "Cow1", "Cow2", "Cow3" };
char* MAChar[] = { "Remove All Accessories", "Black Saddle", "Brown Saddle", "Harness", "Black Rein", "Brown Rein", "Undead Unicorn FX", "Undead Death FX", "Undead Famine FX", "Undead Pestilence FX", "Undead War Red FX", "Undead War Blue FX" };
char* VSChar[] = { "Stagecoach1", "Stagecoach2", "Stagecoach3", "Stagecoach4", "DLCVeh", "GatWagon", "Cart1", "Cart2", "Cart3", "Cart4", "Cart5", "Cart6", "Canoe", "Raft2", "Raft3", "Raft1", "Truck", "Car", "Wagon4", "Wagon5", "PrisonWagon", "DickensElixir1", "Wagon2", "Chuckwagon1", "Chuckwagon2", "DickensElixir2" };
char* LectChar[] = { "Zombies", "Workers", "Gang", "Law", "Prostitues", "Animals", "Misc" };
char* ZombChar[] = { "Toxic", "Brusier", "Fast", "DeadMale2", "DeadMale3", "DeadMale5", "DeadMale6", "Default Zombie" };
char* WorkChar[] = { "BankTeller", "Bartender", "Blacksmith", "Businessman", "DocksWorker", "Nurse", "Musician", "FactoryWorker" };
char* GangChar[] = { "IndianRaider", "CattleRustler", "DrunkNDirty", "Bandito", "CrazyMiner", "MexRebel", "Luisa" };
char* LawChar[] = { "TownPosse1", "TownPosse3", "SheriffTux", "USMarshall2", "USMarshall5", "PuebloPosse", "CorruptOfficial", "Police1" };
char* ProstChar[] = { "Pros2", "Pros5", "Pros11", "MexPros", "BlackPros", "CaucasionPros", "AsianPros" };
char* AniChar[] = { "Bear", "Husky Dog", "Elk", "Giant Bat", "Zombie Cougar", "Wolf", "Buck", "Snake" };
char* MiscChar[] = { "NakedGuy", "HerbertMoon", "MysteryMan", "YoungJack", "Preacher", "Nun", "DeadDutch" };
char* PPPChar[] = { "FX_Deadeye.ppp", "UI_Pause.ppp", "MP_ShowdownBlueTeam.ppp" };
char* AnimChar[] = { "alerted_rifle_right", "angrymob", "angrymob_torch", "anthro01_struggle", "any_craftBasket", "arm_wrestling", "bandito_beatup", "banker_hostage", "Bar_lean_stand", "bar_stand", "begging", "bench_chair", "bench_stool", "binoc_pickup", "blacksmith", "Blacksmith_chopwood", "blow_the_hatch", "body_left_for_dead_loop", "book_shelf", "browse_table_low",  "campfire_talk", "CampfireTreasureHunter", "Cannibal_fam_clue_search", "car_wash", "chair_pot_smash", "chair_sit", "chair_sit_newspaper", "chair_sit_sleep_attach", "chair_sit_table_read", "cheer_on_seat", "chop_chicken", "chop_fish", "clean_rifle", "cooking", "cower", "crazy_poking", "crying_linked", "cs_fbi04_taunt01", "cs_tumbleweed_getup", "digging", "dog_fetch", "door_kick_all_weapon", "door_kick_rifle", "door_locked", "drink_from_barrel", "drinking", "drunk_react", "duck_hunt", "dynamite_AI_controlled", "dynamite_table", "factory_foreman", "factory_lathe", "factory_lumber_stacker", "factory_shovel_coal", "fake_blackjack_dealer", "fake_FiveFingerFillet", "fbi02_cs03_b", "fbi04_wounded_01", "fbi04_wounded_02", "fbi04_wounded_03", "feed_chickens", "fema_stir_cauldron", "firesquad_heldback", "firesquad_shove", "fix_car", "flirting_whore", "Flower_search", "free_bonnie", "frustrated_racer", "furnace", "get_drunk", "Giveaway_Footlocker", "grave01_door_open", "Grave03_Seth_idle", "grave_robber_attack", "grind_corn", "gun01_drunk", "hammering", "Herbalist_sitting", "hold_door_closed", "hostage_kneel", "hostage_shaky", "hostage_sit_loop", "Indian_Sit_Ground", "Indian_Sit_Ground_Smoke", "Intro01_v", "item_bait", "item_bottle", "jake_read", "kick_door", "kick_hogtied_victim", "kneel_hammer", "knl_hoe_soil", "knl_watertrough", "landon_smoking", "lean_fence_back", "lean_fence_H_talking", "lean_fence_L", "lean_rail", "lean_rail_drink", "lean_rail_whore", "lean_table", "lie_sleep_on_bed", "lie_sleep_on_bed_l", "lie_sleep_on_bed_r", "light_candle", "light_candle_multi", "locked_door", "locked_gate", "look_around_corner", "look_distance_binocs", "look_out_window_L", "look_out_window_R", "Loot_Corpse", "loot_corpse_solo_female", "loot_corpse_solo_male", "loot_solo_loop", "luisamomloop", "man_behind_bars", "man_in_prison", "Marshal04_deathpose1", "Marshal04_deathpose2", "Marshal04_deathpose3", "Marshal04_deathpose4", "Marshal04_deathpose5", "Marshal04_deathpose6", "Marshal04_farmer_deathpose", "Marshal04_femfarmer_deathpose", "Marshal04_laborer_deathpose", "Marshal04_wife_deathpose", "merchant02_idle", "merchant_lay_bed", "mex_blacksmith", "mex_cartVendor", "mex_craftBasket", "mex_cry_overBody", "mex_dusting_maid", "mex_eat_apple", "mex_flirt_sit_link", "mex_flirt_sit_stool_attached_link","mex_leanwall", "mex_peerOut_window", "mex_pickGarbage", "mex_playGuitar", "mex_prayer_oldWoman", "mex_sitGround", "mex_sitGround_link_loop", "mex_sleepBed_l", "mex_sleepBed_r", "mex_stool_sit", "mex_table_service", "mex_tableService_bartender", "mex_talking_soldiers_link", "mex_towerGuard", "mex_washCloths", "mexs_doorknock", "milk_cow", "mourn_dead_body", "Mourn_loop", "mourn_suicide", "MP_ignite_bomb", "mp_rig_tnt","multistage_hoe", "multistage_lumber", "multistage_sweeping", "multistage_torch", "musician_wife_idle", "nastas_sack", "NPC_BuryDynamite", "NPC_Lockpicking_Door", "npc_open_safe", "oldf_pray", "open_big_door", "open_crate_ambient", "open_credenza", "open_vault_door", "opium_pipe", "organize_shelf", "organize_wagon", "outhouse", "pan_gold", "panic_female", "Pee", "pistol_whip", "pitch_hay", "player_detonator", "Player_DropDynamite", "player_pickup_hat", "player_sit_movie", "player_sleep_gun_left", "player_sleep_gun_right", "player_sleep_tent", "player_smoking_lean", "pole_hostage", "preaching", "preaching_at_podium", "Prostitute_bed", "ranch04_reflect", "ranch08_close1", "ranch08_close2", "Rand_Idle_NearWall_nospawn", "Rand_Idle_NearWall_Shoulder_L", "Rand_Idle_NearWall_Shoulder_R", "Rand_Idle_Sit_Ground_Bad", "rand_idle_stand", "rand_idle_stand_nospawn", "RCM23_kneel_idle", "RCM_01_CS01_JebIdle", "RCM_02_CS01_Books", "RCM_03_CS02_Water_sweeping", "RCM_04_CS03_Musician", "RCM_05_CS03_CryingIdle", "RCM_05_CS04_CannibalIdle", "RCM_05_CS05_cannibal_link", "RCM_11_CS03_preacher", "RCM_12_CS02_PotStir", "RCM_12_CS03_fix_wing", "RCM_13_CS01_Jenny", "RCM_14_CS01_Lean_letter", "RCM_14_CS02_sleepChair", "RCM_15_CS04_NunIdle", "RCM_15_CS05_MysteryMan", "RCM_16_CS02_NunIdle", "RCM_17_CS01_Mackenna", "RCM_17_CS02_Spatchcock", "RCM_17_CS03_Mackenna", "RCM_20_CS01_clara_pray", "RCM_20_CS02_richman_bar", "RCM_20_CS03_clara_pray", "RCM_23_CS01_Basilio", "RCM_32_CS01_Agent", "RCM_Abandoned", "RCM_AztecGold_Treasure", "RCM_horse_love_A", "RCM_Horse_Love_B", "reb03_detach_train", "reb05_struggle2", "rebel02_cs02_v", "rebel_cheer_pistol", "rebel_cheer_rifle", "rebel_riot01", "rebel_riot02", "rebel_riot03", "reload_slow", "reyes_frees_marston", "reyes_saves", "ricketts_tnt_crates", "ring_bell", "riverwash", "rockclimbing", "saved_by_reyes", "searching", "searching_box", "shaky_chair", "shaky_cover", "shaky_idle", "sharpen_axe", "shopkeep", "shopkeep_bartender", "shopkeeper_return", "shotgun_boss", "sit_barrel", "Sit_BlackJack", "sit_camp_coffee_drink", "sit_chair_comfy", "sit_chair_couch", "sit_chr_dsk_letr", "sit_chr_dsk_wrk", "sit_church", "sit_cleanknife", "sit_cleanpistol", "sit_cleanrifle", "sit_cut_meat", "sit_docks", "sit_drinkbrandy_s_any", "sit_eat_dinner", "sit_embroidery_e_any", "sit_fence_low", "sit_fence_nospawn", "sit_flirt_couch_link", "Sit_Ground_Campfire_Tend", "Sit_Ground_Drink", "Sit_Ground_Only", "Sit_Ground_Play_Cards", "sit_ground_play_guitar", "sit_ground_play_harmonica", "sit_ground_smoke", "Sit_Ground_Smoke_Pipe", "sit_headinhands_n_any", "sit_key_twirling", "sit_no_table", "sit_piano_w_piano", "sit_picknose_e_any", "sit_sleepinchair_n_any", "sit_sleeponbench_n_any", "sit_smokepipe_e_any", "sit_yawning_n_any", "skin_scraper", "sleeping", "sleeping_chair_scripted", "sleeping_wall_scripted", "smoker_idle", "smoking_lean", "smoking_stand", "soldier_banging_on_door", "son_crouchGetup", "SpatchCock_idle", "spittoon", "spyGlass", "stand_adjuststocking_w_whore", "stand_announce", "stand_armoir", "stand_bar_drink", "stand_bar_need_drink", "stand_bartender_bar_work", "stand_bartender_pour", "stand_check_clipboard", "stand_cheer", "stand_chop_door", "stand_chopveggies_w_any", "stand_cleanwindow_w_any", "stand_cupboard", "stand_dnd_rowdydrink", "stand_drunk_dancing_link", "stand_drunkdancing_e_any", "stand_eat_fruit", "stand_fiddle_w_fiddle", "stand_guntricks_e_any", "stand_hammer_table", "stand_hammer_wall", "stand_hammerground_w_any", "stand_holy_water", "stand_key_twirling", "stand_kneelvomit_n_any", "stand_knock_on_door", "stand_lookdistance_w_any", "stand_makebed_w_any", "stand_minerock_w_any", "stand_open_chest", "stand_paint", "stand_peeing_b_any", "stand_pocketwatch_e_any", "stand_read", "stand_reprimand", "stand_sellPaper", "stand_shove", "stand_smokelean_e_any", "stand_spit", "stand_stirringpot_w_any", "stand_sweeping_w_any", "stand_taunt_far", "stand_taunt_near", "stand_telegraph", "stand_torch", "stand_washfacebowl_n_any", "stand_waterpump", "stand_whore_dancing", "stand_worried_n_any", "stand_wring_hands", "stand_yelling", "stand_yelling_down", "stand_yelling_mid", "stand_yelling_up", "stool_sit_newspaper", "TES_CoverIntro_Player", "TES_CoverIntro_Sheriff", "thanks", "ticket_taker_link", "train_boarding", "train_climb_left", "train_climb_right", "train_engineer", "twin_rocks_dad", "undertaker_measure", "US_talking_soldiers_link", "wait_at_door", "wall_phone", "wash_basin", "watch_idle", "wave_flag", "weeping", "whittle_wood", "whore_flirt", "wilderness_drunk_A", "wilderness_drunk_B", "window_shopping" };
char* Provisions[] = { "sn_z_t", "sn_z_e", "sn_z_to", "sn_z_r", "sn_z_ea", "sn_zb_t", "sn_zb_e", "sn_zb_c", "sn_zb_h", "sn_zc_t", "sn_zc_e", "sn_zc_c", "sn_zc_h", "sn_zy_t", "sn_zy_e", "sn_zy_c", "sn_zy_h", "sn_zw_t", "sn_zw_e", "sn_zw_c", "sn_zw_h", "sn_zh_e", "sn_zh_h", "sn_zchT", "sn_zchE", "sn_zchC", "sn_zchH", "sn_zsqT", "sn_zsqE", "sn_zsqH", "sn_zunH", "sn_zunR", "sn_zbat", "sn_zd_t", "sn_zd_e", "sn_zbuH", "sn_zbuE", "sn_zboT", "sn_zboE", "sn_h_bw", "sn_h_ds", "sn_h_gc", "sn_h_hs", "sn_h_pp", "sn_h_po", "sn_h_rs", "sn_h_vs", "sn_h_wf", "sn_h_wo", "sn_a1_m", "sn_a1_c", "sn_b1_w", "sn_b2_m", "sn_b2_c", "sn_b2_f", "sn_b2_t", "sn_b3_m", "sn_b3_f", "sn_b4_m", "sn_t_9", "sn_t_8", "sn_t_7", "sn_t_6", "sn_t_5", "sn_t_4", "sn_t_3", "sn_t_2", "sn_t_1", "sn_h2_s", "sn_h2_m", "sn_m1_h", "sn_m1_m", "sn_c5_m", "sn_d3_f", "sn_d3_m", "sn_c5_h", "sn_g3_f", "sn_w1_h", "sn_w1_p", "sn_w1_m", "sn_v_f", "sn_sb_f", "sn_s3_s", "sn_s2_f", "sn_s2_m", "sn_s1_s", "sn_s1_m", "sn_r2_f", "sn_r2_m", "sn_r1_m", "sn_p1_m", "sn_o1_f", "sn_nb_h", "sn_nb_s", "sn_nb_t", "sn_nb_m", "sn_xc_h", "sn_xc_f", "sn_xc_p", "sn_xc_m", "sn_xb_f", "sn_xb_h", "sn_xb_c", "sn_xb_t", "sn_xb_m", "sn_xw_f", "sn_xw_h", "sn_xw_m", "sn_h1_f", "sn_g2_h", "sn_g2_f", "sn_g2_t", "sn_g2_c", "sn_g2_m", "sn_g1_m", "sn_f1_f", "sn_f1_m", "sn_e2_s", "sn_e2_a", "sn_e2_m", "sn_e1_f", "sn_d2_f", "sn_d1_s", "sn_d1_m", "sn_c4_f", "sn_c3_p", "sn_c3_m", "sn_c2_p", "sn_c2_f", "sn_c2_c", "sn_c2_m", "sn_c1_f", "sn_b8_s", "sn_b8_h", "sn_b8_m", "sn_b7_s", "sn_b7_a", "sn_b7_m", "sn_b6_f", "sn_b6_c", "sn_b6_m", "sn_b5_t", "sn_b5_s", "sn_b5_m", "sn_b4_s", "sn_b4_h" };
char* Plsong[] = { "home01_stereo_song", "ross_endcredits_stereo_song", "endcredits_stereo_song", "fort02_stereo_song", "ftr_beat_complete_song_01", "ftr_beat_fail_song_01", "ftr_bounty_hunter_complete_song_01", "ftr_bounty_hunter_fail_song_01", "ftr_job_complete_song_01", "ftr_job_fail_song_01", "ftr_mission_complete_song_01", "ftr_mission_fail_song_01", "ftr_outfit_complete_song_01", "ftr_purchase_property_song_01", "ftr_rcm_complete_song_01", "ftr_rcm_fail_song_01", "ftr_song_01", "ftr_song_02", "ftr_song_03", "ftr_song_04", "ftr_song_05", "ftr_song_06", "ftr_song_07", "ftr_song_08", "ftr_song_09", "mex_song_01", "nrt_beat_complete_song_01", "nrt_song_01", "nrt_song_02", "nrt_song_03", "nrt_song_04", "nrt_song_05", "nrt_song_06" };

unsafe void OutfitUnlock(int outfitID)
{
	__push(255);
	__getFrame(0);
	__getGlobalP(42265);
	__getArrayP(9);
	__setImm(2);
}
void UnlockMostOutfits()
{
	for (int i = 0; i <= 30; i++)
	{
		OutfitUnlock(i);
		//Unlocks all outfits except US Army, US Marshal, and  Bureau outfits
		// Prob a diff global for those 3 outifts but unsure
	}
}
void CancelScr(int ScriptID)
{
	if (IS_SCRIPT_VALID(cs[ScriptID]))
	{
		REMOVE_PERSISTENT_SCRIPT(cs[ScriptID]);
		TERMINATE_SCRIPT(cs[ScriptID]);
	}
}
void TeleportActor2(Actor actor, vector3 position)
{
	float heading = GET_HEADING(actor);
	if (IS_ACTOR_RIDING(actor))
		TELEPORT_ACTOR(GET_MOUNT(actor), &position, 1, 1, 1);
	else if (IS_ACTOR_DRIVING_VEHICLE(actor))
		TELEPORT_ACTOR(GET_VEHICLE(actor), &position, 1, 1, 1);
	else
		TELEPORT_ACTOR_WITH_HEADING(actor, position, heading, 1, 1, 1);
}
void FuncCleanUp()
{
	submenu = Closed;
	submenuLevel = 0;
	currentOption = 0;
	MenuOpen = false;
	menuoutsound = 0;
	SET_PLAYER_CONTROL(0, true, false, false);
	if (DECOR_CHECK_EXIST(self, "DISABLE_HORSE_WHISTLE"))
	{
		DECOR_REMOVE(self, "DISABLE_HORSE_WHISTLE");
	}
}

unsafe void SetStatArrayValue(int globalIndex, int statValue)
{
	__getFrame(1);
	__callNative(0x67116627, 1, 1);
	__getFrame(0);
	__getGlobalP(54086);
	__setArray(1);
}
void SetStats(int min, int max)
{
	for (int i = 0; i <= 695; i++)
	{
		if (i != 5 && i != 170)
		{
			SetStatArrayValue(i, RAND_INT_RANGE(min, max));
		}
	}
}

void NOCLIPMESS()
{
	NoclipON = true;
	FuncCleanUp();
	HUD_CLEAR_HELP_QUEUE();
	print2("<dpadup>Forward Facing Direction <rb>Up, <ls>Down, <y>Off", 15000);
}

int CreateActor(eActor id)
{
	bool isLoaded = false;
	STREAMING_REQUEST_ACTOR(id, true, false);
	for (int i = 0; i < 5; i++)
	{
		if (STREAMING_IS_ACTOR_LOADED(id, 1)) {
			isLoaded = true;
			break;
		}
		WAIT(500);
	}
	if (!isLoaded)
		return 0;

	GET_POSITION(GET_PLAYER_ACTOR(0), &ve24);
	int peda = CREATE_ACTOR_IN_LAYOUT(FIND_NAMED_LAYOUT("PlayerLayout"), "", id, ve24, ve25);
	return peda;
}

bool RequestGringo(const char* animName)
{
	bool isLoaded = false;
	int iVar0;
	iVar0 = 0;
	char animit[256];
	strcpy(animit, "$/content/scripting/gringo/simplegringo/", 255);
	stradd(animit, animName, 255);
	REQUEST_ASSET(animit, 1);
	animID = GET_ASSET_ID(animit, 1);
	for (int i = 0; i < 5; i++)
	{
		REQUEST_ASSET(animit, 1);
		animID = GET_ASSET_ID(animit, 1);
		if (STREAMING_IS_GRINGO_LOADED(animID)) {
			isLoaded = true;
		}
		WAIT(500);
	}
	return isLoaded;
}

void SetTargetMode()
{
	if (TargetMode == 0)
	{
		//CombatModeSave = GET_PLAYER_COMBATMODE();//no real reason to save it
		SET_PLAYER_COMBATMODE(0);
		print2("<red>Target Mode</red>: Normal", 4000);
		TargetMode = 1;
	}
	else if (TargetMode == 1)
	{
		SET_PLAYER_COMBATMODE(2);
		print2("<red>Target Mode</red>: Casual", 4000);
		TargetMode = 2;
	}
	else if (TargetMode == 2)
	{
		SET_PLAYER_COMBATMODE(1);
		print2("<red>Target Mode</red>: Expert", 4000);
		TargetMode = 0;
	}
}

void PlayerUseGringo(const char* animName)
{
	//animation orientation is buggy need to find a better way to do it....
	// switch is very picky about vector3 data for some stupid reason...
	vector3 vVar1, vVar2, vVar3, vVar4;
	char* cVar6;
	char animit[256];
	strcpy(animit, "$/content/scripting/gringo/simplegringo/", 255);
	stradd(animit, animName, 255);
	AI_QUICK_EXIT_GRINGO(self, 1);
	DESTROY_OBJECT(uVar5);
	TASK_CLEAR(self);
	ACTOR_RESET_ANIMS(self, 1);
	STREAMING_EVICT_GRINGO(animID);
	ENABLE_MOVER(self);
	//SET_MOVER_FROZEN(self, 0);
	if (!RequestGringo(animName))
	{
		print2("Error", 2000);
		return;
	}
	GET_POSITION(self, &vVar1);
	//GET_OBJECT_ORIENTATION(GET_OBJECT_FROM_ACTOR(self), &vVar3);
	float fakehead9 = GET_OBJECT_HEADING(GET_GAME_CAMERA());
	vVar2.x = vVar1.x;
	vVar2.y = vVar1.y;
	vVar2.z = vVar1.z;
	//vVar4.x = vVar3.x;
	//vVar4.y = vVar3.y;
	//vVar4.z = vVar3.z;
	vVar4.x = 0.0f;
	vVar4.y = fakehead9;
	vVar4.z = 0.0f;
	uVar5 = CREATE_GRINGO_IN_LAYOUT(FIND_NAMED_LAYOUT("PlayerLayout"), animName, animit, vVar2, vVar4);
	//Hack to force animation to play in the direction we are looking when executing the animation
	//Object gringoobj = GET_OBJECT_FROM_GRINGO(uVar5);
	//SET_OBJECT_ORIENTATION(gringoobj, 0.0f, vVar4.y, 0.0f);
	cVar6 = GET_GRINGO_FROM_OBJECT(uVar5);
	DECOR_SET_BOOL(self, "NoGringoCamera", 1);
	DECOR_SET_BOOL(self, "GringoNoQuit", 1);
	//float heading = GET_HEADING(self);
	TASK_CLEAR(self);
	TASK_USE_GRINGO(self, cVar6, "UseCase1", 1, 1);
}

int RunScript(const char* scriptName)
{
	char scriptDir[256];
	strcpy(scriptDir, "$/content/", 255);
	stradd(scriptDir, scriptName, 255);

	if (!DOES_SCRIPT_EXIST(scriptDir)) 
	{
		print2("<red>Error", 4000);
		return 0;
	}

	REQUEST_ASSET(scriptDir, 4);
	int id = GET_ASSET_ID(scriptDir, 4);

	while (!STREAMING_IS_SCRIPT_LOADED(id)) 
	{
		STREAMING_REQUEST_SCRIPT(id);
		print2("<orange>Loading", 4000);
		WAIT(0);
	}

	int script = LAUNCH_NEW_SCRIPT(scriptDir, 0);
	ADD_PERSISTENT_SCRIPT(script);

	print2("<green>Launched", 4000);
	return script;
}

void GiveActorAllWeapons()
{
	for (int i = 0; i <= 37; i++)
	{
		if (i != 30)
		{
			if (_IS_WEAPON_ENUM_LOCKED(i))//unlock weapons that are locked
			{
				_SET_WEAPON_ENUM_LOCKED(i, 0);
			}
			SET_EQUIP_SLOT_ENABLED(self, i, 1);
			GIVE_WEAPON_TO_ACTOR(self, i, 0, 0, 0);
			_ADD_AMMO_OF_TYPE(self, GET_AMMO_ENUM(i), TO_FLOAT(100), 1, 0);
		}
	}
}
bool RequestActor(eActor ID)
{
	bool isLoaded = false;
	STREAMING_REQUEST_ACTOR(ID, true, false);
	for (int i = 0; i < 5; i++)
	{
		if (STREAMING_IS_ACTOR_LOADED(ID, 1)) {
			isLoaded = true;
		}
		WAIT(500);
	}
	return isLoaded;
}
void ChangeModel(Actor actor, eActor actorID)
{
	vector3 mcrot;
	mcrot.x = 0;
	mcrot.y = GET_HEADING(self);
	mcrot.z = 0;
	if (!RequestActor(actorID))
	{
		print2("Error", 2000);
		WAIT(2000);
		return;
	}
	GET_POSITION(actor, &ve20);
	RESPAWN_PLAYER_ACTOR_IN_LAYOUT(FIND_NAMED_LAYOUT("PlayerLayout"), actor, "player", actorID, ve20, mcrot, 1);//player may not be needed
	SET_CAMERA_FOLLOW_ACTOR(self);
	SET_ACTOR_HEALTH(actor, GET_ACTOR_MAX_HEALTH(actor));
}

int CarSpawnz(eActor id)
{
	ve25.x = 0;
	ve25.y = GET_HEADING(self);
	ve25.z = 0;
	bool isLoaded = false;
	STREAMING_REQUEST_ACTOR(id, true, false);
	for (int i = 0; i < 5; i++)
	{
		if (STREAMING_IS_ACTOR_LOADED(id, 1)) {
			isLoaded = true;
			break;
		}
		WAIT(500);
	}
	if (!isLoaded)
		return 0;

	GET_POSITION(GET_PLAYER_ACTOR(0), &ve24);
	int car = CREATE_ACTOR_IN_LAYOUT(FIND_NAMED_LAYOUT("PlayerLayout"), "", id, ve24, ve25);
	return car;
}

void SpawnThatVehicle(eActor VehID)
{
	float headit = GET_HEADING(self);
	DESTROY_ACTOR(SpawnCar1);
	for (int i = 0; i <= 3; i++)//destroy drafts before they get created again
	{
		if (IS_ACTOR_VALID(SpawnDra[i]))
		{
			DESTROY_ACTOR(SpawnDra[i]);
		}
	}
	SpawnCar1 = CarSpawnz(VehID);
	int DraftCount = _GET_NUM_DRAFT_SLOTS(SpawnCar1);
	DraftCount -= 1;//fix for correct drafts for vehs
	if (VehID != 1181 && VehID != 1189 && VehID != 1190 && VehID != 1191 && VehID != 1192 && VehID != 1193 && VehID != 1194)
	{
		for (int i = 0; i <= DraftCount; i++)
		{
			SpawnDra[i] = CreateActor(979);
			ATTACH_DRAFT_TO_VEHICLE(SpawnDra[i], SpawnCar1, i, 1);
			_ACCESORIZE_VEHICLE_HORSES(SpawnCar1, 5);
		}
	}
	SET_ACTOR_HEADING(SpawnCar1, headit, 1);
	WAIT(100);
	SET_ACTOR_IN_VEHICLE(self, SpawnCar1, 0);
}

void LaunchCS(int ScriptID, const char* ThatScript)
{
	if (!IS_SCRIPT_VALID(cs[ScriptID]))
		cs[ScriptID] = RunScript(ThatScript);
}

void TeleportActor(float x, float y, float z)
{
	vector3 tptestvec;
	tptestvec.x = x;
	tptestvec.y = y;
	tptestvec.z = z;
	float heading = GET_HEADING(self);
	if (IS_ACTOR_RIDING(self))
		TELEPORT_ACTOR(GET_MOUNT(self), &tptestvec, 1, 1, 1);
	else if (IS_ACTOR_DRIVING_VEHICLE(self))
		TELEPORT_ACTOR(GET_VEHICLE(self), &tptestvec, 1, 1, 1);
	else
		TELEPORT_ACTOR_WITH_HEADING(self, tptestvec, heading, 1, 1, 1);
}
void SpawnHorse(eActor id)
{
	float headit = GET_HEADING(self);
	DESTROY_ACTOR(SpawnMount1); SpawnMount1 = CreateActor(id); SET_ACTOR_HEADING(SpawnMount1, headit, 1); SET_ACTOR_RIDEABLE(SpawnMount1, 1); WAIT(77); ACCESSORIZE_HORSE(SpawnMount1, 3); ACTOR_MOUNT_ACTOR(self, SpawnMount1); SET_ACTOR_HEALTH(SpawnMount1, GET_ACTOR_MAX_HEALTH(SpawnMount1));
}
void SpawnItzPedz(eActor id)
{
	if (pedint2 == 10)
	{
		for (int i = 0; i <= 9; i++)
		{
			if (IS_ACTOR_VALID(SpawnPed[i]))
			{
				DESTROY_ACTOR(SpawnPed[i]);
			}
		}
		pedint2 = 0;//resetting it
	}
	SpawnPed[pedint2] = CreateActor(id); SET_ACTOR_HEALTH(SpawnPed[pedint2], GET_ACTOR_MAX_HEALTH(SpawnPed[pedint2]));
	pedint2 += 1;
}
void MedusaCleanUp()
{
	if (IS_ACTOR_DEAD(GET_LAST_ATTACKER(self)))
	{
		CLEAR_LAST_HIT(self);
	}
	if (IS_ACTOR_ALIVE(GET_LAST_ATTACKER(self)))
	{
		CLEAR_LAST_HIT(self);
	}
	if (!IS_ACTOR_VALID(GET_LAST_ATTACKER(self)))
	{
		CLEAR_LAST_HIT(self);
	}
}
void DEColor()
{
	PPP_UNLOAD_PRESET(PPPChar[0]); PPP_UNLOAD_PRESET(PPPChar[1]); PPP_UNLOAD_PRESET(PPPChar[2]);//resets everytime function is executed then the loops set correct colors.
	if (DETog == 0) { BlueDE = 0; RedDE = 0; ClearDE = 1; print2("CLEAR", 2000); DETog = 1; }
	else if (DETog == 1) { BlueDE = 1; RedDE = 0; ClearDE = 0; print2("BLUE", 2000); DETog = 2; }
	else if (DETog == 2) { BlueDE = 0; RedDE = 1; ClearDE = 0; print2("RED", 2000); DETog = 3; }
	else if (DETog == 3) { BlueDE = 0; RedDE = 0; ClearDE = 0; PPP_UNLOAD_PRESET(PPPChar[0]); PPP_UNLOAD_PRESET(PPPChar[1]); PPP_UNLOAD_PRESET(PPPChar[2]); print2("RESET", 2000); DETog = 0; }
}

void DESelect()
{
	if (DELvl == 0) { SET_DEADEYE_MULTILOCK_ENABLE(self, 0); SET_DEADEYE_TARGETPAINT_ENABLE(self, 0); print2("Lvl 1", 2000); DELvl = 1; }
	else if (DELvl == 1) { SET_DEADEYE_MULTILOCK_ENABLE(self, 1); SET_DEADEYE_TARGETPAINT_ENABLE(self, 0); print2("Lvl 2", 2000); DELvl = 2; }
	else if (DELvl == 2) { SET_DEADEYE_MULTILOCK_ENABLE(self, 1); SET_DEADEYE_TARGETPAINT_ENABLE(self, 1); print2("Lvl 3", 2000); DELvl = 0; }
}

void DETime1()
{
	if (DETime == 0) { SET_DEADEYE_TIMESCALE(self, 1.0); print2("None", 2000); DETime = 1; }
	else if (DETime == 1) { SET_DEADEYE_TIMESCALE(self, 10.0); print2("Fast (Maxed Out)", 2000); DETime = 2; }
	else if (DETime == 2) { SET_DEADEYE_TIMESCALE(self, 0.3); print2("Normal", 2000); DETime = 0; }
}
void RideAbleAnimalsV3()
{
	int MyMount = GET_MOUNT(self);
	if (!IS_ITERATOR_VALID(animalridez1))animalridez1 = CREATE_OBJECT_ITERATOR(FIND_NAMED_LAYOUT("playerlayout"));
	if (!IS_ITERATOR_VALID(animalridez2))animalridez2 = CREATE_OBJECT_ITERATOR(GET_AMBIENT_LAYOUT());
	ITERATE_ON_OBJECT_TYPE(animalridez1, OBJECT_TYPE_Actor);
	ITERATE_ON_OBJECT_TYPE(animalridez2, OBJECT_TYPE_Actor);
	START_OBJECT_ITERATOR(animalridez1); START_OBJECT_ITERATOR(animalridez2);
	int count = GET_NUM_ITERATOR_MATCHES(animalridez1) + GET_NUM_ITERATOR_MATCHES(animalridez2);
	for (int i = 0; i < count; i++)
	{
		int actorrideit = OBJECT_ITERATOR_CURRENT(animalridez1);
		int actorrideit2 = OBJECT_ITERATOR_CURRENT(animalridez2);
		if (IS_ACTOR_VALID(actorrideit))
		{
			if (actorrideit != GET_PLAYER_ACTOR(0))
			{
				if (IS_ACTOR_ANIMAL(actorrideit))
				{
					SET_ACTOR_RIDEABLE(actorrideit, 1); SET_ALLOW_RIDE_BY_PLAYER(actorrideit, 1); ANIMAL_ACTOR_SET_DOMESTICATION(actorrideit, 0);
				}
			}
		}
		if (IS_ACTOR_VALID(actorrideit2))
		{
			if (actorrideit2 != GET_PLAYER_ACTOR(0))
			{
				if (IS_ACTOR_ANIMAL(actorrideit2))
				{
					SET_ACTOR_RIDEABLE(actorrideit2, 1); SET_ALLOW_RIDE_BY_PLAYER(actorrideit2, 1); ANIMAL_ACTOR_SET_DOMESTICATION(actorrideit2, 0);
				}
			}
		}
		OBJECT_ITERATOR_NEXT(animalridez1); OBJECT_ITERATOR_NEXT(animalridez2);
	}
	DESTROY_ITERATOR(animalridez1); DESTROY_ITERATOR(animalridez2);
	if (IS_ACTOR_VALID(MyMount))//for use with ride animal files only, this should fix layout specific special animal spawns to be rideable at all times without kicking us off.
	{
		if (IS_ACTOR_ANIMAL(MyMount))
		{
			ANIMAL_ACTOR_SET_DOMESTICATION(MyMount, 0);
		}
	}
}
void AIOBools()
{
	if (Phos)
	{
		_ENABLE_PHOSPHORUS_ROUNDS(1);
	}
	if (AnimalBypassON)
	{
		RideAbleAnimalsV3();
	}
	if (aimbott2)
	{
		if (IS_PLAYER_WEAPON_ZOOMED(self))
		{
			Actor ReticleActor = GET_ACTOR_UNDER_RETICLE(self, 20);
			if (IS_ACTOR_VALID(ReticleActor))
			{
				_SET_ACTOR_ENUM_HARD_LOCK_AQUIRE_BONE_CASUAL(ReticleActor, "head");
				_SET_ACTOR_ENUM_HARD_LOCK_AQUIRE_BONE(ReticleActor, "head");
			}
		}
	}
	if (CarSpeedBoost)
	{
		float fakehead = GET_OBJECT_HEADING(GET_GAME_CAMERA());
		int Speed = 36;
		if (IS_ACTOR_DRIVING_VEHICLE(self))
		{
			int My_Super_Subaru = GET_VEHICLE(self);
			if (GetButtonDown(BUTTON_R2)) { SET_ACTOR_SPEED(My_Super_Subaru, TO_FLOAT(Speed)); }
			if (GetButtonDown(BUTTON_L1)) { SET_ACTOR_SPEED(My_Super_Subaru, TO_FLOAT(-Speed)); }
			if (GetButtonDown(BUTTON_L2)) { SET_ACTOR_SPEED(My_Super_Subaru, TO_FLOAT(0)); }
			if (GetButtonDown(DPAD_UP)) { SET_ACTOR_HEADING(My_Super_Subaru, fakehead, 1); }
			if (GetButtonDown(BUTTON_L3)) { GET_POSITION(self, &ve16); ve15 = ve16; ve15.y = ve16.y + 1; TELEPORT_ACTOR(My_Super_Subaru, &ve15, 1, 1, 1); }
		}
	}
	if (NoclipON)//seems switch likes to clear vector3 data pretty constantly and breaks our y value ALOT, so applied a hack to get it for forward facing direction
	{
		vector3 loc, loc2, yfix;
		GET_POSITION(self, &loc);
		loc2.x = loc.x;
		loc2.y = loc.y;
		loc2.z = loc.z;
		float heading = GET_HEADING(self);
		float a = 1.0 * SIN(heading);
		float b = 1.0 * COS(heading);
		loc2.x -= a;
		loc2.z -= b;
		float fakehead = GET_OBJECT_HEADING(GET_GAME_CAMERA());
		if (GetButtonDown(DPAD_UP)) { GET_POSITION(self, &yfix); loc2.y = yfix.y; SET_ACTOR_HEADING(self, fakehead, 1); SET_OBJECT_POSITION(self, loc2); }
		if (GetButtonDown(BUTTON_L3)) { TASK_CLEAR(self); GET_POSITION(self, &ve16); ve15 = ve16; ve15.y = ve16.y - 1; TELEPORT_ACTOR(self, &ve15, 1, 1, 1); SET_PLAYER_POSTURE(self, 0, 0); }
		if (GetButtonDown(BUTTON_R1)) { TASK_CLEAR(self); GET_POSITION(self, &ve18); ve17 = ve18; ve17.y = ve18.y + 1; TELEPORT_ACTOR(self, &ve17, 1, 1, 1); SET_PLAYER_POSTURE(self, 0, 0); }
		if (GetButton(BUTTON_Y)) { SET_MOVER_FROZEN(self, 0); NoclipON = false; }
	}

	if (IS_PLAYER_DEADEYE(self))
	{
		if (ClearDE)
		{
			DEColorSwap = 1;
			PPP_UNLOAD_PRESET(PPPChar[0]); PPP_UNLOAD_PRESET(PPPChar[1]); PPP_UNLOAD_PRESET(PPPChar[2]);
		}
		if (BlueDE)
		{
			DEColorSwap = 1;
			PPP_LOAD_PRESET(PPPChar[2]);
		}
		if (RedDE)
		{
			DEColorSwap = 1;
			PPP_LOAD_PRESET(PPPChar[1]);
		}
	}
	if (!IS_PLAYER_DEADEYE(self))//hacky fix to unload the ppp elements when we stop using deadeye
	{
		if (DEColorSwap == 1)
		{
			PPP_UNLOAD_PRESET(PPPChar[0]); PPP_UNLOAD_PRESET(PPPChar[1]); PPP_UNLOAD_PRESET(PPPChar[2]);
			DEColorSwap = 0;
		}
	}
	if (IS_ACTOR_VALID(SpawnCar1))
	{
		ENABLE_VEHICLE_SEAT(SpawnCar1, 0, 1); ENABLE_VEHICLE_SEAT(SpawnCar1, 1, 1); SET_VEHICLE_ENGINE_RUNNING(SpawnCar1, 1); SET_VEHICLE_EJECTION_ENABLED(SpawnCar1, 0); SET_VEHICLE_PASSENGERS_ALLOWED(SpawnCar1, 1);
		ENABLE_VEHICLE_SEAT(SpawnCar1, 2, 1); ENABLE_VEHICLE_SEAT(SpawnCar1, 3, 1); ENABLE_VEHICLE_SEAT(SpawnCar1, 4, 1); ENABLE_VEHICLE_SEAT(SpawnCar1, 5, 1); ENABLE_VEHICLE_SEAT(SpawnCar1, 6, 1); SET_VEHICLE_ALLOWED_TO_DRIVE(SpawnCar1, 1);
	}
	if (God)
	{
		if (!FlameON)SET_ACTOR_PROOF(self, -1);//if ghost rider is off, we allow this
		if (FlameON)CLEAR_ACTOR_PROOF(self, -1);//if ghost rider is on we clear our actor proof
		if (!FlameON && !MedusaKill && !MedusaXplode && !MedusaDestroy && !Fireround && !BGPAI2 && !DeadEye1Hit && !MedusaBurn && !CopyGun)//if all of these are off, we turn invul
		{
			SET_ACTOR_INVULNERABILITY(self, 1);
		}
		if (IS_ACTOR_RIDING(self))
		{
			SET_ACTOR_INVULNERABILITY(GET_MOUNT(self), 1);
			SET_ACTOR_HEALTH(GET_MOUNT(self), GET_ACTOR_MAX_HEALTH(GET_MOUNT(self)));
			SET_ACTOR_PROOF(GET_MOUNT(self), -1);//24
		}
		if (FlameON || MedusaKill || MedusaXplode || MedusaDestroy || Fireround || BGPAI2 || DeadEye1Hit || MedusaBurn || CopyGun)//if any of these are on we turn invul off
		{
			SET_ACTOR_INVULNERABILITY(self, 0);
		}
	}
	if (HrsStam)
	{
		HORSE_SET_INFINITE_FRESHNESS_CHEAT(1);
		if (IS_ACTOR_DRIVING_VEHICLE(self))
		{
			for (int i = 0; i <= 3; i++)
			{
				if (IS_ACTOR_VALID(GET_DRAFT_ACTOR(i, GET_VEHICLE(self))))
				{
					HORSE_SET_CURR_FRESHNESS(GET_DRAFT_ACTOR(i, GET_VEHICLE(self)), TO_FLOAT(100));
					HORSE_LOCK_FRESHNESS(GET_DRAFT_ACTOR(i, GET_VEHICLE(self)));
				}
			}
		}
		if (!IS_ACTOR_DRIVING_VEHICLE(self))
		{
			for (int i = 0; i <= 3; i++)
			{
				if (IS_ACTOR_VALID(GET_ACTOR_MOST_RECENT_VEHICLE(self)))//if vehicle is still valid then try to get drafts of that vehicle
				{
					if (IS_ACTOR_VALID(GET_DRAFT_ACTOR(i, GET_ACTOR_MOST_RECENT_VEHICLE(self))))//if the drafts of that vehicle are valid then set them to normal
					{
						HORSE_UNLOCK_FRESHNESS(GET_DRAFT_ACTOR(i, GET_ACTOR_MOST_RECENT_VEHICLE(self)));
					}
				}
			}
		}
	}
	if (IrishDrunk)SET_ACTOR_DRUNK(self, 1);
	if (IgnoreON)AI_IGNORE_ACTOR(self);
	if ((PLATFORM == PLATFORM_X360 || PLATFORM == PLATFORM_SWITCH) && (SuperJump) && GetButtonDown(BUTTON_X) && IS_ACTOR_ALIVE(self))
	{
		GET_POSITION(self, &ve41);
		ve40 = ve41;
		ve40.y = ve41.y - 1.9;
		_CREATE_EXPLOSION(&ve40, EXPLOSION_ExplosionLargeNoFx, true, &ve40, true);
	}
	if (AntiRagDoll)
	{
		if (!IS_ACTOR_ANIMAL(self))
		{
			if (IS_ACTOR_RAGDOLL(self))
			{
				ACTOR_RESET_ANIMS(self, 1);
				TASK_CROUCH(self, 1);
			}
		}
	}
	if (AntiRagDoll2)
	{
		if (!IS_ACTOR_ANIMAL(self))
		{
			if (!IS_ACTOR_ON_GROUND(self) && !IS_ACTOR_RIDING(self) && !IS_ACTOR_INSIDE_VEHICLE(self) && !IS_ACTOR_USING_LEDGE(self) && !IS_ACTOR_ON_LADDER(self) && !IS_ACTOR_RIDING_VEHICLE(self))
			{
				ACTOR_START_FORCE_HOLSTER(self, 0, 0);
			}
			if (IS_ACTOR_RAGDOLL(self))
			{
				ACTOR_RESET_ANIMS(self, 1);

			}
		}
	}
	if (DeadEye1Hit)
	{
		int DeadTarget = GET_LAST_ATTACK_TARGET(self);
		SET_DEADEYE_DAMAGE_SCALING(self, 100.0f);
		if (DeadTarget != GET_PLAYER_ACTOR(0))
		{
			KILL_ACTOR(DeadTarget);
			KILL_ACTOR(DeadTarget);
			CLEAR_LAST_ATTACK(self);
		}
	}
	if (DeadEyeInf1)
	{
		SET_INFINITE_DEADEYE(self, 1);
		SET_DEADEYE_REGENERATION_RATE(self, TO_FLOAT(500), 1);
		SET_DEADEYE_REGENERATION_RATE_MULTIPLIER(self, TO_FLOAT(500));
	}
	if (StandStillFucker)
	{
		for (int i = 0; i <= 9; i++)
		{
			if (IS_ACTOR_VALID(SpawnPed[i]))TASK_STAND_STILL(SpawnPed[i], 1, 1, 1);
		}
	}
	if (PedzFollow)
	{
		SET_ACTOR_IS_THE_BEASTMASTER(self, 1);//temp fix for animal followers
		for (int i = 0; i <= 9; i++)
		{
			if (IS_ACTOR_VALID(SpawnPed[i]))TASK_FOLLOW_ACTOR(SpawnPed[i], self);
		}
	}
	if (CopyGun)
	{
		if (IS_ACTOR_HUMAN(GET_LAST_ATTACK_TARGET(self)))
		{
			if (GET_LAST_ATTACK_TARGET(self) != GET_PLAYER_ACTOR(0))
			{
				ChangeModel(self, GET_ACTOR_ENUM(GET_LAST_ATTACK_TARGET(self)));
				CLEAR_LAST_ATTACK(self);
			}
		}
	}
	if (Timez)
	{
		SET_TIME_ACCELERATION(TO_FLOAT(5000));
	}
	if (DeleteGun)
	{
		if (GET_LAST_ATTACK_TARGET(self) != GET_PLAYER_ACTOR(0))
		{
			DESTROY_ACTOR(GET_LAST_ATTACK_TARGET(self));
			DESTROY_ACTOR(GET_LAST_ATTACK_TARGET(self));
			CLEAR_LAST_ATTACK(self);
		}
	}
	if (IS_ACTOR_SHOOTING(self) && (nReload))
	{
		_ADD_AMMO_OF_TYPE(self, GET_AMMO_ENUM(GET_WEAPON_IN_HAND(self)), TO_FLOAT(100), 1, 0);
		ACTOR_SET_WEAPON_AMMO(self, GET_WEAPON_IN_HAND(self), TO_FLOAT(55));
	}
	if (FlameON)
	{
		//God = 0;
		SET_ACTOR_INVULNERABILITY(self, 0);
		if (GET_ACTOR_PROOF(self) == -1)CLEAR_ACTOR_PROOF_ALL(self);
		SET_ACTOR_HEALTH(self, GET_ACTOR_MAX_HEALTH(self));
		int ourFire = FIRE_CREATE_HANDLE();
		FIRE_CREATE_ON_ACTOR(ourFire, self);
		FIRE_SET_DAMAGE_ALLOWED(ourFire, 0);
		FIRE_RELEASE_HANDLE(ourFire, self);
	}
	if (GoldIt)
	{
		for (int i = 0; i <= 37; i++)
		{
			if (i != 21 && i != 32 && i != 35 && i != 36 && i != 37)
			{
				if (GET_WEAPON_GOLD(self, i) != 1)
				{
					SET_WEAPON_GOLD(self, i, 1);
				}
			}
		}
	}
	if (BGPAI2)//bodyguard function, feel free to update this because it sure does need it lol.
	{
		StandStillFucker = 0;
		PedzFollow = 0;
		PedCrip = 0;
		int selfattcker = GET_LAST_ATTACKER(self);
		int self_target = GET_LAST_ATTACK_TARGET(self);
		for (int i = 0; i <= 9; i++)
		{
			if (IS_ACTOR_VALID(SpawnPed[i]))
			{
				TASK_FOLLOW_ACTOR(SpawnPed[i], self);
				AI_IGNORE_ACTOR(SpawnPed[i]);
				SET_ACTOR_FACTION(SpawnPed[i], 20);
				MEMORY_ALLOW_TAKE_COVER(SpawnPed[i], 0);
				COMBAT_CLASS_AI_SET_ATTRIB_FLOAT(SpawnPed[i], 28, 0.0f);
				COMBAT_CLASS_AI_SET_ATTRIB_FLOAT(SpawnPed[i], 31, -1.0f);
				COMBAT_CLASS_AI_SET_ATTRIB_FLOAT(SpawnPed[i], 37, 2.0f);
				COMBAT_CLASS_AI_SET_FRIENDLY_FIRE_CONSIDERATION(SpawnPed[i], 0);
				SET_CRIPPLE_ENABLE(SpawnPed[i], 0);
				SET_ACTOR_ALLOW_WEAPON_REACTION_FLEE(SpawnPed[i], 0);
				SET_ACTOR_WEAPON_REACTION_NO_FLEE_HACK(SpawnPed[i], 1);
				SET_ACTOR_PROOF(SpawnPed[i], -1);
				AI_SET_FIRE_DELAY(SpawnPed[i], TO_FLOAT(0));
				AI_SET_FIRE_DELAY_RANDOMNESS(SpawnPed[i], TO_FLOAT(0));
				ACTOR_SET_WEAPON_AMMO(SpawnPed[i], GET_WEAPON_IN_HAND(SpawnPed[i]), TO_FLOAT(55));
				SET_ACTOR_EXEMPT_FROM_AMBIENT_RESTRICTIONS(SpawnPed[i], 1);
				AI_SET_DISARMED(SpawnPed[i], 0);
				SET_ACTOR_ALLOW_BUMP_REACTIONS(SpawnPed[i], 0);
				if (BGuardTarget == 16)
				{
					if (selfattcker)
					{
						if (!IS_WEAPON_DRAWN(SpawnPed[i]))ACTOR_DRAW_WEAPON(SpawnPed[i], wepzint, 1);
						if (wepzint != 22)
						{
							TASK_KILL_CHAR(SpawnPed[i], selfattcker);
							TASK_PRIORITY_SET(SpawnPed[i], 1);
						}
						if (wepzint == 22)
						{
							TASK_MELEE_ATTACK(SpawnPed[i], GET_LAST_ATTACKER(self), 1);
							TASK_PRIORITY_SET(SpawnPed[i], 1);
						}
					}
					if (self_target)
					{
						if (!IS_WEAPON_DRAWN(SpawnPed[i]))ACTOR_DRAW_WEAPON(SpawnPed[i], wepzint, 1);
						if (wepzint != 22)
						{
							TASK_KILL_CHAR(SpawnPed[i], self_target);
							TASK_PRIORITY_SET(SpawnPed[i], 1);
						}
						if (wepzint == 22)
						{
							TASK_MELEE_ATTACK(SpawnPed[i], GET_LAST_ATTACK_TARGET(self), 1);
							TASK_PRIORITY_SET(SpawnPed[i], 1);
						}
					}
					if (IS_ACTOR_DEAD(selfattcker) || IS_ACTOR_VEHICLE(selfattcker) || IS_ACTOR_DEAD(self_target) || IS_ACTOR_VEHICLE(self_target))
					{
						TASK_FOLLOW_ACTOR(SpawnPed[i], self);
						TASK_PRIORITY_SET(SpawnPed[i], 1);
						if (IS_ACTOR_DEAD(selfattcker) || IS_ACTOR_VEHICLE(selfattcker))
						{
							CLEAR_LAST_HIT(self);
						}
						if (IS_ACTOR_DEAD(self_target) || IS_ACTOR_VEHICLE(self_target))
						{
							CLEAR_LAST_ATTACK(self);
						}
					}
				}
			}
		}
	}
	if (ExplosiveRounds)
	{
		vector3 PlayerRetPos;
		bool isPlayerAiming = IS_PLAYER_WEAPON_ZOOMED(self);
		bool isPlayerFiring = IS_ACTOR_SHOOTING(self);
		if (isPlayerAiming)
		{
			GET_RETICLE_TARGET_POINT(self, &PlayerRetPos);
			if (isPlayerFiring)
			{
				_CREATE_EXPLOSION(&PlayerRetPos, EXPLOSION_CannonballExplosion, true, &PlayerRetPos, true);
			}
		}
	}
	if (BurnGun)
	{
		vector3 PlayerRetPos;
		bool isPlayerAiming = IS_PLAYER_WEAPON_ZOOMED(self);
		bool isPlayerFiring = IS_ACTOR_SHOOTING(self);
		if (isPlayerAiming)
		{
			GET_RETICLE_TARGET_POINT(self, &PlayerRetPos);
			if (isPlayerFiring)
			{
				_CREATE_EXPLOSION(&PlayerRetPos, EXPLOSION_FireBottleExplosion, true, &PlayerRetPos, true);
			}
		}
	}
	if (MedusaKill)
	{
		if (GET_LAST_ATTACKER(self) != GET_PLAYER_ACTOR(0) && (!IS_ACTOR_VEHICLE(GET_LAST_ATTACKER(self))))
		{
			KILL_ACTOR(GET_LAST_ATTACKER(self));
		}
		MedusaCleanUp();
	}
	if (MedusaDestroy)
	{
		if (GET_LAST_ATTACKER(self) != GET_PLAYER_ACTOR(0) && (!IS_ACTOR_VEHICLE(GET_LAST_ATTACKER(self))))
		{
			DESTROY_ACTOR(GET_LAST_ATTACKER(self));
		}
		MedusaCleanUp();
	}
	if (MedusaXplode)
	{
		if (GET_LAST_ATTACKER(self) != GET_PLAYER_ACTOR(0) && (!IS_ACTOR_VEHICLE(GET_LAST_ATTACKER(self))))
		{
			GET_POSITION(GET_LAST_ATTACKER(self), &ve19);_CREATE_EXPLOSION(&ve19, EXPLOSION_CannonballExplosion, true, &ve19, true);
		}
		MedusaCleanUp();
	}
	if (MedusaBurn)
	{
		if (GET_LAST_ATTACKER(self) != GET_PLAYER_ACTOR(0) && (!IS_ACTOR_VEHICLE(GET_LAST_ATTACKER(self))))
		{
			GET_POSITION(GET_LAST_ATTACKER(self), &ve19);_CREATE_EXPLOSION(&ve19, EXPLOSION_FireBottleExplosion, true, &ve19, true);
		}
		MedusaCleanUp();
	}
	if (TODLoop)
	{
		SET_TIME_OF_DAY(MAKE_TIME_OF_DAY(todg, 0, 0));
	}
	if (TODLoop2)
	{
		SET_WEATHER(weathint2, 0);//whoops this has been fucked since xbox, fixed now lmao
	}
	if (!IS_PLAYER_DEADEYE(self) && (AutoDead) && (GET_WEAPON_IN_HAND(self) != 22) && (GET_WEAPON_IN_HAND(self) != 33))
	{
		SET_DISABLE_DEADEYE(self, 0);
		SET_PLAYER_DEADEYE_MODE(self, 1);
	}
	if (Fireround)FIRE_SET_GUNS_BLAZING_ACTIVE(1);
	if (Slugz)_DLC_SHOTGUN_SPREAD_OVERRIDE(self, 1, 0.1f);
}
void AmmoInf() //Infinite ammo
{
	UnlimitedAmmo = !UnlimitedAmmo;
	nReload = !nReload;
	if (UnlimitedAmmo)
	{
		for (int weapon = 0; weapon <= 20; weapon++)//10 -- 20 seems to allow all weapons to be inf ammo, shouldnt have a reason to loop in sp?
			_SET_INFINITE_AMMO_FLAG(self, weapon, 1);
	}
	else
	{
		for (int weapon = 0; weapon <= 20; weapon++)//10
			_SET_INFINITE_AMMO_FLAG(self, weapon, 0);
	}
}
void GivePedWepz(int WeaponID)
{
	for (int i = 0; i <= 9; i++)
	{
		if (IS_ACTOR_VALID(SpawnPed[i]))
		{
			_DELETE_ALL_WEAPONS(SpawnPed[i]);
			GIVE_WEAPON_TO_ACTOR(SpawnPed[i], WeaponID, 0, 0, 0);
			_ADD_AMMO_OF_TYPE(SpawnPed[i], GET_AMMO_ENUM(WeaponID), TO_FLOAT(100), 1, 1);
			TASK_CLEAR(SpawnPed[i]);
			ACTOR_RESET_ANIMS(SpawnPed[i], 1);
			ACTOR_HOLSTER_WEAPON(SpawnPed[i], WeaponID);
			ACTOR_SET_NEXT_WEAPON(SpawnPed[i], WeaponID);
			GIVE_WEAPON_TO_ACTOR(SpawnPed[i], WeaponID, 0, 0, 0);
			ACTOR_SET_NEXT_WEAPON(SpawnPed[i], WeaponID);
			ACTOR_DRAW_WEAPON(SpawnPed[i], WeaponID, 1);
		}
	}
}
void FixBG()
{
	for (int i = 0; i <= 9; i++)
	{
		if (IS_ACTOR_VALID(SpawnPed[i]))
		{
			CLEAR_ACTOR_PROOF(SpawnPed[i], -1);
			SET_ACTOR_FACTION(SpawnPed[i], 0);
			TASK_CLEAR(SpawnPed[i]);
		}
	}
}
unsafe void GIVE_MONEY()//updated but switch gives max cash for some reason, no complaints tho lol
{
	__push(0);
	__getGlobalP(55480);
	__getArray(1);
	__push(1000);
	__callNative(0x67116627, 1, 1);
	__addF();
	__push(0);
	__getGlobalP(55480);
	__setArray(1);
	__pushString("MoneyText");
	__pushString("Dmoney_amount");
	__push(0);
	__getGlobalP(55480);
	__getArray(1);
	__callNative(0x32E9BE04, 1, 1);
	__callNative(0xF71BD93A, 3, 0);
}
void WaitForWorldToLoad(bool usePrint)
{
	while (!STREAMING_IS_WORLD_LOADED())
	{
		SET_PLAYER_CONTROL(0, 0, 0, 0);
		if (usePrint)
			print2("Waiting for the world to load", 5000);
		WAIT(0);
	}
	SET_PLAYER_CONTROL(0, 1, 0, 0);
}
int specialW = 0;
vector3 canpos;
bool Cannonwep = 0;
int WTFCAN;
int CreateObject(const char* propName)
{
	char propit[256];
	strcpy(propit, "$/fragments/", 255);
	stradd(propit, propName, 255);
	REQUEST_ASSET(propit, 0);
	int id = GET_ASSET_ID(propit, 0);
	while (!STREAMING_IS_PROP_LOADED(id))
	{
		STREAMING_REQUEST_PROP(id, 1);
		WAIT(0);
	}
	Layout l;
	l = FIND_NAMED_LAYOUT("PlayerLayout");
	GET_POSITION(self, &canpos);
	int cannon = CREATE_PROP_IN_LAYOUT(l, propName, propit, canpos, canpos, 1);
	return cannon;
}
void GiveSpecialWeapon()
{
	int thatweapon;
	Cannonwep = false;
	DESTROY_OBJECT(WTFCAN);//lazy we just destroy it when cycling the weps, else it stays spawned
	if (specialW == 0)
	{
		thatweapon = 26; print2("Gatling", 2000); specialW = 1;
	}
	else if (specialW == 1)
	{
		thatweapon =27; print2("Browing", 2000); specialW = 2;
	}
	else if (specialW == 2)
	{
		Cannonwep = true;
		thatweapon = 28; print2("Cannon", 2000); specialW = 3;
		WTFCAN = CreateObject("p_gen_cannon02x");
	}
	else if (specialW == 3)
	{
		thatweapon = 32; print2("ZombSpit", 2000); specialW = 0;
	}
	ACTOR_HOLSTER_WEAPON(GET_PLAYER_ACTOR(0), thatweapon);
	ACTOR_SET_NEXT_WEAPON(GET_PLAYER_ACTOR(0), thatweapon);
	GIVE_WEAPON_TO_ACTOR(GET_PLAYER_ACTOR(0), thatweapon, 0, 0, 0);
	ACTOR_SET_NEXT_WEAPON(GET_PLAYER_ACTOR(0), thatweapon);
}
void GIVE_ITEMS()
{
	//need to re-do for real hardware support in the future, not a priority rn. Should work fine on real hardware however softlocks could occur for 20-30 seconds. (does on normal)
	//gives one of every item
	for (int items = 0; items <= 100; items++)
	{
		// blocking items to avoid save/crash issues
		if (items != 13 && items != 14 && items != 59 && items != 60 && items != 61 && items != 62 && items != 63 && items != 65)
		{
			for (int m = 0; m <= 256; m++)//this gives max count of current item (some items have a max of 1-5 and do not have a "max" icon/flag.
			{
				ADD_ITEM(SS_GET_STRING(1, items), self, 0);
			}
		}
	}
}
void GIVE_UNDEADPRO()
{
	// function was re-made for hazards save editor, he deciced what to keep and block in undead. 
	// you can still manually add any items give all doesnt give
	// this gives one of each individual item that is not blocked
	for (int i = 0; i < 147; i++)
	{
		//                                                                                                                                                                                                               131 121 120 108 105 103 102 100 98 97
		// we are blocking the function from giving us these items via give all safe items option
		if (i != 59 && i != 60 && i != 61 && i != 62 && i != 63 && i != 64 && i != 65 && i != 66 && i != 67 && i != 76 && i != 80 && i != 81 && i != 91 && i != 92 && i != 93 && i != 94 && i != 97 && i != 98 && i != 100 && i != 102 && i != 103 && i != 105 && i != 108 && i != 120 && i != 121 && i != 131)
		{
			for (int m = 0; m <= 256; m++)//this gives max count of current item
			{
				ADD_COLLECTABLE(Provisions[i], self, 0);
			}
		}
	}
}
void HorseFx(float x, float y, float z, const char* FXType)
{
	float whatx = x;
	float whaty = y;
	float whatz = z;
	//emitter_set
	Layout l = FIND_NAMED_LAYOUT("Player_layout");
	DESTROY_OBJECT(testwtf); DESTROY_OBJECTSET(testwtf2); DESTROY_OBJECT(deafx2); DESTROY_OBJECTSET(deafx); DESTROY_OBJECT(war2); DESTROY_OBJECT(war4); DESTROY_OBJECT(war6); DESTROY_OBJECT(war8); DESTROY_OBJECT(war10); DESTROY_OBJECT(war12); DESTROY_OBJECT(war14); DESTROY_OBJECT(war16); DESTROY_OBJECT(war18); DESTROY_OBJECTSET(war1); DESTROY_OBJECTSET(war3); DESTROY_OBJECTSET(war4); DESTROY_OBJECTSET(war7); DESTROY_OBJECTSET(war9); DESTROY_OBJECTSET(war11); DESTROY_OBJECTSET(war13); DESTROY_OBJECTSET(war15); DESTROY_OBJECTSET(war17);
	testwtf2 = CREATE_OBJECTSET_IN_LAYOUT(l, GET_MOUNT(self), -1, 1);
	if (_STRING_COMPARE(FXType, "script_unicorn_rainbow"))//yeah on switch for some reason, or code issue it's refusing the lower the unicorn fx to look right however it looks okay for now...
	{
		testwtf = _CREATE_RMPTFX_EFFECT_ON_BONE(1, FXType, "spine00", GET_MOUNT(self), whatx, whaty, whatz, GET_MOUNT(self));
	}
	if (!_STRING_COMPARE(FXType, "script_unicorn_rainbow"))//jank as fuck fix so pestilence and famine apply correctly
	{
		testwtf = _CREATE_RMPTFX_EFFECT_ON_OBJECT(0, FXType, GET_MOUNT(self), TO_FLOAT(0), TO_FLOAT(0), TO_FLOAT(0), 1, GET_MOUNT(self));//script_unicorn_rainbow, script_4Horsemen_death_01, script_4Horsemen_famine_01, script_4Horsemen_pestilence_01
	}
	_RMPTFX_EFFECT_START(testwtf, TO_FLOAT(0), TO_FLOAT(0), TO_FLOAT(0));
	ADD_OBJECT_TO_OBJECTSET(testwtf, testwtf2);
}
void HorseFxDea(int x1, int y1, int z1, float x2, float y2, float z2, const char* FXType1, const char* FXType2)
{
	Layout l = FIND_NAMED_LAYOUT("Player_layout");
	DESTROY_OBJECT(testwtf); DESTROY_OBJECTSET(testwtf2); DESTROY_OBJECT(deafx2); DESTROY_OBJECTSET(deafx); DESTROY_OBJECT(war2); DESTROY_OBJECT(war4); DESTROY_OBJECT(war6); DESTROY_OBJECT(war8); DESTROY_OBJECT(war10); DESTROY_OBJECT(war12); DESTROY_OBJECT(war14); DESTROY_OBJECT(war16); DESTROY_OBJECT(war18); DESTROY_OBJECTSET(war1); DESTROY_OBJECTSET(war3); DESTROY_OBJECTSET(war4); DESTROY_OBJECTSET(war7); DESTROY_OBJECTSET(war9); DESTROY_OBJECTSET(war11); DESTROY_OBJECTSET(war13); DESTROY_OBJECTSET(war15); DESTROY_OBJECTSET(war17);
	deafx = CREATE_OBJECTSET_IN_LAYOUT(l, GET_MOUNT(self), -1, 1);
	deafx2 = _CREATE_RMPTFX_EFFECT_ON_OBJECT(0, FXType1, GET_MOUNT(self), TO_FLOAT(x1), TO_FLOAT(y1), TO_FLOAT(z1), 1, GET_MOUNT(self));
	_RMPTFX_EFFECT_START(deafx2, TO_FLOAT(0), TO_FLOAT(0), TO_FLOAT(0));
	ADD_OBJECT_TO_OBJECTSET(deafx2, deafx);
	testwtf2 = CREATE_OBJECTSET_IN_LAYOUT(l, GET_MOUNT(self), -1, 1);
	testwtf = _CREATE_RMPTFX_EFFECT_ON_BONE(0, FXType2, "spine00", GET_MOUNT(self), x2, y2, z2, GET_MOUNT(self));
	_RMPTFX_EFFECT_START(testwtf, TO_FLOAT(0), TO_FLOAT(0), TO_FLOAT(0));
	ADD_OBJECT_TO_OBJECTSET(testwtf, testwtf2);
}
void HorseFxWar(const char* FXType1, const char* FXType2)
{
	Layout l = FIND_NAMED_LAYOUT("Player_layout");
	DESTROY_OBJECT(testwtf); DESTROY_OBJECTSET(testwtf2); DESTROY_OBJECT(deafx2); DESTROY_OBJECTSET(deafx); DESTROY_OBJECT(war2); DESTROY_OBJECT(war4); DESTROY_OBJECT(war6); DESTROY_OBJECT(war8); DESTROY_OBJECT(war10); DESTROY_OBJECT(war12); DESTROY_OBJECT(war14); DESTROY_OBJECT(war16); DESTROY_OBJECT(war18); DESTROY_OBJECTSET(war1); DESTROY_OBJECTSET(war3); DESTROY_OBJECTSET(war4); DESTROY_OBJECTSET(war7); DESTROY_OBJECTSET(war9); DESTROY_OBJECTSET(war11); DESTROY_OBJECTSET(war13); DESTROY_OBJECTSET(war15); DESTROY_OBJECTSET(war17);
	testwtf2 = CREATE_OBJECTSET_IN_LAYOUT(l, GET_MOUNT(self), -1, 1);
	testwtf = _CREATE_RMPTFX_EFFECT_ON_OBJECT(0, FXType1, GET_MOUNT(self), TO_FLOAT(0), TO_FLOAT(0), TO_FLOAT(0), 1, GET_MOUNT(self));
	_RMPTFX_EFFECT_START(testwtf, TO_FLOAT(0), TO_FLOAT(0), TO_FLOAT(0));
	ADD_OBJECT_TO_OBJECTSET(testwtf, testwtf2);
	war1 = CREATE_OBJECTSET_IN_LAYOUT(l, GET_MOUNT(self), -1, 1);
	war2 = _CREATE_RMPTFX_EFFECT_ON_BONE(0, FXType2, "nail_r", GET_MOUNT(self), TO_FLOAT(0), TO_FLOAT(0), TO_FLOAT(0), GET_MOUNT(self));
	_RMPTFX_EFFECT_START(war2, TO_FLOAT(0), TO_FLOAT(0), TO_FLOAT(0));
	ADD_OBJECT_TO_OBJECTSET(war2, war1);
	war3 = CREATE_OBJECTSET_IN_LAYOUT(l, GET_MOUNT(self), -1, 1);
	war4 = _CREATE_RMPTFX_EFFECT_ON_BONE(0, FXType2, "nail_l", GET_MOUNT(self), TO_FLOAT(0), TO_FLOAT(0), TO_FLOAT(0), GET_MOUNT(self));
	_RMPTFX_EFFECT_START(war4, TO_FLOAT(0), TO_FLOAT(0), TO_FLOAT(0));
	ADD_OBJECT_TO_OBJECTSET(war4, war3);
	war5 = CREATE_OBJECTSET_IN_LAYOUT(l, GET_MOUNT(self), -1, 1);
	war6 = _CREATE_RMPTFX_EFFECT_ON_BONE(0, FXType2, "toe_r", GET_MOUNT(self), TO_FLOAT(0), TO_FLOAT(0), TO_FLOAT(0), GET_MOUNT(self));
	_RMPTFX_EFFECT_START(war6, TO_FLOAT(0), TO_FLOAT(0), TO_FLOAT(0));
	ADD_OBJECT_TO_OBJECTSET(war6, war5);
	war7 = CREATE_OBJECTSET_IN_LAYOUT(l, GET_MOUNT(self), -1, 1);
	war8 = _CREATE_RMPTFX_EFFECT_ON_BONE(0, FXType2, "toe_l", GET_MOUNT(self), TO_FLOAT(0), TO_FLOAT(0), TO_FLOAT(0), GET_MOUNT(self));
	_RMPTFX_EFFECT_START(war8, TO_FLOAT(0), TO_FLOAT(0), TO_FLOAT(0));
	ADD_OBJECT_TO_OBJECTSET(war8, war7);
	war9 = CREATE_OBJECTSET_IN_LAYOUT(l, GET_MOUNT(self), -1, 1);
	war10 = _CREATE_RMPTFX_EFFECT_ON_BONE(0, FXType2, "tail_m_02", GET_MOUNT(self), TO_FLOAT(0), TO_FLOAT(0), TO_FLOAT(0), GET_MOUNT(self));
	_RMPTFX_EFFECT_START(war10, TO_FLOAT(0), TO_FLOAT(0), TO_FLOAT(0));
	ADD_OBJECT_TO_OBJECTSET(war10, war9);
	war11 = CREATE_OBJECTSET_IN_LAYOUT(l, GET_MOUNT(self), -1, 1);
	war12 = _CREATE_RMPTFX_EFFECT_ON_BONE(0, FXType2, "tail_l_03", GET_MOUNT(self), TO_FLOAT(0), TO_FLOAT(0), TO_FLOAT(0), GET_MOUNT(self));
	_RMPTFX_EFFECT_START(war12, TO_FLOAT(0), TO_FLOAT(0), TO_FLOAT(0));
	ADD_OBJECT_TO_OBJECTSET(war12, war11);
	war13 = CREATE_OBJECTSET_IN_LAYOUT(l, GET_MOUNT(self), -1, 1);
	war14 = _CREATE_RMPTFX_EFFECT_ON_BONE(0, FXType2, "hair03_04_l", GET_MOUNT(self), TO_FLOAT(0), TO_FLOAT(0), TO_FLOAT(0), GET_MOUNT(self));
	_RMPTFX_EFFECT_START(war14, TO_FLOAT(0), TO_FLOAT(0), TO_FLOAT(0));
	ADD_OBJECT_TO_OBJECTSET(war14, war13);
	war15 = CREATE_OBJECTSET_IN_LAYOUT(l, GET_MOUNT(self), -1, 1);
	war16 = _CREATE_RMPTFX_EFFECT_ON_BONE(0, FXType2, "hair04_04_r", GET_MOUNT(self), TO_FLOAT(0), TO_FLOAT(0), TO_FLOAT(0), GET_MOUNT(self));
	_RMPTFX_EFFECT_START(war16, TO_FLOAT(0), TO_FLOAT(0), TO_FLOAT(0));
	ADD_OBJECT_TO_OBJECTSET(war16, war15);
	war17 = CREATE_OBJECTSET_IN_LAYOUT(l, GET_MOUNT(self), -1, 1);
	war18 = _CREATE_RMPTFX_EFFECT_ON_BONE(0, FXType2, "hair05_04_l", GET_MOUNT(self), TO_FLOAT(0), TO_FLOAT(0), TO_FLOAT(0), GET_MOUNT(self));
	_RMPTFX_EFFECT_START(war18, TO_FLOAT(0), TO_FLOAT(0), TO_FLOAT(0));
	ADD_OBJECT_TO_OBJECTSET(war18, war17);
}
void ZombifyPeds()
{
	for (int i = 0; i <= 9; i++)
	{
		if (IS_ACTOR_VALID(SpawnPed[i]))
		{
			if (IS_ACTOR_HUMAN(SpawnPed[i]))
			{
				ADD_ZOMBIE_TO_ACTOR(SpawnPed[i], RAND_INT_RANGE(1, 3), RAND_INT_RANGE(1, 3));
				DECOR_SET_BOOL(SpawnPed[i], "Zombie", 1);
				TURN_ACTOR_INTO_ZOMBIE(SpawnPed[i], ACTOR_UN_ZOMBIE_Fast_01);// this works and makes them act like retchers, however i rather them be normal zombies, will figure out later.
				AI_SET_TR_PROGRAM_FOR_ACTOR(SpawnPed[i], "Zombie");
			}
		}
	}
}
int weathertest;
void MainLRSwitches()
{
	if (ToggleSpoof13)
	{
		HUD_CLEAR_HELP_QUEUE();
		EnableThat = false;
		char modmsg[255];
		char ModelStuff1[255];
		if (PedWepz == 1)
		{
			stradd_s(modmsg, "Peds Weapon Editor\n<x>:Confirm\n<action>:Cancel\n<dpadleftright>:Weapon:<orange> ");
			if (wepzint == 21 || wepzint == 30)stradd_s(modmsg, "BLOCKED WEP");
			if (wepzint == 25)stradd_s(modmsg, "Throwing Knife");
			if (wepzint == 29)stradd_s(modmsg, "Tomahawk");
			if (wepzint == 32)stradd_s(modmsg, "Remove Weapons");
			if (wepzint != 21 && wepzint != 25 && wepzint != 29 && wepzint != 30 && wepzint != 32)stradd_s(modmsg, UI_GET_STRING(GET_WEAPON_DISPLAY_NAME(wepzint)));
		}
		if (PedWepz == 3)
		{
			stradd_s(modmsg, "Vehicle Spawner\n<x>:Confirm\n<action>:Cancel\n<dpadleftright>:Vehicle:<orange> ");
			stradd_s(modmsg, VSChar[vehintz2]);
		}
		if (PedWepz == 4)
		{
			stradd_s(modmsg, "New Austin Teleports\n<x>:Confirm\n<action>:Cancel\n<dpadleftright>:Teleport:<orange> ");
			stradd_s(modmsg, NAChar[austel]);
		}
		if (PedWepz == 5)
		{
			stradd_s(modmsg, "West Elizabeth Teleports\n<x>:Confirm\n<action>:Cancel\n<dpadleftright>:Teleport:<orange> ");
			stradd_s(modmsg, WEChar[westeli]);
		}
		if (PedWepz == 6)
		{
			stradd_s(modmsg, "Mexico Teleports\n<x>:Confirm\n<action>:Cancel\n<dpadleftright>:Teleport:<orange> ");
			stradd_s(modmsg, MTChar[mextel]);
		}
		if (PedWepz == 7)
		{
			stradd_s(modmsg, "Special Teleports\n<x>:Confirm\n<action>:Cancel\n<dpadleftright>:Teleport:<orange> ");
			stradd_s(modmsg, HIChar[hidint]);
		}
		if (PedWepz == 8)
		{
			stradd_s(modmsg, "Out of Map Teleports\n<x>:Confirm\n<action>:Cancel\n<dpadleftright>:Teleport:<orange> ");
			stradd_s(modmsg, OoMChar[outmapz]);
		}
		if (PedWepz == 9)
		{
			stradd_s(modmsg, "Weather Types\n<x>:Confirm\n<action>:Cancel\n<dpadleftright>:Weather:<orange> ");
			stradd_s(modmsg, WTChar[weathint]);
		}
		if (PedWepz == 10)
		{
			stradd_s(modmsg, "Mount Spawner\n<x>:Confirm\n<action>:Cancel\n<dpadleftright>:Mount:<orange> ");
			stradd_s(modmsg, MSChar[mspz]);
		}
		if (PedWepz == 14)
		{
			stradd_s(modmsg, "Mount Accessory Editor\n<x>:Confirm\n<action>:Cancel\n<dpadleftright>:Accessory:<orange> ");
			stradd_s(modmsg, MAChar[muit]);
		}
		if (PedWepz == 18)
		{
			stradd_s(modmsg, "Script Loader\n<x>:Confirm\n<action>:Cancel\n<y>:Terminate All\n<lb>:Script Info\n<dpadleftright>:Script To Load:<orange> ");
			stradd_s(modmsg, INT_TO_STRING(Cscript));
			if (GetButton(BUTTON_LB))
			{
				print2("<orange>Scripts Go In /content/release64/scripting/</orange> \n <blue>Name As 1-10</blue> \n <green>Example: 1.wsc</green> \nUse MagicRDR/LibertyFourX To Import Scripts", 7000);
			}
		}
		if (PedWepz == 19)
		{
			stradd_s(modmsg, "Quick Model\n<x>:Confirm\n<action>:Cancel\n<dpadleftright>:Model:<orange> ");
			stradd_s(modmsg, QuickM[QModel]);
		}
		if (PedWepz == 20)
		{
			stradd_s(modmsg, "Quick Ped Spawner\n<x>:Confirm\n<action>:Cancel\n<dpadupdown>:Ped Class:<red> ");
			stradd_s(modmsg, LectChar[selectorz]);
			stradd_s(modmsg, "\n</red><dpadleftright>:Ped:<blue> ");
			if (selectorz == 0)stradd_s(modmsg, ZombChar[zombi]);
			if (selectorz == 1)stradd_s(modmsg, WorkChar[workz]);
			if (selectorz == 2)stradd_s(modmsg, GangChar[gangz]);
			if (selectorz == 3)stradd_s(modmsg, LawChar[lawz]);
			if (selectorz == 4)stradd_s(modmsg, ProstChar[prostz]);
			if (selectorz == 5)stradd_s(modmsg, AniChar[animalzz]);
			if (selectorz == 6)stradd_s(modmsg, MiscChar[miscz]);
		}
		if (PedWepz == 21)
		{
			stradd_s(modmsg, "Outfit Editor\n<x>:Confirm\n<action>:Cancel\n<y>:Toggle Hat\n<rb>:Toggle Bandana\n<dpadleftright>:John/Jack Outfit:<orange> ");
			stradd_s(modmsg, INT_TO_STRING(jtest1));
		}
		if (PedWepz == 23)
		{
			stradd_s(modmsg, "Ped Spawner\n<x>:Confirm\n<action>:Cancel\n<dpadleftright>:Ped ID:<orange> ");
			stradd_s(modmsg, INT_TO_STRING(pedname));
			stradd_s(modmsg, "\n");
			stradd_s(modmsg, GET_ACTOR_ENUM_STRING_FROM_ENUM(pedname));
			//Grabbing display name if it exist and just doing a subtitle print for it
			stradd_s(ModelStuff1, "<red>Display Name</red>:");
			if (!_STRING_COMPARE(UI_GET_STRING(GET_ACTOR_ENUM_STRING_FROM_ENUM(pedname)), ""))
			{
				stradd_s(ModelStuff1, UI_GET_STRING(GET_ACTOR_ENUM_STRING_FROM_ENUM(pedname)));// Gets UI display name if it exist.
			}
			else
			{
				stradd_s(ModelStuff1, "--NOT DEFINED--");
			}
			stradd_s(ModelStuff1, "\n<blue>NOT DEFINED means the game doesn't use the enum string.\nThe Stranger is a game placeholder name.");
			print2(ModelStuff1, 1000);
		}
		if (PedWepz == 24)
		{
			stradd_s(modmsg, "Model Changer\n<x>:Confirm\n<action>:Cancel\n<dpadleftright>:Model ID:<orange> ");
			stradd_s(modmsg, INT_TO_STRING(modelname));
			stradd_s(modmsg, "\n");
			stradd_s(modmsg, GET_ACTOR_ENUM_STRING_FROM_ENUM(modelname));
			//Grabbing display name if it exist and just doing a subtitle print for it
			stradd_s(ModelStuff1, "<red>Display Name</red>:");
			if (!_STRING_COMPARE(UI_GET_STRING(GET_ACTOR_ENUM_STRING_FROM_ENUM(modelname)), ""))
			{
				stradd_s(ModelStuff1, UI_GET_STRING(GET_ACTOR_ENUM_STRING_FROM_ENUM(modelname)));// Gets UI display name if it exist.
			}
			else
			{
				stradd_s(ModelStuff1, "--NOT DEFINED--");
			}
			stradd_s(ModelStuff1, "\n<blue>NOT DEFINED means the game doesn't use the enum string.\nThe Stranger is a game placeholder name.");
			print2(ModelStuff1, 1000);
		}
		if (PedWepz == 25)
		{
			stradd_s(modmsg, "Time Editor\n<x>:Confirm\n<action>:Cancel\n<dpadleftright>:Time:<orange> ");
			stradd_s(modmsg, INT_TO_STRING(todg));
		}
		if (PedWepz == 28)
		{
			stradd_s(modmsg, "Movie Player\n<x>:Confirm\n<action>:Cancel\n<y>:Stop Video\n<rb>:Theater:<orange> ");
			if (cusvideo2 == 0)stradd_s(modmsg, "Armadillo\n");
			if (cusvideo2 == 1)stradd_s(modmsg, "Blackwater\n");
			stradd_s(modmsg, "</orange><dpadleftright>:Video:<orange> ");
			if (cusvideo == 11)stradd_s(modmsg, "arm00");
			if (cusvideo == 12)stradd_s(modmsg, "blk00");
			if (cusvideo != 11 && cusvideo != 12)stradd_s(modmsg, INT_TO_STRING(cusvideo));
		}
		if (PedWepz == 29)
		{
			stradd_s(modmsg, "Song Player\n<x>:Confirm\n<action>:Cancel\n<y>:Stop Song\n<dpadleftright>:Song:<orange> ");
			stradd_s(modmsg, Plsong[songIndex]);
		}
		if (PedWepz == 31)
		{
			stradd_s(modmsg, "Animation Player\n<x>:Confirm\n<action>:Cancel\n<y>:Stop Animation\n<dpadleftright>:Animation:<orange> ");
			stradd_s(modmsg, AnimChar[Animint]);
		}
		if (PedWepz == 33)
		{
			//need to re-do for real hardware support in the future, not a priority rn.
			stradd_s(modmsg, "Consumables Editor\n<x>:Confirm\n<y>:Remove Item\n<cancel>:Cancel\n<dpadleftright>:Consumable/Kit:<orange> ");
			if (_STRING_COMPARE(UI_GET_STRING(SS_GET_STRING(1, consume)), "") && consume != 79 && consume != 80)stradd_s(modmsg, "--NOT DEFINED--");
			if (!_STRING_COMPARE(UI_GET_STRING(SS_GET_STRING(1, consume)), "") && consume != 79 && consume != 80)stradd_s(modmsg, UI_GET_STRING(SS_GET_STRING(1, consume)));
			if (consume == 79)stradd_s(modmsg, "Give All Safe Items");
			if (consume == 80)stradd_s(modmsg, "Remove All Items");
			print2("Everything is here, however be warned. The consumable, and kit have a hard limit. If you go over it you won't be able to save the game or will crash when opening satchel. Give All Safe Items gives all acceptable items", 1000);
		}
		if (PedWepz == 34)
		{
			stradd_s(modmsg, "Provisions Editor\n<x>:Confirm\n<y>:Remove Item\n<cancel>:Cancel\n<dpadleftright>:Provision:<orange> ");
			if (proved != 146 && proved != 147)stradd_s(modmsg, UI_GET_STRING(Provisions[proved]));
			if (proved == 146)stradd_s(modmsg, "Give All Safe Items");
			if (proved == 147)stradd_s(modmsg, "Remove All Items");
			print2("Everything is here, however be warned. The provisions have a hard limit (120 items). If you go over it you won't be able to save the game and or will crash when going to provisions tab in the satchel. Give All Safe Items gives all acceptable items", 1000);
		}
		if (PedWepz == 40)
		{
			stradd_s(modmsg, "Ped Task\n<x>:Confirm\n<cancel>:Cancel\n<dpadleftright>:Task:<orange> ");
			if (pedtask == 0 && StandStillFucker)stradd_s(modmsg, "Stand Still</orange>: <green>ON");
			if (pedtask == 0 && !StandStillFucker)stradd_s(modmsg, "Stand Still</orange>: <red>OFF");
			if (pedtask == 1 && PedzFollow)stradd_s(modmsg, "Follow</orange>: <green>ON");
			if (pedtask == 1 && !PedzFollow)stradd_s(modmsg, "Follow</orange>: <red>OFF");
			if (pedtask == 2 && BGPAI2)stradd_s(modmsg, "Bodyguard</orange>: <green>ON");
			if (pedtask == 2 && !BGPAI2)stradd_s(modmsg, "Bodyguard</orange>: <red>OFF");
			if (pedtask == 3 && PedCrip)stradd_s(modmsg, "Cripple</orange>: <green>ON");
			if (pedtask == 3 && !PedCrip)stradd_s(modmsg, "Cripple</orange>: <red>OFF");
			if (pedtask == 4)stradd_s(modmsg, "Zombify");//need to make toggable??
		}
		if (PedWepz == 99)//test switch function
		{
			stradd_s(modmsg, "Test\n<x>:Confirm\n<cancel>:Cancel\n<dpadleftright>:Blah<orange> ");
			stradd_s(modmsg, INT_TO_STRING(troph));
			stradd_s(modmsg, "\n");
			stradd_s(modmsg, UI_GET_STRING(Provisions[troph]));
		}
		PRINT_HELP_B(modmsg, 500.0f, false, 1, 2, 1, "", "");
		if (GetButton(DPAD_LEFT))
		{
			if (PedWepz == 1)
			{
				wepzint--;
				if (wepzint < 0) wepzint = 32;
			}
			if (PedWepz == 3)
			{
				vehintz--;
				if (vehintz < 1177) vehintz = 1202;

				vehintz2--;
				if (vehintz2 < 0) vehintz2 = 25;
			}
			if (PedWepz == 4)
			{
				austel--;
				if (austel < 0) austel = 13;
			}
			if (PedWepz == 5)
			{
				westeli--;
				if (westeli < 0) westeli = 6;
			}
			if (PedWepz == 6)
			{
				mextel--;
				if (mextel < 0) mextel = 12;
			}
			if (PedWepz == 7)
			{
				hidint--;
				if (hidint < 0) hidint = 22;
			}
			if (PedWepz == 8)
			{
				outmapz--;
				if (outmapz < 0) outmapz = 5;
			}
			if (PedWepz == 9)
			{
				weathint--;
				if (weathint < 0) weathint = 22;
			}
			if (PedWepz == 10)
			{
				mspz--;
				if (mspz < 0) mspz = 47;
			}
			if (PedWepz == 14)
			{
				muit--;
				if (muit < 0) muit = 11;
			}
			if (PedWepz == 18)
			{
				Cscript--;
				if (Cscript < 1) Cscript = 10;
			}
			if (PedWepz == 19)
			{
				QModel--;
				if (QModel < 0) QModel = 10;
			}
			if (PedWepz == 20)
			{
				if (selectorz == 0)
				{
					zombi--;
					if (zombi < 0) zombi = 7;
				}
				if (selectorz == 1)
				{
					workz--;
					if (workz < 0) workz = 7;
				}
				if (selectorz == 2)
				{
					gangz--;
					if (gangz < 0) gangz = 6;
				}
				if (selectorz == 3)
				{
					lawz--;
					if (lawz < 0) lawz = 7;
				}
				if (selectorz == 4)
				{
					prostz--;
					if (prostz < 0) prostz = 6;
				}
				if (selectorz == 5)
				{
					animalzz--;
					if (animalzz < 0) animalzz = 7;
				}
				if (selectorz == 6)
				{
					miscz--;
					if (miscz < 0) miscz = 6;
				}
			}
			if (PedWepz == 21)
			{
				jtest1--;
				if (jtest1 < 0) jtest1 = 24;
			}
			if (PedWepz == 25)
			{
				todg--;
				if (todg < 0) todg = 24;
			}
			if (PedWepz == 28)
			{
				cusvideo--;
				if (cusvideo < 1) cusvideo = 12;
			}
			if (PedWepz == 29)
			{
				songIndex--;
				if (songIndex < 0) songIndex = 32;
			}
			if (PedWepz == 33)
			{
				consume--;
				if (consume < 0) consume = 80;
			}
			if (PedWepz == 34)
			{
				proved--;
				if (proved < 0) proved = 147;
			}
			if (PedWepz == 40)
			{
				pedtask--;
				if (pedtask < 0) pedtask = 4;
			}
			if (PedWepz == 99)//for testing
			{
				troph--;
				if (troph < 0) troph = 110;
			}
		}
		if (GetButtonDown(DPAD_LEFT))
		{
			if (PedWepz == 23)
			{
				pedname--;
				if (pedname < 0) pedname = 1310;
				WAIT(65);
			}
			if (PedWepz == 24)
			{
				modelname--;
				if (modelname < 0) modelname = 1310;
				WAIT(65);
			}
			if (PedWepz == 31)
			{
				Animint--;
				if (Animint < 0) Animint = 385;
				WAIT(65);
			}
		}
		if (GetButtonDown(DPAD_RIGHT))
		{
			if (PedWepz == 23)
			{
				pedname++;
				if (pedname > 1310) pedname = 0;
				WAIT(65);
			}
			if (PedWepz == 24)
			{
				modelname++;
				if (modelname > 1310) modelname = 0;
				WAIT(65);
			}
			if (PedWepz == 31)
			{
				Animint++;
				if (Animint > 385) Animint = 0;
				WAIT(65);
			}
		}
		if (GetButton(DPAD_RIGHT))
		{
			if (PedWepz == 1)
			{
				wepzint++;
				if (wepzint > 32) wepzint = 0;
			}
			if (PedWepz == 3)
			{
				vehintz++;
				if (vehintz > 1202) vehintz = 1177;

				vehintz2++;
				if (vehintz2 > 25) vehintz2 = 0;
			}
			if (PedWepz == 4)
			{
				austel++;
				if (austel > 13) austel = 0;
			}
			if (PedWepz == 5)
			{
				westeli++;
				if (westeli > 6) westeli = 0;
			}
			if (PedWepz == 6)
			{
				mextel++;
				if (mextel > 12) mextel = 0;
			}
			if (PedWepz == 7)
			{
				hidint++;
				if (hidint > 22) hidint = 0;
			}
			if (PedWepz == 8)
			{
				outmapz++;
				if (outmapz > 5) outmapz = 0;
			}
			if (PedWepz == 9)
			{
				weathint++;
				if (weathint > 22) weathint = 0;
			}
			if (PedWepz == 10)
			{
				mspz++;
				if (mspz > 47) mspz = 0;
			}
			if (PedWepz == 14)
			{
				muit++;
				if (muit > 11) muit = 0;
			}
			if (PedWepz == 18)
			{
				Cscript++;
				if (Cscript > 10) Cscript = 1;
			}
			if (PedWepz == 19)
			{
				QModel++;
				if (QModel > 10) QModel = 0;
			}
			if (PedWepz == 20)
			{
				if (selectorz == 0)
				{
					zombi++;
					if (zombi > 7) zombi = 0;
				}
				if (selectorz == 1)
				{
					workz++;
					if (workz > 7) workz = 0;
				}
				if (selectorz == 2)
				{
					gangz++;
					if (gangz > 6) gangz = 0;
				}
				if (selectorz == 3)
				{
					lawz++;
					if (lawz > 7) lawz = 0;
				}
				if (selectorz == 4)
				{
					prostz++;
					if (prostz > 6) prostz = 0;
				}
				if (selectorz == 5)
				{
					animalzz++;
					if (animalzz > 7) animalzz = 0;
				}
				if (selectorz == 6)
				{
					miscz++;
					if (miscz > 6) miscz = 0;
				}
			}
			if (PedWepz == 21)
			{
				jtest1++;
				if (jtest1 > 24) jtest1 = 0;
			}
			if (PedWepz == 25)
			{
				todg++;
				if (todg > 24) todg = 0;
			}
			if (PedWepz == 28)
			{
				cusvideo++;
				if (cusvideo > 12) cusvideo = 1;
			}
			if (PedWepz == 29)
			{
				songIndex++;
				if (songIndex > 32) songIndex = 0;
			}
			if (PedWepz == 33)
			{
				consume++;
				if (consume > 80) consume = 0;
			}
			if (PedWepz == 34)
			{
				proved++;
				if (proved > 147) proved = 0;
			}
			if (PedWepz == 40)
			{
				pedtask++;
				if (pedtask > 4) pedtask = 0;
			}
			if (PedWepz == 99)//for testing
			{
				troph++;
				if (troph > 110) troph = 0;
			}
		}
		if (GetButton(DPAD_DOWN))
		{
			if (PedWepz == 20)
			{
				selectorz--;
				if (selectorz < 0) selectorz = 6;
			}
		}
		if (GetButton(DPAD_UP))
		{
			if (PedWepz == 20)
			{
				selectorz++;
				if (selectorz > 6) selectorz = 0;
			}
		}
		if (GetButton(BUTTON_Y))
		{
			if (PedWepz == 18)
			{
				print2("<0x00FFFF>All Scripts Terminated</0x>", 2000);
				for (int i = 1; i <= 10; i++)//can be increased just have to modify cs[11], so lets say you want 100 scripts, change it to cs[101] etc
				{
					CancelScr(i);
				}
			}
			if (PedWepz == 21)
			{
				if (tghat == 0)
				{
					_DELETE_ALL_ACCESSORIES(self);
					tghat = 1;
				}
				else if (tghat == 1)
				{
					SETUP_ASSOCIATED_FRAGMENTS(self);
					tghat = 0;
				}
			}
			if (PedWepz == 28)
			{
				if (_IS_WORLD_MOVIE_PLAYING())
					_STOP_WORLD_MOVIE();
			}
			if (PedWepz == 29)
			{
				AUDIO_MUSIC_SUSPEND(1000);
			}
			if (PedWepz == 31)
			{
				AI_QUICK_EXIT_GRINGO(self, 1);
				DESTROY_OBJECT(uVar5);
				TASK_CLEAR(self);
				ACTOR_RESET_ANIMS(self, 1);
				STREAMING_EVICT_GRINGO(animID);
				ENABLE_MOVER(self);
				//SET_MOVER_FROZEN(self, 0);
			}
			if (PedWepz == 33)
			{
				if (consume != 79 && consume != 80)
				{
					for (int m = 0; m <= 256; m++)//deletes max count of items
					{
						DELETE_ITEM(SS_GET_STRING(1, consume), self, 0);
					}
				}
			}
			if (PedWepz == 34)
			{
				if (proved != 146 && proved != 147)
				{
					//removes all of this item
					for (int m = 0; m <= 256; m++)
					{
						REMOVE_COLLECTABLE(Provisions[proved], self);
					}
				}
			}
		}
		if (GetButton(BUTTON_RB))
		{
			if (PedWepz == 21)
			{
				if (tban == 0)
				{
					EQUIP_ACCESSORY(self, 1, 0); ACTOR_ENABLE_VARIABLE_MESH(self, 26, 0);tban = 1;
				}
				else if (tban == 1)
				{
					EQUIP_ACCESSORY(self, 1, 1); ACTOR_ENABLE_VARIABLE_MESH(self, 26, 1);tban = 0;
				}
			}
			if (PedWepz == 28)
			{
				cusvideo2++;
				if (cusvideo2 > 1) cusvideo2 = 0;
			}
		}
		if (PLATFORM == PLATFORM_X360 || PLATFORM == PLATFORM_SWITCH && GetButton(BUTTON_X))
		{
			if (PedWepz == 1 && wepzint != 21 && wepzint != 30)
			{
				GivePedWepz(wepzint);
			}
			if (PedWepz == 1 && wepzint == 32)
			{
				for (int i = 0; i <= 9; i++)
				{
					if (IS_ACTOR_VALID(SpawnPed[i]))
					{
						_DELETE_ALL_WEAPONS(SpawnPed[i]);
					}
				}
			}
			if (PedWepz == 3)
			{
				SpawnThatVehicle(vehintz);
			}
			if (PedWepz == 4)
			{
				SET_PLAYER_CONTROL(self, 0, 0, 0);
				if (austel == 0) { TeleportActor(-2175.62f, 16.31f, 2613.50f); }
				if (austel == 1) { TeleportActor(-887.08f, 90.19f, 2420.53f); }
				if (austel == 2) { TeleportActor(-4007.25f, 28.46f, 2935.45f); }
				if (austel == 3) { TeleportActor(-2622.53f, 68.08f, 3390.51f); }
				if (austel == 4) { TeleportActor(-4461.66f, 7.78f, 3310.42f); }
				if (austel == 5) { TeleportActor(-2425.06f, 25.00f, 2138.93f); }
				if (austel == 6) { TeleportActor(-3126.40f, 43.57f, 3724.13f); }
				if (austel == 7) { TeleportActor(-3661.76f, 42.23f, 2124.73f); }
				if (austel == 8) { TeleportActor(-3275.14f, 15.89f, 2719.86f); }
				if (austel == 9) { TeleportActor(111.55f, 73.29f, 2318.82f); }
				if (austel == 10) { TeleportActor(-3686.96f, 8.62f, 3493.24f); }
				if (austel == 11) { TeleportActor(-1955.07f, 24.82f, 3255.67f); }
				if (austel == 12) { TeleportActor(-1793.48f, 23.78f, 2836.85f); }
				if (austel == 13) { TeleportActor(-1226.26f, 74.29f, 2369.10f); }
				SET_PLAYER_CONTROL(self, 1, 0, 0);
			}
			if (PedWepz == 5)
			{
				SET_PLAYER_CONTROL(self, 0, 0, 0);
				if (westeli == 0) { TeleportActor(711.18f, 78.31f, 1252.76f); }
				if (westeli == 1) { TeleportActor(-739.29f, 179.10f, 784.69f); }
				if (westeli == 2) { TeleportActor(-83.45f, 117.68f, 1374.10f); }
				if (westeli == 3) { TeleportActor(-428.16f, 151.34f, 1615.59f); }
				if (westeli == 4) { TeleportActor(-221.09f, 84.31f, 2124.10f); }
				if (westeli == 5) { TeleportActor(-1043.06f, 184.05f, 1361.10f); }
				if (westeli == 6) { TeleportActor(325.34f, 74.29f, 1939.81f); }
				SET_PLAYER_CONTROL(self, 1, 0, 0);
			}
			if (PedWepz == 6)
			{
				SET_PLAYER_CONTROL(self, 0, 0, 0);
				if (mextel == 0) { TeleportActor(-4279.04f, 18.07f, 4447.64f); }
				if (mextel == 1) { TeleportActor(-2714.70f, 32.37f, 4251.90f); }
				if (mextel == 2) { TeleportActor(-1700.31f, 8.08f, 4242.14f); }
				if (mextel == 3) { TeleportActor(-3288.00f, 38.20f, 4547.00f); }
				if (mextel == 4) { TeleportActor(-698.10f, 63.25f, 3323.25f); }
				if (mextel == 5) { TeleportActor(-788.78f, 13.04f, 3729.81f); }
				if (mextel == 6) { TeleportActor(-4701.72f, 3.04f, 3958.90f); }
				if (mextel == 7) { TeleportActor(-455.44f, 20.84f, 3926.91f); }
				if (mextel == 8) { TeleportActor(-1545.03f, 15.03f, 3913.46f); }
				if (mextel == 9) { TeleportActor(376.66f, 76.30f, 3459.57f); }
				if (mextel == 10) { TeleportActor(-1153.43f, 26.15f, 4829.81f); }
				if (mextel == 11) { TeleportActor(-82.37f, 53.01f, 2844.53f); }
				if (mextel == 12) { TeleportActor(-2136.35f, 16.03f, 4938.61f); }
				SET_PLAYER_CONTROL(self, 1, 0, 0);
			}
			if (PedWepz == 7)
			{
				SET_PLAYER_CONTROL(self, 0, 0, 0);
				if (hidint == 0) { TeleportActor(-789.04f, 93.07f, 2402.02f); }
				if (hidint == 1) { TeleportActor(-2068.08f, 19.05f, 2648.07f); }
				if (hidint == 2) { TeleportActor(-2159.03f, 19.09f, 2597.04f); }
				if (hidint == 3) { TeleportActor(-2158.06f, 19.09f, 2588.07f); }
				if (hidint == 4) { TeleportActor(133.00f, 73.07f, 2296.06f); }
				if (hidint == 5) { TeleportActor(773.08f, 79.05f, 1235.01f); }
				if (hidint == 6) { TeleportActor(775.08, 78.06f, 1284.04f); }
				if (hidint == 7) { TeleportActor(709.09f, 78.09f, 1290.02f); }
				if (hidint == 8) { TeleportActor(747.09f, 86.09f, 1265.09f); }
				if (hidint == 9) { TeleportActor(749.03f, 78.04f, 1277.05f); }
				if (hidint == 10) { TeleportActor(751.04f, 78.06f, 1302.00f); }
				if (hidint == 11) { TeleportActor(678.07f, 83.05f, 1236.09f); }
				if (hidint == 12) { TeleportActor(751.06f, 82.07f, 1270.02f); }
				if (hidint == 13) { TeleportActor(583.10f, 85.80f, 1326.80f); }
				if (hidint == 14) { TeleportActor(-106.07f, 119.05f, 1361.02f); }
				if (hidint == 15) { TeleportActor(-4307.00f, 31.02f, 4384.01f); }
				if (hidint == 16) { TeleportActor(-4333.05f, 30.00f, 4374.07f); }
				if (hidint == 17) { TeleportActor(-4355.02f, 29.03f, 4405.08f); }
				if (hidint == 18) { TeleportActor(-4356.02f, 42.03f, 4329.08f); }
				if (hidint == 19) { TeleportActor(-1692.01f, 8.00f, 4188.05f); }
				if (hidint == 20) { TeleportActor(-1709.09f, 13.00f, 4199.06f); }
				if (hidint == 21) { TeleportActor(-2690.02f, 31.03f, 4295.08f); }
				if (hidint == 22) { TeleportActor(-2742.02f, 32.03f, 4247.08f); }
				SET_PLAYER_CONTROL(self, 1, 0, 0);
			}
			if (PedWepz == 8)
			{
				SET_PLAYER_CONTROL(self, 0, 0, 0);
				if (outmapz == 0) { TeleportActor(-112.10f, 128.50f, 898.37f); }
				if (outmapz == 1) { TeleportActor(-1085.06f, 354.03f, 1081.01f); }
				if (outmapz == 2) { TeleportActor(1398.61f, 86.31f, 1876.81f); }
				if (outmapz == 3) { TeleportActor(-1048.06f, 189.02f, 5609.07f); }
				if (outmapz == 4) { TeleportActor(-5068.03f, 28.01f, 4163.07f); }
				if (outmapz == 5) { TeleportActor(-177.03f, 36.08f, 4473.09f); }
				SET_PLAYER_CONTROL(self, 1, 0, 0);
			}
			if (PedWepz == 9)
			{
				if (weathint == 0) { SET_WEATHER(0, 0); weathint2 = 0; }
				if (weathint == 1) { SET_WEATHER(1, 0); weathint2 = 1; }
				if (weathint == 2) { SET_WEATHER(2, 0); weathint2 = 2; }
				if (weathint == 3) { SET_WEATHER(3, 0); weathint2 = 3; SET_RAIN_AMOUNT((RAND_FLOAT_RANGE(0.0f, 10000.0f) / 10000.0f)); SET_LIGHTNING_AMOUNT((RAND_FLOAT_RANGE(0.0f, 100.0f) / 10000.0f)); AUDIO_PLAY_DISTANT_THUNDER(); }
				if (weathint == 4) { SET_WEATHER(4, 0); weathint2 = 4; SET_RAIN_AMOUNT((RAND_FLOAT_RANGE(0.0f, 10000.0f) / 10000.0f)); SET_LIGHTNING_AMOUNT((RAND_FLOAT_RANGE(0.0f, 100.0f) / 10000.0f)); AUDIO_PLAY_DISTANT_THUNDER(); }
				if (weathint == 5) { SET_WEATHER(5, 0); weathint2 = 5; }
				if (weathint == 6) { SET_WEATHER(12, 0); weathint2 = 12; }
				if (weathint == 7) { SET_WEATHER(13, 0); weathint2 = 13; }
				if (weathint == 8) { SET_WEATHER(14, 0); weathint2 = 14; }
				if (weathint == 9) { SET_WEATHER(15, 0); weathint2 = 15; }
				if (weathint == 10) { SET_WEATHER(16, 0); weathint2 = 16; }
				if (weathint == 11) { SET_WEATHER(17, 0); weathint2 = 17; }
				if (weathint == 12) { SET_WEATHER(6, 0); weathint2 = 6; }
				if (weathint == 13) { SET_WEATHER(7, 0); weathint2 = 7; }
				if (weathint == 14) { SET_WEATHER(8, 0); weathint2 = 8; }
				if (weathint == 15) { SET_WEATHER(9, 0); weathint2 = 9; }
				if (weathint == 16) { SET_WEATHER(10, 0); weathint2 = 10; }
				if (weathint == 17) { SET_WEATHER(11, 0); weathint2 = 11; }
				if (weathint == 18) { SET_WEATHER(18, 0); weathint2 = 18; }
				if (weathint == 19) { SET_WEATHER(19, 0); weathint2 = 19; }
				if (weathint == 20) { SET_WEATHER(20, 0); weathint2 = 20; }
				if (weathint == 21) { SET_WEATHER(21, 0); weathint2 = 21; }
				if (weathint == 22) { SET_WEATHER(22, 0); weathint2 = 22; }
				SET_TIME_OF_DAY(GET_TIME_OF_DAY());
			}
			if (PedWepz == 10)
			{
				if (mspz == 0) { SpawnHorse(999); }
				if (mspz == 1) { SpawnHorse(1003); }
				if (mspz == 2) { SpawnHorse(1269); }
				if (mspz == 3) { SpawnHorse(1268); }
				if (mspz == 4) { SpawnHorse(1271); }
				if (mspz == 5) { SpawnHorse(1270); }
				if (mspz == 6) { SpawnHorse(1267); }
				if (mspz == 7) { SpawnHorse(1248); }
				if (mspz == 8) { SpawnHorse(1249); }
				if (mspz == 9) { SpawnHorse(1250); }
				if (mspz == 10) { SpawnHorse(1251); }
				if (mspz == 11) { SpawnHorse(994); }
				if (mspz == 12) { SpawnHorse(995); }
				if (mspz == 13) { SpawnHorse(976); }
				if (mspz == 14) { SpawnHorse(977); }
				if (mspz == 15) { SpawnHorse(978); }
				if (mspz == 16) { SpawnHorse(979); }
				if (mspz == 17) { SpawnHorse(980); }
				if (mspz == 18) { SpawnHorse(981); }
				if (mspz == 19) { SpawnHorse(982); }
				if (mspz == 20) { SpawnHorse(983); }
				if (mspz == 21) { SpawnHorse(984); }
				if (mspz == 22) { SpawnHorse(985); }
				if (mspz == 23) { SpawnHorse(986); }
				if (mspz == 24) { SpawnHorse(987); }
				if (mspz == 25) { SpawnHorse(988); }
				if (mspz == 26) { SpawnHorse(989); }
				if (mspz == 27) { SpawnHorse(990); }
				if (mspz == 28) { SpawnHorse(991); }
				if (mspz == 29) { SpawnHorse(992); }
				if (mspz == 30) { SpawnHorse(993); }
				if (mspz == 31) { SpawnHorse(996); }
				if (mspz == 32) { SpawnHorse(997); }
				if (mspz == 33) { SpawnHorse(998); }
				if (mspz == 34) { SpawnHorse(1000); }
				if (mspz == 35) { SpawnHorse(1001); }
				if (mspz == 36) { SpawnHorse(1002); }
				if (mspz == 37) { SpawnHorse(1004); ACCESSORIZE_HORSE(GET_MOUNT(self), 8); }
				if (mspz == 38) { SpawnHorse(1005); ACCESSORIZE_HORSE(GET_MOUNT(self), 8); }
				if (mspz == 39) { SpawnHorse(1012); }
				if (mspz == 40) { SpawnHorse(1013); }
				if (mspz == 41) { SpawnHorse(1014); }
				if (mspz == 42) { SpawnHorse(1006); ACCESSORIZE_HORSE(GET_MOUNT(self), 8); }
				if (mspz == 43) { SpawnHorse(1007); ACCESSORIZE_HORSE(GET_MOUNT(self), 8); }
				if (mspz == 44) { SpawnHorse(1008); }
				if (mspz == 45) { SpawnHorse(1009); }
				if (mspz == 46) { SpawnHorse(1010); }
				if (mspz == 47) { SpawnHorse(1011); }
			}
			if (PedWepz == 14)
			{
				if (muit == 0) { DESTROY_OBJECT(testwtf); DESTROY_OBJECTSET(testwtf2); DESTROY_OBJECT(deafx2); DESTROY_OBJECTSET(deafx); DESTROY_OBJECT(war2); DESTROY_OBJECT(war4); DESTROY_OBJECT(war6); DESTROY_OBJECT(war8); DESTROY_OBJECT(war10); DESTROY_OBJECT(war12); DESTROY_OBJECT(war14); DESTROY_OBJECT(war16); DESTROY_OBJECT(war18); DESTROY_OBJECTSET(war1); DESTROY_OBJECTSET(war3); DESTROY_OBJECTSET(war4); DESTROY_OBJECTSET(war7); DESTROY_OBJECTSET(war9); DESTROY_OBJECTSET(war11); DESTROY_OBJECTSET(war13); DESTROY_OBJECTSET(war15); DESTROY_OBJECTSET(war17); REMOVE_HORSE_ACCESSORY(GET_MOUNT(self), 1); REMOVE_HORSE_ACCESSORY(GET_MOUNT(self), 2); REMOVE_HORSE_ACCESSORY(GET_MOUNT(self), 3); REMOVE_HORSE_ACCESSORY(GET_MOUNT(self), 4); REMOVE_HORSE_ACCESSORY(GET_MOUNT(self), 5); REMOVE_HORSE_ACCESSORY(GET_MOUNT(self), 6); REMOVE_HORSE_ACCESSORY(GET_MOUNT(self), 7); REMOVE_HORSE_ACCESSORY(GET_MOUNT(self), 8); }
				if (muit == 1) { REMOVE_HORSE_ACCESSORY(GET_MOUNT(self), 4); ACCESSORIZE_HORSE(GET_MOUNT(self), 3); }
				if (muit == 2) { REMOVE_HORSE_ACCESSORY(GET_MOUNT(self), 3); ACCESSORIZE_HORSE(GET_MOUNT(self), 4); }
				if (muit == 3) { ACCESSORIZE_HORSE(GET_MOUNT(self), 1); }
				if (muit == 4) { REMOVE_HORSE_ACCESSORY(GET_MOUNT(self), 8); ACCESSORIZE_HORSE(GET_MOUNT(self), 7); }
				if (muit == 5) { REMOVE_HORSE_ACCESSORY(GET_MOUNT(self), 7); ACCESSORIZE_HORSE(GET_MOUNT(self), 8); }
				if (muit == 6) { HorseFx(0.0f, -0.5f, -0.75, "script_unicorn_rainbow"); }//for some reason it's not setting right, however looks okay.
				if (muit == 7) { HorseFxDea(0, 0, 0, 0.0f, -0.5, -0.75, "script_4Horsemen_death_01", "script_4Horsemen_death_02"); }
				if (muit == 8) { HorseFx(0, 0, 0, "script_4Horsemen_famine_01"); }
				if (muit == 9) { HorseFx(0, 0, 0, "script_4Horsemen_pestilence_01"); }//missing a few blood drip fx types but it's fineeeee
				if (muit == 10) { HorseFxWar("script_4Horsemen_war_01", "script_4Horsemen_war_blaze"); }
				if (muit == 11) { HorseFxWar("script_4Horsemen_war_01", "weap_torch_flame_blueFire"); }//blue war fx, this obviously is not a real undead horse fx, just one I whipped together
			}
			if (PedWepz == 18)
			{
				char CusScriptPath[255];
				stradd_s(CusScriptPath, "scripting/");
				stradd_s(CusScriptPath, INT_TO_STRING(Cscript));
				LaunchCS(Cscript, CusScriptPath);
			}
			if (PedWepz == 19)
			{
				if (QModel == 0) { ChangeModel(self, 61); }
				if (QModel == 1) { ChangeModel(self, 551); }
				if (QModel == 2) { ChangeModel(self, 1222); }
				if (QModel == 3) { ChangeModel(self, 638); }
				if (QModel == 4) { ChangeModel(self, 786); }
				if (QModel == 5) { ChangeModel(self, 620); }
				if (QModel == 6) { ChangeModel(self, 604); }
				if (QModel == 7) { ChangeModel(self, 619); }
				if (QModel == 8) { ChangeModel(self, 630); }
				if (QModel == 9) { ChangeModel(self, 349); }
				if (QModel == 10) { ChangeModel(self, 118); }
			}
			if (PedWepz == 20)
			{
				if (selectorz == 0)
				{
					if (zombi == 0) { SpawnItzPedz(1222); }
					if (zombi == 1) { SpawnItzPedz(1214); }
					if (zombi == 2) { SpawnItzPedz(1204); }
					if (zombi == 3) { SpawnItzPedz(542); }
					if (zombi == 4) { SpawnItzPedz(543); }
					if (zombi == 5) { SpawnItzPedz(1252); }
					if (zombi == 6) { SpawnItzPedz(1253); }
					if (zombi == 7) { SpawnItzPedz(1254); }
				}
				if (selectorz == 1)
				{
					if (workz == 0) { SpawnItzPedz(80); }
					if (workz == 1) { SpawnItzPedz(81); }
					if (workz == 2) { SpawnItzPedz(86); }
					if (workz == 3) { SpawnItzPedz(93); }
					if (workz == 4) { SpawnItzPedz(96); }
					if (workz == 5) { SpawnItzPedz(64); }
					if (workz == 6) { SpawnItzPedz(180); }
					if (workz == 7) { SpawnItzPedz(108); }
				}
				if (selectorz == 2)
				{
					if (gangz == 0) { SpawnItzPedz(476); }
					if (gangz == 1) { SpawnItzPedz(485); }
					if (gangz == 2) { SpawnItzPedz(495); }
					if (gangz == 3) { SpawnItzPedz(504); }
					if (gangz == 4) { SpawnItzPedz(512); }
					if (gangz == 5) { SpawnItzPedz(529); }
					if (gangz == 6) { SpawnItzPedz(539); }
				}
				if (selectorz == 3)
				{
					if (lawz == 0) { SpawnItzPedz(424); }
					if (lawz == 1) { SpawnItzPedz(426); }
					if (lawz == 2) { SpawnItzPedz(439); }
					if (lawz == 3) { SpawnItzPedz(450); }
					if (lawz == 4) { SpawnItzPedz(453); }
					if (lawz == 5) { SpawnItzPedz(455); }
					if (lawz == 6) { SpawnItzPedz(463); }
					if (lawz == 7) { SpawnItzPedz(184); }
				}
				if (selectorz == 4)
				{
					if (prostz == 0) { SpawnItzPedz(66); }
					if (prostz == 1) { SpawnItzPedz(69); }
					if (prostz == 2) { SpawnItzPedz(72); }
					if (prostz == 3) { SpawnItzPedz(691); }
					if (prostz == 4) { SpawnItzPedz(692); }
					if (prostz == 5) { SpawnItzPedz(696); }
					if (prostz == 6) { SpawnItzPedz(695); }
				}
				if (selectorz == 5)
				{
					if (animalzz == 0) { SpawnItzPedz(1102); }
					if (animalzz == 1) { SpawnItzPedz(1047); }
					if (animalzz == 2) { SpawnItzPedz(1109); }
					if (animalzz == 3) { SpawnItzPedz(1247); }
					if (animalzz == 4) { SpawnItzPedz(1244); }
					if (animalzz == 5) { SpawnItzPedz(1072); }
					if (animalzz == 6) { SpawnItzPedz(1116); }
					if (animalzz == 7) { SpawnItzPedz(1058); }
				}
				if (selectorz == 6)
				{
					if (miscz == 0) { SpawnItzPedz(786); }
					if (miscz == 1) { SpawnItzPedz(118); }
					if (miscz == 2) { SpawnItzPedz(349); }
					if (miscz == 3) { SpawnItzPedz(638); }
					if (miscz == 4) { SpawnItzPedz(189); }
					if (miscz == 5) { SpawnItzPedz(61); }
					if (miscz == 6) { SpawnItzPedz(630); }
				}
			}
			if (PedWepz == 21)
			{
				if (GET_ACTOR_ENUM(self) == 0 || GET_ACTOR_ENUM(self) == 1)
				{
					_SET_ACTOR_ENUM_VARIATION(self, jtest1);
					// this global has a diff index but does change the outfit for gamesave saving
					// However it only saves actual outfits to the save and not special outfits that arent choosable outfits in game, like john hurt outfits etc.
					// If people want it i'll have a diff outfit editor for gamesave saving but pointless due to unlock outfits mod in the menu...
					//setGlobalAtIndex(42826, jtest1);
					//WAIT(1000);
					//HUD_FADE_IN(1.0f, 1065353216);
				}
				else
				{
					print2("Must Be Player Model ID 0/1", 4000);
				}
			}
			if (PedWepz == 23)
			{
				SpawnItzPedz(pedname);
				for (int i = 0; i <= 9; i++)
				{
					SET_OBJECT_ORIENTATION(SpawnPed[i], 0, 0, 0);
				}
			}
			if (PedWepz == 24)
			{
				ChangeModel(self, modelname);
			}
			if (PedWepz == 25)
			{
				SET_TIME_OF_DAY(MAKE_TIME_OF_DAY(todg, 0, 0));
			}
			if (PedWepz == 28)
			{
				char videoname[256];
				strcpy(videoname, "game:/", 255);
				stradd(videoname, INT_TO_STRING(cusvideo), 255);
				stradd(videoname, ".bk2", 255);
				if (_IS_WORLD_MOVIE_PLAYING())//hack to fix stuff in the case of player playing another movie while one is playing
				{
					_STOP_WORLD_MOVIE();
				}
				if (cusvideo2 == 0)
				{
					TeleportActor(-2072.0f, 19.05f, 2645.06f);
					SET_ACTOR_HEADING(self, -132.06f, 1);
					WaitForWorldToLoad(1);
				}
				if (cusvideo2 == 1)
				{
					TeleportActor(735.07f, 78.3f, 1289.05f);
					SET_ACTOR_HEADING(self, 87.0f, 1);
					WaitForWorldToLoad(1);
					print2("Loading theater interior", 3000);
					WAIT(3000);
					TeleportActor(712.0f, 79.0f, 1289.05f);
					SET_ACTOR_HEADING(self, 87.0f, 1);
					WaitForWorldToLoad(1);
				}
				if (cusvideo != 11 && cusvideo != 12)_START_WORLD_MOVIE(videoname, cusvideo2);
				if (cusvideo == 11)_START_WORLD_MOVIE("game:/arm00.bk2", cusvideo2);
				if (cusvideo == 12)_START_WORLD_MOVIE("game:/blk00.bk2", cusvideo2);
			}
			if (PedWepz == 29)
			{
				AUDIO_MUSIC_SUSPEND(1000);
				AUDIO_MUSIC_ONE_SHOT(Plsong[songIndex], 0, 0, 0, 0, 0);
			}
			if (PedWepz == 31)
			{
				AI_QUICK_EXIT_GRINGO(self, 1);
				DESTROY_OBJECT(uVar5);
				TASK_CLEAR(self);
				STREAMING_EVICT_GRINGO(animID);
				PlayerUseGringo(AnimChar[Animint]);
			}
			if (PedWepz == 33)
			{
				if (consume != 79 && consume != 80)
				{
					//give max count of item
					for (int m = 0; m <= 256; m++)
					{
						ADD_ITEM(SS_GET_STRING(1, consume), self, 0);
					}
				}
				if (consume == 79)GIVE_ITEMS();//give all safe items
				if (consume == 80)
				{
					for (int i = 0; i < 100; i++)//deletes individual items 1 at a time
					{
						for (int m = 0; m <= 256; m++)//deletes max count of items
						{
							DELETE_ITEM(SS_GET_STRING(1, i), self, 0);
						}
					}
				}
			}
			if (PedWepz == 34)
			{
				if (proved != 146 && proved != 147)
				{
					// this gives one of each individual item + give max count for the item
					for (int m = 0; m <= 256; m++)
					{
						ADD_COLLECTABLE(Provisions[proved], self, 0);
					}
				}
				if (proved == 146)GIVE_UNDEADPRO();//give all safe items
				if (proved == 147)
				{
					for (int i = 0; i < 147; i++)//deletes individual items 1 at a time
					{
						for (int m = 0; m <= 256; m++)//deletes max count of items
						{
							REMOVE_COLLECTABLE(Provisions[i], self);
						}
					}
				}
			}
			if (PedWepz == 40)
			{
				if (pedtask == 0)
				{
					PedzFollow = false; StandStillFucker = !StandStillFucker; if (!StandStillFucker) { for (int i = 0; i <= 9; i++) { if (IS_ACTOR_VALID(SpawnPed[i])) { ACTOR_RESET_ANIMS(SpawnPed[i], 1); TASK_CLEAR(SpawnPed[i]); SET_ACTOR_IS_THE_BEASTMASTER(self, 0); } } }
				}
				if (pedtask == 1)
				{
					StandStillFucker = false; PedzFollow = !PedzFollow; if (!PedzFollow) { for (int i = 0; i <= 9; i++) { if (IS_ACTOR_VALID(SpawnPed[i])) { ACTOR_RESET_ANIMS(SpawnPed[i], 1); TASK_CLEAR(SpawnPed[i]); SET_ACTOR_IS_THE_BEASTMASTER(self, 0); } } }
				}
				if (pedtask == 2)
				{
					CLEAR_LAST_ATTACK(self); CLEAR_LAST_HIT(self); BGPAI2 = !BGPAI2; if (!BGPAI2) FixBG();
				}
				if (pedtask == 3)
				{
					PedCrip = !PedCrip;
					if (!PedCrip) { for (int i = 0; i <= 9; i++) { if (IS_ACTOR_VALID(SpawnPed[i])) { SET_CRIPPLE_ENABLE(SpawnPed[i], 0); SET_CRIPPLE_FLAG(SpawnPed[i], 0); } } }
					if (PedCrip) { for (int i = 0; i <= 9; i++) { if (IS_ACTOR_VALID(SpawnPed[i])) { SET_CRIPPLE_ENABLE(SpawnPed[i], 1); SET_CRIPPLE_FLAG(SpawnPed[i], 1); } } }
				}
				if (pedtask == 4)
				{
					ZombifyPeds();
				}
			}
			if (PedWepz == 99)//for testing
			{
				//ADD_COLLECTABLE(Provisions[troph], self, 0);
			}
		}
		if (GetButton(BUTTON_B))
		{
			ToggleSpoof13 = false;
			EnableThat = true;
			HUD_CLEAR_HELP_QUEUE();
			//WAIT(1000); may have to add back????
			DisplayMenu();
		}
	}
}
void TeleportWaypoint()
{
	//unlike ps3 and xbox, we have to do some weird things to make sure our vector3 never gets changed so we manually save it in this loop.
	vector3 positionWP2, savedwaypointpos;
	GET_POSITION(self, &waypointpos1);
	GET_USER_DEFINED_WAYPOINT(&positionWP2);
	positionWP2.y = 360.0f;//hack to make work due to switch bs
	savedwaypointpos.x = positionWP2.x;
	savedwaypointpos.z = positionWP2.z;
	if (positionWP2.x != 0.0f && positionWP2.y != 0.0f && positionWP2.z != 0.0f) //If waypoint isn't set or has been removed
	{
		positionWP2.y = 360.0f;
		TELEPORT_ACTOR(self, &positionWP2, 1, 1, 1);
		WaitForWorldToLoad(true);
		Time timer2 = GET_CURRENT_GAME_TIME();

		while (!IS_ACTOR_ON_GROUND(self))
		{
			if (GET_CURRENT_GAME_TIME() > (timer2 + 12.0f))
			{
				//If we don't reach the ground after all this time, means we are below the map, break and teleport to old position.
				TeleportActor2(self, waypointpos1);
				print2("Failed", 2000);
				return;
			}
			positionWP2.y -= 5;
			savedwaypointpos.y = positionWP2.y;
			TELEPORT_ACTOR(self, &savedwaypointpos, 1, 1, 1);
			WAIT(0);
		}
		print2("Teleported to waypoint", 2000);
	}
}
void SetMountHorse()
{
	if (IS_ACTOR_RIDING(self) && CurrentMount >= 976 && CurrentMount <= 1014 || IS_ACTOR_RIDING(self) && CurrentMount >= 1248 && CurrentMount <= 1251 || IS_ACTOR_RIDING(self) && CurrentMount >= 1267 && CurrentMount <= 1271)
	{
		setGlobalAtIndex(21473, CurrentMount);
		print2("Mount Saved\nSave Game Now.", 15000);
	}
}
void ResetVehicle()
{
	if (IS_ACTOR_VALID(GET_VEHICLE(self)))
	{
		int VehID = GET_ACTOR_ENUM(GET_VEHICLE(self));
		for (int i = 0; i <= 3; i++)
		{
			if (IS_ACTOR_VALID(GET_DRAFT_ACTOR(i, GET_VEHICLE(self))))DESTROY_ACTOR(GET_DRAFT_ACTOR(i, GET_VEHICLE(self)));
			if (IS_ACTOR_VALID(SpawnDra[i]))DESTROY_ACTOR(SpawnDra[i]);
		}
		int DraftCount = _GET_NUM_DRAFT_SLOTS(SpawnCar1);
		DraftCount -= 1;
		if (VehID != 1181 && VehID != 1189 && VehID != 1190 && VehID != 1191 && VehID != 1192 && VehID != 1193 && VehID != 1194)
		{
			for (int i = 0; i <= DraftCount; i++)
			{
				SpawnDra[i] = CreateActor(979);
				ATTACH_DRAFT_TO_VEHICLE(SpawnDra[i], GET_VEHICLE(self), i, 1);
				_ACCESORIZE_VEHICLE_HORSES(GET_VEHICLE(self), 5);
			}
		}
		float fakehead4 = GET_OBJECT_HEADING(GET_GAME_CAMERA());
		SET_ACTOR_HEADING(GET_VEHICLE(self), fakehead4, 1);
	}
}
void SetFreeCamera()//thanks for fixing this on switch foxxyyy!
{
	float camX = 0.0f, camY = 0.0f;
	vector3 camPos, camDirection;
	Camera cam = CREATE_CAMERA_IN_LAYOUT(GET_AMBIENT_LAYOUT(), "", 0);

	INIT_CAMERA_FROM_GAME_CAMERA(cam);
	SET_CURRENT_CAMERA_ON_CHANNEL(cam, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	GET_CAMERA_POSITION(cam, &camPos);
	print2("Press <y> to stop the <green>free camera!</green> \n Press <x> to teleport to <orange>cam position</orange>", 10000);

	while (!IS_BUTTON_PRESSED(0, BUTTON_Y, 1, 0))
	{
		SET_PLAYER_CONTROL(0, 0, 0, 0);

		float xStickLeft = GET_STICK_X(0, 0, 0);
		float yStickLeft = GET_STICK_Y(0, 0, 0);
		float xStickRight = GET_STICK_X(0, 1, 0);
		float yStickRight = GET_STICK_Y(0, 1, 0);

		GET_CAMERA_POSITION(cam, &camPos);
		GET_CAMERA_DIRECTION(cam, &camDirection);

		//Switch version has to be done this way... vectors assignment doesn't seems to work...
		float x = camPos.x;
		float y = camPos.y;
		float z = camPos.z;

		if (yStickLeft < -0.2f)
		{
			x += (camDirection.x * yStickLeft);
			y += (camDirection.y * yStickLeft);
			z += (camDirection.z * yStickLeft);
		}
		if (yStickLeft > 0.2f)
		{
			x += (camDirection.x * yStickLeft);
			y += (camDirection.y * yStickLeft);
			z += (camDirection.z * yStickLeft);
		}
		if (xStickLeft < -0.2f)
		{
			x += (COS_DEGREE(camY) * xStickLeft);
			z += (SIN_DEGREE((camY - 180.0f)) * xStickLeft);
		}
		if (xStickLeft > 0.2f)
		{
			x -= (COS_DEGREE((camY - 180.0f)) * xStickLeft);
			z -= (SIN_DEGREE(camY) * xStickLeft);
		}

		if ((yStickRight < -0.2f) || (yStickRight > 0.2f))
			if ((yStickRight > 0.2f && (camX > -50.0f)) || (yStickRight < -0.2f && (camX < 50.0f))) //Y Axis security
				camX += (yStickRight * -5.0f);
		if ((xStickRight > 0.2f) || (xStickRight < -0.2f))
			camY += (xStickRight * -5.0f);

		camPos.x = x;
		camPos.y = y;
		camPos.z = z;
		camDirection.x = camX;
		camDirection.y = camY;
		camDirection.z = 0.0f;

		SET_CAMERA_POSITION(cam, camPos);//redo native
		SET_CAMERA_ORIENTATION(cam, camDirection, 0);//redo native

		if (IS_BUTTON_PRESSED(0, BUTTON_X, 1, 0))
		{
			TeleportActor(camPos.x, camPos.y, camPos.z);
		}
		WAIT(0);
	}
	REMOVE_CAMERA_FROM_CHANNEL(cam, 0);
	DESTROY_CAMERA(cam);
	CAMERA_RESET(0);
	SET_PLAYER_CONTROL(0, 1, 0, 0);
	SET_CAMERA_FOLLOW_ACTOR(self);
}
void Looped_Functions()
{
	if (tpwp)
	{
		vector3 positionWP3;
		GET_USER_DEFINED_WAYPOINT(&positionWP3);
		positionWP3.y = 360.0f;//hack to make work
		if (positionWP3.x != 0.0f && positionWP3.y != 0.0f && positionWP3.z != 0.0f) //If waypoint isn't set or has been removed
		{
			TeleportWaypoint();
		}
	}
	if (IS_ACTOR_VALID(GET_ACTORS_HORSE(self)))SET_ACTOR_RIDEABLE(GET_ACTORS_HORSE(self), 1);//make sure our mount is always rideable at all times! (mostly cow fixes if players arent using template files)
	MainLRSwitches();
	if (aimbott)//more so a Aim Killbot, rather than aimbot bleh w.e
	{
		vector3 headpos;
		GET_OBJECT_NAMED_BONE_POSITION(GET_ACTOR_UNDER_RETICLE(self, 1), "head", &headpos);
		if (GetButtonDown(BUTTON_LT))
		{
			if (IS_ACTOR_VALID(GET_ACTOR_UNDER_RETICLE(self, 1)))
			{
				FIRE_PROJECTILE(self, PROJECTILE_BASE_SNIPERRIFLE, 3, &headpos, &headpos);
			}
		}
	}
	AIOBools();
	if (Cannonwep)
	{
		GET_POSITION(self, &canpos);
		canpos.y = -25.0f;
		SET_OBJECT_POSITION(WTFCAN, canpos);
	}
}