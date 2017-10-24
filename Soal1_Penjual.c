#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>

void main()
{
        key_t key = 1234;
        int *mp4a1,*pm2_v1,*spr_3,*ss2_v5,*spg1_v3,*mine;
        int shmid = shmget(key, sizeof(int), IPC_CREAT | 0666);
        mp4a1 = shmat(shmid, NULL, 0); pm2_v1 = shmat(shmid, NULL, 0);
	spr_3 = shmat(shmid, NULL, 0); ss2_v5 = shmat(shmid, NULL, 0);
	spg1_v3 = shmat(shmid, NULL, 0); mine = shmat(shmid, NULL, 0); 
        *mp4a1,*pm2_v1,*spr_3,*ss2_v5,*spg1_v3,*mine = 0;

	//system("clear");
	printf("Pilih salah satu:\n1. Lihat Stock\n2. Tambah Stock\n");
	int pil,amount;
	scanf("%d",&pil);
	if(pil==1){
		printf("Stok saat ini:\n");
		printf("MP4A1 = %d\n",*mp4a1);
		printf("PM2_V1 = %d\n",*pm2_v1);
		printf("SPR_3 = %d\n",*spr_3);
		printf("SS2_V5 = %d\n",*ss2_v5);
		printf("SPG1_V3 = %d\n",*spg1_v3);
		printf("MINE = %d\n",*mine);
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
	
        shmdt(mp4a1);shmdt(pm2_v1);shmdt(spr_3);shmdt(ss2_v5);
	shmdt(spg1_v3);shmdt(mine);
        shmctl(shmid, IPC_RMID, NULL);
	//}
}

