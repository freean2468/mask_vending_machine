/*
* 프로그램이 동작할 때 필요한 모든 정보와 상수들을 정의한 곳
*/
#pragma once

#define LENGTH 64

#define ITEMS 3
#define ITEM_1 0
#define ITEM_2 1
#define ITEM_3 2

#define INVENTORY 20

#define PRICE_1 3000
#define PRICE_2 5000
#define PRICE_3 20000

#define uint unsigned int

// 구조체 안에 함수포인터를 통해 OOP의 클래스 메소드마냥 동작하기
typedef struct info {
	uint inventories[ITEMS];
	uint prices[ITEMS];
	uint money;
	uint selected;
	char message[LENGTH];

	uint (*pGetInventory)(uint);
	void (*pSetInventory)(uint);
	uint (*pGetPrice)(uint);
	uint (*pGetSelected)();
	uint (*pGetMoney)();
	void (*pSetMessage)(const char*);
	char* (*pGetMessage)();

	void (*pLeft)();
	void (*pRight)();
	void (*pInsertCoin)();
	void (*pPurchaseMask)();
} Info;

extern Info info;

uint getInventory(uint);
void setInventory(uint);
uint getPrice(uint);
uint getSelected();
uint getMoney();
void setMessage(const char*);
char* getMessage();

void left();
void right();
void insertCoin();
void purchaseMask();