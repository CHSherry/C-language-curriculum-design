/*
1.11-xxx 24����Ϸ���Ѷȵȼ���5����
������������
�������4���ƣ������ܷ��ã������������½�����ϳ�24��
�������ܵ����ʽ��
*/

#include <stdio.h>
#include <time.h>
#include <math.h>
#include <windows.h>
#include <stdlib.h>

#define N 24

struct {
	int mode;//��ǰģʽ 1.���Ҽ���(����С��) 2.��ϰģʽ(�޾�ģʽ) 3.����ģʽ 4.˫��ģʽ 0.exit
	int isPrint;//�Ƿ������� 1.��� 0.�����
	int inputMode;//�л����Ҽ���������ģʽ 1.single ������� 2.linear ����������������
	int saveSettings;//�Ƿ񱣴浱ǰ����

}settings;

void initSettings() {

	settings.mode=666;
	settings.isPrint=0;
	settings.inputMode=2;
	settings.saveSettings=1;

}

float calc(float n1, float n2, char o) {

    switch(o) {
        case '+': return (n1+n2);
        case '-': return (n1-n2);
        case '*': return (n1*n2);
        case '/': 
			if(n2==0)
				return -30000;
			else
				return (n1/n2);
		default: exit(-1);
    }
}



int a,b,c;

int low=1;//����Ϊ1
int high=13;//����Ϊ13

char op[4]={'+','-','*','/'};
float T=0;//T���������ʱ���

float arr[4]={0};//arr������ż�����
float cur[4]={0};//cur������ŵ�ǰ����
float con[4]={0};//con�������ԭʼ����

void initAllFromCon() {

	int i;
	for(i=0;i<4;i++) {
		arr[i]=con[i];
		cur[i]=con[i];
	}
}

void randomGet() {

	srand((unsigned)time(NULL));
	
	printf("�������������Ʒֱ��� ");

	int i;
	for(i=0;i<4;i++)
	{
		con[i]=(float)(rand()%high+low);
		printf("%g ",arr[i]);
	}

	printf("������������Ƴɹ���\n");

}

void userGetLinear() {

	int i,sign;

	while(1)
	{
		sign=0;//������
		
		printf("�����������ƣ�ÿ����֮���ÿո���������س���������롣\n����������4 12 5 1 �س�\n");
		printf("������: ");
		
		fflush(stdin);
		for(i=0;i<4;i++)
			scanf("%f",&con[i]);
		//����д�������� ^ & ( ) ��������ѭ�� !@#$%^&...
	
		printf("���������������: ");
		for(i=0;i<4;i++)
		{
			if(arr[i]>=low&&arr[i]<=high)
			{
				printf("%g ",arr[i]);
				sign++;
			}
			else
			{
				printf("?\n��%d������������",i+1);
				sign=-1;
				break;
			}
			if(sign=-1)
				break;
		}
		if(sign==4)
			break;
		else
			continue;
	}
}

void printResult_1(int a,int b,int c) {
	
	if( (a==0||a==1)&&(b==2||b==3) )
		printf("(%g%c%g)%c%g%c%g=%d\n",cur[0],op[a],cur[1],op[b],cur[2],op[c],cur[3],N);
	else if ( (b==0||b==1)&&(c==2||c==3) )
		printf("(%g%c%g%c%g)%c%g=%d\n",cur[0],op[a],cur[1],op[b],cur[2],op[c],cur[3],N);
	else
		printf("%g%c%g%c%g%c%g=%d\n",cur[0],op[a],cur[1],op[b],cur[2],op[c],cur[3],N);
}


void printResult_2(int a,int b,int c) {
	
		printf("(%g%c%g)%c(%g%c%g)=%d\n",cur[0],op[a],cur[1],op[c],cur[2],op[b],cur[3],N);
}


void initArrFromCur() {

	int g;
	for(g=0;g<4;g++)
		arr[g]=cur[g];

}


//ģ��ƽ�������֮����
int s_first() {

	int result = 0;

	int j,k;

	int sort[4][4]={
			{1,2,3,4},
			{2,3,4,1},
			{2,3,1,4},
			{3,4,2,1},
		};

	for(j=0;j<4;j++) {

		for(k=0;k<4;k++) 
			cur[k]=con[sort[j][k]-1];

		for(a=0;a<4;a++)  {
			for(b=0;b<4;b++) {
				for(c=0;c<4;c++) {

				initArrFromCur();

				arr[1]=calc(arr[0],arr[1],op[a]);
				arr[2]=calc(arr[1],arr[2],op[b]);
				arr[3]=calc(arr[2],arr[3],op[c]);
				if(fabs(arr[3]-N)<=0.1) {
					result=1;
					printResult_1(a,b,c);
				}

				}
			}
		}
	}

	initAllFromCon();
	return result;
}


//ģ��ƽ�������֮˫��
int s_second() {

	int result = 0;

	int j,k;

	int sort[3][4]={
			{1,2,3,4},
			{1,3,2,4},
			{1,4,2,3},
		};

	for(j=0;j<3;j++) {

		for(k=0;k<4;k++) 
			cur[k]=con[sort[j][k]-1];

		for(a=0;a<2;a++)  {
			for(b=0;b<2;b++) {
				for(c=2;c<4;c++) {

				initArrFromCur();

				arr[1]=calc(arr[0],arr[1],op[a]);
				arr[2]=calc(arr[2],arr[3],op[b]);
				arr[3]=calc(arr[1],arr[2],op[c]);
				if(fabs(arr[3]-N)<=0.1) {
					result=1;
					printResult_2(a,b,c);
				}

				}
			}
		}
	}

	initAllFromCon();
	return result;
}

int test(void)
{
	
	randomGet();
	
	
	
	initAllFromCon();
	
	//system("pause");
	s_first();
	s_second();

	return 0;
}

int main(void) {

	initSettings();


	return 0;
}



char ch;
FILE *fp;
fp=fopen("asc.txt","w");
if(fp==NULL)
{printf("cannot open");
exit (0);
}
while(!feof(fp)).........��ΪʲôҪ�������
{ch=fgetc(fp);
putchar(ch);}
fclose(fp);}



 fflush(stdin); //����������� 
    char key;
    key = getch();

int tf = 1;

if (key == 72)
        tf = movup();
    else if (key == 80)
        tf = movdow();
    else if (key == 75)
        tf = movlif();
    else if (key == 77)
        tf = movri();