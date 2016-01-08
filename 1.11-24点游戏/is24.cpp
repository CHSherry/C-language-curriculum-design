/*
1.11-xxx 24����Ϸ���Ѷȵȼ���5����
������������
�������4���ƣ������ܷ��ã������������½�����ϳ�24��
�������ܵ����ʽ��
*/

//���ڵ���getch()��fflush(stdin),�������ֲ�Խϲ�,�뾡����vc++6.0�б�������.

#include <stdio.h>
#include <time.h>
#include <math.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>

//------------------------------------------ȫ�ֱ���

struct temp_set {
	int mode;//��ǰģʽ 1.���Ҽ���(����С��) 2.��ϰģʽ(�޾�ģʽ) 3.����ģʽ 4.˫��ģʽ 5.���� 6.���� 0.exit
	//int isPrint;//�Ƿ������� 1.��� 0.�����
};

struct temp_set settings;

struct saved_set {
	int low;//����
	int high;//����
	int saveSettings;//�Ƿ񱣴浱ǰ����
};

struct saved_set saved;


int N = 24;



char op[4]={'+','-','*','/'};

float arr[4]={0};//arr������ż�����
float cur[4]={0};//cur������ŵ�ǰ����
float con[4]={0};//con�������ԭʼ����


//------------------------------------------�����б�

void goto_pos(int x, int y);
void tianti();
int zhabi();
float cal_value(char exp[]);
void translate(char str[],char exp[]);
char key_to_char(int key);
void read_settings();
void save_settings();
void print_settings();
float poker_to_number(char *poker);
void resetting();
char* number_to_poker(float number);
void initSettings_temp();
float calc(float n1, float n2, char o);
void initAllFromCon();
void randomGet();
void userGet();
int userGetIn();
void printResult_1(int a,int b,int c);
void printResult_2(int a,int b,int c);
void initArrFromCur();
void exercise();
void change_settings(int num);
void help();

void pk();
int s_first(int isPrint);	//ģ��ƽ�������֮����
int s_second(int isPrint);	//ģ��ƽ�������֮˫��

int test(void);
void menuPrint();

int move();
void exitGame(void);


//------------------------------------------���������˵�����


void main(void) {

	system("mode con cols=67 lines=29");
	system("color 3E");
	resetting();
	read_settings();
	initSettings_temp();
	srand((unsigned)time(NULL));
	int a;
	
	while (1) {

		menuPrint();
		a=move();
		switch (a) {
			//1.���Ҽ��� 2.��ϰģʽ 3.����ģʽ 4.˫��ģʽ 5.���� 6.���� 0.exit
			case 1:userGet();continue;
			case 2:exercise();continue;
			case 3:tianti();continue;
			case 4:pk();continue;
			case 5:print_settings();continue;
			case 6:help();continue;
			default:break;
		}
	}
}

void menuPrint() {

	system("cls");
	char name[10][sizeof(char)*15]={
		"exit.txt",
		"menu_1.txt",
		"menu_2.txt",
		"menu_3.txt",
		"menu_4.txt",
		"menu_5.txt",
		"menu_6.txt",
	};

	
	char arr[1000];//����1000��Ϊ����~2333
	memset(arr,0,sizeof(char)*1000);
	FILE *fp;
	fp=fopen(name[settings.mode],"r");

	if(fp==NULL) {
		printf("cannot open %s\n",name[settings.mode]);
		exit (0);
	}
	/*
	char ch;
	while(!feof(fp)) {
		ch=fgetc(fp);
		putchar(ch);
	}
	��������,���Բ����ñ��δ���
	*/
	int h=0;
	while(!feof(fp)) {
		fread(arr+h,sizeof(char),1,fp);
		h++;
	}
	printf("%s",arr);//���δ����Ż���2015-12-28 11:24:45
	//����ƶ�2015-12-31 15:28:56

	int a=(settings.mode==0?7:settings.mode);
	goto_pos(52,3+a*3);
	fclose(fp);
}

