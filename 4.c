#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h> //library thread

void *print_message_function( void *ptr )
{
    int x=(int *)ptr,total=1;
    for(int i=2;i<=x;i++) total*=i;
    printf("%d! : %d\n", x,total);
}

int main()
{
    pthread_t thread[100];//inisialisasi awal
    char test[100][100];
    int  iret1, iret2,jumlah=0,banyak=0;
    while(1){
        int i=0;
        char a;
        scanf("%d%c",&test[jumlah],&a);
        jumlah++;
        if(a=='\n') break;
    }    

    while(1){
        int *message=test[banyak];
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
