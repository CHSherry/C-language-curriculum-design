/*
3.18-xxx ����ѡ�����׼������ϵͳ���Ѷ�ϵ����5����
������������
���һ������ѡ����Ŀ���ϵͳ����ʵ���Զ�����ܡ�
������������
��1������Ա����
    �������ÿ�����������ɡ�4����ѡ�𰸡���׼�𰸵���Ϣ���ɽ���������ӡ�ɾ�����޸ġ���ѯ�����桢����Ȳ�����
    ����ܣ�ָ����Ŀ������Ŀ�ܷ֣������Ծ����Ծ�������ļ��������������һ���ļ���
	�û��������û���Ϣ������ӡ�ɾ�����޸ġ���ѯ�����桢����Ȳ�����
	�û������������ָ���û���ͳ�������Ծ���ܴ������Լ�ÿ�����õ��ܷ֡�
��2���û�����
	��ϰ���ܣ��û�ָ����Ŀ�������ѡ�⡣���û��Ĵ����׼�𰸽��жԱȣ������ո����ɼ����Դ�����Ŀ��Ҫ�ܸ�����ȷ�𰸡�
	���Թ��ܣ��û�ָ����Ŀ������������ܷ�100�ֵ��Ծ�ϵͳ�ɸ����û������׼�𰸵ĶԱ�ʵ���о��������ɼ��������û������Ծ��û��Ĵ𰸡��û������ܷ֣�����������ļ����档���л������������
��3�������ʾ
    ����Ա���û��ֱ�ͨ�������¼��������Ŀά���ʹ���������û������Ĵ����ļ���Ӧ���û���+ϵͳʱ��.txt����ʽ�洢���Ա��ڽ��й���
*/


#include "all.h"


void main(void) {

	printf("�����������,���Ժ�...");

	srand((unsigned)time(NULL));
	int a;
	struct user * head = NULL;
	
	while (1) {

		system("mode con cols=57 lines=20");
		system("color 0A");

		a = move_1(6,menuPrint);
		switch (a) {
			//1.
			case 1:
				admin();
				continue;
			case 2:
				user();
				continue;
			case 3:
				head=read_user();
				input_user(head);
				write_user(head);
				free_user(head);
				continue;
			case 4:
				system("cls");
				printf("���¼����ƹ���ƶ�\n������Ż�س��ɽ�����Ӧѡ��\nһ��Ҫ�г�Ӣ�����뷨!!!\n");
				system("pause");
				continue;
			case 5:
				ShellExecute(NULL, "open", "http://reigning.github.io/", NULL, NULL, SW_MAXIMIZE);
				;continue;
			case 0:exit(0);
			default:break;
		}
	}
}


int move_1(int num,void (*p)(int) ) {

	int a = 1;
	int key = 1;

	while(1) {

		(*p)(a);
		fflush(stdin);
		key=getch();
		if(key==244||key==0)
			key=getch();
		if(key==72)
			a--;//up
		else if(key==80)
			a++;
		else if(key>=48&&key<=57)
			return key-48;
		else if(key==27)
			return 0;//Esc
		else if(key==13)
			return a;
		else
			;

		if(a==num)
			a=0;
		if(a==-1)
			a=num-1;
	}
}


void menuPrint(int a) {

	system("cls");
	char name[15]={"menu_1.txt"};

	
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

void printLaugh(int x, int y) {

	goto_pos(x,y);
	printf("(*^_^*)");
	goto_pos(x+3,y);

}

void goto_pos(int x, int y) {
	//(��,��)
	COORD coord = {x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}

int fuzzy_search(char str[],char str2[]) {

	//char str[]ΪԴ�ַ���
	//char str2[]Ϊ���ҵĹؼ���
	char *res;
	res=(char *)memchr(str,str2[0],strlen(str));
	//����Ҫ���ҵ��ַ�����һ���ַ����и�Դ�ַ���
	if (res==NULL)
		return 0;
	//������������ַ����ĵ�һ���ַ���û���ҵ�...

	int n;
	while (1) {
		n=memcmp(res,str2,strlen(str2)-1); //�Ƚ�
		if(n != 0) {
			if(strlen(res)<=strlen(str2))//�и�����ַ���С��Ҫ�����ַ����ĳ���
				return 0;
			else{  
				//����Ҫ���ҵĵ�һ���ַ������и�
				res=(char *)memchr(res+1,str2[0],strlen(res));  
				if(res==NULL)
					return 0;
			}
		}else//���n = 0���ҵ�
			return 1;
	}
}