#include "menuUtils.h"
#define self GET_PLAYER_ACTOR(0)
#define CurrentMount GET_ACTOR_ENUM(GET_MOUNT(self))

//some of this is unused will clean up later.
//code is a hot mess, have fun looking at it ;)
//I'm a very messy coder, get over it lol.
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
int pedint2 = 0;
int cusvideo = 1;
int cusvideo2 = 0;
int weathint2;
int animID;
int Animint = 0;
int uVar5;//gringo object
bool stoploot;
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
int troph = 1, consume = 69, proved = 107;//test
bool Fireround;
bool Slugz;
bool SuperJump;
int jtest1;
int pedcomp = 0;
bool ClearDE;
bool BlueDE;
bool RedDE;
int DEColorSwap;
int DETog = 0;
int DELvl = 0;
int DETime = 0;
bool AntiRagDoll2;
bool tpwp;
int mornstar = 0, ranchbarn = 0, marshouse = 0, policestat = 0, bankflr = 0, anthro = 0, ridgefarm = 0, campoburn = 0, miltcamp = 0, cavdr = 0, villadoor = 0, gravstn = 0, bridgebroke = 0;
static int cutsceneIndex = 0;
static int songIndex = 0;
Iterator animalridez1, animalridez2, animalridez3;
char* QuickM[] = { "Nun01", "Bonnie", "Young Jack", "NakedGuy", "NakedGirl", "Paperboy", "MirandaFortuna", "DeadDutch", "MysteryGuy", "HerbertMoon" };
char* NAChar[] = { "Armadillo", "MacFarlanes Ranch", "Tumbleweed", "Fort Mercer", "Gaptooth Breach", "Twin Rocks", "Plainview", "Rathskeller Fork", "Ridgewood Farm", "Thieves' Landing", "Benedict Point", "Lake Don Julio", "Coot's Chapel", "Pike's Basin" };
char* WEChar[] = { "Blackwater","Cochinay", "Beechers Hope", "Manzanita Post", "Pacific Union RR", "Aurora Basin", "Serendipitys Wreck" };
char* MTChar[] = { "Escalera", "Chuparosa", "Las Hermanas", "Tesoro Azul", "El Presidio", "Casa Madrugada", "Nosalida", "El Matadero", "Agave Viejo", "Torquemada", "Rancho Polvo", "Manteca Falls", "Campo Mirada" };
char* HIChar[] = { "Macfarlane House", "Armadillo Theatre", "Armadillo Saloon Room 1", "Armadillo Saloon Room 2", "Thieves' Landing Mystery", "Blackwater Jail", "Blackwater Butcher", "Blackwater Theatre", "Blackwater Hotel Room", "Blackwater Anthropology", "Blackwater Restaurant", "Blackwater Bank", "Blackwater Poker Room", "Blackwater Barn", "Marston House", "Escalera Room 1", "Escalera Room 2", "Escalera Room 3", "Escalera Villa Room", "Hermanas Church 1", "Hermanas Church 2", "Chuparosa Marstons Room", "Chuparosa Bank Vault" };
char* OoMChar[] = { "Outfitter", "Snowy Mountain", "Wasteland1", "Wasteland2", "Wasteland3", "MexicoValley" };
char* WTChar[] = { "Clear", "Fair", "Cloudy", "Rainy", "Stormy", "Snowy", "Cave", "Thieves", "Forest", "Location A", "Location B", "Location C", "Interior Clear", "Interior Fair", "Interior Cloudy", "Interior Rainy", "Interior Stormy", "Interior Snowy", "Interior Thieves", "Interior Forest", "Interior Location A", "Interior Location B", "Interior Location C" };
char* MSChar[] = { "Dead Horse", "Zebra Donkey", "Generic Zombie Horse", "Stallion", "Regular Horse", "Cleveland Bay", "Painted Quarter Horse", "Kentucky Saddler", "American Standardbred", "Standardbred Pinto", "Painted Standardbred", "Hungarian Halfbred", "Highland Chestnut", "Quarter Horse", "Welsh Mountain", "Dutch Warmblood", "Turkmen", "Tobiano Pinto", "Lusitano", "Ardennais", "Tersk", "War Horse", "Dark Horse", "Lusitano Nag", "Infested Ardennais", "Jaded Tersk", "El Senor", "El Hedor", "El Picor", "Buffalo", "Albino Buffalo", "Bull", "Bessy", "Ferdinand", "Bonzo Bull", "Super Bull", "Brown Cow", "Cow1", "Cow2", "Cow3" };
char* MAChar[] = { "Remove Accessories", "Black Saddle", "Brown Saddle", "Harness", "Black Rein", "Brown Rein" };
char* VSChar[] = { "Stagecoach1", "Stagecoach2", "Stagecoach3", "Stagecoach4", "DLCVeh", "GatWagon", "Cart1", "Cart2", "Cart3", "Cart4", "Cart5", "Cart6", "Canoe", "Raft2", "Raft3", "Raft1", "Truck", "Car", "Wagon4", "Wagon5", "PrisonWagon", "DickensElixir1", "Wagon2", "Chuckwagon1", "Chuckwagon2", "DickensElixir2" };
char* LectChar[] = { "Workers", "Gang", "Law", "Prostitues", "Animals", "Misc" };
char* WorkChar[] = { "BankTeller", "Bartender", "Blacksmith", "Businessman", "DocksWorker", "Nurse", "Musician", "FactoryWorker" };
char* GangChar[] = { "IndianRaider", "CattleRustler", "DrunkNDirty", "Bandito", "CrazyMiner", "MexRebel", "Luisa" };
char* LawChar[] = { "TownPosse1", "TownPosse3", "SheriffTux", "USMarshall2", "USMarshall5", "PuebloPosse", "CorruptOfficial", "Police1" };
char* ProstChar[] = { "Pros2", "Pros5", "Pros11", "MexPros", "BlackPros", "CaucasionPros", "AsianPros" };
char* AniChar[] = { "Bear", "Husky Dog", "Elk", "Zombie Cougar", "Wolf", "Buck", "Snake" };
char* MiscChar[] = { "NakedGuy", "HerbertMoon", "MysteryMan", "YoungJack", "Preacher", "Nun", "DeadDutch" };
char* INTLoadChar[] = { "Blackwater Morning Star", "MacFarlanes Barn", "Marston House", "Blackwater Police Station", "Blackwater Bank", "Blackwater Anthropology", "Ridgewood Farm", "Campo Mirada", "Torquemada Military Camp", "El Matadero Cave Door", "Escalera Villa Door", "Beechers Hope Graves", "Bridges" };
char* PPPChar[] = { "FX_Deadeye.ppp", "UI_Pause.ppp", "MP_ShowdownBlueTeam.ppp" };
char* AnimChar[] = { "alerted_rifle_right", "angrymob", "angrymob_torch", "anthro01_struggle", "any_craftBasket", "arm_wrestling", "bandito_beatup", "banker_hostage", "Bar_lean_stand", "bar_stand", "begging", "bench_chair", "bench_stool", "binoc_pickup", "blacksmith", "Blacksmith_chopwood", "blow_the_hatch", "body_left_for_dead_loop", "book_shelf", "browse_table_low",  "campfire_talk", "CampfireTreasureHunter", "Cannibal_fam_clue_search", "car_wash", "chair_pot_smash", "chair_sit", "chair_sit_newspaper", "chair_sit_sleep_attach", "chair_sit_table_read", "cheer_on_seat", "chop_chicken", "chop_fish", "clean_rifle", "cooking", "cower", "crazy_poking", "crying_linked", "cs_fbi04_taunt01", "cs_tumbleweed_getup", "digging", "dog_fetch", "door_kick_all_weapon", "door_kick_rifle", "door_locked", "drink_from_barrel", "drinking", "drunk_react", "duck_hunt", "dynamite_AI_controlled", "dynamite_table", "factory_foreman", "factory_lathe", "factory_lumber_stacker", "factory_shovel_coal", "fake_blackjack_dealer", "fake_FiveFingerFillet", "fbi02_cs03_b", "fbi04_wounded_01", "fbi04_wounded_02", "fbi04_wounded_03", "feed_chickens", "fema_stir_cauldron", "firesquad_heldback", "firesquad_shove", "fix_car", "flirting_whore", "Flower_search", "free_bonnie", "frustrated_racer", "furnace", "get_drunk", "Giveaway_Footlocker", "grave01_door_open", "Grave03_Seth_idle", "grave_robber_attack", "grind_corn", "gun01_drunk", "hammering", "Herbalist_sitting", "hold_door_closed", "hostage_kneel", "hostage_shaky", "hostage_sit_loop", "Indian_Sit_Ground", "Indian_Sit_Ground_Smoke", "Intro01_v", "item_bait", "item_bottle", "jake_read", "kick_door", "kick_hogtied_victim", "kneel_hammer", "knl_hoe_soil", "knl_watertrough", "landon_smoking", "lean_fence_back", "lean_fence_H_talking", "lean_fence_L", "lean_rail", "lean_rail_drink", "lean_rail_whore", "lean_table", "lie_sleep_on_bed", "lie_sleep_on_bed_l", "lie_sleep_on_bed_r", "light_candle", "light_candle_multi", "locked_door", "locked_gate", "look_around_corner", "look_distance_binocs", "look_out_window_L", "look_out_window_R", "Loot_Corpse", "loot_corpse_solo_female", "loot_corpse_solo_male", "loot_solo_loop", "luisamomloop", "man_behind_bars", "man_in_prison", "Marshal04_deathpose1", "Marshal04_deathpose2", "Marshal04_deathpose3", "Marshal04_deathpose4", "Marshal04_deathpose5", "Marshal04_deathpose6", "Marshal04_farmer_deathpose", "Marshal04_femfarmer_deathpose", "Marshal04_laborer_deathpose", "Marshal04_wife_deathpose", "merchant02_idle", "merchant_lay_bed", "mex_blacksmith", "mex_cartVendor", "mex_craftBasket", "mex_cry_overBody", "mex_dusting_maid", "mex_eat_apple", "mex_flirt_sit_link", "mex_flirt_sit_stool_attached_link","mex_leanwall", "mex_peerOut_window", "mex_pickGarbage", "mex_playGuitar", "mex_prayer_oldWoman", "mex_sitGround", "mex_sitGround_link_loop", "mex_sleepBed_l", "mex_sleepBed_r", "mex_stool_sit", "mex_table_service", "mex_tableService_bartender", "mex_talking_soldiers_link", "mex_towerGuard", "mex_washCloths", "mexs_doorknock", "milk_cow", "mourn_dead_body", "Mourn_loop", "mourn_suicide", "MP_ignite_bomb", "mp_rig_tnt","multistage_hoe", "multistage_lumber", "multistage_sweeping", "multistage_torch", "musician_wife_idle", "nastas_sack", "NPC_BuryDynamite", "NPC_Lockpicking_Door", "npc_open_safe", "oldf_pray", "open_big_door", "open_crate_ambient", "open_credenza", "open_vault_door", "opium_pipe", "organize_shelf", "organize_wagon", "outhouse", "pan_gold", "panic_female", "Pee", "pistol_whip", "pitch_hay", "player_detonator", "Player_DropDynamite", "player_pickup_hat", "player_sit_movie", "player_sleep_gun_left", "player_sleep_gun_right", "player_sleep_tent", "player_smoking_lean", "pole_hostage", "preaching", "preaching_at_podium", "Prostitute_bed", "ranch04_reflect", "ranch08_close1", "ranch08_close2", "Rand_Idle_NearWall_nospawn", "Rand_Idle_NearWall_Shoulder_L", "Rand_Idle_NearWall_Shoulder_R", "Rand_Idle_Sit_Ground_Bad", "rand_idle_stand", "rand_idle_stand_nospawn", "RCM23_kneel_idle", "RCM_01_CS01_JebIdle", "RCM_02_CS01_Books", "RCM_03_CS02_Water_sweeping", "RCM_04_CS03_Musician", "RCM_05_CS03_CryingIdle", "RCM_05_CS04_CannibalIdle", "RCM_05_CS05_cannibal_link", "RCM_11_CS03_preacher", "RCM_12_CS02_PotStir", "RCM_12_CS03_fix_wing", "RCM_13_CS01_Jenny", "RCM_14_CS01_Lean_letter", "RCM_14_CS02_sleepChair", "RCM_15_CS04_NunIdle", "RCM_15_CS05_MysteryMan", "RCM_16_CS02_NunIdle", "RCM_17_CS01_Mackenna", "RCM_17_CS02_Spatchcock", "RCM_17_CS03_Mackenna", "RCM_20_CS01_clara_pray", "RCM_20_CS02_richman_bar", "RCM_20_CS03_clara_pray", "RCM_23_CS01_Basilio", "RCM_32_CS01_Agent", "RCM_Abandoned", "RCM_AztecGold_Treasure", "RCM_horse_love_A", "RCM_Horse_Love_B", "reb03_detach_train", "reb05_struggle2", "rebel02_cs02_v", "rebel_cheer_pistol", "rebel_cheer_rifle", "rebel_riot01", "rebel_riot02", "rebel_riot03", "reload_slow", "reyes_frees_marston", "reyes_saves", "ricketts_tnt_crates", "ring_bell", "riverwash", "rockclimbing", "saved_by_reyes", "searching", "searching_box", "shaky_chair", "shaky_cover", "shaky_idle", "sharpen_axe", "shopkeep", "shopkeep_bartender", "shopkeeper_return", "shotgun_boss", "sit_barrel", "Sit_BlackJack", "sit_camp_coffee_drink", "sit_chair_comfy", "sit_chair_couch", "sit_chr_dsk_letr", "sit_chr_dsk_wrk", "sit_church", "sit_cleanknife", "sit_cleanpistol", "sit_cleanrifle", "sit_cut_meat", "sit_docks", "sit_drinkbrandy_s_any", "sit_eat_dinner", "sit_embroidery_e_any", "sit_fence_low", "sit_fence_nospawn", "sit_flirt_couch_link", "Sit_Ground_Campfire_Tend", "Sit_Ground_Drink", "Sit_Ground_Only", "Sit_Ground_Play_Cards", "sit_ground_play_guitar", "sit_ground_play_harmonica", "sit_ground_smoke", "Sit_Ground_Smoke_Pipe", "sit_headinhands_n_any", "sit_key_twirling", "sit_no_table", "sit_piano_w_piano", "sit_picknose_e_any", "sit_sleepinchair_n_any", "sit_sleeponbench_n_any", "sit_smokepipe_e_any", "sit_yawning_n_any", "skin_scraper", "sleeping", "sleeping_chair_scripted", "sleeping_wall_scripted", "smoker_idle", "smoking_lean", "smoking_stand", "soldier_banging_on_door", "son_crouchGetup", "SpatchCock_idle", "spittoon", "spyGlass", "stand_adjuststocking_w_whore", "stand_announce", "stand_armoir", "stand_bar_drink", "stand_bar_need_drink", "stand_bartender_bar_work", "stand_bartender_pour", "stand_check_clipboard", "stand_cheer", "stand_chop_door", "stand_chopveggies_w_any", "stand_cleanwindow_w_any", "stand_cupboard", "stand_dnd_rowdydrink", "stand_drunk_dancing_link", "stand_drunkdancing_e_any", "stand_eat_fruit", "stand_fiddle_w_fiddle", "stand_guntricks_e_any", "stand_hammer_table", "stand_hammer_wall", "stand_hammerground_w_any", "stand_holy_water", "stand_key_twirling", "stand_kneelvomit_n_any", "stand_knock_on_door", "stand_lookdistance_w_any", "stand_makebed_w_any", "stand_minerock_w_any", "stand_open_chest", "stand_paint", "stand_peeing_b_any", "stand_pocketwatch_e_any", "stand_read", "stand_reprimand", "stand_sellPaper", "stand_shove", "stand_smokelean_e_any", "stand_spit", "stand_stirringpot_w_any", "stand_sweeping_w_any", "stand_taunt_far", "stand_taunt_near", "stand_telegraph", "stand_torch", "stand_washfacebowl_n_any", "stand_waterpump", "stand_whore_dancing", "stand_worried_n_any", "stand_wring_hands", "stand_yelling", "stand_yelling_down", "stand_yelling_mid", "stand_yelling_up", "stool_sit_newspaper", "TES_CoverIntro_Player", "TES_CoverIntro_Sheriff", "thanks", "ticket_taker_link", "train_boarding", "train_climb_left", "train_climb_right", "train_engineer", "twin_rocks_dad", "undertaker_measure", "US_talking_soldiers_link", "wait_at_door", "wall_phone", "wash_basin", "watch_idle", "wave_flag", "weeping", "whittle_wood", "whore_flirt", "wilderness_drunk_A", "wilderness_drunk_B", "window_shopping" };
char* Provisions[] = { "sn_a1_m", "sn_a1_c", "sn_b1_w", "sn_b2_m", "sn_b2_c", "sn_b2_f", "sn_b2_t", "sn_b3_m", "sn_b3_f", "sn_b4_m", "sn_t_9", "sn_t_8", "sn_t_7", "sn_t_6", "sn_t_5", "sn_t_4", "sn_t_3", "sn_t_2", "sn_t_1", "sn_h_wo", "sn_h_wf", "sn_h_vs", "sn_h_rs", "sn_h_po", "sn_h_pp", "sn_h_hs", "sn_h_gc", "sn_h_ds", "sn_h_bw", "sn_h2_s", "sn_h2_m", "sn_m1_h", "sn_m1_m", "sn_c5_m", "sn_d3_f", "sn_d3_m", "sn_c5_h", "sn_g3_f", "sn_w1_h", "sn_w1_p", "sn_w1_m", "sn_v_f", "sn_sb_f", "sn_s3_s", "sn_s2_f", "sn_s2_m", "sn_s1_s", "sn_s1_m", "sn_r2_f", "sn_r2_m", "sn_r1_m", "sn_p1_m", "sn_o1_f", "sn_nb_h", "sn_nb_s", "sn_nb_t", "sn_nb_m", "sn_xc_h", "sn_xc_f", "sn_xc_p", "sn_xc_m", "sn_xb_f", "sn_xb_h", "sn_xb_c", "sn_xb_t", "sn_xb_m", "sn_xw_f", "sn_xw_h", "sn_xw_m", "sn_h1_f", "sn_g2_h", "sn_g2_f", "sn_g2_t", "sn_g2_c", "sn_g2_m", "sn_g1_m", "sn_f1_f", "sn_f1_m", "sn_e2_s", "sn_e2_a", "sn_e2_m", "sn_e1_f", "sn_d2_f", "sn_d1_s", "sn_d1_m", "sn_c4_f", "sn_c3_p", "sn_c3_m", "sn_c2_p", "sn_c2_f", "sn_c2_c", "sn_c2_m", "sn_c1_f", "sn_b8_s", "sn_b8_h", "sn_b8_m", "sn_b7_s", "sn_b7_a", "sn_b7_m", "sn_b6_f", "sn_b6_c", "sn_b6_m", "sn_b5_t", "sn_b5_s", "sn_b5_m", "sn_b4_s", "sn_b4_h" };
//0-32
char* Plsong[] = { "home01_stereo_song", "ross_endcredits_stereo_song", "endcredits_stereo_song", "fort02_stereo_song", "ftr_beat_complete_song_01", "ftr_beat_fail_song_01", "ftr_bounty_hunter_complete_song_01", "ftr_bounty_hunter_fail_song_01", "ftr_job_complete_song_01", "ftr_job_fail_song_01", "ftr_mission_complete_song_01", "ftr_mission_fail_song_01", "ftr_outfit_complete_song_01", "ftr_purchase_property_song_01", "ftr_rcm_complete_song_01", "ftr_rcm_fail_song_01", "ftr_song_01", "ftr_song_02", "ftr_song_03", "ftr_song_04", "ftr_song_05", "ftr_song_06", "ftr_song_07", "ftr_song_08", "ftr_song_09", "mex_song_01", "nrt_beat_complete_song_01", "nrt_song_01", "nrt_song_02", "nrt_song_03", "nrt_song_04", "nrt_song_05", "nrt_song_06" };
//Cutscene player might eventually be its own script due to compiler issues. Just left it in as a taste, Made By ImFoxxyyy, I gotta map the other cutscenes out...
char* CUscene[] = { "Exodus in America", "New Friends, Old Problems", "Obstacles in Our Path", "This is Armadillo, USA", "Women and Cattle", "Wild Horses, Tamed Passions", "A Tempest Looms", "The Burning", "Political Realities in Armadillo", "Justice in Pike's Basin", "Spare the Rod, Spoil the Bandit", "Hanging Bonnie MacFarlane", "The Assault on Fort Mercer" };
//List of all cutscenes of all missions (not finished)
static char* missionCutscenes[13][6] = {
	{ "$/cutscene/intro_sequence_1/intro_sequence_1", "$/cutscene/intro_sequence_2/intro_sequence_2", "$/cutscene/intro_sequence_3/intro_sequence_3", "$/cutscene/intro_01/intro_01", "$/cutscene/intro_b_seq/intro_b_seq", nullstr },
	{ "$/cutscene/ranch_01/ranch_01", "$/cutscene/ranch_01_end/ranch_01_end", nullstr, nullstr, nullstr, nullstr },
	{ "$/cutscene/r3/r3", "$/cutscene/ranch03_cs03/ranch03_cs03", nullstr, nullstr, nullstr, nullstr }, //r3 = mission 3
	{ "$/cutscene/r2/r2", "$/cutscene/ranch02_cs02/ranch02_cs02", "$/cutscene/ranch02_end/ranch02_end", nullstr, nullstr, nullstr },
	{ "$/cutscene/r7/r7", "$/cutscene/r7_end/r7_end", nullstr, nullstr, nullstr, nullstr },
	{ "$/cutscene/r6/r6", "$/cutscene/ranch_06_cs03/ranch_06_cs03", "$/cutscene/ranch06_cs05/ranch06_cs05", nullstr, nullstr, nullstr },
	{ "$/cutscene/r8/r8", nullstr, nullstr, nullstr, nullstr, nullstr },
	{ "$/cutscene/r4/r4", "$/cutscene/ranch04_cs02/ranch04_cs02", "$/cutscene/r4_end/r4_end", nullstr, nullstr, nullstr },
	{ "$/cutscene/m1/m1", "$/cutscene/marshal01_cs02/marshal01_cs02", "$/cutscene/marshal01_cs03/marshal01_cs03", "$/cutscene/marshal01_cs04/marshal01_cs04", nullstr, nullstr },
	{ "$/cutscene/m2/m2", "$/cutscene/marshal02_end_seq/marshal02_end_seq", nullstr, nullstr, nullstr, nullstr },
	{ "$/cutscene/m4/m4", "$/cutscene/marshal04_cs0a/marshal04_cs0a", "$/cutscene/marshal04_cs02_seq/marshal04_cs02_seq", "$/cutscene/marshal04_cs03/marshal04_cs03", "$/cutscene/marshal04_cs05_seq/marshal04_cs05_seq", "$/cutscene/marshal04_cs06/marshal04_cs06" },
	{ "$/cutscene/m3/m3", "$/cutscene/marshal03_cs02/marshal03_cs02", "$/cutscene/marshal03_cs03_pt3/marshal03_cs03_pt3", nullstr, nullstr, nullstr },
	{ "$/cutscene/fort_01/fort_01", "$/cutscene/fort01_warwagon_climb/fort01_warwagon_climb", "$/cutscene/fort_01_cs03_seq/fort_01_cs03_seq", "$/cutscene/fort01_cs06/fort01_cs06", "$/cutscene/fort01_cs07/fort01_cs07", nullstr },
};

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
bool cutsceneRunning;
void CheckToEndCutscene()
{
	if (IS_BUTTON_PRESSED(0, BUTTON_A, 0, 0) || CUTSCENE_MANAGER_IS_CUTSCENE_FINISHED())
	{
		CUTSCENE_MANAGER_STOP_CUTSCENE(1, 1);
		CUTSCENE_MANAGER_UNLOAD_CUTSCENE();
		STREAMING_SET_CUTSCENE_MODE(false);
		ENABLE_USE_CONTEXTS(true);
		CAMERA_RESET(0);
		UI_EXIT("LoadingScreen");
		UI_POP("FadeToBlack");
		HUD_FADE_IN(1.0f, 1065353216);
		HUD_CLEAR_OBJECTIVE_QUEUE();
		cutsceneRunning = false;
	}
}
void LoadCutscene(char* cutscene)
{
	if (DECOR_CHECK_EXIST(self, "globalcutloadscreen"))
	{
		DECOR_REMOVE(self, "globalcutloadscreen");
	}

	CUTSCENE_MANAGER_LOAD_CUTSCENE(cutscene, 0, 1, 1, 1, 2);
	STREAMING_SET_CUTSCENE_MODE(true);
	ENABLE_USE_CONTEXTS(false);
	CUTSCENE_MANAGER_PLAY_CUTSCENE();
	CUTSCENE_MANAGER_SET_SKIP_UI_STACK_POP(0);

	//FuncCleanUp(); //Close the menu so it doesn't run in the background
	cutsceneRunning = true;
}
void SetCutscene(int index)
{
	vector3 pos;
	GET_POSITION(self, &pos);

	//Most missions contain multiple cutscenes, we're going to load each, yes there is a lot!
	for (int i = 0; i < 6; i++)
	{
		while (cutsceneRunning)
		{
			CheckToEndCutscene();
			WAIT(0);
		}

		if (!CUTSCENE_MANAGER_DOES_CUTSCENE_EXIST(missionCutscenes[index][i]))
			continue;

		WAIT(2000); //Giving time for the game
		LoadCutscene(missionCutscenes[index][i]);
	}

	//We just loaded the last cutscene, we now need to stop it when its finished/user has clicked A
	//Otherwise we might be stuck in the loading screen forever...
	while (cutsceneRunning)
	{
		CheckToEndCutscene();
		WAIT(0);
	}

	//Better use this in-case we finish a cutscene straight in a fight, like in Tumbleweed for example...
	WAIT(1500);
	TeleportActor2(self, pos);
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
	SUSPEND_MOVER(self);
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
unsafe void BountyINC()
{
	__getGlobalP(40000);
	__getImm(12);
	__getGlobalP(40060);
	__getArray(1);
	__push(500);
	__add();
	__getGlobalP(40000);
	__getImm(12);
	__getGlobalP(40060);
	__setArray(1);
	__getGlobalP(40000);
	__getImm(12);
	__getGlobalP(40060);
	__addImm(4428);
	__getArray(1);
	__getGlobalP(54086);
	__getArray(1);
	__push(500);
	__callNative(0x67116627, 1, 1);
	__addF();
	__getGlobalP(40000);
	__getImm(12);
	__getGlobalP(40060);
	__addImm(4428);
	__getArray(1);
	__getGlobalP(54086);
	__setArray(1);
	__push(222);
	__getGlobalP(54086);
	__getArray(1);
	__push(500);
	__callNative(0x67116627, 1, 1);
	__addF();
	__push(222);
	__getGlobalP(54086);
	__setArray(1);
}
unsafe void ClearBountyStat()
{
	__push(0);
	__getGlobalP(40000);
	__getImm(12);//8
	__getGlobalP(40060);
	__setArray(1);
	__push(0);
	__callNative(0x67116627, 1, 1);
	__getGlobalP(40000);
	__getImm(12);
	__getGlobalP(40060);
	__addImm(4428);//2220
	__getArray(1);
	__getGlobalP(54086);
	__setArray(1);
	__push(0);
	__getGlobalP(40060);
	__setImm(1988);//2212
	__push(0);
	__push(3);
	__push(11);
	__getGlobalP(40000);
	__getImm(12);//8
	__getGlobalP(40060);
	__addImm(68);//36
	__getArrayP(181);
	__getArrayP(5);
	__setArray(1);
}
void CLEAR_BOUNTY()
{
	//ClearBountyStat();
	if (getGlobalAtIndex(6646) != 0)
	{
		setGlobalAtIndex(6646, 0);
		setGlobalAtIndex(6648, 0);
		if (IS_FACTION_VALID(getGlobalAtIndex(40000)))
		{
			_SET_FACTION_STATUS_TWO_WAY(getGlobalAtIndex(40000), 2, 2);
		}
		_SET_FACTION_STATUS_TWO_WAY(8, 2, 2);
		_SET_FACTION_STATUS_TWO_WAY(10, 2, 2);
		//none of this really seems to be needed??
		//int* ptr = getGlobalPtrAtIndex(39922);
		//int script1 = *(ptr + 96 * 4);
		//int script2 = *(ptr + 104 * 4);
		//if (IS_SCRIPT_VALID(script1))
		//{
		//	TERMINATE_SCRIPT(script1);
		//}
		//if (IS_SCRIPT_VALID(script2))
		//{
		//	TERMINATE_SCRIPT(script2);
		//}
		//setGlobalAtIndex(6621, -1);
		RELEASE_LAYOUT_OBJECTS(getGlobalAtIndex(39918));
	}
}
unsafe void ENABLE_LAW(int lawID)
{
	__getFrame(0);
	__getGlobalP(39922);
	__setImm(22);
}

unsafe int lawreturn()
{
	__getGlobalP(39922);
	__getImm(22);
	return __popI();
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
	WAIT(500);//delay to make sure we are fully swapped in
	for (int i = 0; i <= 100; i++)
	{
		if (i != 29 && i != 30)//exploded head types (prob only for undead?)
		{
			if (ACTOR_HAS_VARIABLE_MESH(self, i))
			{
				if (!ACTOR_IS_VARIABLE_MESH_ENABLED(self, i))
				{
					ACTOR_ENABLE_VARIABLE_MESH(self, i, 1);
				}
			}
		}
	}
	if (GET_ACTOR_ENUM(self) == 0 || GET_ACTOR_ENUM(self) == 1)//prob need to add checks for dead john, player clones, and cutscene john model but meh
	{
		EQUIP_ACCESSORY(self, 1, 0); ACTOR_ENABLE_VARIABLE_MESH(self, 26, 0);//disabling bandanna because we dont need that if we are swapping to john or jack outright
	}
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
	WAIT(300);//small delay to make sure the ped is loaded in!
	for (int j = 0; j <= 100; j++)
	{
		if (j != 29 && j != 30)//exploded head types(prob just undead?)
		{
			if (ACTOR_HAS_VARIABLE_MESH(SpawnPed[pedint2], j))
			{
				if (!ACTOR_IS_VARIABLE_MESH_ENABLED(SpawnPed[pedint2], j))
				{
					ACTOR_ENABLE_VARIABLE_MESH(SpawnPed[pedint2], j, 1);
				}
			}
		}
	}
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
	if (stoploot)
	{
		//stop animations for corpse looting, feather looting, animal skinning
		if (ACTOR_HAS_ANIM_SET(self, "skinning") || ACTOR_HAS_ANIM_SET(self, "loot_corpse") || ACTOR_HAS_ANIM_SET(self, "loot_corpse_solo_female") || ACTOR_HAS_ANIM_SET(self, "loot_corpse_solo_male") || ACTOR_HAS_ANIM_SET(self, "skin_scraper"))
		{
			ACTOR_RESET_ANIMS(self, 1);
		}
		//can't seem to skip herb picking anim, as it refuses to give you any herb after the fact.
		//if (ACTOR_HAS_ANIM_SET(self, "picking_herbs"))
		//{
		//	WAIT(1000);
		//	ACTOR_RESET_ANIMS(self, 1);
		//}
	}
	if (AnimalBypassON)
	{
		RideAbleAnimalsV3();
	}
	if (NoWanted)
	{
		ENABLE_LAW(512);//disables law
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
	if (BGPAI2)
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
unsafe void FHSelect()//UNUSED, doesnt fully work, just spoofs the fame/honor and not actually setting to gamesave
{
	__push(10000);
	__callNative(0x67116627, 1, 1);
	__push(3);
	__getGlobalP(54086);//updated
	__setArray(1);
	__pushString("sr_ntr6");
	__push(4);
	__getGlobalP(55480);//updated
	__getArrayP(16);//20
	__addImm(32);//16
	__strCopy(32);
	__push(5);
	__getGlobalP(21369);//updated
	__setImm(248);
	WAIT(1000);
	__push(60536);
	__callNative(0x67116627, 1, 1);
	__push(3);
	__getGlobalP(54086);//updated
	__setArray(1);
	__pushString("sr_hnr1");
	__push(2);
	__getGlobalP(55480);//updated
	__getArrayP(16);//20
	__addImm(32);//16
	__strCopy(32);
	__push(0);
	__getGlobalP(21369);//updated
	__setImm(248);
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
		thatweapon = 28; print2("Cannon", 2000); specialW = 0;
		WTFCAN = CreateObject("p_gen_cannon02x");
	}
	ACTOR_HOLSTER_WEAPON(GET_PLAYER_ACTOR(0), thatweapon);
	ACTOR_SET_NEXT_WEAPON(GET_PLAYER_ACTOR(0), thatweapon);
	GIVE_WEAPON_TO_ACTOR(GET_PLAYER_ACTOR(0), thatweapon, 0, 0, 0);
	ACTOR_SET_NEXT_WEAPON(GET_PLAYER_ACTOR(0), thatweapon);
}
void GIVE_ITEMS()
{
	//need to re-do for real hardware support in the future, not a priority rn. On real hardware this softlocks for 20-30 seconds due to it trying to give invalid items, ez fix tho
	for (int items = 0; items <= 68; items++)//100
	{
		for (int m = 0; m <= 256; m++)//this gives max count of current item
		{
			ADD_ITEM(SS_GET_STRING(1, items), self, 0);
		}
	}
}
void GIVE_NORMALPRO()
{
	for (int i = 0; i < 108; i++)
	{
		for (int m = 0; m <= 256; m++)//this gives max count of current item
		{
			ADD_COLLECTABLE(Provisions[i], self, 0);
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
		//const char* glow;
		if (PedWepz == 1)
		{
			stradd_s(modmsg, "Peds Weapon Editor\n<x>:Confirm\n<cancel>:Cancel\n<dpadleftright>:Weapon:<orange> ");
			if (wepzint == 21 || wepzint == 30)stradd_s(modmsg, "BLOCKED WEP");
			if (wepzint == 25)stradd_s(modmsg, "Throwing Knife");
			if (wepzint == 29)stradd_s(modmsg, "Tomahawk");
			if (wepzint == 32)stradd_s(modmsg, "Remove Weapons");
			if (wepzint != 21 && wepzint != 25 && wepzint != 29 && wepzint != 30 && wepzint != 32)stradd_s(modmsg, UI_GET_STRING(GET_WEAPON_DISPLAY_NAME(wepzint)));
		}
		if (PedWepz == 3)
		{
			stradd_s(modmsg, "Vehicle Spawner\n<x>:Confirm\n<cancel>:Cancel\n<dpadleftright>:Vehicle:<orange> ");
			stradd_s(modmsg, VSChar[vehintz2]);
		}
		if (PedWepz == 4)
		{
			stradd_s(modmsg, "New Austin Teleports\n<x>:Confirm\n<cancel>:Cancel\n<dpadleftright>:Teleport:<orange> ");
			stradd_s(modmsg, NAChar[austel]);
		}
		if (PedWepz == 5)
		{
			stradd_s(modmsg, "West Elizabeth Teleports\n<x>:Confirm\n<cancel>:Cancel\n<dpadleftright>:Teleport:<orange> ");
			stradd_s(modmsg, WEChar[westeli]);
		}
		if (PedWepz == 6)
		{
			stradd_s(modmsg, "Mexico Teleports\n<x>:Confirm\n<cancel>:Cancel\n<dpadleftright>:Teleport:<orange> ");
			stradd_s(modmsg, MTChar[mextel]);
		}
		if (PedWepz == 7)
		{
			stradd_s(modmsg, "Special Teleports\n<x>:Confirm\n<cancel>:Cancel\n<dpadleftright>:Teleport:<orange> ");
			stradd_s(modmsg, HIChar[hidint]);
		}
		if (PedWepz == 8)
		{
			stradd_s(modmsg, "Out of Map Teleports\n<x>:Confirm\n<cancel>:Cancel\n<dpadleftright>:Teleport:<orange> ");
			stradd_s(modmsg, OoMChar[outmapz]);
		}
		if (PedWepz == 9)
		{
			stradd_s(modmsg, "Weather Types\n<x>:Confirm\n<cancel>:Cancel\n<dpadleftright>:Weather:<orange> ");
			stradd_s(modmsg, WTChar[weathint]);
		}
		if (PedWepz == 10)
		{
			stradd_s(modmsg, "Mount Spawner\n<x>:Confirm\n<cancel>:Cancel\n<dpadleftright>:Mount:<orange> ");
			stradd_s(modmsg, MSChar[mspz]);
		}
		if (PedWepz == 14)
		{
			stradd_s(modmsg, "Mount Accessory Editor\n<x>:Confirm\n<cancel>:Cancel\n<dpadleftright>:Accessory:<orange> ");
			stradd_s(modmsg, MAChar[muit]);
		}
		if (PedWepz == 18)
		{
			stradd_s(modmsg, "Script Loader\n<x>:Confirm\n<cancel>:Cancel\n<y>:Terminate All\n<lb>:Script Info\n<dpadleftright>:Script To Load:<orange> ");
			stradd_s(modmsg, INT_TO_STRING(Cscript));
			if (GetButton(BUTTON_LB))
			{
				print2("<orange>Scripts Go In /content/release64/scripting/</orange> \n <blue>Name As 1-10</blue> \n <green>Example: 1.wsc</green> \nUse MagicRDR To Import Scripts", 7000);
			}
		}
		if (PedWepz == 19)
		{
			stradd_s(modmsg, "Quick Model\n<x>:Confirm\n<cancel>:Cancel\n<dpadleftright>:Model:<orange> ");
			stradd_s(modmsg, QuickM[QModel]);
		}
		if (PedWepz == 20)
		{
			stradd_s(modmsg, "Quick Ped Spawner\n<x>:Confirm\n<cancel>:Cancel\n<dpadupdown>:Ped Class:<red> ");
			stradd_s(modmsg, LectChar[selectorz]);
			stradd_s(modmsg, "\n</red><dpadleftright>:Ped:<blue> ");
			if (selectorz == 0)stradd_s(modmsg, WorkChar[workz]);
			if (selectorz == 1)stradd_s(modmsg, GangChar[gangz]);
			if (selectorz == 2)stradd_s(modmsg, LawChar[lawz]);
			if (selectorz == 3)stradd_s(modmsg, ProstChar[prostz]);
			if (selectorz == 4)stradd_s(modmsg, AniChar[animalzz]);
			if (selectorz == 5)stradd_s(modmsg, MiscChar[miscz]);
		}
		if (PedWepz == 21)
		{
			stradd_s(modmsg, "Outfit Editor\n<x>:Confirm\n<cancel>:Cancel\n<y>:Toggle Hat\n<rb>:Toggle Bandana\n<dpadleftright>:John/Jack Outfit:<orange> ");
			stradd_s(modmsg, INT_TO_STRING(jtest1));
		}
		if (PedWepz == 23)
		{
			stradd_s(modmsg, "Ped Spawner\n<x>:Confirm\n<cancel>:Cancel\n<dpadleftright>:Ped ID:<orange> ");
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
			stradd_s(modmsg, "Model Changer\n<x>:Confirm\n<cancel>:Cancel\n<dpadleftright>:Model ID:<orange> ");
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
			stradd_s(modmsg, "Time Editor\n<x>:Confirm\n<cancel>:Cancel\n<dpadleftright>:Time:<orange> ");
			stradd_s(modmsg, INT_TO_STRING(todg));
		}
		if (PedWepz == 27)
		{
			stradd_s(modmsg, "Cutscene Player\n<x>:Confirm\n<cancel>:Cancel\n<cancel>Cancel Cutscene\n<dpadleftright>:Cutscene:<orange> ");
			stradd_s(modmsg, CUscene[cutsceneIndex]);
		}
		if (PedWepz == 28)
		{
			stradd_s(modmsg, "Movie Player\n<x>:Confirm\n<cancel>:Cancel\n<y>:Stop Video\n<rb>:Theater:<orange> ");
			if (cusvideo2 == 0)stradd_s(modmsg, "Armadillo\n");
			if (cusvideo2 == 1)stradd_s(modmsg, "Blackwater\n");
			stradd_s(modmsg, "</orange><dpadleftright>:Video:<orange> ");
			if (cusvideo == 11)stradd_s(modmsg, "arm00");
			if (cusvideo == 12)stradd_s(modmsg, "blk00");
			if (cusvideo != 11 && cusvideo != 12)stradd_s(modmsg, INT_TO_STRING(cusvideo));
		}
		if (PedWepz == 29)
		{
			stradd_s(modmsg, "Song Player\n<x>:Confirm\n<cancel>:Cancel\n<y>:Stop Song\n<dpadleftright>:Song:<orange> ");
			stradd_s(modmsg, Plsong[songIndex]);
		}
		if (PedWepz == 30)
		{
			stradd_s(modmsg, "Interior Loader\n<x>:Confirm\n<cancel>:Cancel\n<dpadleftright>:Interior/State:<orange> ");
			stradd_s(modmsg, INTLoadChar[interiorint]);
		}
		if (PedWepz == 31)
		{
			stradd_s(modmsg, "Animation Player\n<x>:Confirm\n<cancel>:Cancel\n<y>:Stop Animation\n<dpadleftright>:Animation:<orange> ");
			stradd_s(modmsg, AnimChar[Animint]);
		}
		if (PedWepz == 32)
		{
			stradd_s(modmsg, "Wanted Editor\n<x>:Confirm\n<cancel>:Cancel\n<dpadleftright>:Edit:<orange> ");
			if (bountedit == 0 && NoWanted)stradd_s(modmsg, "Disable Law</orange>: <green>ON");
			if (bountedit == 0 && !NoWanted)stradd_s(modmsg, "Disable Law</orange>: <red>OFF");
			if (bountedit == 1)stradd_s(modmsg, "Increase Bounty");
			if (bountedit == 2)stradd_s(modmsg, "Clear Bounty");
		}
		if (PedWepz == 33)
		{
			stradd_s(modmsg, "Consumables Editor\n<x>:Confirm\n<y>:Remove Item\n<cancel>:Cancel\n<dpadleftright>:Consumable/Kit:<orange> ");
			if (consume == 66)stradd_s(modmsg, "--NOT DEFINED--");
			if (consume != 66 && consume != 69 && consume != 70)stradd_s(modmsg, UI_GET_STRING(SS_GET_STRING(1, consume)));
			if (consume == 69)stradd_s(modmsg, "Give All");
			if (consume == 70)stradd_s(modmsg, "Remove All");
		}
		if (PedWepz == 34)
		{
			stradd_s(modmsg, "Provisions Editor\n<x>:Confirm\n<y>:Remove Item\n<cancel>:Cancel\n<dpadleftright>:Provision:<orange> ");
			if (proved != 107 && proved != 108)stradd_s(modmsg, UI_GET_STRING(Provisions[proved]));
			if (proved == 107)stradd_s(modmsg, "Give All");
			if (proved == 108)stradd_s(modmsg, "Remove All");
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
		}
		if (PedWepz == 41)
		{
			stradd_s(modmsg, "Component Editor\n<x>:Enable\n<y>:Disable\n<cancel>:Cancel\n<dpadleftright>:Component ID:<orange> ");
			stradd_s(modmsg, INT_TO_STRING(pedcomp));
			stradd_s(modmsg, "\nSome components are force disabled by the game (only fix is to loop them always on and that's not really ideal...)");
			// so this is kinda hard to explain as Idk what to really call this mod func.
			// Basically this can enable/disable some body parts if the model has a mesh that controls a bodypart as being active or inactive
			// it can also enable/disable some attachments such as bandanas, bullet shells, gloves, hair, bonnets, bandoliers, gun holsters etc.
			// but this varies ped model to ped model and the ids can be random on what they control
			// some id's are force disabled and by what is unknown to me, so like if you enable it, the game will force it back off (I self assume for good reason but honestly idk why)
		}
		if (PedWepz == 99)//test switch function
		{
			//stradd_s(modmsg, "Test\n<x>:Confirm\n<cancel>:Cancel\n<dpadleftright>:Blah<orange> ");
			//stradd_s(modmsg, INT_TO_STRING(troph));
			//stradd_s(modmsg, "\n");
			//stradd_s(modmsg, UI_GET_STRING(Provisions[troph]));
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
				if (mspz < 0) mspz = 39;
			}
			if (PedWepz == 14)
			{
				muit--;
				if (muit < 0) muit = 5;
			}
			if (PedWepz == 18)
			{
				Cscript--;
				if (Cscript < 1) Cscript = 10;
			}
			if (PedWepz == 19)
			{
				QModel--;
				if (QModel < 0) QModel = 9;
			}
			if (PedWepz == 20)
			{
				if (selectorz == 0)
				{
					workz--;
					if (workz < 0) workz = 7;
				}
				if (selectorz == 1)
				{
					gangz--;
					if (gangz < 0) gangz = 6;
				}
				if (selectorz == 2)
				{
					lawz--;
					if (lawz < 0) lawz = 7;
				}
				if (selectorz == 3)
				{
					prostz--;
					if (prostz < 0) prostz = 6;
				}
				if (selectorz == 4)
				{
					animalzz--;
					if (animalzz < 0) animalzz = 6;
				}
				if (selectorz == 5)
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
			if (PedWepz == 27)
			{
				cutsceneIndex--;
				if (cutsceneIndex < 0) cutsceneIndex = 12;
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
			if (PedWepz == 30)
			{
				interiorint--;
				if (interiorint < 0) interiorint = 12;
			}
			if (PedWepz == 32)
			{
				bountedit--;
				if (bountedit < 0) bountedit = 2;
			}
			if (PedWepz == 33)
			{
				consume--;
				if (consume < 0) consume = 70;
			}
			if (PedWepz == 34)
			{
				proved--;
				if (proved < 0) proved = 108;
			}
			if (PedWepz == 40)
			{
				pedtask--;
				if (pedtask < 0) pedtask = 3;
			}
			if (PedWepz == 41)
			{
				pedcomp--;
				if (pedcomp < 0) pedcomp = 31;
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
				if (mspz > 39) mspz = 0;
			}
			if (PedWepz == 14)
			{
				muit++;
				if (muit > 5) muit = 0;
			}
			if (PedWepz == 18)
			{
				Cscript++;
				if (Cscript > 10) Cscript = 1;
			}
			if (PedWepz == 19)
			{
				QModel++;
				if (QModel > 9) QModel = 0;
			}
			if (PedWepz == 20)
			{
				if (selectorz == 0)
				{
					workz++;
					if (workz > 7) workz = 0;
				}
				if (selectorz == 1)
				{
					gangz++;
					if (gangz > 6) gangz = 0;
				}
				if (selectorz == 2)
				{
					lawz++;
					if (lawz > 7) lawz = 0;
				}
				if (selectorz == 3)
				{
					prostz++;
					if (prostz > 6) prostz = 0;
				}
				if (selectorz == 4)
				{
					animalzz++;
					if (animalzz > 6) animalzz = 0;
				}
				if (selectorz == 5)
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
			if (PedWepz == 27)
			{
				cutsceneIndex++;
				if (cutsceneIndex > 12) cutsceneIndex = 0;
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
			if (PedWepz == 30)
			{
				interiorint++;
				if (interiorint > 12) interiorint = 0;
			}
			if (PedWepz == 32)
			{
				bountedit++;
				if (bountedit > 2) bountedit = 0;
			}
			if (PedWepz == 33)
			{
				consume++;
				if (consume > 70) consume = 0;
			}
			if (PedWepz == 34)
			{
				proved++;
				if (proved > 108) proved = 0;
			}
			if (PedWepz == 40)
			{
				pedtask++;
				if (pedtask > 3) pedtask = 0;
			}
			if (PedWepz == 41)
			{
				pedcomp++;
				if (pedcomp > 31) pedcomp = 0;
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
				if (selectorz < 0) selectorz = 5;
			}
		}
		if (GetButton(DPAD_UP))
		{
			if (PedWepz == 20)
			{
				selectorz++;
				if (selectorz > 5) selectorz = 0;
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
				SUSPEND_MOVER(self);
				ENABLE_MOVER(self);
				//SET_MOVER_FROZEN(self, 0);
			}
			if (PedWepz == 33)
			{
				if (consume != 66 && consume != 69 && consume != 70)
				{
					for (int m = 0; m <= 256; m++)//deletes max count of items
					{
						DELETE_ITEM(SS_GET_STRING(1, consume), self, 0);
					}
				}
			}
			if (PedWepz == 34)
			{
				if (proved != 107 && proved != 108)
				{
					//removes all of this item
					for (int m = 0; m <= 256; m++)
					{
						REMOVE_COLLECTABLE(Provisions[proved], self);
					}
				}
			}
			if (PedWepz == 41)//for testing
			{
				if (ACTOR_HAS_VARIABLE_MESH(self, pedcomp))
				{
					if (ACTOR_IS_VARIABLE_MESH_ENABLED(self, pedcomp))
					{
						ACTOR_ENABLE_VARIABLE_MESH(self, pedcomp, 0);
					}
					else
						print2("Component Already Disabled", 2000);
				}
				else
					print2("Component Not Valid For Current Model", 2000);
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
				if (mspz == 2) { SpawnHorse(1251); }//generic zombie horse works in normal SP for some reason
				if (mspz == 3) { SpawnHorse(994); }
				if (mspz == 4) { SpawnHorse(995); }
				if (mspz == 5) { SpawnHorse(976); }
				if (mspz == 6) { SpawnHorse(977); }
				if (mspz == 7) { SpawnHorse(978); }
				if (mspz == 8) { SpawnHorse(979); }
				if (mspz == 9) { SpawnHorse(980); }
				if (mspz == 10) { SpawnHorse(981); }
				if (mspz == 11) { SpawnHorse(982); }
				if (mspz == 12) { SpawnHorse(983); }
				if (mspz == 13) { SpawnHorse(984); }
				if (mspz == 14) { SpawnHorse(985); }
				if (mspz == 15) { SpawnHorse(986); }
				if (mspz == 16) { SpawnHorse(987); }
				if (mspz == 17) { SpawnHorse(988); }
				if (mspz == 18) { SpawnHorse(989); }
				if (mspz == 19) { SpawnHorse(990); }
				if (mspz == 20) { SpawnHorse(991); }
				if (mspz == 21) { SpawnHorse(992); }
				if (mspz == 22) { SpawnHorse(993); }
				if (mspz == 23) { SpawnHorse(996); }
				if (mspz == 24) { SpawnHorse(997); }
				if (mspz == 25) { SpawnHorse(998); }
				if (mspz == 26) { SpawnHorse(1000); }
				if (mspz == 27) { SpawnHorse(1001); }
				if (mspz == 28) { SpawnHorse(1002); }
				if (mspz == 29) { SpawnHorse(1004); ACCESSORIZE_HORSE(GET_MOUNT(self), 8); }
				if (mspz == 30) { SpawnHorse(1005); ACCESSORIZE_HORSE(GET_MOUNT(self), 8); }
				if (mspz == 31) { SpawnHorse(1012); }
				if (mspz == 32) { SpawnHorse(1013); }
				if (mspz == 33) { SpawnHorse(1014); }
				if (mspz == 34) { SpawnHorse(1006); ACCESSORIZE_HORSE(GET_MOUNT(self), 8); }
				if (mspz == 35) { SpawnHorse(1007); ACCESSORIZE_HORSE(GET_MOUNT(self), 8); }
				if (mspz == 36) { SpawnHorse(1008); }
				if (mspz == 37) { SpawnHorse(1009); }
				if (mspz == 38) { SpawnHorse(1010); }
				if (mspz == 39) { SpawnHorse(1011); }
			}
			if (PedWepz == 14)
			{
				if (muit == 0) { REMOVE_HORSE_ACCESSORY(GET_MOUNT(self), 1); REMOVE_HORSE_ACCESSORY(GET_MOUNT(self), 2); REMOVE_HORSE_ACCESSORY(GET_MOUNT(self), 3); REMOVE_HORSE_ACCESSORY(GET_MOUNT(self), 4); REMOVE_HORSE_ACCESSORY(GET_MOUNT(self), 5); REMOVE_HORSE_ACCESSORY(GET_MOUNT(self), 6); REMOVE_HORSE_ACCESSORY(GET_MOUNT(self), 7); REMOVE_HORSE_ACCESSORY(GET_MOUNT(self), 8); }
				if (muit == 1) { REMOVE_HORSE_ACCESSORY(GET_MOUNT(self), 4); ACCESSORIZE_HORSE(GET_MOUNT(self), 3); }
				if (muit == 2) { REMOVE_HORSE_ACCESSORY(GET_MOUNT(self), 3); ACCESSORIZE_HORSE(GET_MOUNT(self), 4); }
				if (muit == 3) { ACCESSORIZE_HORSE(GET_MOUNT(self), 1); }
				if (muit == 4) { REMOVE_HORSE_ACCESSORY(GET_MOUNT(self), 8); ACCESSORIZE_HORSE(GET_MOUNT(self), 7); }
				if (muit == 5) { REMOVE_HORSE_ACCESSORY(GET_MOUNT(self), 7); ACCESSORIZE_HORSE(GET_MOUNT(self), 8); }
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
				if (QModel == 2) { ChangeModel(self, 638); }
				if (QModel == 3) { ChangeModel(self, 786); }
				if (QModel == 4) { ChangeModel(self, 620); }
				if (QModel == 5) { ChangeModel(self, 604); }
				if (QModel == 6) { ChangeModel(self, 619); }
				if (QModel == 7) { ChangeModel(self, 630); }
				if (QModel == 8) { ChangeModel(self, 349); }
				if (QModel == 9) { ChangeModel(self, 118); }
			}
			if (PedWepz == 20)
			{
				if (selectorz == 0)
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
				if (selectorz == 1)
				{
					if (gangz == 0) { SpawnItzPedz(476); }
					if (gangz == 1) { SpawnItzPedz(485); }
					if (gangz == 2) { SpawnItzPedz(495); }
					if (gangz == 3) { SpawnItzPedz(504); }
					if (gangz == 4) { SpawnItzPedz(512); }
					if (gangz == 5) { SpawnItzPedz(529); }
					if (gangz == 6) { SpawnItzPedz(539); }
				}
				if (selectorz == 2)
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
				if (selectorz == 3)
				{
					if (prostz == 0) { SpawnItzPedz(66); }
					if (prostz == 1) { SpawnItzPedz(69); }
					if (prostz == 2) { SpawnItzPedz(72); }
					if (prostz == 3) { SpawnItzPedz(691); }
					if (prostz == 4) { SpawnItzPedz(692); }
					if (prostz == 5) { SpawnItzPedz(696); }
					if (prostz == 6) { SpawnItzPedz(695); }
				}
				if (selectorz == 4)
				{
					if (animalzz == 0) { SpawnItzPedz(1102); }
					if (animalzz == 1) { SpawnItzPedz(1047); }
					if (animalzz == 2) { SpawnItzPedz(1109); }
					if (animalzz == 3) { SpawnItzPedz(1244); }
					if (animalzz == 4) { SpawnItzPedz(1072); }
					if (animalzz == 5) { SpawnItzPedz(1116); }
					if (animalzz == 6) { SpawnItzPedz(1058); }
				}
				if (selectorz == 5)
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
				int e = GET_ACTOR_ENUM(self);
				if (e == 0 || e == 1)
				{
					_SET_ACTOR_ENUM_VARIATION(self, jtest1);//just gonna test this again....
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
			if (PedWepz == 27)
			{
				SetCutscene(cutsceneIndex);
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
			if (PedWepz == 30)
			{
				if (interiorint == 0)
				{ 
					if (mornstar == 0){ENABLE_WORLD_SECTOR("morningStar"); ENABLE_CHILD_SECTOR("blk_barge01Props01x"); ENABLE_CHILD_SECTOR("blk_barge01x"); ENABLE_CHILD_SECTOR("mor_morningStar01_int_Props01x"); ENABLE_CHILD_SECTOR("mor_morningStar_int_01x"); ENABLE_CHILD_SECTOR("mor_morningStar_int_shade_01x"); print2("Enabled", 2000); mornstar = 1;}
					else if (mornstar == 1){DISABLE_WORLD_SECTOR("morningStar"); DISABLE_CHILD_SECTOR("blk_barge01Props01x"); DISABLE_CHILD_SECTOR("blk_barge01x"); DISABLE_CHILD_SECTOR("mor_morningStar01_int_Props01x"); DISABLE_CHILD_SECTOR("mor_morningStar_int_01x"); DISABLE_CHILD_SECTOR("mor_morningStar_int_shade_01x");print2("Disabled", 2000); mornstar = 0;}
				}
				if (interiorint == 1)
				{
					if (ranchbarn == 0){ENABLE_CHILD_SECTOR("hen_barn02x"); ENABLE_CHILD_SECTOR("hen_barn02props01x"); DISABLE_CHILD_SECTOR("hen_barn01x"); DISABLE_CHILD_SECTOR("hen_barn01props01x"); DISABLE_CHILD_SECTOR("hen_barn01props02x"); ENABLE_CHILD_SECTOR("hen_windmill01x"); ENABLE_CHILD_SECTOR("hen_windmill02x");print2("Burned", 2000); ranchbarn = 1;}
					else if(ranchbarn == 1){DISABLE_CHILD_SECTOR("hen_barn02x"); DISABLE_CHILD_SECTOR("hen_barn02props01x"); ENABLE_CHILD_SECTOR("hen_barn01x"); ENABLE_CHILD_SECTOR("hen_barn01props01x"); ENABLE_CHILD_SECTOR("hen_barn01props02x"); DISABLE_CHILD_SECTOR("hen_windmill01x"); DISABLE_CHILD_SECTOR("hen_windmill02x"); ENABLE_CHILD_SECTOR("hen_windmill02x"); ENABLE_CHILD_SECTOR("hen_windmill01x");print2("Normal", 2000); ranchbarn = 0;}
				}
				if (interiorint == 2)
				{
					if (marshouse == 0){ DISABLE_CHILD_SECTOR("beh_house02x"); DISABLE_CHILD_SECTOR("beh_house02props01x"); ENABLE_CHILD_SECTOR("beh_house01x"); ENABLE_CHILD_SECTOR("beh_house01props01x");;print2("Enabled", 2000); marshouse = 1;}
					else if (marshouse == 1){ENABLE_CHILD_SECTOR("beh_house02x"); ENABLE_CHILD_SECTOR("beh_house02props01x"); DISABLE_CHILD_SECTOR("beh_house01x"); DISABLE_CHILD_SECTOR("beh_house01props01x");print2("Disabled", 2000); marshouse = 0;}
				}
				if (interiorint == 3)
				{
					if (policestat == 0){ENABLE_CHILD_SECTOR("blk_policeStation_int_02x"); ENABLE_CHILD_SECTOR("blk_policeStation01_int_props02x");print2("2nd Floor Enabled", 2000); policestat = 1;}
					else if (policestat == 1){DISABLE_CHILD_SECTOR("blk_policeStation_int_02x"); DISABLE_CHILD_SECTOR("blk_policeStation01_int_props02x");print2("2nd Floor Disabled", 2000); policestat = 0;}
				}
				if (interiorint == 4)
				{
					if (bankflr == 0){ENABLE_CHILD_SECTOR("blk_bank_int_02x"); ENABLE_CHILD_SECTOR("blk_bank01_int_Props02x");print2("2nd Floor Enabled", 2000); bankflr = 1;}
					else if (bankflr == 1){DISABLE_CHILD_SECTOR("blk_bank_int_02x"); DISABLE_CHILD_SECTOR("blk_bank01_int_Props02x");print2("2nd Floor Disabled", 2000); bankflr = 0;}
				}
				if (interiorint == 5)
				{
					if (anthro == 0){ENABLE_CHILD_SECTOR("blk_archeologist01Props01x");print2("Enabled", 2000); anthro = 1;}
					else if (anthro == 1){DISABLE_CHILD_SECTOR("blk_archeologist01Props01x");print2("Disabled", 2000); anthro = 0;}
				}
				if (interiorint == 6)
				{
					if (ridgefarm == 0){ENABLE_CHILD_SECTOR("rwf_mainhouse01props02x"); DISABLE_CHILD_SECTOR("rwf_barn01xprops01x"); ENABLE_CHILD_SECTOR("rwf_barn01xprops02x"); ENABLE_CHILD_SECTOR("rwf_livingRoom01props02x"); DISABLE_CHILD_SECTOR("rwf_livingRoom01props01x");print2("Blood/Mess Enabled", 2000); ridgefarm = 1;}
					else if (ridgefarm == 1){DISABLE_CHILD_SECTOR("rwf_mainhouse01props02x"); ENABLE_CHILD_SECTOR("rwf_barn01xprops01x"); DISABLE_CHILD_SECTOR("rwf_barn01xprops02x"); DISABLE_CHILD_SECTOR("rwf_livingRoom01props02x"); ENABLE_CHILD_SECTOR("rwf_livingRoom01props01x");print2("Blood/Mess Disabled", 2000); ridgefarm = 0;}
				}
				if (interiorint == 7)
				{
					if (campoburn == 0){ENABLE_WORLD_SECTOR("campoMiradaAfter"); DISABLE_WORLD_SECTOR("campoMiradaBefore");print2("Burned", 2000); campoburn = 1;}
					else if (campoburn == 1){DISABLE_WORLD_SECTOR("campoMiradaAfter"); ENABLE_WORLD_SECTOR("campoMiradaBefore");print2("Normal", 2000); campoburn = 0;}
				}
				if (interiorint == 8)
				{
					if (miltcamp == 0){DISABLE_CHILD_SECTOR("tor_militaryCamp02x"); ENABLE_CHILD_SECTOR("tor_militaryCamp01x");print2("Enabled", 2000); miltcamp = 1;}
					else if (miltcamp == 1){ENABLE_CHILD_SECTOR("tor_militaryCamp02x"); DISABLE_CHILD_SECTOR("tor_militaryCamp01x");print2("Disabled", 2000); miltcamp = 0;}
				}
				if (interiorint == 9)
				{
					if (cavdr == 0){ENABLE_CHILD_SECTOR("emt_cavedoor01x"); DISABLE_CHILD_SECTOR("emt_cavedoor02x");print2("Destroyed", 2000); cavdr = 1;}
					else if (cavdr == 1){DISABLE_CHILD_SECTOR("emt_cavedoor01x"); ENABLE_CHILD_SECTOR("emt_cavedoor02x");print2("Normal", 2000); cavdr = 0;}
				}
				if (interiorint == 10)
				{
					if (villadoor == 0){DISABLE_CHILD_SECTOR("esc_villaWall04x"); ENABLE_CHILD_SECTOR("esc_villaWall05x");print2("Burned", 2000); villadoor = 1;}
					else if (villadoor == 1){ENABLE_CHILD_SECTOR("esc_villaWall04x"); DISABLE_CHILD_SECTOR("esc_villaWall05x");print2("Normal", 2000); villadoor = 0;}
				}
				if (interiorint == 11)
				{
					if (gravstn == 0){ENABLE_CHILD_SECTOR("beh_grave01x"); ENABLE_CHILD_SECTOR("beh_grave02x"); ENABLE_CHILD_SECTOR("beh_grave03x");print2("Enabled", 2000); gravstn = 1;}
					else if (gravstn == 1){DISABLE_CHILD_SECTOR("beh_grave02x"); DISABLE_CHILD_SECTOR("beh_grave03x"); DISABLE_CHILD_SECTOR("beh_grave01x");print2("Disabled", 2000); gravstn = 0;}}
				if (interiorint == 12)
				{
					if (bridgebroke == 0){ENABLE_WORLD_SECTOR("ramitaBayaBefore"); ENABLE_WORLD_SECTOR("butterBridgeA"); ENABLE_WORLD_SECTOR("tannersSpanBefore"); ENABLE_WORLD_SECTOR("dixonCrossingBefore"); ENABLE_WORLD_SECTOR("fronteraBridgeBefore"); ENABLE_WORLD_SECTOR("masonBridgeBefore"); DISABLE_WORLD_SECTOR("butterBridgeD"); DISABLE_WORLD_SECTOR("butterBridgeC"); DISABLE_WORLD_SECTOR("butterBridgeB"); DISABLE_WORLD_SECTOR("ramitaBayaAfter"); DISABLE_WORLD_SECTOR("tannersSpanAfter"); DISABLE_WORLD_SECTOR("dixonCrossingAfter"); DISABLE_WORLD_SECTOR("fronteraBridgeAfter"); DISABLE_WORLD_SECTOR("masonBridgeAfter");print2("Destroyed", 2000); bridgebroke = 1;}
					else if (bridgebroke == 1){DISABLE_WORLD_SECTOR("ramitaBayaBefore"); DISABLE_WORLD_SECTOR("butterBridgeA"); DISABLE_WORLD_SECTOR("tannersSpanBefore"); DISABLE_WORLD_SECTOR("dixonCrossingBefore"); DISABLE_WORLD_SECTOR("fronteraBridgeBefore"); DISABLE_WORLD_SECTOR("campoMiradaAfter"); DISABLE_WORLD_SECTOR("masonBridgeBefore"); DISABLE_WORLD_SECTOR("butterBridgeD"); DISABLE_WORLD_SECTOR("butterBridgeC"); ENABLE_WORLD_SECTOR("butterBridgeB"); ENABLE_WORLD_SECTOR("ramitaBayaAfter"); ENABLE_WORLD_SECTOR("tannersSpanAfter"); ENABLE_WORLD_SECTOR("dixonCrossingAfter"); ENABLE_WORLD_SECTOR("fronteraBridgeAfter"); ENABLE_WORLD_SECTOR("masonBridgeAfter");print2("Built", 2000); bridgebroke = 0;}
				}
			}
			if (PedWepz == 31)
			{
				AI_QUICK_EXIT_GRINGO(self, 1);
				DESTROY_OBJECT(uVar5);
				TASK_CLEAR(self);
				STREAMING_EVICT_GRINGO(animID);
				PlayerUseGringo(AnimChar[Animint]);
			}
			if (PedWepz == 32)
			{
				if (bountedit == 0)
				{
					NoWanted = !NoWanted;
					if (NoWanted)
					{
						CLEAR_BOUNTY();//clears wanted state but will keep current wanted cops active till dead
						lawID = lawreturn();//save law ID
					}
					if (!NoWanted)
					{
						ENABLE_LAW(lawID);//resetting it
					}
				}
				if (bountedit == 1)BountyINC();//on certain saves/progression this stops working and halts the menu?
				if (bountedit == 2) { ClearBountyStat(); CLEAR_BOUNTY(); }//on certain saves/progression this stops working and halts the menu?
			}
			if (PedWepz == 33)
			{
				if (consume != 66 && consume != 69 && consume != 70)
				{
					//give max count of item
					for (int m = 0; m <= 256; m++)
					{
						ADD_ITEM(SS_GET_STRING(1, consume), self, 0);
					}
				}
				if (consume == 69)GIVE_ITEMS();//give all
				if (consume == 70)
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
				if (proved != 107 && proved != 108)
				{
					// this gives one of each individual item + give max count for the item
					for (int m = 0; m <= 256; m++)
					{
						ADD_COLLECTABLE(Provisions[proved], self, 0);
					}
				}
				if (proved == 107)GIVE_NORMALPRO();//give all
				if (proved == 108)
				{
					for (int i = 0; i < 108; i++)//deletes individual items 1 at a time
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
			}
			if (PedWepz == 41)//for testing
			{
				if (ACTOR_HAS_VARIABLE_MESH(self, pedcomp))
				{
					if (!ACTOR_IS_VARIABLE_MESH_ENABLED(self, pedcomp))
					{
						ACTOR_ENABLE_VARIABLE_MESH(self, pedcomp, 1);
					}
					else
						print2("Component Already Enabled", 2000);
				}
				else
					print2("Component Not Valid For Current Model", 2000);
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
void SetFreeCamera()
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

		SET_CAMERA_POSITION(cam, camPos);
		SET_CAMERA_ORIENTATION(cam, camDirection, 0);

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
	if (IS_ACTOR_VALID(GET_ACTORS_HORSE(self)))SET_ACTOR_RIDEABLE(GET_ACTORS_HORSE(self), 1);//make sure our mount is always rideable at all times! (mostly for cows)
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