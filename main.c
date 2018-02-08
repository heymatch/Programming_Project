#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

void version();

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
	puts("版本：1.2_beta");
	puts("更新日：2/8");
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
