/*
1.11-xxx 24����Ϸ���Ѷȵȼ���5����
������������
�������4���ƣ������ܷ��ã������������½�����ϳ�24��
�������ܵ����ʽ��
*/

#include<stdio.h>
#include<time.h>
#include<math.h>
#include<windows.h>
#include<stdlib.h>

/*
#define add Q
#define minus W
#define multiply E
#define divide R
*/

float add(float a,float b) {
	return a+b;
}
float minus(float a,float b) {
	return a-b;
}
float multiply(float a,float b) {
	return a*b;
}
float divide(float a,float b) {
	if(b==0)
		return 30000;
	else
		return a/b;
}
//...
float *Q(float a,float b);
//Q=add,Q=minus;Q=multiply;Q=divide;


int i;

int low=1;//����Ϊ1
int high=13;//����Ϊ13

float T=0;//T���������ʱ���

void randomGet(int arr[]) {

	srand((unsigned)time(NULL));
	
	printf("�������������Ʒֱ��� ");

	for(i=0;i<4;i++)
	{
		arr[i]=rand()%high+low;
		printf("%d ",arr[i]);
	}

	printf("������������Ƴɹ���\n");

}

void userGet(int arr[]) {

	int sign;
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

void s_first(float *p) {

	T=0;//��ʼ
	//T=T+*p+*p+1

}



int main(void)
{
	int pai[4]={0};
	float arr[4]={0};
	randomGet(pai);
	//userGet(pai);
	for(i=0;i<4;i++)
		arr[i]=(float)pai[i];//ת��Ϊ�������鷽���������

	return 0;
}