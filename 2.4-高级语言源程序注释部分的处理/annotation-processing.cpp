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

	char first[MAX_READ];//first��������ļ�����
	memset(first,0,sizeof(char)*MAX_READ);
	printf("���ڶ�ȡ %s ...\n",name);

	for (i=0; (!feof(fp))&&i<MAX_READ; i++) {

		if(fread(first+i, sizeof(char), 1, fp)!=1) {
            printf("���ƶ�ȡ%d���ַ�\n",i+1);
		}
	}
	fclose(fp);
	


/****************************************************************/


	FILE * second; //second�������Դ����

	quit = 1;
	char name_1[70];
	memset(name_1,0,sizeof(char)*70);

	while (quit) {

		printf("������Ҫ���Դ������ļ���...Ĭ�Ϻ�׺: *.cpp\n");
		scanf("%50s",name_1);
		
		printf("���������: ");
		j=printf("%s",name_1);
		printf("\n");
		if(j==0) {
			printf("����Ϊ��,����������!\n");
			continue;
		}
		for(i=0;i<j;i++)
			if(name_1[i]=='.')
				break;
		if(i==j)
			strcpy(&name_1[i],".cpp");
		
		if ((second = fopen(name_1, "w")) == NULL) {

			printf("�ļ� %s �������ȡ�ļ�ʧ��\n���鵱ǰ�û�Ȩ��!\n",name_1);
			exit(-2);
		}
		
		quit=0;
		
	}


/****************************************************************/



	FILE * third; //third�������ע�Ͳ���

	quit=1;
	char name_2[70];
	memset(name_2,0,sizeof(char)*70);

	while (quit) {

	printf("������Ҫ���ע�͵��ļ���...Ĭ�Ϻ�׺: *.txt\n");
	scanf("%50s",name_2);
	
		printf("���������: ");
		j=printf("%s",name_2);
		printf("\n");
		if(j==0) {
			printf("����Ϊ��,����������!\n");
			continue;
		}
		for(i=0;i<j;i++)
			if(name_2[i]=='.')
				break;
		if(i==j)
			strcpy(&name_2[i],".txt");
		
		if ((third = fopen(name_2, "w")) == NULL) {

			printf("�ļ� %s �������ȡ�ļ�ʧ��\n���鵱ǰ�û�Ȩ��!\n",name_2);
			exit(-2);
		}

		quit=0;
	
	}
	

/****************************************************************/


	//��ʼ���Դ���뵽name_1.cpp
	
	int sign = 0;
	int count = 0;
	char * p = NULL;
	char * q = NULL;
	p = first;
	q = first+1;

	while (*p!='\0') {

		if (*p=='/'&&*q=='/') {

			for(;;p++,q++,count++) {

				//fwrite(p,sizeof(char),1,third);
				fputc(*p,third);
				if(*p=='\n'||*p=='\0')
					break;

			}

		} else if (*p=='/'&&*q=='*') {

			for(;*p!='\0';p++,q++,count++) {

				fputc(*p,third);

				if(*p=='*'&&*q=='/') {

					//fwrite(p,sizeof(char),1,third);
					//fwrite(q,sizeof(char),1,third);
					fputc(*q,third);
					fputc('\n',third);
					p++;
					q=p+1;
					break;
				}

			}
			
		} else
			//fprintf(second,"%c",p);
			fputc(*p,second);

		p++;
		q++;
	}



	fclose(second);
	fclose(third);

	return 0;
}