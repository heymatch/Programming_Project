#include <stdio.h>
#include <string.h>

int event_trigger(int date, int time, int place, int phase, int action, int definition);
int protagonist_hidden();
int date_definition(int verify);
int time_definition(int verify);
int place_definition(int verify);
int action_definition(int verify);
int phase_definition(int verify);
int event_definition(int verify);
int ending_definition();
int event_code_definition(int verify);

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

struct status extern chinese;
struct status extern english;
struct status extern math;
struct status extern social;
struct status extern science;
struct status extern favorability;

int event_trigger(int date, int time, int place, int phase, int action, int triggered){
	int a, b, c, d, e;
	for(a = 0; a <= 1; a++)
	for(b = 0; b <= 1; b++)
	for(c = 0; c <= 1; c++)
	for(d = 0; d <= 1; d++)
	for(e = 0; e <= 1; e++)
		if(date == a && date_definition(date) == a && time == b && time_definition(time) == b && place == c && place_definition(place) == c && action == d && action_definition(action) == d && phase == e && phase_definition(phase) == e)
			if(event_code_definition(event_code) == (date+time+place+phase+action)){
				if(triggered == 1 && event_definition(triggered) == 1){
					return 1;
				}
			}
	event_code = -1;		
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
	
	fclose(ftext_check);
	
	if(strcmp(text, text_check) == 0){
		protagonist_introduction(5);
		return 5;
	}
	else{
		puts("Wrong.");
		return 0;
	}
}

int date_definition(int verify){
	FILE *fdate_definition;
	fdate_definition = fopen("data/definition/date.txt", "r");
	
	int code_check;
	int protagonist_selection_check;
	int definition;
	
	while(!feof(fdate_definition)){
		fscanf(fdate_definition, "%d %d %d", &protagonist_selection_check, &code_check, &definition);
			if(protagonist_selection_check == protagonist_selection && definition == day_now && event_check(code_check) == 1)
				break;
			if(code_check == 0)
				break;
	}
	fclose(fdate_definition);
	
	if(definition == day_now && verify == 1){
		if(event_code == -1){
			event_code = code_check;
			return 1;
		}
		else if(event_code == code_check)
			return 1;
		else
			return 0;
	}
	else
		return 0;
}

int time_definition(int verify){
	FILE *ftime_definition;
	ftime_definition = fopen("data/definition/time.txt", "r");
	
	int code_check;
	int protagonist_selection_check;
	int definition;
	
	while(!feof(ftime_definition)){
		fscanf(ftime_definition, "%d %d %d", &protagonist_selection_check, &code_check, &definition);
			if(protagonist_selection_check == protagonist_selection && definition == day_time && event_check(code_check) == 1)
				break;
			if(code_check == 0)
				break;
	}
	
	fclose(ftime_definition);
	
	if(definition == day_time && verify == 1){
		if(event_code == -1){
			event_code = code_check;
			return 1;
		}
		else if(event_code == code_check)
			return 1;
		else
			return 0;
	}
	else
		return 0;
}

int place_definition(int verify){
	FILE *fplace_definition;
	fplace_definition = fopen("data/definition/place.txt", "r");
	
	int code_check;
	int protagonist_selection_check;
	int definition;
	
	while(!feof(fplace_definition)){
		fscanf(fplace_definition, "%d %d %d", &protagonist_selection_check, &code_check, &definition);
			if(protagonist_selection_check == protagonist_selection && definition == activity_selection && event_check(code_check) == 1)
				break;
			if(code_check == 0)
				break;
	}
	
	fclose(fplace_definition);
	
	if(definition == activity_selection && verify == 1){
		if(event_code == -1){
			event_code = code_check;
			return 1;
		}
		else if(event_code == code_check)
			return 1;
		else
			return 0;
	}
	else
		return 0;
}

int action_definition(int verify){
	FILE *faction_definition;
	faction_definition = fopen("data/definition/action.txt", "r");
	
	int code_check;
	int protagonist_selection_check;
	int definition;
	
	while(!feof(faction_definition)){
		fscanf(faction_definition, "%d %d %d", &protagonist_selection_check, &code_check, &definition);
			if(protagonist_selection_check == protagonist_selection && definition == activity_selection && event_check(code_check) == 1)
				break;
			if(code_check == 0)
				break;
	}
	
	fclose(faction_definition);
	
	if(definition == activity_selection && verify == 1){
		if(event_code == -1){
			event_code = code_check;
			return 1;
		}
		else if(event_code == code_check)
			return 1;
		else
			return 0;
	}
	else
		return 0;
}

