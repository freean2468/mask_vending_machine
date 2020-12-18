#include "helper.h"
#include "info.h"

// vendingMachine sprite 출력
void printVM() {
    for (int i = 0, j = 0; i < WINDOW_HEIGHT * WINDOW_WIDTH; ) {

        // 현재 선택된 아이템에 따라 색깔을 주고
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

// 각종 정보 출력
void printInfo() {
    printf("%30s%32s%37s\n", "의료용 마스크", "KF-95마스크", "복면마스크");
    printf("<-J%117s\n", "L->");
    printf("%6s\
%6s%2d%6s%6s%4d\
%6s\
%8s%2d%6s%9s%4d\
%7s\
%8s%2d%7s%8s%5d\n", 
        "",
        "잔량 : ", info.pGetInventory(ITEM_1), "", "가격 : \\", info.pGetPrice(ITEM_1),
        "",
        "잔량 : ", info.pGetInventory(ITEM_2), "", "가격 : \\", info.pGetPrice(ITEM_2),
        "",
        "잔량 : ", info.pGetInventory(ITEM_3), "", "가격 : \\", info.pGetPrice(ITEM_3));
    
    printf("\n%15s : \\%d%5s%83s", "투입된 돈", info.pGetMoney(), "", "돈 넣기 : i, 구매 : spacebar");

    printf("%20s%60s%40s", "", info.pGetMessage(), "");
}
