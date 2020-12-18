#include "helper.h"
#include "info.h"

// vendingMachine sprite ���
void printVM() {
    for (int i = 0, j = 0; i < WINDOW_HEIGHT * WINDOW_WIDTH; ) {

        // ���� ���õ� �����ۿ� ���� ������ �ְ�
        if (i % WINDOW_WIDTH >= 5 && i % WINDOW_WIDTH <= 37 
            && j >= 7 && j <= 23 && info.pGetSelected() == ITEM_1)
            setCyan();
        else if (i % WINDOW_WIDTH >= 39 && i % WINDOW_WIDTH <= 73
            && j >= 7 && j <= 23 && info.pGetSelected() == ITEM_2)
            setBlue();
        else if (i % WINDOW_WIDTH >= 75 && i % WINDOW_WIDTH <= 108
            && j >= 7 && j <= 23 && info.pGetSelected() == ITEM_3)
            setRed();

        // vendingMachine[i++]
        printf("%c", *((char*)vendingMachine + i++));
        if (!(i % WINDOW_WIDTH)) {
            j++;
            printf("\n");
        }
        reset();
    }
}

// ���� ���� ���
void printInfo() {
    printf("%30s%32s%37s\n", "�Ƿ�� ����ũ", "KF-95����ũ", "���鸶��ũ");
    printf("<-J%117s\n", "L->");
    printf("%6s\
%6s%2d%6s%6s%4d\
%6s\
%8s%2d%6s%9s%4d\
%7s\
%8s%2d%7s%8s%5d\n", 
        "",
        "�ܷ� : ", info.pGetInventory(ITEM_1), "", "���� : \\", info.pGetPrice(ITEM_1),
        "",
        "�ܷ� : ", info.pGetInventory(ITEM_2), "", "���� : \\", info.pGetPrice(ITEM_2),
        "",
        "�ܷ� : ", info.pGetInventory(ITEM_3), "", "���� : \\", info.pGetPrice(ITEM_3));
    
    printf("\n%15s : \\%d%5s%83s", "���Ե� ��", info.pGetMoney(), "", "�� �ֱ� : i, ���� : spacebar");

    printf("%20s%60s%40s", "", info.pGetMessage(), "");
}
