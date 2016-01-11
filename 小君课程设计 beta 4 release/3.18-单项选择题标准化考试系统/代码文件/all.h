
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
	float examScore[300];//�û�����ÿ�ο��Է���
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
void main(void);//�������
int move_1(int num,void (*p)(int) );//����ɵ�move_1���� ����˵�ѡ��ĸ����Ѿ���Ӧ��void menuPrint_x(int a); ���ɴ�ӡ���ֲ˵�
void menuPrint(int a);//�˵���ʾ����
void printLaugh(int x, int y);//��ӡ(*^_^*)���ѹ���ƶ���Ц��������
void goto_pos(int x, int y);//����ƶ�����
int fuzzy_search(char str[],char str2[]);//ģ�����Һ���,char str[]ΪԴ�ַ���,char str2[]Ϊ���ҵĹؼ���


//admin.cpp
int sign_in();//����Ա��¼����
void admin();//����Ա���ƽ��� 1.�������(��ɾ�Ĳ�) 2.����� 3.�û��˺ż������������ 4.�޸Ĺ���Ա���� 0.ע����¼
void menuPrint_2(int a);//��ʾ�˵�~~����Ա��¼����
void question_admin();//question() -> question.cpp
void auto_paper();//�Զ�����
void user_admin();//���뺯��admin_user()
void change_admin_password();//�޸Ĺ���Ա����
struct info * find_info_num(struct info * head,int num);//������Ų�������
struct info * find_info_score_num(struct info * head,int lev);//���ݷ����������� ����Ƿ���


//question.cpp
void question();//����������
void menuPrint_3(int a);//��ʾ�˵�~~����������
struct info * solo_info();//����malloc������Ŀ
void input_info(struct info * head);//�½�һ����Ŀ����ʼ����Ŀ��Ϣ��ͷ����β�巨
void write_info(struct info * head);//�����д�뵽�ļ�info.txt��
struct info * read_info();//�ӱ����ļ�info.txt�������
void free_info(struct info * head);//�ͷ�����
void print_info(struct info * node);//���������Ŀ����Ϣ
void print_info_solo(struct info * node);//���һ����Ŀȫ����Ϣ����Ļ
void fprint_info_solo(FILE *fp,struct info * node);//���һ����Ŀȫ����Ϣ���ļ�fp


//time.cpp
void print_time(long lt);//�����ǰʱ�䵽��Ļ
void sprint_time(char * buf);//�����ǰʱ�䵽�ַ�����


//find_info.cpp
struct info * find_info(struct info * head);//�����������
void menuPrint_4(int a);//��ʾ�˵�~~�����������
struct info * find_info_key(struct info * head);//���չؼ��ֲ�����Ŀ,������Ŀ����һ��ָ��
void delete_info_no(struct info * find);//ɾ����Ŀ��Ϣ
struct info * find_info_no(struct info * head);//������Ŀ��Ų�����Ŀ,������Ŀ����һ��ָ��
void change_info(struct info * node);//�޸���Ŀ��ϸ��Ϣ
void find_info_next(struct info * node);//ѡ���޸���Ŀ��Ϣ��ɾ����Ŀ,����������Ŀ����һ���ڵ�
struct info * find_info_lever(struct info * head);//����Ŀ�ѶȲ���
struct info * find_info_score(struct info * head);//����Ŀ��ֵ����
struct info * find_info_time(struct info * head);//��������/�޸���Ŀ


//admin_user.cpp
void admin_user();//ѧ����Ϣ�������
void menuPrint_5(int a);//��ʾ�˵�~~ѧ����Ϣ�������
struct user * solo_user();//�����ڴ�
void input_user(struct user * head);//ѧ��ע�᲻~��ͷ����β�巨
void write_user(struct user * head);//��ѧ����Ϣд���ļ���
struct user * read_user();//���ļ��ж���ѧ����Ϣ
void free_user(struct user * head);//�ͷ��ڴ�
void print_user(struct user * node);//�������ѧ����Ϣ
void print_user_solo(struct user * node);//�������ѧ����Ϣ


//find_user.cpp
struct user * find_user(struct user * head);//����ѧ������
void menuPrint_6(int a);//��ʾ�˵�~~����ѧ������
struct user * find_user_name_key(struct user * head);//��ѧ������(ģ��)����
struct user * find_user_no_key(struct user * head);//��ѧ��ѧ��(ģ��)����
void delete_user_no(struct user * find);//����ѧ��ɾ���û���Ϣ
struct user * find_user_no(struct user * head);//����ѧ�Ų����û�
struct user * find_user_name(struct user * head);//�������������û�
void change_user(struct user * node);//�޸��û�ѧ�ź�����
void find_user_next(struct user * node);//�޸��û���Ϣ��ɾ���û�
struct user * find_user_time(struct user * head);//�����¼���û�


//user.cpp
void user();//ѧ����¼����
void user_login(struct user * head,struct user * node);//�û���¼��
void menuPrint_7(int a);//��ʾ�˵�~~����ѡ�����׼������ϵͳ
void printRectangle(int x, int y);//��ָ��λ�������ɫ����
void color(const unsigned short color1);//�ı���ɫ---
void exam(struct user * node);//����
int isQusetion(struct info * node,char *p);//��Ŀ�Ƿ�����Ҫ��
int errorsNum(struct user * node);//�����û����˶�����
void answerWrong(struct user * node,struct info * temp);//�û��������֮��...
void execrise(struct user * node);//��ϰ
