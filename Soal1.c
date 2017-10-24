#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>

void main()
{
        key_t key = 1234;
        int *mp4a1,*pm2_v1,*spr_3,*ss2_v5,*spg1_v3,*mine,amount;
        int shmid = shmget(key, sizeof(int), IPC_CREAT | 0666);
        mp4a1 = shmat(shmid, NULL, 0); pm2_v1 = shmat(shmid, NULL, 0);
	spr_3 = shmat(shmid, NULL, 0); ss2_v5 = shmat(shmid, NULL, 0);
	spg1_v3 = shmat(shmid, NULL, 0); mine = shmat(shmid, NULL, 0); 
        *mp4a1,*pm2_v1,*spr_3,*ss2_v5,*spg1_v3,*mine = 0;
	
	printf("Pilih salah satu:\n1. Lihat Stock\n2. Tambah Stock\n");
	int pil;
	scanf("%d",&pil);
	if(pil==1){
		printf("Stok saat ini:\n");
		printf("MP4A1 = %d",*mp4a1);
		printf("PM2_V1 = %d",*pm2_v1);
		printf("SPR_3 = %d",*spr_3);
		printf("SS2_V5 = %d",*ss2_v5);
		printf("SPG1_V3 = %d",*spg1_v3);
		printf("MINE = %d",*mine);
	}
	char barang[15];
	scanf("%s%d",barang,amount);
	if(strcmp(barang,"MP4A1")==0) *mp4a1 += amount;
	else if


        shmdt(value);
        shmctl(shmid, IPC_RMID, NULL);
}

