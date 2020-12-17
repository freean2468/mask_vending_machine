#pragma once

#define ITEMS 3
#define ITEM_1 0
#define ITEM_2 1
#define ITEM_3 2

#define INVENTORY 20

#define PRICE_1 3000
#define PRICE_2 5000
#define PRICE_3 20000

#define uint unsigned int

typedef struct info {
	uint inventories[ITEMS];
	uint prices[ITEMS];
	uint money;
	uint selected;

	uint(*pGetInventory)(uint);
	void (*pSetInventory)(uint);
	void (*pLeft)();
	void (*pRight)();
	void (*pInsertCoin)();
} Info;

extern Info info;

uint getInventory(uint);
void setInventory(uint);
void left();
void right();
void insertCoin();