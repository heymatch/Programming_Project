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
	puts("版本：1.0.3_beta");
	puts("更新日：2/12");
}
