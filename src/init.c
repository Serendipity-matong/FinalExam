#include <stdio.h>
#include <stdlib.h>
#include "../include/StartSever.h"
#include "../include/student.h"
#include "../include/db_connection.h"
#include "../mysql/mysql.h"
void init()
{
    MYSQL* conn=db_connect();
    if(conn==NULL)
    {
        fprintf(stderr,"数据库连接失败\n");
        return ;
    }
    exeSql(conn,"SELECT * FROM studentcard;");
    db_close(conn);
}