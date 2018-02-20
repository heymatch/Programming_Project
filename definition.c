#include <stdio.h>
#include <string.h>

int protagonist_hidden();
int date_definition();
int triggered_definition;

int extern day_now;
int extern user_id;
int extern protagonist_selection;
int extern event_code;

int protagonist_hidden(){
	char text[30];
	char text_check[30];
	FILE *ftext_check;
	ftext_check = fopen("data/profile/protagonist_hidden.txt", "r");
	
	fscanf(ftext_check, "%s", text_check);
	puts("Please enter the pass-code:");
	scanf("%s", text);
	
	if(strcmp(text, text_check) == 0){
		protagonist_introduction(5);
		return 5;
	}
	else{
		puts("Wrong.");
		return 0;
	}
}

int date_definition(){
	FILE *fdate_definition;
	fdate_definition = fopen("data/definition/date.txt", "r");
	
	int code_check;
	int protagonist_selection_check;
	int definition;
	
	while(!feof(fdate_definition)){
		fscanf(fdate_definition, "%d %d %d", &protagonist_selection_check, &code_check, &definition);
			if(protagonist_selection_check == protagonist_selection && definition == day_now)
				break;
			if(code_check == 0)
				break;
	}
	event_code = code_check;
	
	if(definition == day_now)
		return 1;
	else
		return 0;
}

int event_definition(){
	FILE *fevent_definition;
	fevent_definition = fopen("data/save/event.txt", "r");
	
	int code_check;
	int protagonist_selection_check;
	int code_definition;
	int definition;
	
	while(!feof(fevent_definition)){
		fscanf(fevent_definition, "%d %d %d %d", &code_check, &protagonist_selection_check, &code_definition, &definition);
			if(code_check == user_id && protagonist_selection_check == protagonist_selection && code_definition == event_code)
				break;
			if(code_check == 0)
				break;
	}
	event_save(event_code, 1);
	
	if(definition == 0)
		return 1;
	else
		return 0;
}

int holiday_definition(int code){
	if(code == 39 || code == 122)
		return 1;
	else
		return 0;
}


