#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <wchar.h>
#include <windows.h>
#include "../include/Menu.h"
#include "../include/StartSever.h"
#include "../include/Service.h"
#include "../include/student.h"
#include "../include/db_connection.h"
#include "../include/fileoperation.h"
const char *fields[] = {
    "student",
    "id",
    "money",
    "class",
    "administrator",
    "password"};
// void AddUpdata(long long x,float k)
// {
//     for(;x<=studentnum;x+=x&-x)
//        tree[x]+=k;
// }
// float Query(long long x)
// {
//     float res;
//     for(;x>=1;x-=x&-x)
//     res+=tree[x];
//     return res;
// }
void Sever()
{
    int choice;
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        check();
        break;
    case 2:
        admin();
        break;
    case 3:
        recharge();
        break;
    case 4:
        About();
        break;
    case 5:
        Help();
        break;
    default:
        break;
    }
}

// 校园卡查询函数
void check()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int consoleWidth = 80; // 默认宽度为80
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))//调用控制台函数，将控制台的信息传到csbi中
    {
        consoleWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    }
    bool found = 0;
    long long ID;
    char *Name = malloc(100 * sizeof(char));
    char *Password = malloc(256 * sizeof(char));
    Name = MenuName();

    ID = MenuID();

    Password = MenuPassword();

    for (int i = 0; i < studentnum; i++)
    {
        if (students[i].id == ID && strcmp(students[i].name, Name) == 0 && strcmp(students[i].password, Password) == 0)
        {
            found = 1;
            printf("已查询到您的账户\n");
            printf("您的余额为：%.2f\n", students[i].money);
            for (int i = 1; i <= consoleWidth; i++)
                printf("-");
            printf("\n");
            break;
        }
    }
    if(!found)
    {
        printf("用户名或密码错误\n");
    }
    //
    // if (ID>studentnum)
    // printf("用户名或密码错误\n");
    // else
    // printf("%.2f",Query(ID));
    for (int i = 1; i <= consoleWidth; i++)
        printf("-");
    printf("\n");
}

