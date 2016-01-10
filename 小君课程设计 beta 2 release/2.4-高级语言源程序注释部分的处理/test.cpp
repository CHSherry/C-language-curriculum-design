//  C_playground6_LinkedList main.c
//  �������ļ�
//  Created by  Reign on 15/12/16.
//  ���ļ�����utf-8����

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct birthday {
	unsigned int year;
	unsigned int month;
	unsigned int day;
};

struct info {
	char name[20];
	char no[10];
	struct birthday date;
	struct info * next;
};

//solo -> ������ʼ��(�����ڴ�)

struct info * solo() {
    struct info * node=NULL;
    node = (struct info *)malloc(sizeof(struct info));
    memset(node, 0, sizeof(struct info));
    if (node == NULL) {
        printf("�����ڴ�ʧ��!");
        exit(-1);
    }
    return node;
}

//initialization -> ��ʼ��(�����ڴ�) �ݲ�ʹ�� ��������

struct info * initialization(int len) {
	struct info * head = NULL;
	struct info * node = NULL;
	int i;
	for (i = 0; i<len; i++) {
        node=solo();
		node->next = head;
		head = node;
	}
    printf("��ʼ���������!\n");
	return head;
}

//traversal -> ����(����ͷ����ͷ�巨)

struct info * traversal() {
    
    struct info * head = NULL;
    struct info * node = NULL;
    
    int i,len;
	char ch='c';
    printf("ѧ���ĸ�����: ");
    scanf("%300d",&len);
	for (i=0; i<len; i++) {
        node = solo();
		while ((ch = getchar()) != '\n' && ch !=' ');//ʹ��ch�󷨳Իس��Ϳո�...
		printf("����������: ");
		scanf("%20s",node->name);
		printf("������ѧ��: ");
		scanf("%10s",node->no);
		printf("����������: �� 1666 06 06\n");
		scanf("%d%d%d", &node->date.year, &node->date.month, &node->date.day);
		node->next = head;
        head = node;
        
	}
    return head;
}

//traversal_1 -> ����(����ͷ����β�巨)

struct info * traversal_1() {
    
	struct info * tail = NULL;
	struct info * head = NULL;
    struct info * node = NULL;
    
    int i,len;
	char ch='c';
    printf("ѧ���ĸ�����: ");
    scanf("%300d",&len);
	for (i=0; i<len; i++) {
	
		node = solo();
		
		while ((ch = getchar()) != '\n' && ch !=' ');//ʹ��ch�󷨳Իس��Ϳո�...
		printf("����������: ");
		scanf("%20s",node->name);
		printf("������ѧ��: ");
		scanf("%10s",node->no);
		printf("����������: �� 1666 06 06\n");
		scanf("%d%d%d", &node->date.year, &node->date.month, &node->date.day);
		
		if(i==0)
			head = tail = node ;
		else
		{
			tail->next = node;
			tail = node;
		}
	}
	return head;
}

//print -> �������Ļ

void print(struct info * head) {

	while(head!=NULL)
    {
		printf("%s\t",head->name);
		printf("%s\t",head->no);
		printf("%d-%d-%d\n", head->date.year, head->date.month, head->date.day);
		head = head->next;
	}
    printf("������\n");
}

//output -> ������ļ�

void output(struct info * head) {
	FILE * fp;
	if ((fp = fopen("test.txt", "w")) == NULL) {
		printf("���ļ�ʧ��");
		exit(-2);
	}
    printf("д���ļ���");
    while(head!=NULL)
    {
        printf(".");
        if(fwrite(head, sizeof(struct info), 1, fp)!=1) {
            printf("д���ļ�ʧ��");
            exit(-2);
        }
		head = head->next;
    }
    printf("д�����\n");
	fclose(fp);
}

//readFromFile -> ���ļ��ж�ȡ(����ͷ����ͷ�巨)

struct info * readFromFile() {
	struct info * head = NULL;
	struct info * node = NULL;

	FILE * fp;
	
	int temp = 0;
	int i;
	if ((fp = fopen("test.txt", "r")) == NULL) {
		printf("��ȡ�ļ�ʧ��");
		exit(-3);
	}

