#ifndef STUDENT_H
#define STUDENT_H

#define MAX_NUM 101

typedef struct
{
    long long id;
    char name[MAX_NUM];
    float money;
    char classroom[MAX_NUM];
    int admin;
    char password[MAX_NUM];
} Student;

extern Student students[MAX_NUM];
extern int studentnum;
// extern double tree[300010];

#endif