int move() {
	
	char key = 0;

	while (1) {

		fflush(stdin); //����������� 
		key = getch();
		if(key==0||key==-32)
			key = getch();
		if (key==72)
			settings.mode--;//...
		else if (key==80)
			settings.mode++;
		else if (key>=49&&key<=54)
			return key-48;
		else if (key==48||key==27) 
			exitGame();
		else if (key==13)
			if(settings.mode)
				return settings.mode;
			else
				exitGame();
		else
			key=0;
		
		if(settings.mode<0)
			settings.mode=settings.mode+7;
		if(settings.mode>6)
			settings.mode=settings.mode-7;
		
		menuPrint();
	}

	return settings.mode;
}

void exitGame(void) {
	
	system("cls");
	goto_pos(25,13);
	printf("�����˳���Ϸ...\n\t\t   ");
	if(saved.saveSettings)
		save_settings();
	Sleep(700);
	exit(0);

}

//------------------------------------------һ������

void userGet() {

	int a=1;
	//���userGetIn()�ķ���ֵΪ0�򷵻����˵�,�������ִ��userGetIn()
	while (a) {
		printf("����%d��\n",N);
		a=userGetIn();
		//system("pause");
	}
	
}

void exercise() {

	int key=10;
	system("cls");
	printf("��ͨ��4����֮���+-*/��(),�����%d��\n",N);
	printf("���ո�(Space��)����,���������������˵�\n");
	fflush(stdin);
	if((key=getch())==32)
		;
	else
		return ;

	while (1) {

		system("cls");
		randomGet();
		printf("��������ʽ: ");
		if(zhabi()) {
			printf("����ɹ�!\n");
			printf("���ո�(Space��)������ϰ,���������������˵�\n");
			fflush(stdin);
			if((key=getch())==32)
				;
			else
				return ;
		} else {
			printf("����ʧ��!\n");
			printf("���ո�(Space��)��ȷ���,���������������˵�\n");
			fflush(stdin);
			if((key=getch())==32) {
				s_first(1);
				s_second(1);

			}else
				return ;
		
			printf("���ո�(Space��)������ϰ,���������������˵�");
			fflush(stdin);
			if((key=getch())==32)
				;
			else
				return ;
		}
		//�����и����Ʋ˵�
	}
}


void tianti() {


	int lever=0;
	int key=10;
	system("cls");
	printf("��ͨ��4����֮���+-*/��(),�����%d��\n",N);
	printf("���ո�(Space��)��ʼ��ս,���������������˵�\n");
	fflush(stdin);
	if((key=getch())==32)
		;
	else
		return ;

	while (1) {

		system("cls");
		printf("��ǰ�ؿ�: lever %d\n",lever);
		randomGet();
		printf("��������ʽ: ");
		if(zhabi()) {
			printf("����ɹ�!\n");
			lever++;
			printf("���ո�(Space��)������ս��һ��,���������������˵�\n");
			fflush(stdin);
			if((key=getch())==32)
				;
			else
				return ;
		} else {
			printf("����ʧ��!\n");
			printf("���ո�(Space��)��ȷ���\n");
			fflush(stdin);
			if((key=getch())==32) {
				s_first(1);
				s_second(1);
				printf("\n��������������˵�...");
				key=getch();

			}else
				return ;
		
			printf("���ո�(Space��)������ϰ,���������������˵�");
			fflush(stdin);
			if((key=getch())==32)
				;
			else
				return ;
		}
		//�����и����Ʋ˵�
	}

}

void pk() {

	system("cls");
	int a=0,b=0,key,sign;
	char A[20]={0};
	char B[20]={0};
	printf("pkģʽ!\n");

	printf("�������û�A������:");
	fflush(stdin);
	scanf("%s",A);
	printf("�������û�B������:");
	fflush(stdin);
	scanf("%s",B);
	printf("���������ʼ P K !!!\n");
	key=getch();

	while (1) {

		printf("��ǰ���� A:%d B:%d\n",a,b);

		randomGet();
		fflush(stdin);
		printf("\n%s��������밴�ո�,\n%s��������밴�س�,\n���������밴���������\n",A,B);
		if( (key=getch())==32)
			sign=1;
		else if(key==13)
			sign=2;
		else
			sign=0;

		if(sign==1) {
			printf("��%s������ʽ: ",A);
			if(zhabi()) a++;
			else {printf("��Ϊ%d��!����ʧ��,Ҫ��%s 1��Ŷ\n",N,A); a--;}
		} else if(sign==2) {
			printf("��%s������ʽ: ",B);
			if(zhabi()) b++;
			else {printf("��Ϊ%d��!����ʧ��,Ҫ��%s 1��Ŷ\n",N,B); b--;}
		} else
			;

		printf("Ҫ����PK��?�����밴�ո��س�,����PK�밴������\n");
		key=getch();
		if(key==13||key==32)
			;
		else
			break;

	}
}


