#include <stdio.h>
#include <string.h>

int event_trigger(int date, int time, int place, int phase, int action, int definition);
int protagonist_hidden();
int date_definition();
int time_definition();
int place_definition();
int action_definition();
int phase_definition();
int event_definition();
int ending_definition();

int holiday_definition();
int birthday_definition();

void day_skip();

int extern day_now;
int extern day_time;
int extern user_id;
int extern protagonist_selection;
int extern activity_selection;
int extern event_code;

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

int event_trigger(int date, int time, int place, int phase, int action, int triggered){
	int a, b, c, d, e, f;
	for(a = 0; a <= 1; a++)
	for(b = 0; b <= 1; b++)
	for(c = 0; c <= 1; c++)
	for(d = 0; d <= 1; d++)
	for(e = 0; e <= 1; e++)
	for(f = 0; f <= 1; f++)
		if(date == a && date_definition() == a && time == b && time_definition() == b && place == c && place_definition() == c && phase == d && phase_definition() == d && action == e && action_definition() == e && triggered == f && event_definition() == f)
			return 1;
	return 0;
}

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

int time_definition(){
	FILE *ftime_definition;
	ftime_definition = fopen("data/definition/time.txt", "r");
	
	int code_check;
	int protagonist_selection_check;
	int definition;
	
	while(!feof(ftime_definition)){
		fscanf(ftime_definition, "%d %d %d", &protagonist_selection_check, &code_check, &definition);
			if(protagonist_selection_check == protagonist_selection && definition == day_time)
				break;
			if(code_check == 0)
				break;
	}
	event_code = code_check;
	
	if(definition == day_time)
		return 1;
	else
		return 0;
}

int place_definition(){
	FILE *fplace_definition;
	fplace_definition = fopen("data/definition/place.txt", "r");
	
	int code_check;
	int protagonist_selection_check;
	int definition;
	
	while(!feof(fplace_definition)){
		fscanf(fplace_definition, "%d %d %d", &protagonist_selection_check, &code_check, &definition);
			if(protagonist_selection_check == protagonist_selection && definition == activity_selection)
				break;
			if(code_check == 0)
				break;
	}
	event_code = code_check;
	
	if(definition == activity_selection)
		return 1;
	else
		return 0;
}

int action_definition(){
	FILE *faction_definition;
	faction_definition = fopen("data/definition/date.txt", "r");
	
	int code_check;
	int protagonist_selection_check;
	int definition;
	
	while(!feof(faction_definition)){
		fscanf(faction_definition, "%d %d %d", &protagonist_selection_check, &code_check, &definition);
			if(protagonist_selection_check == protagonist_selection && definition == activity_selection)
				break;
			if(code_check == 0)
				break;
	}
	event_code = code_check;
	
	if(definition == activity_selection)
		return 1;
	else
		return 0;
}

int phase_definition(){
	FILE *fphase_definition;
	fphase_definition = fopen("data/definition/phase.txt", "r");
	
	int code_check;
	int protagonist_selection_check;
	int definition[6];
	
	while(!feof(fphase_definition)){
		fscanf(fphase_definition, "%d %d %d %d %d %d %d %d", &protagonist_selection_check, &code_check, &definition[0], &definition[1], &definition[2], &definition[3], &definition[4], &definition[5]);
			if(protagonist_selection_check == protagonist_selection && chinese.phase >= definition[0] && math.phase >= definition[1] && english.phase >= definition[2], social.phase >= definition[3], science.phase >= definition[4], favorability.phase >= definition[5])
				break;
			if(code_check == 0)
				break;
	}
	event_code = code_check;
	
	if(chinese.phase >= definition[0] && math.phase >= definition[1] && english.phase >= definition[2], social.phase >= definition[3], science.phase >= definition[4], favorability.phase >= definition[5])
		return 1;
	else
		return 0;
}

int ending_definition(){
	FILE *fending_definition;
	fending_definition = fopen("data/definition/ending.txt", "r");
	
	int protagonist_selection_check;
	int definition[6];
	
	while(!feof(fending_definition)){
		fscanf(fending_definition, "%d %d %d %d %d %d %d", &protagonist_selection_check, &definition[0], &definition[1], &definition[2], &definition[3], &definition[4], &definition[5]);
			if(protagonist_selection_check == protagonist_selection && chinese.phase >= definition[0] && math.phase >= definition[1] && english.phase >= definition[2], social.phase >= definition[3], science.phase >= definition[4], favorability.phase >= definition[5]);
				break;
	}
	
	if(chinese.phase >= definition[0] && math.phase >= definition[1] && english.phase >= definition[2], social.phase >= definition[3], science.phase >= definition[4], favorability.phase >= definition[5])
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

int daytime_definition(int code){
	if(code == 29)
		return 1;
	else
		return 0;
}

int holiday_definition(int code){
	if(code == 39 || code == 122 || code == 38 || code == 33)
		return 1;
	else
		return 0;
}

void day_skip(){
	FILE *fday_skip;
	fday_skip = fopen("data/definition/day_skip.txt", "r");
	
	int code_check;
	int protagonist_selection_check;
	int definition;
	
	while(!feof(fday_skip)){
		fscanf(fday_skip, "%d %d %d", &protagonist_selection_check, &code_check, &definition);
			if(protagonist_selection_check == protagonist_selection && code_check == event_code && definition == 1)
				break;
			if(code_check == 0)
				break;
	}
	
	if(code_check == event_code && definition == 1)
		day_now++;
	else
		return;
}
