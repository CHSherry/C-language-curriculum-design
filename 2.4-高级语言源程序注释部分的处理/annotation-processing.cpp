/*
2.4-xxx �߼�����Դ����ע�Ͳ��ֵĴ����Ѷ�ϵ����4����
������������
��C���Գ����е�����ע�Ͷ�ȥ��������ȥ��ע�͵��ļ���ע�ͷֱ����һ���µ��ļ��С�

������������
��1����ȡ�û�ָ�����ֵ�Դ�������磬�û����룺exercise.cpp�������ܶ�ȡ���ļ����д���
��2�����ļ��е�ע��
��3����ȥ����ע�Ͳ��ֺ�ɾ��ע�ͺ��C���Գ��򣬷ֱ𱣴浽������ͬ���ļ��У��ļ��������û�ָ����
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_READ 30000

int main(void) {
	
	printf("�߼�����Դ����ע�Ͳ��ֵĴ���\n");

	FILE * fp;

	int i,j;
	int quit = 1;
	char ch;
	char name[70];
	memset(name,0,sizeof(char)*70);
	
	while (quit) {

		printf("�������ļ�����...Ĭ�Ϻ�׺: *.cpp\n");
		scanf("%50s",name);
		
		printf("���������: ");
		j=printf("%s",name);
		printf("\n");
		if(j==0) {
			printf("����Ϊ��,����������!\n");
			continue;
		}
		for(i=0;i<j;i++)
			if(name[i]=='.')
				break;
		if(i==j)
			strcpy(&name[i],".cpp");
		
		if ((fp = fopen(name, "r")) == NULL) {

			printf("�ļ�û���ҵ� %s ,��ȡ�ļ�ʧ��\n",name);
			printf("�Ƿ����������ļ���? y/n ? ");
			fflush(stdin);
			if( (ch=getchar())==124)
				continue;
			else
				quit=0;
		}
		
		quit = 0; //��ȡ�ɹ���...�´β��ٽ�����ѭ��
	}

	char first[MAX_READ];
	printf("���ڶ�ȡ %s ...\n",name);

	for (i=0; (!feof(fp))&&i<MAX_READ; i++) {

		if(fread(first, sizeof(char), 1, fp)!=1) {
            printf("���ƶ�ȡ%d���ַ�\n",i+1);
		}
	}
	fclose(fp);
	
	FILE * second; //second�������Դ����

	printf("������Ҫ���Դ������ļ���...Ĭ�Ϻ�׺: *.cpp\n");

	if ((fp = fopen(, "w")) == NULL) {

			printf("�ļ�û���ҵ� %s ,��ȡ�ļ�ʧ��\n",name);
			printf("�Ƿ����������ļ���? y/n ? ");
			fflush(stdin);
			if( (ch=getchar())==124)
				continue;
			else
				quit=0;
		}




	return 0;
}