void print_settings() {

	char isSave[2][10]={"��","��"};

	int key=0;
	while (1) {

		system("cls");
		printf("\n\n");
		printf("\t���� C ���� д������ȽϷ���\n");
		printf("\t������ý�����ʱ��֧�����»������س�ѡ��\n");
		printf("\tҲ��֧�ָ��ĵ�ǰ����\n");
		printf("\t������1~9�޸�������,����0���ɻص����˵�\n\n");
		printf("\t1.��ǰ����(��С���˿���):%s\n",number_to_poker(float(saved.low)));
		printf("\t2.��ǰ����(�����˿���):%s\n",number_to_poker(float(saved.high)));
		printf("\t3.is %d��(�������ò������´���Ϸ����ʱ����...)\n",N);
		printf("\t8.������������(������bugʱҲ��������)\n");
		printf("\t9.�´�������Ϸ�Ƿ����뵱ǰ����:%s\n",isSave[saved.saveSettings]);
		printf("\t0.���ز˵�\n\n\t");


		fflush(stdin);
		key = getch();
		if (key>=49&&key<=59)
			change_settings(key-48);
		else if(key==48||key==27) {
			settings.mode=1;//�˳����ý���ʱ����ƶ��� 1.���Ҽ���
			return ;
		}
		else
			;
	}
	
}




void help() {


	system("cls");
	printf("\n");
	printf("                  -                                 4\n");
	printf("                22222                              44\n");
	printf("            22        222              44          44\n");
	printf("         22              22            44          44\n");
	printf("                           22          44          44\n");
	printf("                          22           44          44\n");
	printf("                        22             44          44\n");
	printf("                      22               44          44\n");
	printf("                   22                  4444444444444444444444444\n");
	printf("                22                                 44\n");
	printf("             22                                    44\n");
	printf("          22                                       44\n");
	printf("         222222222222222222222                     44\n");
	
	printf("\n");
	printf("\tHello,This is a little game written by Reigning.\n");
	printf("\tIf you want to have a look on source code,\n");
	printf("\tPlease invite https://Reigning.GitHub.io\n");
	printf("\tԭ��c����д������ô...");
	printf("\t����,���²���~2333\n");
	printf("\t1.�˵�����ȿ���֧�ַ����(����)+�س�\n\t\t\t  Ҳ����ֱ������1.2.3.4.5.6.\n");
	printf("\t2.��ʵ�������԰� 0 �˳�,���ҿ��԰�ESC�˳�\n");
	printf("\t3.���Ҽ������֧��С����Ŷ~��\n");
	printf("\t4.�����Ϸ�������Ǽ���24��,��������Ҳ����Ŷ,\n\t\t\t  ������������������С����\n");
	printf("\t5.������Щ������Bug,���ڿγ����ʱ�����,\n\t\t\t  û��ʱ��һһ�����޸�,�Ժ���������\n");
	printf("\t�밴���������...");
	fflush(stdin);
	int key;
	key=getch();
}


//------------------------------------------��������


void change_settings(int num) {

	char poker[5];
	memset(poker,0,sizeof(char)*5);
	fflush(stdin);
	switch (num) {
		case 1:
			printf("�����뵱ǰ����(��С���˿���):");
			scanf("%s",poker);
			saved.low=(int)(poker_to_number(poker));
			break;
		case 2:
			printf("�����뵱ǰ����(�����˿���):");
			scanf("%s",poker);
			saved.high=(int)(poker_to_number(poker));
			break;
		case 3:
			printf("�����뵱ǰ����(Ĭ��Ϊ24):");
			scanf("%d",&N);
			break;
		case 8:
			resetting();
			save_settings();
			break;
		case 9:
			if(saved.saveSettings)
				saved.saveSettings=0;
			else
				saved.saveSettings=1;
			break;
		default:
			break;
	}

}

