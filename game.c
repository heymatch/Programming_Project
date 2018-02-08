#include <stdio.h>
#include <string.h>

void greeting();
void course();
void chat();
void action();
void status();
void option();
void value_setting();

int extern user_id;
char playername[20];

void game_main(){
	pause(2);
	puts("選課(1)");
	puts("聊天(2)");
	puts("活動(3)");
	puts("狀態(4)");
	puts("設定(5)");
	
	value_setting();
	
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
				action();
				break;
			case 4:
				status();
				break;
			case 5:
				option();
				break;
		}
	}
	
}

void value_setting(){
	FILE *fplayername;
	fplayername = fopen("data/profile/playername.txt", "r");
	int id_check;
	
	rewind(fplayername);
	while(!feof(fplayername)){
		fscanf(fplayername, "%d %s", &id_check, playername);
		if(id_check == user_id){
			break;
		}
	}
	
}

void course(){
	puts("The function is not prepared.");
	game_main();
}

void chat(){
	char text[50];
	char name[20];
	
	FILE *fchat;
	fchat = fopen("data/text/chat.txt", "r");
	int code_check;
	int code = (rand() % 1) + 1;
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
	
	
	game_main();
}

void action(){
	puts("The function is not prepared.");
	game_main();
}

void status(){
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
	puts("返回(-1)");
	
	int selection;
	while(selection != -1){
		scanf("%d", &selection);
		switch(selection){
			case 1:
				log_out();
				break;
			case -1:
				game_main();
				break;
		}
	}
}

void log_out(){
	puts("已成功登出!");
	pause(2);
	main();
}
