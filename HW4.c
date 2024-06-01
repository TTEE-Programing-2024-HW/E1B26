#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
	char name[20];
	char ID[7];
	float mat;
	float phy;
	float eng;
	float ave;
}stu;

// Empty function placeholder
void pass(void){
}

void Etr(stu** _cls,int* _count){
	int add=0,f=0;
	system("cls");
	printf("How many students do you want to add(5~10)?\n=>");
	while(1){
		fflush(stdin);
		scanf("%d",&add);
		if(1<=add&&add<=10){//Test mode
			break;
		}
		else{
			printf("Please enter a number from 5 to 10\n=>");
		}
	}
	stu*temp=(stu*)realloc(*_cls,sizeof(stu)*(*_count+add));
	if(temp==NULL){
		printf("Memory addition failed.\n");
		return;
	}
	*_cls=temp;
	for(int i=0;i<add;i++){
		printf("Please enter the %dth student's name\n=>",i+1);
		fflush(stdin);
        fgets((*_cls)[*_count+i].name,sizeof((*_cls)[*_count+i].name),stdin);
        int len=strlen((*_cls)[*_count+i].name);
        if(len> 0 && (*_cls)[*_count+i].name[len-1] =='\n'){
            (*_cls)[*_count+i].name[len-1] = '\0';
        }
        printf("Please enter the %dth student's ID\n=>",i+1);
        while(1){
        	f=0;
        	fflush(stdin);
        	fgets((*_cls)[*_count+i].ID,sizeof((*_cls)[*_count+i].ID),stdin);
        	len= strlen((*_cls)[*_count+i].ID);
        	if (len>0 && (*_cls)[*_count + i].ID[len-1]=='\n'){
            (*_cls)[*_count+i].ID[len-1]='\0';
			}
        	for(int j=0;j<sizeof((*_cls)[*_count+i].ID)-1;j++){
        		if('0'<=(*_cls)[*_count+i].ID[j]&&(*_cls)[*_count+i].ID[j]<='9'){
        			f++;
				}
        	}
        	if(f==6){
        		break;
			}
			else{
				printf("Error!\nPlease enter a 6-digit integer\n=>");
			}
		}
        fflush(stdin);
        printf("Please enter the %dth student's Math grade\n=>",i+1);
        while(1){
        	fflush(stdin);
        	if(scanf("%f",&(*_cls)[*_count+i].mat)==1&&0<=(*_cls)[*_count+i].mat&&(*_cls)[*_count+i].mat<=100){
                break;
            } else {
                printf("Please enter 0 to 100.\n=>");
            }
		}
        printf("Please enter the %dth student's Physics grade\n=>",i+1);
        while(1){
        	fflush(stdin);
        	if(scanf("%f",&(*_cls)[*_count+i].phy)==1&&0<=(*_cls)[*_count+i].phy&&(*_cls)[*_count+i].phy<=100){
                break;
            } else {
                printf("Please enter 0 to 100.\n=>");
            }
		}
        printf("Please enter the %dth student's English grade\n=>",i+1);
        while(1){
        	fflush(stdin);
        	if(scanf("%f",&(*_cls)[*_count+i].eng)==1&&0<=(*_cls)[*_count+i].eng&&(*_cls)[*_count+i].eng<=100){
                break;
            } else {
                printf("Please enter 0 to 100.\n=>");
            }
		}
		(*_cls)[*_count+i].ave=((*_cls)[*_count+i].mat+(*_cls)[*_count+i].phy+(*_cls)[*_count+i].eng)/3.0;
	}
	(*_count)+=add;
}

void Dsp(stu** _cls,int *_count){
	system("cls");
	printf("%8s%8s%16s\n","Name","ID","average grade");
	for(int i=0;i<*_count;i++){
		printf("%8s%8s%16.1f\n",(*_cls)[i].name,(*_cls)[i].ID,(*_cls)[i].ave);
	}
	system("pause");
	system("cls");
}

void Srch(stu**_cls,int*_count){
	char inputname[sizeof((*_cls)->name)];
	system("cls");
	printf("Please enter the name you want to search for\n=>");
	fflush(stdin);
	fgets(inputname,sizeof((*_cls)->name),stdin);
	int len=strlen(inputname);
   	if(len>0&&inputname[len-1] =='\n'){
	   inputname[len-1] = '\0';
    }
    printf("%8s%8s%8s%8s%8s%16s\n","Name","ID","Math","Physics","English","average grade");
    int situ=0;
    for(int i=0;i<(*_count);i++){
    	if(strcmp(inputname,(*_cls)[i].name)==0){
    		printf("%8s%8s%8.1f%8.1f%8.1f%16.1f\n",(*_cls)[i].name,(*_cls)[i].ID,(*_cls)[i].mat,(*_cls)[i].phy,(*_cls)[i].eng,(*_cls)[i].ave);
    		situ=1;
		}
	}
	if(situ==0){
		printf("NO data\n");
	}
	system("pause");
	system("cls");
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
    
    int count=0;
    stu* cls=(stu*)malloc(0);//cls 是指向stu結構的單一指針
    
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
    	switch(ch){
    		case 'A':
    		case 'a':{
    			Etr(&cls, &count);
    			pass();
				break;
			}
			case 'B':
    		case 'b':{
    			Dsp(&cls, &count);
    			pass();
				break;
			}
			case 'C':
    		case 'c':{
    			Srch(&cls, &count);
    			pass();
				break;
			}
			case 'D':
    		case 'd':{
    			pass();
				break;
			}
			case 'E':
    		case 'e':{
    			pass();
				break;
			}
			default:{
				printf("Error!\nPlease enter A to E\n");
				system("pause");
				system("cls");
				break;
			}
		}
    }
    return 0;
}