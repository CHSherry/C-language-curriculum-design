//find_info.cpp created time 2016-1-6 14:33:22

#include "all.h"

void find_info() {

	int a;
		
	while (1) {

		system("mode con cols=57 lines=20");
		system("color 47");

		a = move_1(3,menuPrint_4);
		switch (a) {
			//1.
			case 1:;continue;
			case 2:;continue;
			case 3:;continue;
			case 4:;continue;
			case 5:;continue;
			case 6:;continue;
			case 0:
			default:break;
		}
		break;
	}

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

	char key[20]={'0'};
	printf(" ������ؼ���:\n");
	printf(" ���ڲ���...\n");
	while(head!=NULL);//

	return head;
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