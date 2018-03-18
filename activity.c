#include <stdio.h>

void action_list_1(int code);
void action_list_2(int code);
void place_list(int code);
void action(int selection);
void place(int selection);
void addition_trigger(int code);
void addition_activity(int selection, int code);

int extern event_code;
int extern day_time;
int extern activity_definition;
int extern protagonist_selection;
int extern const textlong;
int extern const namelong;
char extern playername[20];
char extern protagonistname[20];

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

void action_list_1(int code){
	FILE *faction_list;
	FILE *faction_data;
	faction_list = fopen("data/text/action_list_1.txt", "r");
	faction_data = fopen("data/text/action_data.txt", "r");
	int protagonist_selection_check = 0;
	int i = 0;
	int input = 1;
	int data;
	int list[15];
	char text[10];
	
	while(protagonist_selection_check != code){
		fscanf(faction_list, "%d", &protagonist_selection_check);
		i = 0;
		while(input != 0){
			fscanf(faction_list, "%d", &input);
			list[i] = input;
			i++;
		}
	}
	
	i = 0;
	while(list[i] != 0){
		fscanf(faction_data, "%d %s", &data, text);
		if(list[i] == data){
			printf("(%d)%s\n", i+1, text);
			i++;
		}		
	}
	
	fclose(faction_list);
	fclose(faction_data);
}

void action_list_2(int code){
	FILE *faction_list;
	FILE *faction_data;
	faction_list = fopen("data/text/action_list_2.txt", "r");
	faction_data = fopen("data/text/action_data.txt", "r");
	int protagonist_selection_check = 0;
	int i = 0;
	int input = 1;
	int data;
	int list[15];
	char text[10];
	
	while(protagonist_selection_check != code){
		fscanf(faction_list, "%d", &protagonist_selection_check);
		i = 0;
		while(input != 0){
			fscanf(faction_list, "%d", &input);
			list[i] = input;
			i++;
		}
	}
	
	i = 0;
	while(list[i] != 0){
		fscanf(faction_data, "%d %s", &data, text);
		if(list[i] == data){
			printf("(%d)%s\n", i+1, text);
			i++;
		}		
	}
	
	fclose(faction_list);
	fclose(faction_data);
}

void place_list(int code){
	FILE *fplace_list;
	FILE *fplace_data;
	fplace_list = fopen("data/text/place_list.txt", "r");
	fplace_data = fopen("data/text/place_data.txt", "r");
	int protagonist_selection_check = 0;
	int i = 0;
	int input = 1;
	int data;
	int list[15];
	char text[10];
	
	while(protagonist_selection_check != code){
		fscanf(fplace_list, "%d", &protagonist_selection_check);
		i = 0;
		while(input != 0){
			fscanf(fplace_list, "%d", &input);
			list[i] = input;
			i++;
		}
	}
	
	i = 0;
	while(list[i] != 0){
		fscanf(fplace_data, "%d %s", &data, text);
		if(list[i] == data){
			printf("(%d)%s\n", i+1, text);
			i++;
		}		
	}
	
	fclose(fplace_list);
	fclose(fplace_data);
}

void action(int selection){
	char text[textlong];
	char name[namelong];
	
	FILE *faction;
	faction = fopen("data/text/action_normal.txt", "r");
	int code_check;
	int selection_check;
	int protagonist_selection_check;
	int code = (rand() % action_quantity_load(selection)) + 1;
	int definition = 0;
	int i;
	
	while(!feof(faction)){
		fscanf(faction, "%d %d %d %[^ ] %s", &protagonist_selection_check, &selection_check, &code_check, name, text);
		if(code_check == code && protagonist_selection_check == protagonist_selection && selection_check == selection){
			if(name[0] == '%')
				printf("%s¡G", playername);
			else if(name[0] == '*')
				;
			else
				printf("%s¡G", name);
			for(i = 0; text[i] != '\0'; i++){
				if(text[i] == '%')
					printf("%s¡G", playername);
				else if(text[i] == '_')
					printf(" ");
				else
					printf("%c", text[i]);
				text[i] = '\0';
				Sleep(75);
			}
			printf("\n");
			definition = 1;
		}
		if(definition == 1 && code_check != code)
			break;
		if(code_check == 0 && protagonist_selection_check == 0)
			break;
	}
	
	addition_activity(selection, code);
	if(definition == 1){
		day_time++;
		activity_definition = 0;
	}
	
	system("pause");
	fclose(faction);
}

void place(int selection){
	char text[textlong];
	char name[namelong];
	
	FILE *fplace;
	fplace = fopen("data/text/place_normal.txt", "r");
	int code_check;
	int selection_check;
	int protagonist_selection_check;
	int code = (rand() % place_quantity_load(selection)) + 1;
	int definition = 0;
	int i;
	
	while(!feof(fplace)){
		fscanf(fplace, "%d %d %d %[^ ] %s", &protagonist_selection_check, &selection, &code_check, name, text);
		if(code_check == code && protagonist_selection_check == protagonist_selection && selection_check == selection){
			if(name[0] == '%')
				printf("%s¡G", playername);
			else if(name[0] == '*')
				;
			else
				printf("%s¡G", name);
			for(i = 0; text[i] != '\0'; i++){
				if(text[i] == '%')
					printf("%s¡G", playername);
				else if(text[i] == '_')
					printf(" ");
				else
					printf("%c", text[i]);
				text[i] = '\0';
				Sleep(75);
			}
			printf("\n");
			definition = 1;
		}
		if(definition == 1 && code_check != code)
			break;
		if(code_check == 0 && protagonist_selection_check == 0)
			break;
	}
	
	addition_activity(selection, code);
	if(code != 1 && definition == 1)
		day_time++;
	
	system("pause");
	fclose(fplace);
}

void addition_trigger(int code){
	FILE *faddition;
	faddition = fopen("data/definition/addition_trigger.txt", "r");
	
	int code_check;
	int protagonist_selection_check;
	int definition[6];
	
	while(!feof(faddition)){
		fscanf(faddition, "%d %d %d %d %d %d %d %d", &protagonist_selection_check, &code_check, &definition[0], &definition[1], &definition[2], &definition[3], &definition[4], &definition[5]);
			if(protagonist_selection_check == protagonist_selection && code_check == event_code)
				break;
			if(code_check == 0)
				break;
	}
	
	chinese.now += definition[0];
	english.now += definition[1];
	math.now += definition[2];
	social.now += definition[3];
	science.now += definition[4];
	favorability.now += definition[5];
}

void addition_activity(int selection, int code){
	FILE *faddition;
	faddition = fopen("data/definition/addition_activity.txt", "r");
	
	int code_check;
	int selection_check;
	int protagonist_selection_check;
	int definition[6];
	
	while(!feof(faddition)){
		fscanf(faddition, "%d %d %d %d %d %d %d %d %d", &protagonist_selection_check, &selection_check, &code_check, &definition[0], &definition[1], &definition[2], &definition[3], &definition[4], &definition[5]);
			if(protagonist_selection_check == protagonist_selection && code_check == code && selection_check == selection)
				break;
			if(code_check == 0)
				break;
	}
	
	chinese.now += definition[0];
	english.now += definition[1];
	math.now += definition[2];
	social.now += definition[3];
	science.now += definition[4];
	favorability.now += definition[5];
}
