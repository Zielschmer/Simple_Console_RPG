#pragma once

class Inventory {

	int m_coins = 800;
	int m_potions = 0;
	int m_arrows = 0;
	int m_darts = 0;

public:

	//Buy functions
	bool buyPotion(int howMany);
	bool buyArrows(int howMany);
	bool buyDarts(int howMany);

	//Check functions
	int checkPotion();
	int checkArrows();
	int checkDarts();
	int checkCoins();

	//Use functions
	void usePotion();
	bool useArrow();
	void useDart();

};