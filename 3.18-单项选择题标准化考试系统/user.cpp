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



