#include <stdio.h>
#include <string.h>
#include <windows.h>

void game_load();
void game_save();

int game_time(int code);
int event_trigger(int date, int time, int place, int phrase, int action, int definition);

void greeting();

void course();
void chat();
void activity();
void information();
void next_day(int code);
void option();

float talent_calculate(int talent, int record);

struct status{
	int talent;
	int record;
	int phrase;
	float add;
	float now;
};

struct status extern chinese;
struct status extern english;
struct status extern math;
struct status extern social;
struct status extern science;
struct status extern favorability;

int const status_max = 100;

int extern first_log_in_definition;
int extern first_sign_in_definition;
int extern day_now;
int extern day_time;
int extern course_definition;
int extern const user_id;
int extern const protagonist_selection;
int extern const textlong;
int extern const namelong;
char extern playername[20];
char extern protagonistname[20];

void game_main(){
	if(first_sign_in_definition == 1){
		protagonist_start(protagonist_selection);
		first_sign_in_definition = 0;
	}
	if(first_log_in_definition == 1){
		game_load();
		greeting();
		first_log_in_definition = 0;
	}
	
	if(game_time(3) == 1){
		;
		main();
	}
	
	pause(2);
	if(event_trigger(1, 0, 0, 0, 0, 1) == 1){
		day_trigger(day_now+1);
		pause(2);
	}
	
	if(game_time(0) == 2 || game_time(0) == 3 || holiday_definition(day_now) == 1){
		day_time = 2;
		game_time(2);
		puts("今天是假日");
		puts("活動(1)"); 
		puts("狀態(2)"); 
		puts("下一天(3)");
		puts("設定(4)");
		
		int selection;
		while(selection != -1){
			scanf("%d", &selection);
			switch(selection){
				case 1:
					activity(2);
					break;
				case 2:
					information();
					break;
				case 3:
					next_day(0);
					break;
				case 4:
					option();
			}
		}
	}
	else{
		day_time = 1;
		game_time(1);
		puts("選課(1)");
		puts("聊天(2)"); 
		puts("活動(3)"); 
		puts("狀態(4)"); 
		puts("下一天(5)");
		puts("設定(6)");
		
		int selection;
		while(selection != -1){
			scanf("%d", &selection);
			switch(selection){
				case 1:
					course();
					break;
				case 2:
					chat();
					break;
				case 3:
					activity(1);
					break;
				case 4:
					information();
					break;
				case 5:
					next_day(1);
					break;
				case 6:
					option();
					break;	
			}
		}
	}
}

int game_time(int code){ //遊戲時間 
	char day[3];
	char daytime[3];
	int date = 1;
	int month = 9;
	int end = 0;
	int n;
	
	for(n = 0; n != day_now; n++){
		date++;
		if(date == 31){
			if(month == 9 || month == 11){
				month++;
				date = 1;
			}
		}
		if(date == 32){
			if(month == 10){
				month++;
				date = 1;
			}
		    if(month == 12){
		    	month = 1;
		    	date = 1;
			}
		}
		if(month == 1 && date == 26){
			end = 1;
		    break;
		}
	}
	
	int code_check;
	FILE *fday;
	FILE *ftime;
	fday = fopen("data/text/day.txt", "r");
	ftime = fopen("data/text/time.txt", "r");
	int i = (day_now % 7) + 1;
	
	rewind(fday);
	while(!feof(fday)){
		fscanf(fday, "%d %s", &code_check, day);
		if(code_check == i){
			break;
		}
	}
	
	rewind(ftime);
	while(!feof(ftime)){
		fscanf(ftime, "%d %s", &code_check, daytime);
		if(code_check == day_time){
			break;
		}
	}
	
	fclose(fday);
	
	if(code == 1)
		printf("今天是%2d月%2d日(%s)\n", month, date, day);
	if(code == 2)
		printf("今天是%2d月%2d日(%s)(%s)\n", month, date, day, daytime);
	if(code == 3)
		return end;
	if(code == 0)
		return i;
}

int event_trigger(int date, int time, int place, int phrase, int action, int triggered){
	if(date == 1 && date_definition() == 1 && triggered == 1 && event_definition() == 1)
		return 1;
	else
		return 0;
	
}

void greeting(){
	char text[textlong];
	
	FILE *fgreeting;
	fgreeting = fopen("data/text/greeting.txt", "r");
	
	int code_check;
	int protagonist_selection_check;
	int code = (rand() % greeting_quantity_load(protagonist_selection)) + 1;
	int definition = 0;
	
	while(!feof(fgreeting)){
		fscanf(fgreeting, "%d %d %s", &protagonist_selection_check, &code_check, text);
		if(code_check == code && protagonist_selection_check == protagonist_selection){
				printf("%s\n", text);
			definition = 1;
		}
		if(definition == 1 && code_check != code)
			break;
		if(code_check == 0 && protagonist_selection_check == 0)
			break;
	}
}

