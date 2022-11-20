
#pragma once


//Game Menu Size:
const int MENU_WIDTH = 800;
const int MENU_HEIGHT = 700;

//Game Help Size:
const int HELP_WIDTH = 800;
const int HELP_HEIGHT = 700;

//Game Board Size:
const int GAME_WIDTH = 850;
const int GAME_HEIGHT = 850;

//Tiles char indicators:
const static char TheKing = 'K';
const static char TheMage = 'M';
const static char TheThief = 'T';
const static char TheWarrior = 'W';
const static char TheOrc = '!';
const static char TheKey = 'F';
const static char ThePortal = 'X';
const static char TheFire = '*';
const static char TheThrone = '@';
const static char TheGate = '#';
const static char TheWall = '=';
const static char Space = ' ';
const static char TheDwarf = '^';
const static char TheGift = '&';

//Tiles int indicators:
enum Sprites
{
	KingSprite, MageSprite, ThiefSprite, WarriorSprite,
	OrcSprite, KeySprite, PortalSprite, FireSprite,
	ThroneSprite, GateSprite, WallSprite, BackgroundSprite,
	DwarfSprite, GiftSprite
};
enum menuEnum
{
	menuBG
};
enum GiftOptions
{
	goodTime, badTime, Eliminate
};
//Movement speeds of the moving classes:
const int HERO_SPEED = 300;
const int DWARF_SPEED = 190;
constexpr auto ANIMATION_SPEED = 0.1f;
//Menu buttons size:
const int MENU_OPTION_WIDTH = 200;
const int MENU_OPTION_HEIGHT = 130;

//
const int STAT_BAR = 100;


enum CurrentMode
{
	WallPaper, Play, Help, Quit,
	Phl, Hhl, Qhl, OptionMenu, numOfTextures
};
const int StatsSprite = 7;

//sound effect indicators:
const int FIRE_OFF = 0;
const int END_LEVEL = 1;

//scalers
const float MOVING_SCALE = 0.75;
const float MOVING_DESCALE = 1.3;