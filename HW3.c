#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>

void pass(void){
}

void show(char arr[10][10]){
	for(int r=0;r<10;r++){
		for(int c=0;c<10;c++){
			printf("%c ",arr[r][c]);
		}
		printf("\n");
	}
}

int main(void){
	char seat[10][10];
	
	int c=1,pw=2024,ipw=0,n;
	char ch;
	
	printf("System is online\n");	//顯示時表示程式正常啟動
    for(int i=1;i<=20;i++){       	//開始顯示個人風格畫面
        for(int j=0;j<i;j++){
            printf(">");
        }
        for(int j=0;j<(100-2*i);j++){
            if(i==20&&j==17){
                printf("Welcome to the file HW3.c");
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
        printf("\n");				//個人風格畫面結束
    }
    while(1){				//進入輸入密碼環節
    	printf("Pls enter 4 digits passwor(%d/3)(Hint:2024)\n=>",c);
    	fflush(stdin);
    	scanf("%d",&ipw);	//儲存輸入的密碼
    	if(ipw==pw){
    		break;
		}
		else if(c==3){		//輸錯密碼到第三次時
			printf("Error password over 3 times\n");
			return 0;
		}
		c++;				//累計密碼輸入次數
	}
	printf("Log in suceesfully\n");  	
	system("PAUSE");
    system("CLS");
    //第一題結束
    
    seat[0][0]='\\';
    for(int i=1;i<=9;i++){
    	seat[i][0]='0'+i;
    	seat[0][i]='0'+i;
	}
	for(int r=1;r<=9;r++){
		for(int c=1;c<=9;c++){
			seat[r][c]='-';
		}
	}
	for(int i=0;i<10;i++){
		srand(time(NULL)*i);
		seat[rand()%9+1][rand()%9+1]='*';
	}
    
    while(1){
    	//顯示選單
    	printf("/\\/\\[Booking System]/\\/\\\n");
    	printf("\\ a.Available seats    /\n");
    	printf("/ b.Arrange for you    \\\n");
    	printf("\\ c.Choose by yourself /\n");
    	printf("/ d.Exit               \\\n");
    	printf("\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\n=>");
    	fflush(stdin);
    	scanf("%c",&ch);
    	if(ch=='A'||ch=='a'){
    		show(seat);
    		system("pause");
    		system("cls");
    		pass();
		}
		else if(ch=='B'||ch=='b'){
			pass();
		}
		else if(ch=='C'||ch=='c'){
			pass();
		}
		else if(ch=='D'||ch=='d'){
			printf("\'Continue?(y/n):");
			while(1){
				fflush(stdin);
				ch=0;
				scanf("%c",&ch);
				if(ch=='N'||ch=='n'){
					printf("Ok, byebye :>");
					return 0;		//程式結束
				}
				else if(ch=='Y'||ch=='y'){
					break;			//跳出並回到顯示表單那裡
				}
				else{
					printf("Error input!\n\'Continue?(y/n):");
				}
			}
			system("CLS");
			pass();
		}
		else{
			printf("Error! Pls enter a,b,c and d to choose function you want.\n");
			pass();
		}
	}
    
    
	return 0;
}