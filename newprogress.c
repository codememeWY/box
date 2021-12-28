#include"filecp.h"


int newprogress(const char* sname,const char* name,int progressnum,int block)
{
	int flag;
	pid_t pid;
	int pos;
	char cblock[10];
	char cpos[10];
	bzero(cblock,sizeof(cblock));
	bzero(cpos,sizeof(cpos));


	for(flag=0;flag<progressnum;flag++)
	{
		pid=fork();
		if(pid==0)
			break;
	}
	if(pid>0)
	{
		printf("Parent pid is [%d]  非阻塞回收进程\n",getpid());
		pid_t zpid;

		while((zpid=waitpid(-1,NULL,WNOHANG))!=-1)
		{
			if(zpid>0)
			{
				printf("Parent wait successed,zpid is [%d]\n",zpid);
			}
		}
	}else if(pid==0)
	{
		pos=flag*block;//偏移量计算
		sprintf(cblock,"%d",block);
		sprintf(cpos,"%d",pos);
		printf("child \n");
		execl("/home/wangyao/test/progresscp/cp","cp",sname,name,cblock,cpos,NULL);

	}else
	{
		printf("fork fail\n");
		exit(0);
	}

	return 0;

}
