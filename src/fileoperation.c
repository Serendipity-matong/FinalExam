#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "../include/Service.h"
#include "../include/fileoperation.h"
// #include "../include/Service.h"

void GetCurrentData(char *Data, size_t size)
{
    time_t rawtime;
    struct tm *timeinfo;
    //获取当前时间——秒级时间戳
    time(&rawtime);
    //将时间戳转换为本地时间
    timeinfo = localtime(&rawtime);
    //格式化日期，年月日
    strftime(Data, size, "%Y.%m.%d", timeinfo);
}

void addfile(const char *filename, long long id, char *name, const char *operation, float amount)
{
    FILE *file = fopen(filename, "r+"); // 打开文件进行读取和写入
    if (!file)
    {
        printf("无法打开文件\n");
        return;
    }

    FILE *tempFile = tmpfile(); // 创建临时文件
    if (!tempFile)
    {
        printf("无法创建临时文件\n");
        fclose(file);
        return;
    }

    char line[500];
    char date_str[80];
    int found = 0;

    // 获取当前日期
    GetCurrentData(date_str, sizeof(date_str));

    // fseek(file, 0, SEEK_END);
    // long file_size = ftell(file);
    // if (file_size == 0) {
    //     printf("文件为空！\n");
    //     fclose(file);
    //     return;
    // }

    // // 将文件指针重置回文件开头
    // fseek(file, 0, SEEK_SET);
    //     while (fgets(line, sizeof(line), file)) {
    //     printf("fgets 返回: %s\n", line);
    //     // 其他代码...
    // }

    // 逐行读取原文件，并根据条件处理
    while (fgets(line, sizeof(line), file))
    {
        long long student_id;
        char student_name[200];
        float balance;
        int class_id;
        //  printf("%s",line);
        // 如果该行是学生的基本信息
        if (sscanf(line, "学号:%lld 姓名:%s 余额:%f 班级:%d", &student_id, student_name, &balance, &class_id) == 4)
        {
            // 如果找到匹配的学号和姓名，添加操作记录
            fputs(line, tempFile);
            if (student_id == id && strcmp(student_name, name) == 0)
            {
                fprintf(tempFile, "%s %s %s %.2f元\n", date_str, operation, name, amount);
                found = 1;
            }
        }
        else
            // 将原文件的内容写入临时文件
            fputs(line, tempFile);
    }

    if (!found)
    {
        printf("未找到匹配的学生: 学号: %lld 姓名: %s\n", id, name);
    }

    // 将临时文件的内容写回原文件
    rewind(tempFile);             // 移动文件指针到文件开头
    freopen(filename, "w", file); // 重新打开文件以清空原文件内容

    // 将临时文件内容写回原文件
    while (fgets(line, sizeof(line), tempFile))
    {
        fputs(line, file);
    }

    fclose(tempFile);
    fclose(file);
}

void UpdateFile(const char *filename, long long id, char *NewName, char *NewClassroom, int NewAdmin, char *NewPassword, float NewMoney, int choice)
{
    char line[500];
    FILE *file = fopen(filename, "r+"); // 打开文件进行读取和写入
    if (!file)
    {
        printf("无法打开文件\n");
        return;
    }

    FILE *tempFile = tmpfile(); // 创建临时文件
    if (!tempFile)
    {
        printf("无法创建临时文件\n");
        fclose(file);
        return;
    }

    if (choice == 3)
    {
        while (fgets(line, sizeof(line), file))
        {
            long long student_id;
            char *Name = (char *)malloc(sizeof(char) * 200);
            float Money;
            int Admin;
            char *Password = (char *)malloc(sizeof(char) * 200);
            char *Classroom = (char *)malloc(sizeof(char) * 200);
            if (sscanf(line, "学号:%lld 姓名:%s 余额:%f 班级:%s 管理员:%d 密码:%s", &student_id, Name, &Money, Classroom, &Admin, Password) == 6)
            {
                if (student_id == id)
                {
                    fprintf(file, "学号:%lld 姓名:%s 余额:%.2f 班级:%s 管理员:%d 密码:%s\n", id, NewName, NewMoney, NewClassroom, NewAdmin, NewPassword);
                }
            }
            else
                fputs(line, tempFile);
        }
        rewind(tempFile);             // 移动文件指针到文件开头
        freopen(filename, "w", file); // 重新打开文件以清空原文件内容
        // 将临时文件内容写回原文件
        while (fgets(line, sizeof(line), tempFile))
        {
            fputs(line, file);
        }

        fclose(tempFile);
        fclose(file);
    }
    // else if(choice==4)
    // {

    // }
}