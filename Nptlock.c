#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>

pthread_mutex_t lock;
int fileA,fileB;
int block(char *srcfile,int num)
{
	int fd=open(srcfile,O_RDONLY);
	int seek=lseek(fd,0,SEEK_END);
	fileA=seek;
	close(fd);
	if(seek%num==0)
	{
		return seek/num;
	}else
	{
		return seek/num+1;
	}
}

typedef struct
{
	char *srcfile;
	char *dfile;
	int block;
	int pos;
}threadarg;

void *threadcp(void *arg)
{
	pthread_detach(pthread_self());
		pthread_mutex_unlock(&lock);
		threadarg *a=(threadarg*)arg;
		int sfd=open(a->srcfile,O_RDWR);
		int dfd=open(a->dfile,O_RDWR|O_CREAT,0664);
		
		lseek(sfd,a->pos,SEEK_SET);
		lseek(dfd,a->pos,SEEK_SET);

		char buffer[a->block];
		bzero(buffer,sizeof(buffer));

		int len=read(sfd,buffer,sizeof(buffer));
		write(dfd,buffer,strlen(buffer));//
		printf("Pthread [%x]\t\t...Copy success Pos [%d] Block [%d]\n",(unsigned int)pthread_self(),a->pos,a->block);
//sleep(1);
	pthread_mutex_unlock(&lock);
	pthread_exit(NULL);
}
void print()
{
	int n=0;
	char str[102]={0};
	char *str4="-/\|";
	while(n!=100)
	{
int		fd=open("desfilecp.c",O_RDWR);
		int k=lseek(fd,0,SEEK_END);
		n=k*100/fileA;
		
		for(int i=0;i<=n;i++)
		{
			str[i]='=';
		printf("[%-100s][%d%%]\r",str,i);

		fflush(stdout);
		}
		usleep(100000);
	}

}
int main()

{
	pthread_mutex_init(&lock,NULL);
	//threadarg tpara;
	threadarg tpara[5];
	pthread_t tid;
	int b=block("test.c",5);
	//tpara.srcfile="Npthreadcp.c";
	//tpara.dfile="desfilecp.c";
	//tpara.block=b;
	for(int i=0;i<5;i++)
	{
		tpara[i].srcfile="test.c";
		tpara[i].dfile="desfilecp.c";
		tpara[i].pos=i*b;
		tpara[i].block=b;
		printf("\t\t\t\t赋值block:%d,创建线程\n",tpara[i].pos);
		pthread_create(&tid,NULL,threadcp,(void *)&tpara[i]);
	sleep(0);
	}
	
	while(1)
	{
		//sleep(1);
	print();
	}
	pthread_mutex_destroy(&lock);

	return 0 ;
}

