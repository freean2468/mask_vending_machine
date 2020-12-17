/*
프로그램 : 마스크 자판기
개발자 : 송훈일
개발기간 : Dec 16, 2020 ~ 
문의 : https://www.youtube.com/channel/UC5yZGtDDMZDe3jmCDUB_rJA
*/
#include "helper.h"
#include "UI.h"
#include "info.h"

int main(void)
{
    setConsoleWindow();
    /*
    while (1) {
        완료 // 자판기 출력
        사용자 정보 출력
        if (input) {
            좌우 화살표로 제품 선택(선택된 제품 색깔 변경)
            spacebar 로 제품 구매
                구매 후 제품 재고 확인
                    재고가 없으면 이미지 출력 x + sold out 출력
            c 로 돈 받기
            q 로 종료
        }
    }
    */
    while (1) {
        printVM();
        printInfo();

        int c = zeroBufferGetchar();

        if (c == 'q' || c == 'Q') {
            break;
        }
        else if (c == 'J' || c == 'j') { // 'J'
            info.pLeft();
        }
        else if (c == 'L' || c == 'l') { // 'L'
            info.pRight();
        }
        else if (c == 'c' || c == 'C') {
            info.pInsertCoin();
        }
        else if (c == 32) { // space
            
        }

        clearScreen();

        printf("%d\n", c);
    }

    return 0;
}