#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
    int date=1;
	int month=9;
	
	printf("%d 月 %d 日\n",month,date);
	int class;
	while(class != -1)//返回為-1
	{
		scanf("%d", &class);
		date++;
		
		if(date==31)
		{
			if(month==9 || month==11)
			{
				month++;
				date=1;
			}
		}
		
		if(date==32)
		{
			if(month==10)
			{
				month++;
				date=1;
			}
		    if(month==12)
		    {
		    	month=1;
		    	date=1;
			}
		}
		
		if(month==1 && date==25)
		{
		    printf("Time's up !\n");
		    break;
		}
		
		printf("%d 月 %d 日\n", month, date);
		
	}
	return 0;
}