void course(){
	if(course_definition == 0){
		puts("今天已經上過課了！");
		game_main();
		return;
	}
	
	puts("要選擇什麼科目？");
	puts("國文(1)");
	puts("英文(2)");
	puts("數學(3)");
	puts("社會(4)");
	puts("自然(5)");
	puts("返回(-1)");
	
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
		chinese.add = talent_calculate(chinese.talent, chinese.record);
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
		english.add = talent_calculate(english.talent, english.record);
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
		math.add = talent_calculate(math.talent, math.record);
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
		social.add = talent_calculate(social.talent, social.record);
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
		science.add = talent_calculate(science.talent, science.record);
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
	
	course_definition = 0;
	
	game_main();
}

void chat(){
	char text[textlong];
	char name[namelong];
	
	FILE *fchat;
	fchat = fopen("data/text/chat.txt", "r");
	int code_check;
	int protagonist_selection_check;
	int code = (rand() % chat_quantity_load(protagonist_selection)) + 1;
	int definition = 0;
	int i;
	
	while(!feof(fchat)){
		fscanf(fchat, "%d %d %[^ ] %s", &protagonist_selection_check, &code_check, name, text);
		if(code_check == code && protagonist_selection_check == protagonist_selection){
			if(name[0] == '%')
				printf("%s：", playername);
			else if(name[0] == '*')
				;
			else
				printf("%s：", name);
			for(i = 0; text[i] != '\0'; i++){
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
	fclose(fchat);
	game_main();
}

void activity(int code){
	if(code == 1){
		puts("要做什麼？");
		
		puts("返回(-1)");
		int selection;
		while(selection != -1){
			scanf("%d", &selection);
			switch(selection){
				case 1:
					break;
				case 2:
					break;
				case 3:
					break;
				case 4:
					break;
			}
		}
	}
	else if(code == 2 && day_time <= 4){
		puts("要做什麼？(1)");
		puts("要去哪裡？(2)");
		puts("返回(-1)");
		int selection_1;
		int selection_2;
		while(selection_1 != -1){
			scanf("%d", &selection_1);
			switch(selection_1){
				case 1:
					puts("(1)");
					puts("返回(-1)");
					scanf("%d", &selection_2);
					switch(selection_2){
						case 1:
							day_time++;
							break;
					}
					break;
				case 2:
					puts("(1)");
					puts("返回(-1)");
					scanf("%d", &selection_2);
					switch(selection_2){
						case 1:
							day_time++;
							break;
					}
					break;
			}
			break;
		}
	}
	else if(code == 2 && day_time == 5)
		puts("已經太晚了！");
	
	game_main();
}

void next_day(int code){
	if(code == 0)
		;
	else
		puts("再見了~");
	
	day_now++;
	course_definition = 1;
	
	game_main();
}

void information(){
	
	printf("玩家姓名：%s\n", playername);
	printf("主角姓名：%s\n", protagonistname);
	printf("好感度：%.2f/%d\n", favorability.now, status_max);
	printf("國文：%.2f/%d\n", chinese.now, status_max);
	printf("英文：%.2f/%d\n", english.now, status_max);
	printf("數學：%.2f/%d\n", math.now, status_max);
	printf("社會：%.2f/%d\n", social.now, status_max);
	printf("自然：%.2f/%d\n", science.now, status_max);
	
	puts("返回(-1)");
	
	int selection;
	while(selection != -1){
		scanf("%d", &selection);
		switch(selection){
			case -1:
				game_main();
				break;
		}
	}
}

void log_out();

void option(){
	puts("登出(1)");
	puts("版本資訊(2)");
	puts("返回(-1)");
	
	int selection;
	while(selection != -1){
		scanf("%d", &selection);
		switch(selection){
			case 1:
				log_out();
				break;
			case 2:
				version();
				game_main();
				break;
			case -1:
				game_main();
				break;
		}
	}
}

void log_out(){
	puts("已成功登出!");
	
	game_save();
	main();
}

float talent_calculate(int talent, int record){
	int result;
	int fortune = rand() % 2;
	
	result = talent - record;
	
	if(result <= 0 && fortune == 1)
		return (float)1 * 15 / 100;
	else if(result <= 0 && fortune == 0)
		return 0;
	else
		return (float)((rand() % result) + 1) * 15 / 100;
}


