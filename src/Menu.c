#include <stdio.h>
#include "../include/menu.h"
#include <stdio.h>
#include <string.h>
#include <windows.h> // 用于获取控制台宽度

void Menu()
{
    // 获取控制台宽度
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int consoleWidth = 80; // 默认宽度为80
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
    {
        consoleWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    }

    // 打印顶部框架
    for (int i = 1; i <= consoleWidth; i++)
        printf("-");
    printf("\n");

    // 打印标题并居中
    const char *title = "南昌大学校园卡管理系统";
    int titleLength = strlen(title) / 3 * 2;
    // printf("%d",titleLength);
    int paddingLeft = (consoleWidth - titleLength - 2) / 2; // 左右均衡
    printf("|");
    for (int i = 0; i < paddingLeft; i++)
        printf(" ");
    printf("%s", title);
    for (int i = 0; i < paddingLeft; i++)
        printf(" ");
    printf("|\n");

    // 打印分隔线
    for (int i = 0; i < consoleWidth; i++)
        printf("-");
    printf("\n");

    // 打印每一行菜单内容，逐行处理
    const char *line1 = "尊敬的用户，欢迎来到校园管理系统。";
    const char *line2 = "请选择以下操作：";
    const char *line3 = "1. 进入校园卡查询";
    const char *line4 = "2. 进入管理员页面";
    const char *line5 = "3. 进行校园卡充值操作";
    const char *line6 = "4. 关于程序";
    const char *line7 = "5. 帮助操作";

    // 打印第1行
    int line1Length = strlen(line1) / 3 * 2;
    paddingLeft = (consoleWidth - line1Length - 2) / 2;
    printf("|");
    for (int i = 0; i < paddingLeft; i++)
        printf(" ");
    printf("%s", line1);
    for (int i = 0; i < paddingLeft; i++)
        printf(" ");
    printf("|\n");

    printf("|");
    for (int i = 0; i < consoleWidth - 2; i++)
        printf(" ");
    printf("|\n");

    // 打印第2行
    int line2Length = strlen(line2) / 3 * 2;
    paddingLeft = (consoleWidth - line2Length - 2) / 2;
    printf("|");
    for (int i = 0; i < paddingLeft; i++)
        printf(" ");
    printf("%s", line2);
    for (int i = 0; i < paddingLeft; i++)
        printf(" ");
    printf("|\n");

    printf("|");
    for (int i = 0; i < consoleWidth - 2; i++)
        printf(" ");
    printf("|\n");

    // 打印第3行
    int line3Length = strlen(line3) / 3 * 2;
    paddingLeft = (consoleWidth - line3Length - 2) / 2;
    printf("|");
    for (int i = 0; i < paddingLeft; i++)
        printf(" ");
    printf("%s", line3);
    for (int i = 0; i < paddingLeft - 1; i++)
        printf(" ");
    printf("|\n");

    printf("|");
    for (int i = 0; i < consoleWidth - 2; i++)
        printf(" ");
    printf("|\n");

    // 打印第4行
    int line4Length = strlen(line4) / 3 * 2;
    paddingLeft = (consoleWidth - line4Length - 2) / 2;
    printf("|");
    for (int i = 0; i < paddingLeft; i++)
        printf(" ");
    printf("%s", line4);
    for (int i = 0; i < paddingLeft - 1; i++)
        printf(" ");
    printf("|\n");

    printf("|");
    for (int i = 0; i < consoleWidth - 2; i++)
        printf(" ");
    printf("|\n");

    // 打印第5行
    int line5Length = strlen(line5) / 3 * 2;
    paddingLeft = (consoleWidth - line5Length - 2) / 2;
    printf("|");
    for (int i = 0; i < paddingLeft; i++)
        printf(" ");
    printf("%s", line5);
    for (int i = 0; i < paddingLeft - 1; i++)
        printf(" ");
    printf("|\n");

    printf("|");
    for (int i = 0; i < consoleWidth - 2; i++)
        printf(" ");
    printf("|\n");

    // 打印第六行
    int line6Length = strlen(line6) / 3 * 2;
    paddingLeft = (consoleWidth - line6Length - 2) / 2;
    printf("|");
    for (int i = 0; i < paddingLeft; i++)
        printf(" ");
    printf("%s", line6);
    for (int i = 0; i < paddingLeft - 1; i++)
        printf(" ");
    printf("|\n");

    printf("|");
    for (int i = 0; i < consoleWidth - 2; i++)
        printf(" ");
    printf("|\n");

    // 打印第7行
    int line7Length = strlen(line7) / 3 * 2;
    paddingLeft = (consoleWidth - line7Length - 2) / 2;
    printf("|");
    for (int i = 0; i < paddingLeft; i++)
        printf(" ");
    printf("%s", line7);
    for (int i = 0; i < paddingLeft - 1; i++)
        printf(" ");
    printf("|\n");

    printf("|");
    for (int i = 0; i < consoleWidth - 2; i++)
        printf(" ");
    printf("|\n");

    printf("|");
    for (int i = 0; i < consoleWidth - 2; i++)
        printf(" ");
    printf("|\n");

    printf("|");
    for (int i = 0; i < consoleWidth - 2; i++)
        printf(" ");
    printf("|\n");

    printf("|");
    printf("version:1.0.0 ；版权说明：该程序的版权最终归于方梓杰所有。\n");

    // 打印底部框架
    for (int i = 0; i < consoleWidth; i++)
        printf("-");
    printf("\n");
}

