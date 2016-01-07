
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

struct info {

	int no;//��Ŀ���
	int lever;//��Ŀ�Ѷ�1-10
	int score;//��Ŀ����1-5
	int rightAnswer;//��ȷѡ��
	time_t timeAdd;//��Ŀ��ӵ�ʱ��
	time_t timeModify;//����޸�ʱ��
	
	char keyWords[5][40];//ÿ������5���ؼ���
	char options[4][100];//��Ŀ���ĸ�ѡ��
	char answers[4][300];//ÿ��ѡ��Ĵ���ԭ��
	char statement[1000];//��Ŀ����
	
	struct info * next;
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


//question.cpp
void question();
void menuPrint_3(int a);
struct info * solo_info();
void input_info(struct info * head);
struct info * find_info_tail(struct info * head);
void add_info(struct info * node);
void write_info(struct info * head);
struct info * read_info(void);
void free_info(struct info * head);
void print_info(struct info * head);
void print_info_solo(struct info * node);


//time.cpp
void print_time(long lt);


//find_info.cpp
struct info * find_info(struct info * head);
void menuPrint_4(int a);
struct info * find_info_key(struct info * head);
int fuzzy_search(char str[] , char str2[]);
void delete_info_no(struct info * find);
struct info * find_info_no(struct info * head);
void change_info(struct info * node);
void find_info_next(struct info * node);
struct info * find_info_lever(struct info * head);