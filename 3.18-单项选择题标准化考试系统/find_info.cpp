//find_info.cpp created time 2016-1-6 14:33:22

#include "all.h"

struct info * find_info(struct info * head) {

	int a;
	struct info * find = NULL;
		
	while (1) {

		system("mode con cols=57 lines=20");
		system("color 47");

		a = move_1(3,menuPrint_4);
		switch (a) {
			//1.
			case 1:find=find_info_key(head);continue;
			case 2:find=find_info_no(head);continue;
			case 3:;continue;
			case 4:;continue;
			case 5:;continue;
			case 6:;continue;
			case 0:
			default:break;
		}
		break;
	}
	return find;
}

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
	char key[20]={'0'};

	printf(" ������ؼ���:\n");
	printf(" ���ڲ���...\n");
	while(node->next!=NULL){
		if(fuzzy_search(node->next->statement,key)){
			print_info(node);
			sign++;
		}
		count++;
		node=node->next;
	}
	printf(" �������!�ۼƲ���%d��,���ҽ��%d��\n",count,sign);
	if(sign==1)
		return node;
	else if(sign>1)
		find=find_info_no(head);
	else{
		printf(" û���ҵ����,���ڷ�����һ���˵�...")
		find = NULL;
	}
	return find;
}

int fuzzy_search(char str[] , char str2[]) {
	//char str[]ΪԴ�ַ���
	//char str2[]Ϊ���ҵĹؼ���
	char *res;
	res = (char *)memchr(str, str2[0], strlen(str));
	//����Ҫ���ҵ��ַ�����һ���ַ����и�Դ�ַ���
	if (res == NULL)
		return 0;

	int n;
	while (1)
	{
		n = memcmp(res, str2, strlen(str2) - 1); //�Ƚ�
		if (n != 0) {

			if (strlen(res) <= strlen(str2))  //�и�����ַ���С��Ҫ�����ַ����ĳ���
				return 0;
			else
			{  
				//����Ҫ���ҵĵ�һ���ַ������и�
				res = (char *)memchr(res + 1, str2[0], strlen(res));  
				if (res == NULL)
					return 0;
			}
		} else//���n = 0���ҵ�
			return 1;
	}
}

void delete_info_no(struct info * find) {

	int num;
	struct info * node = find->next;
	num=node->no;
	find=find->next->next;
	free(node);
	node=NULL;
	printf(" ɾ����Ŀ%d�ɹ�!\n",num);
}

struct info * find_info_no(struct info * head) {

	int num;
	struct info * node = NULL;

	printf(" ���������:\n");
	printf(" ���ڶ�λ...\n");
	while(node->next!=NULL){
		if(node->next->no==num){
			print_info(node);
			return node;
		}
		node=node->next;
	}
	return NULL;
}

void change_info(struct info * node) {

	int s = 2;
	char ch;
	node=node->next;
	while (s!=0) {

		printf(" ��������Ӧ������,���س�����...\n");
		printf(" 1.lever -> �޸���Ŀ�Ѷ�\n");
		printf(" 2.score -> �޸���Ŀ����\n");
		printf(" 3.rightAnswer -> �޸���Ŀ��ȷ��\n");
		printf(" 4.options -> �޸���Ŀѡ��\n");
		printf(" 5.answers -> �޸�ѡ��𰸴���/��ȷԭ��\n");
		printf(" 6.statement -> �޸���Ŀ����\n");

		printf(" 0.return -> ���ز˵�\n");

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
				scanf("%2d",&node->lever);
				break;
			case 2:
				printf("��������Ŀ�Ѷ�: ");
				scanf("%2d",&node->lever);
				break;
			case 2:
				printf("��������Ŀ�Ѷ�: ");
				scanf("%2d",&node->lever);
				break;
			default:break;
		}


	}
}


void find_info_next(struct info * node) {

	int s = 2;
	while (s!=0) {

		printf(" ��������Ӧ������,���س�����...\n");
		printf(" 1.change -> �޸�\n");
		printf(" 2.delete -> ɾ��\n");
		printf(" 0.return -> ���ز˵�\n");

		fflush(stdin);
		scanf("%d", &s);
		switch (s) {
			case 1:node=node->next;p=traversal_1(); break;
			case 2:delete_info_no(node); break;
			default:break;
		}
	}
}