#include<stdio.h>
#include<stdlib.h>

// Empty function placeholder
void pass(void){
}


int main(void){
	
	int c=1,pw=2024,ipw=0,n;
	char ch;
	
	printf("System is online\n");	//顯示時表示程式正常啟動
    for(int i=1;i<=20;i++){       	//開始顯示個人風格畫面
        for(int j=0;j<i;j++){
            printf(">");
        }
        for(int j=0;j<(100-2*i);j++){
            if(i==20&&j==17){
                printf("Welcome to the file HW4.c");
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
	// Password input loop
    while(1){
    	printf("Pls enter 4 digits passwor(%d/3)(Hint:2024)\n=>",c);
    	fflush(stdin);
    	scanf("%d",&ipw); // Store entered password
    	if(ipw==pw){
    		break;
		}
		else if(c==3){		// After three incorrect attempts
			printf("Error password over 3 times\n");
			return 0;
		}
		c++;				// Increment password attempt counter
	}
	printf("Log in suceesfully\n");  	
	system("PAUSE");
    system("CLS");
    while(1){
    	// Main menu loop
    	printf("/\\/\\/\\/\\[Grade System]/\\/\\/\\/\\\n");
    	printf("\\ a.Enter student grades      \\\n");
    	printf("/ b.Display student grades    /\n");
    	printf("\\ c.Search for student grades \\\n");
    	printf("/ d.Grade ranking             /\n");
    	printf("\\ e.Exit system               \\\n");
    	printf(" \\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\n=>");
    	fflush(stdin);
    	scanf("%c",&ch);
    }
    return 0;
}