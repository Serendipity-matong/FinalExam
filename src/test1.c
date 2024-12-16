#define _CRT_SECURE_NO_WARNINGS 1
 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*引入连接Mysql的头文件和lib包*/
#include "mysql/mysql.h"
#pragma comment(lib,"libmysql")
 
/*定义一些数据库连接需要的宏*/
#define HOST "localhost" /*MySql服务器地址*/
#define USERNAME "root" /*用户名*/
#define PASSWORD "123" /*数据库连接密码*/
#define DATABASE "school" /*需要连接的数据库*/
 
// 执行sql语句的函数
void exeSql(char* sql) {
    MYSQL my_connection; /*数据库连接*/
    int res;  /*执行sql语句后的返回标志*/
    MYSQL_RES* res_ptr; /*执行结果*/
    MYSQL_ROW result_row; /*按行返回查询信息*/
    MYSQL_FIELD* field;   /*返回表字段*/
    int row, column; /* 定义行数,列数*/
    mysql_init(&my_connection);
    if (mysql_real_connect(&my_connection, HOST, USERNAME, PASSWORD, DATABASE, 0, NULL, CLIENT_FOUND_ROWS))
    {
        //printf("数据库连接成功！");
        /*vs默认编码为 gbk 防止乱码*/
        mysql_query(&my_connection, "set names gbk");
        res = mysql_query(&my_connection, sql);
        if (res) {
            /*现在就代表执行失败了*/
            printf("Error： mysql_query !\n");
            /*不要忘了关闭连接*/
            mysql_close(&my_connection);
        }
        else 
        {
            /*现在就代表执行成功了*/
            /*mysql_affected_rows会返回执行sql后影响的行数*/
            printf("%lld 行受到影响！\n", mysql_affected_rows(&my_connection));
            // 把查询结果装入 res_ptr
            res_ptr = mysql_store_result(&my_connection);
            // 存在则输出
            if (res_ptr) 
            {
                // 获取行数，列数
                row = (int)mysql_num_rows(res_ptr);
                column = (int)mysql_num_fields(res_ptr);
 
                //打印字段
                field = mysql_fetch_fields(res_ptr);
                for (int i = 0; i < column; i++)
                {
                    printf("%s ", field->name);
                    field++;
                }
                printf("\n");
 
                // 执行输出结果,从第二行开始循环（第一行是字段名）
                for (int i = 1; i < row + 1; i++)
                {
                    // 一行数据
                    result_row = mysql_fetch_row(res_ptr);             
                    for (int j = 0; j < column; j++)
                    {
                        printf("%s ", result_row[j]);
                    }
                    printf("\n");
                }
            }
            /*不要忘了关闭连接*/
            mysql_close(&my_connection);
        }
    }
    else
    {
        printf("数据库连接失败！");
    }
}
 
 
 
int main()
{
    exeSql("insert into user values ('02','张三',90);");
 
    exeSql("insert into user values ('01','李四',90);");
 
    exeSql("select * from user;");
 
	return 0;
} 