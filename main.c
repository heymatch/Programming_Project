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
	puts("�����G1.01_beta");
	puts("��s��G2/7");
}
