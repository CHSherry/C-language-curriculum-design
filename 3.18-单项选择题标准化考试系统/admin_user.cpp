/*
(1) ����Ա����

	�û��������û���Ϣ������ӡ�ɾ�����޸ġ���ѯ�����桢����Ȳ�����

	(�û������������ָ���û���ͳ�������Ծ���ܴ������Լ�ÿ�����õ��ܷ֡�)
*/

//admin_user.cpp created time 2016-1-8 10:06:12

#include "all.h"

void admin_user() {
		
	int a;
	struct user * head = NULL;
	head=read_user();

	while (1) {

		system("mode con cols=57 lines=20");
		system("color 3F");

		a = move_1(6,menuPrint_5);
		switch (a) {
			//1.
			//case 1:find_user(head);continue;
			case 2:input_user(head);continue;
			//case 3:find_user(head);continue;
			//case 4:find_user(head);continue;
			case 5:
				system("cls");
				print_user(head->next);
				system("pause");
				continue;
			case 0:
			default:break;
		}
		break;
	}
	write_user(head);
	free_user(head);  //save
}

/*

            ѧ����Ϣ�������       admin


               1.����ѧ��

               2.���ѧ��     

               3.�Ƴ�ѧ����Ϣ(���Ȳ���)

               4.�޸�ѧ����Ϣ(���Ȳ���)

               5.���ѧ����Ϣ    

               0.���沢�˳�
                       
*/

void menuPrint_5(int a) {

	system("cls");
	char name[15]={"menu_5.txt"};

	
	char arr[1500];//����1000��Ϊ����~2333
	memset(arr,0,sizeof(char)*1500);
	FILE *fp;
	fp=fopen(name,"r");

	if(fp==NULL) {
		printf("cannot open %s\n",name);
		exit (0);
	}

	int h=0;
	while(!feof(fp)) {
		fread(arr+h,sizeof(char),1,fp);
		h++;
	}
	printf("%s",arr);

	fclose(fp);

	switch (a) {
		//��ʾ���
		case 1:printLaugh(40,6);break;
		case 2:printLaugh(40,8);break;
		case 3:printLaugh(40,10);break;
		case 4:printLaugh(40,12);break;
		case 5:printLaugh(40,14);break;
		case 0:printLaugh(40,16);break;
		default:break;
	}
	
}

//����ͷ����β�巨

struct user * solo_user() {

    struct user * node = NULL;
    node = (struct user *)malloc(sizeof(struct user));
    memset(node, 0, sizeof(struct user));
    if (node == NULL) {
        printf("�����ڴ�ʧ��!");
        exit(-1);
    }else{
		node->next=NULL;
	}
    return node;
}



