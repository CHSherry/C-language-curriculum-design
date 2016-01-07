/*
(1) ����Ա����

    �������ÿ�����������ɡ�4����ѡ�𰸡���׼�𰸵���Ϣ��
	�ɽ���������ӡ�ɾ�����޸ġ���ѯ�����桢����Ȳ�����

*/

//question.cpp created time 2016-1-3 23:45:41

#include "all.h"

void question() {
		
	int a;
	struct info * head = NULL;
	head=read_info();

	while (1) {

		system("mode con cols=57 lines=20");
		system("color 3F");

		a = move_1(6,menuPrint_3);
		switch (a) {
			//1.
			case 1:find_info(head);continue;
			case 2:input_info(head);continue;
			case 3:find_info(head);continue;
			case 4:find_info(head);continue;
			case 5:
				system("cls");
				print_info(head->next);
				system("pause");
				continue;
			case 0:
			default:break;
		}
		break;
	}
	write_info(head);
	free_info(head);  //save
}

/*
 ����������       admin


               1.��������

               2.�������     

               3.ɾ������

               4.�޸�����

               5.�������    

               0.���沢�˳�
*/

void menuPrint_3(int a) {

	system("cls");
	char name[15]={"menu_3.txt"};

	
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

struct info * solo_info() {

    struct info * node = NULL;
    node = (struct info *)malloc(sizeof(struct info));
    memset(node, 0, sizeof(struct info));
    if (node == NULL) {
        printf("�����ڴ�ʧ��!");
        exit(-1);
    }else{
		node->next=NULL;
	}
    return node;
}



void input_info(struct info * head) {

	int i,j;
	char ch;
	struct info * node = NULL;
	struct info * tail = head;
	
	node = solo_info();
	while(tail->next!=NULL)
		tail = tail->next;
	tail->next = node;

	system("mode con cols=30 lines=20");
	system("color 0F");

	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
	printf("       ������Ŀ��Ϣ\n\n");
	printf("     ---------------------\n");
	printf("     | �Ѷ�(1-10): |     |\n");
	printf("     ---------------------\n");
	printf("\n");
	printf("     ---------------------\n");
	printf("     | ��ֵ (1-5): |     |\n");
	printf("     ---------------------\n");
	printf("\n");
	printf("     ---------------------\n");
	printf("     | ��ȷѡ��: |       |\n");
	printf("     |   A---D   |       |\n");
	printf("     ---------------------\n");
	printf("\n");
	
	node->no = tail->no+1;

	fflush(stdin);
	goto_pos(22,7);
	scanf("%2d",&node->lever);

	fflush(stdin);
	goto_pos(22,11);
	scanf("%2d",&node->score);

	fflush(stdin);
	goto_pos(22,15);
	ch=getchar();
	node->rightAnswer=ch-'A';

	system("cls");
	system("mode con cols=50 lines=40");
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
	printf("                  ������Ŀ��Ϣ\n\n");
	printf("              ---------------------\n\n");
	printf("��������Ŀ����:\n");
	fflush(stdin);
	for(j=0;j<1000;j++) {
		ch=getchar();
		if(ch!='\n')
			node->statement[j]=ch;
		else
			break;
	}

	for(i=0;i<4;i++) {
		printf("������%cѡ������",'A'+i);
		fflush(stdin);
		for(j=0;j<100;j++) {
			ch=getchar();
			if(ch!='\n')
				node->options[i][j]=ch;
			else
				break;
		}
	}

	printf("������5���ؼ���,���ÿո����,���� @+�س� �����ؼ��ֵ�����.\n");
	fflush(stdin);
	for(i=0;i<5;i++) {
		for(j=0;j<40;j++) {
			ch=getchar();
			if(ch!='\n'&&ch!=' ')
				node->keyWords[i][j]=ch;
			else
				break;
		}
		if(node->keyWords[i][0]=='@')
			break;
	}

	printf("������%cѡ�����ȷԭ��:\n",'A'+node->rightAnswer);
	fflush(stdin);
	scanf("%300s",node->answers[node->rightAnswer]);

	for(i=0;i<4;i++) {
		if(i==node->rightAnswer)
			continue;
		printf("������%cѡ��Ĵ���ԭ��:\n",'A'+i);
		fflush(stdin);
		scanf("%300s",node->answers[i]);
	}

	node->timeAdd=node->timeModify=time(NULL);
	node->next=NULL;

	printf("�������ɹ�!���ڷ������˵�...");
	Sleep(1300);

}

void write_info(struct info * head) {

	FILE * fp;
	if ((fp = fopen("info.txt", "w")) == NULL) {
		printf("���ļ�ʧ��");
		exit(-2);
	}
    printf("д���ļ���");
    while(head->next!=NULL)
    {
        printf(".");
		head = head->next;
        if(fwrite(head, sizeof(struct info), 1, fp)!=1) {
            printf("д���ļ�ʧ��");
            exit(-2);
        }
		
    }
    //printf("д�����\n");
	fclose(fp);
}

struct info * read_info() {

	int i=0;
	FILE * fp;
	struct info * head = NULL;
	struct info * node = NULL;
	struct info * tail = NULL;

	//head=solo_info();

	if ((fp = fopen("info.txt", "r")) == NULL) {
		system("cls");
		printf("��ȡ�ļ�ʧ��");
		exit(-3);
	}
	tail=head=solo_info();
	while(!feof(fp)){

		node=solo_info();
		if(fread(node, sizeof(struct info),1 , fp)==1){
			tail->next=node;
			tail=node;
		}
	}

	//!@#$%^&*()_)(*&^%$#@!@#$%^&*())(*&^%$#@!#$%^&*()(*&^%$#@

	fclose(fp);
	return head;
}

void free_info(struct info * head) {
    
    struct info * p = NULL;
    while (head!=NULL) {
        p = head->next;
        free(head);
        head = p;
    }
    return ;
}

void print_info(struct info * node) {

	int i;
	system("mode con cols=80 lines=1000");
	
	printf("���ڶ�ȡ����...\n");
	if (node==NULL) {
		printf("��ǰ���Ϊ��!");
	}else{
		struct info * p = node;
		while (p!=NULL) {
			printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			printf(" no:%3d ",p->no);
			printf(" lever:%2d ",p->lever);
			printf(" score:%d ",p->score);
			printf("\n statement:\n\t%s\n\n",p->statement);

			printf(" keyWords:");
			for(i=0;i<5;i++)
				if(p->keyWords[i][0]!='@')
					printf("%s ",p->answers[i]);
				else
					break;
			printf("\n");

			printf(" A:%s\t",p->options[0]);
			printf(" B:%s\t",p->options[1]);
			printf(" C:%s\t",p->options[2]);
			printf(" D:%s\t\n",p->options[3]);
			//printf("rightAnswer:%c",'A'+p->rightAnswer);
			printf(" %c right,because %s\n",'A'+p->rightAnswer,p->answers[p->rightAnswer]);
			for(i=0;i<4;i++) {
				if(i==p->rightAnswer)
					continue;
				printf(" %c wrong,because %s\n",'A'+i,p->answers[i]);
			}
			printf(" timeAdd:   ");
			print_time(p->timeAdd);
			printf(" timeModify:");
			print_time(p->timeModify);

			p=p->next;
		}
	}
}


void print_info_solo(struct info * node) {

	int i;

	
	if (node==NULL) {
		printf("��ǰ���Ϊ��!");
	}else{
		struct info * p = node;
		
			printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			printf(" no:%3d ",p->no);
			printf(" lever:%2d ",p->lever);
			printf(" score:%d ",p->score);
			printf("\n statement:\n\t%s\n\n",p->statement);

			printf(" keyWords:");
			for(i=0;i<5;i++)
				if(p->keyWords[i][0]!='@')
					printf("%s ",p->answers[i]);
				else
					break;
			printf("\n");

			printf(" A:%s\t",p->options[0]);
			printf(" B:%s\t",p->options[1]);
			printf(" C:%s\t",p->options[2]);
			printf(" D:%s\t\n",p->options[3]);
			//printf("rightAnswer:%c",'A'+p->rightAnswer);
			printf(" %c right,because %s\n",'A'+p->rightAnswer,p->answers[p->rightAnswer]);
			for(i=0;i<4;i++) {
				if(i==p->rightAnswer)
					continue;
				printf(" %c wrong,because %s\n",'A'+i,p->answers[i]);
			}
			printf(" timeAdd:   ");
			print_time(p->timeAdd);
			printf(" timeModify:");
			print_time(p->timeModify);

			
		
	}
}