#include <stdio.h>
#include <windows.h>

void version();

void main() {
	
	registration_main();
	initial_setting();
	game_main();
	
	return ;
}

void pause(int n){
	sleep(n);
	system("cls");
}

void version(){
	puts("版本：1.01_beta");
	puts("更新日：2/7");
}