char *MenuName()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int consoleWidth = 80; // 默认宽度为80
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
    {
        consoleWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    }
    char *Name = (char *)malloc(sizeof(char) * 20);
    const char *line1 = "下面进行身份验证";
    printf("|");
    int titleLength = strlen(line1) / 3 * 2;
    int paddingLeft = (consoleWidth - titleLength - 2) / 2;
    for (int i = 1; i <= paddingLeft; i++)
        printf(" ");
    printf("%s\n", line1);
    for (int i = 1; i <= paddingLeft; i++)
        printf(" ");
    printf("|\n");

    printf("|");
    for (int i = 0; i < consoleWidth - 2; i++)
        printf(" ");
    printf("|\n");
    for (int i = 1; i <= consoleWidth; i++)
        printf("-");
    printf("\n");

    printf("\n");
    printf("|");
    printf("请输入姓名:");
    scanf("%s", Name);
    printf("|");
    for (int i = 0; i < consoleWidth - 2; i++)
        printf(" ");
    printf("|\n");
    printf("\n");
    return Name;
}
long long MenuID()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int consoleWidth = 80; // 默认宽度为80
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
    {
        consoleWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    }
    long long ID;
    printf("|");
    printf("请输入相应学号:");
    scanf("%lld", &ID);
    printf("\n|");
    for (int i = 0; i < consoleWidth - 2; i++)
        printf(" ");
    printf("|\n");
    printf("\n");
    return ID;
}
char *MenuPassword()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int consoleWidth = 80; // 默认宽度为80
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
    {
        consoleWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    }
    char *Password = (char *)malloc(sizeof(char) * 20);
    printf("|");
    printf("请输入您的密码:");
    scanf("%s", Password);
    printf("\n|");
    for (int i = 0; i < consoleWidth - 2; i++)
        printf(" ");
    printf("|\n");
    for (int i = 1; i <= consoleWidth; i++)
        printf("-");
    printf("\n");
    return Password;
}

