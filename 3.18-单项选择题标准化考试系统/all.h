
//all.h created time 2016-1-3 18:08:44


#include <stdio.h>
#include <time.h>
#include <math.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>


//------------------------------------------


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

struct user {

	char no[15];//�û�ѧ��
	char name[30];//�û���
	char password[30];//�û�����
	

	int exercise;//�û���ϰ����Ŀ
	int exerciseTime;//�û���ϰ����
	int exerciseRight;//�û���ϰ����ȷ��Ŀ

	int exam;//�û���������Ŀ
	int examTime;//�û����Դ���
	int examScore[300];//�û�����ÿ�ο��Է���
	int examRight[300][2];//�û�������ȷ/������Ŀ	

	time_t timeAdd;//�û�ע��ʱ��
	time_t timeOnline;//�û�����ʱ��
	time_t timeLogin;//�û�����¼ʱ��
	time_t timeLogout;//�û����ǳ�ʱ��
	int last;//���һ�η��ʵ�����ϰϵͳ���ǿ���ϵͳ,��ϰΪ1,����Ϊ2
	
	int errorHistory[300];//������ʷ���
	int errorTime[300];//�״�����˼��θ�ͷ
	char error[300][40];//ÿ��һ����,��Ŀ�ļ����ؼ��ֻ��Զ������û��״��
	
	struct user * next;
};


//main.cpp
void main(void);
int move_1(int num,void (*p)(int) );
void menuPrint(int a);
void printLaugh(int x, int y);
void goto_pos(int x, int y);
int fuzzy_search(char str[],char str2[]);

//admin.cpp
int sign_in();
void admin();
void menuPrint_2(int a);
void question_admin();
void auto_paper();
void user_admin();
void change_admin_password();
struct info * find_info_num(struct info * head,int num);
struct info * find_info_score_num(struct info * head,int lev);


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

void delete_info_no(struct info * find);
struct info * find_info_no(struct info * head);
void change_info(struct info * node);
void find_info_next(struct info * node);
struct info * find_info_lever(struct info * head);
struct info * find_info_score(struct info * head);
struct info * find_info_time(struct info * head);


//admin_user.cpp
void admin_user();
void menuPrint_5(int a);

struct user * solo_user();
void input_user(struct user * head);
void write_user(struct user * head);
struct user * read_user();
void free_user(struct user * head);
void print_user(struct user * node);
void print_user_solo(struct user * node);

//find_user.cpp
struct user * find_user(struct user * head);
void menuPrint_6(int a);
struct user * find_user_name_key(struct user * head);
struct user * find_user_no_key(struct user * head);
void delete_user_no(struct user * find);
struct user * find_user_no(struct user * head);
struct user * find_user_name(struct user * head);
void change_user(struct user * node);
void find_user_next(struct user * node);
/*
struct user * find_user_lever(struct user * head);
struct user * find_user_score(struct user * head);
*/
struct user * find_user_time(struct user * head);


//user.cpp
void user();
void user_login(struct user * head,struct user * node);
void menuPrint_7(int a);
void printRectangle(int x, int y);
void exam(struct user * node);
void execrise(struct user * node);
void color(const unsigned short color1);
int isQusetion(struct info * node,char *p);