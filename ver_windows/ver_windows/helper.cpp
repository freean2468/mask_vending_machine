#include "helper.h"

static DWORD stdin_mode;

int setConsoleWindow()
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
    SMALL_RECT srctWindow;

    // Get the current screen buffer size and window position.

    if (!GetConsoleScreenBufferInfo(hStdout, &csbiInfo))
    {
        printf("GetConsoleScreenBufferInfo (%d)\n", GetLastError());
        return 0;
    }

    // 변경 가능한 콘솔창의 최대 크기 정보 가져오기
    //printf("maximum window size x : %d \n", csbiInfo.dwMaximumWindowSize.X);
    //printf("maximu window size y : %d \n", csbiInfo.dwMaximumWindowSize.Y);

    srctWindow = csbiInfo.srWindow;
    srctWindow.Bottom = WINDOW_HEIGHT + 10;
    srctWindow.Right = WINDOW_WIDTH - 1;

    //SetConsoleScreenBufferSize(hStdout, csbiInfo.dwSize * 2);

    // Set srctWindow to the current window size and location.
    if (!SetConsoleWindowInfo(
        hStdout,          // screen buffer handle
        TRUE,             // absolute coordinates
        &srctWindow))     // specifies new location
    {
        printf("SetConsoleWindowInfo (%d)\n", GetLastError());
        return 0;
    }
    return 1;
}

// 각 OS에 따른 터미널 조작
int save_tty_attributes() {
#ifdef _WIN32
    HANDLE hstdin = GetStdHandle(STD_INPUT_HANDLE);

    if (!GetConsoleMode(hstdin, &stdin_mode))
        return ERR_SAVE_TTY_GETATTR;

    if (hstdin == INVALID_HANDLE_VALUE || !(SetConsoleMode(hstdin, 0)))
        return ERR_SAVE_TTY_GETATTR; /* Failed to disable buffering */
#elif __APPLE__
    struct termios tty_attr;

    if (tcgetattr(STDIN_FILENO, &tty_attr) < 0)
        return ERR_SAVE_TTY_GETATTR;

    tty_attr.c_lflag &= ~ICANON;
    tty_attr.c_lflag &= ~ECHO;

    if (tcsetattr(STDIN_FILENO, 0, &tty_attr) < 0)
        return ERR_SAVE_TTY_SETATTR;
#endif 

    return NO_ERR;
}

// 각 OS에 따른 터미널 기본값으로 다시 설정
int restore_tty_attributes() {
#ifdef _WIN32
    HANDLE hstdin = GetStdHandle(STD_INPUT_HANDLE);

    if (!SetConsoleMode(hstdin, stdin_mode))
        return ERR_RESTORE_TTY_SETATTR;
#elif __APPLE__
    struct termios tty_attr;
    if (tcgetattr(STDIN_FILENO, &tty_attr) < 0)
        return ERR_SAVE_TTY_GETATTR;

    tty_attr.c_lflag |= ICANON;
    tty_attr.c_lflag |= ECHO;

    if (tcsetattr(STDIN_FILENO, 0, &tty_attr) < 0)
        return ERR_RESTORE_TTY_SETATTR;
#endif 
    return NO_ERR;
}

// 터미널에서 입력 버퍼를 없애고 입력을 screen에 표시 없이 변수에 저장해 사용
int zeroBufferGetchar() {
    int c = 0;
    int res = 0;
    if ((res = save_tty_attributes()) < 0) {
        printf("error : %d", ERR_SAVE_TTY_GETATTR);
        return res;
    }
    c = getchar();
    if ((res = restore_tty_attributes()) < 0) {
        printf("error : %d", ERR_SAVE_TTY_GETATTR);
        return res;
    }
    return c;
}

//
// ANSI escape codes
//
void setRed() {
    printf("\033[1;31m");
}

void setCyan() {
    printf("\033[1;36m");
}

void setBlue() {
    printf("\033[1;34m");
}

void reset() {
    printf("\033[0m");
}

void clearScreen() {
    system("cls");
}