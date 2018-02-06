#include <stdio.h>

int main() {
	
	registration_main();
	game_main();
	
	return 0;
}

void pause(int n){
	sleep(n);
	system("cls");
}
