#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/wait.h>

int block(const char* sname,int progressnum);
int check(const char* sname,int argnum,int progressnum);
int newprogress(const char *sname,const char *name,int progressnum,int block);
