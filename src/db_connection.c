#include "db_connection.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/student.h"
#include "../include/Service.h"
// 数据库连接函数
MYSQL *db_connect()
{
    MYSQL *conn = mysql_init(NULL); // 初始化 MySQL 连接对象
    if (conn == NULL)
    {
        fprintf(stderr, "mysql_init() failed\n");
        return NULL;
    }

    //连接本地mariadb的表格
    if (!mysql_real_connect(conn, HOST, USERNAME, PASSWORD, DATABASE, 0, NULL, CLIENT_FOUND_ROWS))
    {
        fprintf(stderr, "数据库连接失败: %s\n", mysql_error(conn));
        mysql_close(conn);
        return NULL;
    }

    // 设置字符集为 utf8mb3
    if (mysql_query(conn, "SET NAMES utf8mb3"))
    {
        fprintf(stderr, "字符集设置失败: %s\n", mysql_error(conn));
        mysql_close(conn);
        return NULL;
    }
    // printf("11");
    return conn;
}

// 关闭数据库连接
void db_close(MYSQL *conn)
{
    if (conn != NULL)
    {
        mysql_close(conn);
    }
}

// 执行 SQL 查询
void exeSql(MYSQL *conn, const char *sql)
{
    int res;              // 存储 SQL 执行结果
    MYSQL_RES *res_ptr;   // 用来指向 SQL 查询结果的指针
    MYSQL_ROW result_row; // 用于存储从查询结果中读取的一行数据
    // MYSQL_FIELD *field;   // 存储数据库列信息
    int row;      // 查询结果的行和列

    // 执行 SQL 查询
    res = mysql_query(conn, sql);
    if (res)
    {
        fprintf(stderr, "SQL 执行失败: %s\n", mysql_error(conn));
        return;
    }

    // 如果是查询操作 (SELECT)
    if (strncasecmp(sql, "SELECT", 6) == 0)
    {
        // printf("查询结果:\n");

        res_ptr = mysql_store_result(conn);
        if (res_ptr)
        {
            row = (int)mysql_num_rows(res_ptr);
            // column = (int)mysql_num_fields(res_ptr);

            studentnum = row;
            long long i = 0;
            //这个一个字符串类型的一个数组
            while ((result_row = mysql_fetch_row(res_ptr)) != NULL)
            {
                students[i].id = atoll(result_row[1]);                                  // ID 为第一列
                strncpy(students[i].name, result_row[0], sizeof(students[i].name) - 1); // 姓名为第二列
                students[i].name[sizeof(students[i].name) - 1] = '\0';
                students[i].money = atof(result_row[2]);                                          // 金钱为第三列
                // AddUpdata(students[i].id,students[i].money-students[i-1].money);
                strncpy(students[i].classroom, result_row[3], sizeof(students[i].classroom) - 1); // 教室为第四列
                students[i].classroom[sizeof(students[i].classroom) - 1] = '\0';
                students[i].admin = atoi(result_row[4]);
                strncpy(students[i].password, result_row[5], sizeof(students[i].password) - 1);
                students[i].password[sizeof(students[i].password) - 1] = '\0';
                i++;
            }

            mysql_free_result(res_ptr);
        }
    }
}
