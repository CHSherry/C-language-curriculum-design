/*
1.11-xxx 24����Ϸ���Ѷȵȼ���5����
������������
�������4���ƣ������ܷ��ã������������½�����ϳ�24��
�������ܵ����ʽ��
*/

//���ڵ���getch()��fflush(stdin),�������ֲ�Խϲ�,�뾡����vc++6.0�б�������.

#include <stdio.h>
#include <time.h>
#include <math.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>

//------------------------------------------ȫ�ֱ���

struct set{
	int mode;//��ǰģʽ 1.���Ҽ���(����С��) 2.��ϰģʽ(�޾�ģʽ) 3.����ģʽ 4.˫��ģʽ 5.���� 6.���� 0.exit
	int isPrint;//�Ƿ������� 1.��� 0.�����
	int saveSettings;//�Ƿ񱣴浱ǰ����

};

struct set settings;

int N = 24;

int low=1;//����Ϊ1
int high=13;//����Ϊ13

char op[4]={'+','-','*','/'};

float arr[4]={0};//arr������ż�����
float cur[4]={0};//cur������ŵ�ǰ����
float con[4]={0};//con�������ԭʼ����


//------------------------------------------�����б�

void initSettings();
float calc(float n1, float n2, char o);
void initAllFromCon();
void randomGet();
int isJQK(char *p);
void userGet();
int userGetIn();
void printResult_1(int a,int b,int c);
void printResult_2(int a,int b,int c);
void initArrFromCur();
void exercise();


int s_first();	//ģ��ƽ�������֮����
int s_second();	//ģ��ƽ�������֮˫��

int test(void);
void menuPrint();

int move();
void exitGame(void);


//------------------------------------------���������˵�����


void main(void) {

	
	system("color 47");
	initSettings();
	srand((unsigned)time(NULL));
	int a;
	
	while (1) {

		menuPrint();
		a=move();
		switch (a) {
			//1.���Ҽ��� 2.��ϰģʽ 3.����ģʽ 4.˫��ģʽ 5.���� 6.���� 0.exit
			case 1:userGet();continue;
			case 2:exercise();continue;
			default:break;
		}
	}
}

void menuPrint() {

	system("cls");
	char name[10][sizeof(char)*15]={
		"exit.txt",
		"menu_1.txt",
		"menu_2.txt",
		"menu_3.txt",
		"menu_4.txt",
		"menu_5.txt",
		"menu_6.txt",
	};

	char ch;
	FILE *fp;
	fp=fopen(name[settings.mode],"r");

	if(fp==NULL) {
		printf("cannot open %s\n",name[settings.mode]);
		exit (0);
	}
	while(!feof(fp)) {
		ch=fgetc(fp);
		putchar(ch);
	}
	fclose(fp);
}

int move() {
	
	char key = 0;

	while (1) {

		fflush(stdin); //����������� 
		key = getch();
		if(key==0||key==-32)
			key = getch();
		if (key==72)
			settings.mode--;//down
		else if (key==80)
			settings.mode++;
		else if (key>=49&&key<=52)
			return key-48;
		else if (key==48) 
			exitGame();
		else if (key==13)
			if(settings.mode)
				return settings.mode;
			else
				exitGame();
		else
			key=0;
		
		if(settings.mode<0)
			settings.mode=settings.mode+5;
		if(settings.mode>4)
			settings.mode=settings.mode-5;
		
		menuPrint();
	}

	return settings.mode;
}

void exitGame(void) {
	
	printf("\n\t\t�����˳���Ϸ...");
	exit(0);

}

//------------------------------------------һ������

void userGet() {

	settings.isPrint=1;
	int a=1;
	//���userGetIn()�ķ���ֵΪ0�򷵻����˵�,�������ִ��userGetIn()
	while (a) {
		printf("����%d��\n",N);
		a=userGetIn();
		//system("pause");
	}
	
}

void exercise() {

	system("cls");
	randomGet();
	
	//�����и����Ʋ˵�
	system("pause");
}


//------------------------------------------��������


void initSettings() {

	settings.mode=1;
	settings.isPrint=0;
	settings.saveSettings=1;

}


void initAllFromCon() {

	int i;
	for(i=0;i<4;i++) {
		arr[i]=con[i];
		cur[i]=con[i];
	}
}

void initArrFromCur() {

	int g;
	for(g=0;g<4;g++)
		arr[g]=cur[g];

}

float calc(float n1, float n2, char o) {

    switch(o) {
        case '+': return (n1+n2);
        case '-': return (n1-n2);
        case '*': return (n1*n2);
        case '/': 
			if(n2==0)
				return -30000;
			else
				return (n1/n2);
		default: exit(-1);
    }
}


