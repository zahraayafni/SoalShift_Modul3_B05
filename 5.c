#include <stdio.h>
#include <stdlib.h>
#include <pthread.h> //library thread

void *print_message_function( void *ptr )
{
    char *message,*temp;
    int total=0;
    message = (char *) ptr;
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
    const char *message;
    int  iret1, iret2,flag=0;
    while(1){
        int i=0;
        flag=0;
        while(1){
            message[i]=getchar();
            if(message[i]==' '){
                message[i]=='\0';break;
            }
            if(message[i]=='\n'){
                message[i]=='\0';flag=1;break;
            }
            i++;
        }
        iret1 = pthread_create( &thread[banyak], NULL, print_message_function, (void*) message);//membuat thread pertama
        if(iret1)//jika eror
        {
            fprintf(stderr,"Error - pthread_create() return code: %d\n",iret1);
            exit(EXIT_FAILURE);
        }
        banyak++;
        if(flag) break;
    }
    for(int i=0;i<banyak;i++){
        pthread_join( thread[i], NULL);    
    }
     exit(EXIT_SUCCESS);
}
