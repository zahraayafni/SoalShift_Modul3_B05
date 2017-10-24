#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h> //library thread

void *print_message_function( void *ptr )
{
    char message[100],temp[100];
    int total=0;
    strcpy(message, ptr);
    message[strlen(message)-1]='\0';
    FILE *novel;
    novel=fopen("novel.txt","r");
    while(fgets(temp,1024,novel)!=NULL){
		if(strstr(temp,message)){
            for(int i=0;i<=strlen(temp)-strlen(message);i++){
                if(temp[i]==message[0]){
                    int flag=1;
                    for(int j=0;j<strlen(message);j++,i++){
                        if(message[j]!=temp[i]){
                            flag=0;break;
                        }
                    }
                    i--;
                    total+=flag;
                }
            }
		}
	}
    printf("%s : %d\n", message,total);
}

int main()
{
    pthread_t thread[100];//inisialisasi awal
    char test[100][100];
    int  iret1, iret2,flag=0,jumlah=0,banyak=0;
    while(1){
        int i=0;
        flag=0;
        while(1){
            test[jumlah][i]=getchar();
            if(test[jumlah][i]==' '){
                test[jumlah][i]=='\0';break;
            }
            if(test[jumlah][i]=='\n'){
                test[jumlah][i]=='\0';flag=1;break;
            }
            i++;
        }
        jumlah++;
        if(flag) break;
    }    

    while(1){
        const char *message=test[banyak];
        iret1 = pthread_create( &thread[banyak], NULL, print_message_function, (void*) message);//membuat thread pertama
        if(iret1)//jika eror
        {
            fprintf(stderr,"Error - pthread_create() return code: %d\n",iret1);
            exit(EXIT_FAILURE);
        }
        banyak++;
        if(jumlah==banyak) break;
    }
    for(int i=0;i<banyak;i++){
        pthread_join( thread[i], NULL);    
    }
     exit(EXIT_SUCCESS);
}
