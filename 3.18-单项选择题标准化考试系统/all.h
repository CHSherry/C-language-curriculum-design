
//all.h created time 2016-1-3 18:08:44


#include <stdio.h>
#include <time.h>
#include <math.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>


//------------------------------------------

//A=0,B=1,C=2,D=3;
#define A 1
#define B 2
#define C 3
#define D 4

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




//main.cpp
void main(void);
int move_1(int num,void (*p)(int) );
void menuPrint(int a);
void printLaugh(int x, int y);
void goto_pos(int x, int y);

//admin.cpp
void admin();
void question_admin();
void auto_paper();
void user_admin();
void situation_analysis();
void menuPrint_2(int a);


