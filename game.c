#include <stdio.h>

void course();
void chat();
void action();
void status();
void option();

void game_main(){
	pause(2);
	puts("���(1)");
	puts("���(2)");
	puts("����(3)");
	puts("���A(4)");
	puts("�]�w(5)");
	
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
			case 5:
				option();
				break;
		}
	}
	
}



void log_out();

void option(){
	puts("�n�X(1)");
	puts("��^(-1)");
	
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
	puts("�w���\�n�X!");
	pause(2);
	main();
}
