#include "helper.h"
#include "info.h"

void printVM() {
    for (int i = 0; i < WINDOW_HEIGHT * WINDOW_WIDTH; ) {
        printf("%c", *((char*)vendingMachine + i++));
        if (!(i % WINDOW_WIDTH))
            printf("\n");
    }
}

void printInfo() {

}
