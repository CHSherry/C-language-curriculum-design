/*
(1) ����Ա����

    �������ÿ�����������ɡ�4����ѡ�𰸡���׼�𰸵���Ϣ��
	�ɽ���������ӡ�ɾ�����޸ġ���ѯ�����桢����Ȳ�����

*/

//question.cpp created time 2016-1-3 23:45:41

#include "all.h"

void question() {
		
	int a;
	struct info * tail = NULL;

	while (1) {

		system("mode con cols=57 lines=20");
		system("color 3F");

		a = move_1(5,menuPrint_3);
		switch (a) {
			//1.
			case 1:;continue;
			case 2:;continue;
			case 3:;continue;
			case 4:;continue;
			case 6:;continue;
			case 0:
			default:break;
		}
		break;
	}
	//save

}

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

//��ͷ����β�巨

struct info * solo() {

    struct info * node = NULL;
    node = (struct info *)malloc(sizeof(struct info));
    memset(node, 0, sizeof(struct info));
    if (node == NULL) {
        printf("�����ڴ�ʧ��!");
        exit(-1);
    }
    return node;
}

void input_info(struct info * tail) {

	int i;
	struct info * node = NULL;
	
	node = solo();

	system("mode con cols=50 lines=40");
	system("color 0F");

	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
	printf("       ������Ŀ��Ϣ\n\n");
	printf("     ---------------------\n");
	printf("     | �Ѷ�(1-10): |           |\n");
	printf("     ---------------------\n");
	printf("\n");
	printf("     ---------------------\n");
	printf("     | ��ֵ (1-5): |           |\n");
	printf("     ---------------------\n");
	printf("\n");
	printf("     ---------------------\n");
	printf("     | ��ȷѡ��:  |       |\n");
	printf("     |   A---D	|       |\n");
	printf("     ---------------------\n");
	printf("\n");
	
	node->no = tail->no+1;

	fflush(stdin);
	goto_pos(16,7);
	scanf("%d",node->lever);
	fflush(stdin);
	goto_pos(16,11);
	scanf("%d",node->score);

	system("cls");
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
	printf("       ������Ŀ��Ϣ\n\n");
	printf("     ---------------------\n");
	printf("      ��������Ŀ����:\n");
	fflush(stdin);
	scanf("%1000s",node->statement);

	printf("������5���ؼ���,���ÿո����,���� @+�س� �����ؼ��ֵ�����.\n");
	for(i=0;i<4;i++) {
		scanf("%40s",node->keyWords[i]);
		if( *(node->keyWords[i])=='@' )
			break;
	}

	printf("������%cѡ�����ȷԭ��:\n",'A'+node->rightAnswer);
	fflush(stdin);
	scanf("%300s",node->answers[node->rightAnswer]);

	for(i=0;i<3;i++) {
		if(i==node->rightAnswer)
			continue;
		printf("������%cѡ��Ĵ���ԭ��:\n",'A'+i);
		fflush(stdin);
		scanf("%300s",node->answers[i]);
	}

	node->timeAdd=node->timeModify=time(NULL);

	


}

void add(struct info * tail) {

	struct info * node = NULL;
	input_info(tail);
	

}
