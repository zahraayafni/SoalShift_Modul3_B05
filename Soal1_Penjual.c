#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>

void main()
{
        key_t key = 1234, key1 = 1235, key2 = 1236, key3 = 1237, key4 = 1238, key5 = 1239;
        int *mp4a1,*pm2_v1,*spr_3,*ss2_v5,*spg1_v3,*mine;
        int shmid = shmget(key, sizeof(int), IPC_CREAT | 0666);
	int shmid1 = shmget(key1, sizeof(int), IPC_CREAT | 0666);
	int shmid2 = shmget(key2, sizeof(int), IPC_CREAT | 0666);
	int shmid3 = shmget(key3, sizeof(int), IPC_CREAT | 0666);
	int shmid4 = shmget(key4, sizeof(int), IPC_CREAT | 0666);
	int shmid5 = shmget(key5, sizeof(int), IPC_CREAT | 0666);
        mp4a1 = shmat(shmid, NULL, 0); pm2_v1 = shmat(shmid1, NULL, 0);
	spr_3 = shmat(shmid2, NULL, 0); ss2_v5 = shmat(shmid3, NULL, 0);
	spg1_v3 = shmat(shmid4, NULL, 0); mine = shmat(shmid5, NULL, 0); 
        *mp4a1 = 0; *pm2_v1 = 0; *spr_3 = 0; *ss2_v5 = 0; *spg1_v3 = 0; *mine = 0;
	int a;
	while(scanf("%d",&a)==1){
	system("clear");
	printf("Pilih salah satu:\n1. Lihat Stock\n2. Tambah Stock\n");
	int pil,amount;
	scanf("%d",&pil);
	if(pil==1){
		printf("Stok saat ini:\n");
		if(*mp4a1 > 0) printf("MP4A1 = %d\n",*mp4a1);
		if(*pm2_v1 > 0) printf("PM2_V1 = %d\n",*pm2_v1);
		if(*spr_3 > 0) printf("SPR_3 = %d\n",*spr_3);
		if(*ss2_v5 > 0) printf("SS2_V5 = %d\n",*ss2_v5);
		if(*spg1_v3 > 0) printf("SPG1_V3 = %d\n",*spg1_v3);
		if(*mine > 0) printf("MINE = %d\n",*mine);
	}
	else if(pil==2){
		char *barang;
		scanf("%s %d",barang,&amount);
		if(strcmp(barang,"MP4A1")==0) *mp4a1 += amount;
		else if(strcmp(barang,"PM2_V1")==0) *pm2_v1 += amount;
		else if(strcmp(barang,"SPR_3")==0) *spr_3 += amount;
		else if(strcmp(barang,"SS2_V5")==0) *ss2_v5 += amount;
		else if(strcmp(barang,"SPG1_V3")==0) *spg1_v3 += amount;
		else if(strcmp(barang,"MINE")==0) *mine += amount;
	}
	
}
        shmdt(mp4a1);shmdt(pm2_v1);shmdt(spr_3);shmdt(ss2_v5);
	shmdt(spg1_v3);shmdt(mine);
        shmctl(shmid, IPC_RMID, NULL);
	shmctl(shmid1, IPC_RMID, NULL);
	shmctl(shmid2, IPC_RMID, NULL);
	shmctl(shmid3, IPC_RMID, NULL);
	shmctl(shmid4, IPC_RMID, NULL);
	shmctl(shmid5, IPC_RMID, NULL);
}

