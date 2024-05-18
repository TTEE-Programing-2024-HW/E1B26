#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>

void pass(void){
}

int is_space_square(char arr[10][10]){
	int count=0;
	for(int r=1;r<=8;r++){
		for(int c=1;c<=8;c++){
			for(int i=0;i<2;i++){
				for(int j=0;j<2;j++){
					if(arr[r+i][c+j]=='-'){
						count++;
					}
				}
			}
			if(count==4){
				return 1;
			}
			else{
				count=0;
			}
		}
	}
	return 0;
}

int is_space_row(int n,char arr[10][10]){
	int count=0;
	for(int r=1;r<=9;r++){
		for(int c=1;c<=(10-n);c++){
			for(int i=0;i<n;i++){
				if(arr[r][c+i]=='-'){
					count++;
				}
			}
			if(count==n){
				return 1;
			}
			else{
				count=0;
			}
		}
	}
	return 0;
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
	int i;
	while(i!=10){
		srand(time(NULL)*i);
		int r=rand()%9+1,c=rand()%9+1;
		if(seat[r][c]=='*'){
			continue;
		}
		seat[r][c]='*';
		i++;
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
			while(1){
				int f=0;
				n=0;
				printf("How many seats do you need?(1~4)\n=>");
				fflush(stdin);
				scanf("%d",&n);
				if(1<=n&&n<=4){
					if(1<=n&&n<=3){
						if(is_space_row(n,seat)==1){
							while(1){
								srand(time(NULL));
								int r=rand()%9+1;
								int c=rand()%(10-n)+1;
								int count=0;
								for(int i=0;i<n;i++){
									if(seat[r][c+i]=='-'){
										count++;
									}
									else{
										break;
									}
								}
								if(count==n){
									for(int i=0;i<n;i++){
										seat[r][c+i]='@';
									}
									show(seat);
									while(1){
										printf("Are you satisfied with this system recommendation?(y/n):");
										ch=0;
										fflush(stdin);
										scanf("%c",&ch);
										if(ch=='Y'||ch=='y'){
											for(int i=0;i<n;i++){
												seat[r][c+i]='*';
											}
											printf("Fine, thank you for using this reservation system.\n");
											system("pause");
											system("cls");
											f=1;
											break;
										}
										else if(ch=='N'||ch=='n'){
											for(int i=0;i<n;i++){
												seat[r][c+i]='-';
											}
											printf("Sorry for your dissatisfaction. You can do again or choose by yourself.\n");
											system("pause");
											system("cls");
											f=1;
											break;
										}
										else{
											printf("Error input!\n");
										}
									}
									if(f==1){
										break;
									}
								}
							}
						}
						else{
							printf("Sorry, there are no seats left.\n");
							system("pause");
							system("cls");
							f=1;
						}
					}
					else{
						if(is_space_square(seat)==1){
							while(1){
								srand(time(NULL));
								int r=rand()%8+1;
								int c=rand()%8+1;
								int count=0;
								for(int i=0;i<2;i++){
									for(int j=0;j<2;j++){
										if(seat[r+i][c+j]=='-'){
											count++;
										}
									}
								}
								if(count==4){
									for(int i=0;i<2;i++){
										for(int j=0;j<2;j++){
											seat[r+i][c+j]='@';
										}
									}
									show(seat);
									while(1){
										printf("Are you satisfied with this system recommendation?(y/n):");
										ch=0;
										fflush(stdin);
										scanf("%c",&ch);
										if(ch=='Y'||ch=='y'){
											for(int i=0;i<2;i++){
												for(int j=0;j<2;j++){
													seat[r+i][c+j]='*';
												}
											}
											printf("Fine, thank you for using this reservation system.\n");
											system("pause");
											system("cls");
											f=1;
											break;
										}
										else if(ch=='N'||ch=='n'){
											for(int i=0;i<2;i++){
												for(int j=0;j<2;j++){
													seat[r+i][c+j]='-';
												}
											}
											printf("Sorry for your dissatisfaction. You can do again or choose by yourself.\n");
											system("pause");
											system("cls");
											f=1;
											break;
										}
										else{
											printf("Error input!\n");
										}
									}
								}
								if(f==1){
									break;
								}
							}
							pass();
						}
						else if(is_space_row(4,seat)==1){
							while(1){
								srand(time(NULL));
								int r=rand()%9+1;
								int c=rand()%(10-n)+1;
								int count=0;
								for(int i=0;i<n;i++){
									if(seat[r][c+i]=='-'){
										count++;
									}
									else{
										break;
									}
								}
								if(count==n){
									for(int i=0;i<n;i++){
										seat[r][c+i]='@';
									}
									show(seat);
									while(1){
										printf("Are you satisfied with this system recommendation?(y/n):");
										ch=0;
										fflush(stdin);
										scanf("%c",&ch);
										if(ch=='Y'||ch=='y'){
											for(int i=0;i<n;i++){
												seat[r][c+i]='*';
											}
											printf("Fine, thank you for using this reservation system.\n");
											system("pause");
											system("cls");
											f=1;
											break;
										}
										else if(ch=='N'||ch=='n'){
											for(int i=0;i<n;i++){
												seat[r][c+i]='-';
											}
											printf("Sorry for your dissatisfaction. You can do again or choose by yourself.\n");
											system("pause");
											system("cls");
											f=1;
											break;
										}
										else{
											printf("Error input!\n");
										}
									}
									if(f==1){
										break;
									}
								}
							}
							pass();
						}
						else{
							printf("Sorry, there are no seats left.\n");
							system("pause");
							system("cls");
							f=1;
						}
					}
				}
				if(f==1){
					break;
				}
			}
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