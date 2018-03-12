#include <stdio.h>

void ending();
void thanks(int code);
void staff();

int extern protagonist_selection;

char extern playername[20];

int extern const textlong;
int extern const namelong;

void ending(){
	thanks(5); //beta
	pause(2);
	staff();
}

void thanks(int code){
	char text[textlong];
	char name[namelong];
	
	FILE *fthanks;
	fthanks = fopen("data/text/thanks.txt", "r");
	int code_check;
	int definition = 0;
	int i;
	
	while(!feof(fthanks)){
		fscanf(fthanks, "%d %[^ ] %s", &code_check, name, text);
		if(code_check == code){
			if(name[0] == '%')
				printf("%s", playername);
			else if(name[0] == '*')
				;
			else if(name[0] == '/')
				;
			else
				printf("%s", name);
			for(i = 0; text[i] != '\0'; i++){
				if(text[i] == '%')
					printf("%s", playername);
				else if(text[i] == '/')
					Sleep(75);
				else if(text[i] == '_')
					printf(" ");
				else
					printf("%c", text[i]);
				text[i] = '\0';
				Sleep(75);
			}
			printf("\n");
			definition = 1;
		}
		if(definition == 1 && code_check != code)
			break;
		if(code_check == 0)
			break;
	}
	system("pause");
	fclose(fthanks);
}

void staff(){
	char text[textlong];
	
	FILE *fstaff;
	fstaff = fopen("data/text/staff.txt", "r");
	int i;
	
	while(!feof(fstaff)){
		fscanf(fstaff, "%s", text);
		for(i = 0; text[i] != '\0'; i++){
			if(text[i] == '%')
				printf("%s", playername);
			else if(text[i] == '/')
				Sleep(75);
			else if(text[i] == '_')
				printf(" ");
			else
				printf("%c", text[i]);
			text[i] = '\0';
			Sleep(75);
		}
		printf("\n");
	}
	system("pause");
	fclose(fstaff);
}
