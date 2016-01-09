//user.cpp created time 2016-1-9 17:57:32

#include "all.h"

void user() {

	system("mode con cols=34 lines=22");
	system("color 3A");

	int i;
	struct user * head = NULL;
	head=read_user();
	struct user * temp = NULL;

	char get_1[10],get_2[10];
	for(i=0;i<3;i++) {
		system("cls");
		printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
		printf("           ѧ����¼����\n\n");
		printf("     -------------------------\n");
		printf("     | ѧ��: |               |\n");
		printf("     -------------------------\n");
		printf("\n");
		printf("     -------------------------\n");
		printf("     | ����: |               |\n");
		printf("     -------------------------\n");
		printf("\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		fflush(stdin);
		goto_pos(16,7);
		scanf("%20s",get_1);
		fflush(stdin);
		goto_pos(16,11);
		scanf("%20s",get_2);

		temp=head;
		while(temp!=NULL){
			if(strcmp(temp->no,get_1)==0&&strcmp(temp->password,get_2)==0){
				goto_pos(11,17);
				printf("��¼�ɹ�!");
				Sleep(800);
				user_login(head,temp);
				//->��¼�ɹ������user_login����
				return ;
			}else
				temp=temp->next;
		}
		goto_pos(11,17);
		printf("�������\n    ���������� (ʣ�����:%d)",2-i);
		Sleep(1300);
	}
	exit(-1);
}

void user_login(struct user * head,struct user * node) {
		
	int a;
	system("color 07");
	while (1) {

		system("mode con cols=70 lines=30");
		a = move_1(5,menuPrint_7);

		switch (a) {
			case 1:exam(node);continue;
			case 2:execrise(node);continue;
			case 3:
				system("cls");
				print_user_solo(node);
				system("pause");
				continue;
			case 4:
				system("cls");
				print_user_solo(node);
				change_user(node);
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

 *******************************************************

               ����ѡ�����׼������ϵͳ      
 
       ��ӭ��,
                                             -------------------
             -------------------          | 1 ��ʼ����  |
             | 2 ��ʼ��ϰ  |          -------------------
             -------------------
                              --------------------
                              | 3  �鿴��Ϣ  |
                              --------------------
                --------------------
                | 4  �޸�����  |
                --------------------          --------------------
                                                  | 0  �˳���¼  |
                                                  --------------------
  2016-1-9 coded by Reigning...
*/

void menuPrint_7(int a) {

	system("cls");
	
	char name[15]={"menu_7.txt"};

	
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
		case 1:printRectangle(42,6);break;
		case 2:printRectangle(13,7);break;
		case 3:printRectangle(30,10);break;
		case 4:printRectangle(16,13);break;
		case 0:printRectangle(50,15);break;
		default:break;
	}
	
}

void printRectangle(int x, int y) {

	color(14);
	goto_pos(x,y);
	printf("---------------");
	goto_pos(x,y+1);
	printf("|");
	goto_pos(x+14,y+1);
	printf("|");
	goto_pos(x,y+2);
	printf("---------------");
	goto_pos(x+2,y+1);
	color(7);

}

/*��ɫ��Ӧֵ�� 
����0=��ɫ                8=��ɫ����
  �� 1=��ɫ                9=����ɫ                ����                        
����2=��ɫ                10=����ɫ       0xa        ����
����3=����ɫ          11=��ǳ��ɫ        0xb��
����4=��ɫ                12=����ɫ        0xc����
����5=��ɫ                13=����ɫ        0xd        ����
����6=��ɫ                14=����ɫ        0xe        ����
����7=��ɫ                15=����ɫ        0xf 
����Ҳ���԰���Щֵ���óɳ�����
*/
void color(const unsigned short color1)
{        
	/*���޸ı�0-15����ɫ;�����0-15��ôʵ��������ɫ   ��Ϊ�������15����ĸı�����ı�����ɫ��*/
    if(color1>=0&&color1<=15)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color1);
    /*�������0-15�ķ�Χ��ɫ����ô��ΪĬ�ϵ���ɫ��ɫ��*/
    else
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}


void exam(struct user * node) {

	int i=0,lever=100;
	float num,right=0,score=0;
	time_t begin,temp,end;
	char ch[20];
	int key;
	system("mode con cols=80 lines=300");

	printf("---------����---------\n");
	printf("��������Ŀ����: ");
	fflush(stdin);
	scanf("%f",&num);
	printf("�����뿼������(�����,�θ�,����,ָ��.��Ҫ����ֱ�Ӱ�@+�س�): ");
	fflush(stdin);
	scanf("%20s",ch);

	struct info * head = read_info();
	struct info * p = head->next;

	printf("������֪:�����������,�� 0 ��������ǰ��Ŀ,��Esc�����ʣ��������Ŀ������!\n");
	printf("����������Կ�ʼ!\n");
	begin=time(NULL);
	key=getch();
	if(key==0||key==224||key==-32)
		key=getch();
	//��ʼ
	while(i<num&&p!=NULL)
	{
		if(isQusetion(p,ch))
		{
			temp=time(NULL);
			printf("\n---------��ǰ����:%g ��---����ʱ��:%ld ��------\n",score,temp-begin);
			printf("\n---��%d��:",i);
			printf("\n statement:\n\t%s\n\n",p->statement);
			printf(" A:%s\t",p->options[0]);
			printf(" B:%s\n",p->options[1]);
			printf(" C:%s\t",p->options[2]);
			printf(" D:%s\n",p->options[3]);
			printf("***������: ");
			fflush(stdin);
			key=getch();
			if(key==0||key==224||key==-32)
				key=getch();
			else if(key>=97&&key<=100)
				if((key-97)==p->rightAnswer){
					right++;
					printf("����ȷ!\n");
				}else
					printf("�𰸴���!\n");
			else if(key==27)
				return ;//����
			else
				printf("�𰸴���!\n");
			i++;
		}
		p=p->next;
	}//while
	if(i!=num)
		printf("��ǰ�����������,�����½�\n");
	else{
		end=time(NULL);
		printf("�������!\n");
		printf("������Ŀ%g��,��ȷ��Ϊ%g%%\n",right,right*100.0/num);
		printf("�ܼ���ʱ�� %ld minutes %ld seconds",(end-begin)/60,(end-begin)%60);
	}
	system("pause");
}

int isQusetion(struct info * node,char *p) {

	int i;
	if(strcmp(p,"����")==0)
		if(node->lever>=5)
			return 0;
	else if(strcmp(p,"�θ�")==0)
		if(node->lever<=5)
			return 0;
	else if(*p!='@')
	{
		for(i=0;i<4;i++)
			if(fuzzy_search(node->keyWords[i],p)==1)
				return 1;
		return 0;
	}
	else
		if(rand()%2==0)
			return 0;
	return 1;
}

void execrise(struct user * node) {

	int i=0,lever=100;
	float num,right=0,score=0;
	time_t begin,temp,end;
	char ch[20];
	int key;
	system("mode con cols=80 lines=300");

	printf("---------����---------\n");
	printf("��������Ŀ����: ");
	fflush(stdin);
	scanf("%f",&num);
	printf("�����뿼������(�����,�θ�,����,ָ��.��Ҫ����ֱ�Ӱ�@+�س�): ");
	fflush(stdin);
	scanf("%20s",ch);

	struct info * head = read_info();
	struct info * p = head->next;

	printf("������֪:�����������,�� 0 ��������ǰ��Ŀ,��Esc�����ʣ��������Ŀ������!\n");
	printf("����������Կ�ʼ!\n");
	begin=time(NULL);
	key=getch();
	if(key==0||key==224||key==-32)
		key=getch();
	//��ʼ
	while(i<num&&p!=NULL)
	{
		if(isQusetion(p,ch))
		{
			temp=time(NULL);
			printf("\n---------��ǰ����:%g ��---����ʱ��:%ld ��------\n",score,temp-begin);
			printf("\n---��%d��:",i);
			printf("\n statement:\n\t%s\n\n",p->statement);
			printf(" A:%s\t",p->options[0]);
			printf(" B:%s\n",p->options[1]);
			printf(" C:%s\t",p->options[2]);
			printf(" D:%s\n",p->options[3]);
			printf("***������: ");
			fflush(stdin);
			key=getch();
			if(key==0||key==224||key==-32)
				key=getch();
			else if(key>=97&&key<=100)
				if((key-97)==p->rightAnswer){
					right++;
					printf("����ȷ!\n");
				}else
					printf("�𰸴���!\n");
			else if(key==27)
				return ;//����
			else
				printf("�𰸴���!\n");
			i++;
		}
		p=p->next;
	}//while
	if(i!=num)
		printf("��ǰ�����������,�����½�\n");
	else{
		end=time(NULL);
		printf("�������!\n");
		printf("������Ŀ%g��,��ȷ��Ϊ%g%%\n",right,right*100.0/num);
		printf("�ܼ���ʱ�� %ld minutes %ld seconds",(end-begin)/60,(end-begin)%60);
	}
	system("pause");
}