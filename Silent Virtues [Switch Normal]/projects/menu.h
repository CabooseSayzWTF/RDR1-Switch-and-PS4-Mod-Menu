void MainMenu()
{
	add_title("<RED_SKULL> Silent Virtues <RED_SKULL>");
	DrawSubMenuOption("Self Options", SubMenu1);
	DrawSubMenuOption("Weapon Options", SubMenu2);
	DrawSubMenuOption("Teleport Options", SubMenu3);
	DrawSubMenuOption("World Options", SubMenu4);
	DrawSubMenuOption("Misc Options", SubMenu5);
	DrawSubMenuOption("Spawner Options", SubMenu7);
}

void Sub_Menu1()
{
	add_title("Self Options");
	add_option("Page 1");
	add_option("Page 2");
	add_option("SP Specific");
	add_option("Medusa Menu");
	add_option("Model Changer");
	add_option("DeadEye Editor");
	switch (getOption())
	{
	case 1: Option1: changeSubmenu(Self_OptionsP1); break;
	case 2: Option2: changeSubmenu(Self_OptionsP2); break;
	case 3: Option3: changeSubmenu(SPShit); break;
	case 4: Option4: changeSubmenu(MedusaMenu); break;
	case 5: Option5: changeSubmenu(PedSwap); break;
	case 6: Option6: changeSubmenu(DeadEyeEditor); break;
	}
}

void SelfOptionP1()
{
	add_title("Self Options - Page 1");
	DrawBoolOption("God Mode", God);
	DrawBoolOption("Inf Horse Stamina", HrsStam);
	DrawBoolOption("EXP Jump", SuperJump);
	add_option("Noclip");
	add_option("Free Camera");
	DrawBoolOption("NoRagDollv1", AntiRagDoll);//there are two versions because some people like this or that version so just kept both...
	DrawBoolOption("NoRagDollv2", AntiRagDoll2);
	DrawBoolOption("Skip Loot Anim", stoploot);
	switch (getOption())
	{
	case 1: Option1: CLEAR_ACTOR_PROOF_ALL(self); God = !God; if (!God) { CLEAR_ACTOR_PROOF(self, -1); SET_ACTOR_INVULNERABILITY(self, 0); }; break;
	case 2: Option2: HrsStam = !HrsStam; if (!HrsStam) { HORSE_SET_INFINITE_FRESHNESS_CHEAT(0); HORSE_UNLOCK_FRESHNESS(GET_DRAFT_ACTOR(0, GET_ACTOR_MOST_RECENT_VEHICLE(self))); HORSE_UNLOCK_FRESHNESS(GET_DRAFT_ACTOR(1, GET_ACTOR_MOST_RECENT_VEHICLE(self))); HORSE_UNLOCK_FRESHNESS(GET_DRAFT_ACTOR(2, GET_ACTOR_MOST_RECENT_VEHICLE(self))); HORSE_UNLOCK_FRESHNESS(GET_DRAFT_ACTOR(3, GET_ACTOR_MOST_RECENT_VEHICLE(self))); }; break;
	case 3: Option3: SuperJump = !SuperJump; if (SuperJump) { if (!God)God = 1; }; break;
	case 4: Option4: if (!NoclipON) { SET_MOVER_FROZEN(self, 1); NOCLIPMESS(); }; break;
	case 5: Option5: SetFreeCamera(); break;
	case 6: Option6: AntiRagDoll2 = 0; TASK_CROUCH(self, 0); AntiRagDoll = !AntiRagDoll; break;
	case 7: Option7: AntiRagDoll = 0; AntiRagDoll2 = !AntiRagDoll2; break;
	case 8: Option8: stoploot = !stoploot; break;
	}
}
void SelfOptionP2()
{
	add_title("Self Options - Page 2");
	add_option("Wanted Editor");
	DrawBoolOption("AI Ignore", IgnoreON);
	DrawBoolOption("Drunk", IrishDrunk);
	add_option("Suicide");
	DrawBoolOption("AI Mode", AiControl);
	DrawBoolOption("Ghost Rider", FlameON);
	DrawBoolOption("Ride All Animals", AnimalBypassON);
	switch (getOption())
	{
	case 1: Option1: PedWepz = 32; ToggleSpoof13 = true; break;
	case 2: Option2: IgnoreON = !IgnoreON; if (!IgnoreON) AI_STOP_IGNORING_ACTORS(); break;
	case 3: Option3: IrishDrunk = !IrishDrunk; if (!IrishDrunk) SET_ACTOR_DRUNK(self, 0); break;
	case 4: Option4: KILL_ACTOR(self); break;
	case 5: Option5: AiControl = !AiControl; if (AiControl) { print2("Works Best With Non Story/Non MP Characters", 3000); TASK_CLEAR(self); RELEASE_ACTOR_AS_AMBIENT(self); }; if (!AiControl) { TASK_CLEAR(self); SET_ACTOR_IS_AMBIENT(self, 0); }; break;
	case 6: Option6: FlameON = !FlameON; if (FlameON) { print2("<blue>God Mode temp turned off so this works as expected", 3000); } break;
	case 7: Option7: AnimalBypassON = !AnimalBypassON; if (AnimalBypassON)print2("This makes it so you can mount animals without getting kicked off, you will need to use template files for this to work properly", 10000); break;
	}
}

