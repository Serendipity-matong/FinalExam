#define _CRT_SECURE_NO_WARNINGS 1
#ifndef DB_CONNECTION_H
#define DB_CONNECTION_H
#include "../mysql/mysql.h"

#define HOST "localhost"
#define USERNAME "root"
#define PASSWORD "123"
#define DATABASE "studentcard"

// 函数声明
MYSQL* db_connect();
// void AU(long long i,double k);
void db_close(MYSQL* conn);
void exeSql(MYSQL* conn, const char* sql);

#endif // DB_CONNECTION_H