void randomGet() {


	
	int i;
	while (1) {
		
		settings.isPrint=0;
		for(i=0;i<4;i++)
			con[i]=(float)(rand()%high+low);
		if(s_first()||s_second()) {
			for(i=0;i<4;i++)
				printf("%g ",con[i]);
			settings.isPrint=1;
			break;
		}
		else
			continue;
	
	}

}

int isJQK(char *p) {
	if(*p=='j'||*p=='J')
		return 11;
	else if(*p=='q'||*p=='Q')
		return 12;
	else if(*p=='k'||*p=='K')
		return 13;
	else if(*p=='a'||*p=='A')
		return 1;
	else
		return 0;
}


void printResult_1(int a,int b,int c) {
	
	if( (a==0||a==1)&&(b==2||b==3) )
		printf("(%g%c%g)%c%g%c%g=%d\n",cur[0],op[a],cur[1],op[b],cur[2],op[c],cur[3],N);
	else if ( (b==0||b==1)&&(c==2||c==3) )
		printf("(%g%c%g%c%g)%c%g=%d\n",cur[0],op[a],cur[1],op[b],cur[2],op[c],cur[3],N);
	else
		printf("%g%c%g%c%g%c%g=%d\n",cur[0],op[a],cur[1],op[b],cur[2],op[c],cur[3],N);
}


void printResult_2(int a,int b,int c) {
	
	printf("(%g%c%g)%c(%g%c%g)=%d\n",cur[0],op[a],cur[1],op[c],cur[2],op[b],cur[3],N);
}



//ģ��ƽ�������֮����

int s_first() {

	int result = 0;

	int a,b,c;
	int j,k;

	int sort[4][4]={
			{1,2,3,4},
			{2,3,4,1},
			{2,3,1,4},
			{3,4,2,1},
		};

	for(j=0;j<4;j++) {

		for(k=0;k<4;k++) 
			cur[k]=con[sort[j][k]-1];

		for(a=0;a<4;a++)  {
			for(b=0;b<4;b++) {
				for(c=0;c<4;c++) {

				initArrFromCur();

				arr[1]=calc(arr[0],arr[1],op[a]);
				arr[2]=calc(arr[1],arr[2],op[b]);
				arr[3]=calc(arr[2],arr[3],op[c]);
				if(fabs(arr[3]-N)<=0.1) {
					result=1;
					if(settings.isPrint)
						printResult_1(a,b,c);
					else
						return result;
				}

				}
			}
		}
	}

	initAllFromCon();
	return result;
}


//ģ��ƽ�������֮˫��

int s_second() {

	int result = 0;

	int a,b,c;
	int j,k;

	int sort[3][4]={
			{1,2,3,4},
			{1,3,2,4},
			{1,4,2,3},
		};

	for(j=0;j<3;j++) {

		for(k=0;k<4;k++) 
			cur[k]=con[sort[j][k]-1];

		for(a=0;a<2;a++)  {
			for(b=0;b<2;b++) {
				for(c=2;c<4;c++) {

				initArrFromCur();

				arr[1]=calc(arr[0],arr[1],op[a]);
				arr[2]=calc(arr[2],arr[3],op[b]);
				arr[3]=calc(arr[1],arr[2],op[c]);
				if(fabs(arr[3]-N)<=0.1) {
					result=1;
					if(settings.isPrint)
						printResult_2(a,b,c);
					else
						return result;
				}

				}
			}
		}
	}

	initAllFromCon();
	return result;
}

int userGetIn() {
	
	system("cls");
	int i;
	int sign=0;
	char input[4][10];
	for(i=0;i<4;i++)
		memset(input[i],0,sizeof(char)*10);
	//���С��,д��һ�� ����ʶ�� JQKA jqka space enter �ĺ���,��ʹ������������
	fflush(stdin); //�����������
	printf("������������,���ÿո����.\n");
	scanf("%10s%10s%10s%10s",input[0],input[1],input[2],input[3]);
	for(i=0;i<4;i++) {
		con[i]=isJQK(input[i])+(float)(atof(input[i]));
		if(con[i]<low||con[i]>high) {
			printf("��%d����������ʧ��!����������������\n",i+1);
			system("pause");
			return -1;
		}
	}


	initAllFromCon();
	if(s_first())
		sign=1;
	if(s_second())
		sign=1;
	if(sign)
		printf("�������!\n");
	else
		printf("��,�㲻����Ŷ\n");
	printf("�Ƿ�������Ҽ���%d��?",N);
	fflush(stdin);

	//δ���
	return 0;
}


//------------------------------------------���Ժ���

int test(void)
{
	
	randomGet();
	
	
	
	initAllFromCon();
	
	//system("pause");
	s_first();
	s_second();

	return 0;
}










