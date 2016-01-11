//find_user.cpp created time 2016-1-9 11:01:10

#include "all.h"

struct user * find_user(struct user * head) {

	int a;
	struct user * find = NULL;
		
	while (1) {

		system("mode con cols=57 lines=20");
		system("color 4E");

		a = move_1(3,menuPrint_6);
		system("cls");
		switch (a) {
			//1.
			case 1:find=find_user_name_key(head);break;
			case 2:find=find_user_no_key(head);break;
			case 3:find=find_user_name(head);break;
			case 4:find=find_user_no(head);break;
			case 5:find=find_user_time(head);break;
			case 0:
			default:break;
		}
		if(find!=NULL)
			find_user_next(find);
		break;
	}
	return find;
}


/*
               ����ѧ������       admin


               1.������(ģ��)����

               2.��ѧ��(ģ��)����     

               3.������(��ȷ)����

               4.��ѧ��(��ȷ)����

               5.�����¼��ѧ��   

               0.������һ��
*/

void menuPrint_6(int a) {

	system("cls");
	char name[15]={"menu_6.txt"};

	
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

struct user * find_user_name_key(struct user * head) {

	int count=0,sign=0;
	struct user * node = head;
	struct user * find = NULL;
	char key[20];
	memset(key,0,sizeof(char)*20);

	system("cls");
	printf(" ---��ѧ������(ģ��)����---\n ������ؼ���:\n");
	fflush(stdin);
	scanf("%19s",key);
	printf(" ���ڲ���...\n");
	system("mode con cols=80 lines=1000");
	while(node->next!=NULL){
		if(fuzzy_search(node->next->name,key)){
			print_user_solo(node->next);
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
		return find_user_no(head);
	else{
		printf(" û���ҵ����,���ڷ�����һ���˵�...");
		Sleep(3000);
		return NULL;
	}
	return NULL;
}


struct user * find_user_no_key(struct user * head) {

	int count=0,sign=0;
	struct user * node = head;
	struct user * find = NULL;
	char key[20];
	memset(key,0,sizeof(char)*20);

	system("cls");
	printf(" ---��ѧ��ѧ��(ģ��)����---\n ������ؼ���:\n");
	fflush(stdin);
	scanf("%19s",key);
	printf(" ���ڲ���...\n");
	system("mode con cols=80 lines=1000");
	while(node->next!=NULL){
		if(fuzzy_search(node->next->no,key)){
			print_user_solo(node->next);
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
		return find_user_no(head);
	else{
		printf(" û���ҵ����,���ڷ�����һ���˵�...");
		Sleep(3000);
		return NULL;
	}
	return NULL;
}



void delete_user_no(struct user * find) {

	struct user * node = find->next;
	printf(" ɾ��ѧ�� %s %s �ɹ�!\n",node->no,node->name);
	find->next=node->next;
	free(node);
	node=NULL;	
}

struct user * find_user_no(struct user * head) {

	char num[11];
	struct user * node = head;

	printf(" ������ѧ����ѡ�񵥸�ѧ��(����0���˳�):\n");
	fflush(stdin);
	scanf("%s",num);
	printf(" ���ڶ�λ...\n");
	system("mode con cols=80 lines=30");
	while(node->next!=NULL){
		if( strcmp(node->next->no,num)==0 ){
			print_user_solo(node->next);
			return node;
		}
		node=node->next;
	}
	printf(" û���ҵ����,���ڷ�����һ���˵�...");
	Sleep(3000);
	return NULL;
}

struct user * find_user_name(struct user * head) {

	char num[11];
	struct user * node = head;

	printf(" �����������Բ��ҵ���ѧ��(����0���˳�):\n");
	fflush(stdin);
	scanf("%s",num);
	printf(" ���ڶ�λ...\n");
	system("mode con cols=80 lines=30");
	while(node->next!=NULL){
		if( strcmp(node->next->name,num)==0 ){
			print_user_solo(node->next);
			return node;
		}
		node=node->next;
	}
	printf(" û���ҵ����,���ڷ�����һ���˵�...");
	Sleep(3000);
	return NULL;
}

void change_user(struct user * node) {

	int s = 2;
	char ch[30];
	while (s!=0) {

		printf("\n ��������Ӧ������,���س�����...\n");
		printf(" 1.no -> �޸�ѧ��\n");
		printf(" 2.password -> �޸�����\n");
		printf(" 3.name -> �޸�����\n");

		printf(" 0.return -> ���ز˵�\n\t\t");

		fflush(stdin);
		scanf("%d", &s);
		fflush(stdin);

		switch(s) {
			case 1:
				printf("�������µ�ѧ��: ");
				scanf("%20s",ch);
				if(strlen(ch)==11){
					strcpy(node->no,ch);
					printf("---�޸ĳɹ�!\n");
					s=0;
				}else{
					printf("---�޸�ʧ��! ԭ��:�����ѧ�Ų���10λ\n");
					Sleep(1300);
					s=0;
				}
				break;
			case 2:
				printf("�������µ�����: ");
				scanf("%20s",ch);
				if(strlen(ch)>=6){
					strcpy(node->password,ch);
					printf("---�޸ĳɹ�!\n");
					s=0;
				}else{
					printf("---�޸�ʧ��! ԭ��:������ڼ�\n");
					Sleep(1300);
					s=0;
				}
				break;
			case 3:
				printf("�������µ�����: ");
				scanf("%20s",node->name);
				printf("---�޸ĳɹ�!\n");
				s=0;
				break;
			default:
				break;
		}//ƥ��switch
	}//ƥ��while

	print_user_solo(node);
}


void find_user_next(struct user * node) {

	int s = 2;
	while (s!=0) {

		printf("\n ��������Ӧ������,���س�����...\n");
		printf(" 1.change -> �޸�\n");
		printf(" 2.delete -> ɾ��\n");//Сbug �û��Լ�ɾ���Լ�~~~2333
		printf(" 0.return -> ���ز˵�\n\t\t");

		fflush(stdin);
		scanf("%d", &s);
		switch (s) {
			case 1:change_user(node->next); break;
			case 2:delete_user_no(node); break;
			default:break;
		}
	}
}

/*

struct user * find_user_lever(struct user * head) {

	int count=0,sign=0;
	struct user * node = head;
	struct user * find = NULL;
	int lev;

	system("cls");
	printf(" ��������Ŀ�Ѷ�:\n");
	fflush(stdin);
	scanf("%2d",&lev);
	printf(" ���ڲ���...\n");
	system("mode con cols=80 lines=1000");
	while(node->next!=NULL){
		if(node->next->lever==lev){
			print_user_solo(node->next);
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
		return find_user_no(head);
	else{
		printf(" û���ҵ����,���ڷ�����һ���˵�...");
		Sleep(3000);
		return NULL;
	}
	return NULL;
}


struct user * find_user_score(struct user * head) {

	int count=0,sign=0;
	struct user * node = head;
	struct user * find = NULL;
	int lev;

	system("cls");
	printf(" ��������Ŀ�Ѷ�:\n");
	fflush(stdin);
	scanf("%2d",&lev);
	printf(" ���ڲ���...\n");
	system("mode con cols=80 lines=1000");
	while(node->next!=NULL){
		if(node->next->score==lev){
			print_user_solo(node->next);
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
		return find_user_no(head);
	else{
		printf(" û���ҵ����,���ڷ�����һ���˵�...");
		Sleep(3000);
		return NULL;
	}
	return NULL;
}

*/


struct user * find_user_time(struct user * head) {

	int count=0,sign=0;
	struct user * node = head;
	struct user * find = NULL;

	system("cls");
	printf(" ���ڲ���...\n");
	system("mode con cols=80 lines=1000");
	while(node->next!=NULL){
		if( (time(NULL)-node->next->timeLogin)<=250942){
			print_user_solo(node->next);
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
		return find_user_no(head);
	else{
		printf(" û���ҵ����,���ڷ�����һ���˵�...");
		Sleep(3000);
		return NULL;
	}
	return NULL;
}
