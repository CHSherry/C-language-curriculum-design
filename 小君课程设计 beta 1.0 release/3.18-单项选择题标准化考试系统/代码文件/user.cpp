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
	time_t in,out;
	in=time(NULL);
	system("color 07");
	while (1) {

		system("mode con cols=70 lines=22");
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
	out=time(NULL);
	node->timeOnline+=(out-in);
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

	int key,num,a,b=strlen(node->name);
	int i=0,lever=100,right=0;
	float score=0;
	time_t begin,temp,end;
	char ch[20];

	FILE *fp = NULL;
	char n[40];
	strcpy(n,node->name);
	for(a=0;a<b;a++)
		if(n[a]=='.')
			break;
	if(a==b)
		strcpy(&n[b],".txt");
		
	fp=fopen(n,"a+");
	if(fp==NULL) {
		printf("cannot attach %s\n",n);
		exit (0);
	}

	system("mode con cols=80 lines=300");
	printf("---------����---------\n");
	printf("��������Ŀ����: ");
	fflush(stdin);
	scanf("%d",&num);
	printf("�����뿼������(�����,�θ�,����,ָ��.��Ҫ����ֱ�Ӱ�@+�س�): ");
	fflush(stdin);
	scanf("%20s",ch);

	struct info * head = read_info();
	struct info * p = head->next;

	printf("������֪:�����������,�� 0 ��������ǰ��Ŀ,��Esc�����ʣ��������Ŀ������!\n");
	printf("����������Կ�ʼ!\n");
	
	node->examTime++;//�û����Դ���++
	begin=time(NULL);
	key=getch();
	if(key==0||key==224||key==-32)
		key=getch();
	//��ʼ
	while(i<num)
	{
		if(p==NULL){
			i=-1;
			break;
		}
		if(isQusetion(p,ch))
		{
			temp=time(NULL);
			printf("\n---------��ǰ����:%g ��---����ʱ��:%ld ��------\n",score,temp-begin);
			printf("\n---��%d��:",i+1);
			printf("\n statement:\n\t%s\n\n",p->statement);
			printf(" A:%s\t",p->options[0]);
			printf(" B:%s\n",p->options[1]);
			printf(" C:%s\t",p->options[2]);
			printf(" D:%s\n",p->options[3]);
			fprint_info_solo(fp,p);
			printf("***������: ");
			fprintf(fp,"%s","�ҵĴ���: ");
			fflush(stdin);
			key=getch();
			if(key==0||key==224||key==-32)
				key=getch();
			else if(key>=97&&key<=100){
				printf(" %c ",'A'+key-97);
				fprintf(fp," %c \n",'A'+key-97);
				if((key-97)==p->rightAnswer){
					right++;
					node->examRight[node->examTime-1][0]++;//�û�������ȷ��Ŀ
					score+=(float)(100.0/num);
					printf("����ȷ!\n");
				}else{
					node->errorHistory[errorsNum(node)]=p->no;
					node->examRight[node->examTime-1][1]++;//�û����Դ�����Ŀ
					answerWrong(node,p);
					printf("�𰸴���!\n");
				}
			}else if(key==27)
				break;//����
			else{
				node->errorHistory[errorsNum(node)]=p->no;
				node->examRight[node->examTime-1][1]++;//�û����Դ�����Ŀ
				printf("�𰸴���!\n");
			}
			i++;
			node->exam++;//�û���������Ŀ++
		}
		p=p->next;
	}//while
	if(i==-1)
		printf("��ǰ�����������,�����½�\n");
	else{
		end=time(NULL);
		printf("�������!\n");
		printf("��ķ�����:%g\n",score);
		node->examScore[node->examTime-1]=score;//�û�����ÿ�ο��Է���
		printf("������Ŀ%d��,��ȷ��Ϊ%g%%\n",right,right*100.0/num);
		node->examRight[node->examTime-1][0]=right;//�û�������ȷ��Ŀ
		node->examRight[node->examTime-1][1]=num-right;//�û����Դ�����Ŀ
		printf("�ܼ���ʱ�� %ld minutes %ld seconds",(end-begin)/60,(end-begin)%60);
	}
	printf("\n");
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

int errorsNum(struct user * node) {
	int i,sum=0;
	for(i=0;i<300;i++)
		sum+=node->examRight[i][1];
	return node->exercise-node->exerciseRight+sum;
}

void answerWrong(struct user * node,struct info * temp) {

	int i,j,max;
	for(i=0;i<300;i++)
		if(node->error[i][0]=='\0'){
			max=i+1;
			break;
		}
	for(i=0;i<5;i++)
	{
		if(temp->keyWords[i][0]!='@'&&temp->keyWords[i][0]!='\0') {

			for(j=0;j<max;j++) {
				if(strcmp(node->error[j],temp->answers[i])==0) {
					node->errorTime[j]++;
					break;
				}
			}

			if(j==max) {
				strcpy(node->error[max-1],temp->keyWords[i]);
				node->errorTime[max-1]++;
			}

		}else
			break;
	}//for
}

void execrise(struct user * node) {

	int key;
	int i=0,lever=100,right=0,a=1;
	float score=0;
	char ch[20];

	system("mode con cols=80 lines=300");
	printf("---------��ϰ---------\n");
	printf("��������ϰ����(�����,�θ�,����,ָ��.��Ҫ����ֱ�Ӱ�@+�س�): ");
	fflush(stdin);
	scanf("%20s",ch);

	struct info * head = read_info();
	struct info * p = head->next;

	printf("��ϰ����:�����������,�� 0 ��������ǰ��Ŀ���鿴��ǰ��Ŀ��,��Esc�򷵻����˵�!\n");
	printf("���������ϰ��ʼ!\n");
	
	node->exerciseTime++;//�û���ϰ����++
	key=getch();
	if(key==0||key==224||key==-32)
		key=getch();
	//��ʼ
	while(a)
	{
		if(p==NULL){
			a=-1;
			break;
		}
		if(isQusetion(p,ch))
		{
			printf("\n---��%d��---:",i+1);
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
			else if(key>=97&&key<=100){
				printf(" %c ",'A'+key-97);
				if((key-97)==p->rightAnswer){
					node->exerciseRight++;
					printf("����ȷ!\n");
				}else{
					answerWrong(node,p);
					printf("�𰸴���!\n");
					printf(" %c right,because %s\n",'A'+p->rightAnswer,p->answers[p->rightAnswer]);
					for(i=0;i<4;i++) {
						if(i==p->rightAnswer)
							continue;
						printf(" %c wrong,because %s\n",'A'+i,p->answers[i]);
					}
				}
			}else if(key==27)
				break;//����
			else
				printf("��������\n");
			i++;
			node->exercise++;//�û���������Ŀ++
		}
		p=p->next;
	}//while
	if(a==-1)
		printf("��ǰ�����������,�����½�\n");
	else
		printf("�ܼ���ϰ%d����~,����Ŭ��");
	printf("\n");
	system("pause");
}