int phase_definition(int verify){
	FILE *fphase_definition;
	fphase_definition = fopen("data/definition/phase.txt", "r");
	
	int code_check;
	int protagonist_selection_check;
	int definition[6];
	
	while(!feof(fphase_definition)){
		fscanf(fphase_definition, "%d %d %d %d %d %d %d %d", &protagonist_selection_check, &code_check, &definition[0], &definition[1], &definition[2], &definition[3], &definition[4], &definition[5]);
			if(protagonist_selection_check == protagonist_selection && chinese.phase >= definition[0] && english.phase >= definition[1] && math.phase >= definition[2] && social.phase >= definition[3] && science.phase >= definition[4] && favorability.phase >= definition[5] && event_check(code_check) == 1)
				break;
			if(code_check == 0)
				break;
	}
	
	fclose(fphase_definition);
	
	if(chinese.phase >= definition[0] && english.phase >= definition[1] && math.phase >= definition[2] && social.phase >= definition[3] && science.phase >= definition[4] && favorability.phase >= definition[5] && verify == 1){
		if(event_code == -1){
			event_code = code_check;
			return 1;
		}
		else if(event_code == code_check)
			return 1;
		else
			return 0;
	}
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
		if(protagonist_selection_check == protagonist_selection)
			break;
	}
	fclose(fending_definition);
	
	if(chinese.phase >= definition[0] && english.phase >= definition[1] && math.phase >= definition[2] && social.phase >= definition[3] && science.phase >= definition[4] && favorability.phase >= definition[5])
		return 1;
	else
		return 0;
}

int event_definition(int verify){
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
	
	fclose(fevent_definition);
	
	if(definition == 0 && verify == 1){
		event_save(event_code, 1);
		return 1;
	}
	else
		return 0;
}

int event_check(int verify){
	FILE *fevent_definition;
	fevent_definition = fopen("data/save/event.txt", "r");
	
	int code_check;
	int protagonist_selection_check;
	int code_definition;
	int definition;
	
	while(!feof(fevent_definition)){
		fscanf(fevent_definition, "%d %d %d %d", &code_check, &protagonist_selection_check, &code_definition, &definition);
			if(code_check == user_id && protagonist_selection_check == protagonist_selection && code_definition == verify)
				break;
			if(code_check == 0)
				break;
	}
	
	fclose(fevent_definition);
	
	if(definition == 0){
		return 1;
	}
	else
		return 0;
}

int event_code_definition(int verify){
	FILE *fdate_definition;
	fdate_definition = fopen("data/definition/date.txt", "r");
	FILE *ftime_definition;
	ftime_definition = fopen("data/definition/time.txt", "r");
	FILE *fplace_definition;
	fplace_definition = fopen("data/definition/place.txt", "r");
	FILE *faction_definition;
	faction_definition = fopen("data/definition/action.txt", "r");
	FILE *fphase_definition;
	fphase_definition = fopen("data/definition/phase.txt", "r");
	
	int code_check;
	int protagonist_selection_check;
	int definition[6];
	int valid = 0;
	
	while(!feof(fdate_definition)){
		fscanf(fdate_definition, "%d %d %d", &protagonist_selection_check, &code_check, &definition[0]);
			if(protagonist_selection_check == protagonist_selection && code_check == event_code){
				valid++;
				break;
			}
			if(code_check == 0)
				break;
	}
	while(!feof(ftime_definition)){
		fscanf(ftime_definition, "%d %d %d", &protagonist_selection_check, &code_check, &definition[0]);
			if(protagonist_selection_check == protagonist_selection && code_check == event_code){
				valid++;
				break;
			}
			if(code_check == 0)
				break;
	}
	while(!feof(fplace_definition)){
		fscanf(fplace_definition, "%d %d %d", &protagonist_selection_check, &code_check, &definition[0]);
			if(protagonist_selection_check == protagonist_selection && code_check == event_code){
				valid++;
				break;
			}
			if(code_check == 0)
				break;
	}
	while(!feof(faction_definition)){
		fscanf(faction_definition, "%d %d %d", &protagonist_selection_check, &code_check, &definition[0]);
			if(protagonist_selection_check == protagonist_selection && code_check == event_code){
				valid++;
				break;
			}
			if(code_check == 0)
				break;
	}
	while(!feof(fphase_definition)){
		fscanf(fphase_definition, "%d %d %d %d %d %d %d %d", &protagonist_selection_check, &code_check, &definition[0], &definition[1], &definition[2], &definition[3], &definition[4], &definition[5]);
			if(protagonist_selection_check == protagonist_selection && code_check == event_code){
				valid++;
				break;
			}
			if(code_check == 0)
				break;
	}
	
	fclose(fdate_definition);
	fclose(ftime_definition);
	fclose(fplace_definition);
	fclose(faction_definition);
	fclose(fphase_definition);
	
	return valid;
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
	
	fclose(fday_skip);
	
	if(code_check == event_code && definition == 1)
		day_now++;
	else
		return;
}
