#include"filecp.h"


int check(const char* sname,int argnum,int progressnum)
{
		if((access(sname,F_OK))!=0)
		{
			perror("check file error");
			exit(-1);
		}
		if(argnum<3)
		{
			printf("check error:参数过少\n");
			exit(-1);
		}
		if(progressnum<=0 || progressnum>10)
		{
			printf("progress 应大于0  or 小于10\n");
			exit(-1);
		}
		return 0;
}