void admin()
{
    // CONSOLE_SCREEN_BUFFER_INFO csbi;
    // int consoleWidth = 80; // 默认宽度为80
    // if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
    // {
    //     consoleWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    // }
    float NewMoney = 0;
    char NewClass[256];
    bool found = 0;
    long long ID;
    char Menuchoice;
    char *Name = malloc(100 * sizeof(char));
    char NewName[256];
    int NewAdmin = 0;
    ;
    char *NewPassword = malloc(256 * sizeof(char));
    char *Password = malloc(256 * sizeof(char));

    Name = MenuName();

    ID = MenuID();

    Password = MenuPassword();

    for (int i = 0; i < studentnum; i++)
    {
        if (students[i].id == ID && strcmp(students[i].name, Name) == 0 && strcmp(students[i].password, Password) == 0&&students[i].admin==1)
        {
            found = 1;
            printf("已成功验证您的管理员身份\n");

            break;
        }
    }
    if (!found)
    {
        printf("用户名或密码错误\n");
        return;
    }
    do
    {
        MenuAdmin();
        int choicelarge;
        int choice;
        scanf("%d", &choicelarge);
        switch (choicelarge)
        {
        case 1:
            printf("下面是所有学生的信息\n");
            for (int i = 0; i < studentnum; i++)
            {
                printf("学号:%lld\n", students[i].id);
                printf("姓名:%s\n", students[i].name);
                printf("密码:%s\n", students[i].password);
                printf("余额:%.2f\n", students[i].money);
                printf("班级:%s\n", students[i].classroom);
            }
            break;
        case 2:
            printf("请输入您要查询的学号:");
            scanf("%lld", &ID);
            for (int i = 0; i < studentnum; i++)
            {
                if (students[i].id == ID)
                {
                    printf("学号:%lld\n", students[i].id);
                    printf("姓名:%s\n", students[i].name);
                    printf("密码:%s\n", students[i].password);
                    printf("余额:%.2f\n", students[i].money);
                    printf("班级:%s\n", students[i].classroom);
                    break;
                }
            }
            break;
        case 3:
            printf("请输入您要修改的学号:");
            scanf("%lld", &ID);
            for (int i = 0; i < studentnum; i++)
            {
                if (students[i].id == ID)
                {
                    MenuUpdate();
                    scanf("%d", &choice);
                    switch (choice)
                    {
                    case 1:
                        printf("请输入新的姓名:");
                        scanf("%s", NewName);
                        // printf("%s & %lld",NewName,ID);
                        break;
                    case 2:
                        printf("请输入新的密码:");
                        scanf("%s", NewPassword);
                        break;
                    case 3:
                        printf("请输入新的余额:");
                        scanf("%f", &NewMoney);
                        break;
                    case 4:
                        printf("请输入新的班级:");
                        scanf("%s", NewClass);
                        break;
                    case 5:
                        printf("请输入新的管理员:");
                        scanf("%d", &NewAdmin);
                        break;
                    case 6:
                        break;
                    default:
                        break;
                    }
                    break;
                }
            }
            break;
        case 4:
            printf("请输入您要添加的学生信息\n");
            printf("请输入学号:");
            scanf("%lld", &ID);
            printf("请输入姓名:");
            scanf("%s", NewName);
            printf("请输入密码:");
            scanf("%s", NewPassword);
            printf("请输入余额:");
            scanf("%f", &NewMoney);
            printf("请输入班级:");
            scanf("%s", NewClass);
            printf("请决定是否需要管理员模式:");
            scanf("%d", &NewAdmin);
            students[studentnum].id = ID;
            strcpy(students[studentnum].name, Name);
            strcpy(students[studentnum].password, Password);
            students[studentnum].money = NewMoney;
            strcpy(students[studentnum].classroom, NewClass);
            students[studentnum].admin = NewAdmin;
            studentnum++;
            break;
        case 5:
            printf("请输入您要删除的学号:");
            scanf("%lld", &ID);
            for (int i = 0; i < studentnum; i++)
            {
                if (students[i].id == ID)
                {
                    for (int j = i; j < studentnum - 1; j++)
                    {
                        students[j] = students[j + 1];
                    }
                    studentnum--;
                    break;
                }
            }
            break;
        default:
            break;
        }
        MYSQL *conn = db_connect();
        if (conn == NULL)
        {
            fprintf(stderr, "数据库连接失败\n");
            return;
        }    
        char sql[1000];
        if (choicelarge == 3)
        {
            if (choice == 1)
            {
                // printf("%s\n",students[i].name);
                sprintf(sql, "UPDATE studentcard SET student='%s' WHERE id=%lld", NewName, ID);
                exeSql(conn, sql);
                UpdateFile("../Studentsinf.txt", ID, NewName, NewClass, NewAdmin, NewPassword, NewMoney, choice);
            }
            else if (choice == 2)
            {
                sprintf(sql, "UPDATE studentcard SET password='%s' WHERE id=%lld", NewPassword, ID);
                exeSql(conn, sql);
            }
            else if (choice == 3)
            {
                sprintf(sql, "UPDATE studentcard SET money=%.2f WHERE id=%lld", NewMoney, ID);
                exeSql(conn, sql);
            }
            else if (choice == 4)
            {
                sprintf(sql, "UPDATE studentcard SET class='%s' WHERE id=%lld", NewClass, ID);
                exeSql(conn, sql);
            }
            else if (choice == 5)
            {
                sprintf(sql, "UPDATE studentcard SET administrator=%d WHERE id=%lld", NewAdmin, ID);
                exeSql(conn, sql);
            }
        }
        else if (choicelarge == 4)
        {
            snprintf(sql, sizeof(sql), "INSERT INTO studentcard (student,id,money,class,administrator,password)"
                                       "VALUES('%s',%lld,%.2f,'%s',%d,'%s')",
                     NewName, ID, NewMoney, NewClass, NewAdmin, NewPassword);
            exeSql(conn, sql);
        }
        else if (choicelarge == 5)
        {
            sprintf(sql, "DELETE FROM studentcard WHERE id = %lld", ID);
            exeSql(conn, sql);
        }
        // if(found==1)
        // {
        db_close(conn);
        FILE *file = fopen("../Studentsinf.txt", "r+");
        if (!file)
        {
            printf("无法打开文件\n");
        }
        printf("是否需要继续操作y/n?");
        scanf(" %c", &Menuchoice);
    } while (Menuchoice == 'y' || Menuchoice == 'Y');

    //     MYSQL *conn = db_connect();
    //     if (conn == NULL)
    //     {
    //         fprintf(stderr, "数据库连接失败\n");
    //         return;
    //     }
    //     char sql[1000];
    //     for (int i = 0; i < studentnum; i++)
    //     {
    //         // 构造更新语句
    //         sprintf(sql, "UPDATE studentcard SET money = %.2f WHERE id = %lld", students[i].money, students[i].id);
    //         exeSql(conn, sql); // 执行 SQL 更新
    //     }
    //     // if(found==1)
    //     // {
    //     db_close(conn);
    //     FILE *file = fopen("../Studentsinf.txt", "r+");
    //     if (!file)
    //     {
    //         printf("无法打开文件\n");
    //     }
}

