#include <stdio.h>
#include <stdlib.h>
#include "../include/StartSever.h"
#include "../include/init.h"
#include "../include/menu.h"
#include "../include/Service.h"
// #include "../include/CRUD.h"
void StartSever()
{
    
    init();
    char Menuchoice;
    do
    {
        Menu();
        Sever();
        printf("主菜单是否需要继续操作y/n?");
        scanf(" %c",&Menuchoice);
    } while (Menuchoice=='y'||Menuchoice=='Y');
}