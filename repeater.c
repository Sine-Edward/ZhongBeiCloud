#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <netinet/in.h>

struct user_ID_IP{
	char ID[16];
	char IP[16];
};

struct user_ID_IP id_ip_list[200] = {};
int flag = 0;
int change = 0;

#define SERVPORT 9857
#define BACKLOG 10

int set_char_arr(char* str,char* p,int limit);

int main()
{
	int sock_fd;
	int client_fd;
	int sin_size;
	struct sockaddr_in my_addr;
	struct sockaddr_in remote_addr;

	if( (sock_fd = socket(AF_INET,SOCK_STREAM,0) ) == -1 )
	{printf("socket make err\n");return 0;}
	
	my_addr.sin_family=AF_INET;
	my_addr.sin_port=htons(SERVPORT);
	my_addr.sin_addr.s_addr=INADDR_ANY;
	bzero(&(my_addr.sin_zero),8);

	if(bind(sock_fd,(struct sockaddr*)&my_addr,sizeof(struct sockaddr)) == -1)
	{printf("bind err\n");return 0;}

	if(listen(sock_fd,BACKLOG)==-1)
	{printf("listen err\n");return 0;}

	int i = 0;
	while(1)
	{
		sin_size=sizeof(struct sockaddr_in);
		
		if( (client_fd = accept(sock_fd,(struct sockaddr*)&remote
_addr,&sin_size)) == -1)
		{printf("accept error\n");continue;}

		char buf[100];
		int recvbytes=0;
		if((recvbytes = recv(client_fd,buf,100,0))==-1)
		{printf("recv error");continue;}
		buf[recvbytes] = '\0';
		printf("%s\n",buf);
		buf[0] = '\0';		

		
		i++;
		if(!fork())
		{
			char p[30] ="Hello,you are connected!+";
			p[10] = i+'0';
			if(!send(client_fd,p,26,0))
			{printf("send error\n");}
			close(client_fd);
			return 0;
		}
	}
	return 0;
}

int set_char_arr(char* str,char* p,int limit)
{
	if(limit <= 0)
	{return -1;}

	int i=0;
	for(i=0;i<limit;i++)
	{
		str[i] = p[i];
	}
	return 0;
}
