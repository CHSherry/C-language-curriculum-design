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
/*
void admin() {

	system("mode con cols=57 lines=20");
	system("color 0A");

	int a;
		
	while (1) {

		a = move(5);
		switch (a) {
			//1.
			case 1:admin();continue;
			case 2:;continue;
			case 3:;continue;
			case 6:;continue;
			case 0:exit(0);
			default:break;
		}
	}

}

void menuPrint_2() {

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
		case 1:printLaugh(32,6);break;
		case 2:printLaugh(32,8);break;
		case 3:printLaugh(32,10);break;
		case 4:printLaugh(32,12);break;
		case 5:printLaugh(32,14);break;
		case 0:printLaugh(32,16);break;
		default:break;
	}
	
}

//------------------------------------------

void question_admin() {


}

void auto_paper() {


}

void user_admin() {


}

void situation_analysis() {


}


*/