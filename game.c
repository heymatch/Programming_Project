#include <stdio.h>
#include <string.h>

void game_time();
void game_load();
void greeting();
void course();
void chat();
void activity();
void information();
void option();
void next_day();

struct status{
	int talent;
	float add;
	float now;
};
struct status chinese = {1, 0, 99.50}; //beta
struct status english = {5, 0};
struct status math = {4, 0};
struct status social = {3, 0};
struct status science = {2, 0};

int const status_max = 100;

int extern first_log_in_definition;
int extern day_now;
int extern course_definition;
int extern const user_id;
char extern playername[20];

void game_main(){
	if(first_log_in_definition == 1){
		game_load();
		greeting();
		first_log_in_definition = 0;
	}
	
	pause(2);
	
	game_time();
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
				activity();
				break;
			case 4:
				information();
				break;
			case 5:
				next_day();
				break;
			case 6:
				option();
				break;	
		}
	}
	
}

void game_time(){ //遊戲時間 
	char day[3];
	int date = 1;
	int month = 9;
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
		    printf("Time's up !\n");
		    break;
		}
	}
	int code_check;
	FILE *fday;
	fday = fopen("data/text/day.txt", "r");
	int i = (day_now % 7) + 1;
	
	rewind(fday);
	while(!feof(fday)){
		fscanf(fday, "%d %s", &code_check, day);
		if(code_check == i){
			break;
		}
	}
	
	fclose(fday);
	
	printf("今天是%2d月%2d日(%s)\n", month, date, day);
}

void greeting(){
	
	
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
		chinese.add = (float)((rand() % chinese.talent) + 1) * 15 / 100;
		chinese.now += chinese.add;
		if(chinese.now > status_max){
			chinese.add = status_max - chinese.now;
			chinese.now = status_max;
		}
		printf("經過一番努力，增加了%.2f!\n", chinese.add);
	}
	else if(course_selection == 2){
		english.add = (float)((rand() % english.talent) + 1) * 15 / 100;
		english.now += english.add;
		if(english.now > status_max){
			english.add = status_max - english.now;
			english.now = status_max;
		}
		printf("經過一番努力，增加了%.2f!\n", english.add);
	}
	else if(course_selection == 3){
		math.add = (float)((rand() % math.talent) + 1) * 15 / 100;
		math.now += math.add;
		if(math.now > status_max){
			math.add = status_max - math.now;
			math.now = status_max;
		}
		printf("經過一番努力，增加了%.2f!\n", math.add);
	}
	else if(course_selection == 4){
		social.add = (float)((rand() % social.talent) + 1) * 15 / 100;
		social.now += social.add;
		if(social.now > status_max){
			social.add = status_max - social.now;
			social.now = status_max;
		}
		printf("經過一番努力，增加了%.2f!\n", social.add);
	}
	else if(course_selection == 5){
		science.add = (float)((rand() % science.talent) + 1) * 15 / 100;
		science.now += science.add;
		if(science.now > status_max){
			science.add = status_max - science.now;
			science.now = status_max;
		}
		printf("經過一番努力，增加了%.2f!\n", science.add);
	}
	
	course_definition = 0;
	game_main();
}

void chat(){ //beta
	char text[50];
	char name[20];
	
	FILE *fchat;
	fchat = fopen("data/text/chat.txt", "r");
	int code_check;
	int code = (rand() % 3) + 1; //beta
	int definition = 0;
	
	while(!feof(fchat)){
		fscanf(fchat, "%d %[^ ] %s", &code_check, name, text);
		if(code_check == code){
			if(name[0] == '%')
				printf("%s%s\n", playername, text);
			else if(name[0] == '*')
				printf("%s\n", text);
			else
				printf("%s%s\n", name, text);
			definition = 1;
		}
		if(definition == 1 && code_check != code)
			break;
	}
	sleep(2);
	
	game_main();
}

void activity(){
	puts("The function is not prepared.");
	game_main();
}

void next_day(){
	puts("明天見了~");
	
	day_now++;
	course_definition = 1;
	
	game_main();
}

void information(){
	char text[30];
	FILE *fplayername;
	fplayername = fopen("data/profile/playername.txt", "r");
	int id_check;
	
	rewind(fplayername);
	while(!feof(fplayername)){
		fscanf(fplayername, "%d %s", &id_check, text);
		if(id_check == user_id){
			printf("學霸姓名：%s\n", text);
		}
	}
	
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