void MenuAdmin()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int consoleWidth = 80; // 默认宽度为80
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
    {
        consoleWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    }

    // 打印顶部框架
    for (int i = 1; i <= consoleWidth; i++)
        printf("-");
    printf("\n");

    // 打印标题并居中
    const char *title = "欢迎进入管理员模式";
    int titleLength = strlen(title) / 3 * 2;
    // printf("%d",titleLength);
    int paddingLeft = (consoleWidth - titleLength - 2) / 2; // 左右均衡
    printf("|");
    for (int i = 0; i < paddingLeft; i++)
        printf(" ");
    printf("%s", title);
    for (int i = 0; i < paddingLeft; i++)
        printf(" ");
    printf("|\n");

    // 打印分隔线
    for (int i = 0; i < consoleWidth; i++)
        printf("-");
    printf("\n");

    // 打印每一行菜单内容，逐行处理
    const char *line1 = "请输入您要进行的操作";
    const char *line2 = "1. 查询所有学生信息";
    const char *line3 = "2. 查询单个学生信息";
    const char *line4 = "3. 修改学生信息";
    const char *line5 = "4. 添加学生信息";
    const char *line6 = "5. 删除学生信息";

    // 打印第1行
    int line1Length = strlen(line1) / 3 * 2;
    paddingLeft = (consoleWidth - line1Length - 2) / 2;
    printf("|");
    for (int i = 0; i < paddingLeft; i++)
        printf(" ");
    printf("%s", line1);
    for (int i = 0; i < paddingLeft; i++)
        printf(" ");
    printf("|\n");

    printf("|");
    for (int i = 0; i < consoleWidth - 2; i++)
        printf(" ");
    printf("|\n");

    // 打印第2行
    int line2Length = strlen(line2) / 3 * 2;
    paddingLeft = (consoleWidth - line2Length - 2) / 2;
    printf("|");
    for (int i = 0; i < paddingLeft; i++)
        printf(" ");
    printf("%s", line2);
    for (int i = 0; i < paddingLeft; i++)
        printf(" ");
    printf("|\n");

    printf("|");
    for (int i = 0; i < consoleWidth - 2; i++)
        printf(" ");
    printf("|\n");

    // 打印第3行
    int line3Length = strlen(line3) / 3 * 2;
    paddingLeft = (consoleWidth - line3Length - 2) / 2;
    printf("|");
    for (int i = 0; i < paddingLeft; i++)
        printf(" ");
    printf("%s", line3);
    for (int i = 0; i < paddingLeft - 1; i++)
        printf(" ");
    printf("|\n");

    printf("|");
    for (int i = 0; i < consoleWidth - 2; i++)
        printf(" ");
    printf("|\n");

    // 打印第4行
    int line4Length = strlen(line4) / 3 * 2;
    paddingLeft = (consoleWidth - line4Length - 2) / 2;
    printf("|");
    for (int i = 0; i < paddingLeft; i++)
        printf(" ");
    printf("%s", line4);
    for (int i = 0; i < paddingLeft - 1; i++)
        printf(" ");
    printf("|\n");

    printf("|");
    for (int i = 0; i < consoleWidth - 2; i++)
        printf(" ");
    printf("|\n");

    // 打印第5行
    int line5Length = strlen(line5) / 3 * 2;
    paddingLeft = (consoleWidth - line5Length - 2) / 2;
    printf("|");
    for (int i = 0; i < paddingLeft; i++)
        printf(" ");
    printf("%s", line5);
    for (int i = 0; i < paddingLeft - 1; i++)
        printf(" ");
    printf("|\n");

    printf("|");
    for (int i = 0; i < consoleWidth - 2; i++)
        printf(" ");
    printf("|\n");

    int line6Length = strlen(line6) / 3 * 2;
    paddingLeft = (consoleWidth - line6Length - 2) / 2;
    printf("|");
    for (int i = 0; i < paddingLeft; i++)
        printf(" ");
    printf("%s", line6);
    for (int i = 0; i < paddingLeft - 1; i++)
        printf(" ");
    printf("|\n");

    // 打印底部框架
    for (int i = 0; i < consoleWidth; i++)
        printf("-");
    printf("\n");
}
void MenuUpdate()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int consoleWidth = 80; // 默认宽度为80
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
    {
        consoleWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    }

    // 打印顶部框架
    for (int i = 1; i <= consoleWidth; i++)
        printf("-");
    printf("\n");

    // 打印标题并居中
    const char *title = "请输入您要修改的信息";
    int titleLength = strlen(title) / 3 * 2;
    // printf("%d",titleLength);
    int paddingLeft = (consoleWidth - titleLength - 2) / 2; // 左右均衡
    printf("|");
    for (int i = 0; i < paddingLeft; i++)
        printf(" ");
    printf("%s", title);
    for (int i = 0; i < paddingLeft; i++)
        printf(" ");
    printf("|\n");

    // 打印分隔线
    for (int i = 0; i < consoleWidth; i++)
        printf("-");
    printf("\n");

    const char *line1 = "1.姓名";
    const char *line2 = "2.密码";
    const char *line3 = "3.余额";
    const char *line4 = "4.班级";
    const char *line5 = "5.管理员";
    const char *line6 = "6.退出";

    // 打印第1行
    int line1Length = strlen(line1) / 3 * 2;
    paddingLeft = (consoleWidth - line1Length - 2) / 2;
    printf("|");
    for (int i = 0; i < paddingLeft; i++)
        printf(" ");
    printf("%s", line1);
    for (int i = 0; i < paddingLeft; i++)
        printf(" ");
    printf("|\n");

    printf("|");
    for (int i = 0; i < consoleWidth - 2; i++)
        printf(" ");
    printf("|\n");

    // 打印第2行
    int line2Length = strlen(line2) / 3 * 2;
    paddingLeft = (consoleWidth - line2Length - 2) / 2;
    printf("|");
    for (int i = 0; i < paddingLeft; i++)
        printf(" ");
    printf("%s", line2);
    for (int i = 0; i < paddingLeft; i++)
        printf(" ");
    printf("|\n");

    printf("|");
    for (int i = 0; i < consoleWidth - 2; i++)
        printf(" ");
    printf("|\n");

    // 打印第3行
    int line3Length = strlen(line3) / 3 * 2;
    paddingLeft = (consoleWidth - line3Length - 2) / 2;
    printf("|");
    for (int i = 0; i < paddingLeft; i++)
        printf(" ");
    printf("%s", line3);
    for (int i = 0; i < paddingLeft - 1; i++)
        printf(" ");
    printf("|\n");

    printf("|");
    for (int i = 0; i < consoleWidth - 2; i++)
        printf(" ");
    printf("|\n");

    // 打印第4行
    int line4Length = strlen(line4) / 3 * 2;
    paddingLeft = (consoleWidth - line4Length - 2) / 2;
    printf("|");
    for (int i = 0; i < paddingLeft; i++)
        printf(" ");
    printf("%s", line4);
    for (int i = 0; i < paddingLeft - 1; i++)
        printf(" ");
    printf("|\n");

    printf("|");
    for (int i = 0; i < consoleWidth - 2; i++)
        printf(" ");
    printf("|\n");

    // 打印第5行
    int line5Length = strlen(line5) / 3 * 2;
    paddingLeft = (consoleWidth - line5Length - 2) / 2;
    printf("|");
    for (int i = 0; i < paddingLeft; i++)
        printf(" ");
    printf("%s", line5);
    for (int i = 0; i < paddingLeft - 1; i++)
        printf(" ");
    printf("|\n");

    printf("|");
    for (int i = 0; i < consoleWidth - 2; i++)
        printf(" ");
    printf("|\n");

    int line6Length = strlen(line6) / 3 * 2;
    paddingLeft = (consoleWidth - line6Length - 2) / 2;
    printf("|");
    for (int i = 0; i < paddingLeft; i++)
        printf(" ");
    printf("%s", line6);
    for (int i = 0; i < paddingLeft - 1; i++)
        printf(" ");
    printf("|\n");

    // 打印底部框架
    for (int i = 0; i < consoleWidth; i++)
        printf("-");
    printf("\n");
}