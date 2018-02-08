#include <stdio.h>
#include <windows.h>
#include <string.h>

int extern user_id;

void initial_setting(){
	pause(2);
	
	FILE *finitialize_verify;
	
	finitialize_verify = fopen("data/profile/initialization.txt", "r");
	
	int verify;
	int id_check;
	int definition = 0;
	rewind(finitialize_verify);
	while(!feof(finitialize_verify)){
		fscanf(finitialize_verify, "%d %d", &id_check, &verify);
		if(verify == 0 && id_check == user_id){
			FILE *fplayername;
			fplayername = fopen("data/profile/playername.txt", "a");
		
			char playername[20];
		
			puts("請輸入你/妳的名字");
			scanf("%s", playername);
			fprintf(fplayername, "\n%d %s", user_id, playername);
		
			puts("基本資料設定完成");
			
			FILE *ftemp;
			ftemp = fopen("data/profile/temp.txt", "w");
			rewind(finitialize_verify);
			rewind(ftemp);
			while(!feof(finitialize_verify)){
				fscanf(finitialize_verify, "%d %d", &id_check ,&verify);
				fprintf(ftemp, "%d %d\n", id_check, verify);
				if((id_check + 1) == user_id){
					fprintf(ftemp, "%d %d", user_id, 1);
					definition = 1;
					break;
				}
			}
			fclose(ftemp);
			
			finitialize_verify = fopen("data/profile/initialization.txt", "w");
			ftemp = fopen("data/profile/temp.txt", "r");
			rewind(finitialize_verify);
			rewind(ftemp);
			while(!feof(ftemp)){
					fscanf(ftemp, "%d %d", &id_check, &verify);
					fprintf(finitialize_verify, "%d %d", id_check, verify);
					if(!feof(ftemp))
						fprintf(finitialize_verify, "\n");
				}
			
			fclose(fplayername);
			fclose(finitialize_verify);
			remove("data/profile/temp.txt");
		}
		if(definition == 1)
			break;
	}
	
}
