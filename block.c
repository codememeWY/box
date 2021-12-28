#include"filecp.h"


int block(const char *sname,int progressnum)
{
	int filesize;
	int blocksize;
	int fd=open(sname,O_RDONLY);

	filesize=lseek(fd,0,SEEK_END);//获取文件大小
	
	if(filesize%progressnum==0)
	{
		return filesize/progressnum;
	}else
	{
		return filesize/progressnum+1;
	}
	
}
