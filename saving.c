#include <stdio.h>

void date_save();
void course_definition_save();
void information_save();

int extern const user_id;

void game_save(){
	pause(2);
	puts("資料儲存中...\n請勿直接關閉遊戲...");
	
	date_save();
	course_definition_save();
	
	pause(2);
}

void date_save(){
	FILE *fdate;
	FILE *ftemp;
	fdate = fopen("data/save/date.txt", "r");
	ftemp = fopen("data/save/temp.txt", "w");
	int temp;
	int id_check;
	int extern day_now;
	
	rewind(fdate);
	rewind(ftemp);
	while(!feof(fdate)){
		fscanf(fdate, "%d %d", &id_check, &temp);
		fprintf(ftemp, "%d %d\n", id_check, temp);
		if((id_check + 1) == user_id){
			fprintf(ftemp, "%d %d", user_id, day_now);
			fscanf(fdate, "%d %d", &id_check, &temp);
		}
	}
	fclose(ftemp);
	fdate = fopen("data/save/date.txt", "w");
	ftemp = fopen("data/save/temp.txt", "r");
	rewind(fdate);
	rewind(ftemp);
	while(!feof(ftemp)){
		fscanf(ftemp, "%d %d", &id_check, &temp);
		fprintf(fdate, "%d %d", id_check, temp);
		if(!feof(ftemp))
			fprintf(fdate, "\n");
	}
	
	fclose(ftemp);
	fclose(fdate);
}

void course_definition_save(){
	FILE *fcourse_definition;
	FILE *ftemp;
	fcourse_definition = fopen("data/save/course_definition.txt", "r");
	ftemp = fopen("data/save/temp.txt", "w");
	int temp;
	int id_check;
	int extern course_definition;
	
	rewind(fcourse_definition);
	rewind(ftemp);
	while(!feof(fcourse_definition)){
		fscanf(fcourse_definition, "%d %d", &id_check, &temp);
		fprintf(ftemp, "%d %d\n", id_check, temp);
		if((id_check + 1) == user_id){
			fprintf(ftemp, "%d %d", user_id, course_definition);
			fscanf(fcourse_definition, "%d %d", &id_check, &temp);
		}
	}
	fclose(ftemp);
	fcourse_definition = fopen("data/save/course_definition.txt", "w");
	ftemp = fopen("data/save/temp.txt", "r");
	rewind(fcourse_definition);
	rewind(ftemp);
	while(!feof(ftemp)){
		fscanf(ftemp, "%d %d", &id_check, &temp);
		fprintf(fcourse_definition, "%d %d", id_check, temp);
		if(!feof(ftemp))
			fprintf(fcourse_definition, "\n");
	}
	
	fclose(ftemp);
	fclose(fcourse_definition);
	
}


