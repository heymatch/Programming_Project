#include <stdio.h>
#include <stdlib.h>

int log_in();
int sign_in();
void game_over();

int user_id;

void registration_main(){
	int selection;
	int verify;
	
	while(selection != -1){
		pause(2);
		puts("登入(1)");
		puts("註冊(2)");
		puts("離開遊戲(-1)");
		
		scanf("%d", &selection);
		switch(selection){
			case 1:
				verify = log_in();
				break;
			case 2:
				verify = sign_in();
				break;
			case -1:
				game_over();
				break;
		}
		if(verify == 1)
			break;
	}
}

int log_in(){
	char username[20];
	char password[20];
	
	puts("帳號:");
	scanf("%s", username);
	puts("密碼:");
	scanf("%s", password);
	
	if(check_user(username, "username") == 0){
		puts("Username is not found.");
		return 0;
	}
	else if(check_user(password, "password") == 0){
		puts("Password is incorrect.");
		return 0;
	}
	else if(check_user(username, "username") == check_user(password, "password")){
		puts("Succeed!");
		return 1;
	}
}

int sign_in(){
	char username[20];
	char password[20];
	
	puts("請輸入新帳號:");
	scanf("%s", username);
	if(check_user(username, "username") == 0){
		puts("請輸入新密碼:");
		scanf("%s", password);
		
		FILE *fregister_username;
		FILE *fregister_password;
		FILE *fregister_id;
		FILE *fcheck_id;
		fregister_username = fopen("data/account/username.txt", "a");
		fregister_password = fopen("data/account/password.txt", "a");
		fcheck_id = fopen("data/account/id.txt", "r");
		
		fprintf(fregister_username, "\n%s", username);
		fprintf(fregister_password, "\n%s", password);
		int data_id;
		while(!feof(fcheck_id)){
			fscanf(fcheck_id, "%d", &data_id);
		}
		fregister_id = fopen("data/account/id.txt", "a");
		fprintf(fregister_id, "\n%d", data_id + 1);
		
		puts("帳號已成功建立，請重新登入");
		FILE *fregister_initialization;
		fregister_initialization = fopen("data/profile/initialization.txt", "a");
		fprintf(fregister_initialization, "%d %d",data_id + 1 ,0);
		
		fclose(fregister_username);
		fclose(fregister_password);
		fclose(fregister_id);
		fclose(fregister_initialization);
	}
	else
		puts("已有此帳號，請重新註冊");
	
	return 0;
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
