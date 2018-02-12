#include <stdio.h>

void playername_load();
void date_load();
void courase_definition_load();
void information_load();

int course_definition;
int first_log_in_definition = 1;
int day_now;
char playername[3];

int extern user_id;

void game_load(){
	pause(2);
	puts("¸ü¤J¹CÀ¸¤¤...");
	
	playername_load();
	date_load();
	courase_definition_load();
	information_load();
	
}

void playername_load(){
	int id_check;
	FILE *fplayername;
	fplayername = fopen("data/profile/playername.txt", "r");
	
	rewind(fplayername);
	while(!feof(fplayername)){
		fscanf(fplayername, "%d %s", &id_check, playername);
		if(id_check == user_id){
			break;
		}
	}
	
	fclose(fplayername);
}

void date_load(){
	int id_check;
	FILE *fdate;
	fdate = fopen("data/save/date.txt", "r");
	
	rewind(fdate);
	while(!feof(fdate)){
		fscanf(fdate, "%d %d", &id_check, &day_now);
		if(id_check == user_id){
			break;
		}
	}
	
	fclose(fdate);
}

void courase_definition_load(){
	int id_check;
	FILE *fcourse_definition;
	fcourse_definition = fopen("data/save/course_definition.txt", "r");
	
	rewind(fcourse_definition);
	while(!feof(fcourse_definition)){
		fscanf(fcourse_definition, "%d %d", &id_check, &course_definition);
		if(id_check == user_id){
			break;
		}
	}
	
	fclose(fcourse_definition);
}

void information_load(){
	FILE *finformation;
	
}
