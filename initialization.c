#include <stdio.h>
#include <windows.h>
#include <string.h>

void instruction();
void background();

void playername_initialization();
void protagonist_initialization();
void player_birthday_initialization();

void date_initialization();
void time_initialization();
void course_definition_initialization();
void course_record_initialization();
void information_initialization();
void event_initialization();

int extern const user_id;
int extern const textlong;
int extern protagonist_selection;
int extern first_sign_in_definition;

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
			background();
			pause(2);
			instruction();
			pause(2);
			//建立玩家輸入資料
			playername_initialization();
			protagonist_initialization();
			player_birthday_initialization();
			//建立初始設定
			date_initialization();
			time_initialization();
			course_definition_initialization();
			course_record_initialization();
			information_initialization();
			event_initialization();
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
			first_sign_in_definition = 1;
			
			fclose(finitialize_verify);
		}
		if(definition == 1)
			break;
	}
	
}

void background(){
	char text[textlong];
	
	FILE *fbackground;
	fbackground = fopen("data/text/background.txt", "r");
	int i;
	
	while(!feof(fbackground)){
		fscanf(fbackground, "%s", text);
		for(i = 0; text[i] != '\0'; i++){
			if(text[i] == '/')
				Sleep(75);
			else
				printf("%c", text[i]);
			text[i] = '\0';
			Sleep(75);
		}
		printf("\n");
	}
	system("pause");
	fclose(fbackground);
}

void instruction(){
	char text[textlong];
	
	FILE *finstruction;
	finstruction = fopen("data/text/instruction.txt", "r");
	int i;
	
	while(!feof(finstruction)){
		fscanf(finstruction, "%s", text);
		for(i = 0; text[i] != '\0'; i++){
			if(text[i] == '/')
				Sleep(75);
			else
				printf("%c", text[i]);
			text[i] = '\0';
			Sleep(75);
		}
		printf("\n");
	}
	system("pause");
	fclose(finstruction);
}

void playername_initialization(){
	FILE *fplayername;
	fplayername = fopen("data/profile/playername.txt", "a");
	char playername[20];
	
	puts("請輸入你/妳的名字(輸入後無法更改)");
	scanf("%s", playername);
	fprintf(fplayername, "\n%d %s", user_id, playername);
	
	fclose(fplayername);
}

void player_birthday_initialization(){
	FILE *fplayer_birthday;
	fplayer_birthday = fopen("data/profile/player_birthday.txt", "a");
	int player_birthday_month;
	int player_birthday_date;
	int definition = 0;
	
	while(definition != 1){
		puts("請輸入你/妳的生日(輸入後無法更改)(mm/dd)");
		scanf("%d/%d", &player_birthday_month, &player_birthday_date);
		puts("確定嗎？");
		puts("是(1)");
		puts("否(-1)");
		scanf("%d", &definition);
	}
	fprintf(fplayer_birthday, "\n%d %d %d", user_id, player_birthday_month, player_birthday_date);
	fclose(fplayer_birthday);
}

void protagonist_initialization(){
	FILE *fprotagonist;
	fprotagonist = fopen("data/save/protagonist_selection.txt", "a");
	int selection;
	int decision = 0;
	int definition = 0;
	
	while(definition == 0){
		puts("請問要選擇誰？");
		protagonist_name(1);
		puts("(1)");
		protagonist_name(2);
		puts("(2)");
		protagonist_name(3);
		puts("(3)");
		protagonist_name(4);
		puts("(4)");
		
		scanf("%d", &selection);
		if(selection == 5)
			selection = protagonist_hidden();
		else
			protagonist_introduction(selection);
		printf("\n");
		
		if(selection != 0){
			puts("決定？");
			puts("是(1)");
			puts("否(-1)");
			scanf("%d", &decision);
		}
		
		if(decision == 1 && selection != 0)
			definition = 1;
		else if(decision == -1 && selection != 0){
			definition = 0;
			pause(1);
		}
	}
	
	fprintf(fprotagonist, "\n%d %d", user_id, selection);
	protagonist_selection = selection;
	
	fclose(fprotagonist);
}

void date_initialization(){
	FILE *fdate;
	fdate = fopen("data/save/date.txt", "a");
	
	fprintf(fdate, "\n%d %d", user_id, 0);
	
	fclose(fdate);
}

void time_initialization(){
	FILE *ftime;
	ftime = fopen("data/save/time.txt", "a");
	
	fprintf(ftime, "\n%d %d", user_id, 1);
	
	fclose(ftime);
}

void course_definition_initialization(){
	FILE *fcourse_definition;
	fcourse_definition = fopen("data/save/course_definition.txt", "a");
	
	fprintf(fcourse_definition, "\n%d %d", user_id, 1);
	
	fclose(fcourse_definition);
}

void information_initialization(){
	FILE *finformation;
	finformation = fopen("data/save/information.txt", "a");
	
	fprintf(finformation, "\n%d %.2f %.2f %.2f %.2f %.2f %.2f", user_id, 0.00, 0.00, 0.00, 0.00, 0.00, 0.00);
	
	fclose(finformation);
}

void course_record_initialization(){
	FILE *fcourse_record;
	fcourse_record = fopen("data/save/course_record.txt", "a");
	
	fprintf(fcourse_record, "\n%d %d %d %d %d %d", user_id, 0, 0, 0, 0, 0);
	
	fclose(fcourse_record);
	
}

void event_initialization(){
	FILE* fevent;
	fevent = fopen("data/save/event.txt", "a");
	int i;
	
	for(i = 0; i <= 300; i++)
		fprintf(fevent, "\n%d %d %d %d", user_id, protagonist_selection, i, 0);
			
	fclose(fevent);
}
