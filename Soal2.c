#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<math.h>
#include<sys/wait.h>

#define true 1
#define false 0
char player1[20],player2[20];
int board1[16],board2[16],poin1,poin2,ke,b1,b2;
pthread_t tid[20];

void inti(char *p1,char *p2)
{
	int status,lobang,trial=0; char a;
	printf("%s masukkan nomor lubang tempat ranjau",p1);
	   while(trial<4){
		scanf("%d%c",&lobang,&a);
		if(strcmp(p1,player1)==0){board1[lobang]=1; b1++;}
		else if(strcmp(p1,player2)==0){board2[lobang]=1; b2++;}
		trial++;
		if(a=='\n') break;
		}
	   printf("%s Tebak dimana ranjau berada",p2);
	   for(status=0;status<4;status++)
		{scanf("%d",&lobang);
		if(strcmp(p1,player1)==0){
			if(board1[lobang]==1) poin1++;
			else poin2++;
		}
		else if(strcmp(p1,player2)==0){
			if(board2[lobang]==1) poin2++;
			else poin1++;
		}
	}
}
void* play(void *arg)
{
	pthread_t id=pthread_self();
	
	if(pthread_equal(id,tid[ke]))
	{
	   if(ke&1) inti(player1,player2);
	   else inti(player2,player1);
		
	}

	return NULL;
}

int main(void)
{
	int i,j,err,status;
	memset(board1,0,sizeof(board1));
	memset(board2,0,sizeof(board2));
	printf("Masukkan nama player 1: ");
	scanf("%s",player1);
	printf("\nMasukkan nama player 2: ");
	scanf("%s",player2);
	ke = 0;
	while(poin1<=10||poin2<=10||b1<=16||b2<=16)
	{
		err=pthread_create(&(tid[ke]),NULL,&play,NULL);//membuat thread
		if(err!=0)//cek error
		{
			printf("\n can't create thread : [%s]\n",strerror(err));
		}
		else
		{
			printf("\n create thread success\n");
		}
		sleep(1);
		while(wait(&status)>0);
		ke++;
	}
	for(j=0;j<ke;j++)
	pthread_join(tid[j],NULL);

	return 0;
}
