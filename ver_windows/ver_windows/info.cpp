#include "info.h"

static Info info = {
	{INVENTORY, INVENTORY, INVENTORY},
	{PRICE_1, PRICE_2, PRICE_3},
	0,
	ITEM_1,
	getInventory,
	setInventory,
	left,
	right,
	insertCoin
};

uint getInventory(uint n) {
	return info.inventories[n];
}

void setInventory(uint n) {
	info.inventories[info.selected] = n;
}

void left() {
	info.selected -= 1;
	if (info.selected < 0) {
		info.selected = ITEM_3;
	}
}

void right() {
	info.selected += 1;
	info.selected %= (ITEM_3 + 1);
}

void insertCoin() {
	info.money += 10000;
}