	printf("��ȡ����Ŀ�� ");
	scanf("%4d", &temp);

	for (i = 0; i<temp&&(!feof(fp)); i++) {
	
			printf("��ȡ�ļ���...\n");
            node = solo();
			
			if(fread(node, sizeof(struct info),1 , fp)!=1) {
                printf("��%d->%d�����ݴ������ʧ��\n",i+1,temp);
				free(NULL);
				node = NULL;
			}
            
			node->next = head;
			head = node;
	}
	fclose(fp);
	return head;
}

//readFromFile_1 -> ���ļ��ж�ȡ(����ͷ����β�巨)

struct info * readFromFile_1() {
	struct info * head = NULL;
	struct info * tail = NULL;
	struct info * node = NULL;

	FILE * fp;
	
	int temp = 0;
	int i;
	if ((fp = fopen("test.txt", "r")) == NULL) {
		printf("��ȡ�ļ�ʧ��");
		exit(-3);
	}

	printf("��ȡ����Ŀ�� ");
	scanf("%d", &temp);

	for (i = 0; i<temp&&(!feof(fp)); i++) {
	
			printf("��ȡ�ļ���...\n");
            node = solo();
			
			if(fread(node, sizeof(struct info),1 , fp)!=1) {
                printf("��%d->%d�����ݴ������ʧ��\n",i+1,temp);
				free(NULL);
				node = NULL;
			}
			if(i==0)
				head = tail = node;
			else
			{
				tail->next = node;
				tail = node;
			}
	}
	fclose(fp);
	return head;
}

//deleteWithNo -> ͨ��ѧ��ɾ��ָ������

void deleteWithNo(struct info * head) {

	int i;
	char ch;
	char *p = (char *)malloc(sizeof(char)*30);
	memset(p,0,sizeof(char)*30);
	struct info * node = head;
	struct info * temp = NULL;

	printf("������Ҫɾ��ѧ����ѧ��: ");
	fflush(stdin);
//	while ((ch = getchar()) != '\n' && ch !=' ');//ʹ��ch�󷨳Իس��Ϳո�...
	scanf("%s",p);
	printf("Ҫɾ��ѧ����ѧ����: %s\n",p);
	for(i=0;;i++) {

		if(head!=NULL&&head->next!=NULL&&strcmp(node->next->no,p)==0)
		{
			temp = node->next;
			node->next = node->next->next;
			free(temp);
			printf("ɾ�����,�ۼƲ���%d��\n",i+1);
			return ;
		}
		else
			node = node->next;
	}
	printf("�Բ���,������%d�κ�,��Ȼû�в��ҵ���ѧ��.\n",i+1);
			return ;
}


//freeAll -> �ͷŵ�ǰ�����ڴ�

void freeAll(struct info * head) {
    
    struct info * p = NULL;
    while (head!=NULL) {
        p = head->next;
        free(head);
        head = p;
    }
    printf("�ͷ��ڴ����\n");
}




int main() {
	
	struct info * p = NULL;
	
	int s = 2;
	while (s!=0) {

		printf("0.exit -> �˳�����\n");

		printf("1.traversal -> ����(����ͷ����ͷ�巨)\n");
		printf("2.traversal_1 -> ����(����ͷ����β�巨)\n");

		printf("3.readFromFile -> ���ļ��ж�ȡ(����ͷ����ͷ�巨)\n");
		printf("4.readFromFile_1 -> ���ļ��ж�ȡ(����ͷ����β�巨)\n");

		printf("5.print -> �������Ļ\n");
		printf("6.output -> ������ļ�\n");
		
		printf("8.deleteWithNo -> ͨ��ѧ��ɾ��ָ������\n");

		printf("9.freeAll -> �ͷŵ�ǰ�����ڴ�\n");


		scanf("%d", &s);
		switch (s) {
		case 1:p=traversal(); break;
		case 2:p=traversal_1(); break;
		case 3:p=readFromFile(); break;
		case 4:p=readFromFile_1(); break;
		case 5:print(p); break;
		case 6:output(p); break;
		case 8:deleteWithNo(p);break;
		case 9:freeAll(p);p=NULL; break;
		default:break;
		}
	}

	return 0;
}


