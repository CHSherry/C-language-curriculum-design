/*
(1) ����Ա����

    �������ÿ�����������ɡ�4����ѡ�𰸡���׼�𰸵���Ϣ��
	�ɽ���������ӡ�ɾ�����޸ġ���ѯ�����桢����Ȳ�����

    ����ܣ�ָ����Ŀ������Ŀ�ܷ֣������Ծ�
	���Ծ�������ļ��������������һ���ļ���

	�û��������û���Ϣ������ӡ�ɾ�����޸ġ���ѯ�����桢����Ȳ�����

	�û������������ָ���û���ͳ�������Ծ���ܴ������Լ�ÿ�����õ��ܷ֡�
*/

//admin.cpp created time 2016-1-3 17:58:13

#include "all.h"

int sign_in() {

	system("mode con cols=30 lines=22");
	system("color 3A");

	int i;
	//char name[10]={"admin"},password[10]={"admin"};
	char name[10]={"1"},password[10]={"1"};
	char get_1[10],get_2[10];
	for(i=0;i<3;i++) {
		system("cls");
		printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
		printf("       ����Ա��¼����\n\n");
		printf("     ---------------------\n");
		printf("     |��¼��:|           |\n");
		printf("     ---------------------\n");
		printf("\n");
		printf("     ---------------------\n");
		printf("     | ����: |           |\n");
		printf("     ---------------------\n");
		printf("\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		fflush(stdin);
		goto_pos(16,7);
		scanf("%10s",get_1);
		fflush(stdin);
		goto_pos(16,11);
		scanf("%10s",get_2);
		
		if(strcmp(name,get_1)==0&&strcmp(password,get_2)==0){
			goto_pos(11,17);
			printf("��¼�ɹ�!");
			Sleep(800);
			return 0;
		}else{
			goto_pos(11,17);
			printf("�������\n    ���������� (ʣ�����:%d)",2-i);
			Sleep(1300);
		}
	}

	return -1;
}

void admin() {

	if(sign_in()==-1)//�����¼ʧ�����˳�
		return ;

	int a;
		
	while (1) {

		system("mode con cols=57 lines=20");
		system("color 47");

		a = move_1(5,menuPrint_2);
		switch (a) {
			//1.
			case 1:question_admin();continue;
			case 2:auto_paper();continue;
			case 3:user_admin();continue;
			case 4:situation_analysis();continue;
			case 6:;continue;
			case 0:
			default:break;
		}
		break;
	}

}

void menuPrint_2(int a) {

	system("cls");
	char name[15]={"menu_2.txt"};

	
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

//------------------------------------------

void question_admin() {

	question(); // ->question.cpp

}

void auto_paper() {


}

void user_admin() {


}

void situation_analysis() {


}


