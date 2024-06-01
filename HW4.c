#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// Define a structure for student information
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

// Function to enter student grades
void Etr(stu**_cls,int*_count){
	int add=0,f=0;
	system("cls");
	printf("How many students do you want to add(5~10)?\n=>");
	// Loop to ensure valid number of students
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
	// Allocate or reallocate memory for students
	stu*temp=(stu*)realloc(*_cls,sizeof(stu)*(*_count+add));
	if(temp==NULL){
		printf("Memory addition failed.\n");
		return;
	}
	*_cls=temp;
	
	// Loop to input student details
	for(int i=0;i<add;i++){
		printf("Please enter the %dth student's name\n=>",i+1);
		fflush(stdin);
        fgets((*_cls)[*_count+i].name,sizeof((*_cls)[*_count+i].name),stdin);
        int len=strlen((*_cls)[*_count+i].name);
        if(len> 0 && (*_cls)[*_count+i].name[len-1] =='\n'){
            (*_cls)[*_count+i].name[len-1] = '\0';
        }
        printf("Please enter the %dth student's ID\n=>",i+1);
        
        // Input and validate student ID
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
        
        // Input and validate Math grade
        while(1){
        	fflush(stdin);
        	if(scanf("%f",&(*_cls)[*_count+i].mat)==1&&0<=(*_cls)[*_count+i].mat&&(*_cls)[*_count+i].mat<=100){
                break;
            } else {
                printf("Please enter 0 to 100.\n=>");
            }
		}
        printf("Please enter the %dth student's Physics grade\n=>",i+1);
        // Input and validate Physics grade
        while(1){
        	fflush(stdin);
        	if(scanf("%f",&(*_cls)[*_count+i].phy)==1&&0<=(*_cls)[*_count+i].phy&&(*_cls)[*_count+i].phy<=100){
                break;
            } else {
                printf("Please enter 0 to 100.\n=>");
            }
		}
        printf("Please enter the %dth student's English grade\n=>",i+1);
        // Input and validate English grade
        while(1){
        	fflush(stdin);
        	if(scanf("%f",&(*_cls)[*_count+i].eng)==1&&0<=(*_cls)[*_count+i].eng&&(*_cls)[*_count+i].eng<=100){
                break;
            } else {
                printf("Please enter 0 to 100.\n=>");
            }
		}
		// Calculate average grade
		(*_cls)[*_count+i].ave=((*_cls)[*_count+i].mat+(*_cls)[*_count+i].phy+(*_cls)[*_count+i].eng)/3.0;
	}
	// Update student count
	(*_count)+=add;
}

// Function to display student grades
void Dsp(stu**_cls,int*_count){
	system("cls");
	printf("%8s%8s%16s\n","Name","ID","average grade");
	for(int i=0;i<*_count;i++){
		printf("%8s%8s%16.1f\n",(*_cls)[i].name,(*_cls)[i].ID,(*_cls)[i].ave);
	}
	system("pause");
	system("cls");
}

// Function to search for a student by name
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

// Function to rank students by their average grades
void Rank(stu**_cls,int*_count){
	// Allocate memory for ranking students
    stu*rank=(stu*)malloc(sizeof(stu)*(*_count));
    if(rank==NULL){
        printf("Memory allocation failed.\n");
        return;
    }
    for(int i=0;i<*_count;i++){
        rank[i]=(*_cls)[i];
    }
	
	// Sort students by average grade in descending order
    for(int i=0;i<*_count-1;i++){
        for(int j=0;j<*_count-i-1;j++){
            if(rank[j].ave<rank[j+1].ave){
                stu temp=rank[j];
                rank[j]=rank[j+1];
                rank[j+1]=temp;
            }
        }
    }
    // Display ranked students
    Dsp(&rank,&*_count);
    free(rank);
    system("pause");
    system("cls");
}

int main(void){
	
	int c=1,pw=2024,ipw=0,n;
	char ch;
	
	printf("System is online\n");	// Display indicates program start
    for(int i=1;i<=20;i++){       	// Start displaying personal style screen
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
    stu* cls=(stu*)malloc(0);// cls is a single pointer pointing to stu structure
    
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
    			Rank(&cls,&count);
    			pass();
				break;
			}
			case 'E':
    		case 'e':{
    			char ch;
				printf("Are you sure you want to exit?(Y/N)\n=>");
				while(1){
					fflush(stdin);
					scanf("%c",&ch);
					if(ch=='Y'||ch=='y'){
						printf("Good bye!\n");
						free(cls);
						return 0;
					}
					else if(ch=='N'||ch=='n'){
						break;
					}
					else{
						printf("Are you sure you want to exit?(Y/N)\n=>");
					}
				}
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
//這一次我花一天就寫完了，但是我花了很久的時間，嘗試使用了動態記憶體配置的陣列，搞了很久在指針的變數宣告上