void recharge()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int consoleWidth = 80; // 默认宽度为80
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
    {
        consoleWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    }
    float Money;
    bool found = 0;
    long long ID;
    char Name[256];
    char *Password = malloc(100 * sizeof(char));
    printf("下面进行身份验证\n");
    printf("请输入您的姓名和学号\n");
    printf("请输入姓名:");
    scanf("%s", Name);
    for (int i = 1; i <= consoleWidth; i++)
        printf("-");
    printf("\n");

    printf("请输入相应学号:");
    scanf("%lld", &ID);
    for (int i = 1; i <= consoleWidth; i++)
        printf("-");
    printf("\n");

    printf("请输入您的密码:");
    scanf("%s", Password);
    for (int i = 1; i <= consoleWidth; i++)
        printf("-");
    printf("\n");

    for (int i = 0; i < studentnum; i++)
    {
        if (students[i].id == ID && strcmp(students[i].name, Name) == 0 && strcmp(students[i].password, Password) == 0)
        {
            found = 1;
            printf("已查询到您的账户\n");
            printf("请输入充值金额:");
            scanf("%f", &Money);
            students[i].money += Money;
            printf("充值成功\n");
            printf("您的余额为：%.2f\n", students[i].money);
            for (int i = 1; i <= consoleWidth; i++)
                printf("-");
            printf("\n");
            break;
        }
    }
    if (!found)
        printf("用户名或密码错误\n");
    for (int i = 1; i <= consoleWidth; i++)
        printf("-");
    printf("\n");

    MYSQL *conn = db_connect();
    if (conn == NULL)
    {
        fprintf(stderr, "数据库连接失败\n");
        return;
    }
    char sql[1000];
    for (int i = 0; i < studentnum; i++)
    {
        // 构造更新语句
        sprintf(sql, "UPDATE studentcard SET money = %.2f WHERE id = %lld", students[i].money, students[i].id);
        exeSql(conn, sql); // 执行 SQL 更新
    }
    // if(found==1)
    // {
    db_close(conn);
    FILE *file = fopen("../Studentsinf.txt", "r+");
    if (!file)
    {
        printf("无法打开文件\n");
    }
    addfile("../Studentsinf.txt", ID, Name, "充值", Money);
    // printf("所有数据已成功更新到数据库！\n");
}
void About()
{
    printf("本程序是关于南昌大学校园卡的使用，用于用户的充值消费及管理员查询.\n");
    printf("version:1.0.0\n");
    printf("开发时间：12.21 开发者：方梓杰 软工2401 学号8002124005 \n");
}
void Help()
{
    printf("本程序主要分为查询余额，管理员管控和校园卡充值系统，三大模块，所有的功能基于mysql的数据库操作，同时能利用file文件实时监控用户的充值记录，输入对应操作即可查询\n");
}
