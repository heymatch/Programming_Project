#include <stdio.h>

void action_list_1(int code);
void action_list_2(int code);
void place_list(int code);
void action(int selection);
void place(int selection);
void addition_trigger(int code);
void addition_activity(int selection, int code);
void extra_lesson();

int extern event_code;
int extern day_time;
int extern activity_definition;
int extern protagonist_selection;
int extern const textlong;
int extern const namelong;
int extern const status_max;
char extern playername[20];
char extern protagonistname[20];

struct status{
	int talent;
	int record;
	int phase;
	float add;
	float now;
};

struct status extern chinese;
struct status extern english;
struct status extern math;
struct status extern social;
struct status extern science;
struct status extern favorability;

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
				printf("%s：", playername);
			else if(name[0] == '*')
				;
			else
				printf("%s：", name);
			for(i = 0; text[i] != '\0'; i++){
				if(text[i] == '%')
					printf("%s：", playername);
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
				printf("%s：", playername);
			else if(name[0] == '*')
				;
			else
				printf("%s：", name);
			for(i = 0; text[i] != '\0'; i++){
				if(text[i] == '%')
					printf("%s：", playername);
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
	if(selection == 1 && code == 1){
		extra_lesson();
		day_time++;
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

void extra_lesson(){
	puts("在圖書館加課！");
	puts("要選擇什麼科目？");
	puts("國文(1)");
	puts("英文(2)");
	puts("數學(3)");
	puts("社會(4)");
	puts("自然(5)");
	
	int course_selection = 0;
	int selection;
	while(selection != -1){
		scanf("%d", &selection);
		switch(selection){
			case 1:
				course_selection = 1;
				break;
			case 2:
				course_selection = 2;
				break;
			case 3:
				course_selection = 3;
				break;
			case 4:
				course_selection = 4;
				break;
			case 5:
				course_selection = 5;
				break;
			case -1:
				game_main();
				break;
		}
		break;
	}
	
	if(course_selection == 1){
		chinese.add = calculate(chinese.talent, chinese.record);
		chinese.now += chinese.add;
		chinese.record++;
		english.record = 0;
		math.record = 0;
		social.record = 0;
		science.record = 0;
		if(chinese.now > status_max){
			chinese.add = status_max - chinese.now;
			chinese.now = status_max;
		}
		printf("經過一番努力，增加了%.2f!\n", chinese.add);
		if(chinese.add == 0 && chinese.now != status_max){
			puts("大腦無法運作了，想休息>A<");
		}
	}
	else if(course_selection == 2){
		english.add = calculate(english.talent, english.record);
		english.now += english.add;
		chinese.record = 0;
		english.record++;
		math.record = 0;
		social.record = 0;
		science.record = 0;
		if(english.now > status_max){
			english.add = status_max - english.now;
			english.now = status_max;
		}
		printf("經過一番努力，增加了%.2f!\n", english.add);
		if(english.add == 0 && english.now != status_max){
			puts("大腦無法運作了，想休息>A<");
		}
	}
	else if(course_selection == 3){
		math.add = calculate(math.talent, math.record);
		math.now += math.add;
		chinese.record = 0;
		english.record = 0;
		math.record++;
		social.record = 0;
		science.record = 0;
		if(math.now > status_max){
			math.add = status_max - math.now;
			math.now = status_max;
		}
		printf("經過一番努力，增加了%.2f!\n", math.add);
		if(math.add == 0 && math.now != status_max){
			puts("大腦無法運作了，想休息>A<");
		}
	}
	else if(course_selection == 4){
		social.add = calculate(social.talent, social.record);
		social.now += social.add;
		chinese.record = 0;
		english.record = 0;
		math.record = 0;
		social.record++;
		science.record = 0;
		if(social.now > status_max){
			social.add = status_max - social.now;
			social.now = status_max;
		}
		printf("經過一番努力，增加了%.2f!\n", social.add);
		if(social.add == 0 && social.now != status_max){
			puts("大腦無法運作了，想休息>A<");
		}
	}
	else if(course_selection == 5){
		science.add = calculate(science.talent, science.record);
		science.now += science.add;
		chinese.record = 0;
		english.record = 0;
		math.record = 0;
		social.record = 0;
		science.record++;
		if(science.now > status_max){
			science.add = status_max - science.now;
			science.now = status_max;
		}
		printf("經過一番努力，增加了%.2f!\n", science.add);
		if(science.add == 0 && science.now != status_max){
			puts("大腦無法運作了，想休息>A<");
		}
	}
	
}
