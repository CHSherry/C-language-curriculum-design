/*
3.18-xxx ����ѡ�����׼������ϵͳ���Ѷ�ϵ����5����
������������
���һ������ѡ����Ŀ���ϵͳ����ʵ���Զ�����ܡ�
������������
��1������Ա����
    �������ÿ�����������ɡ�4����ѡ�𰸡���׼�𰸵���Ϣ���ɽ���������ӡ�ɾ�����޸ġ���ѯ�����桢����Ȳ�����
    ����ܣ�ָ����Ŀ������Ŀ�ܷ֣������Ծ����Ծ�������ļ��������������һ���ļ���
	�û��������û���Ϣ������ӡ�ɾ�����޸ġ���ѯ�����桢����Ȳ�����
	�û������������ָ���û���ͳ�������Ծ���ܴ������Լ�ÿ�����õ��ܷ֡�
��2���û�����
	��ϰ���ܣ��û�ָ����Ŀ�������ѡ�⡣���û��Ĵ����׼�𰸽��жԱȣ������ո����ɼ����Դ�����Ŀ��Ҫ�ܸ�����ȷ�𰸡�
	���Թ��ܣ��û�ָ����Ŀ������������ܷ�100�ֵ��Ծ�ϵͳ�ɸ����û������׼�𰸵ĶԱ�ʵ���о��������ɼ��������û������Ծ��û��Ĵ𰸡��û������ܷ֣�����������ļ����档���л������������
��3�������ʾ
    ����Ա���û��ֱ�ͨ�������¼��������Ŀά���ʹ���������û������Ĵ����ļ���Ӧ���û���+ϵͳʱ��.txt����ʽ�洢���Ա��ڽ��й���
*/


#include <stdio.h>
#include <time.h>
#include <math.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>


enum {A,B,C,D} option; //A=0,B=1,C=2,D=3;

struct information {
    
    int no;//��Ŀ���
    int lever;//��Ŀ�Ѷ�
	int score;//��Ŀ����
    char timeAdd[20];//��Ŀ��ӵ�ʱ��
    char timeModify[20];//����޸�ʱ��
    char statement[1000];//��Ŀ����
    char keyWords[5][40];//ÿ������5���ؼ���

	char options[4][100];//��Ŀ���ĸ�ѡ��
    int rightAnswer;//��ȷѡ��
    char answers[4][300];//ÿ��ѡ��Ĵ���ԭ��
	struct information * next;
};



void menuPrint(int a);
int move();

//------------------------------------------���������˵�����


void main(void) {

	system("mode con cols=57 lines=30");
	system("color 0A");

	srand((unsigned)time(NULL));
	int a=1;
	
	while (1) {

		menuPrint(a);
		a=move();
		switch (a) {
			//1.
			case 1:;continue;
			case 2:;continue;
			case 3:;continue;	
			case 6:;continue;
			default:break;
		}
	}
}

void menuPrint(int a) {

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

	
	char arr[1500];//����1000��Ϊ����~2333
	memset(arr,0,sizeof(char)*1500);
	FILE *fp;
	fp=fopen(name[a],"r");

	if(fp==NULL) {
		printf("cannot open %s\n",name[a]);
		exit (0);
	}

	int h=0;
	while(!feof(fp)) {
		fread(arr+h,sizeof(char),1,fp);
		h++;
	}
	printf("%s",arr);

	fclose(fp);
}

int move() {
	
	int i = 1;
	char key = 0;

	while (1) {

		fflush(stdin); //����������� 
		key = getch();
		if(key==0||key==-32)
			key = getch();
		if (key==72)
			i--;//...
		else if (key==80)
			i++;
		else if (key>=49&&key<=54)
			return key-48;
		else if (key==48||key==27) 
			exit(0);
		else if (key==13)
			if(i)
				return i;
			else
				exit(0);
		else
			key=0;
		
		if(i<0)
			i=i+7;
		if(i>6)
			i=i-7;
		
		menuPrint(i);
	}

	return i;
}
