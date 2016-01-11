//find_info.cpp created time 2016-1-6 14:33:22

#include "all.h"

struct info * find_info(struct info * head) {

	int a;
	struct info * find = NULL;
		
	while (1) {

		system("mode con cols=57 lines=20");
		system("color 47");

		a = move_1(3,menuPrint_4);
		system("cls");
		switch (a) {
			//1.
			case 1:find=find_info_key(head);break;
			case 2:find=find_info_no(head);break;
			case 3:find=find_info_lever(head);break;
			case 4:find=find_info_score(head);break;
			case 5:find=find_info_time(head);break;
			case 0:
			default:break;
		}
		if(find!=NULL)
			find_info_next(find);
		break;
	}
	return find;
}


/*
               �����������       admin


               1.���ؼ��ֲ���

               2.����Ų���     

               3.���ѶȲ���

               4.����ֵ����

               5.������/�޸�   

               0.������һ��
*/

void menuPrint_4(int a) {

	system("cls");
	char name[15]={"menu_4.txt"};

	
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

struct info * find_info_key(struct info * head) {

	int count=0,sign=0;
	struct info * node = head;
	struct info * find = NULL;
	char key[20];
	memset(key,0,sizeof(char)*20);

	system("cls");
	printf(" ������ؼ���:\n");
	fflush(stdin);
	scanf("%19s",key);
	printf(" ���ڲ���...\n");
	system("mode con cols=80 lines=1000");
	while(node->next!=NULL){
		if(fuzzy_search(node->next->statement,key)){
			print_info_solo(node->next);
			find=node;
			sign++;
		}
		count++;
		node=node->next;
	}
	printf("\n �������!�ۼƲ���%d��,���ҽ��%d��\n",count,sign);
	if(sign==1)
		return find;
	else if(sign>1)
		return find_info_no(head);
	else{
		printf(" û���ҵ����,���ڷ�����һ���˵�...");
		Sleep(3000);
		return NULL;
	}
	return NULL;
}


void delete_info_no(struct info * find) {

	int num;
	struct info * node = find->next;
	num=node->no;
	find->next=node->next;
	free(node);
	node=NULL;
	printf(" ɾ����Ŀ%d�ɹ�!\n",num);
}

struct info * find_info_no(struct info * head) {

	int num;
	struct info * node = head;

	printf(" ���������(����0���˳�):\n");
	scanf("%4d",&num);
	printf(" ���ڶ�λ...\n");
	system("mode con cols=80 lines=30");
	while(node->next!=NULL){
		if(node->next->no==num){
			print_info_solo(node->next);
			return node;
		}
		node=node->next;
	}
	return NULL;
}

void change_info(struct info * node) {

	int j;
	int s = 2;
	char ch,ch1;
	node=node->next;
	while (s!=0) {

		printf("\n ��������Ӧ������,���س�����...\n");
		printf(" 1.lever -> �޸���Ŀ�Ѷ�\n");
		printf(" 2.score -> �޸���Ŀ����\n");
		printf(" 3.rightAnswer -> �޸���Ŀ��ȷ��\n");
		printf(" 4.options -> �޸���Ŀѡ��\n");
		printf(" 5.answers -> �޸�ѡ��𰸴���/��ȷԭ��\n");
		printf(" 6.statement -> �޸���Ŀ����\n");

		printf(" 0.return -> ���ز˵�\n\t\t");

		fflush(stdin);
		scanf("%d", &s);
		fflush(stdin);
		switch (s) {
			case 1:
				printf("��������Ŀ�Ѷ�: ");
				scanf("%2d",&node->lever);
				break;
			case 2:
				printf("��������Ŀ����: ");
				scanf("%2d",&node->score);
				break;
			case 3:
				printf("��������Ŀ��ȷ��: ");
				ch=getchar();
				node->rightAnswer=ch-'A';
				break;
			case 4:
				printf("������ѡ��: ");
				ch=getchar(); 
				fflush(stdin);
				printf("�������ѡ����%c,�������µ�����:",ch);
				for(j=0;j<100;j++) {
					ch1=getchar();
					if(ch1!='\n')
						node->options[ch-'A'][j]=ch1;
					else
						break;
				}
				break;
			case 5:
				printf("������ѡ��: ");
				ch=getchar(); 
				fflush(stdin);
				printf("�������ѡ����%c,�������µ���ȷ/����ԭ��:",ch);
				for(j=0;j<300;j++) {
					ch1=getchar();
					if(ch1!='\n')
						node->answers[ch-'A'][j]=ch1;
					else
						break;
				}
				break;
			case 6:
				printf("��������Ŀ����: ");
				for(j=0;j<1000;j++) {
					ch=getchar();
					if(ch!='\n')
						node->statement[j]=ch;
					else
						break;
				}
				break;
			default:break;
		}

		node->timeModify=time(NULL);
		print_info_solo(node);

	}
}


void find_info_next(struct info * node) {

	int s = 2;
	while (s!=0) {

		printf("\n ��������Ӧ������,���س�����...\n");
		printf(" 1.change -> �޸�\n");
		printf(" 2.delete -> ɾ��\n");
		printf(" 0.return -> ���ز˵�\n\t\t");

		fflush(stdin);
		scanf("%d", &s);
		switch (s) {
			case 1:change_info(node); break;
			case 2:delete_info_no(node); break;
			default:break;
		}
	}
}


struct info * find_info_lever(struct info * head) {

	int count=0,sign=0;
	struct info * node = head;
	struct info * find = NULL;
	int lev;

	system("cls");
	printf(" ��������Ŀ�Ѷ�:\n");
	fflush(stdin);
	scanf("%2d",&lev);
	printf(" ���ڲ���...\n");
	system("mode con cols=80 lines=1000");
	while(node->next!=NULL){
		if(node->next->lever==lev){
			print_info_solo(node->next);
			find=node;
			sign++;
		}
		count++;
		node=node->next;
	}
	printf("\n �������!�ۼƲ���%d��,���ҽ��%d��\n",count,sign);
	if(sign==1)
		return find;
	else if(sign>1)
		return find_info_no(head);
	else{
		printf(" û���ҵ����,���ڷ�����һ���˵�...");
		Sleep(3000);
		return NULL;
	}
	return NULL;
}


struct info * find_info_score(struct info * head) {

	int count=0,sign=0;
	struct info * node = head;
	struct info * find = NULL;
	int lev;

	system("cls");
	printf(" ��������Ŀ��ֵ:\n");
	fflush(stdin);
	scanf("%2d",&lev);
	printf(" ���ڲ���...\n");
	system("mode con cols=80 lines=1000");
	while(node->next!=NULL){
		if(node->next->score==lev){
			print_info_solo(node->next);
			find=node;
			sign++;
		}
		count++;
		node=node->next;
	}
	printf("\n �������!�ۼƲ���%d��,���ҽ��%d��\n",count,sign);
	if(sign==1)
		return find;
	else if(sign>1)
		return find_info_no(head);
	else{
		printf(" û���ҵ����,���ڷ�����һ���˵�...");
		Sleep(3000);
		return NULL;
	}
	return NULL;
}

struct info * find_info_time(struct info * head) {

	int count=0,sign=0;
	struct info * node = head;
	struct info * find = NULL;

	system("cls");
	printf(" ���ڲ���...\n");
	system("mode con cols=80 lines=1000");
	while(node->next!=NULL){
		if( (time(NULL)-node->next->timeModify)<=250942){
			print_info_solo(node->next);
			find=node;
			sign++;
		}
		count++;
		node=node->next;
	}
	printf("\n �������!�ۼƲ���%d��,���ҽ��%d��\n",count,sign);
	if(sign==1)
		return find;
	else if(sign>1)
		return find_info_no(head);
	else{
		printf(" û���ҵ����,���ڷ�����һ���˵�...");
		Sleep(3000);
		return NULL;
	}
	return NULL;
}
