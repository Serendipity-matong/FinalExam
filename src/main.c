#include <stdio.h>
#include <stdlib.h>
#include "../include/student.h"
#include "../include/StartSever.h"
#include <windows.h>
int main()
{
    system("chcp 65001");
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    // init();
    // exeSql("SELECT * FROM studentcard;");
    // EasyX();
    StartSever();
    // 在结束后释放内存
    // free(students);  // 释放动态分配的内存

    return 0;
}