#include <stdio.h>

void course();
void chat();
void action();
void status();
void option();

void game_main(){
	pause(2);
	puts("選課(1)");
	puts("聊天(2)");
	puts("活動(3)");
	puts("狀態(4)");
	puts("設定(5)");
	
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
