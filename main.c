#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

void version();
void pause(int n);
void system_message(int code);

void main() {
	srand(time(NULL));
	
	registration_main();
	initial_setting();
	game_main();
	
	return;
}

void pause(int n){
	sleep(n);
	system("cls");
}

void version(){
	puts("版本：1.0.6_beta");
	puts("更新日：3/18");
}

void system_message(int code){
	FILE *fsystem_message;
	fsystem_message = fopen("data/text/system_message.txt", "r");
	int code_check;
	char text[50];
	int definition = 0;
	
	rewind(fsystem_message);
	while(!feof(fsystem_message)){
		fscanf(fsystem_message, "%d %s", &code_check, text);
		if(code_check == code){
			printf("%s\n", text);
			definition = 1;
		}
		if(definition == 1 && code_check != code)
			break;
	}
	
	fclose(fsystem_message);
}