void save_settings() {

	FILE *fp;
	if( (fp=fopen("is24.set","w"))!=NULL )
		fwrite(&saved,sizeof(struct saved_set),1,fp);

}

void initSettings_temp() {

	settings.mode=1;

}

void resetting() {

	settings.mode=1;//ģʽ ���Ҽ���
	saved.low=1;//����Ϊ1
	saved.high=13;//����Ϊ13
	saved.saveSettings=0;//�Ƿ񱣴浱ǰ����
}

void read_settings() {

	FILE *fp;
	resetting();
	if( (fp=fopen("is24.set","r"))==NULL ) {
		save_settings();
		//δ���->��ʾ��������
	} else {
		if( (fread(&saved,sizeof(saved_set),1,fp) )!=1 )
			resetting();
	}

}


char * number_to_poker(float number) {

	char temp[11];
	memset(temp,0,sizeof(char)*11);

	if(number==1)
		return "A";
	else if(number==11)
		return "J";
	else if(number==12)
		return "Q";
	else if(number==13)
		return "K";
	else if(number==10)
		return "10";
	else if(number>1&&number<10)
		return itoa((int)number,temp,10);
	else
		return NULL;
}

float poker_to_number(char *poker) {

	if(*poker=='j'||*poker=='J')
		return 11;
	else if(*poker=='q'||*poker=='Q')
		return 12;
	else if(*poker=='k'||*poker=='K')
		return 13;
	else if(*poker=='a'||*poker=='A')
		return 1;
	else
		return (float)(atof(poker));
}


void initAllFromCon() {

	int i;
	for(i=0;i<4;i++) {
		arr[i]=con[i];
		cur[i]=con[i];
	}
}

void initArrFromCur() {

	int g;
	for(g=0;g<4;g++)
		arr[g]=cur[g];

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


void randomGet() {


	
	int i;
	while (1) {
		
		for(i=0;i<4;i++)
			con[i]=(float)(rand()%saved.high+saved.low);
		if(s_first(0)||s_second(0)) {
			for(i=0;i<4;i++)
				printf("%g ",con[i]);
			break;
		}
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



//ģ��ƽ�������֮����

int s_first(int isPrint) {

	int result = 0;

	int a,b,c;
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
					if(isPrint)
						printResult_1(a,b,c);
					else
						return result;
				}

				}
			}
		}
	}

	initAllFromCon();
	return result;
}


//ģ��ƽ�������֮˫��

int s_second(int isPrint) {

	int result = 0;

	int a,b,c;
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
					if(isPrint)
						printResult_2(a,b,c);
					else
						return result;
				}

				}
			}
		}
	}

	initAllFromCon();
	return result;
}

int userGetIn() {
	
	system("cls");
	int i;
	int key=0;
	int sign=0;
	char input[4][10];
	for(i=0;i<4;i++)
		memset(input[i],0,sizeof(char)*10);
	//���С��,�����и� ����ʶ�� JQKA jqka space enter �ĺ���,��ʹ������������
	fflush(stdin); //�����������
	printf("������������,���ÿո����.");
	printf("������: ");
	for(i=0;i<4;i++) {
		scanf("%10s",input[i]);
	}
	for(i=0;i<4;i++) {
		con[i]=poker_to_number(input[i]);
		if(con[i]<saved.low||con[i]>saved.high) {
			printf("��%d����������ʧ��!����������������\n",i+1);
			system("pause");
			return -1;
		}
	}


	initAllFromCon();
	if(s_first(1))
		sign=1;
	if(s_second(1))
		sign=1;
	if(sign)
		printf("�������!\n");
	else
		printf("��,�㲻����Ŷ\n");
	printf("�Ƿ�������Ҽ���%d��?\n",N);
	printf("��ESC��0�������˵�,������������\n");
	fflush(stdin);
	key=getch();
	if(key==27||key==48)
		return 0;
	else
		userGetIn();

	//����ʹ���˵ݹ� δ�����ز���
	return 0;
}


//------------------------------------------���Ⱥ���

char * keyControl_to_charPointer(int key) {

	int key_2=0;
	if(key==224)
		key_2=getch();
	return NULL;//δ���
}