void SP_1()
{
	add_title("SP Specific [Use At Own Risk]");
	add_option("Unlock Outfits");
	add_option("Give Max Cash");
	add_option("Edit Consumables");
	add_option("Edit Provisions");
	add_option("Unlock Cheat Codes");
	add_option("Unlock Achievements");
	add_option("High Stats");
	switch (getOption())
	{
	case 1: Option1: UnlockMostOutfits(); print2("This unlocks every outfit except US Army, US Marshall, & Bureau\n Save Game, Then Reload Save", 8000); break;
	case 2: Option2: GIVE_MONEY(); WAIT(100); SetStatArrayValue(0, 2147000000); PLAY_SOUND_FRONTEND("HUD_PAY_BOUNTY_MASTER"); break;
	case 3: Option3: PedWepz = 33; ToggleSpoof13 = true; break;
	case 4: Option4: PedWepz = 34; ToggleSpoof13 = true; break;
	case 5: Option5: for (int i = 0; i <= 55; i++) { UI_CHEAT_SET_STATE(i, 1); }; break;
	case 6: Option6: for (int i = 1; i <= 51; i++) { if (!HAS_ACHIEVEMENT_BEEN_PASSED(i)) { AWARD_ACHIEVEMENT(i); WAIT(2000); if (i == 51)print2("All Achievements Unlocked", 3000); } }; break;//added a 2 second wait between cheevo unlocks to avoid a kernal panic from unlocking too fast, menu will be unresponsive during this time.
	case 7: Option7: SetStats(2147000000, 2147000000); break;
	}
}
void Dead_Eye_Editor()
{
	add_title("DeadEye Editor");
	DrawBoolOption("Inf DeadEye", DeadEyeInf1);
	DrawBoolOption("1 Hit Kill DeadEye", DeadEye1Hit);
	DrawBoolOption("Auto Enter DeadEye", AutoDead);
	add_option("Fill DeadEye");
	add_option("Cycle DeadEye Color");
	add_option("Cycle DeadEye Lvl");
	add_option("Cycle DeadEye Timescale");
	switch (getOption())
	{
	case 1: Option1: DeadEyeInf1 = !DeadEyeInf1; SET_DISABLE_DEADEYE(self, 0); SET_PLAYER_DEADEYE_POINTS(self, TO_FLOAT(100), 1); if (!DeadEyeInf1)SET_INFINITE_DEADEYE(self, 0); break;
	case 2: Option2: DeadEye1Hit = !DeadEye1Hit; if (!DeadEye1Hit)SET_DEADEYE_DAMAGE_SCALING(self, 1); break;
	case 3: Option3: AutoDead = !AutoDead; break;
	case 4: Option4: SET_DISABLE_DEADEYE(self, 0); SET_PLAYER_DEADEYE_POINTS(self, TO_FLOAT(100), 1); break;
	case 5: Option5: DEColor(); break;
	case 6: Option6: DESelect(); break;
	case 7: Option7: DETime1(); break;
	}
}
void MedusaOptionsMenu()
{
	add_title("Medusa Options");
	DrawBoolOption("Kill", MedusaKill);
	DrawBoolOption("Explode", MedusaXplode);
	DrawBoolOption("Hell Fire", MedusaBurn);
	DrawBoolOption("Delete", MedusaDestroy);
	switch (getOption())
	{
	case 1: Option1: CLEAR_LAST_HIT(self); MedusaXplode = 0; MedusaBurn = 0; MedusaDestroy = 0; MedusaKill = !MedusaKill; break;
	case 2: Option2: CLEAR_LAST_HIT(self); MedusaKill = 0; MedusaBurn = 0; MedusaDestroy = 0; MedusaXplode = !MedusaXplode; break;
	case 3: Option3: CLEAR_LAST_HIT(self); MedusaKill = 0; MedusaXplode = 0; MedusaDestroy = 0; MedusaBurn = !MedusaBurn; break;
	case 4: Option4: CLEAR_LAST_HIT(self); MedusaKill = 0; MedusaXplode = 0; MedusaBurn = 0; MedusaDestroy = !MedusaDestroy; break;
	}
}
void Sub_Menu2()
{
	add_title("Weapon Options");
	add_option("Give Weapons");
	DrawBoolOption("Inf Ammo", UnlimitedAmmo);
	DrawBoolOption("Gold Weps", GoldIt);
	DrawBoolOption("Explosive Rounds", ExplosiveRounds);
	DrawBoolOption("Delete Gun", DeleteGun);
	DrawBoolOption("Hell Fire Gun", BurnGun);
	add_option("More Options");
	switch (getOption())
	{
	case 1: Option1: GiveActorAllWeapons(); break;
	case 2: Option2: AmmoInf(); break;
	case 3: Option3: GoldIt = !GoldIt; if (!GoldIt) { for (int i = 0; i <= 37; i++) { if (ACTOR_HAS_WEAPON(self, i)) { if (GET_WEAPON_GOLD(self, i) != 0) { SET_WEAPON_GOLD(self, i, 0); } } } }; break;
	case 4: Option4: CLEAR_LAST_ATTACK(self); DeleteGun = 0; BurnGun = 0; CopyGun = 0; ExplosiveRounds = !ExplosiveRounds; break;
	case 5: Option5: ExplosiveRounds = 0; BurnGun = 0; CopyGun = 0; DeleteGun = !DeleteGun; break;
	case 6: Option6: ExplosiveRounds = 0; DeleteGun = 0; CopyGun = 0; BurnGun = !BurnGun; break;
	case 7: Option7: changeSubmenu(Weapons2); break;
	}
}
void WepMenu2()
{
	add_title("Weapon Options");
	DrawBoolOption("CopyCat", CopyGun);
	DrawBoolOption("Fire Round", Fireround);
	DrawBoolOption("Slug Round", Slugz);
	DrawBoolOption("Killbot", aimbott);
	DrawBoolOption("Headlock", aimbott2);
	add_option("Cycle Target Mode");
	add_option("Cycle Special Weapons");
	switch (getOption())
	{
	case 1: Option1: CLEAR_LAST_ATTACK(self); ExplosiveRounds = 0; DeleteGun = 0; BurnGun = 0; CopyGun = !CopyGun; break;
	case 2: Option2: Fireround = !Fireround; if (!Fireround)FIRE_SET_GUNS_BLAZING_ACTIVE(0); break;
	case 3: Option3: Slugz = !Slugz; if (!Slugz)_DLC_SHOTGUN_SPREAD_OVERRIDE(self, 0, 0.1f); break;
	case 4: Option4: aimbott = !aimbott; if (aimbott) { print2("<blue>Just Aim At Somebody", 2000); }; break;
	case 5: Option5: aimbott2 = !aimbott2; break;
	case 6: Option6: SetTargetMode(); break;
	case 7: Option7: GiveSpecialWeapon(); break;
	}
}
void Sub_Menu3()
{
	add_title("Teleport Options");
	add_option("New Austin");
	add_option("West Elizabeth");
	add_option("Mexico");
	add_option("Special");
	add_option("Out of Map");
	add_option("Save Position");
	add_option("Load Position");
	DrawBoolOption("Teleport To Waypoint", tpwp);
	switch (getOption())
	{
	case 1: Option1: PedWepz = 4; ToggleSpoof13 = true; break;
	case 2: Option2: PedWepz = 5; ToggleSpoof13 = true; break;
	case 3: Option3: PedWepz = 6; ToggleSpoof13 = true; break;
	case 4: Option4: PedWepz = 7; ToggleSpoof13 = true; break;
	case 5: Option5: PedWepz = 8; ToggleSpoof13 = true; break;
	case 6: Option6: GET_POSITION(self, &savedPos); isSaved = true; break;
	case 7: Option7: if (!isSaved)print2("<red>Save a Position", 3000); if (isSaved) TELEPORT_ACTOR(self, &savedPos, 1, 1, 1); break;
	case 8: Option8: tpwp = !tpwp; break;
	}
}
void Sub_Menu4()
{
	add_title("World Options");
	add_option("Weather");
	add_option("Time Of Day");
	DrawBoolOption("Time Acceleration", Timez);
	DrawBoolOption("Freeze Time", TODLoop);
	DrawBoolOption("Freeze Weather", TODLoop2);
	switch (getOption())
	{
	case 1: Option1: PedWepz = 9; ToggleSpoof13 = true; break;
	case 2: Option2: PedWepz = 25; ToggleSpoof13 = true; break;
	case 3: Option3: TODLoop = 0; Timez = !Timez; if (!Timez)SET_TIME_ACCELERATION(1097859072); break;//reset is overflowing and causing time acc to go back to normal, however could be wrong
	case 4: Option4: Timez = 0; TODLoop = !TODLoop; break;
	case 5: Option5: TODLoop2 = !TODLoop2; break;
	}
}
void Sub_Menu5()
{
	add_title("Misc Options");
	add_option("Script Loader");
	add_option("Interior Loader");
	add_option("Animation Player");
	add_option("Cutscene Player");
	add_option("Movie Player");
	add_option("Song Player");
	add_option("Credits");
	//add_option("test");
	switch (getOption())
	{
	case 1: Option1: PedWepz = 18; ToggleSpoof13 = true; break;
	case 2: Option2: PedWepz = 30; ToggleSpoof13 = true; break;
	case 3: Option3: PedWepz = 31; ToggleSpoof13 = true; break;
	case 4: Option4: PedWepz = 27; ToggleSpoof13 = true; break;
	case 5: Option5: PedWepz = 28; ToggleSpoof13 = true; break;
	case 6: Option6: PedWepz = 29; ToggleSpoof13 = true; break;
	case 7: Option7: print2("Creators\n <0x00FFFF>CabooseSayzWTF, Im Foxxyyy, & Sockstress", 5000); WAIT(5000); print2("Helpers\n <0xFFA500>Cain532, Mizdx, FuhzBots, JamesTwt\n xTheDevilRazedMe, Slluxx, RouletteBoi \n <red>Function Help/Examples, Reverse Engineering Etc..", 5000); WAIT(5000); print2("Testers\n <0xF700FF>KeatonTheBot", 5000); WAIT(5000); print2("Special Thanks!\n <yellow>XBLToothPik, ap ii intense, jedijosh920, Teh1337Online", 5000); WAIT(5000); print2("SC-CL\n <blue>Without The SC-CL Team This Would Of Never Been Possible!", 5000); break;
	//case 8: Option8: PedWepz = 99; ToggleSpoof13 = true; break;
	}
}

