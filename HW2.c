#include<stdio.h>
#include <stdlib.h>

int main(void){
	
	int c=1,pw=2024,ipw;
	
	printf("System is online\n");
    for(int i=1;i<=20;i++){
        for(int j=0;j<i;j++){
            printf(">");
        }
        for(int j=0;j<(100-2*i);j++){
            if(i==20&&j==17){
                printf("Welcome to the file HW2.c");
                j+=24;
            }
            else{
                printf(" ");
            }
        }
        for(int j=0;j<i;j++){
            printf("<");
        }
        printf("\n");
    }
    for(int i=21;i<=40;i++){
        for(int j=0;j<(40-i);j++){
            printf(">");
        }
        for(int j=0;j<(2*i+20);j++){
            printf(" ");
        }
        for(int j=0;j<(40-i);j++){
            printf("<");
        }
        printf("\n");
    }
    while(1){
    	printf("Pls enter 4 digits passwor(%d/3)(Hint:2024)\n=>",c);
    	scanf("%d",&ipw);
    	if(ipw==pw){
    		break;
		}
		else if(c==3){
			printf("Error password over 3 times\n");
			system("PAUSE");
			return 0;
		}
		c++;
	}
	printf("Log in suceesfully\n");
	system("PAUSE");
    system("CLS");
    //第一題結束
	return 0;
}