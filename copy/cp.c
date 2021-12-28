#include"filecp.h"

int main(int argc,char** argv)
{
		//argv[1]=sfile argv[2]=dfile argv[3]=blocksize argv[4]=pos
		int blocksize=atoi(argv[3]);
		int pos=atoi(argv[4]);
		char buffer[blocksize];
		bzero(buffer,sizeof(buffer));
		
		int sfd=open(argv[1],O_RDONLY);//文件描述符
		int dfd=open(argv[2],O_WRONLY|O_CREAT,0664);
		lseek(sfd,pos,SEEK_SET);
		lseek(dfd,pos,SEEK_SET);
		printf("CP childpro pid is [%d],pos is [%d],blocksize is [%d]\n",getpid(),pos,blocksize);
		int rdsize;
		rdsize=read(sfd,buffer,sizeof(buffer));
		write(dfd,buffer,rdsize);
		printf("cp acomplished\n");
		return 0;

}
