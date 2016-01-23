#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char op[3], o[5]="+-*/";
float n[4], on[10];
int used[4] = {0}, top=0, tp=0, x;

void chk(float k);
void search24(int d);
float calc(float n1, float n2, char o);
void make(int i, float p, float q, char o, int d);

int main( void )
{
 printf("please input 4 card number:\n");
    scanf("%f%f%f%f", &n[0], &n[1], &n[2], &n[3]);

    search24(0);
    printf("No answer.\n");

    return 0;
}


void chk(float k)
{
    if( (tp != 3) || ( fabs(k-24.0) > 0.000001 )) //û������3����������߽����Ϊ24���˳�.
  return;
    for(x=0; x<5; x+=2)                                            //���������Ϊ��ʹ3��ѡ�еķ��Ŷ����Եõ����.
        printf("%g%c%g=%g\n", on[x], op[x/2], on[x+1],         //�����õ���.
                               calc(on[x], on[x+1], op[x/2]));
 system("pause");
    exit(0);
}
float calc(float n1, float n2, char o)
{

    switch(o){
        case '+': return (n1+n2);
        case '-': return (n1-n2);
        case '*': return (n1*n2);
        case '/': return (n1/n2);
  default: exit(0);
    }

}
void make(int i, float p, float q, char o, int d)
{
    if(fabs(q)>0.000001 || o!='/')   //������Ϊ0,����Ϊ0��ʱ����Ϊ����.
        n[i] = calc(p, q, o);
    op[tp++] = o; 

 chk(n[i]);
    search24(d+1);
 tp--;    //��Ϊ��ȫ��ȫ�ֱ���,�������������Ե�ѭ���ݹ�����ʱ,���ʧ��,Ҫ�ڵݹ麯���������»ָ���ԭ����ֵ
}

void search24(int d)
{
    int i, j, k;
    float p, q;
    if(d>=3)    //���Ƶݹ����,������������������.
  return;
    for(i=0; i<4; i++)
        for(j=0; j<4; j++)
            if( (i!=j)&& (used[i]+used[j] == 0) ) //i!=j�Ƿ�ֹ�ظ�,(used[i]+used[j] == 0)�Ƿ�ֹ����ƥ���Ѿ��ù���j,
                                      //����i��������.
   {
                used[j] = 1;   //j�õ�ƥ��֮��,��ֵΪ1,��ʾ�Ѿ�ʹ��
    p=n[i];
    q=n[j];
                on[top++] = p;
    on[top++] = q;
                for(k=0; k<4; k++)  //�������ѭ������.
                    make(i, p, q, o[k], d);
                n[i] = p;        //��Ϊ��ȫ��ȫ�ֱ���,�������������Ե�ѭ���ݹ�����ʱ,
    used[j] = 0;     //���ʧ��,Ҫ�ڵݹ麯���������»ָ���ԭ����ֵ
                top -= 2;        //
            }

}