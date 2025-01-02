#ifndef FILEOPERATION_H
#define FILEOPERATION_H

void GetCurrentData(char *Data, size_t size);

void addfile(const char* filename, long long ID,char *Name,const char* operation,float Money);

void UpdateFile(const char *filename, long long id, char *NewName, char *NewClassroom, int NewAdmin, char *NewPassword,float NewMoney,int choice);

#endif