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



void menuPrint();
int move();

//------------------------------------------���������˵�����


void main(void) {

	system("mode con cols=67 lines=29");
	system("color 0A");
	srand((unsigned)time(NULL));
	
}

void menuPrint(int i) {

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

	
	char arr[1000];//����1000��Ϊ����~2333
	memset(arr,0,sizeof(char)*1000);
	FILE *fp;
	fp=fopen(name[i],"r");

	if(fp==NULL) {
		printf("cannot open %s\n",name[i]);
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
		
	}

	return i;
}
