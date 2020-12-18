#pragma once

#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#include "sprites.h"

// 콘솔창의 가로 세로
#define WINDOW_WIDTH   120
#define WINDOW_HEIGHT  25

// error codes
enum errors {
    NO_ERR = 0,
    ERR_SAVE_TTY_GETATTR = -2,
    ERR_SAVE_TTY_SETATTR = -3,
    ERR_RESTORE_TTY_SETATTR = -4
};

// 헬퍼 함수들은 바깥에서 쓸 수 있도록 extern처리.

extern int setConsoleWindow();

int save_tty_attributes();
int restore_tty_attributes();
extern int zeroBufferGetchar();

extern void setRed();
extern void setCyan();
extern void setBlue();
extern void reset();
extern void clearScreen();