void input_user(struct user * head) {

	int i;
	struct user * node = NULL;
	struct user * tail = head;
	
	node = solo_user();
	while(tail->next!=NULL)
		tail = tail->next;
	tail->next = node;

	system("mode con cols=37 lines=27");
	system("color 3A");

	//char name[10]={"admin"},password[10]={"admin"};

	for(i=0;i<3;i++) {
		system("cls");
		printf("\n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
		printf("           ѧ��ע��\n\n");
		printf("     --------------------------\n");
		printf("     | ѧ��: |                |\n");
		printf("     --------------------------\n");
		printf("\n");
		printf("     --------------------------\n");
		printf("     | ����: |                |\n");
		printf("     --------------------------\n");
		printf("\n");
		printf("     --------------------------\n");
		printf("       | ѧ�ű�����10λ����|\n");
		printf("       | ����֮�䲻���пո�|\n");
		printf("       | ���س����������..|\n");
		printf("     --------------------------\n");
		printf("\n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		fflush(stdin);
		goto_pos(16,6);
		scanf("%20s",node->no);
		fflush(stdin);
		goto_pos(16,10);
		scanf("%30s",node->password);
		
		if(strlen(node->no)==11&&strlen(node->password)>=6) {
			goto_pos(11,21);
			printf("ע��ɹ�!");
			{
				//��ʼ��ʼ��ѧ��������Ϣ



			}
			Sleep(1800);
			return ;
		}else{
			goto_pos(13,21);
			printf("ע��ʧ��\n      ������ע�� (ʣ�����:%d)",2-i);
			goto_pos(9,23);
			if(strlen(node->no)!=11)
				printf("ѧ�Ų���11λ,��Ч!");
			else
				printf("������ڼ�!");
			Sleep(2100);
		}
	}
	free(node);
}

void write_user(struct user * head) {

	FILE * fp;
	if ((fp = fopen("user.txt", "w")) == NULL) {
		printf("���ļ�ʧ��");
		exit(-2);
	}
    printf("д���ļ���");
    while(head->next!=NULL)
    {
        printf(".");
		head = head->next;
        if(fwrite(head, sizeof(struct user), 1, fp)!=1) {
            printf("д���ļ�ʧ��");
            exit(-2);
        }
		
    }
    //printf("д�����\n");
	fclose(fp);
}

struct user * read_user() {

	int i=0;
	FILE * fp;
	struct user * head = NULL;
	struct user * node = NULL;
	struct user * tail = NULL;

	//head=solo_user();

	if ((fp = fopen("user.txt", "r")) == NULL) {
		system("cls");
		printf("��ȡ�ļ�ʧ��");
		exit(-3);
	}
	tail=head=solo_user();
	while(!feof(fp)){

		node=solo_user();
		if(fread(node, sizeof(struct user),1 , fp)==1){
			tail->next=node;
			tail=node;
		}
	}

	//!@#$%^&*()_)(*&^%$#@!@#$%^&*())(*&^%$#@!#$%^&*()(*&^%$#@

	fclose(fp);
	return head;
}

void free_user(struct user * head) {
    
    struct user * p = NULL;
    while (head!=NULL) {
        p = head->next;
        free(head);
        head = p;
    }
    return ;
}

void print_user(struct user * node) {

	system("mode con cols=80 lines=1000");
	
	printf("���ڶ�ȡ����...\n");
	if (node==NULL) {
		printf("û���κ�ѧ����Ϣ!");
	}else{
		printf("\n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		struct user * p = node;
		while (p!=NULL) {
			print_user_solo(p);
			p=p->next;
		}
	}
}


void print_user_solo(struct user * node) {


	if (node==NULL) {
		printf("��ǰ���Ϊ��!");
	}else{
		struct user * p = node;
		{	//������Ϣ		
			printf(" ѧ��:%s ",p->no);
			printf(" password:%s ",p->password);
			printf("\n");
		}
		{	//��ϰ��Ϣ
			printf("�û���ϰ����:%d\t",p->exerciseTime);
			printf("�ܼ���ϰ��Ŀ����:%d\t",p->exercise);
			printf("��ȷ����:%d\t",p->exerciseRight);
			printf("��ȷ��:%.1f%%\t",((p->exerciseRight+0.0)/p->exercise)*100);
		}
		{	//������Ϣ
			printf("�û����Դ���:%d\t",p->examTime);
			printf("�ܼƿ�����Ŀ����:%d\t",p->exam);
		
		int right,i;
		for(i=0,right=0;(p->examRight[i][0]+p->examRight[i][1])!=0;i++){
			right+=p->examRight[i][0];
		}
			printf("��ȷ����:%d\t",right);
			printf("��ȷ��:%.1f%%\t",((right+0.0)/p->exam)*100);

			printf("�û����ο��Է���:\n");
		int j
		for(i=0;
			int examScore[300];//�û�����ÿ�ο��Է���
	

			time_t timeAdd;//�û�ע��ʱ��
			time_t timeOnline;//�û�����ʱ��
			time_t timeLogin;//�û�����¼ʱ��
			time_t timeLogout;//�û����ǳ�ʱ��
			int last;//���һ�η��ʵ�����ϰϵͳ���ǿ���ϵͳ,��ϰΪ1,����Ϊ2
			
			int errorHistory[300];//������ʷ���
			int errorTime[300];//�״�����˼��θ�ͷ
			char error[300][40];//ÿ��һ����,��Ŀ�ļ����ؼ��ֻ��Զ������û��״��
			
	}
}









