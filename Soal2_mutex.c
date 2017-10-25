#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
 
pthread_t tid1;
pthread_t tid2;
char player1[20],player2[20];
int board1[16],board2[16],poin1,poin2,ke,b1,b2,status;
 
void* input(void *arg)
{
    status = 0;
 	int s,lobang,trial=0; char a;
	while(wait(&s)>0);
   if(ke&1) printf("%s masukkan nomor lubang tempat ranjau\n",player1);
	else printf("%s masukkan nomor lubang tempat ranjau\n",player2);
	   while(trial<4){
		scanf("%d%c",&lobang,&a);
		if(ke&1){board1[lobang]=1; b1++;}
		else {board2[lobang]=1; b2++;}
		trial++;
		if(a=='\n') break;
		}
 
    status = 1;
 
    return NULL;
}


void* tebak(void *arg)
{
    while(status != 1)
    {

    }
	int i,s,lobang;
	while(wait(&s)>0);
    if(ke&1) printf("%s Tebak dimana ranjau berada\n",player2);
	else printf("%s Tebak dimana ranjau berada\n",player1);
	   for(i=0;i<4;i++)
		{scanf("%d",&lobang);
		if(ke&1){
			if(board1[lobang]==1) poin1++;
			else poin2++;
		}
		else {
			if(board2[lobang]==1) poin2++;
			else poin1++;
		}
	}
}
 
int main(void)
{
	memset(board1,0,sizeof(board1));
	memset(board2,0,sizeof(board2));
	printf("Masukkan nama player 1: ");
	scanf("%s",player1);
	printf("\nMasukkan nama player 2: ");
	scanf("%s",player2);
	ke =1; int s; poin1,poin2=0;
	while(1){
		printf("poin1 %d poin2 %d b1 %d b2 %d\n",poin1,poin2,b1,b2);
    		pthread_create(&(tid1), NULL, &input, NULL);
		sleep(7);
		pthread_create(&(tid2), NULL, &tebak, NULL);
		sleep(7);
		if(poin1>10||poin2>10||b1>16||b2>16) break;
		ke++;
	}
	pthread_join(tid1, NULL);
    	pthread_join(tid2, NULL);

	printf("%d %d\n",poin1,poin2);
	if(poin1>poin2) printf("Hore! %s menang!!\n",player1);
	else if(poin1==poin2) printf("Permainan berakhir seri\n");
	else printf("Hore! %s menang!!\n",player2);
  
    return 0;
}
