TITLE:
	Save The King!
By:
	David Vapna.

Design:
	Controller Class:
	managing the game's responsiveness to input and output, the board itself
	and the helpp menu.

	Board Class:
	responsible for the communcation between the game objects.
	holds the all the characters and static pbjects.

	World+Map Classes:
	they are responsible for the stuctures of the game and the memory.
	first time loading the data and then using the loaded data without disturbing
	the flow of the game.

	MovingObject Class:
	this is a base class derived from gameObject.
	this class will be the base class from the moving objects (like the heros and the gnom).

	StaticObject Class:
	derived from gameObject, will be the parent class of the static objects and will help
	with executing the interactions between moving and static objects.


Level format:
	at the begining of each level there's the level's size (height and width).
	after that the level's time limit(0 if none).
	after that we use marks to indicate positions of the game objects (Explnation below).

File list:
	main.cpp, Board.h+cpp, BadTimeGift.h+cpp, Controller.h+cpp, main.cpp, DataLoader.h+cpp,
	Gate.h+cpp, GoodTimeGift.h+cpp, Gift.h+cpp, Hero.h+cpp, Key.h+cpp, King.h+cpp, Mage.h+cpp,
	Map.h+cpp,Menu.h+cpp, MovingObject.h+cpp, Orc.h+cpp, Portal.h+cpp, StaticObject.h+cpp,
	Thief.h+cpp, Throne.h+cpp, Wall.h+cpp,Warrior.h+cpp, World.h+cpp, Const.h

Data Structures:	
	World's(levels) data management class.
	Heroes vector.
	Static objects vector.
	Gnoms vector.

Game Objects Indicator:
! - Orc
F - Key
# - Gate
* - Fire
@ - Throne
M - Mage
W - Warrior
T - Thief
K - King
X - Portal
^ - Gnom


16.1.2022

