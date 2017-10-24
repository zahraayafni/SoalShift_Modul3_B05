#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h> //library thread

int lohan,kepiting,statuslohan,statuskepiting;

void *print_message_function( void *ptr )
{
    int x=(int)ptr,total=1;
    if(x==0){
        while(lohan>0&&lohan<=100){
            sleep(10);
            lohan-=15;
        }
        statuslohan=1;
    }
    else{
        while(kepiting>0&&kepiting<=100){
            sleep(20);
            kepiting-=10;
        }
        statuskepiting=1;
    }
}

int main()
{
    statuskepiting = statuslohan =0;
    lohan=kepiting=100;
    pthread_t thread[2];
    int a=0;
    iret1 = pthread_create( &thread[banyak], NULL, print_message_function, (void*) a++);//membuat thread pertama
    if(iret1)//jika eror
    {
        fprintf(stderr,"Error - pthread_create() lohan return code: %d\n",iret1);
        exit(EXIT_FAILURE);
    }
    iret1 = pthread_create( &thread[banyak], NULL, print_message_function, (void*) a);//membuat thread pertama
    if(iret1)//jika eror
    {
        fprintf(stderr,"Error - pthread_create() kepiting return code: %d\n",iret1);
        exit(EXIT_FAILURE);
    }    
    for(int i=0;i<2;i++){
        pthread_join( thread[i], NULL);    
    }
    while(1){
        int i=0;
        char a;
        system("clear");
        printf("1. memberi makan lohan\n2. memberi makan kepiting\n masukan kode kegiatannya"
        scanf("%d",&i);
        if(i==1) lohan+=10;
        else kepiting+=10;
        if(statuskepiting&&statuslohan) break;
    }
     exit(EXIT_SUCCESS);
}