void Sub_Menu7()
{
	add_title("Spawner Options");
	add_option("Mount Spawner");
	add_option("Ped Spawner");
	add_option("Vehicle Spawner");
	switch (getOption())
	{
	case 1: Option1: changeSubmenu(MountMain); break;
	case 2: Option2: changeSubmenu(PedSpawnz); break;
	case 3: Option3: changeSubmenu(VehSpawnerMenu); break;
	}
}
void VehMenu()
{
	add_title("Vehicle Spawner");
	add_option("Vehicles");
	add_option("Teleport Vehicle");
	add_option("Teleport Into Vehicle");
	add_option("Reset Vehicle");
	add_option("Delete Vehicle");
	DrawBoolOption("Flyable Car - [Car/Truck]", CarSpeedBoost);
	switch (getOption())
	{
	case 1: Option1: PedWepz = 3; ToggleSpoof13 = true; break;
	case 2: Option2: if (IS_ACTOR_VALID(SpawnCar1)) { GET_POSITION(self, &ve23); float headye = GET_HEADING(self); TELEPORT_ACTOR(SpawnCar1, &ve23, 1, 1, 1); SET_ACTOR_HEADING(SpawnCar1, headye, 1); SET_ACTOR_IN_VEHICLE(self, SpawnCar1, 0); }; break;
	case 3: Option3: if (IS_ACTOR_VALID(SpawnCar1))SET_ACTOR_IN_VEHICLE(self, SpawnCar1, 0); break;
	case 4: Option4: ResetVehicle(); break;
	case 5: Option5: if (IS_ACTOR_VALID(SpawnCar1)) { DESTROY_ACTOR(SpawnCar1); }for (int i = 0; i <= 3; i++) { if (IS_ACTOR_VALID(SpawnDra[i])) { DESTROY_ACTOR(SpawnDra[i]); } } break;
	case 6: Option6: CarSpeedBoost = !CarSpeedBoost; if (CarSpeedBoost)print2("<RT>Forward, <LB>Backwards, <LT>Stop, <dpadup>Turn Vehicle To Cam Direction, <LS>Go Up", 8000); break;
	}
}
void MountMainMenu()
{
	add_title("Mount Spawner");
	add_option("Choose Mount");
	add_option("Teleport Mount");
	add_option("Delete Mount");
	add_option("Save Mount");
	add_option("Mount Accessory Editor");
	switch (getOption())
	{
	case 1: Option1: PedWepz = 10; ToggleSpoof13 = true; break;
	case 2: Option2: if (IS_ACTOR_VALID(SpawnMount1)) { GET_POSITION(self, &animaltp); TELEPORT_ACTOR(SpawnMount1, &animaltp, 1, 1, 1); }; break;
	case 3: Option3: if (IS_ACTOR_VALID(SpawnMount1))DESTROY_ACTOR(SpawnMount1); break;
	case 4: Option4: SetMountHorse(); break;
	case 5: Option5: PedWepz = 14; ToggleSpoof13 = true; break;
	}
}
void PedMenu()
{
	add_title("Ped Spawner");
	add_option("All Peds");
	add_option("Quick Peds");
	add_option("Teleport Peds");
	add_option("Delete Peds");
	add_option("Ped Task Editor");
	add_option("Ped Weapons Editor");
	switch (getOption())
	{
	case 1: Option1: PedWepz = 23; ToggleSpoof13 = true; break;
	case 2: Option2: PedWepz = 20; ToggleSpoof13 = true; break;
	case 3: Option3: GET_POSITION(self, &pedztp);for (int i = 0; i <= 9; i++){if (IS_ACTOR_VALID(SpawnPed[i])){TELEPORT_ACTOR(SpawnPed[i], &pedztp, 1, 1, 1);}}; break;
	case 4: Option4: pedint2 = 0;for (int i = 0; i <= 9; i++){if (IS_ACTOR_VALID(SpawnPed[i])){DESTROY_ACTOR(SpawnPed[i]);}}; break;
	case 5: Option5: PedWepz = 40; ToggleSpoof13 = true; break;
	case 6: Option6: PedWepz = 1; ToggleSpoof13 = true; break;
	}
}
void PedChanger()
{
	add_title("Model Changer");
	add_option("All Models");
	add_option("Quick Models");
	add_option("Outfit Editor");
	add_option("Component Editor");
	add_option("Anim Set");
	add_option("Save Model");//saves to a unused stat in SP but the stat still gets saved regardless to the gamesave, it's actually a MP stat hence why it saves
	add_option("Load Model");
	switch (getOption())
	{
	case 1: Option1: PedWepz = 24; ToggleSpoof13 = true; break;
	case 2: Option2: PedWepz = 19; ToggleSpoof13 = true; break;
	case 3: Option3: PedWepz = 21; ToggleSpoof13 = true; break;
	case 4: Option4: PedWepz = 41; ToggleSpoof13 = true; break;
	case 5: Option5: PedWepz = 42; ToggleSpoof13 = true; break;
	case 6: Option6: SetStatArrayValue(170, GET_ACTOR_ENUM(self)); break;
	case 7: Option7: DefautSavedModel = GetStatArrayValue(170); WAIT(1000); if (DefautSavedModel > 1294 || DefautSavedModel == -1)print2("<red>Error", 2000); if(DefautSavedModel >= 0 && DefautSavedModel <= 1294)ChangeModel(self, DefautSavedModel); break;
	}
}

void MenuSetup()
{
	if (MenuOpen)
	{
		optionCount = 0;
		switch (submenu)
		{
			case Main_Menu: MainMenu(); break;
			case SubMenu1: Sub_Menu1(); break;
			case SubMenu2: Sub_Menu2(); break;
			case SubMenu3: Sub_Menu3(); break;
			case SubMenu4: Sub_Menu4(); break;
			case SubMenu5: Sub_Menu5(); break;
			case SubMenu7: Sub_Menu7(); break;
			case Self_OptionsP1: SelfOptionP1(); break;
			case Self_OptionsP2: SelfOptionP2(); break;
			case VehSpawnerMenu: VehMenu(); break;
			case MedusaMenu: MedusaOptionsMenu(); break;
			case DeadEyeEditor: Dead_Eye_Editor(); break;
			case MountMain: MountMainMenu(); break;
			case PedSpawnz: PedMenu(); break;
			case PedSwap: PedChanger(); break;
			case SPShit: SP_1(); break;
			case Weapons2: WepMenu2(); break;
		}
	}
}
void Menu_Loop()
{
	Hook();
	MenuSetup();
	resetVars();
}