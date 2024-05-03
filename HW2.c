#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

void pass(void){
}

int main(void){
	
	int c=1,pw=2024,ipw=0,n;
	char ch;
	
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
    	fflush(stdin);
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
    while(1){
    	printf("/\\/\\/\\/\\/\\/\\/\\/\\/\n");
    	printf("\\ a.畫出直角三角\\\n");
    	printf("/ b.顯示乘法表  /\n");
    	printf("\\ c.結束        \\\n");
    	printf("/\\/\\/\\/\\/\\/\\/\\/\\/\n=>");
    	fflush(stdin);
    	scanf("%c",&ch);
    	if(ch=='A'||ch=='a'){
    		system("CLS");
    		printf("Pls enter a character('a'~'n')\n=>");
    		while(1){
    			fflush(stdin);
    			ch=0;
    			scanf("%c",&ch);
    			if(ch>='a'&&ch<='n'){
    				break;
				}
				else{
					printf("Error! Pls enter a character('a'~'n')\n=>\n");
				}
			}
			for(char i=ch;i>='a';i--){
				for(int j=i-'a';j>0;j--){
					printf(" ");
				}
				for(char j=i;j<=ch;j++){
					printf("%c",j);
				}
				printf("\n");
			}
    		system("PAUSE");
    		system("CLS");
    		pass();
		}
		else if(ch=='B'||ch=='b'){
			printf("Pls enter a number(1~9)\n=>");
    		while(1){
    			fflush(stdin);
    			n=0;
    			scanf("%d",&n);
    			if(n>=1&&n<=9){
    				break;
				}
				else{
					printf("Error! Pls enter a number(1~9)\n=>");
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					printf("%1d×%1d=%2d ",j,i,i*j);
				}
				printf("\n");
			}
    		system("PAUSE");
    		system("CLS");
			pass();
		}
		else if(ch=='C'||ch=='c'){
			pass();
		}
		else{
			pass();
		}
	}
    
    
	return 0;
}