char key_to_char(int key) {

	if(key>=48&&key<=57)
		return '0'+key-48;//��������0->9
	else if(key>=96&&key<=105)
		return '0'+key-96;//С��������0->9
	else if(key>=65&&key<=90)
		return 'A'+key-65;//С��������0->9
	else if(key>=97&&key<=122)
		return 'a'+key-97;//С��������0->9
	else if(key==43)
		return '+';
	else if(key==45)
		return '-';
	else if(key==42)
		return '*';
	else if(key==47)
		return '/';
	else if(key==61)
		return '=';
	else if(key==40)
		return '(';
	else if(key==41)
		return ')';
	else
		return NULL;

}

//------------------------------------------���Ժ���

int test(void)
{
	
	randomGet();
	
	initAllFromCon();
	
	s_first(1);
	s_second(1);
	system("pause");

	return 0;
}

//------------------------------------------���Ⱥ���

void translate(char str[],char exp[])  
{
       struct
       {
              char data[100];
              int top;                 
       }op;                            
       char ch;                    
       int i = 0,t = 0;
       op.top = -1;
       ch = str[i];                      
       i++;
       while(ch != '\0')                 
       {
              switch(ch)
              {
              case '(':                
                   op.top++;op.data[op.top]=ch;
                     break;
              case ')':              
                   while(op.data[op.top] != '(')    
                {
                            exp[t]=op.data[op.top];
                            op.top--;
                            t++;
                     }
                     op.top--;
                     break;
              case '+':
              case '-':
                     while(op.top != -1&&op.data[op.top] != '(')
                     {
                            exp[t] = op.data[op.top];
                            op.top--;
                            t++;
                     }
                     op.top++;           
                     op.data[op.top] = ch;
                     break;
              case '*':
              case '/':
                     while(op.top == '/'||op.top == '*')      
                     {
                            exp[t] = op.data[op.top];
                            op.top--;
                            t++;
                     }
                     op.top++;
                     op.data[op.top] = ch;
                     break;
              case ' ':                        
                     break;
              default:
                     while(ch >= '0'&&ch <= '9')
                     {
                            exp[t] = ch;t++;
                            ch = str[i];i++;
                     }
                     i--;
                     exp[t] = '#';         
                     t++;
              }
              ch = str[i];
              i++;
       }
       while(op.top != -1)                  
       {
              exp[t] = op.data[op.top];
              t++;
              op.top--;
       }
       exp[t] = '\0';                        
}
float cal_value(char exp[])
{
       struct
       {
              float data[100];
              int top;
       }st;                               
       float d;
       char ch;
       int t = 0;
       st.top = -1;
       ch = exp[t];
       t++;
       while(ch != '\0')
       {
              switch(ch)                 
              {
               case '+':
                      st.data[st.top-1] = st.data[st.top-1]+st.data[st.top];
                      st.top--;
                      break;
               case '-':
                      st.data[st.top-1] = st.data[st.top-1]-st.data[st.top];
                      st.top--;
                      break;
               case '*':
                      st.data[st.top-1] = st.data[st.top-1]*st.data[st.top];
                      st.top--;
                      break;
               case '/':
                       if(st.data[st.top] != 0)
                              st.data[st.top-1]=st.data[st.top-1]/st.data[st.top];
                       else
                       {
                              printf("\n\t��0�Ǵ����");
                              st.data[st.top-1]=-3000;
                       }
                       st.top--;
                       break;
               default:
                      d=0;
                      while(ch >= '0'&&ch <= '9')   
                      {
                             d = 10*d+ch-'0';
                             ch = exp[t];
                             t++;
                      }
                      st.top++;
                      st.data[st.top] = d;
            }
            ch = exp[t];
            t++;
       }
       return st.data[st.top];
}

int zhabi()
{
       char str[100],exp[100];      
       fflush(stdin);
	   memset(str,0,sizeof(char)*100);
	   scanf("%99s",str);
	   char *p=str;
	   while(*p!='\0'){
		   if(*p=='=') *p='\0';
		   p++;
	   }
       translate(str,exp);    
	   float a=cal_value(exp);
       printf("������:%g\n",a);
	   //system("pause");
	   if(a==N)
		   return 1;
       return 0;
}


void goto_pos(int x, int y) {

	COORD coord = {x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}