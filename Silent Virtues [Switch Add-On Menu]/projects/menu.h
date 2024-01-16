void MainMenu()
{
	add_title("<RED_SKULL> Silent Virtues Add-On<RED_SKULL>");
	add_option("Cutscene Player");
	add_option("Object Spawner");
	add_option("Define Object");
	switch (getOption())
	{
	case 1: Option1: PedWepz = 100; ToggleSpoof13 = true; break;
	case 2: Option2: PedWepz = 101; ToggleSpoof13 = true; break;
	case 3: Option3: PedWepz = 102; ToggleSpoof13 = true; break;
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
		}
	}
}
void Menu_Loop()
{
	Hook();
	MenuSetup();
	resetVars();
}