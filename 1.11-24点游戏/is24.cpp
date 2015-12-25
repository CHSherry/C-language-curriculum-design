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

void randomGet(int arr[]) {

	srand((unsigned)time(NULL));
	
	printf("�������������Ʒֱ��� ");

	int i;
	for(i=0;i<4;i++)
	{
		arr[i]=rand()%high+low;
		printf("%d ",arr[i]);
	}

	printf("������������Ƴɹ���\n");

}

void userGet(int arr[]) {

	int i,sign;
	int temp=0;

	while(1)
	{
		sign=0;//������
		
		printf("�����������ƣ�ÿ����֮���ÿո���������س���������롣\n����������4 12 5 1 �س�\n");
		printf("������: ");
		
		fflush(stdin);
		for(i=0;i<4;i++)
			scanf("%5d",&arr[i]);
		//����д�������� ^ & ( ) ��������ѭ�� !@#$%^&...
	
		printf("���������������: ");
		for(i=0;i<4;i++)
		{
			if(arr[i]>=low&&arr[i]<=high)
			{
				printf("%d ",arr[i]);
				sign++;
			}
			else
			{
				printf("?\n��%d������������",i+1);
				break;
			}
			sign=i+1;
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

void initArrFromCur() {

	int g;
	for(g=0;g<4;g++)
		arr[g]=cur[g];

}


void s_first() {

	int i,j,k;

	int sort[4][4]={
			{1,2,3,4},
			{2,3,4,1},
			{2,3,1,4},
			{3,4,2,1},
		};
	//ģ��ƽ�������֮����
	for(j=0;j<4;j++) {

		for(k=0;k<4;k++) 
			cur[k]=con[sort[j][k]-1];

		for(a=0;a<4;a++)  {
			for(b=0;b<4;b++) {
				for(c=0;c<4;c++) {

				initArrFromCur();

				i=0;
				arr[1]=calc(arr[i],arr[i+1],op[a]);
				i++;
				arr[2]=calc(arr[i],arr[i+1],op[b]);
				i++;
				arr[3]=calc(arr[i],arr[i+1],op[c]);
				if(fabs(arr[3]-N)<=0.1)
					printResult_1(a,b,c);
				}
			}
		}
	}
}



int main(void)
{
	int pai[4]={0};
	//float arr[4]={0};�Ѿ�ȫ�ֶ���
	//randomGet(pai);
	userGet(pai);
	int i;
	for(i=0;i<4;i++)
		con[i]=(float)pai[i];//ת��Ϊ�������鷽���������.�����û����븡����

	initAllFromCon();
	
	//system("pause");
	s_first();



	return 0;
}