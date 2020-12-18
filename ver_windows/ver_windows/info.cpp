#include "info.h"

Info info = {
	{INVENTORY, INVENTORY, INVENTORY},
	{PRICE_1, PRICE_2, PRICE_3},
	0,
	ITEM_1,
	{"���� � �־��ּ��� ����"},
	getInventory,
	setInventory,
	getPrice,
	getSelected,
	getMoney,
	setMessage,
	getMessage,
	left,
	right,
	insertCoin,
	purchaseMask
};

uint getInventory(uint n) {
	return info.inventories[n];
}

void setInventory(uint n) {
	info.inventories[info.selected] = n;
}

uint getPrice(uint n) {
	return info.prices[n];
}

uint getSelected() {
	return info.selected;
}

uint getMoney() {
	return info.money;
}

void setMessage(const char* p) {
	char* pMessage = info.message;

	// �޼��� �ʱ�ȭ
	while (*pMessage) {
		*(pMessage++) = '\0';
	}

	pMessage = info.message;

	// �޼��� ����
	while (*p) {
		*(pMessage++) = *(p++);
	}
}

char* getMessage() {
	return info.message;
}

void left() {
	if (!info.selected) {
		info.selected = ITEM_3;
		return;
	}
	info.selected -= 1;
}

void right() {
	info.selected += 1;
	info.selected %= (ITEM_3 + 1);
}

void insertCoin() {
	info.money += 10000;
}

void purchaseMask() {
	if (info.money >= info.prices[info.selected] && info.inventories[info.selected] > 0) {
		info.money -= info.prices[info.selected];
		info.inventories[info.selected]--;
		// ���� ���� �޼���
		info.pSetMessage("���� �������ּż� �����մϴ�.");
	}
	else if (info.inventories[info.selected] == 0) {
		// �ȳ�â�� ��� �޼���
		info.pSetMessage("Sold out.");
	}
	else {
		// �ȳ�â�� ��� �޼���
		info.pSetMessage("���� �����մϴ� ����, � ���� �־��ּ���.");
	}
}