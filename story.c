#include <stdio.h>
#include <string.h>
#include <windows.h>

void protagonist_introduction(int code);
void protagonist_name(int code);
void protagonist_start(int code);
void protagonist_event(int code);
void day_trigger(int code);
void time_trigger(int code);
void action_trigger(int code);
void place_trigger(int code);

void birthday_trigger();

int protagonist_hidden();

int const textlong = 80;
int const namelong = 20;

int event_code;

int extern protagonist_selection;
int extern day_time;
int extern activity_definition;

char extern playername[20];

void protagonist_introduction(int code){
	FILE *fprotagonist_introduction;
	fprotagonist_introduction = fopen("data/profile/protagonist_introduction.txt", "r");
	int code_check;
	char text[textlong];
	int definition = 0;
	
	rewind(fprotagonist_introduction);
	while(!feof(fprotagonist_introduction)){
		fscanf(fprotagonist_introduction, "%d %s", &code_check, text);
		if(code_check == code){
			printf("%s\n", text);
			definition = 1;
		}
		if(definition == 1 && code_check != code)
			break;
	}
	
	fclose(fprotagonist_introduction);
}

void protagonist_name(int code){
	FILE *fprotagonist_name;
	fprotagonist_name = fopen("data/profile/protagonist_name.txt", "r");
	int code_check;
	char text[namelong];
	
	rewind(fprotagonist_name);
	while(!feof(fprotagonist_name)){
		fscanf(fprotagonist_name, "%d %s", &code_check, text);
		if(code_check == code){
			printf("%s", text);
			break;
		}
	}
	
	fclose(fprotagonist_name);
}

void protagonist_start(int code){
	char text[textlong];
	char name[namelong];
	
	FILE *fprotagonist_start;
	fprotagonist_start = fopen("data/text/start.txt", "r");
	int code_check;
	int definition = 0;
	int i;
	
	rewind(fprotagonist_start);
	while(!feof(fprotagonist_start)){
		fscanf(fprotagonist_start, "%d %[^ ] %s", &code_check, name, text);
		if(code_check == code){
			if(name[0] == '%')
				printf("%s", playername);
			else if(name[0] == '*')
				;
			else if(name[0] == '/')
				;	
			else
				printf("%s", name);
			for(i = 0; text[i] != '\0'; i++){
				if(text[i] == '%')
					printf("%s¡G", playername);
				else if(text[i] == '/')
					Sleep(75);
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
	}
	system("pause");
	fclose(fprotagonist_start);
}

void day_trigger(int code){
	char text[textlong];
	char name[namelong];
	
	FILE *fday_trigger;
	fday_trigger = fopen("data/text/day_trigger.txt", "r");
	int code_check;
	int protagonist_selection_check;
	int definition = 0;
	int i;
	
	while(!feof(fday_trigger)){
		fscanf(fday_trigger, "%d %d %[^ ] %s", &protagonist_selection_check, &code_check, name, text);
		if(code_check == code && protagonist_selection_check == protagonist_selection){
			if(name[0] == '%')
				printf("%s¡G", playername);
			else if(name[0] == '*')
				;
			else if(name[0] == '/')
				;
			else
				printf("%s¡G", name);
			for(i = 0; text[i] != '\0'; i++){
				if(text[i] == '%')
					printf("%s¡G", playername);
				else if(text[i] == '/')
					Sleep(75);
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
	system("pause");
	fclose(fday_trigger);
}

void time_trigger(int code){
	char text[textlong];
	char name[namelong];
	
	FILE *ftime_trigger;
	ftime_trigger = fopen("data/text/time_trigger.txt", "r");
	int code_check;
	int protagonist_selection_check;
	int definition = 0;
	int i;
	
	while(!feof(ftime_trigger)){
		fscanf(ftime_trigger, "%d %d %[^ ] %s", &protagonist_selection_check, &code_check, name, text);
		if(code_check == code && protagonist_selection_check == protagonist_selection){
			if(name[0] == '%')
				printf("%s¡G", playername);
			else if(name[0] == '*')
				;
			else if(name[0] == '/')
				;
			else
				printf("%s¡G", name);
			for(i = 0; text[i] != '\0'; i++){
				if(text[i] == '%')
					printf("%s¡G", playername);
				else if(text[i] == '/')
					Sleep(75);
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
	system("pause");
	fclose(ftime_trigger);
}

void action_trigger(int code){
	char text[textlong];
	char name[namelong];
	
	FILE *faction_trigger;
	faction_trigger = fopen("data/text/action_trigger.txt", "r");
	int code_check;
	int protagonist_selection_check;
	int definition = 0;
	int i;
	
	while(!feof(faction_trigger)){
		fscanf(faction_trigger, "%d %d %[^ ] %s", &protagonist_selection_check, &code_check, name, text);
		if(code_check == code && protagonist_selection_check == protagonist_selection){
			if(name[0] == '%')
				printf("%s¡G", playername);
			else if(name[0] == '*')
				;
			else if(name[0] == '/')
				;
			else
				printf("%s¡G", name);
			for(i = 0; text[i] != '\0'; i++){
				if(text[i] == '%')
					printf("%s¡G", playername);
				else if(text[i] == '/')
					Sleep(75);
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
	
	day_time++;
	activity_definition = 0;
	
	system("pause");
	fclose(faction_trigger);
}

void place_trigger(int code){
	char text[textlong];
	char name[namelong];
	
	FILE *fplace_trigger;
	fplace_trigger = fopen("data/text/place_trigger.txt", "r");
	int code_check;
	int protagonist_selection_check;
	int definition = 0;
	int i;
	
	while(!feof(fplace_trigger)){
		fscanf(fplace_trigger, "%d %d %[^ ] %s", &protagonist_selection_check, &code_check, name, text);
		if(code_check == code && protagonist_selection_check == protagonist_selection){
			if(name[0] == '%')
				printf("%s¡G", playername);
			else if(name[0] == '*')
				;
			else if(name[0] == '/')
				;
			else
				printf("%s¡G", name);
			for(i = 0; text[i] != '\0'; i++){
				if(text[i] == '%')
					printf("%s¡G", playername);
				else if(text[i] == '/')
					Sleep(75);
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
	
	day_time++;
	
	system("pause");
	fclose(fplace_trigger);
}

void birthday_trigger(){
	char text[textlong];
	char name[namelong];
	
	FILE *fbirthday_trigger;
	fbirthday_trigger = fopen("data/text/birthday_trigger.txt", "r");
	int code_check;
	int protagonist_selection_check;
	int definition = 0;
	int i;
	
	while(!feof(fbirthday_trigger)){
		fscanf(fbirthday_trigger, "%d %d %[^ ] %s", &protagonist_selection_check, name, text);
		if(protagonist_selection_check == protagonist_selection){
			if(name[0] == '%')
				printf("%s¡G", playername);
			else if(name[0] == '*')
				;
			else if(name[0] == '/')
				;
			else
				printf("%s¡G", name);
			for(i = 0; text[i] != '\0'; i++){
				if(text[i] == '%')
					printf("%s¡G", playername);
				else if(text[i] == '/')
					Sleep(75);
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
		if(definition == 1)
			break;
		if(code_check == 0 && protagonist_selection_check == 0)
			break;
	}
	system("pause");
	fclose(fbirthday_trigger);
}
