#include<stdio.h>
#include <stdlib.h>

int main(void){

    int pw;
    char ch;
    
	//第一題個人風格畫面
    printf("System is online\n");
    for(int i=1;i<=20;i++){
        for(int j=0;j<i;j++){
            printf(">");
        }
        for(int j=0;j<(100-2*i);j++){
            if(i==20&&j==17){
                printf("Welcome to the file P1E1B26");
                j+=26;
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
    
	system("PAUSE");
    system("CLS");
    //第一題結束
	//第二題開始
	printf("Pls enter 4 digits password:");
    fflush(stdin);
    scanf("%d",&pw);
    if(pw==2024){//確認密碼
        printf("Welcome to your account\n");
    }
    else{
        printf("%c",'\a');
        printf("password erro");
        return 0;
    }
    system("PAUSE");
    system("CLS");
    //第二題結束
	//第三題開始
	printf("/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\\n");
    printf("\\ 1. \'A\'...\'Z\' => Uppercase      /\n");
    printf("/ 2. \'a\'...\'z\' => Lowercase      \\\n");
    printf("\\ 3. \'0\'...\'9\' => Digit          /\n");
    printf("/ 4. Otherwise => E1B26王奕超    \\\n");
    printf("\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\n");
    //第三題結束
    //第四題開始
    printf("\nPls enter 1 character:");
    fflush(stdin);
    scanf("%c",&ch);
    if('A'<=ch && ch<='Z'){
        printf("Uppercase\n");
    }
    else if('a'<=ch&&ch<='z'){
        printf("Lowercase\n");
    }
    else if('0'<=ch&&ch<='9'){
        printf("Digit\n");
    }
    else{
        printf("E1B26王奕超\n");
    }
    system("PAUSE");
    //第四題結束
    return 0;
}