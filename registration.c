#include <stdio.h>
#include <stdlib.h>

void log_in();
void sign_in();
void game_over();

int user_id;

void registration_main(){
	puts("登入(1)");
	puts("註冊(2)");
	puts("離開遊戲(-1)");
	
	int selection;
	while(selection != -1){
		scanf("%d", &selection);
		switch(selection){
			case 1:
				log_in();
				pause(2);
				break;
			case 2:
				sign_in();
				break;
			case -1:
				game_over();
				break;
		}
		break;
	}
}

void log_in(){
	char username[20];
	char password[20];
	
	puts("帳號:");
	scanf("%s", username);
	puts("密碼:");
	scanf("%s", password);
	
	if(check_user(username, "username") == 0){
		puts("Username is not found.");
		registration_main();
	}
	else if(check_user(password, "password") == 0){
		puts("Password is incorrect.");
		registration_main();
	}
	else if(check_user(username, "username") == check_user(password, "password")){
		puts("Succeed!");
	}
}

void sign_in(){
	printf("這功能未完成\n");
}

void game_over(){
	puts("Thank you for playing");
	system("PAUSE");
	exit(0);
}

int check_user(char *checked, char *check){
	FILE *fcheck_username;
	FILE *fcheck_password;
	FILE *fcheck_id;
	fcheck_username = fopen("data/account/username.txt", "r");
	fcheck_password = fopen("data/account/password.txt", "r");
	fcheck_id = fopen("data/account/id.txt", "r");
	
	if(strcmp(check, "username") == 0){
		char data_username[20];
		int data_id;
		
		rewind(fcheck_username);
		rewind(fcheck_id);
		while(!feof(fcheck_id)){
			fscanf(fcheck_username, "%s", data_username);
			fscanf(fcheck_id, "%d", &data_id);
			if(strcmp(data_username, checked) == 0){
				user_id = data_id;
				return data_id;
			}
		}
		return 0;
		
	}
	if(strcmp(check, "password") == 0){
		char data_password[20];
		int data_id;
		
		rewind(fcheck_password);
		rewind(fcheck_id);
		while(!feof(fcheck_id)){
			fscanf(fcheck_password, "%s", data_password);
			fscanf(fcheck_id, "%d", &data_id);
			if(strcmp(data_password, checked) == 0)
				return data_id;
		}
		return 0;
	}
}
