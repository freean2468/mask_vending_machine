/*
프로그램 : 마스크 자판기
개발자 : 송훈일
개발기간 : Dec 16, 2020 ~ Dec 18, 2020
문의 : https://www.youtube.com/channel/UC5yZGtDDMZDe3jmCDUB_rJA
*/
#include "helper.h"
#include "UI.h"
#include "info.h"

int main(void)
{
    // 콘솔창 화면크기 셋팅
    setConsoleWindow();
    /*
    while (1) {
        자판기 출력
        사용자 정보 출력
        if (input) {
            좌우 화살표로 제품 선택(선택된 제품 색깔 변경)
            spacebar 로 제품 구매
                구매 후 제품 재고 확인
                    재고가 없으면 sold out 출력
            i 로 돈 받기
            q 로 종료
        }
        화면 초기화
    }
    */

    // 이상하게 먼저 clearScreen을 하지 않으면 release혹은 debug 실행 파일을 통해 실행 시 문자가 깨져서 나온다.
    clearScreen();

    while (1) {
        printVM();
        printInfo();

        int c = zeroBufferGetchar();

        if (c == 'q' || c == 'Q') {
            break;
        }
        else if (c == 'J' || c == 'j') {
            info.pLeft();
        }
        else if (c == 'L' || c == 'l') {
            info.pRight();
        }
        else if (c == 'i' || c == 'I') {
            info.pInsertCoin();
        }
        else if (c == 32) { // space
            info.pPurchaseMask();
        }

        clearScreen();
    }

    return 0;
}