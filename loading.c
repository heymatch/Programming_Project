#include <stdio.h>

void playername_load();
void date_load();
void time_load();
void courase_definition_load();
void activity_definition_load();
void information_load();
void protagonist_selection_load();
void player_birthday_load();
void course_record_load();

void place_list_load(int code);
void action_list_load(int code);

void talent_load(int code);
void protagonist_name_load(int code);

int chat_quantity_load(int code);
int greeting_quantity_load(int code);
int action_quantity_load_1(int code);
int action_quantity_load_2(int code);

struct status{
	int talent;
	int record;
	int phase;
	float add;
	float now;
};

struct status chinese;
struct status english;
struct status math;
struct status social;
struct status science;
struct status favorability;

char playername[20];
char protagonistname[20];
int day_now;
int day_time;
int player_birthday = -1;
int course_definition;
int activity_definition;
int protagonist_selection;

int extern user_id;

void game_load(){
	pause(2);
	puts("���J�C����...");
	
	playername_load();
	date_load();
	time_load();
	courase_definition_load();
	activity_definition_load();
	information_load();
	protagonist_selection_load();
	course_record_load();
	player_birthday_load();
	
	talent_load(protagonist_selection);
	protagonist_name_load(protagonist_selection);
	
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

void time_load(){
	int id_check;
	FILE *ftime;
	ftime = fopen("data/save/time.txt", "r");
	
	rewind(ftime);
	while(!feof(ftime)){
		fscanf(ftime, "%d %d", &id_check, &day_time);
		if(id_check == user_id){
			break;
		}
	}
	
	fclose(ftime);
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

void activity_definition_load(){
	int id_check;
	FILE *factivity_definition;
	factivity_definition = fopen("data/save/activity_definition.txt", "r");
	
	rewind(factivity_definition);
	while(!feof(factivity_definition)){
		fscanf(factivity_definition, "%d %d", &id_check, &activity_definition);
		if(id_check == user_id){
			break;
		}
	}
	
	fclose(factivity_definition);
}

void information_load(){
	int id_check;
	FILE *finformation;
	finformation = fopen("data/save/information.txt", "r");
	
	rewind(finformation);
	while(!feof(finformation)){
		fscanf(finformation, "%d %f %f %f %f %f %f", &id_check, &chinese.now, &english.now, &math.now, &social.now, &science.now, &favorability.now);
		if(id_check == user_id){
			break;
		}
	}
	
	fclose(finformation);
}

void course_record_load(){
	int id_check;
	FILE *fcourse_record;
	fcourse_record = fopen("data/save/course_record.txt", "r");
	
	rewind(fcourse_record);
	while(!feof(fcourse_record)){
		fscanf(fcourse_record, "%d %d %d %d %d %d", &id_check, &chinese.record, &english.record, &math.record, &social.record, &science.record);
		if(id_check == user_id){
			break;
		}
	}
	
	fclose(fcourse_record);
}

void protagonist_selection_load(){
	int id_check;
	FILE *fprotagonist_selection;
	fprotagonist_selection = fopen("data/save/protagonist_selection.txt", "r");
	
	rewind(fprotagonist_selection);
	while(!feof(fprotagonist_selection)){
		fscanf(fprotagonist_selection, "%d %d", &id_check, &protagonist_selection);
		if(id_check == user_id){
			break;
		}
	}
	
	fclose(fprotagonist_selection);
}

void player_birthday_load(){
	int id_check;
	int month, day;
	FILE *fplayer_birthday;
	fplayer_birthday = fopen("data/profile/player_birthday.txt", "r");
	
	rewind(fplayer_birthday);
	while(!feof(fplayer_birthday)){
		fscanf(fplayer_birthday, "%d %d %d", &id_check, &month, &day);
		if(id_check == user_id){
			break;
		}
	}
	
	int i = 9, j = 1, n = 0;
		while(player_birthday != n){
		if(i == month && j == day){
			player_birthday = n;
			break;
		}
		if(i == 9 && j == 31){
			i++;
			j = 1;
		}
		else if(i == 11 && j == 31){
			i++;
			j = 1;
		}
		else if(j == 32){
			i++;
			j = 1;
		}
		if(i == 13)
			i = 1;
		j++;
		n++;
	}
	
	fclose(fplayer_birthday);
}

void talent_load(int code){
	int code_check;
	FILE *ftalent;
	ftalent = fopen("data/profile/talent.txt", "r");
	
	rewind(ftalent);
	while(!feof(ftalent)){
		fscanf(ftalent, "%d %d %d %d %d %d", &code_check, &chinese.talent, &english.talent, &math.talent, &social.talent, &science.talent);
		if(code_check == code){
			break;
		}
	}
	
	fclose(ftalent);
}

void protagonist_name_load(int code){
	int code_check;
	FILE *fprotagonist_name;
	fprotagonist_name = fopen("data/profile/protagonist_name.txt", "r");
	
	rewind(fprotagonist_name);
	while(!feof(fprotagonist_name)){
		fscanf(fprotagonist_name, "%d %s", &code_check, protagonistname);
		if(code_check == code){
			break;
		}
	}
	
	fclose(fprotagonist_name);
}

int chat_quantity_load(int code){
	int code_check;
	FILE *fchat_quantity;
	fchat_quantity = fopen("data/text/chat_quantity.txt", "r");
	int quantity;
	
	rewind(fchat_quantity);
	while(!feof(fchat_quantity)){
		fscanf(fchat_quantity, "%d %d", &code_check, &quantity);
		if(code_check == code){
			break;
		}
	}
	
	fclose(fchat_quantity);
	
	if(quantity == 0)
		return 1;
	else
		return quantity;
}

int greeting_quantity_load(int code){
	int code_check;
	FILE *fgreeting_quantity;
	fgreeting_quantity = fopen("data/text/greeting_quantity.txt", "r");
	int quantity;
	
	rewind(fgreeting_quantity);
	while(!feof(fgreeting_quantity)){
		fscanf(fgreeting_quantity, "%d %d", &code_check, &quantity);
		if(code_check == code){
			break;
		}
	}
	
	fclose(fgreeting_quantity);
	
	if(quantity == 0)
		return 1;
	else
		return quantity;
}

int action_quantity_load_1(int code){
	int code_check;
	int action_check;
	FILE *faction_quantity;
	faction_quantity = fopen("data/text/action_quantity_1.txt", "r");
	int quantity;
	
	rewind(faction_quantity);
	while(!feof(faction_quantity)){
		fscanf(faction_quantity, "%d %d %d", &code_check, &action_check, &quantity);
		if(code_check == protagonist_selection && action_check == code){
			break;
		}
		if(code_check == 0)
			break;
	}
	
	fclose(faction_quantity);
	
	if(quantity == 0)
		return 1;
	else
		return quantity;
}

int action_quantity_load_2(int code){
	int code_check;
	int action_check;
	FILE *faction_quantity;
	faction_quantity = fopen("data/text/action_quantity_2.txt", "r");
	int quantity;
	
	rewind(faction_quantity);
	while(!feof(faction_quantity)){
		fscanf(faction_quantity, "%d %d %d", &code_check, &action_check, &quantity);
		if(code_check == protagonist_selection && action_check == code){
			break;
		}
		if(code_check == 0)
			break;
	}
	
	fclose(faction_quantity);
	
	if(quantity == 0)
		return 1;
	else
		return quantity;
}

int place_quantity_load(int code){
	int code_check;
	int place_check;
	FILE *fplace_quantity;
	fplace_quantity = fopen("data/text/place_quantity.txt", "r");
	int quantity;
	
	rewind(fplace_quantity);
	while(!feof(fplace_quantity)){
		fscanf(fplace_quantity, "%d %d %d", &code_check, &place_check, &quantity);
		if(code_check == protagonist_selection && place_check == code){
			break;
		}
		if(code_check == 0)
			break;
	}
	
	fclose(fplace_quantity);
	
	if(quantity == 0)
		return 1;
	else
		return quantity;
}
