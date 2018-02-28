#include <stdio.h>

void date_save();
void time_save();
void course_definition_save();
void information_save();
void course_record_save();

struct status{
	int talent;
	int record;
	int phrase[6];
	float add;
	float now;
};

struct status extern chinese;
struct status extern english;
struct status extern math;
struct status extern social;
struct status extern science;
struct status extern favorability;

int extern const user_id;
int extern protagonist_selection;

void game_save(){
	pause(2);
	puts("資料儲存中...\n請勿直接關閉遊戲...");
	
	date_save();
	time_save();
	course_definition_save();
	information_save();
	course_record_save();
	
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
		fprintf(ftemp, "%d %d", id_check, temp);
		if(!feof(fdate))
			fprintf(ftemp, "\n");
		if((id_check + 1) == user_id){
			fprintf(ftemp, "%d %d", user_id, day_now);
			fscanf(fdate, "%d %d", &id_check, &temp);
			if(!feof(fdate))
				fprintf(ftemp, "\n");
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

void time_save(){
	FILE *ftime;
	FILE *ftemp;
	ftime = fopen("data/save/time.txt", "r");
	ftemp = fopen("data/save/temp.txt", "w");
	int temp;
	int id_check;
	int extern day_time;
	
	rewind(ftime);
	rewind(ftemp);
	while(!feof(ftime)){
		fscanf(ftime, "%d %d", &id_check, &temp);
		fprintf(ftemp, "%d %d", id_check, temp);
		if(!feof(ftime))
			fprintf(ftemp, "\n");
		if((id_check + 1) == user_id){
			fprintf(ftemp, "%d %d", user_id, day_time);
			fscanf(ftime, "%d %d", &id_check, &temp);
			if(!feof(ftime))
				fprintf(ftemp, "\n");
		}
	}
	fclose(ftemp);
	ftime = fopen("data/save/time.txt", "w");
	ftemp = fopen("data/save/temp.txt", "r");
	rewind(ftime);
	rewind(ftemp);
	while(!feof(ftemp)){
		fscanf(ftemp, "%d %d", &id_check, &temp);
		fprintf(ftime, "%d %d", id_check, temp);
		if(!feof(ftemp))
			fprintf(ftime, "\n");
	}
	
	fclose(ftemp);
	fclose(ftime);
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
		fprintf(ftemp, "%d %d", id_check, temp);
		if(!feof(fcourse_definition))
			fprintf(ftemp, "\n");
		if((id_check + 1) == user_id){
			fprintf(ftemp, "%d %d", user_id, course_definition);
			fscanf(fcourse_definition, "%d %d", &id_check, &temp);
			if(!feof(fcourse_definition))
				fprintf(ftemp, "\n");	
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

void information_save(){
	FILE *finformation;
	FILE *ftemp;
	finformation = fopen("data/save/information.txt", "r");
	ftemp = fopen("data/save/temp.txt", "w");
	float temp[6];
	int id_check;
	
	rewind(finformation);
	rewind(ftemp);
	while(!feof(finformation)){
		fscanf(finformation, "%d %f %f %f %f %f %f", &id_check, &temp[0], &temp[1], &temp[2], &temp[3], &temp[4], &temp[5]);
		fprintf(ftemp, "%d %.2f %.2f %.2f %.2f %.2f %.2f", id_check, temp[0], temp[1], temp[2], temp[3], temp[4], temp[5]);
		if(!feof(finformation))
			fprintf(ftemp, "\n");
		if((id_check + 1) == user_id){
			fprintf(ftemp, "%d %.2f %.2f %.2f %.2f %.2f %.2f", user_id, chinese.now, english.now, math.now, social.now, science.now, favorability.now);
			fscanf(finformation, "%d %f %f %f %f %f %f", &id_check, &temp[0], &temp[1], &temp[2], &temp[3], &temp[4], &temp[5]);
			if(!feof(finformation))
				fprintf(ftemp, "\n");
		}
	}
	fclose(ftemp);
	finformation = fopen("data/save/information.txt", "w");
	ftemp = fopen("data/save/temp.txt", "r");
	rewind(finformation);
	rewind(ftemp);
	while(!feof(ftemp)){
		fscanf(ftemp, "%d %f %f %f %f %f %f", &id_check, &temp[0], &temp[1], &temp[2], &temp[3], &temp[4], &temp[5]);
		fprintf(finformation, "%d %.2f %.2f %.2f %.2f %.2f %.2f", id_check, temp[0], temp[1], temp[2], temp[3], temp[4], temp[5]);
		if(!feof(ftemp))
			fprintf(finformation, "\n");
	}
	
	fclose(ftemp);
	fclose(finformation);
}

void course_record_save(){
	FILE *fcourse_record;
	FILE *ftemp;
	fcourse_record = fopen("data/save/course_record.txt", "r");
	ftemp = fopen("data/save/temp.txt", "w");
	int temp[5];
	int id_check;
	
	rewind(fcourse_record);
	rewind(ftemp);
	while(!feof(fcourse_record)){
		fscanf(fcourse_record, "%d %d %d %d %d %d", &id_check, &temp[0], &temp[1], &temp[2], &temp[3], &temp[4]);
		fprintf(ftemp, "%d %d %d %d %d %d", id_check, temp[0], temp[1], temp[2], temp[3], temp[4]);
		if(!feof(fcourse_record))
			fprintf(ftemp, "\n");
		if((id_check + 1) == user_id){
			fprintf(ftemp, "%d %d %d %d %d %d", user_id, chinese.record, english.record, math.record, social.record, science.record);
			fscanf(fcourse_record, "%d %d %d %d %d %d", &id_check, &temp[0], &temp[1], &temp[2], &temp[3], &temp[4]);
			if(!feof(fcourse_record))
				fprintf(ftemp, "\n");
		}
	}
	fclose(ftemp);
	fcourse_record = fopen("data/save/course_record.txt", "w");
	ftemp = fopen("data/save/temp.txt", "r");
	rewind(fcourse_record);
	rewind(ftemp);
	while(!feof(ftemp)){
		fscanf(ftemp, "%d %d %d %d %d %d", &id_check, &temp[0], &temp[1], &temp[2], &temp[3], &temp[4]);
		fprintf(fcourse_record, "%d %d %d %d %d %d", id_check, temp[0], temp[1], temp[2], temp[3], temp[4]);
		if(!feof(ftemp))
			fprintf(fcourse_record, "\n");
	}
	
	fclose(ftemp);
	fclose(fcourse_record);
}

void event_save(int code, int definition){
	FILE *fevent;
	FILE *ftemp;
	fevent = fopen("data/save/event.txt", "r");
	ftemp = fopen("data/save/temp.txt", "w");
	int temp[4];
	int id_check;
	
	rewind(fevent);
	rewind(ftemp);
	while(!feof(fevent)){
		fscanf(fevent, "%d %d %d %d", &id_check, &temp[0], &temp[1], &temp[2]);
		fprintf(ftemp, "%d %d %d %d", id_check, temp[0], temp[1], temp[2]);
		if(!feof(fevent))
			fprintf(ftemp, "\n");
		if(id_check == user_id && (temp[1]+1) == code){
			fprintf(ftemp, "%d %d %d %d", user_id, protagonist_selection, code, definition);
			fscanf(fevent, "%d %d %d %d", &id_check, &temp[0], &temp[1], &temp[2]);
			if(!feof(fevent))
				fprintf(ftemp, "\n");
		}
	}
	fclose(ftemp);
	fevent = fopen("data/save/event.txt", "w");
	ftemp = fopen("data/save/temp.txt", "r");
	rewind(fevent);
	rewind(ftemp);
	while(!feof(ftemp)){
		fscanf(ftemp, "%d %d %d %d", &id_check, &temp[0], &temp[1], &temp[2]);
		fprintf(fevent, "%d %d %d %d", id_check, temp[0], temp[1], temp[2]);
		if(!feof(ftemp))
			fprintf(fevent, "\n");
	}
	
	fclose(ftemp);
	fclose(fevent);
}

