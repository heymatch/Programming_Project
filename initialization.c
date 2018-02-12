#include <stdio.h>
#include <windows.h>
#include <string.h>

void playername_initialization();
void protagonist_initialization();
void date_initialization();
void course_definition_initialization();
void information_initializtion();

int extern const user_id;

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
			//建立玩家輸入資料
			playername_initialization();
			//建立初始設定
			date_initialization();
			course_definition_initialization();
			//建立新驗證碼 
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
			
			puts("基本資料設定完成");
			
			fclose(finitialize_verify);
		}
		if(definition == 1)
			break;
	}
	
}

void playername_initialization(){
	FILE *fplayername;
	fplayername = fopen("data/profile/playername.txt", "a");
	char playername[20];
	
	puts("請輸入你/妳的名字");
	scanf("%s", playername);
	fprintf(fplayername, "\n%d %s", user_id, playername);
	
	fclose(fplayername);
}

void date_initialization(){
	FILE *fdate;
	fdate = fopen("data/save/date.txt", "a");
	
	fprintf(fdate, "\n%d %d", user_id, 0);
	
	fclose(fdate);
}

void course_definition_initialization(){
	FILE *fcourse_definition;
	fcourse_definition = fopen("data/save/course_definition.txt", "a");
	
	fprintf(fcourse_definition, "\n%d %d", user_id, 1);
	
	fclose(fcourse_definition);
}


